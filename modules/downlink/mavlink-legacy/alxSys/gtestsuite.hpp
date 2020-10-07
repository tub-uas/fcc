/** @file
 *	@brief MAVLink comm testsuite protocol generated from alxSys.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "alxSys.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(alxSys, DataRaiIn)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataRaiIn packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.channels = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.roll = 101.0;
    packet_in.pitch = 129.0;
    packet_in.yaw = 157.0;
    packet_in.thr = 185.0;
    packet_in.fltmode = 19939;
    packet_in.alive = 39;

    mavlink::alxSys::msg::DataRaiIn packet1{};
    mavlink::alxSys::msg::DataRaiIn packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.channels, packet2.channels);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.thr, packet2.thr);
    EXPECT_EQ(packet1.fltmode, packet2.fltmode);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, DataRaiIn)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiin_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, { 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }, 19939, 39
    };

    mavlink::alxSys::msg::DataRaiIn packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.channels = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.roll = 101.0;
    packet_in.pitch = 129.0;
    packet_in.yaw = 157.0;
    packet_in.thr = 185.0;
    packet_in.fltmode = 19939;
    packet_in.alive = 39;

    mavlink::alxSys::msg::DataRaiIn packet2{};

    mavlink_msg_dataraiin_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.channels, packet2.channels);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.thr, packet2.thr);
    EXPECT_EQ(packet_in.fltmode, packet2.fltmode);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, DataRaiOut)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataRaiOut packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.chnls = {{ 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }};
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.thr = 157.0;
    packet_in.fltMode = 19731;
    packet_in.alive = 27;

    mavlink::alxSys::msg::DataRaiOut packet1{};
    mavlink::alxSys::msg::DataRaiOut packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.chnls, packet2.chnls);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.thr, packet2.thr);
    EXPECT_EQ(packet1.fltMode, packet2.fltMode);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, DataRaiOut)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiout_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, { 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }, 19731, 27
    };

    mavlink::alxSys::msg::DataRaiOut packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.chnls = {{ 18483, 18484, 18485, 18486, 18487, 18488, 18489, 18490, 18491, 18492, 18493, 18494 }};
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.thr = 157.0;
    packet_in.fltMode = 19731;
    packet_in.alive = 27;

    mavlink::alxSys::msg::DataRaiOut packet2{};

    mavlink_msg_dataraiout_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.chnls, packet2.chnls);
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

TEST(alxSys, DataAhrs)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataAhrs packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.gX = 101.0;
    packet_in.gY = 129.0;
    packet_in.gZ = 157.0;
    packet_in.aX = 185.0;
    packet_in.aY = 213.0;
    packet_in.aZ = 241.0;
    packet_in.mX = 269.0;
    packet_in.mY = 297.0;
    packet_in.mZ = 325.0;
    packet_in.temp = 353.0;
    packet_in.baro_ahrs = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.q0 = 493.0;
    packet_in.q1 = 521.0;
    packet_in.q2 = 549.0;
    packet_in.q3 = 577.0;
    packet_in.alive = 1;

    mavlink::alxSys::msg::DataAhrs packet1{};
    mavlink::alxSys::msg::DataAhrs packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.gX, packet2.gX);
    EXPECT_EQ(packet1.gY, packet2.gY);
    EXPECT_EQ(packet1.gZ, packet2.gZ);
    EXPECT_EQ(packet1.aX, packet2.aX);
    EXPECT_EQ(packet1.aY, packet2.aY);
    EXPECT_EQ(packet1.aZ, packet2.aZ);
    EXPECT_EQ(packet1.mX, packet2.mX);
    EXPECT_EQ(packet1.mY, packet2.mY);
    EXPECT_EQ(packet1.mZ, packet2.mZ);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.baro_ahrs, packet2.baro_ahrs);
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
TEST(alxSys_interop, DataAhrs)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataahrs_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 1
    };

    mavlink::alxSys::msg::DataAhrs packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.gX = 101.0;
    packet_in.gY = 129.0;
    packet_in.gZ = 157.0;
    packet_in.aX = 185.0;
    packet_in.aY = 213.0;
    packet_in.aZ = 241.0;
    packet_in.mX = 269.0;
    packet_in.mY = 297.0;
    packet_in.mZ = 325.0;
    packet_in.temp = 353.0;
    packet_in.baro_ahrs = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.q0 = 493.0;
    packet_in.q1 = 521.0;
    packet_in.q2 = 549.0;
    packet_in.q3 = 577.0;
    packet_in.alive = 1;

    mavlink::alxSys::msg::DataAhrs packet2{};

    mavlink_msg_dataahrs_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.gX, packet2.gX);
    EXPECT_EQ(packet_in.gY, packet2.gY);
    EXPECT_EQ(packet_in.gZ, packet2.gZ);
    EXPECT_EQ(packet_in.aX, packet2.aX);
    EXPECT_EQ(packet_in.aY, packet2.aY);
    EXPECT_EQ(packet_in.aZ, packet2.aZ);
    EXPECT_EQ(packet_in.mX, packet2.mX);
    EXPECT_EQ(packet_in.mY, packet2.mY);
    EXPECT_EQ(packet_in.mZ, packet2.mZ);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.baro_ahrs, packet2.baro_ahrs);
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

TEST(alxSys, DataAir)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataAir packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.TAS = 101.0;
    packet_in.baro_air = 129.0;
    packet_in.density = 157.0;
    packet_in.temp = 185.0;
    packet_in.alive = 89;

    mavlink::alxSys::msg::DataAir packet1{};
    mavlink::alxSys::msg::DataAir packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.TAS, packet2.TAS);
    EXPECT_EQ(packet1.baro_air, packet2.baro_air);
    EXPECT_EQ(packet1.density, packet2.density);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, DataAir)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataair_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 89
    };

    mavlink::alxSys::msg::DataAir packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.TAS = 101.0;
    packet_in.baro_air = 129.0;
    packet_in.density = 157.0;
    packet_in.temp = 185.0;
    packet_in.alive = 89;

    mavlink::alxSys::msg::DataAir packet2{};

    mavlink_msg_dataair_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.TAS, packet2.TAS);
    EXPECT_EQ(packet_in.baro_air, packet2.baro_air);
    EXPECT_EQ(packet_in.density, packet2.density);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, DataSfusion)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataSfusion packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.phi = 73.0;
    packet_in.the = 101.0;
    packet_in.psi = 129.0;
    packet_in.q0 = 157.0;
    packet_in.q1 = 185.0;
    packet_in.q2 = 213.0;
    packet_in.q3 = 241.0;
    packet_in.baro_fused = 269.0;
    packet_in.temp_fused = 297.0;
    packet_in.posN = 325.0;
    packet_in.posE = 353.0;
    packet_in.posD = 381.0;
    packet_in.speedN = 409.0;
    packet_in.speedE = 437.0;
    packet_in.speedD = 465.0;
    packet_in.WindN = 493.0;
    packet_in.WindE = 521.0;
    packet_in.WindD = 549.0;
    packet_in.ssa = 577.0;
    packet_in.aoa = 605.0;
    packet_in.gamma = 633.0;
    packet_in.alive = 25;

    mavlink::alxSys::msg::DataSfusion packet1{};
    mavlink::alxSys::msg::DataSfusion packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.phi, packet2.phi);
    EXPECT_EQ(packet1.the, packet2.the);
    EXPECT_EQ(packet1.psi, packet2.psi);
    EXPECT_EQ(packet1.q0, packet2.q0);
    EXPECT_EQ(packet1.q1, packet2.q1);
    EXPECT_EQ(packet1.q2, packet2.q2);
    EXPECT_EQ(packet1.q3, packet2.q3);
    EXPECT_EQ(packet1.baro_fused, packet2.baro_fused);
    EXPECT_EQ(packet1.temp_fused, packet2.temp_fused);
    EXPECT_EQ(packet1.posN, packet2.posN);
    EXPECT_EQ(packet1.posE, packet2.posE);
    EXPECT_EQ(packet1.posD, packet2.posD);
    EXPECT_EQ(packet1.speedN, packet2.speedN);
    EXPECT_EQ(packet1.speedE, packet2.speedE);
    EXPECT_EQ(packet1.speedD, packet2.speedD);
    EXPECT_EQ(packet1.WindN, packet2.WindN);
    EXPECT_EQ(packet1.WindE, packet2.WindE);
    EXPECT_EQ(packet1.WindD, packet2.WindD);
    EXPECT_EQ(packet1.ssa, packet2.ssa);
    EXPECT_EQ(packet1.aoa, packet2.aoa);
    EXPECT_EQ(packet1.gamma, packet2.gamma);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, DataSfusion)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datasfusion_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 605.0, 633.0, 25
    };

    mavlink::alxSys::msg::DataSfusion packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.phi = 73.0;
    packet_in.the = 101.0;
    packet_in.psi = 129.0;
    packet_in.q0 = 157.0;
    packet_in.q1 = 185.0;
    packet_in.q2 = 213.0;
    packet_in.q3 = 241.0;
    packet_in.baro_fused = 269.0;
    packet_in.temp_fused = 297.0;
    packet_in.posN = 325.0;
    packet_in.posE = 353.0;
    packet_in.posD = 381.0;
    packet_in.speedN = 409.0;
    packet_in.speedE = 437.0;
    packet_in.speedD = 465.0;
    packet_in.WindN = 493.0;
    packet_in.WindE = 521.0;
    packet_in.WindD = 549.0;
    packet_in.ssa = 577.0;
    packet_in.aoa = 605.0;
    packet_in.gamma = 633.0;
    packet_in.alive = 25;

    mavlink::alxSys::msg::DataSfusion packet2{};

    mavlink_msg_datasfusion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.phi, packet2.phi);
    EXPECT_EQ(packet_in.the, packet2.the);
    EXPECT_EQ(packet_in.psi, packet2.psi);
    EXPECT_EQ(packet_in.q0, packet2.q0);
    EXPECT_EQ(packet_in.q1, packet2.q1);
    EXPECT_EQ(packet_in.q2, packet2.q2);
    EXPECT_EQ(packet_in.q3, packet2.q3);
    EXPECT_EQ(packet_in.baro_fused, packet2.baro_fused);
    EXPECT_EQ(packet_in.temp_fused, packet2.temp_fused);
    EXPECT_EQ(packet_in.posN, packet2.posN);
    EXPECT_EQ(packet_in.posE, packet2.posE);
    EXPECT_EQ(packet_in.posD, packet2.posD);
    EXPECT_EQ(packet_in.speedN, packet2.speedN);
    EXPECT_EQ(packet_in.speedE, packet2.speedE);
    EXPECT_EQ(packet_in.speedD, packet2.speedD);
    EXPECT_EQ(packet_in.WindN, packet2.WindN);
    EXPECT_EQ(packet_in.WindE, packet2.WindE);
    EXPECT_EQ(packet_in.WindD, packet2.WindD);
    EXPECT_EQ(packet_in.ssa, packet2.ssa);
    EXPECT_EQ(packet_in.aoa, packet2.aoa);
    EXPECT_EQ(packet_in.gamma, packet2.gamma);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, DataCtrl)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::DataCtrl packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.xi = 73.0;
    packet_in.eta = 101.0;
    packet_in.zeta = 129.0;
    packet_in.etaT = 157.0;
    packet_in.etaF = 185.0;
    packet_in.alive = 89;

    mavlink::alxSys::msg::DataCtrl packet1{};
    mavlink::alxSys::msg::DataCtrl packet2{};

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
TEST(alxSys_interop, DataCtrl)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datactrl_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 89
    };

    mavlink::alxSys::msg::DataCtrl packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.xi = 73.0;
    packet_in.eta = 101.0;
    packet_in.zeta = 129.0;
    packet_in.etaT = 157.0;
    packet_in.etaF = 185.0;
    packet_in.alive = 89;

    mavlink::alxSys::msg::DataCtrl packet2{};

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
