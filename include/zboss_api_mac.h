/* ZBOSS Zigbee software protocol stack
 *
 * Copyright (c) 2012-2020 DSR Corporation, Denver CO, USA.
 * www.dsr-zboss.com
 * www.dsr-corporation.com
 * All rights reserved.
 *
 * This is unpublished proprietary source code of DSR Corporation
 * The copyright notice does not evidence any actual or intended
 * publication of such source code.
 *
 * ZBOSS is a registered trademark of Data Storage Research LLC d/b/a DSR
 * Corporation
 *
 * Commercial Usage
 * Licensees holding valid DSR Commercial licenses may use
 * this file in accordance with the DSR Commercial License
 * Agreement provided with the Software or, alternatively, in accordance
 * with the terms contained in a written agreement between you and
 * DSR.
 */
/*  PURPOSE: Public MAC layer API
*/
#ifndef ZB_ZBOSS_API_MAC_H
#define ZB_ZBOSS_API_MAC_H 1

/** \addtogroup mac_api */
/** @{ */

/** @addtogroup mac_api_phy_testing_mode PHY testing mode
 * @{
 */

#ifdef ZB_PHY_TESTING_MODE
/*
 * PHY Testing mode state machine state enumeration
 */
typedef zb_uint8_t zb_phy_testing_state_t;

typedef enum zb_phy_testing_states_e
{
  /* Phase 1. Set common parameters */
  ZB_PHY_TESTING_STATE_PANID = 0x00,
  ZB_PHY_TESTING_STATE_SHORT_ADDRESS,
  ZB_PHY_TESTING_STATE_EXTEND_ADDRESS,
  ZB_PHY_TESTING_STATE_MAX_FRAME_RETRIES,
  ZB_PHY_TESTING_STATE_TEST_CONTINUE,
  /* Phase 2. Set promiscuous mode rx test parameters */
  ZB_PHY_TESTING_STATE_PROMISCUOUS_MODE_ON_CB,
  ZB_PHY_TESTING_STATE_PROMISCUOUS_MODE_ON,
  ZB_PHY_TESTING_STATE_PROMISCUOUS_RX_ON,
  ZB_PHY_TESTING_STATE_CONTINUE_PROMISCUOUS_RX_TEST,
  /* Phase 3. Stop test */
  ZB_PHY_TESTING_STATE_PROMISCUOUS_MODE_OFF,
  ZB_PHY_TESTING_STATE_PROMISCUOUS_RX_OFF,
  ZB_PHY_TESTING_STATE_STOP,
  NUM_ZB_PHY_TESTING_STATE_ELEMENTS,
} zb_phy_testing_states_t;


typedef zb_uint8_t zb_phy_testing_mode_t;

typedef enum zb_phy_testing_modes_e
{
  /* Stop previous test */
  ZB_PHY_TESTING_STOP                   = 0x00,
  /* Continuously transmit raw packetized data (raw packets) */
  ZB_PHY_TESTING_RAW_PACKET_TX          = 0x01,
  /* Continuously transmit real ZigBee packets (with standard MAC header, with ACK request and retries) */
  ZB_PHY_TESTING_ZIGBEE_TX              = 0x02,
  /* Continuously transmit real ZigBee packets (with standard MAC header, without ACK request and retries) */
  ZB_PHY_TESTING_ZIGBEE_NO_ACK_TX       = 0x03,
  /* Continuously transmit non-packetized modulated data */
  ZB_PHY_TESTING_NO_PACKET_MODULATED_TX = 0x04,
  /* Continuously transmit non-packetized unmodulated data (Continuous Wave) */
  ZB_PHY_TESTING_CONTINUOUS_WAVE_TX     = 0x05,
  /* Continuously receive packets and calculate PER */
  ZB_PHY_TESTING_PACKET_PER_RX          = 0x06,
  /* Continuously receiving realistic ZigBee packets and calculate PER */
  ZB_PHY_TESTING_ZIGBEE_PACKET_PER_RX   = 0x07,
  /* Continuously receive modulated data and calculate BER */
  ZB_PHY_TESTING_MODULATED_BER_RX       = 0x08,
  NUM_ZB_PHY_TESTING_MODES_ELEMENTS
} zb_phy_testing_modes_t;

typedef zb_uint8_t zb_phy_testing_pattern_t;

typedef enum zb_phy_testing_patterns_e
{
  /* 9-bit pseudorandom binary sequence pattern */
  ZB_PHY_TESTING_PATTERN_PRBS9  = 0x01,
  /* Specified pattern filled */
  ZB_PHY_TESTING_PATTERN_SPECIFIED = 0x02,
  NUM_ZB_PHY_TESTING_PATTERN_ELEMENTS
} zb_phy_testing_patterns_t;

typedef zb_uint8_t zb_phy_testing_test_event_t;

typedef enum zb_phy_testing_test_events_e
{
  /* Test requested */
  ZB_PHY_TESTING_TEST_EVENT_REQUEST  = 0x00,
  /* Test stopped */
  ZB_PHY_TESTING_TEST_EVENT_STOP = 0x01,
  /* Test statistics sent */
  ZB_PHY_TESTING_TEST_EVENT_STATISTICS = 0x02,
  ZB_PHY_TESTING_TEST_EVENT_ELEMENTS
} zb_phy_testing_test_events_t;

typedef ZB_PACKED_PRE struct zb_phy_testing_statistics_s
{
  /* Total number of received packets */
  zb_uint32_t rx_pkt_counter;
  /* Total number of received valid packets */
  zb_uint32_t rx_valid_pkt_counter;
  /* Total number of receive errors (CRC errors, etc.) */
  zb_uint32_t rx_errors_counter;
} ZB_PACKED_STRUCT zb_phy_testing_statistics_t;

typedef ZB_PACKED_PRE struct zb_phy_testing_params_s
{
  /* Enable or disable CSMA/CA */
  zb_bitfield_t csma_ca:1;
  /* Enable or disable validation of RX packets */
  zb_bitfield_t validation:1;
  /* TDB */
  zb_bitfield_t reserved:6;
} ZB_PACKED_STRUCT zb_phy_testing_params_t;

typedef ZB_PACKED_PRE struct zb_phy_testing_request_s
{
  /* Test mode */
  zb_phy_testing_mode_t test_mode;
  /* Channel number */
  zb_uint8_t channel;
  /* Channel page */
  zb_uint8_t page;
  /* Transmission power, dBm */
  zb_int8_t tx_power;
  /* Pause between first message end and second message begin */
  zb_uint16_t delay;
  /* Packet count */
  zb_uint16_t count;
  /* Short address */
  zb_uint16_t short_addr;
  /* Long IEEE address */
  zb_ieee_addr_t long_addr;
  /* Destination short address */
  zb_uint16_t dest_short_addr;
  /* Pan ID */
  zb_uint16_t pan_id;
  /* The maximum number of retries allowed after a transmission failure. */
  zb_uint8_t mac_retry;
  /* Test mode configuration parameters */
  zb_phy_testing_params_t params;
} ZB_PACKED_STRUCT
zb_phy_testing_request_t;

/* Make sure we can fit the maximum available frame payload along with PHY testing mode parameters into a ZB buffer */
ZB_ASSERT_COMPILE_DECL((MAX_PHY_FRM_SIZE - 2 /* MAC Footer */) + sizeof(zb_phy_testing_request_t) <= ZB_IO_BUF_SIZE);

typedef ZB_PACKED_PRE struct zb_phy_testing_notification_s
{
  zb_ret_t ret_val;
  zb_phy_testing_test_event_t event_type;
  zb_phy_testing_statistics_t statistics;
} ZB_PACKED_STRUCT
zb_phy_testing_notification_t;

typedef void (*zb_phy_test_mode_notification_cb_t) (zb_phy_testing_notification_t notification);

/**
 * The function sends a PHY test mode request to MAC layer
 */
void zboss_phy_testing_mode_request(zb_bufid_t param, zb_phy_test_mode_notification_cb_t cb);

/**
 * The function sends a PHY testing mode statistics request to MAC layer
 */
void zboss_phy_testing_mode_statistics_request(zb_bufid_t param);

/**
 * The function is called by MAC layer to notify a higher layer about an event:
 * 1. Test is started
 * 2. Test is finished
 * 3. Statistics is sent
 */
void zboss_phy_testing_mode_notification(zb_bufid_t param);
#endif /* ZB_PHY_TESTING_MODE */
/** @} */
/** @} */

#endif /* ZB_ZBOSS_API_MAC_H */
