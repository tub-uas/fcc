/** @file
 *	@brief MAVLink comm protocol generated from downlink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace downlink {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 9> MESSAGE_ENTRIES {{ {10000, 21, 101, 101, 0, 0, 0}, {15000, 86, 57, 57, 0, 0, 0}, {20000, 55, 69, 69, 0, 0, 0}, {30000, 215, 41, 41, 0, 0, 0}, {40000, 180, 137, 137, 0, 0, 0}, {50000, 247, 73, 73, 0, 0, 0}, {60000, 217, 49, 49, 0, 0, 0}, {70000, 77, 21, 21, 0, 0, 0}, {80000, 161, 61, 61, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS




} // namespace downlink
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_dataraiin.hpp"
#include "./mavlink_msg_dataraiout.hpp"
#include "./mavlink_msg_dataahrs.hpp"
#include "./mavlink_msg_dataair.hpp"
#include "./mavlink_msg_datasfusion.hpp"
#include "./mavlink_msg_datactrl.hpp"
#include "./mavlink_msg_datapsu.hpp"
#include "./mavlink_msg_datawatchdog.hpp"
#include "./mavlink_msg_datagps.hpp"

// base include

