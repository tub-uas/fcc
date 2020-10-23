/** @file
 *	@brief MAVLink comm testsuite protocol generated from downlink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "downlink.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(downlink, DataRaiIn)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataRaiIn packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.chnl = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.roll = 101.0;
    packet_in.pitch = 129.0;
    packet_in.yaw = 157.0;
    packet_in.thr = 185.0;
    packet_in.fltMode = 19939;
    packet_in.alive = 39;

    mavlink::downlink::msg::DataRaiIn packet1{};
    mavlink::downlink::msg::DataRaiIn packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.chnl, packet2.chnl);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.thr, packet2.thr);
    EXPECT_EQ(packet1.fltMode, packet2.fltMode);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataRaiIn)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiin_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, { 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }, 19939, 39
    };

    mavlink::downlink::msg::DataRaiIn packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.chnl = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.roll = 101.0;
    packet_in.pitch = 129.0;
    packet_in.yaw = 157.0;
    packet_in.thr = 185.0;
    packet_in.fltMode = 19939;
    packet_in.alive = 39;

    mavlink::downlink::msg::DataRaiIn packet2{};

    mavlink_msg_dataraiin_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.chnl, packet2.chnl);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.thr, packet2.thr);
    EXPECT_EQ(packet_in.fltMode, packet2.fltMode);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataRaiOut)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataRaiOut packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.chnl = {{ 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }};
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.thr = 157.0;
    packet_in.fltMode = 19731;
    packet_in.alive = 27;

    mavlink::downlink::msg::DataRaiOut packet1{};
    mavlink::downlink::msg::DataRaiOut packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.chnl, packet2.chnl);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.thr, packet2.thr);
    EXPECT_EQ(packet1.fltMode, packet2.fltMode);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataRaiOut)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiout_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, { 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }, 19731, 27
    };

    mavlink::downlink::msg::DataRaiOut packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.chnl = {{ 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }};
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.thr = 157.0;
    packet_in.fltMode = 19731;
    packet_in.alive = 27;

    mavlink::downlink::msg::DataRaiOut packet2{};

    mavlink_msg_dataraiout_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.chnl, packet2.chnl);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.thr, packet2.thr);
    EXPECT_EQ(packet_in.fltMode, packet2.fltMode);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataAhrs)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataAhrs packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.gyrX = 101.0;
    packet_in.gyrY = 129.0;
    packet_in.gyrZ = 157.0;
    packet_in.accX = 185.0;
    packet_in.accY = 213.0;
    packet_in.accZ = 241.0;
    packet_in.magX = 269.0;
    packet_in.magY = 297.0;
    packet_in.magZ = 325.0;
    packet_in.temp = 353.0;
    packet_in.press = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.q0 = 493.0;
    packet_in.q1 = 521.0;
    packet_in.q2 = 549.0;
    packet_in.q3 = 577.0;
    packet_in.alive = 1;

    mavlink::downlink::msg::DataAhrs packet1{};
    mavlink::downlink::msg::DataAhrs packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.gyrX, packet2.gyrX);
    EXPECT_EQ(packet1.gyrY, packet2.gyrY);
    EXPECT_EQ(packet1.gyrZ, packet2.gyrZ);
    EXPECT_EQ(packet1.accX, packet2.accX);
    EXPECT_EQ(packet1.accY, packet2.accY);
    EXPECT_EQ(packet1.accZ, packet2.accZ);
    EXPECT_EQ(packet1.magX, packet2.magX);
    EXPECT_EQ(packet1.magY, packet2.magY);
    EXPECT_EQ(packet1.magZ, packet2.magZ);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.press, packet2.press);
    EXPECT_EQ(packet1.phi, packet2.phi);
    EXPECT_EQ(packet1.the, packet2.the);
    EXPECT_EQ(packet1.psi, packet2.psi);
    EXPECT_EQ(packet1.q0, packet2.q0);
    EXPECT_EQ(packet1.q1, packet2.q1);
    EXPECT_EQ(packet1.q2, packet2.q2);
    EXPECT_EQ(packet1.q3, packet2.q3);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataAhrs)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataahrs_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 1
    };

    mavlink::downlink::msg::DataAhrs packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.gyrX = 101.0;
    packet_in.gyrY = 129.0;
    packet_in.gyrZ = 157.0;
    packet_in.accX = 185.0;
    packet_in.accY = 213.0;
    packet_in.accZ = 241.0;
    packet_in.magX = 269.0;
    packet_in.magY = 297.0;
    packet_in.magZ = 325.0;
    packet_in.temp = 353.0;
    packet_in.press = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.q0 = 493.0;
    packet_in.q1 = 521.0;
    packet_in.q2 = 549.0;
    packet_in.q3 = 577.0;
    packet_in.alive = 1;

    mavlink::downlink::msg::DataAhrs packet2{};

    mavlink_msg_dataahrs_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.gyrX, packet2.gyrX);
    EXPECT_EQ(packet_in.gyrY, packet2.gyrY);
    EXPECT_EQ(packet_in.gyrZ, packet2.gyrZ);
    EXPECT_EQ(packet_in.accX, packet2.accX);
    EXPECT_EQ(packet_in.accY, packet2.accY);
    EXPECT_EQ(packet_in.accZ, packet2.accZ);
    EXPECT_EQ(packet_in.magX, packet2.magX);
    EXPECT_EQ(packet_in.magY, packet2.magY);
    EXPECT_EQ(packet_in.magZ, packet2.magZ);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.press, packet2.press);
    EXPECT_EQ(packet_in.phi, packet2.phi);
    EXPECT_EQ(packet_in.the, packet2.the);
    EXPECT_EQ(packet_in.psi, packet2.psi);
    EXPECT_EQ(packet_in.q0, packet2.q0);
    EXPECT_EQ(packet_in.q1, packet2.q1);
    EXPECT_EQ(packet_in.q2, packet2.q2);
    EXPECT_EQ(packet_in.q3, packet2.q3);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataAir)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataAir packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.dynamicPress = 101.0;
    packet_in.velocity = 129.0;
    packet_in.baroPress = 157.0;
    packet_in.density = 185.0;
    packet_in.temp = 213.0;
    packet_in.alive = 101;

    mavlink::downlink::msg::DataAir packet1{};
    mavlink::downlink::msg::DataAir packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.dynamicPress, packet2.dynamicPress);
    EXPECT_EQ(packet1.velocity, packet2.velocity);
    EXPECT_EQ(packet1.baroPress, packet2.baroPress);
    EXPECT_EQ(packet1.density, packet2.density);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataAir)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataair_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 101
    };

    mavlink::downlink::msg::DataAir packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.dynamicPress = 101.0;
    packet_in.velocity = 129.0;
    packet_in.baroPress = 157.0;
    packet_in.density = 185.0;
    packet_in.temp = 213.0;
    packet_in.alive = 101;

    mavlink::downlink::msg::DataAir packet2{};

    mavlink_msg_dataair_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.dynamicPress, packet2.dynamicPress);
    EXPECT_EQ(packet_in.velocity, packet2.velocity);
    EXPECT_EQ(packet_in.baroPress, packet2.baroPress);
    EXPECT_EQ(packet_in.density, packet2.density);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataSFusion)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataSFusion packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.gyrX = 73.0;
    packet_in.gyrY = 101.0;
    packet_in.gyrZ = 129.0;
    packet_in.accX = 157.0;
    packet_in.accY = 185.0;
    packet_in.accZ = 213.0;
    packet_in.magX = 241.0;
    packet_in.magY = 269.0;
    packet_in.magZ = 297.0;
    packet_in.temp = 325.0;
    packet_in.press = 353.0;
    packet_in.phi = 381.0;
    packet_in.the = 409.0;
    packet_in.psi = 437.0;
    packet_in.q0 = 465.0;
    packet_in.q1 = 493.0;
    packet_in.q2 = 521.0;
    packet_in.q3 = 549.0;
    packet_in.posN = 577.0;
    packet_in.posE = 605.0;
    packet_in.posD = 633.0;
    packet_in.speedN = 661.0;
    packet_in.speedE = 689.0;
    packet_in.speedD = 717.0;
    packet_in.windN = 745.0;
    packet_in.windE = 773.0;
    packet_in.windD = 801.0;
    packet_in.ssa = 829.0;
    packet_in.aoa = 857.0;
    packet_in.gamma = 885.0;
    packet_in.alive = 133;

    mavlink::downlink::msg::DataSFusion packet1{};
    mavlink::downlink::msg::DataSFusion packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.gyrX, packet2.gyrX);
    EXPECT_EQ(packet1.gyrY, packet2.gyrY);
    EXPECT_EQ(packet1.gyrZ, packet2.gyrZ);
    EXPECT_EQ(packet1.accX, packet2.accX);
    EXPECT_EQ(packet1.accY, packet2.accY);
    EXPECT_EQ(packet1.accZ, packet2.accZ);
    EXPECT_EQ(packet1.magX, packet2.magX);
    EXPECT_EQ(packet1.magY, packet2.magY);
    EXPECT_EQ(packet1.magZ, packet2.magZ);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.press, packet2.press);
    EXPECT_EQ(packet1.phi, packet2.phi);
    EXPECT_EQ(packet1.the, packet2.the);
    EXPECT_EQ(packet1.psi, packet2.psi);
    EXPECT_EQ(packet1.q0, packet2.q0);
    EXPECT_EQ(packet1.q1, packet2.q1);
    EXPECT_EQ(packet1.q2, packet2.q2);
    EXPECT_EQ(packet1.q3, packet2.q3);
    EXPECT_EQ(packet1.posN, packet2.posN);
    EXPECT_EQ(packet1.posE, packet2.posE);
    EXPECT_EQ(packet1.posD, packet2.posD);
    EXPECT_EQ(packet1.speedN, packet2.speedN);
    EXPECT_EQ(packet1.speedE, packet2.speedE);
    EXPECT_EQ(packet1.speedD, packet2.speedD);
    EXPECT_EQ(packet1.windN, packet2.windN);
    EXPECT_EQ(packet1.windE, packet2.windE);
    EXPECT_EQ(packet1.windD, packet2.windD);
    EXPECT_EQ(packet1.ssa, packet2.ssa);
    EXPECT_EQ(packet1.aoa, packet2.aoa);
    EXPECT_EQ(packet1.gamma, packet2.gamma);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataSFusion)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datasfusion_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 605.0, 633.0, 661.0, 689.0, 717.0, 745.0, 773.0, 801.0, 829.0, 857.0, 885.0, 133
    };

    mavlink::downlink::msg::DataSFusion packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.gyrX = 73.0;
    packet_in.gyrY = 101.0;
    packet_in.gyrZ = 129.0;
    packet_in.accX = 157.0;
    packet_in.accY = 185.0;
    packet_in.accZ = 213.0;
    packet_in.magX = 241.0;
    packet_in.magY = 269.0;
    packet_in.magZ = 297.0;
    packet_in.temp = 325.0;
    packet_in.press = 353.0;
    packet_in.phi = 381.0;
    packet_in.the = 409.0;
    packet_in.psi = 437.0;
    packet_in.q0 = 465.0;
    packet_in.q1 = 493.0;
    packet_in.q2 = 521.0;
    packet_in.q3 = 549.0;
    packet_in.posN = 577.0;
    packet_in.posE = 605.0;
    packet_in.posD = 633.0;
    packet_in.speedN = 661.0;
    packet_in.speedE = 689.0;
    packet_in.speedD = 717.0;
    packet_in.windN = 745.0;
    packet_in.windE = 773.0;
    packet_in.windD = 801.0;
    packet_in.ssa = 829.0;
    packet_in.aoa = 857.0;
    packet_in.gamma = 885.0;
    packet_in.alive = 133;

    mavlink::downlink::msg::DataSFusion packet2{};

    mavlink_msg_datasfusion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.gyrX, packet2.gyrX);
    EXPECT_EQ(packet_in.gyrY, packet2.gyrY);
    EXPECT_EQ(packet_in.gyrZ, packet2.gyrZ);
    EXPECT_EQ(packet_in.accX, packet2.accX);
    EXPECT_EQ(packet_in.accY, packet2.accY);
    EXPECT_EQ(packet_in.accZ, packet2.accZ);
    EXPECT_EQ(packet_in.magX, packet2.magX);
    EXPECT_EQ(packet_in.magY, packet2.magY);
    EXPECT_EQ(packet_in.magZ, packet2.magZ);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.press, packet2.press);
    EXPECT_EQ(packet_in.phi, packet2.phi);
    EXPECT_EQ(packet_in.the, packet2.the);
    EXPECT_EQ(packet_in.psi, packet2.psi);
    EXPECT_EQ(packet_in.q0, packet2.q0);
    EXPECT_EQ(packet_in.q1, packet2.q1);
    EXPECT_EQ(packet_in.q2, packet2.q2);
    EXPECT_EQ(packet_in.q3, packet2.q3);
    EXPECT_EQ(packet_in.posN, packet2.posN);
    EXPECT_EQ(packet_in.posE, packet2.posE);
    EXPECT_EQ(packet_in.posD, packet2.posD);
    EXPECT_EQ(packet_in.speedN, packet2.speedN);
    EXPECT_EQ(packet_in.speedE, packet2.speedE);
    EXPECT_EQ(packet_in.speedD, packet2.speedD);
    EXPECT_EQ(packet_in.windN, packet2.windN);
    EXPECT_EQ(packet_in.windE, packet2.windE);
    EXPECT_EQ(packet_in.windD, packet2.windD);
    EXPECT_EQ(packet_in.ssa, packet2.ssa);
    EXPECT_EQ(packet_in.aoa, packet2.aoa);
    EXPECT_EQ(packet_in.gamma, packet2.gamma);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataCtrl)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataCtrl packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.xi = 73.0;
    packet_in.eta = 101.0;
    packet_in.zeta = 129.0;
    packet_in.etaT = 157.0;
    packet_in.etaF = 185.0;
    packet_in.alive = 89;

    mavlink::downlink::msg::DataCtrl packet1{};
    mavlink::downlink::msg::DataCtrl packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.xi, packet2.xi);
    EXPECT_EQ(packet1.eta, packet2.eta);
    EXPECT_EQ(packet1.zeta, packet2.zeta);
    EXPECT_EQ(packet1.etaT, packet2.etaT);
    EXPECT_EQ(packet1.etaF, packet2.etaF);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataCtrl)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datactrl_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 89
    };

    mavlink::downlink::msg::DataCtrl packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.xi = 73.0;
    packet_in.eta = 101.0;
    packet_in.zeta = 129.0;
    packet_in.etaT = 157.0;
    packet_in.etaF = 185.0;
    packet_in.alive = 89;

    mavlink::downlink::msg::DataCtrl packet2{};

    mavlink_msg_datactrl_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.xi, packet2.xi);
    EXPECT_EQ(packet_in.eta, packet2.eta);
    EXPECT_EQ(packet_in.zeta, packet2.zeta);
    EXPECT_EQ(packet_in.etaT, packet2.etaT);
    EXPECT_EQ(packet_in.etaF, packet2.etaF);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataPsu)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataPsu packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.mainVolt = 101.0;
    packet_in.mainCurr = 129.0;
    packet_in.mainPow = 157.0;
    packet_in.pwrVolt = 185.0;
    packet_in.pwrCurr = 213.0;
    packet_in.pwrPow = 241.0;
    packet_in.sysVolt = 269.0;
    packet_in.sysCurr = 297.0;
    packet_in.sysPow = 325.0;
    packet_in.alive = 149;

    mavlink::downlink::msg::DataPsu packet1{};
    mavlink::downlink::msg::DataPsu packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.mainVolt, packet2.mainVolt);
    EXPECT_EQ(packet1.mainCurr, packet2.mainCurr);
    EXPECT_EQ(packet1.mainPow, packet2.mainPow);
    EXPECT_EQ(packet1.pwrVolt, packet2.pwrVolt);
    EXPECT_EQ(packet1.pwrCurr, packet2.pwrCurr);
    EXPECT_EQ(packet1.pwrPow, packet2.pwrPow);
    EXPECT_EQ(packet1.sysVolt, packet2.sysVolt);
    EXPECT_EQ(packet1.sysCurr, packet2.sysCurr);
    EXPECT_EQ(packet1.sysPow, packet2.sysPow);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataPsu)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datapsu_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 149
    };

    mavlink::downlink::msg::DataPsu packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.mainVolt = 101.0;
    packet_in.mainCurr = 129.0;
    packet_in.mainPow = 157.0;
    packet_in.pwrVolt = 185.0;
    packet_in.pwrCurr = 213.0;
    packet_in.pwrPow = 241.0;
    packet_in.sysVolt = 269.0;
    packet_in.sysCurr = 297.0;
    packet_in.sysPow = 325.0;
    packet_in.alive = 149;

    mavlink::downlink::msg::DataPsu packet2{};

    mavlink_msg_datapsu_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.mainVolt, packet2.mainVolt);
    EXPECT_EQ(packet_in.mainCurr, packet2.mainCurr);
    EXPECT_EQ(packet_in.mainPow, packet2.mainPow);
    EXPECT_EQ(packet_in.pwrVolt, packet2.pwrVolt);
    EXPECT_EQ(packet_in.pwrCurr, packet2.pwrCurr);
    EXPECT_EQ(packet_in.pwrPow, packet2.pwrPow);
    EXPECT_EQ(packet_in.sysVolt, packet2.sysVolt);
    EXPECT_EQ(packet_in.sysCurr, packet2.sysCurr);
    EXPECT_EQ(packet_in.sysPow, packet2.sysPow);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataWatchdog)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataWatchdog packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.allAlive = 29;
    packet_in.ahrsAlive = 96;
    packet_in.airAlive = 163;
    packet_in.ctrlAlive = 230;
    packet_in.downlinkAlive = 41;
    packet_in.gpsAlive = 108;
    packet_in.logAlive = 175;
    packet_in.psuAlive = 242;
    packet_in.raiInAlive = 53;
    packet_in.raiOutAlive = 120;
    packet_in.sFusionAlive = 187;
    packet_in.uplinkAlive = 254;
    packet_in.alive = 65;

    mavlink::downlink::msg::DataWatchdog packet1{};
    mavlink::downlink::msg::DataWatchdog packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.allAlive, packet2.allAlive);
    EXPECT_EQ(packet1.ahrsAlive, packet2.ahrsAlive);
    EXPECT_EQ(packet1.airAlive, packet2.airAlive);
    EXPECT_EQ(packet1.ctrlAlive, packet2.ctrlAlive);
    EXPECT_EQ(packet1.downlinkAlive, packet2.downlinkAlive);
    EXPECT_EQ(packet1.gpsAlive, packet2.gpsAlive);
    EXPECT_EQ(packet1.logAlive, packet2.logAlive);
    EXPECT_EQ(packet1.psuAlive, packet2.psuAlive);
    EXPECT_EQ(packet1.raiInAlive, packet2.raiInAlive);
    EXPECT_EQ(packet1.raiOutAlive, packet2.raiOutAlive);
    EXPECT_EQ(packet1.sFusionAlive, packet2.sFusionAlive);
    EXPECT_EQ(packet1.uplinkAlive, packet2.uplinkAlive);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataWatchdog)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datawatchdog_t packet_c {
         93372036854775807ULL, 29, 96, 163, 230, 41, 108, 175, 242, 53, 120, 187, 254, 65
    };

    mavlink::downlink::msg::DataWatchdog packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.allAlive = 29;
    packet_in.ahrsAlive = 96;
    packet_in.airAlive = 163;
    packet_in.ctrlAlive = 230;
    packet_in.downlinkAlive = 41;
    packet_in.gpsAlive = 108;
    packet_in.logAlive = 175;
    packet_in.psuAlive = 242;
    packet_in.raiInAlive = 53;
    packet_in.raiOutAlive = 120;
    packet_in.sFusionAlive = 187;
    packet_in.uplinkAlive = 254;
    packet_in.alive = 65;

    mavlink::downlink::msg::DataWatchdog packet2{};

    mavlink_msg_datawatchdog_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.allAlive, packet2.allAlive);
    EXPECT_EQ(packet_in.ahrsAlive, packet2.ahrsAlive);
    EXPECT_EQ(packet_in.airAlive, packet2.airAlive);
    EXPECT_EQ(packet_in.ctrlAlive, packet2.ctrlAlive);
    EXPECT_EQ(packet_in.downlinkAlive, packet2.downlinkAlive);
    EXPECT_EQ(packet_in.gpsAlive, packet2.gpsAlive);
    EXPECT_EQ(packet_in.logAlive, packet2.logAlive);
    EXPECT_EQ(packet_in.psuAlive, packet2.psuAlive);
    EXPECT_EQ(packet_in.raiInAlive, packet2.raiInAlive);
    EXPECT_EQ(packet_in.raiOutAlive, packet2.raiOutAlive);
    EXPECT_EQ(packet_in.sFusionAlive, packet2.sFusionAlive);
    EXPECT_EQ(packet_in.uplinkAlive, packet2.uplinkAlive);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(downlink, DataGps)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::downlink::msg::DataGps packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.lat = 101.0;
    packet_in.lon = 129.0;
    packet_in.alt = 157.0;
    packet_in.speed = 185.0;
    packet_in.cog = 213.0;
    packet_in.sats = 241.0;
    packet_in.fix = 269.0;
    packet_in.fixMode = 297.0;
    packet_in.dopP = 325.0;
    packet_in.dopH = 353.0;
    packet_in.dopV = 381.0;
    packet_in.alive = 173;

    mavlink::downlink::msg::DataGps packet1{};
    mavlink::downlink::msg::DataGps packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lon, packet2.lon);
    EXPECT_EQ(packet1.alt, packet2.alt);
    EXPECT_EQ(packet1.speed, packet2.speed);
    EXPECT_EQ(packet1.cog, packet2.cog);
    EXPECT_EQ(packet1.sats, packet2.sats);
    EXPECT_EQ(packet1.fix, packet2.fix);
    EXPECT_EQ(packet1.fixMode, packet2.fixMode);
    EXPECT_EQ(packet1.dopP, packet2.dopP);
    EXPECT_EQ(packet1.dopH, packet2.dopH);
    EXPECT_EQ(packet1.dopV, packet2.dopV);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataGps)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datagps_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 173
    };

    mavlink::downlink::msg::DataGps packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.lat = 101.0;
    packet_in.lon = 129.0;
    packet_in.alt = 157.0;
    packet_in.speed = 185.0;
    packet_in.cog = 213.0;
    packet_in.sats = 241.0;
    packet_in.fix = 269.0;
    packet_in.fixMode = 297.0;
    packet_in.dopP = 325.0;
    packet_in.dopH = 353.0;
    packet_in.dopV = 381.0;
    packet_in.alive = 173;

    mavlink::downlink::msg::DataGps packet2{};

    mavlink_msg_datagps_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lon, packet2.lon);
    EXPECT_EQ(packet_in.alt, packet2.alt);
    EXPECT_EQ(packet_in.speed, packet2.speed);
    EXPECT_EQ(packet_in.cog, packet2.cog);
    EXPECT_EQ(packet_in.sats, packet2.sats);
    EXPECT_EQ(packet_in.fix, packet2.fix);
    EXPECT_EQ(packet_in.fixMode, packet2.fixMode);
    EXPECT_EQ(packet_in.dopP, packet2.dopP);
    EXPECT_EQ(packet_in.dopH, packet2.dopH);
    EXPECT_EQ(packet_in.dopV, packet2.dopV);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
