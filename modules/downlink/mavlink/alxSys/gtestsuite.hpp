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


TEST(alxSys, RC2SIN)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::RC2SIN packet_in{};
    packet_in.setPoint_aill = 17.0;
    packet_in.setPoint_elev = 45.0;
    packet_in.setPoint_rudd = 73.0;
    packet_in.setPoint_thrt = 101.0;
    packet_in.control_law = 18067;

    mavlink::alxSys::msg::RC2SIN packet1{};
    mavlink::alxSys::msg::RC2SIN packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.setPoint_aill, packet2.setPoint_aill);
    EXPECT_EQ(packet1.setPoint_elev, packet2.setPoint_elev);
    EXPECT_EQ(packet1.setPoint_rudd, packet2.setPoint_rudd);
    EXPECT_EQ(packet1.setPoint_thrt, packet2.setPoint_thrt);
    EXPECT_EQ(packet1.control_law, packet2.control_law);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, RC2SIN)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rc2sin_t packet_c {
         17.0, 45.0, 73.0, 101.0, 18067
    };

    mavlink::alxSys::msg::RC2SIN packet_in{};
    packet_in.setPoint_aill = 17.0;
    packet_in.setPoint_elev = 45.0;
    packet_in.setPoint_rudd = 73.0;
    packet_in.setPoint_thrt = 101.0;
    packet_in.control_law = 18067;

    mavlink::alxSys::msg::RC2SIN packet2{};

    mavlink_msg_rc2sin_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.setPoint_aill, packet2.setPoint_aill);
    EXPECT_EQ(packet_in.setPoint_elev, packet2.setPoint_elev);
    EXPECT_EQ(packet_in.setPoint_rudd, packet2.setPoint_rudd);
    EXPECT_EQ(packet_in.setPoint_thrt, packet2.setPoint_thrt);
    EXPECT_EQ(packet_in.control_law, packet2.control_law);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, AHRS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::AHRS packet_in{};
    packet_in.timestamp = 963497464;
    packet_in.gX = 45.0;
    packet_in.gY = 73.0;
    packet_in.gZ = 101.0;
    packet_in.aX = 129.0;
    packet_in.aY = 157.0;
    packet_in.aZ = 185.0;
    packet_in.mX = 213.0;
    packet_in.mY = 241.0;
    packet_in.mZ = 269.0;
    packet_in.Phi = 297.0;
    packet_in.Tht = 325.0;
    packet_in.Psi = 353.0;
    packet_in.alive = 161;

    mavlink::alxSys::msg::AHRS packet1{};
    mavlink::alxSys::msg::AHRS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
    EXPECT_EQ(packet1.gX, packet2.gX);
    EXPECT_EQ(packet1.gY, packet2.gY);
    EXPECT_EQ(packet1.gZ, packet2.gZ);
    EXPECT_EQ(packet1.aX, packet2.aX);
    EXPECT_EQ(packet1.aY, packet2.aY);
    EXPECT_EQ(packet1.aZ, packet2.aZ);
    EXPECT_EQ(packet1.mX, packet2.mX);
    EXPECT_EQ(packet1.mY, packet2.mY);
    EXPECT_EQ(packet1.mZ, packet2.mZ);
    EXPECT_EQ(packet1.Phi, packet2.Phi);
    EXPECT_EQ(packet1.Tht, packet2.Tht);
    EXPECT_EQ(packet1.Psi, packet2.Psi);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, AHRS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 161
    };

    mavlink::alxSys::msg::AHRS packet_in{};
    packet_in.timestamp = 963497464;
    packet_in.gX = 45.0;
    packet_in.gY = 73.0;
    packet_in.gZ = 101.0;
    packet_in.aX = 129.0;
    packet_in.aY = 157.0;
    packet_in.aZ = 185.0;
    packet_in.mX = 213.0;
    packet_in.mY = 241.0;
    packet_in.mZ = 269.0;
    packet_in.Phi = 297.0;
    packet_in.Tht = 325.0;
    packet_in.Psi = 353.0;
    packet_in.alive = 161;

    mavlink::alxSys::msg::AHRS packet2{};

    mavlink_msg_ahrs_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);
    EXPECT_EQ(packet_in.gX, packet2.gX);
    EXPECT_EQ(packet_in.gY, packet2.gY);
    EXPECT_EQ(packet_in.gZ, packet2.gZ);
    EXPECT_EQ(packet_in.aX, packet2.aX);
    EXPECT_EQ(packet_in.aY, packet2.aY);
    EXPECT_EQ(packet_in.aZ, packet2.aZ);
    EXPECT_EQ(packet_in.mX, packet2.mX);
    EXPECT_EQ(packet_in.mY, packet2.mY);
    EXPECT_EQ(packet_in.mZ, packet2.mZ);
    EXPECT_EQ(packet_in.Phi, packet2.Phi);
    EXPECT_EQ(packet_in.Tht, packet2.Tht);
    EXPECT_EQ(packet_in.Psi, packet2.Psi);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, AIR)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::AIR packet_in{};
    packet_in.timestamp = 963497464;
    packet_in.aspd = 45.0;
    packet_in.altb = 73.0;
    packet_in.alive = 41;

    mavlink::alxSys::msg::AIR packet1{};
    mavlink::alxSys::msg::AIR packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
    EXPECT_EQ(packet1.aspd, packet2.aspd);
    EXPECT_EQ(packet1.altb, packet2.altb);
    EXPECT_EQ(packet1.alive, packet2.alive);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, AIR)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_air_t packet_c {
         963497464, 45.0, 73.0, 41
    };

    mavlink::alxSys::msg::AIR packet_in{};
    packet_in.timestamp = 963497464;
    packet_in.aspd = 45.0;
    packet_in.altb = 73.0;
    packet_in.alive = 41;

    mavlink::alxSys::msg::AIR packet2{};

    mavlink_msg_air_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);
    EXPECT_EQ(packet_in.aspd, packet2.aspd);
    EXPECT_EQ(packet_in.altb, packet2.altb);
    EXPECT_EQ(packet_in.alive, packet2.alive);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, SFUSION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::SFUSION packet_in{};
    packet_in.timestamp = 963497464;

    mavlink::alxSys::msg::SFUSION packet1{};
    mavlink::alxSys::msg::SFUSION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, SFUSION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sfusion_t packet_c {
         963497464
    };

    mavlink::alxSys::msg::SFUSION packet_in{};
    packet_in.timestamp = 963497464;

    mavlink::alxSys::msg::SFUSION packet2{};

    mavlink_msg_sfusion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(alxSys, RC2SOUT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::RC2SOUT packet_in{};
    packet_in.out_aill = 17.0;
    packet_in.out_elev = 45.0;
    packet_in.out_rudd = 73.0;
    packet_in.out_thrt = 101.0;
    packet_in.control_law = 18067;

    mavlink::alxSys::msg::RC2SOUT packet1{};
    mavlink::alxSys::msg::RC2SOUT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.out_aill, packet2.out_aill);
    EXPECT_EQ(packet1.out_elev, packet2.out_elev);
    EXPECT_EQ(packet1.out_rudd, packet2.out_rudd);
    EXPECT_EQ(packet1.out_thrt, packet2.out_thrt);
    EXPECT_EQ(packet1.control_law, packet2.control_law);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, RC2SOUT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rc2sout_t packet_c {
         17.0, 45.0, 73.0, 101.0, 18067
    };

    mavlink::alxSys::msg::RC2SOUT packet_in{};
    packet_in.out_aill = 17.0;
    packet_in.out_elev = 45.0;
    packet_in.out_rudd = 73.0;
    packet_in.out_thrt = 101.0;
    packet_in.control_law = 18067;

    mavlink::alxSys::msg::RC2SOUT packet2{};

    mavlink_msg_rc2sout_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.out_aill, packet2.out_aill);
    EXPECT_EQ(packet_in.out_elev, packet2.out_elev);
    EXPECT_EQ(packet_in.out_rudd, packet2.out_rudd);
    EXPECT_EQ(packet_in.out_thrt, packet2.out_thrt);
    EXPECT_EQ(packet_in.control_law, packet2.control_law);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
