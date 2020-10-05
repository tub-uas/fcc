#pragma once
// MESSAGE DataRaiOut PACKING

#define MAVLINK_MSG_ID_DataRaiOut 15000


typedef struct __mavlink_dataraiout_t {
 uint64_t time; /*<  Time.*/
 float roll; /*<  Output ailleron.*/
 float pitch; /*<  Output elevator.*/
 float yaw; /*<  Output rudder.*/
 float thr; /*<  Output thrust.*/
 uint16_t chnls[12]; /*<  Channels.*/
 uint16_t fltMode; /*<  Flightmode.*/
 uint8_t alive; /*<   Alive.*/
} mavlink_dataraiout_t;

#define MAVLINK_MSG_ID_DataRaiOut_LEN 51
#define MAVLINK_MSG_ID_DataRaiOut_MIN_LEN 51
#define MAVLINK_MSG_ID_15000_LEN 51
#define MAVLINK_MSG_ID_15000_MIN_LEN 51

#define MAVLINK_MSG_ID_DataRaiOut_CRC 117
#define MAVLINK_MSG_ID_15000_CRC 117

#define MAVLINK_MSG_DataRaiOut_FIELD_CHNLS_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataRaiOut { \
    15000, \
    "DataRaiOut", \
    8, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiout_t, time) }, \
         { "chnls", NULL, MAVLINK_TYPE_UINT16_T, 12, 24, offsetof(mavlink_dataraiout_t, chnls) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiout_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiout_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiout_t, yaw) }, \
         { "thr", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiout_t, thr) }, \
         { "fltMode", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_dataraiout_t, fltMode) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_dataraiout_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataRaiOut { \
    "DataRaiOut", \
    8, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiout_t, time) }, \
         { "chnls", NULL, MAVLINK_TYPE_UINT16_T, 12, 24, offsetof(mavlink_dataraiout_t, chnls) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiout_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiout_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiout_t, yaw) }, \
         { "thr", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiout_t, thr) }, \
         { "fltMode", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_dataraiout_t, fltMode) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_dataraiout_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataraiout message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  Time.
 * @param chnls  Channels.
 * @param roll  Output ailleron.
 * @param pitch  Output elevator.
 * @param yaw  Output rudder.
 * @param thr  Output thrust.
 * @param fltMode  Flightmode.
 * @param alive   Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiout_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, const uint16_t *chnls, float roll, float pitch, float yaw, float thr, uint16_t fltMode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, thr);
    _mav_put_uint16_t(buf, 48, fltMode);
    _mav_put_uint8_t(buf, 50, alive);
    _mav_put_uint16_t_array(buf, 24, chnls, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiOut_LEN);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltMode = fltMode;
    packet.alive = alive;
    mav_array_memcpy(packet.chnls, chnls, sizeof(uint16_t)*12);
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
 * @param time  Time.
 * @param chnls  Channels.
 * @param roll  Output ailleron.
 * @param pitch  Output elevator.
 * @param yaw  Output rudder.
 * @param thr  Output thrust.
 * @param fltMode  Flightmode.
 * @param alive   Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiout_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,const uint16_t *chnls,float roll,float pitch,float yaw,float thr,uint16_t fltMode,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, thr);
    _mav_put_uint16_t(buf, 48, fltMode);
    _mav_put_uint8_t(buf, 50, alive);
    _mav_put_uint16_t_array(buf, 24, chnls, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiOut_LEN);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltMode = fltMode;
    packet.alive = alive;
    mav_array_memcpy(packet.chnls, chnls, sizeof(uint16_t)*12);
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
    return mavlink_msg_dataraiout_pack(system_id, component_id, msg, dataraiout->time, dataraiout->chnls, dataraiout->roll, dataraiout->pitch, dataraiout->yaw, dataraiout->thr, dataraiout->fltMode, dataraiout->alive);
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
    return mavlink_msg_dataraiout_pack_chan(system_id, component_id, chan, msg, dataraiout->time, dataraiout->chnls, dataraiout->roll, dataraiout->pitch, dataraiout->yaw, dataraiout->thr, dataraiout->fltMode, dataraiout->alive);
}

/**
 * @brief Send a dataraiout message
 * @param chan MAVLink channel to send the message
 *
 * @param time  Time.
 * @param chnls  Channels.
 * @param roll  Output ailleron.
 * @param pitch  Output elevator.
 * @param yaw  Output rudder.
 * @param thr  Output thrust.
 * @param fltMode  Flightmode.
 * @param alive   Alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataraiout_send(mavlink_channel_t chan, uint64_t time, const uint16_t *chnls, float roll, float pitch, float yaw, float thr, uint16_t fltMode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiOut_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, thr);
    _mav_put_uint16_t(buf, 48, fltMode);
    _mav_put_uint8_t(buf, 50, alive);
    _mav_put_uint16_t_array(buf, 24, chnls, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, buf, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#else
    mavlink_dataraiout_t packet;
    packet.time = time;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltMode = fltMode;
    packet.alive = alive;
    mav_array_memcpy(packet.chnls, chnls, sizeof(uint16_t)*12);
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
    mavlink_msg_dataraiout_send(chan, dataraiout->time, dataraiout->chnls, dataraiout->roll, dataraiout->pitch, dataraiout->yaw, dataraiout->thr, dataraiout->fltMode, dataraiout->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, (const char *)dataraiout, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataRaiOut_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataraiout_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, const uint16_t *chnls, float roll, float pitch, float yaw, float thr, uint16_t fltMode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, thr);
    _mav_put_uint16_t(buf, 48, fltMode);
    _mav_put_uint8_t(buf, 50, alive);
    _mav_put_uint16_t_array(buf, 24, chnls, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, buf, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#else
    mavlink_dataraiout_t *packet = (mavlink_dataraiout_t *)msgbuf;
    packet->time = time;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->thr = thr;
    packet->fltMode = fltMode;
    packet->alive = alive;
    mav_array_memcpy(packet->chnls, chnls, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiOut, (const char *)packet, MAVLINK_MSG_ID_DataRaiOut_MIN_LEN, MAVLINK_MSG_ID_DataRaiOut_LEN, MAVLINK_MSG_ID_DataRaiOut_CRC);
#endif
}
#endif

#endif

// MESSAGE DataRaiOut UNPACKING


/**
 * @brief Get field time from dataraiout message
 *
 * @return  Time.
 */
static inline uint64_t mavlink_msg_dataraiout_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field chnls from dataraiout message
 *
 * @return  Channels.
 */
static inline uint16_t mavlink_msg_dataraiout_get_chnls(const mavlink_message_t* msg, uint16_t *chnls)
{
    return _MAV_RETURN_uint16_t_array(msg, chnls, 12,  24);
}

/**
 * @brief Get field roll from dataraiout message
 *
 * @return  Output ailleron.
 */
static inline float mavlink_msg_dataraiout_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch from dataraiout message
 *
 * @return  Output elevator.
 */
static inline float mavlink_msg_dataraiout_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from dataraiout message
 *
 * @return  Output rudder.
 */
static inline float mavlink_msg_dataraiout_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field thr from dataraiout message
 *
 * @return  Output thrust.
 */
static inline float mavlink_msg_dataraiout_get_thr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field fltMode from dataraiout message
 *
 * @return  Flightmode.
 */
static inline uint16_t mavlink_msg_dataraiout_get_fltMode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field alive from dataraiout message
 *
 * @return   Alive.
 */
static inline uint8_t mavlink_msg_dataraiout_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  50);
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
    dataraiout->roll = mavlink_msg_dataraiout_get_roll(msg);
    dataraiout->pitch = mavlink_msg_dataraiout_get_pitch(msg);
    dataraiout->yaw = mavlink_msg_dataraiout_get_yaw(msg);
    dataraiout->thr = mavlink_msg_dataraiout_get_thr(msg);
    mavlink_msg_dataraiout_get_chnls(msg, dataraiout->chnls);
    dataraiout->fltMode = mavlink_msg_dataraiout_get_fltMode(msg);
    dataraiout->alive = mavlink_msg_dataraiout_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataRaiOut_LEN? msg->len : MAVLINK_MSG_ID_DataRaiOut_LEN;
        memset(dataraiout, 0, MAVLINK_MSG_ID_DataRaiOut_LEN);
    memcpy(dataraiout, _MAV_PAYLOAD(msg), len);
#endif
}
