#pragma once
// MESSAGE DataRaiOut PACKING

#define MAVLINK_MSG_ID_DataRaiOut 15000


typedef struct __mavlink_dataraiout_t {
 uint64_t time; /*<  System time at publication*/
 float xi_setpoint; /*<  xi command from fcc*/
 float eta_setpoint; /*<  eta command from fcc*/
 float zeta_setpoint; /*<  zeta command from fcc*/
 float throttle_setpoint; /*<  Thr command from fcc*/
 float flaps_setpoint; /*<  Flaps command from fcc*/
 uint16_t chnl[12]; /*<  Channels with raw PWM values*/
 uint16_t flight_mode; /*<  Flightmode*/
 uint16_t flight_fct; /*<  Flightfunction*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_dataraiout_t;

#define MAVLINK_MSG_ID_DataRaiOut_LEN 57
#define MAVLINK_MSG_ID_DataRaiOut_MIN_LEN 57
#define MAVLINK_MSG_ID_15000_LEN 57
#define MAVLINK_MSG_ID_15000_MIN_LEN 57

#define MAVLINK_MSG_ID_DataRaiOut_CRC 86
#define MAVLINK_MSG_ID_15000_CRC 86

#define MAVLINK_MSG_DataRaiOut_FIELD_CHNL_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataRaiOut { \
    15000, \
    "DataRaiOut", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiout_t, time) }, \
         { "chnl", NULL, MAVLINK_TYPE_UINT16_T, 12, 28, offsetof(mavlink_dataraiout_t, chnl) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiout_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiout_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiout_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiout_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiout_t, flaps_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_dataraiout_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_dataraiout_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_dataraiout_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataRaiOut { \
    "DataRaiOut", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiout_t, time) }, \
         { "chnl", NULL, MAVLINK_TYPE_UINT16_T, 12, 28, offsetof(mavlink_dataraiout_t, chnl) }, \
         { "xi_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiout_t, xi_setpoint) }, \
         { "eta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiout_t, eta_setpoint) }, \
         { "zeta_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiout_t, zeta_setpoint) }, \
         { "throttle_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiout_t, throttle_setpoint) }, \
         { "flaps_setpoint", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiout_t, flaps_setpoint) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_dataraiout_t, flight_mode) }, \
         { "flight_fct", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_dataraiout_t, flight_fct) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_dataraiout_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataraiout message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi command from fcc
 * @param eta_setpoint  eta command from fcc
 * @param zeta_setpoint  zeta command from fcc
 * @param throttle_setpoint  Thr command from fcc
 * @param flaps_setpoint  Flaps command from fcc
 * @param flight_mode  Flightmode
 * @param flight_fct  Flightfunction
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiout_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_uint16_t(buf, 52, flight_mode);
    _mav_put_uint16_t(buf, 54, flight_fct);
    _mav_put_uint8_t(buf, 56, alive);
    _mav_put_uint16_t_array(buf, 28, chnl, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiOut_LEN);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataRaiOut_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataRaiOut;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
}

/**
 * @brief Pack a dataraiout message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi command from fcc
 * @param eta_setpoint  eta command from fcc
 * @param zeta_setpoint  zeta command from fcc
 * @param throttle_setpoint  Thr command from fcc
 * @param flaps_setpoint  Flaps command from fcc
 * @param flight_mode  Flightmode
 * @param flight_fct  Flightfunction
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiout_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,const uint16_t *chnl,float xi_setpoint,float eta_setpoint,float zeta_setpoint,float throttle_setpoint,float flaps_setpoint,uint16_t flight_mode,uint16_t flight_fct,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_uint16_t(buf, 52, flight_mode);
    _mav_put_uint16_t(buf, 54, flight_fct);
    _mav_put_uint8_t(buf, 56, alive);
    _mav_put_uint16_t_array(buf, 28, chnl, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiOut_LEN);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataRaiOut_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataRaiOut;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
}

/**
 * @brief Encode a dataraiout struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dataraiout C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataraiout_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dataraiout_t* dataraiout)
{
    return mavlink_msg_dataraiout_pack(system_id, component_id, msg, dataraiout->time, dataraiout->chnl, dataraiout->xi_setpoint, dataraiout->eta_setpoint, dataraiout->zeta_setpoint, dataraiout->throttle_setpoint, dataraiout->flaps_setpoint, dataraiout->flight_mode, dataraiout->flight_fct, dataraiout->alive);
}

/**
 * @brief Encode a dataraiout struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dataraiout C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataraiout_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dataraiout_t* dataraiout)
{
    return mavlink_msg_dataraiout_pack_chan(system_id, component_id, chan, msg, dataraiout->time, dataraiout->chnl, dataraiout->xi_setpoint, dataraiout->eta_setpoint, dataraiout->zeta_setpoint, dataraiout->throttle_setpoint, dataraiout->flaps_setpoint, dataraiout->flight_mode, dataraiout->flight_fct, dataraiout->alive);
}

/**
 * @brief Send a dataraiout message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param chnl  Channels with raw PWM values
 * @param xi_setpoint  xi command from fcc
 * @param eta_setpoint  eta command from fcc
 * @param zeta_setpoint  zeta command from fcc
 * @param throttle_setpoint  Thr command from fcc
 * @param flaps_setpoint  Flaps command from fcc
 * @param flight_mode  Flightmode
 * @param flight_fct  Flightfunction
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataraiout_send(mavlink_channel_t chan, uint64_t time, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_uint16_t(buf, 52, flight_mode);
    _mav_put_uint16_t(buf, 54, flight_fct);
    _mav_put_uint8_t(buf, 56, alive);
    _mav_put_uint16_t_array(buf, 28, chnl, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, buf, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.xi_setpoint = xi_setpoint;
    packet.eta_setpoint = eta_setpoint;
    packet.zeta_setpoint = zeta_setpoint;
    packet.throttle_setpoint = throttle_setpoint;
    packet.flaps_setpoint = flaps_setpoint;
    packet.flight_mode = flight_mode;
    packet.flight_fct = flight_fct;
    packet.alive = alive;
    mav_array_memcpy(packet.chnl, chnl, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, (const char *)&packet, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#endif
}

/**
 * @brief Send a dataraiout message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dataraiout_send_struct(mavlink_channel_t chan, const mavlink_dataraiout_t* dataraiout)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dataraiout_send(chan, dataraiout->time, dataraiout->chnl, dataraiout->xi_setpoint, dataraiout->eta_setpoint, dataraiout->zeta_setpoint, dataraiout->throttle_setpoint, dataraiout->flaps_setpoint, dataraiout->flight_mode, dataraiout->flight_fct, dataraiout->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, (const char *)dataraiout, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataRaiOut_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataraiout_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, const uint16_t *chnl, float xi_setpoint, float eta_setpoint, float zeta_setpoint, float throttle_setpoint, float flaps_setpoint, uint16_t flight_mode, uint16_t flight_fct, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi_setpoint);
    _mav_put_float(buf, 12, eta_setpoint);
    _mav_put_float(buf, 16, zeta_setpoint);
    _mav_put_float(buf, 20, throttle_setpoint);
    _mav_put_float(buf, 24, flaps_setpoint);
    _mav_put_uint16_t(buf, 52, flight_mode);
    _mav_put_uint16_t(buf, 54, flight_fct);
    _mav_put_uint8_t(buf, 56, alive);
    _mav_put_uint16_t_array(buf, 28, chnl, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, buf, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#else
    mavlink_dataraiout_t *packet = (mavlink_dataraiout_t *)msgbuf;
    packet->time = time;
    packet->xi_setpoint = xi_setpoint;
    packet->eta_setpoint = eta_setpoint;
    packet->zeta_setpoint = zeta_setpoint;
    packet->throttle_setpoint = throttle_setpoint;
    packet->flaps_setpoint = flaps_setpoint;
    packet->flight_mode = flight_mode;
    packet->flight_fct = flight_fct;
    packet->alive = alive;
    mav_array_memcpy(packet->chnl, chnl, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, (const char *)packet, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#endif
}
#endif

#endif

// MESSAGE DataRaiOut UNPACKING


/**
 * @brief Get field time from dataraiout message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_dataraiout_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field chnl from dataraiout message
 *
 * @return  Channels with raw PWM values
 */
static inline uint16_t mavlink_msg_dataraiout_get_chnl(const mavlink_message_t* msg, uint16_t *chnl)
{
    return _MAV_RETURN_uint16_t_array(msg, chnl, 12,  28);
}

/**
 * @brief Get field xi_setpoint from dataraiout message
 *
 * @return  xi command from fcc
 */
static inline float mavlink_msg_dataraiout_get_xi_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field eta_setpoint from dataraiout message
 *
 * @return  eta command from fcc
 */
static inline float mavlink_msg_dataraiout_get_eta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zeta_setpoint from dataraiout message
 *
 * @return  zeta command from fcc
 */
static inline float mavlink_msg_dataraiout_get_zeta_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field throttle_setpoint from dataraiout message
 *
 * @return  Thr command from fcc
 */
static inline float mavlink_msg_dataraiout_get_throttle_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field flaps_setpoint from dataraiout message
 *
 * @return  Flaps command from fcc
 */
static inline float mavlink_msg_dataraiout_get_flaps_setpoint(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field flight_mode from dataraiout message
 *
 * @return  Flightmode
 */
static inline uint16_t mavlink_msg_dataraiout_get_flight_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field flight_fct from dataraiout message
 *
 * @return  Flightfunction
 */
static inline uint16_t mavlink_msg_dataraiout_get_flight_fct(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  54);
}

/**
 * @brief Get field alive from dataraiout message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_dataraiout_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Decode a dataraiout message into a struct
 *
 * @param msg The message to decode
 * @param dataraiout C-struct to decode the message contents into
 */
static inline void mavlink_msg_dataraiout_decode(const mavlink_message_t* msg, mavlink_dataraiout_t* dataraiout)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dataraiout->time = mavlink_msg_dataraiout_get_time(msg);
    dataraiout->xi_setpoint = mavlink_msg_dataraiout_get_xi_setpoint(msg);
    dataraiout->eta_setpoint = mavlink_msg_dataraiout_get_eta_setpoint(msg);
    dataraiout->zeta_setpoint = mavlink_msg_dataraiout_get_zeta_setpoint(msg);
    dataraiout->throttle_setpoint = mavlink_msg_dataraiout_get_throttle_setpoint(msg);
    dataraiout->flaps_setpoint = mavlink_msg_dataraiout_get_flaps_setpoint(msg);
    mavlink_msg_dataraiout_get_chnl(msg, dataraiout->chnl);
    dataraiout->flight_mode = mavlink_msg_dataraiout_get_flight_mode(msg);
    dataraiout->flight_fct = mavlink_msg_dataraiout_get_flight_fct(msg);
    dataraiout->alive = mavlink_msg_dataraiout_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataRaiOut_LEN? msg->len : MAVLINK_MSG_ID_DataRaiOut_LEN;
        memset(dataraiout, 0, MAVLINK_MSG_ID_DataRaiOut_LEN);
    memcpy(dataraiout, _MAV_PAYLOAD(msg), len);
#endif
}
