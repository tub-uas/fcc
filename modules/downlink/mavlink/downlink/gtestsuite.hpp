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
    packet_in.chnl = {{ 20979, 20980, 20981, 20982, 20983, 20984, 20985, 20986, 20987, 20988, 20989, 20990 }};
    packet_in.xi_setpoint = 101.0;
    packet_in.eta_setpoint = 129.0;
    packet_in.zeta_setpoint = 157.0;
    packet_in.throttle_setpoint = 185.0;
    packet_in.flaps_setpoint = 213.0;
    packet_in.roll_setpoint = 241.0;
    packet_in.roll_rate_setpoint = 269.0;
    packet_in.pitch_setpoint = 297.0;
    packet_in.pitch_rate_setpoint = 325.0;
    packet_in.yaw_setpoint = 353.0;
    packet_in.yaw_rate_setpoint = 381.0;
    packet_in.tas_setpoint = 409.0;
    packet_in.tas_rate_setpoint = 437.0;
    packet_in.hgt_setpoint = 465.0;
    packet_in.hgt_rate_setpoint = 493.0;
    packet_in.flight_mode = 22227;
    packet_in.flight_fct = 22331;
    packet_in.alive = 49;

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
    EXPECT_EQ(packet1.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet1.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet1.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet1.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet1.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet1.roll_setpoint, packet2.roll_setpoint);
    EXPECT_EQ(packet1.roll_rate_setpoint, packet2.roll_rate_setpoint);
    EXPECT_EQ(packet1.pitch_setpoint, packet2.pitch_setpoint);
    EXPECT_EQ(packet1.pitch_rate_setpoint, packet2.pitch_rate_setpoint);
    EXPECT_EQ(packet1.yaw_setpoint, packet2.yaw_setpoint);
    EXPECT_EQ(packet1.yaw_rate_setpoint, packet2.yaw_rate_setpoint);
    EXPECT_EQ(packet1.tas_setpoint, packet2.tas_setpoint);
    EXPECT_EQ(packet1.tas_rate_setpoint, packet2.tas_rate_setpoint);
    EXPECT_EQ(packet1.hgt_setpoint, packet2.hgt_setpoint);
    EXPECT_EQ(packet1.hgt_rate_setpoint, packet2.hgt_rate_setpoint);
    EXPECT_EQ(packet1.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet1.flight_fct, packet2.flight_fct);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataRaiIn)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiin_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, { 20979, 20980, 20981, 20982, 20983, 20984, 20985, 20986, 20987, 20988, 20989, 20990 }, 22227, 22331, 49
    };

    mavlink::downlink::msg::DataRaiIn packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.chnl = {{ 20979, 20980, 20981, 20982, 20983, 20984, 20985, 20986, 20987, 20988, 20989, 20990 }};
    packet_in.xi_setpoint = 101.0;
    packet_in.eta_setpoint = 129.0;
    packet_in.zeta_setpoint = 157.0;
    packet_in.throttle_setpoint = 185.0;
    packet_in.flaps_setpoint = 213.0;
    packet_in.roll_setpoint = 241.0;
    packet_in.roll_rate_setpoint = 269.0;
    packet_in.pitch_setpoint = 297.0;
    packet_in.pitch_rate_setpoint = 325.0;
    packet_in.yaw_setpoint = 353.0;
    packet_in.yaw_rate_setpoint = 381.0;
    packet_in.tas_setpoint = 409.0;
    packet_in.tas_rate_setpoint = 437.0;
    packet_in.hgt_setpoint = 465.0;
    packet_in.hgt_rate_setpoint = 493.0;
    packet_in.flight_mode = 22227;
    packet_in.flight_fct = 22331;
    packet_in.alive = 49;

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
    EXPECT_EQ(packet_in.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet_in.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet_in.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet_in.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet_in.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet_in.roll_setpoint, packet2.roll_setpoint);
    EXPECT_EQ(packet_in.roll_rate_setpoint, packet2.roll_rate_setpoint);
    EXPECT_EQ(packet_in.pitch_setpoint, packet2.pitch_setpoint);
    EXPECT_EQ(packet_in.pitch_rate_setpoint, packet2.pitch_rate_setpoint);
    EXPECT_EQ(packet_in.yaw_setpoint, packet2.yaw_setpoint);
    EXPECT_EQ(packet_in.yaw_rate_setpoint, packet2.yaw_rate_setpoint);
    EXPECT_EQ(packet_in.tas_setpoint, packet2.tas_setpoint);
    EXPECT_EQ(packet_in.tas_rate_setpoint, packet2.tas_rate_setpoint);
    EXPECT_EQ(packet_in.hgt_setpoint, packet2.hgt_setpoint);
    EXPECT_EQ(packet_in.hgt_rate_setpoint, packet2.hgt_rate_setpoint);
    EXPECT_EQ(packet_in.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet_in.flight_fct, packet2.flight_fct);
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
    packet_in.chnl = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.xi_setpoint = 73.0;
    packet_in.eta_setpoint = 101.0;
    packet_in.zeta_setpoint = 129.0;
    packet_in.throttle_setpoint = 157.0;
    packet_in.flaps_setpoint = 185.0;
    packet_in.flight_mode = 19939;
    packet_in.flight_fct = 20043;
    packet_in.alive = 173;

    mavlink::downlink::msg::DataRaiOut packet1{};
    mavlink::downlink::msg::DataRaiOut packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.chnl, packet2.chnl);
    EXPECT_EQ(packet1.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet1.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet1.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet1.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet1.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet1.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet1.flight_fct, packet2.flight_fct);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataRaiOut)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataraiout_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, { 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }, 19939, 20043, 173
    };

    mavlink::downlink::msg::DataRaiOut packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.chnl = {{ 18691, 18692, 18693, 18694, 18695, 18696, 18697, 18698, 18699, 18700, 18701, 18702 }};
    packet_in.xi_setpoint = 73.0;
    packet_in.eta_setpoint = 101.0;
    packet_in.zeta_setpoint = 129.0;
    packet_in.throttle_setpoint = 157.0;
    packet_in.flaps_setpoint = 185.0;
    packet_in.flight_mode = 19939;
    packet_in.flight_fct = 20043;
    packet_in.alive = 173;

    mavlink::downlink::msg::DataRaiOut packet2{};

    mavlink_msg_dataraiout_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.chnl, packet2.chnl);
    EXPECT_EQ(packet_in.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet_in.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet_in.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet_in.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet_in.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet_in.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet_in.flight_fct, packet2.flight_fct);
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
    packet_in.temperature = 353.0;
    packet_in.barometric_pressure = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.alive = 209;

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
    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet1.phi, packet2.phi);
    EXPECT_EQ(packet1.the, packet2.the);
    EXPECT_EQ(packet1.psi, packet2.psi);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataAhrs)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataahrs_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 209
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
    packet_in.temperature = 353.0;
    packet_in.barometric_pressure = 381.0;
    packet_in.phi = 409.0;
    packet_in.the = 437.0;
    packet_in.psi = 465.0;
    packet_in.alive = 209;

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
    EXPECT_EQ(packet_in.temperature, packet2.temperature);
    EXPECT_EQ(packet_in.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet_in.phi, packet2.phi);
    EXPECT_EQ(packet_in.the, packet2.the);
    EXPECT_EQ(packet_in.psi, packet2.psi);
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
    packet_in.dynamic_pressure = 101.0;
    packet_in.true_airspeed = 129.0;
    packet_in.indicated_airspeed = 157.0;
    packet_in.barometric_pressure = 185.0;
    packet_in.barometric_height = 213.0;
    packet_in.density = 241.0;
    packet_in.temperature = 269.0;
    packet_in.alive = 125;

    mavlink::downlink::msg::DataAir packet1{};
    mavlink::downlink::msg::DataAir packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.dynamic_pressure, packet2.dynamic_pressure);
    EXPECT_EQ(packet1.true_airspeed, packet2.true_airspeed);
    EXPECT_EQ(packet1.indicated_airspeed, packet2.indicated_airspeed);
    EXPECT_EQ(packet1.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet1.barometric_height, packet2.barometric_height);
    EXPECT_EQ(packet1.density, packet2.density);
    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataAir)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_dataair_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 125
    };

    mavlink::downlink::msg::DataAir packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.dynamic_pressure = 101.0;
    packet_in.true_airspeed = 129.0;
    packet_in.indicated_airspeed = 157.0;
    packet_in.barometric_pressure = 185.0;
    packet_in.barometric_height = 213.0;
    packet_in.density = 241.0;
    packet_in.temperature = 269.0;
    packet_in.alive = 125;

    mavlink::downlink::msg::DataAir packet2{};

    mavlink_msg_dataair_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.dynamic_pressure, packet2.dynamic_pressure);
    EXPECT_EQ(packet_in.true_airspeed, packet2.true_airspeed);
    EXPECT_EQ(packet_in.indicated_airspeed, packet2.indicated_airspeed);
    EXPECT_EQ(packet_in.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet_in.barometric_height, packet2.barometric_height);
    EXPECT_EQ(packet_in.density, packet2.density);
    EXPECT_EQ(packet_in.temperature, packet2.temperature);
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
    packet_in.p = 185.0;
    packet_in.q = 213.0;
    packet_in.r = 241.0;
    packet_in.a_x = 269.0;
    packet_in.a_y = 297.0;
    packet_in.a_z = 325.0;
    packet_in.true_airspeed = 353.0;
    packet_in.indicated_airspeed = 381.0;
    packet_in.density = 409.0;
    packet_in.dynamic_pressure = 437.0;
    packet_in.barometric_pressure = 465.0;
    packet_in.height_rate = 493.0;
    packet_in.height = 521.0;
    packet_in.ssa = 549.0;
    packet_in.aoa = 577.0;
    packet_in.gamma = 605.0;
    packet_in.phi = 633.0;
    packet_in.the = 661.0;
    packet_in.psi = 689.0;
    packet_in.latitude = 179.0;
    packet_in.longitude = 235.0;
    packet_in.posN = 717.0;
    packet_in.posE = 745.0;
    packet_in.posD = 773.0;
    packet_in.speedN = 801.0;
    packet_in.speedE = 829.0;
    packet_in.speedD = 857.0;
    packet_in.windN = 885.0;
    packet_in.windE = 913.0;
    packet_in.windD = 941.0;
    packet_in.alive = 157;

    mavlink::downlink::msg::DataSFusion packet1{};
    mavlink::downlink::msg::DataSFusion packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.p, packet2.p);
    EXPECT_EQ(packet1.q, packet2.q);
    EXPECT_EQ(packet1.r, packet2.r);
    EXPECT_EQ(packet1.a_x, packet2.a_x);
    EXPECT_EQ(packet1.a_y, packet2.a_y);
    EXPECT_EQ(packet1.a_z, packet2.a_z);
    EXPECT_EQ(packet1.true_airspeed, packet2.true_airspeed);
    EXPECT_EQ(packet1.indicated_airspeed, packet2.indicated_airspeed);
    EXPECT_EQ(packet1.density, packet2.density);
    EXPECT_EQ(packet1.dynamic_pressure, packet2.dynamic_pressure);
    EXPECT_EQ(packet1.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet1.height_rate, packet2.height_rate);
    EXPECT_EQ(packet1.height, packet2.height);
    EXPECT_EQ(packet1.ssa, packet2.ssa);
    EXPECT_EQ(packet1.aoa, packet2.aoa);
    EXPECT_EQ(packet1.gamma, packet2.gamma);
    EXPECT_EQ(packet1.phi, packet2.phi);
    EXPECT_EQ(packet1.the, packet2.the);
    EXPECT_EQ(packet1.psi, packet2.psi);
    EXPECT_EQ(packet1.latitude, packet2.latitude);
    EXPECT_EQ(packet1.longitude, packet2.longitude);
    EXPECT_EQ(packet1.posN, packet2.posN);
    EXPECT_EQ(packet1.posE, packet2.posE);
    EXPECT_EQ(packet1.posD, packet2.posD);
    EXPECT_EQ(packet1.speedN, packet2.speedN);
    EXPECT_EQ(packet1.speedE, packet2.speedE);
    EXPECT_EQ(packet1.speedD, packet2.speedD);
    EXPECT_EQ(packet1.windN, packet2.windN);
    EXPECT_EQ(packet1.windE, packet2.windE);
    EXPECT_EQ(packet1.windD, packet2.windD);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataSFusion)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datasfusion_t packet_c {
         93372036854775807ULL, 179.0, 235.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 605.0, 633.0, 661.0, 689.0, 717.0, 745.0, 773.0, 801.0, 829.0, 857.0, 885.0, 913.0, 941.0, 157
    };

    mavlink::downlink::msg::DataSFusion packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.p = 185.0;
    packet_in.q = 213.0;
    packet_in.r = 241.0;
    packet_in.a_x = 269.0;
    packet_in.a_y = 297.0;
    packet_in.a_z = 325.0;
    packet_in.true_airspeed = 353.0;
    packet_in.indicated_airspeed = 381.0;
    packet_in.density = 409.0;
    packet_in.dynamic_pressure = 437.0;
    packet_in.barometric_pressure = 465.0;
    packet_in.height_rate = 493.0;
    packet_in.height = 521.0;
    packet_in.ssa = 549.0;
    packet_in.aoa = 577.0;
    packet_in.gamma = 605.0;
    packet_in.phi = 633.0;
    packet_in.the = 661.0;
    packet_in.psi = 689.0;
    packet_in.latitude = 179.0;
    packet_in.longitude = 235.0;
    packet_in.posN = 717.0;
    packet_in.posE = 745.0;
    packet_in.posD = 773.0;
    packet_in.speedN = 801.0;
    packet_in.speedE = 829.0;
    packet_in.speedD = 857.0;
    packet_in.windN = 885.0;
    packet_in.windE = 913.0;
    packet_in.windD = 941.0;
    packet_in.alive = 157;

    mavlink::downlink::msg::DataSFusion packet2{};

    mavlink_msg_datasfusion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.p, packet2.p);
    EXPECT_EQ(packet_in.q, packet2.q);
    EXPECT_EQ(packet_in.r, packet2.r);
    EXPECT_EQ(packet_in.a_x, packet2.a_x);
    EXPECT_EQ(packet_in.a_y, packet2.a_y);
    EXPECT_EQ(packet_in.a_z, packet2.a_z);
    EXPECT_EQ(packet_in.true_airspeed, packet2.true_airspeed);
    EXPECT_EQ(packet_in.indicated_airspeed, packet2.indicated_airspeed);
    EXPECT_EQ(packet_in.density, packet2.density);
    EXPECT_EQ(packet_in.dynamic_pressure, packet2.dynamic_pressure);
    EXPECT_EQ(packet_in.barometric_pressure, packet2.barometric_pressure);
    EXPECT_EQ(packet_in.height_rate, packet2.height_rate);
    EXPECT_EQ(packet_in.height, packet2.height);
    EXPECT_EQ(packet_in.ssa, packet2.ssa);
    EXPECT_EQ(packet_in.aoa, packet2.aoa);
    EXPECT_EQ(packet_in.gamma, packet2.gamma);
    EXPECT_EQ(packet_in.phi, packet2.phi);
    EXPECT_EQ(packet_in.the, packet2.the);
    EXPECT_EQ(packet_in.psi, packet2.psi);
    EXPECT_EQ(packet_in.latitude, packet2.latitude);
    EXPECT_EQ(packet_in.longitude, packet2.longitude);
    EXPECT_EQ(packet_in.posN, packet2.posN);
    EXPECT_EQ(packet_in.posE, packet2.posE);
    EXPECT_EQ(packet_in.posD, packet2.posD);
    EXPECT_EQ(packet_in.speedN, packet2.speedN);
    EXPECT_EQ(packet_in.speedE, packet2.speedE);
    EXPECT_EQ(packet_in.speedD, packet2.speedD);
    EXPECT_EQ(packet_in.windN, packet2.windN);
    EXPECT_EQ(packet_in.windE, packet2.windE);
    EXPECT_EQ(packet_in.windD, packet2.windD);
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
    packet_in.xi_setpoint = 73.0;
    packet_in.eta_setpoint = 101.0;
    packet_in.zeta_setpoint = 129.0;
    packet_in.throttle_setpoint = 157.0;
    packet_in.flaps_setpoint = 185.0;
    packet_in.roll_setpoint = 213.0;
    packet_in.roll_rate_setpoint = 241.0;
    packet_in.pitch_setpoint = 269.0;
    packet_in.pitch_rate_setpoint = 297.0;
    packet_in.yaw_setpoint = 325.0;
    packet_in.yaw_rate_setpoint = 353.0;
    packet_in.tas_setpoint = 381.0;
    packet_in.tas_rate_setpoint = 409.0;
    packet_in.hgt_setpoint = 437.0;
    packet_in.hgt_rate_setpoint = 465.0;
    packet_in.flight_mode = 20771;
    packet_in.flight_fct = 20875;
    packet_in.alive = 221;

    mavlink::downlink::msg::DataCtrl packet1{};
    mavlink::downlink::msg::DataCtrl packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet1.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet1.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet1.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet1.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet1.roll_setpoint, packet2.roll_setpoint);
    EXPECT_EQ(packet1.roll_rate_setpoint, packet2.roll_rate_setpoint);
    EXPECT_EQ(packet1.pitch_setpoint, packet2.pitch_setpoint);
    EXPECT_EQ(packet1.pitch_rate_setpoint, packet2.pitch_rate_setpoint);
    EXPECT_EQ(packet1.yaw_setpoint, packet2.yaw_setpoint);
    EXPECT_EQ(packet1.yaw_rate_setpoint, packet2.yaw_rate_setpoint);
    EXPECT_EQ(packet1.tas_setpoint, packet2.tas_setpoint);
    EXPECT_EQ(packet1.tas_rate_setpoint, packet2.tas_rate_setpoint);
    EXPECT_EQ(packet1.hgt_setpoint, packet2.hgt_setpoint);
    EXPECT_EQ(packet1.hgt_rate_setpoint, packet2.hgt_rate_setpoint);
    EXPECT_EQ(packet1.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet1.flight_fct, packet2.flight_fct);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataCtrl)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datactrl_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 20771, 20875, 221
    };

    mavlink::downlink::msg::DataCtrl packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.xi_setpoint = 73.0;
    packet_in.eta_setpoint = 101.0;
    packet_in.zeta_setpoint = 129.0;
    packet_in.throttle_setpoint = 157.0;
    packet_in.flaps_setpoint = 185.0;
    packet_in.roll_setpoint = 213.0;
    packet_in.roll_rate_setpoint = 241.0;
    packet_in.pitch_setpoint = 269.0;
    packet_in.pitch_rate_setpoint = 297.0;
    packet_in.yaw_setpoint = 325.0;
    packet_in.yaw_rate_setpoint = 353.0;
    packet_in.tas_setpoint = 381.0;
    packet_in.tas_rate_setpoint = 409.0;
    packet_in.hgt_setpoint = 437.0;
    packet_in.hgt_rate_setpoint = 465.0;
    packet_in.flight_mode = 20771;
    packet_in.flight_fct = 20875;
    packet_in.alive = 221;

    mavlink::downlink::msg::DataCtrl packet2{};

    mavlink_msg_datactrl_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.xi_setpoint, packet2.xi_setpoint);
    EXPECT_EQ(packet_in.eta_setpoint, packet2.eta_setpoint);
    EXPECT_EQ(packet_in.zeta_setpoint, packet2.zeta_setpoint);
    EXPECT_EQ(packet_in.throttle_setpoint, packet2.throttle_setpoint);
    EXPECT_EQ(packet_in.flaps_setpoint, packet2.flaps_setpoint);
    EXPECT_EQ(packet_in.roll_setpoint, packet2.roll_setpoint);
    EXPECT_EQ(packet_in.roll_rate_setpoint, packet2.roll_rate_setpoint);
    EXPECT_EQ(packet_in.pitch_setpoint, packet2.pitch_setpoint);
    EXPECT_EQ(packet_in.pitch_rate_setpoint, packet2.pitch_rate_setpoint);
    EXPECT_EQ(packet_in.yaw_setpoint, packet2.yaw_setpoint);
    EXPECT_EQ(packet_in.yaw_rate_setpoint, packet2.yaw_rate_setpoint);
    EXPECT_EQ(packet_in.tas_setpoint, packet2.tas_setpoint);
    EXPECT_EQ(packet_in.tas_rate_setpoint, packet2.tas_rate_setpoint);
    EXPECT_EQ(packet_in.hgt_setpoint, packet2.hgt_setpoint);
    EXPECT_EQ(packet_in.hgt_rate_setpoint, packet2.hgt_rate_setpoint);
    EXPECT_EQ(packet_in.flight_mode, packet2.flight_mode);
    EXPECT_EQ(packet_in.flight_fct, packet2.flight_fct);
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
    packet_in.main_volt = 101.0;
    packet_in.main_curr = 129.0;
    packet_in.main_pwr = 157.0;
    packet_in.pwr_volt = 185.0;
    packet_in.pwr_curr = 213.0;
    packet_in.pwr_pwr = 241.0;
    packet_in.sys_volt = 269.0;
    packet_in.sys_curr = 297.0;
    packet_in.sys_pwr = 325.0;
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
    EXPECT_EQ(packet1.main_volt, packet2.main_volt);
    EXPECT_EQ(packet1.main_curr, packet2.main_curr);
    EXPECT_EQ(packet1.main_pwr, packet2.main_pwr);
    EXPECT_EQ(packet1.pwr_volt, packet2.pwr_volt);
    EXPECT_EQ(packet1.pwr_curr, packet2.pwr_curr);
    EXPECT_EQ(packet1.pwr_pwr, packet2.pwr_pwr);
    EXPECT_EQ(packet1.sys_volt, packet2.sys_volt);
    EXPECT_EQ(packet1.sys_curr, packet2.sys_curr);
    EXPECT_EQ(packet1.sys_pwr, packet2.sys_pwr);
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
    packet_in.main_volt = 101.0;
    packet_in.main_curr = 129.0;
    packet_in.main_pwr = 157.0;
    packet_in.pwr_volt = 185.0;
    packet_in.pwr_curr = 213.0;
    packet_in.pwr_pwr = 241.0;
    packet_in.sys_volt = 269.0;
    packet_in.sys_curr = 297.0;
    packet_in.sys_pwr = 325.0;
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
    EXPECT_EQ(packet_in.main_volt, packet2.main_volt);
    EXPECT_EQ(packet_in.main_curr, packet2.main_curr);
    EXPECT_EQ(packet_in.main_pwr, packet2.main_pwr);
    EXPECT_EQ(packet_in.pwr_volt, packet2.pwr_volt);
    EXPECT_EQ(packet_in.pwr_curr, packet2.pwr_curr);
    EXPECT_EQ(packet_in.pwr_pwr, packet2.pwr_pwr);
    EXPECT_EQ(packet_in.sys_volt, packet2.sys_volt);
    EXPECT_EQ(packet_in.sys_curr, packet2.sys_curr);
    EXPECT_EQ(packet_in.sys_pwr, packet2.sys_pwr);
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
    packet_in.latitude = 101.0;
    packet_in.longitude = 129.0;
    packet_in.alt_msl = 157.0;
    packet_in.groundspeed = 185.0;
    packet_in.course_over_ground = 213.0;
    packet_in.sats = 241.0;
    packet_in.sats_in_view = 269.0;
    packet_in.fix = 297.0;
    packet_in.fix_mode = 325.0;
    packet_in.dop_position = 353.0;
    packet_in.dop_horizontal = 381.0;
    packet_in.dop_velocity = 409.0;
    packet_in.alive = 185;

    mavlink::downlink::msg::DataGps packet1{};
    mavlink::downlink::msg::DataGps packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time, packet2.time);
    EXPECT_EQ(packet1.senseTime, packet2.senseTime);
    EXPECT_EQ(packet1.latitude, packet2.latitude);
    EXPECT_EQ(packet1.longitude, packet2.longitude);
    EXPECT_EQ(packet1.alt_msl, packet2.alt_msl);
    EXPECT_EQ(packet1.groundspeed, packet2.groundspeed);
    EXPECT_EQ(packet1.course_over_ground, packet2.course_over_ground);
    EXPECT_EQ(packet1.sats, packet2.sats);
    EXPECT_EQ(packet1.sats_in_view, packet2.sats_in_view);
    EXPECT_EQ(packet1.fix, packet2.fix);
    EXPECT_EQ(packet1.fix_mode, packet2.fix_mode);
    EXPECT_EQ(packet1.dop_position, packet2.dop_position);
    EXPECT_EQ(packet1.dop_horizontal, packet2.dop_horizontal);
    EXPECT_EQ(packet1.dop_velocity, packet2.dop_velocity);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(downlink_interop, DataGps)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_datagps_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 185
    };

    mavlink::downlink::msg::DataGps packet_in{};
    packet_in.time = 93372036854775807ULL;
    packet_in.senseTime = 73.0;
    packet_in.latitude = 101.0;
    packet_in.longitude = 129.0;
    packet_in.alt_msl = 157.0;
    packet_in.groundspeed = 185.0;
    packet_in.course_over_ground = 213.0;
    packet_in.sats = 241.0;
    packet_in.sats_in_view = 269.0;
    packet_in.fix = 297.0;
    packet_in.fix_mode = 325.0;
    packet_in.dop_position = 353.0;
    packet_in.dop_horizontal = 381.0;
    packet_in.dop_velocity = 409.0;
    packet_in.alive = 185;

    mavlink::downlink::msg::DataGps packet2{};

    mavlink_msg_datagps_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time, packet2.time);
    EXPECT_EQ(packet_in.senseTime, packet2.senseTime);
    EXPECT_EQ(packet_in.latitude, packet2.latitude);
    EXPECT_EQ(packet_in.longitude, packet2.longitude);
    EXPECT_EQ(packet_in.alt_msl, packet2.alt_msl);
    EXPECT_EQ(packet_in.groundspeed, packet2.groundspeed);
    EXPECT_EQ(packet_in.course_over_ground, packet2.course_over_ground);
    EXPECT_EQ(packet_in.sats, packet2.sats);
    EXPECT_EQ(packet_in.sats_in_view, packet2.sats_in_view);
    EXPECT_EQ(packet_in.fix, packet2.fix);
    EXPECT_EQ(packet_in.fix_mode, packet2.fix_mode);
    EXPECT_EQ(packet_in.dop_position, packet2.dop_position);
    EXPECT_EQ(packet_in.dop_horizontal, packet2.dop_horizontal);
    EXPECT_EQ(packet_in.dop_velocity, packet2.dop_velocity);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
