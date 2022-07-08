#pragma once
// MESSAGE DataCtrl PACKING

#define MAVLINK_MSG_ID_DataCtrl 50000


typedef struct __mavlink_datactrl_t {
 uint64_t time; /*<  System time at publication*/
 float xi_setpoint; /*<  xi controller output (aka. setpoint)*/
 float eta_setpoint; /*<  eta controller output (aka. setpoint)*/
 float zeta_setpoint; /*<  zeta controller output (aka. setpoint)*/
 float throttle_setpoint; /*<  Throttle controller output (aka. setpoint)*/
 float flaps_setpoint; /*<  Flaps controller output (aka. setpoint)*/
 float roll_setpoint; /*<  Roll controller output (aka. setpoint)*/
 float roll_rate_setpoint; /*<  Rollrate controller output (aka. setpoint)*/
 float pitch_setpoint; /*<  Pitch controller output (aka. setpoint)*/
 float pitch_rate_setpoint; /*<  Pitchrate controller output (aka. setpoint)*/
 float yaw_setpoint; /*<  Yaw controller output (aka. setpoint)*/
 float yaw_rate_setpoint; /*<  Yaw_rate controller output (aka. setpoint)*/
 float tas_setpoint; /*<  TAS controller output (aka. setpoint)*/
 float tas_rate_setpoint; /*<  TAS controller output (aka. setpoint)*/
 float hgt_setpoint; /*<  Hgt controller output (aka. setpoint)*/
 float hgt_rate_setpoint; /*<  Hgt_rate controller output (aka. setpoint)*/
 uint16_t flight_mode; /*<  Flightmode set by pilot*/
 uint16_t flight_fct; /*<  Flightfunction set by pilot*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_datactrl_t;

#define MAVLINK_MSG_ID_DataCtrl_LEN 73
#define MAVLINK_MSG_ID_DataCtrl_MIN_LEN 73
#define MAVLINK_MSG_ID_50000_LEN 73
#define MAVLINK_MSG_ID_50000_MIN_LEN 73

#define MAVLINK_MSG_ID_DataCtrl_CRC 247
#define MAVLINK_MSG_ID_50000_CRC 247



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataCtrl { \
    50000, \
    "DataCtrl", \
    19, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datactrl_t, time) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datactrl_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datactrl_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datactrl_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datactrl_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datactrl_t, flaps_setpoint) }, \
         { "roll_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datactrl_t, roll_setpoint) }, \
         { "roll_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datactrl_t, roll_rate_setpoint) }, \
         { "pitch_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datactrl_t, pitch_setpoint) }, \
         { "pitch_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datactrl_t, pitch_rate_setpoint) }, \
         { "yaw_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datactrl_t, yaw_setpoint) }, \
         { "yaw_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datactrl_t, yaw_rate_setpoint) }, \
         { "tas_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datactrl_t, tas_setpoint) }, \
         { "tas_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datactrl_t, tas_rate_setpoint) }, \
         { "hgt_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datactrl_t, hgt_setpoint) }, \
         { "hgt_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datactrl_t, hgt_rate_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_datactrl_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_datactrl_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 72, offsetof(mavlink_datactrl_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataCtrl { \
    "DataCtrl", \
    19, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datactrl_t, time) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datactrl_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datactrl_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datactrl_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datactrl_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datactrl_t, flaps_setpoint) }, \
         { "roll_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datactrl_t, roll_setpoint) }, \
         { "roll_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datactrl_t, roll_rate_setpoint) }, \
         { "pitch_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datactrl_t, pitch_setpoint) }, \
         { "pitch_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datactrl_t, pitch_rate_setpoint) }, \
         { "yaw_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datactrl_t, yaw_setpoint) }, \
         { "yaw_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datactrl_t, yaw_rate_setpoint) }, \
         { "tas_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datactrl_t, tas_setpoint) }, \
         { "tas_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datactrl_t, tas_rate_setpoint) }, \
         { "hgt_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datactrl_t, hgt_setpoint) }, \
         { "hgt_rate_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datactrl_t, hgt_rate_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_datactrl_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_datactrl_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 72, offsetof(mavlink_datactrl_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datactrl message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param xi_setpoint  xi controller output (aka. setpoint)
 * @param eta_setpoint  eta controller output (aka. setpoint)
 * @param zeta_setpoint  zeta controller output (aka. setpoint)
 * @param throttle_setpoint  Throttle controller output (aka. setpoint)
 * @param flaps_setpoint  Flaps controller output (aka. setpoint)
 * @param roll_setpoint  Roll controller output (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate controller output (aka. setpoint)
 * @param pitch_setpoint  Pitch controller output (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate controller output (aka. setpoint)
 * @param yaw_setpoint  Yaw controller output (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate controller output (aka. setpoint)
 * @param tas_setpoint  TAS controller output (aka. setpoint)
 * @param tas_rate_setpoint  TAS controller output (aka. setpoint)
 * @param hgt_setpoint  Hgt controller output (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate controller output (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datactrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_float(buf, 28, roll_setpoint);
    _mav_put_float(buf, 32, roll_rate_setpoint);
    _mav_put_float(buf, 36, pitch_setpoint);
    _mav_put_float(buf, 40, pitch_rate_setpoint);
    _mav_put_float(buf, 44, yaw_setpoint);
    _mav_put_float(buf, 48, yaw_rate_setpoint);
    _mav_put_float(buf, 52, tas_setpoint);
    _mav_put_float(buf, 56, tas_rate_setpoint);
    _mav_put_float(buf, 60, hgt_setpoint);
    _mav_put_float(buf, 64, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 68, flight_mode);
    _mav_put_uint16_t(buf, 70, flight_fct);
    _mav_put_uint8_t(buf, 72, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataCtrl_LEN);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataCtrl_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataCtrl;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
}

/**
 * @brief Pack a datactrl message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param xi_setpoint  xi controller output (aka. setpoint)
 * @param eta_setpoint  eta controller output (aka. setpoint)
 * @param zeta_setpoint  zeta controller output (aka. setpoint)
 * @param throttle_setpoint  Throttle controller output (aka. setpoint)
 * @param flaps_setpoint  Flaps controller output (aka. setpoint)
 * @param roll_setpoint  Roll controller output (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate controller output (aka. setpoint)
 * @param pitch_setpoint  Pitch controller output (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate controller output (aka. setpoint)
 * @param yaw_setpoint  Yaw controller output (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate controller output (aka. setpoint)
 * @param tas_setpoint  TAS controller output (aka. setpoint)
 * @param tas_rate_setpoint  TAS controller output (aka. setpoint)
 * @param hgt_setpoint  Hgt controller output (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate controller output (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datactrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float xi_setpoint,float eta_setpoint,float zeta_setpoint,float throttle_setpoint,float flaps_setpoint,float roll_setpoint,float roll_rate_setpoint,float pitch_setpoint,float pitch_rate_setpoint,float yaw_setpoint,float yaw_rate_setpoint,float tas_setpoint,float tas_rate_setpoint,float hgt_setpoint,float hgt_rate_setpoint,uint16_t flight_mode,uint16_t flight_fct,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_float(buf, 28, roll_setpoint);
    _mav_put_float(buf, 32, roll_rate_setpoint);
    _mav_put_float(buf, 36, pitch_setpoint);
    _mav_put_float(buf, 40, pitch_rate_setpoint);
    _mav_put_float(buf, 44, yaw_setpoint);
    _mav_put_float(buf, 48, yaw_rate_setpoint);
    _mav_put_float(buf, 52, tas_setpoint);
    _mav_put_float(buf, 56, tas_rate_setpoint);
    _mav_put_float(buf, 60, hgt_setpoint);
    _mav_put_float(buf, 64, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 68, flight_mode);
    _mav_put_uint16_t(buf, 70, flight_fct);
    _mav_put_uint8_t(buf, 72, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataCtrl_LEN);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataCtrl_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataCtrl;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
}

/**
 * @brief Encode a datactrl struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datactrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datactrl_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datactrl_t* datactrl)
{
    return mavlink_msg_datactrl_pack(system_id, component_id, msg, datactrl->time, datactrl->xi_setpoint, datactrl->eta_setpoint, datactrl->zeta_setpoint, datactrl->throttle_setpoint, datactrl->flaps_setpoint, datactrl->roll_setpoint, datactrl->roll_rate_setpoint, datactrl->pitch_setpoint, datactrl->pitch_rate_setpoint, datactrl->yaw_setpoint, datactrl->yaw_rate_setpoint, datactrl->tas_setpoint, datactrl->tas_rate_setpoint, datactrl->hgt_setpoint, datactrl->hgt_rate_setpoint, datactrl->flight_mode, datactrl->flight_fct, datactrl->alive);
}

/**
 * @brief Encode a datactrl struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datactrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datactrl_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datactrl_t* datactrl)
{
    return mavlink_msg_datactrl_pack_chan(system_id, component_id, chan, msg, datactrl->time, datactrl->xi_setpoint, datactrl->eta_setpoint, datactrl->zeta_setpoint, datactrl->throttle_setpoint, datactrl->flaps_setpoint, datactrl->roll_setpoint, datactrl->roll_rate_setpoint, datactrl->pitch_setpoint, datactrl->pitch_rate_setpoint, datactrl->yaw_setpoint, datactrl->yaw_rate_setpoint, datactrl->tas_setpoint, datactrl->tas_rate_setpoint, datactrl->hgt_setpoint, datactrl->hgt_rate_setpoint, datactrl->flight_mode, datactrl->flight_fct, datactrl->alive);
}

/**
 * @brief Send a datactrl message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param xi_setpoint  xi controller output (aka. setpoint)
 * @param eta_setpoint  eta controller output (aka. setpoint)
 * @param zeta_setpoint  zeta controller output (aka. setpoint)
 * @param throttle_setpoint  Throttle controller output (aka. setpoint)
 * @param flaps_setpoint  Flaps controller output (aka. setpoint)
 * @param roll_setpoint  Roll controller output (aka. setpoint)
 * @param roll_rate_setpoint  Rollrate controller output (aka. setpoint)
 * @param pitch_setpoint  Pitch controller output (aka. setpoint)
 * @param pitch_rate_setpoint  Pitchrate controller output (aka. setpoint)
 * @param yaw_setpoint  Yaw controller output (aka. setpoint)
 * @param yaw_rate_setpoint  Yaw_rate controller output (aka. setpoint)
 * @param tas_setpoint  TAS controller output (aka. setpoint)
 * @param tas_rate_setpoint  TAS controller output (aka. setpoint)
 * @param hgt_setpoint  Hgt controller output (aka. setpoint)
 * @param hgt_rate_setpoint  Hgt_rate controller output (aka. setpoint)
 * @param flight_mode  Flightmode set by pilot
 * @param flight_fct  Flightfunction set by pilot
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datactrl_send(mavlink_channel_t chan, uint64_t time, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_float(buf, 28, roll_setpoint);
    _mav_put_float(buf, 32, roll_rate_setpoint);
    _mav_put_float(buf, 36, pitch_setpoint);
    _mav_put_float(buf, 40, pitch_rate_setpoint);
    _mav_put_float(buf, 44, yaw_setpoint);
    _mav_put_float(buf, 48, yaw_rate_setpoint);
    _mav_put_float(buf, 52, tas_setpoint);
    _mav_put_float(buf, 56, tas_rate_setpoint);
    _mav_put_float(buf, 60, hgt_setpoint);
    _mav_put_float(buf, 64, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 68, flight_mode);
    _mav_put_uint16_t(buf, 70, flight_fct);
    _mav_put_uint8_t(buf, 72, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, buf, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, (const char *)&packet, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#endif
}

/**
 * @brief Send a datactrl message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datactrl_send_struct(mavlink_channel_t chan, const mavlink_datactrl_t* datactrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datactrl_send(chan, datactrl->time, datactrl->xi_setpoint, datactrl->eta_setpoint, datactrl->zeta_setpoint, datactrl->throttle_setpoint, datactrl->flaps_setpoint, datactrl->roll_setpoint, datactrl->roll_rate_setpoint, datactrl->pitch_setpoint, datactrl->pitch_rate_setpoint, datactrl->yaw_setpoint, datactrl->yaw_rate_setpoint, datactrl->tas_setpoint, datactrl->tas_rate_setpoint, datactrl->hgt_setpoint, datactrl->hgt_rate_setpoint, datactrl->flight_mode, datactrl->flight_fct, datactrl->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, (const char *)datactrl, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataCtrl_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datactrl_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, float roll_setpoint, float roll_rate_setpoint, float pitch_setpoint, float pitch_rate_setpoint, float yaw_setpoint, float yaw_rate_setpoint, float tas_setpoint, float tas_rate_setpoint, float hgt_setpoint, float hgt_rate_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_float(buf, 28, roll_setpoint);
    _mav_put_float(buf, 32, roll_rate_setpoint);
    _mav_put_float(buf, 36, pitch_setpoint);
    _mav_put_float(buf, 40, pitch_rate_setpoint);
    _mav_put_float(buf, 44, yaw_setpoint);
    _mav_put_float(buf, 48, yaw_rate_setpoint);
    _mav_put_float(buf, 52, tas_setpoint);
    _mav_put_float(buf, 56, tas_rate_setpoint);
    _mav_put_float(buf, 60, hgt_setpoint);
    _mav_put_float(buf, 64, hgt_rate_setpoint);
    _mav_put_uint16_t(buf, 68, flight_mode);
    _mav_put_uint16_t(buf, 70, flight_fct);
    _mav_put_uint8_t(buf, 72, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, buf, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#else
    mavlink_datactrl_t *packet = (mavlink_datactrl_t *)msgbuf;
    packet->time = time;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, (const char *)packet, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#endif
}
#endif

#endif

// MESSAGE DataCtrl UNPACKING


/**
 * @brief Get field time from datactrl message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datactrl_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xi_setpoint from datactrl message
 *
 * @return  xi controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_xi_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field eta_setpoint from datactrl message
 *
 * @return  eta controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_eta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zeta_setpoint from datactrl message
 *
 * @return  zeta controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_zeta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field throttle_setpoint from datactrl message
 *
 * @return  Throttle controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_throttle_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field flaps_setpoint from datactrl message
 *
 * @return  Flaps controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_flaps_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field roll_setpoint from datactrl message
 *
 * @return  Roll controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_roll_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field roll_rate_setpoint from datactrl message
 *
 * @return  Rollrate controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_roll_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pitch_setpoint from datactrl message
 *
 * @return  Pitch controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_pitch_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field pitch_rate_setpoint from datactrl message
 *
 * @return  Pitchrate controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_pitch_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field yaw_setpoint from datactrl message
 *
 * @return  Yaw controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_yaw_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field yaw_rate_setpoint from datactrl message
 *
 * @return  Yaw_rate controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_yaw_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field tas_setpoint from datactrl message
 *
 * @return  TAS controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_tas_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field tas_rate_setpoint from datactrl message
 *
 * @return  TAS controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_tas_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field hgt_setpoint from datactrl message
 *
 * @return  Hgt controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_hgt_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field hgt_rate_setpoint from datactrl message
 *
 * @return  Hgt_rate controller output (aka. setpoint)
 */
static inline float mavlink_msg_datactrl_get_hgt_rate_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field flight_mode from datactrl message
 *
 * @return  Flightmode set by pilot
 */
static inline uint16_t mavlink_msg_datactrl_get_flight_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  68);
}

/**
 * @brief Get field flight_fct from datactrl message
 *
 * @return  Flightfunction set by pilot
 */
static inline uint16_t mavlink_msg_datactrl_get_flight_fct(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  70);
}

/**
 * @brief Get field alive from datactrl message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_datactrl_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  72);
}

/**
 * @brief Decode a datactrl message into a struct
 *
 * @param msg The message to decode
 * @param datactrl C-struct to decode the message contents into
 */
static inline void mavlink_msg_datactrl_decode(const mavlink_message_t* msg, mavlink_datactrl_t* datactrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datactrl->time = mavlink_msg_datactrl_get_time(msg);
    datactrl->xi_setpoint = mavlink_msg_datactrl_get_xi_setpoint(msg);
    datactrl->eta_setpoint = mavlink_msg_datactrl_get_eta_setpoint(msg);
    datactrl->zeta_setpoint = mavlink_msg_datactrl_get_zeta_setpoint(msg);
    datactrl->throttle_setpoint = mavlink_msg_datactrl_get_throttle_setpoint(msg);
    datactrl->flaps_setpoint = mavlink_msg_datactrl_get_flaps_setpoint(msg);
    datactrl->roll_setpoint = mavlink_msg_datactrl_get_roll_setpoint(msg);
    datactrl->roll_rate_setpoint = mavlink_msg_datactrl_get_roll_rate_setpoint(msg);
    datactrl->pitch_setpoint = mavlink_msg_datactrl_get_pitch_setpoint(msg);
    datactrl->pitch_rate_setpoint = mavlink_msg_datactrl_get_pitch_rate_setpoint(msg);
    datactrl->yaw_setpoint = mavlink_msg_datactrl_get_yaw_setpoint(msg);
    datactrl->yaw_rate_setpoint = mavlink_msg_datactrl_get_yaw_rate_setpoint(msg);
    datactrl->tas_setpoint = mavlink_msg_datactrl_get_tas_setpoint(msg);
    datactrl->tas_rate_setpoint = mavlink_msg_datactrl_get_tas_rate_setpoint(msg);
    datactrl->hgt_setpoint = mavlink_msg_datactrl_get_hgt_setpoint(msg);
    datactrl->hgt_rate_setpoint = mavlink_msg_datactrl_get_hgt_rate_setpoint(msg);
    datactrl->flight_mode = mavlink_msg_datactrl_get_flight_mode(msg);
    datactrl->flight_fct = mavlink_msg_datactrl_get_flight_fct(msg);
    datactrl->alive = mavlink_msg_datactrl_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataCtrl_LEN? msg->len : MAVLINK_MSG_ID_DataCtrl_LEN;
        memset(datactrl, 0, MAVLINK_MSG_ID_DataCtrl_LEN);
    memcpy(datactrl, _MAV_PAYLOAD(msg), len);
#endif
}
