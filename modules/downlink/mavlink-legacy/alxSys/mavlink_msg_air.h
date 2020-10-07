#pragma once
// MESSAGE AIR PACKING

#define MAVLINK_MSG_ID_AIR 30000


typedef struct __mavlink_air_t {
 int32_t timestamp; /*<  Timestamp.*/
 float aspd; /*<  airspeed.*/
 float altb; /*<  altitude baro.*/
 uint8_t alive; /*<  AIR alive.*/
} mavlink_air_t;

#define MAVLINK_MSG_ID_AIR_LEN 13
#define MAVLINK_MSG_ID_AIR_MIN_LEN 13
#define MAVLINK_MSG_ID_30000_LEN 13
#define MAVLINK_MSG_ID_30000_MIN_LEN 13

#define MAVLINK_MSG_ID_AIR_CRC 56
#define MAVLINK_MSG_ID_30000_CRC 56



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AIR { \
    30000, \
    "AIR", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_air_t, timestamp) }, \
         { "aspd", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_air_t, aspd) }, \
         { "altb", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_air_t, altb) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_air_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AIR { \
    "AIR", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_air_t, timestamp) }, \
         { "aspd", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_air_t, aspd) }, \
         { "altb", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_air_t, altb) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_air_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a air message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp.
 * @param aspd  airspeed.
 * @param altb  altitude baro.
 * @param alive  AIR alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_air_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t timestamp, float aspd, float altb, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, aspd);
    _mav_put_float(buf, 8, altb);
    _mav_put_uint8_t(buf, 12, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIR_LEN);
#else
    mavlink_air_t packet;
    packet.timestamp = timestamp;
    packet.aspd = aspd;
    packet.altb = altb;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
}

/**
 * @brief Pack a air message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp.
 * @param aspd  airspeed.
 * @param altb  altitude baro.
 * @param alive  AIR alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_air_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t timestamp,float aspd,float altb,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, aspd);
    _mav_put_float(buf, 8, altb);
    _mav_put_uint8_t(buf, 12, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIR_LEN);
#else
    mavlink_air_t packet;
    packet.timestamp = timestamp;
    packet.aspd = aspd;
    packet.altb = altb;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
}

/**
 * @brief Encode a air struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param air C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_air_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_air_t* air)
{
    return mavlink_msg_air_pack(system_id, component_id, msg, air->timestamp, air->aspd, air->altb, air->alive);
}

/**
 * @brief Encode a air struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param air C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_air_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_air_t* air)
{
    return mavlink_msg_air_pack_chan(system_id, component_id, chan, msg, air->timestamp, air->aspd, air->altb, air->alive);
}

/**
 * @brief Send a air message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp.
 * @param aspd  airspeed.
 * @param altb  altitude baro.
 * @param alive  AIR alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_air_send(mavlink_channel_t chan, int32_t timestamp, float aspd, float altb, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, aspd);
    _mav_put_float(buf, 8, altb);
    _mav_put_uint8_t(buf, 12, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR, buf, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
#else
    mavlink_air_t packet;
    packet.timestamp = timestamp;
    packet.aspd = aspd;
    packet.altb = altb;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR, (const char *)&packet, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
#endif
}

/**
 * @brief Send a air message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_air_send_struct(mavlink_channel_t chan, const mavlink_air_t* air)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_air_send(chan, air->timestamp, air->aspd, air->altb, air->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR, (const char *)air, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
#endif
}

#if MAVLINK_MSG_ID_AIR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_air_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t timestamp, float aspd, float altb, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, aspd);
    _mav_put_float(buf, 8, altb);
    _mav_put_uint8_t(buf, 12, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR, buf, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
#else
    mavlink_air_t *packet = (mavlink_air_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->aspd = aspd;
    packet->altb = altb;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR, (const char *)packet, MAVLINK_MSG_ID_AIR_MIN_LEN, MAVLINK_MSG_ID_AIR_LEN, MAVLINK_MSG_ID_AIR_CRC);
#endif
}
#endif

#endif

// MESSAGE AIR UNPACKING


/**
 * @brief Get field timestamp from air message
 *
 * @return  Timestamp.
 */
static inline int32_t mavlink_msg_air_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field aspd from air message
 *
 * @return  airspeed.
 */
static inline float mavlink_msg_air_get_aspd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field altb from air message
 *
 * @return  altitude baro.
 */
static inline float mavlink_msg_air_get_altb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field alive from air message
 *
 * @return  AIR alive.
 */
static inline uint8_t mavlink_msg_air_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a air message into a struct
 *
 * @param msg The message to decode
 * @param air C-struct to decode the message contents into
 */
static inline void mavlink_msg_air_decode(const mavlink_message_t* msg, mavlink_air_t* air)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    air->timestamp = mavlink_msg_air_get_timestamp(msg);
    air->aspd = mavlink_msg_air_get_aspd(msg);
    air->altb = mavlink_msg_air_get_altb(msg);
    air->alive = mavlink_msg_air_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AIR_LEN? msg->len : MAVLINK_MSG_ID_AIR_LEN;
        memset(air, 0, MAVLINK_MSG_ID_AIR_LEN);
    memcpy(air, _MAV_PAYLOAD(msg), len);
#endif
}
