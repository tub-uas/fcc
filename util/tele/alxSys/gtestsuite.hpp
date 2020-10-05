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


TEST(alxSys, RC2SPUBLISHER)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::alxSys::msg::RC2SPUBLISHER packet_in{};
    packet_in.setPoint_aill = 17.0;
    packet_in.setPoint_elev = 45.0;
    packet_in.control_law = 17651;

    mavlink::alxSys::msg::RC2SPUBLISHER packet1{};
    mavlink::alxSys::msg::RC2SPUBLISHER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.setPoint_aill, packet2.setPoint_aill);
    EXPECT_EQ(packet1.setPoint_elev, packet2.setPoint_elev);
    EXPECT_EQ(packet1.control_law, packet2.control_law);
}

#ifdef TEST_INTEROP
TEST(alxSys_interop, RC2SPUBLISHER)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rc2spublisher_t packet_c {
         17.0, 45.0, 17651
    };

    mavlink::alxSys::msg::RC2SPUBLISHER packet_in{};
    packet_in.setPoint_aill = 17.0;
    packet_in.setPoint_elev = 45.0;
    packet_in.control_law = 17651;

    mavlink::alxSys::msg::RC2SPUBLISHER packet2{};

    mavlink_msg_rc2spublisher_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.setPoint_aill, packet2.setPoint_aill);
    EXPECT_EQ(packet_in.setPoint_elev, packet2.setPoint_elev);
    EXPECT_EQ(packet_in.control_law, packet2.control_law);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
