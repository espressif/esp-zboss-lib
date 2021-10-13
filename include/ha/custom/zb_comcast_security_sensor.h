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
/* PURPOSE: Comcast Security Sensor device definition
*/

#ifndef ZB_HA_COMCAST_SECURITY_SENSOR_H
#define ZB_HA_COMCAST_SECURITY_SENSOR_H 1

#if defined ZB_HA_DEFINE_DEVICE_COMCAST_SECURITY_SENSOR || defined DOXYGEN

/** @cond DOXYGEN_HA_SECTION */

/**
 *  @defgroup ZB_COMCAST_SECURITY_SENSOR Comcast security sensor
 *  @ingroup ZB_HA_DEVICES
 *  @{
    @details
        - @ref ZB_ZCL_BASIC \n
        - @ref ZB_ZCL_IDENTIFY \n
        - @ref ZB_ZCL_IAS_ZONE \n
        - @ref ZB_ZCL_POLL_CONTROL \n
        - @ref ZB_ZCL_TEMP_MEASUREMENT \n
        - @ref ZB_ZCL_POWER_CONFIG \n
        - @ref ZB_ZCL_DIAGNOSTICS \n
        - @ref ZB_ZCL_OTA_UPGRADE \n
        - @ref ZB_ZCL_ILLUMINANCE_MEASUREMENT \n
        - @ref ZB_ZCL_WATER_CONTENT_MEASUREMENT

*/

#define ZB_HA_COMCAST_SECURITY_SENSOR_VER 0

/**< Input clusters number. */
#define ZB_HA_COMCAST_SECURITY_SENSOR_IN_CLUSTER_NUM  9

/**< Output clusters number. */
#define ZB_HA_COMCAST_SECURITY_SENSOR_OUT_CLUSTER_NUM 1

/*! @internal Number of attribute for reporting on IAS Zone device */
#define ZB_HA_COMCAST_SECURITY_SENSOR_REPORT_ATTR_COUNT \
  (ZB_ZCL_TEMP_MEASUREMENT_REPORT_ATTR_COUNT + ZB_ZCL_IAS_ZONE_REPORT_ATTR_COUNT + \
   ZB_ZCL_POWER_CONFIG_BAT_PACK_2_REPORT_ATTR_COUNT + ZB_ZCL_REL_HUMIDITY_MEASUREMENT_REPORT_ATTR_COUNT + \
   ZB_ZCL_ILLUMINANCE_MEASUREMENT_REPORT_ATTR_COUNT)

/**
 *  @brief Declare cluster list for IAS Zone
 *  @param cluster_list_name [IN] - cluster list variable name.
 *  @param basic_attr_list [IN] - attribute list for Basic cluster.
 *  @param identify_attr_list [IN] - attribute list for Identify cluster.
 *  @param ias_zone_attr_list [IN] - attribute list for IAS Zone cluster.
 *  @param poll_ctrl_attr_list [IN] - attribute list for Poll Control cluster.
 *  @param temp_meas_attr_list [IN] - attribute list for IAS Zone cluster.
 *  @param power_config_attr_list [IN] - attribute list for Power configuration cluster.
 *  @param diagnostic_attr_list [IN] - attribute list for Diagnostics cluster.
 *  @param ota_upgrade_attr_list [IN] - attribute list for OTA Upgrade cluster.
 *  @param illuminance_measurement_attr_list [IN] - attribute list for Illuminance measurement cluster.
 *  @param rel_humidity_measurement_attr_list [IN] - attribute list for Relative Humidity Measurement cluster.
 */
#define ZB_HA_DECLARE_COMCAST_SECURITY_SENSOR_CLUSTER_LIST(                    \
  cluster_list_name,                                                           \
  basic_attr_list,                                                             \
  identify_attr_list,                                                          \
  ias_zone_attr_list,                                                          \
  poll_ctrl_attr_list,                                                         \
  temp_meas_attr_list,                                                         \
  power_config_attr_list,                                                      \
  diagnostic_attr_list,                                                        \
  ota_upgrade_attr_list,                                                       \
  illuminance_measurement_attr_list,                                           \
  rel_humidity_measurement_attr_list                                           \
  )                                                                            \
      zb_zcl_cluster_desc_t cluster_list_name[] =                              \
      {                                                                        \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_BASIC,                                             \
          ZB_ZCL_ARRAY_SIZE(basic_attr_list, zb_zcl_attr_t),                   \
          (basic_attr_list),                                                   \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_IDENTIFY,                                          \
          ZB_ZCL_ARRAY_SIZE(identify_attr_list, zb_zcl_attr_t),                \
          (identify_attr_list),                                                \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_IAS_ZONE,                                          \
          ZB_ZCL_ARRAY_SIZE(ias_zone_attr_list, zb_zcl_attr_t),                \
          (ias_zone_attr_list),                                                \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_POLL_CONTROL,                                      \
          ZB_ZCL_ARRAY_SIZE(poll_ctrl_attr_list, zb_zcl_attr_t),               \
          (poll_ctrl_attr_list),                                               \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT,                                  \
          ZB_ZCL_ARRAY_SIZE(temp_meas_attr_list, zb_zcl_attr_t),               \
          (temp_meas_attr_list),                                               \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_POWER_CONFIG,                                      \
          ZB_ZCL_ARRAY_SIZE(power_config_attr_list, zb_zcl_attr_t),            \
          (power_config_attr_list),                                            \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_DIAGNOSTICS,                                       \
          ZB_ZCL_ARRAY_SIZE(diagnostic_attr_list, zb_zcl_attr_t),              \
          (diagnostic_attr_list),                                              \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_ILLUMINANCE_MEASUREMENT,                           \
          ZB_ZCL_ARRAY_SIZE(illuminance_measurement_attr_list, zb_zcl_attr_t), \
          (illuminance_measurement_attr_list),                                 \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_REL_HUMIDITY_MEASUREMENT,                          \
          ZB_ZCL_ARRAY_SIZE(rel_humidity_measurement_attr_list, zb_zcl_attr_t),\
          (rel_humidity_measurement_attr_list),                                \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        ),                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                   \
          ZB_ZCL_CLUSTER_ID_OTA_UPGRADE,                                       \
          ZB_ZCL_ARRAY_SIZE(ota_upgrade_attr_list, zb_zcl_attr_t),             \
          (ota_upgrade_attr_list),                                             \
          ZB_ZCL_CLUSTER_CLIENT_ROLE,                                          \
          ZB_ZCL_MANUF_CODE_INVALID                                            \
        )                                                                      \
      }

/**
 *  @brief Declare simple descriptor for IAS Zone
 *  @param ep_name - endpoint variable name.
 *  @param ep_id [IN] - endpoint ID.
 *  @param in_clust_num [IN] - number of supported input clusters.
 *  @param out_clust_num [IN] - number of supported output clusters.
 *  @note in_clust_num, out_clust_num should be defined by numeric constants, not variables or any
 *  definitions, because these values are used to form simple descriptor type name.
 */
#define ZB_HA_DECLARE_COMCAST_SECURITY_SENSOR_SIMPLE_DESC(      \
  ep_name, ep_id, in_clust_num, out_clust_num)                  \
      ZB_DECLARE_SIMPLE_DESC(in_clust_num, out_clust_num);      \
      ZB_AF_SIMPLE_DESC_TYPE(in_clust_num, out_clust_num)       \
            simple_desc_##ep_name =                             \
      {                                                         \
        ep_id,                                                  \
        ZB_AF_HA_PROFILE_ID,                                    \
        ZB_HA_IAS_ZONE_ID, /* TODO: actualy, device id should be changed */ \
        ZB_HA_COMCAST_SECURITY_SENSOR_VER,                         \
        0,                                                      \
        in_clust_num,                                           \
        out_clust_num,                                          \
        {                                                       \
          ZB_ZCL_CLUSTER_ID_BASIC,                              \
          ZB_ZCL_CLUSTER_ID_IDENTIFY,                           \
          ZB_ZCL_CLUSTER_ID_IAS_ZONE,                           \
          ZB_ZCL_CLUSTER_ID_POLL_CONTROL,                       \
          ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT,                   \
          ZB_ZCL_CLUSTER_ID_POWER_CONFIG,                       \
          ZB_ZCL_CLUSTER_ID_DIAGNOSTICS,                        \
          ZB_ZCL_CLUSTER_ID_ILLUMINANCE_MEASUREMENT,            \
          ZB_ZCL_CLUSTER_ID_REL_HUMIDITY_MEASUREMENT,           \
          ZB_ZCL_CLUSTER_ID_OTA_UPGRADE                         \
        }                                                       \
      }

/**
 *  @brief Declare endpoint for IAS Ancillary Control Equipment
 *  @param ep_name [IN] - endpoint variable name.
 *  @param ep_id [IN] - endpoint ID.
 *  @param cluster_list [IN] - endpoint cluster list.
 */
#define ZB_HA_DECLARE_COMCAST_SECURITY_SENSOR_EP(ep_name, ep_id, cluster_list)               \
      ZBOSS_DEVICE_DECLARE_REPORTING_CTX(reporting_info## device_ctx_name,                   \
                                         ZB_HA_COMCAST_SECURITY_SENSOR_REPORT_ATTR_COUNT);   \
      ZB_HA_DECLARE_COMCAST_SECURITY_SENSOR_SIMPLE_DESC(                                     \
          ep_name,                                                                           \
          ep_id,                                                                             \
          ZB_HA_COMCAST_SECURITY_SENSOR_IN_CLUSTER_NUM,                                      \
          ZB_HA_COMCAST_SECURITY_SENSOR_OUT_CLUSTER_NUM);                                    \
      ZB_AF_DECLARE_ENDPOINT_DESC(                                                           \
          ep_name,                                                                           \
          ep_id,                                                                             \
          ZB_AF_HA_PROFILE_ID,                                                               \
          0,                                                                                 \
          NULL,                                                                              \
          ZB_ZCL_ARRAY_SIZE(                                                                 \
              cluster_list,                                                                  \
              zb_zcl_cluster_desc_t),                                                        \
          cluster_list,                                                                      \
          (zb_af_simple_desc_1_1_t*)&simple_desc_##ep_name,                                  \
          ZB_HA_COMCAST_SECURITY_SENSOR_REPORT_ATTR_COUNT, reporting_info## device_ctx_name, \
          0, NULL)

#define ZB_HA_DECLARE_COMCAST_SECURITY_SENSOR_CTX(device_ctx, ep_name)   \
  ZBOSS_DECLARE_DEVICE_CTX_1_EP(device_ctx, ep_name)

/**
 * @}
 */

/** @endcond */ /* DOXYGEN_HA_SECTION */

#endif /* defined ZB_HA_DEFINE_DEVICE_COMCAST_SECURITY_SENSOR || defined DOXYGEN */

#endif /* ZB_HA_COMCAST_SECURITY_SENSOR_H */
