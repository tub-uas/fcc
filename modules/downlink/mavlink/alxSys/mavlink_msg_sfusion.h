#pragma once
// MESSAGE SFUSION PACKING

#define MAVLINK_MSG_ID_SFUSION 40000


typedef struct __mavlink_sfusion_t {
 int32_t timestamp; /*<  Timestamp.*/
} mavlink_sfusion_t;

#define MAVLINK_MSG_ID_SFUSION_LEN 4
#define MAVLINK_MSG_ID_SFUSION_MIN_LEN 4
#define MAVLINK_MSG_ID_40000_LEN 4
#define MAVLINK_MSG_ID_40000_MIN_LEN 4

#define MAVLINK_MSG_ID_SFUSION_CRC 229
#define MAVLINK_MSG_ID_40000_CRC 229



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SFUSION { \
    40000, \
    "SFUSION", \
    1, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sfusion_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SFUSION { \
    "SFUSION", \
    1, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sfusion_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a sfusion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sfusion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SFUSION_LEN];
    _mav_put_int32_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SFUSION_LEN);
#else
    mavlink_sfusion_t packet;
    packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SFUSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SFUSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
}

/**
 * @brief Pack a sfusion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sfusion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SFUSION_LEN];
    _mav_put_int32_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SFUSION_LEN);
#else
    mavlink_sfusion_t packet;
    packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SFUSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SFUSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
}

/**
 * @brief Encode a sfusion struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sfusion_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sfusion_t* sfusion)
{
    return mavlink_msg_sfusion_pack(system_id, component_id, msg, sfusion->timestamp);
}

/**
 * @brief Encode a sfusion struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sfusion_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sfusion_t* sfusion)
{
    return mavlink_msg_sfusion_pack_chan(system_id, component_id, chan, msg, sfusion->timestamp);
}

/**
 * @brief Send a sfusion message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sfusion_send(mavlink_channel_t chan, int32_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SFUSION_LEN];
    _mav_put_int32_t(buf, 0, timestamp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SFUSION, buf, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
#else
    mavlink_sfusion_t packet;
    packet.timestamp = timestamp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SFUSION, (const char *)&packet, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
#endif
}

/**
 * @brief Send a sfusion message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sfusion_send_struct(mavlink_channel_t chan, const mavlink_sfusion_t* sfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sfusion_send(chan, sfusion->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SFUSION, (const char *)sfusion, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SFUSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sfusion_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, timestamp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SFUSION, buf, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
#else
    mavlink_sfusion_t *packet = (mavlink_sfusion_t *)msgbuf;
    packet->timestamp = timestamp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SFUSION, (const char *)packet, MAVLINK_MSG_ID_SFUSION_MIN_LEN, MAVLINK_MSG_ID_SFUSION_LEN, MAVLINK_MSG_ID_SFUSION_CRC);
#endif
}
#endif

#endif

// MESSAGE SFUSION UNPACKING


/**
 * @brief Get field timestamp from sfusion message
 *
 * @return  Timestamp.
 */
static inline int32_t mavlink_msg_sfusion_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a sfusion message into a struct
 *
 * @param msg The message to decode
 * @param sfusion C-struct to decode the message contents into
 */
static inline void mavlink_msg_sfusion_decode(const mavlink_message_t* msg, mavlink_sfusion_t* sfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sfusion->timestamp = mavlink_msg_sfusion_get_timestamp(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SFUSION_LEN? msg->len : MAVLINK_MSG_ID_SFUSION_LEN;
        memset(sfusion, 0, MAVLINK_MSG_ID_SFUSION_LEN);
    memcpy(sfusion, _MAV_PAYLOAD(msg), len);
#endif
}
