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


static void mavlink_test_rc2sin(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RC2SIN >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rc2sin_t packet_in = {
        17.0,45.0,73.0,101.0,18067
    };
    mavlink_rc2sin_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.setPoint_aill = packet_in.setPoint_aill;
        packet1.setPoint_elev = packet_in.setPoint_elev;
        packet1.setPoint_rudd = packet_in.setPoint_rudd;
        packet1.setPoint_thrt = packet_in.setPoint_thrt;
        packet1.control_law = packet_in.control_law;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RC2SIN_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RC2SIN_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sin_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rc2sin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sin_pack(system_id, component_id, &msg , packet1.setPoint_aill , packet1.setPoint_elev , packet1.setPoint_rudd , packet1.setPoint_thrt , packet1.control_law );
    mavlink_msg_rc2sin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sin_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.setPoint_aill , packet1.setPoint_elev , packet1.setPoint_rudd , packet1.setPoint_thrt , packet1.control_law );
    mavlink_msg_rc2sin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rc2sin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sin_send(MAVLINK_COMM_1 , packet1.setPoint_aill , packet1.setPoint_elev , packet1.setPoint_rudd , packet1.setPoint_thrt , packet1.control_law );
    mavlink_msg_rc2sin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ahrs(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ahrs_t packet_in = {
        963497464,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,161
    };
    mavlink_ahrs_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.gX = packet_in.gX;
        packet1.gY = packet_in.gY;
        packet1.gZ = packet_in.gZ;
        packet1.aX = packet_in.aX;
        packet1.aY = packet_in.aY;
        packet1.aZ = packet_in.aZ;
        packet1.mX = packet_in.mX;
        packet1.mY = packet_in.mY;
        packet1.mZ = packet_in.mZ;
        packet1.Phi = packet_in.Phi;
        packet1.Tht = packet_in.Tht;
        packet1.Psi = packet_in.Psi;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_pack(system_id, component_id, &msg , packet1.timestamp , packet1.gX , packet1.gY , packet1.gZ , packet1.aX , packet1.aY , packet1.aZ , packet1.mX , packet1.mY , packet1.mZ , packet1.Phi , packet1.Tht , packet1.Psi , packet1.alive );
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.gX , packet1.gY , packet1.gZ , packet1.aX , packet1.aY , packet1.aZ , packet1.mX , packet1.mY , packet1.mZ , packet1.Phi , packet1.Tht , packet1.Psi , packet1.alive );
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.gX , packet1.gY , packet1.gZ , packet1.aX , packet1.aY , packet1.aZ , packet1.mX , packet1.mY , packet1.mZ , packet1.Phi , packet1.Tht , packet1.Psi , packet1.alive );
    mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_air(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AIR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_air_t packet_in = {
        963497464,45.0,73.0,41
    };
    mavlink_air_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.aspd = packet_in.aspd;
        packet1.altb = packet_in.altb;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AIR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AIR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_air_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_pack(system_id, component_id, &msg , packet1.timestamp , packet1.aspd , packet1.altb , packet1.alive );
    mavlink_msg_air_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.aspd , packet1.altb , packet1.alive );
    mavlink_msg_air_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_air_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.aspd , packet1.altb , packet1.alive );
    mavlink_msg_air_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sfusion(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SFUSION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_sfusion_t packet_in = {
        963497464
    };
    mavlink_sfusion_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SFUSION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SFUSION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sfusion_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_sfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sfusion_pack(system_id, component_id, &msg , packet1.timestamp );
    mavlink_msg_sfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sfusion_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp );
    mavlink_msg_sfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_sfusion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sfusion_send(MAVLINK_COMM_1 , packet1.timestamp );
    mavlink_msg_sfusion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_rc2sout(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RC2SOUT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rc2sout_t packet_in = {
        17.0,45.0,73.0,101.0,18067
    };
    mavlink_rc2sout_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.out_aill = packet_in.out_aill;
        packet1.out_elev = packet_in.out_elev;
        packet1.out_rudd = packet_in.out_rudd;
        packet1.out_thrt = packet_in.out_thrt;
        packet1.control_law = packet_in.control_law;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RC2SOUT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RC2SOUT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sout_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rc2sout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sout_pack(system_id, component_id, &msg , packet1.out_aill , packet1.out_elev , packet1.out_rudd , packet1.out_thrt , packet1.control_law );
    mavlink_msg_rc2sout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sout_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.out_aill , packet1.out_elev , packet1.out_rudd , packet1.out_thrt , packet1.control_law );
    mavlink_msg_rc2sout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rc2sout_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rc2sout_send(MAVLINK_COMM_1 , packet1.out_aill , packet1.out_elev , packet1.out_rudd , packet1.out_thrt , packet1.control_law );
    mavlink_msg_rc2sout_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_alxSys(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_rc2sin(system_id, component_id, last_msg);
    mavlink_test_ahrs(system_id, component_id, last_msg);
    mavlink_test_air(system_id, component_id, last_msg);
    mavlink_test_sfusion(system_id, component_id, last_msg);
    mavlink_test_rc2sout(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ALXSYS_TESTSUITE_H
