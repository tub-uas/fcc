#pragma once
// MESSAGE RC2SPUBLISHER PACKING

#define MAVLINK_MSG_ID_RC2SPUBLISHER 8811


typedef struct __mavlink_rc2spublisher_t {
 float setPoint_aill; /*<  Setpoint ailleron.*/
 float setPoint_elev; /*<  Setpoint elevator.*/
 int16_t control_law; /*<  Active control law.*/
} mavlink_rc2spublisher_t;

#define MAVLINK_MSG_ID_RC2SPUBLISHER_LEN 10
#define MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN 10
#define MAVLINK_MSG_ID_8811_LEN 10
#define MAVLINK_MSG_ID_8811_MIN_LEN 10

#define MAVLINK_MSG_ID_RC2SPUBLISHER_CRC 215
#define MAVLINK_MSG_ID_8811_CRC 215



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RC2SPUBLISHER { \
    8811, \
    "RC2SPUBLISHER", \
    3, \
    {  { "setPoint_aill", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc2spublisher_t, setPoint_aill) }, \
         { "setPoint_elev", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rc2spublisher_t, setPoint_elev) }, \
         { "control_law", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_rc2spublisher_t, control_law) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RC2SPUBLISHER { \
    "RC2SPUBLISHER", \
    3, \
    {  { "setPoint_aill", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc2spublisher_t, setPoint_aill) }, \
         { "setPoint_elev", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rc2spublisher_t, setPoint_elev) }, \
         { "control_law", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_rc2spublisher_t, control_law) }, \
         } \
}
#endif

/**
 * @brief Pack a rc2spublisher message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param setPoint_aill  Setpoint ailleron.
 * @param setPoint_elev  Setpoint elevator.
 * @param control_law  Active control law.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc2spublisher_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float setPoint_aill, float setPoint_elev, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SPUBLISHER_LEN];
    _mav_put_float(buf, 0, setPoint_aill);
    _mav_put_float(buf, 4, setPoint_elev);
    _mav_put_int16_t(buf, 8, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN);
#else
    mavlink_rc2spublisher_t packet;
    packet.setPoint_aill = setPoint_aill;
    packet.setPoint_elev = setPoint_elev;
    packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC2SPUBLISHER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
}

/**
 * @brief Pack a rc2spublisher message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setPoint_aill  Setpoint ailleron.
 * @param setPoint_elev  Setpoint elevator.
 * @param control_law  Active control law.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc2spublisher_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float setPoint_aill,float setPoint_elev,int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SPUBLISHER_LEN];
    _mav_put_float(buf, 0, setPoint_aill);
    _mav_put_float(buf, 4, setPoint_elev);
    _mav_put_int16_t(buf, 8, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN);
#else
    mavlink_rc2spublisher_t packet;
    packet.setPoint_aill = setPoint_aill;
    packet.setPoint_elev = setPoint_elev;
    packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC2SPUBLISHER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
}

/**
 * @brief Encode a rc2spublisher struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc2spublisher C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc2spublisher_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc2spublisher_t* rc2spublisher)
{
    return mavlink_msg_rc2spublisher_pack(system_id, component_id, msg, rc2spublisher->setPoint_aill, rc2spublisher->setPoint_elev, rc2spublisher->control_law);
}

/**
 * @brief Encode a rc2spublisher struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rc2spublisher C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc2spublisher_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rc2spublisher_t* rc2spublisher)
{
    return mavlink_msg_rc2spublisher_pack_chan(system_id, component_id, chan, msg, rc2spublisher->setPoint_aill, rc2spublisher->setPoint_elev, rc2spublisher->control_law);
}

/**
 * @brief Send a rc2spublisher message
 * @param chan MAVLink channel to send the message
 *
 * @param setPoint_aill  Setpoint ailleron.
 * @param setPoint_elev  Setpoint elevator.
 * @param control_law  Active control law.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rc2spublisher_send(mavlink_channel_t chan, float setPoint_aill, float setPoint_elev, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SPUBLISHER_LEN];
    _mav_put_float(buf, 0, setPoint_aill);
    _mav_put_float(buf, 4, setPoint_elev);
    _mav_put_int16_t(buf, 8, control_law);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SPUBLISHER, buf, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
#else
    mavlink_rc2spublisher_t packet;
    packet.setPoint_aill = setPoint_aill;
    packet.setPoint_elev = setPoint_elev;
    packet.control_law = control_law;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SPUBLISHER, (const char *)&packet, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
#endif
}

/**
 * @brief Send a rc2spublisher message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rc2spublisher_send_struct(mavlink_channel_t chan, const mavlink_rc2spublisher_t* rc2spublisher)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rc2spublisher_send(chan, rc2spublisher->setPoint_aill, rc2spublisher->setPoint_elev, rc2spublisher->control_law);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SPUBLISHER, (const char *)rc2spublisher, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
#endif
}

#if MAVLINK_MSG_ID_RC2SPUBLISHER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rc2spublisher_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float setPoint_aill, float setPoint_elev, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, setPoint_aill);
    _mav_put_float(buf, 4, setPoint_elev);
    _mav_put_int16_t(buf, 8, control_law);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SPUBLISHER, buf, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
#else
    mavlink_rc2spublisher_t *packet = (mavlink_rc2spublisher_t *)msgbuf;
    packet->setPoint_aill = setPoint_aill;
    packet->setPoint_elev = setPoint_elev;
    packet->control_law = control_law;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SPUBLISHER, (const char *)packet, MAVLINK_MSG_ID_RC2SPUBLISHER_MIN_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN, MAVLINK_MSG_ID_RC2SPUBLISHER_CRC);
#endif
}
#endif

#endif

// MESSAGE RC2SPUBLISHER UNPACKING


/**
 * @brief Get field setPoint_aill from rc2spublisher message
 *
 * @return  Setpoint ailleron.
 */
static inline float mavlink_msg_rc2spublisher_get_setPoint_aill(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field setPoint_elev from rc2spublisher message
 *
 * @return  Setpoint elevator.
 */
static inline float mavlink_msg_rc2spublisher_get_setPoint_elev(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field control_law from rc2spublisher message
 *
 * @return  Active control law.
 */
static inline int16_t mavlink_msg_rc2spublisher_get_control_law(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a rc2spublisher message into a struct
 *
 * @param msg The message to decode
 * @param rc2spublisher C-struct to decode the message contents into
 */
static inline void mavlink_msg_rc2spublisher_decode(const mavlink_message_t* msg, mavlink_rc2spublisher_t* rc2spublisher)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rc2spublisher->setPoint_aill = mavlink_msg_rc2spublisher_get_setPoint_aill(msg);
    rc2spublisher->setPoint_elev = mavlink_msg_rc2spublisher_get_setPoint_elev(msg);
    rc2spublisher->control_law = mavlink_msg_rc2spublisher_get_control_law(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RC2SPUBLISHER_LEN? msg->len : MAVLINK_MSG_ID_RC2SPUBLISHER_LEN;
        memset(rc2spublisher, 0, MAVLINK_MSG_ID_RC2SPUBLISHER_LEN);
    memcpy(rc2spublisher, _MAV_PAYLOAD(msg), len);
#endif
}
