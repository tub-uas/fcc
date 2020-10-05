/** @file
 *    @brief MAVLink comm protocol testsuite generated from alxSys.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef ALXSYS_TESTSUITE_H
#define ALXSYS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_alxSys(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_alxSys(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_rc2spublisher(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RC2SPUBLISHER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rc2spublisher_t packet_in = {
        17.0,45.0,17651
    };
    mavlink_rc2spublisher_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.setPoint_aill = packet_in.setPoint_aill;
        packet1.setPoint_elev = packet_in.setPoint_elev;
        packet1.control_law = packet_in.control_law;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2spublisher_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rc2spublisher_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2spublisher_pack(system_id, component_id, &msg , packet1.setPoint_aill , packet1.setPoint_elev , packet1.control_law );
    mavlink_msg_rc2spublisher_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2spublisher_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.setPoint_aill , packet1.setPoint_elev , packet1.control_law );
    mavlink_msg_rc2spublisher_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rc2spublisher_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2spublisher_send(MAVLINK_COMM_1 , packet1.setPoint_aill , packet1.setPoint_elev , packet1.control_law );
    mavlink_msg_rc2spublisher_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_alxSys(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_rc2spublisher(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ALXSYS_TESTSUITE_H
