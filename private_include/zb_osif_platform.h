/*
 * Copyright (c) 2012-2021 DSR Corporation, Denver CO, USA
 * Copyright (c) 2021 Espressif Systems (Shanghai) PTE LTD
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

#include <stdint.h>             /* memcpy */
#include <string.h>             /* memcpy */

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



#define ZB_PLATFORM_INIT() zb_esp_init()
void zb_esp_init();
