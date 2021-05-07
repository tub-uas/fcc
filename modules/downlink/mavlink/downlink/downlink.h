/** @file
 *  @brief MAVLink comm protocol generated from downlink.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_DOWNLINK_H
#define MAVLINK_DOWNLINK_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_DOWNLINK.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{10000, 252, 55, 55, 0, 0, 0}, {15000, 187, 51, 51, 0, 0, 0}, {20000, 109, 85, 85, 0, 0, 0}, {30000, 175, 33, 33, 0, 0, 0}, {40000, 64, 129, 129, 0, 0, 0}, {50000, 128, 29, 29, 0, 0, 0}, {60000, 202, 49, 49, 0, 0, 0}, {70000, 77, 21, 21, 0, 0, 0}, {80000, 34, 57, 57, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_DOWNLINK

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_dataraiin.h"
#include "./mavlink_msg_dataraiout.h"
#include "./mavlink_msg_dataahrs.h"
#include "./mavlink_msg_dataair.h"
#include "./mavlink_msg_datasfusion.h"
#include "./mavlink_msg_datactrl.h"
#include "./mavlink_msg_datapsu.h"
#include "./mavlink_msg_datawatchdog.h"
#include "./mavlink_msg_datagps.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_DataRaiIn, MAVLINK_MESSAGE_INFO_DataRaiOut, MAVLINK_MESSAGE_INFO_DataAhrs, MAVLINK_MESSAGE_INFO_DataAir, MAVLINK_MESSAGE_INFO_DataSFusion, MAVLINK_MESSAGE_INFO_DataCtrl, MAVLINK_MESSAGE_INFO_DataPsu, MAVLINK_MESSAGE_INFO_DataWatchdog, MAVLINK_MESSAGE_INFO_DataGps}
# define MAVLINK_MESSAGE_NAMES {{ "DataAhrs", 20000 }, { "DataAir", 30000 }, { "DataCtrl", 50000 }, { "DataGps", 80000 }, { "DataPsu", 60000 }, { "DataRaiIn", 10000 }, { "DataRaiOut", 15000 }, { "DataSFusion", 40000 }, { "DataWatchdog", 70000 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_DOWNLINK_H
