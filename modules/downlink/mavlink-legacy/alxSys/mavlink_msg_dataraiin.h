#pragma once
// MESSAGE DataRaiIn PACKING

#define MAVLINK_MSG_ID_DataRaiIn 10000


typedef struct __mavlink_dataraiin_t {
 uint64_t time; /*<  Time.*/
 float senseTime; /*<  Sensetime.*/
 float roll; /*<  Setpoint ailleron.*/
 float pitch; /*<  Setpoint elevator.*/
 float yaw; /*<  Setpoint rudder.*/
 float thr; /*<  Setpoint thrust.*/
 uint16_t channels[12]; /*<  Channels.*/
 uint16_t fltmode; /*<  Flightmode.*/
 uint8_t alive; /*<   Alive.*/
} mavlink_dataraiin_t;

#define MAVLINK_MSG_ID_DataRaiIn_LEN 55
#define MAVLINK_MSG_ID_DataRaiIn_MIN_LEN 55
#define MAVLINK_MSG_ID_10000_LEN 55
#define MAVLINK_MSG_ID_10000_MIN_LEN 55

#define MAVLINK_MSG_ID_DataRaiIn_CRC 45
#define MAVLINK_MSG_ID_10000_CRC 45

#define MAVLINK_MSG_DataRaiIn_FIELD_CHANNELS_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataRaiIn { \
    10000, \
    "DataRaiIn", \
    9, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiin_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiin_t, senseTime) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 12, 28, offsetof(mavlink_dataraiin_t, channels) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiin_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiin_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiin_t, yaw) }, \
         { "thr", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiin_t, thr) }, \
         { "fltmode", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_dataraiin_t, fltmode) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_dataraiin_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataRaiIn { \
    "DataRaiIn", \
    9, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataraiin_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataraiin_t, senseTime) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 12, 28, offsetof(mavlink_dataraiin_t, channels) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataraiin_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataraiin_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataraiin_t, yaw) }, \
         { "thr", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataraiin_t, thr) }, \
         { "fltmode", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_dataraiin_t, fltmode) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_dataraiin_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataraiin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param channels  Channels.
 * @param roll  Setpoint ailleron.
 * @param pitch  Setpoint elevator.
 * @param yaw  Setpoint rudder.
 * @param thr  Setpoint thrust.
 * @param fltmode  Flightmode.
 * @param alive   Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, const uint16_t *channels, float roll, float pitch, float yaw, float thr, uint16_t fltmode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, pitch);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, thr);
    _mav_put_uint16_t(buf, 52, fltmode);
    _mav_put_uint8_t(buf, 54, alive);
    _mav_put_uint16_t_array(buf, 28, channels, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiIn_LEN);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltmode = fltmode;
    packet.alive = alive;
    mav_array_memcpy(packet.channels, channels, sizeof(uint16_t)*12);
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
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param channels  Channels.
 * @param roll  Setpoint ailleron.
 * @param pitch  Setpoint elevator.
 * @param yaw  Setpoint rudder.
 * @param thr  Setpoint thrust.
 * @param fltmode  Flightmode.
 * @param alive   Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataraiin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,const uint16_t *channels,float roll,float pitch,float yaw,float thr,uint16_t fltmode,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, pitch);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, thr);
    _mav_put_uint16_t(buf, 52, fltmode);
    _mav_put_uint8_t(buf, 54, alive);
    _mav_put_uint16_t_array(buf, 28, channels, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataRaiIn_LEN);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltmode = fltmode;
    packet.alive = alive;
    mav_array_memcpy(packet.channels, channels, sizeof(uint16_t)*12);
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
    return mavlink_msg_dataraiin_pack(system_id, component_id, msg, dataraiin->time, dataraiin->senseTime, dataraiin->channels, dataraiin->roll, dataraiin->pitch, dataraiin->yaw, dataraiin->thr, dataraiin->fltmode, dataraiin->alive);
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
    return mavlink_msg_dataraiin_pack_chan(system_id, component_id, chan, msg, dataraiin->time, dataraiin->senseTime, dataraiin->channels, dataraiin->roll, dataraiin->pitch, dataraiin->yaw, dataraiin->thr, dataraiin->fltmode, dataraiin->alive);
}

/**
 * @brief Send a dataraiin message
 * @param chan MAVLink channel to send the message
 *
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param channels  Channels.
 * @param roll  Setpoint ailleron.
 * @param pitch  Setpoint elevator.
 * @param yaw  Setpoint rudder.
 * @param thr  Setpoint thrust.
 * @param fltmode  Flightmode.
 * @param alive   Alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataraiin_send(mavlink_channel_t chan, uint64_t time, float senseTime, const uint16_t *channels, float roll, float pitch, float yaw, float thr, uint16_t fltmode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataRaiIn_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, pitch);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, thr);
    _mav_put_uint16_t(buf, 52, fltmode);
    _mav_put_uint8_t(buf, 54, alive);
    _mav_put_uint16_t_array(buf, 28, channels, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, buf, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#else
    mavlink_dataraiin_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.thr = thr;
    packet.fltmode = fltmode;
    packet.alive = alive;
    mav_array_memcpy(packet.channels, channels, sizeof(uint16_t)*12);
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
    mavlink_msg_dataraiin_send(chan, dataraiin->time, dataraiin->senseTime, dataraiin->channels, dataraiin->roll, dataraiin->pitch, dataraiin->yaw, dataraiin->thr, dataraiin->fltmode, dataraiin->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, (const char *)dataraiin, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataRaiIn_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataraiin_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, const uint16_t *channels, float roll, float pitch, float yaw, float thr, uint16_t fltmode, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, pitch);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, thr);
    _mav_put_uint16_t(buf, 52, fltmode);
    _mav_put_uint8_t(buf, 54, alive);
    _mav_put_uint16_t_array(buf, 28, channels, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, buf, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#else
    mavlink_dataraiin_t *packet = (mavlink_dataraiin_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->thr = thr;
    packet->fltmode = fltmode;
    packet->alive = alive;
    mav_array_memcpy(packet->channels, channels, sizeof(uint16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataRaiIn, (const char *)packet, MAVLINK_MSG_ID_DataRaiIn_MIN_LEN, MAVLINK_MSG_ID_DataRaiIn_LEN, MAVLINK_MSG_ID_DataRaiIn_CRC);
#endif
}
#endif

#endif

// MESSAGE DataRaiIn UNPACKING


/**
 * @brief Get field time from dataraiin message
 *
 * @return  Time.
 */
static inline uint64_t mavlink_msg_dataraiin_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from dataraiin message
 *
 * @return  Sensetime.
 */
static inline float mavlink_msg_dataraiin_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field channels from dataraiin message
 *
 * @return  Channels.
 */
static inline uint16_t mavlink_msg_dataraiin_get_channels(const mavlink_message_t* msg, uint16_t *channels)
{
    return _MAV_RETURN_uint16_t_array(msg, channels, 12,  28);
}

/**
 * @brief Get field roll from dataraiin message
 *
 * @return  Setpoint ailleron.
 */
static inline float mavlink_msg_dataraiin_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field pitch from dataraiin message
 *
 * @return  Setpoint elevator.
 */
static inline float mavlink_msg_dataraiin_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field yaw from dataraiin message
 *
 * @return  Setpoint rudder.
 */
static inline float mavlink_msg_dataraiin_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field thr from dataraiin message
 *
 * @return  Setpoint thrust.
 */
static inline float mavlink_msg_dataraiin_get_thr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field fltmode from dataraiin message
 *
 * @return  Flightmode.
 */
static inline uint16_t mavlink_msg_dataraiin_get_fltmode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field alive from dataraiin message
 *
 * @return   Alive.
 */
static inline uint8_t mavlink_msg_dataraiin_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  54);
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
    dataraiin->roll = mavlink_msg_dataraiin_get_roll(msg);
    dataraiin->pitch = mavlink_msg_dataraiin_get_pitch(msg);
    dataraiin->yaw = mavlink_msg_dataraiin_get_yaw(msg);
    dataraiin->thr = mavlink_msg_dataraiin_get_thr(msg);
    mavlink_msg_dataraiin_get_channels(msg, dataraiin->channels);
    dataraiin->fltmode = mavlink_msg_dataraiin_get_fltmode(msg);
    dataraiin->alive = mavlink_msg_dataraiin_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataRaiIn_LEN? msg->len : MAVLINK_MSG_ID_DataRaiIn_LEN;
        memset(dataraiin, 0, MAVLINK_MSG_ID_DataRaiIn_LEN);
    memcpy(dataraiin, _MAV_PAYLOAD(msg), len);
#endif
}
