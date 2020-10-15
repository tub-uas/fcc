/** @file
 *    @brief MAVLink comm protocol testsuite generated from downlink.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef DOWNLINK_TESTSUITE_H
#define DOWNLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_downlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_downlink(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_dataraiin(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataRaiIn >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dataraiin_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 },19939,39
    };
    mavlink_dataraiin_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.senseTime = packet_in.senseTime;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.thr = packet_in.thr;
        packet1.fltMode = packet_in.fltMode;
        packet1.alive = packet_in.alive;
        
        mav_array_memcpy(packet1.chnl, packet_in.chnl, sizeof(uint16_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataRaiIn_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataRaiIn_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiin_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dataraiin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiin_pack(system_id, component_id, &msg , packet1.time , packet1.senseTime , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiin_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.senseTime , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dataraiin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiin_send(MAVLINK_COMM_1 , packet1.time , packet1.senseTime , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dataraiout(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataRaiOut >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dataraiout_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,{ 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 },19731,27
    };
    mavlink_dataraiout_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.thr = packet_in.thr;
        packet1.fltMode = packet_in.fltMode;
        packet1.alive = packet_in.alive;
        
        mav_array_memcpy(packet1.chnl, packet_in.chnl, sizeof(uint16_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataRaiOut_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataRaiOut_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiout_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dataraiout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiout_pack(system_id, component_id, &msg , packet1.time , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiout_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiout_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dataraiout_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataraiout_send(MAVLINK_COMM_1 , packet1.time , packet1.chnl , packet1.roll , packet1.pitch , packet1.yaw , packet1.thr , packet1.fltMode , packet1.alive );
    mavlink_msg_dataraiout_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dataahrs(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataAhrs >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dataahrs_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,1
    };
    mavlink_dataahrs_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.senseTime = packet_in.senseTime;
        packet1.gyrX = packet_in.gyrX;
        packet1.gyrY = packet_in.gyrY;
        packet1.gyrZ = packet_in.gyrZ;
        packet1.accX = packet_in.accX;
        packet1.accY = packet_in.accY;
        packet1.accZ = packet_in.accZ;
        packet1.magX = packet_in.magX;
        packet1.magY = packet_in.magY;
        packet1.magZ = packet_in.magZ;
        packet1.temp = packet_in.temp;
        packet1.press = packet_in.press;
        packet1.phi = packet_in.phi;
        packet1.the = packet_in.the;
        packet1.psi = packet_in.psi;
        packet1.q0 = packet_in.q0;
        packet1.q1 = packet_in.q1;
        packet1.q2 = packet_in.q2;
        packet1.q3 = packet_in.q3;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataAhrs_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataAhrs_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataahrs_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dataahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataahrs_pack(system_id, component_id, &msg , packet1.time , packet1.senseTime , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.alive );
    mavlink_msg_dataahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataahrs_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.senseTime , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.alive );
    mavlink_msg_dataahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dataahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataahrs_send(MAVLINK_COMM_1 , packet1.time , packet1.senseTime , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.alive );
    mavlink_msg_dataahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dataair(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataAir >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dataair_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,101
    };
    mavlink_dataair_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.senseTime = packet_in.senseTime;
        packet1.dynamicPress = packet_in.dynamicPress;
        packet1.velocity = packet_in.velocity;
        packet1.baroPress = packet_in.baroPress;
        packet1.density = packet_in.density;
        packet1.temp = packet_in.temp;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataAir_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataAir_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataair_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dataair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataair_pack(system_id, component_id, &msg , packet1.time , packet1.senseTime , packet1.dynamicPress , packet1.velocity , packet1.baroPress , packet1.density , packet1.temp , packet1.alive );
    mavlink_msg_dataair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataair_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.senseTime , packet1.dynamicPress , packet1.velocity , packet1.baroPress , packet1.density , packet1.temp , packet1.alive );
    mavlink_msg_dataair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dataair_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dataair_send(MAVLINK_COMM_1 , packet1.time , packet1.senseTime , packet1.dynamicPress , packet1.velocity , packet1.baroPress , packet1.density , packet1.temp , packet1.alive );
    mavlink_msg_dataair_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_datasfusion(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataSFusion >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_datasfusion_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,605.0,633.0,661.0,689.0,717.0,745.0,773.0,801.0,829.0,857.0,885.0,133
    };
    mavlink_datasfusion_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.gyrX = packet_in.gyrX;
        packet1.gyrY = packet_in.gyrY;
        packet1.gyrZ = packet_in.gyrZ;
        packet1.accX = packet_in.accX;
        packet1.accY = packet_in.accY;
        packet1.accZ = packet_in.accZ;
        packet1.magX = packet_in.magX;
        packet1.magY = packet_in.magY;
        packet1.magZ = packet_in.magZ;
        packet1.temp = packet_in.temp;
        packet1.press = packet_in.press;
        packet1.phi = packet_in.phi;
        packet1.the = packet_in.the;
        packet1.psi = packet_in.psi;
        packet1.q0 = packet_in.q0;
        packet1.q1 = packet_in.q1;
        packet1.q2 = packet_in.q2;
        packet1.q3 = packet_in.q3;
        packet1.posN = packet_in.posN;
        packet1.posE = packet_in.posE;
        packet1.posD = packet_in.posD;
        packet1.speedN = packet_in.speedN;
        packet1.speedE = packet_in.speedE;
        packet1.speedD = packet_in.speedD;
        packet1.windN = packet_in.windN;
        packet1.windE = packet_in.windE;
        packet1.windD = packet_in.windD;
        packet1.ssa = packet_in.ssa;
        packet1.aoa = packet_in.aoa;
        packet1.gamma = packet_in.gamma;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataSFusion_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataSFusion_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datasfusion_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_datasfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datasfusion_pack(system_id, component_id, &msg , packet1.time , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.posN , packet1.posE , packet1.posD , packet1.speedN , packet1.speedE , packet1.speedD , packet1.windN , packet1.windE , packet1.windD , packet1.ssa , packet1.aoa , packet1.gamma , packet1.alive );
    mavlink_msg_datasfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datasfusion_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.posN , packet1.posE , packet1.posD , packet1.speedN , packet1.speedE , packet1.speedD , packet1.windN , packet1.windE , packet1.windD , packet1.ssa , packet1.aoa , packet1.gamma , packet1.alive );
    mavlink_msg_datasfusion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_datasfusion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datasfusion_send(MAVLINK_COMM_1 , packet1.time , packet1.gyrX , packet1.gyrY , packet1.gyrZ , packet1.accX , packet1.accY , packet1.accZ , packet1.magX , packet1.magY , packet1.magZ , packet1.temp , packet1.press , packet1.phi , packet1.the , packet1.psi , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.posN , packet1.posE , packet1.posD , packet1.speedN , packet1.speedE , packet1.speedD , packet1.windN , packet1.windE , packet1.windD , packet1.ssa , packet1.aoa , packet1.gamma , packet1.alive );
    mavlink_msg_datasfusion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_datactrl(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataCtrl >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_datactrl_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,89
    };
    mavlink_datactrl_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.xi = packet_in.xi;
        packet1.eta = packet_in.eta;
        packet1.zeta = packet_in.zeta;
        packet1.etaT = packet_in.etaT;
        packet1.etaF = packet_in.etaF;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataCtrl_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataCtrl_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datactrl_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_datactrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datactrl_pack(system_id, component_id, &msg , packet1.time , packet1.xi , packet1.eta , packet1.zeta , packet1.etaT , packet1.etaF , packet1.alive );
    mavlink_msg_datactrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datactrl_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.xi , packet1.eta , packet1.zeta , packet1.etaT , packet1.etaF , packet1.alive );
    mavlink_msg_datactrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_datactrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datactrl_send(MAVLINK_COMM_1 , packet1.time , packet1.xi , packet1.eta , packet1.zeta , packet1.etaT , packet1.etaF , packet1.alive );
    mavlink_msg_datactrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_datapsu(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataPsu >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_datapsu_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,149
    };
    mavlink_datapsu_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.senseTime = packet_in.senseTime;
        packet1.mainVolt = packet_in.mainVolt;
        packet1.mainCurr = packet_in.mainCurr;
        packet1.mainPow = packet_in.mainPow;
        packet1.pwrVolt = packet_in.pwrVolt;
        packet1.pwrCurr = packet_in.pwrCurr;
        packet1.pwrPow = packet_in.pwrPow;
        packet1.sysVolt = packet_in.sysVolt;
        packet1.sysCurr = packet_in.sysCurr;
        packet1.sysPow = packet_in.sysPow;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataPsu_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataPsu_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datapsu_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_datapsu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datapsu_pack(system_id, component_id, &msg , packet1.time , packet1.senseTime , packet1.mainVolt , packet1.mainCurr , packet1.mainPow , packet1.pwrVolt , packet1.pwrCurr , packet1.pwrPow , packet1.sysVolt , packet1.sysCurr , packet1.sysPow , packet1.alive );
    mavlink_msg_datapsu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datapsu_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.senseTime , packet1.mainVolt , packet1.mainCurr , packet1.mainPow , packet1.pwrVolt , packet1.pwrCurr , packet1.pwrPow , packet1.sysVolt , packet1.sysCurr , packet1.sysPow , packet1.alive );
    mavlink_msg_datapsu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_datapsu_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datapsu_send(MAVLINK_COMM_1 , packet1.time , packet1.senseTime , packet1.mainVolt , packet1.mainCurr , packet1.mainPow , packet1.pwrVolt , packet1.pwrCurr , packet1.pwrPow , packet1.sysVolt , packet1.sysCurr , packet1.sysPow , packet1.alive );
    mavlink_msg_datapsu_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_datawatchdog(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DataWatchdog >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_datawatchdog_t packet_in = {
        93372036854775807ULL,29,96,163,230,41,108,175,242,53,120,187,254,65
    };
    mavlink_datawatchdog_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.allAlive = packet_in.allAlive;
        packet1.ahrsAlive = packet_in.ahrsAlive;
        packet1.airAlive = packet_in.airAlive;
        packet1.ctrlAlive = packet_in.ctrlAlive;
        packet1.downlinkAlive = packet_in.downlinkAlive;
        packet1.gpsAlive = packet_in.gpsAlive;
        packet1.logAlive = packet_in.logAlive;
        packet1.psuAlive = packet_in.psuAlive;
        packet1.raiInAlive = packet_in.raiInAlive;
        packet1.raiOutAlive = packet_in.raiOutAlive;
        packet1.sFusionAlive = packet_in.sFusionAlive;
        packet1.uplinkAlive = packet_in.uplinkAlive;
        packet1.alive = packet_in.alive;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DataWatchdog_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DataWatchdog_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datawatchdog_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_datawatchdog_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datawatchdog_pack(system_id, component_id, &msg , packet1.time , packet1.allAlive , packet1.ahrsAlive , packet1.airAlive , packet1.ctrlAlive , packet1.downlinkAlive , packet1.gpsAlive , packet1.logAlive , packet1.psuAlive , packet1.raiInAlive , packet1.raiOutAlive , packet1.sFusionAlive , packet1.uplinkAlive , packet1.alive );
    mavlink_msg_datawatchdog_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datawatchdog_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.allAlive , packet1.ahrsAlive , packet1.airAlive , packet1.ctrlAlive , packet1.downlinkAlive , packet1.gpsAlive , packet1.logAlive , packet1.psuAlive , packet1.raiInAlive , packet1.raiOutAlive , packet1.sFusionAlive , packet1.uplinkAlive , packet1.alive );
    mavlink_msg_datawatchdog_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_datawatchdog_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_datawatchdog_send(MAVLINK_COMM_1 , packet1.time , packet1.allAlive , packet1.ahrsAlive , packet1.airAlive , packet1.ctrlAlive , packet1.downlinkAlive , packet1.gpsAlive , packet1.logAlive , packet1.psuAlive , packet1.raiInAlive , packet1.raiOutAlive , packet1.sFusionAlive , packet1.uplinkAlive , packet1.alive );
    mavlink_msg_datawatchdog_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_downlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_dataraiin(system_id, component_id, last_msg);
    mavlink_test_dataraiout(system_id, component_id, last_msg);
    mavlink_test_dataahrs(system_id, component_id, last_msg);
    mavlink_test_dataair(system_id, component_id, last_msg);
    mavlink_test_datasfusion(system_id, component_id, last_msg);
    mavlink_test_datactrl(system_id, component_id, last_msg);
    mavlink_test_datapsu(system_id, component_id, last_msg);
    mavlink_test_datawatchdog(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // DOWNLINK_TESTSUITE_H
