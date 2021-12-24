/*
 * Copyright (c) 2021 Espressif Systems (Shanghai) CO LTD
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Espressif Systems
 *    integrated circuit in a product or a software update for such product,
 *    must reproduce the above copyright notice, this list of conditions and
 *    the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* PURPOSE: Header to combine osif dependent files with stack
*/

#pragma once

#include <stdint.h>
#include <string.h>
#include "freertos/portmacro.h"

#define ZB_VOLATILE
#define ZB_SDCC_XDATA
#define ZB_CALLBACK
#define ZB_SDCC_BANKED
#define ZB_KEIL_REENTRANT
/* At ARM all types from 1 to 4 bytes are passed to vararg with casting to 4 bytes */
typedef zb_uint32_t zb_minimal_vararg_t;
/* use macros to be able to redefine */
#define ZB_MEMCPY   memcpy
#define ZB_MEMMOVE  memmove
#define ZB_MEMSET   memset
#define ZB_MEMCMP   memcmp
#define ZB_BZERO(s,l) ZB_MEMSET((char*)(s), 0, (l))
#define ZB_BZERO2(s) ZB_BZERO(s, 2)
#define ZVUNUSED(v) (void)v
void random_init(unsigned short seed);
uint32_t random_rand(void);
#define ZB_RANDOM_INIT()
#define ZB_RANDOM_RAND() random_rand()
#define ZB_PLATFORM_INIT() zb_esp_init()
void zb_esp_init();
void zb_esp_abort();
#define ZB_CHECK_TIMER_IS_ON() 1
#define ZB_START_HW_TIMER()
#define ZB_STOP_HW_TIMER()
void zb_osif_iteration();
#define ZB_TRANSPORT_BLOCK() zb_osif_iteration()
#define ZB_TRANSPORT_NONBLOCK_ITERATION() zb_osif_iteration()
extern portMUX_TYPE zboss_mux;
extern uint8_t g_dis_inter_flag;
#define ZB_ENABLE_ALL_INTER()  if(g_dis_inter_flag){portEXIT_CRITICAL(&zboss_mux);} g_dis_inter_flag = 0;
#define ZB_DISABLE_ALL_INTER() portENTER_CRITICAL(&zboss_mux); g_dis_inter_flag =1;
#define ZB_OSIF_GLOBAL_LOCK()      ZB_DISABLE_ALL_INTER()
#define ZB_OSIF_GLOBAL_UNLOCK()    ZB_ENABLE_ALL_INTER()
#define ZB_ABORT abort
#define ZB_GO_IDLE()
zb_bool_t zb_osif_prod_cfg_check_presence(void);
zb_ret_t zb_osif_prod_cfg_read_header(zb_uint8_t *prod_cfg_hdr, zb_uint16_t hdr_len);
zb_ret_t zb_osif_prod_cfg_read(zb_uint8_t *buffer, zb_uint16_t len, zb_uint16_t offset);
void zb_osif_userial_poll(void);

typedef struct {
    fd_set         read_fds;    /* The read file descriptors.*/
    fd_set         write_fds;   /* The write file descriptors.*/
    fd_set         error_fds;   /* The error file descriptors.*/
    int            max_fd;      /* The max file descriptor.*/
    struct timeval timeout;     /* The timeout.*/
} zb_osif_iteration_context_t;

void zb_esp_console_update(zb_osif_iteration_context_t *iteration);
void zb_esp_radio_update(zb_osif_iteration_context_t *iteration);
void zb_esp_console_process(void);
void zb_esp_radio_process(void);

#ifdef ZB_SERIAL_FOR_TRACE
#define ZB_OSIF_SERIAL_FLUSH() zb_esp_console_process()
#endif
