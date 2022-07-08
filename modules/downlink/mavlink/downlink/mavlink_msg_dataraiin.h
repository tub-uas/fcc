#pragma once
// MESSAGE DataRaiIn PACKING

#define MAVLINK_MSG_ID_DataRaiIn 10000


typedef struct __mavlink_dataraiin_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float xi_setpoint; /*<  xi input from pilot (aka. setpoint)*/
 float eta_setpoint; /*<  eta input from pilot (aka. setpoint)*/
 float zeta_setpoint; /*<  zeta input from pilot (aka. setpoint)*/
 float throttle_setpoint; /*<  Throttle input from pilot (aka. setpoint)*/
 float flaps_setpoint; /*<  Flaps input from pilot (aka. setpoint)*/
 float roll_setpoint; /*<  Roll input from pilot (aka. setpoint)*/
 float roll_rate_setpoint; /*<  Rollrate input from pilot (aka. setpoint)*/
 float pitch_setpoint; /*<  Pitch input from pilot (aka. setpoint)*/
 float pitch_rate_setpoint; /*<  Pitchrate input from pilot (aka. setpoint)*/
 float yaw_setpoint; /*<  Yaw input from pilot (aka. setpoint)*/
 float yaw_rate_setpoint; /*<  Yaw_rate input from pilot (aka. setpoint)*/
 float tas_setpoint; /*<  TAS input from pilot (aka. setpoint)*/
 float tas_rate_setpoint; /*<  TAS rate input from pilot (aka. setpoint)*/
 float hgt_setpoint; /*<  Hgt input from pilot (aka. setpoint)*/
 float hgt_rate_setpoint; /*<  Hgt_rate input from pilot (aka. setpoint)*/
 uint16_t chnl[12]; /*<  Channels with raw PWM values*/
 uint16_t flight_mode; /*<  Flightmode set by pilot*/
 uint16_t flight_fct; /*<  Flightfunction set by pilot*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_dataraiin_t;

#define MAVLINK_MSG_ID_DataRaiIn_LEN 101
#define MAVLINK_MSG_ID_DataRaiIn_MIN_LEN 101
#define MAVLINK_MSG_ID_10000_LEN 101
#define MAVLINK_MSG_ID_10000_MIN_LEN 101

#define MAVLINK_MSG_ID_DataRaiIn_CRC 21
#define MAVLINK_MSG_ID_10000_CRC 21

#define MAVLINK_MSG_DataRaiIn_FIELD_CHNL_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataRaiIn { \
    10000, \
    "DataRaiIn", \
    21, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiin_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiin_t, senseTime) }, \
         { "chnl", NULL, MAVLINK_TYPE_UINT16_T, 12, 72, offsetof(mavlink_dataraiin_t, chnl) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiin_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiin_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiin_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiin_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataraiin_t, flaps_setpoint) }, \
         { "roll_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataraiin_t, roll_setpoint) }, \
         { "roll_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataraiin_t, roll_rate_setpoint) }, \
         { "pitch_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataraiin_t, pitch_setpoint) }, \
         { "pitch_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataraiin_t, pitch_rate_setpoint) }, \
         { "yaw_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataraiin_t, yaw_setpoint) }, \
         { "yaw_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataraiin_t, yaw_rate_setpoint) }, \
         { "tas_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataraiin_t, tas_setpoint) }, \
         { "tas_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataraiin_t, tas_rate_setpoint) }, \
         { "hgt_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataraiin_t, hgt_setpoint) }, \
         { "hgt_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dataraiin_t, hgt_rate_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_dataraiin_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 98, offsetof(mavlink_dataraiin_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 100, offsetof(mavlink_dataraiin_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataRaiIn { \
    "DataRaiIn", \
    21, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiin_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiin_t, senseTime) }, \
         { "chnl", NULL, MAVLINK_TYPE_UINT16_T, 12, 72, offsetof(mavlink_dataraiin_t, chnl) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiin_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiin_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiin_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiin_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataraiin_t, flaps_setpoint) }, \
         { "roll_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataraiin_t, roll_setpoint) }, \
         { "roll_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataraiin_t, roll_rate_setpoint) }, \
         { "pitch_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataraiin_t, pitch_setpoint) }, \
         { "pitch_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataraiin_t, pitch_rate_setpoint) }, \
         { "yaw_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataraiin_t, yaw_setpoint) }, \
         { "yaw_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataraiin_t, yaw_rate_setpoint) }, \
         { "tas_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataraiin_t, tas_setpoint) }, \
         { "tas_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataraiin_t, tas_rate_setpoint) }, \
         { "hgt_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataraiin_t, hgt_setpoint) }, \
         { "hgt_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dataraiin_t, hgt_rate_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_dataraiin_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 98, offsetof(mavlink_dataraiin_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 100, offsetof(mavlink_dataraiin_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataraiin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi input from pilot (aka. setpoint)
 * @param eta_setpoint  eta input from pilot (aka. setpoint)
 * @param zeta_setpoint  zeta input from pilot (aka. setpoint)
 * @param throttle_setpoint  Throttle input from pilot (aka. setpoint)
 * @param flaps_setpoint  Flaps input from pilot (aka. setpoint)
 * @param roll_setpoint  Roll input from pilot (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate input from pilot (aka. setpoint)
 * @param pitch_setpoint  Pitch input from pilot (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate input from pilot (aka. setpoint)
 * @param yaw_setpoint  Yaw input from pilot (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate input from pilot (aka. setpoint)
 * @param tas_setpoint  TAS input from pilot (aka. setpoint)
 * @param tas_rate_setpoint  TAS rate input from pilot (aka. setpoint)
 * @param hgt_setpoint  Hgt input from pilot (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate input from pilot (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, xi_setpoint);
    _mav_put_float(buf, 16, eta_setpoint);
    _mav_put_float(buf, 20, zeta_setpoint);
    _mav_put_float(buf, 24, throttle_setpoint);
    _mav_put_float(buf, 28, flaps_setpoint);
    _mav_put_float(buf, 32, roll_setpoint);
    _mav_put_float(buf, 36, roll_rate_setpoint);
    _mav_put_float(buf, 40, pitch_setpoint);
    _mav_put_float(buf, 44, pitch_rate_setpoint);
    _mav_put_float(buf, 48, yaw_setpoint);
    _mav_put_float(buf, 52, yaw_rate_setpoint);
    _mav_put_float(buf, 56, tas_setpoint);
    _mav_put_float(buf, 60, tas_rate_setpoint);
    _mav_put_float(buf, 64, hgt_setpoint);
    _mav_put_float(buf, 68, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 96, flight_mode);
    _mav_put_uint16_t(buf, 98, flight_fct);
    _mav_put_uint8_t(buf, 100, alive);
    _mav_put_uint16_t_array(buf, 72, chnl, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiIn_LEN);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.roll_setpoint = roll_setpoint;
    packet.roll_rate_setpoint = roll_rate_setpoint;
    packet.pitch_setpoint = pitch_setpoint;
    packet.pitch_rate_setpoint = pitch_rate_setpoint;
    packet.yaw_setpoint = yaw_setpoint;
    packet.yaw_rate_setpoint = yaw_rate_setpoint;
    packet.tas_setpoint = tas_setpoint;
    packet.tas_rate_setpoint = tas_rate_setpoint;
    packet.hgt_setpoint = hgt_setpoint;
    packet.hgt_rate_setpoint = hgt_rate_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataRaiIn_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataRaiIn;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
}

/**
 * @brief Pack a dataraiin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi input from pilot (aka. setpoint)
 * @param eta_setpoint  eta input from pilot (aka. setpoint)
 * @param zeta_setpoint  zeta input from pilot (aka. setpoint)
 * @param throttle_setpoint  Throttle input from pilot (aka. setpoint)
 * @param flaps_setpoint  Flaps input from pilot (aka. setpoint)
 * @param roll_setpoint  Roll input from pilot (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate input from pilot (aka. setpoint)
 * @param pitch_setpoint  Pitch input from pilot (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate input from pilot (aka. setpoint)
 * @param yaw_setpoint  Yaw input from pilot (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate input from pilot (aka. setpoint)
 * @param tas_setpoint  TAS input from pilot (aka. setpoint)
 * @param tas_rate_setpoint  TAS rate input from pilot (aka. setpoint)
 * @param hgt_setpoint  Hgt input from pilot (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate input from pilot (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,const uint16_t *chnl,float xi_setpoint,float eta_setpoint,float zeta_setpoint,float throttle_setpoint,float flaps_setpoint,float roll_setpoint,float roll_rate_setpoint,float pitch_setpoint,float pitch_rate_setpoint,float yaw_setpoint,float yaw_rate_setpoint,float tas_setpoint,float tas_rate_setpoint,float hgt_setpoint,float hgt_rate_setpoint,uint16_t flight_mode,uint16_t flight_fct,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, xi_setpoint);
    _mav_put_float(buf, 16, eta_setpoint);
    _mav_put_float(buf, 20, zeta_setpoint);
    _mav_put_float(buf, 24, throttle_setpoint);
    _mav_put_float(buf, 28, flaps_setpoint);
    _mav_put_float(buf, 32, roll_setpoint);
    _mav_put_float(buf, 36, roll_rate_setpoint);
    _mav_put_float(buf, 40, pitch_setpoint);
    _mav_put_float(buf, 44, pitch_rate_setpoint);
    _mav_put_float(buf, 48, yaw_setpoint);
    _mav_put_float(buf, 52, yaw_rate_setpoint);
    _mav_put_float(buf, 56, tas_setpoint);
    _mav_put_float(buf, 60, tas_rate_setpoint);
    _mav_put_float(buf, 64, hgt_setpoint);
    _mav_put_float(buf, 68, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 96, flight_mode);
    _mav_put_uint16_t(buf, 98, flight_fct);
    _mav_put_uint8_t(buf, 100, alive);
    _mav_put_uint16_t_array(buf, 72, chnl, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiIn_LEN);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.roll_setpoint = roll_setpoint;
    packet.roll_rate_setpoint = roll_rate_setpoint;
    packet.pitch_setpoint = pitch_setpoint;
    packet.pitch_rate_setpoint = pitch_rate_setpoint;
    packet.yaw_setpoint = yaw_setpoint;
    packet.yaw_rate_setpoint = yaw_rate_setpoint;
    packet.tas_setpoint = tas_setpoint;
    packet.tas_rate_setpoint = tas_rate_setpoint;
    packet.hgt_setpoint = hgt_setpoint;
    packet.hgt_rate_setpoint = hgt_rate_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataRaiIn_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataRaiIn;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
}

/**
 * @brief Encode a dataraiin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dataraiin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataraiin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dataraiin_t* dataraiin)
{
    return mavlink_msg_dataraiin_pack(system_id, component_id, msg, dataraiin->time, dataraiin->senseTime, dataraiin->chnl, dataraiin->xi_setpoint, dataraiin->eta_setpoint, dataraiin->zeta_setpoint, dataraiin->throttle_setpoint, dataraiin->flaps_setpoint, dataraiin->roll_setpoint, dataraiin->roll_rate_setpoint, dataraiin->pitch_setpoint, dataraiin->pitch_rate_setpoint, dataraiin->yaw_setpoint, dataraiin->yaw_rate_setpoint, dataraiin->tas_setpoint, dataraiin->tas_rate_setpoint, dataraiin->hgt_setpoint, dataraiin->hgt_rate_setpoint, dataraiin->flight_mode, dataraiin->flight_fct, dataraiin->alive);
}

/**
 * @brief Encode a dataraiin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dataraiin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataraiin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dataraiin_t* dataraiin)
{
    return mavlink_msg_dataraiin_pack_chan(system_id, component_id, chan, msg, dataraiin->time, dataraiin->senseTime, dataraiin->chnl, dataraiin->xi_setpoint, dataraiin->eta_setpoint, dataraiin->zeta_setpoint, dataraiin->throttle_setpoint, dataraiin->flaps_setpoint, dataraiin->roll_setpoint, dataraiin->roll_rate_setpoint, dataraiin->pitch_setpoint, dataraiin->pitch_rate_setpoint, dataraiin->yaw_setpoint, dataraiin->yaw_rate_setpoint, dataraiin->tas_setpoint, dataraiin->tas_rate_setpoint, dataraiin->hgt_setpoint, dataraiin->hgt_rate_setpoint, dataraiin->flight_mode, dataraiin->flight_fct, dataraiin->alive);
}

/**
 * @brief Send a dataraiin message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi input from pilot (aka. setpoint)
 * @param eta_setpoint  eta input from pilot (aka. setpoint)
 * @param zeta_setpoint  zeta input from pilot (aka. setpoint)
 * @param throttle_setpoint  Throttle input from pilot (aka. setpoint)
 * @param flaps_setpoint  Flaps input from pilot (aka. setpoint)
 * @param roll_setpoint  Roll input from pilot (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate input from pilot (aka. setpoint)
 * @param pitch_setpoint  Pitch input from pilot (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate input from pilot (aka. setpoint)
 * @param yaw_setpoint  Yaw input from pilot (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate input from pilot (aka. setpoint)
 * @param tas_setpoint  TAS input from pilot (aka. setpoint)
 * @param tas_rate_setpoint  TAS rate input from pilot (aka. setpoint)
 * @param hgt_setpoint  Hgt input from pilot (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate input from pilot (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataraiin_send(mavlink_channel_t chan, uint64_t time, float senseTime, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, xi_setpoint);
    _mav_put_float(buf, 16, eta_setpoint);
    _mav_put_float(buf, 20, zeta_setpoint);
    _mav_put_float(buf, 24, throttle_setpoint);
    _mav_put_float(buf, 28, flaps_setpoint);
    _mav_put_float(buf, 32, roll_setpoint);
    _mav_put_float(buf, 36, roll_rate_setpoint);
    _mav_put_float(buf, 40, pitch_setpoint);
    _mav_put_float(buf, 44, pitch_rate_setpoint);
    _mav_put_float(buf, 48, yaw_setpoint);
    _mav_put_float(buf, 52, yaw_rate_setpoint);
    _mav_put_float(buf, 56, tas_setpoint);
    _mav_put_float(buf, 60, tas_rate_setpoint);
    _mav_put_float(buf, 64, hgt_setpoint);
    _mav_put_float(buf, 68, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 96, flight_mode);
    _mav_put_uint16_t(buf, 98, flight_fct);
    _mav_put_uint8_t(buf, 100, alive);
    _mav_put_uint16_t_array(buf, 72, chnl, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, buf, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.roll_setpoint = roll_setpoint;
    packet.roll_rate_setpoint = roll_rate_setpoint;
    packet.pitch_setpoint = pitch_setpoint;
    packet.pitch_rate_setpoint = pitch_rate_setpoint;
    packet.yaw_setpoint = yaw_setpoint;
    packet.yaw_rate_setpoint = yaw_rate_setpoint;
    packet.tas_setpoint = tas_setpoint;
    packet.tas_rate_setpoint = tas_rate_setpoint;
    packet.hgt_setpoint = hgt_setpoint;
    packet.hgt_rate_setpoint = hgt_rate_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, (const char *)&packet, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#endif
}

/**
 * @brief Send a dataraiin message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dataraiin_send_struct(mavlink_channel_t chan, const mavlink_dataraiin_t* dataraiin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dataraiin_send(chan, dataraiin->time, dataraiin->senseTime, dataraiin->chnl, dataraiin->xi_setpoint, dataraiin->eta_setpoint, dataraiin->zeta_setpoint, dataraiin->throttle_setpoint, dataraiin->flaps_setpoint, dataraiin->roll_setpoint, dataraiin->roll_rate_setpoint, dataraiin->pitch_setpoint, dataraiin->pitch_rate_setpoint, dataraiin->yaw_setpoint, dataraiin->yaw_rate_setpoint, dataraiin->tas_setpoint, dataraiin->tas_rate_setpoint, dataraiin->hgt_setpoint, dataraiin->hgt_rate_setpoint, dataraiin->flight_mode, dataraiin->flight_fct, dataraiin->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, (const char *)dataraiin, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataRaiIn_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataraiin_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, xi_setpoint);
    _mav_put_float(buf, 16, eta_setpoint);
    _mav_put_float(buf, 20, zeta_setpoint);
    _mav_put_float(buf, 24, throttle_setpoint);
    _mav_put_float(buf, 28, flaps_setpoint);
    _mav_put_float(buf, 32, roll_setpoint);
    _mav_put_float(buf, 36, roll_rate_setpoint);
    _mav_put_float(buf, 40, pitch_setpoint);
    _mav_put_float(buf, 44, pitch_rate_setpoint);
    _mav_put_float(buf, 48, yaw_setpoint);
    _mav_put_float(buf, 52, yaw_rate_setpoint);
    _mav_put_float(buf, 56, tas_setpoint);
    _mav_put_float(buf, 60, tas_rate_setpoint);
    _mav_put_float(buf, 64, hgt_setpoint);
    _mav_put_float(buf, 68, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 96, flight_mode);
    _mav_put_uint16_t(buf, 98, flight_fct);
    _mav_put_uint8_t(buf, 100, alive);
    _mav_put_uint16_t_array(buf, 72, chnl, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, buf, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#else
    mavlink_dataraiin_t *packet = (mavlink_dataraiin_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->xi_setpoint = xi_setpoint;
    packet->eta_setpoint = eta_setpoint;
    packet->zeta_setpoint = zeta_setpoint;
    packet->throttle_setpoint = throttle_setpoint;
    packet->flaps_setpoint = flaps_setpoint;
    packet->roll_setpoint = roll_setpoint;
    packet->roll_rate_setpoint = roll_rate_setpoint;
    packet->pitch_setpoint = pitch_setpoint;
    packet->pitch_rate_setpoint = pitch_rate_setpoint;
    packet->yaw_setpoint = yaw_setpoint;
    packet->yaw_rate_setpoint = yaw_rate_setpoint;
    packet->tas_setpoint = tas_setpoint;
    packet->tas_rate_setpoint = tas_rate_setpoint;
    packet->hgt_setpoint = hgt_setpoint;
    packet->hgt_rate_setpoint = hgt_rate_setpoint;
    packet->flight_mode = flight_mode;
    packet->flight_fct = flight_fct;
    packet->alive = alive;
    mav_array_memcpy(packet->chnl, chnl, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, (const char *)packet, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#endif
}
#endif

#endif

// MESSAGE DataRaiIn UNPACKING


/**
 * @brief Get field time from dataraiin message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_dataraiin_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from dataraiin message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_dataraiin_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field chnl from dataraiin message
 *
 * @return  Channels with raw PWM values
 */
static inline uint16_t mavlink_msg_dataraiin_get_chnl(const mavlink_message_t* msg, uint16_t *chnl)
{
    return _MAV_RETURN_uint16_t_array(msg, chnl, 12,  72);
}

/**
 * @brief Get field xi_setpoint from dataraiin message
 *
 * @return  xi input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_xi_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field eta_setpoint from dataraiin message
 *
 * @return  eta input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_eta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field zeta_setpoint from dataraiin message
 *
 * @return  zeta input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_zeta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field throttle_setpoint from dataraiin message
 *
 * @return  Throttle input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_throttle_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field flaps_setpoint from dataraiin message
 *
 * @return  Flaps input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_flaps_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field roll_setpoint from dataraiin message
 *
 * @return  Roll input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_roll_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field roll_rate_setpoint from dataraiin message
 *
 * @return  Rollrate input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_roll_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field pitch_setpoint from dataraiin message
 *
 * @return  Pitch input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_pitch_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field pitch_rate_setpoint from dataraiin message
 *
 * @return  Pitchrate input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_pitch_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field yaw_setpoint from dataraiin message
 *
 * @return  Yaw input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_yaw_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yaw_rate_setpoint from dataraiin message
 *
 * @return  Yaw_rate input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_yaw_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field tas_setpoint from dataraiin message
 *
 * @return  TAS input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_tas_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field tas_rate_setpoint from dataraiin message
 *
 * @return  TAS rate input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_tas_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field hgt_setpoint from dataraiin message
 *
 * @return  Hgt input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_hgt_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field hgt_rate_setpoint from dataraiin message
 *
 * @return  Hgt_rate input from pilot (aka. setpoint)
 */
static inline float mavlink_msg_dataraiin_get_hgt_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field flight_mode from dataraiin message
 *
 * @return  Flightmode set by pilot
 */
static inline uint16_t mavlink_msg_dataraiin_get_flight_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  96);
}

/**
 * @brief Get field flight_fct from dataraiin message
 *
 * @return  Flightfunction set by pilot
 */
static inline uint16_t mavlink_msg_dataraiin_get_flight_fct(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  98);
}

/**
 * @brief Get field alive from dataraiin message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_dataraiin_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  100);
}

/**
 * @brief Decode a dataraiin message into a struct
 *
 * @param msg The message to decode
 * @param dataraiin C-struct to decode the message contents into
 */
static inline void mavlink_msg_dataraiin_decode(const mavlink_message_t* msg, mavlink_dataraiin_t* dataraiin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dataraiin->time = mavlink_msg_dataraiin_get_time(msg);
    dataraiin->senseTime = mavlink_msg_dataraiin_get_senseTime(msg);
    dataraiin->xi_setpoint = mavlink_msg_dataraiin_get_xi_setpoint(msg);
    dataraiin->eta_setpoint = mavlink_msg_dataraiin_get_eta_setpoint(msg);
    dataraiin->zeta_setpoint = mavlink_msg_dataraiin_get_zeta_setpoint(msg);
    dataraiin->throttle_setpoint = mavlink_msg_dataraiin_get_throttle_setpoint(msg);
    dataraiin->flaps_setpoint = mavlink_msg_dataraiin_get_flaps_setpoint(msg);
    dataraiin->roll_setpoint = mavlink_msg_dataraiin_get_roll_setpoint(msg);
    dataraiin->roll_rate_setpoint = mavlink_msg_dataraiin_get_roll_rate_setpoint(msg);
    dataraiin->pitch_setpoint = mavlink_msg_dataraiin_get_pitch_setpoint(msg);
    dataraiin->pitch_rate_setpoint = mavlink_msg_dataraiin_get_pitch_rate_setpoint(msg);
    dataraiin->yaw_setpoint = mavlink_msg_dataraiin_get_yaw_setpoint(msg);
    dataraiin->yaw_rate_setpoint = mavlink_msg_dataraiin_get_yaw_rate_setpoint(msg);
    dataraiin->tas_setpoint = mavlink_msg_dataraiin_get_tas_setpoint(msg);
    dataraiin->tas_rate_setpoint = mavlink_msg_dataraiin_get_tas_rate_setpoint(msg);
    dataraiin->hgt_setpoint = mavlink_msg_dataraiin_get_hgt_setpoint(msg);
    dataraiin->hgt_rate_setpoint = mavlink_msg_dataraiin_get_hgt_rate_setpoint(msg);
    mavlink_msg_dataraiin_get_chnl(msg, dataraiin->chnl);
    dataraiin->flight_mode = mavlink_msg_dataraiin_get_flight_mode(msg);
    dataraiin->flight_fct = mavlink_msg_dataraiin_get_flight_fct(msg);
    dataraiin->alive = mavlink_msg_dataraiin_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataRaiIn_LEN? msg->len : MAVLINK_MSG_ID_DataRaiIn_LEN;
        memset(dataraiin, 0, MAVLINK_MSG_ID_DataRaiIn_LEN);
    memcpy(dataraiin, _MAV_PAYLOAD(msg), len);
#endif
}
