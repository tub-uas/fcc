#pragma once
// MESSAGE RC2SOUT PACKING

#define MAVLINK_MSG_ID_RC2SOUT 15000


typedef struct __mavlink_rc2sout_t {
 float out_aill; /*<  Output ailleron.*/
 float out_elev; /*<  Output elevator.*/
 float out_rudd; /*<  Output rudder.*/
 float out_thrt; /*<  Output thrust.*/
 int16_t control_law; /*<  Active control law.*/
} mavlink_rc2sout_t;

#define MAVLINK_MSG_ID_RC2SOUT_LEN 18
#define MAVLINK_MSG_ID_RC2SOUT_MIN_LEN 18
#define MAVLINK_MSG_ID_15000_LEN 18
#define MAVLINK_MSG_ID_15000_MIN_LEN 18

#define MAVLINK_MSG_ID_RC2SOUT_CRC 202
#define MAVLINK_MSG_ID_15000_CRC 202



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RC2SOUT { \
    15000, \
    "RC2SOUT", \
    5, \
    {  { "out_aill", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc2sout_t, out_aill) }, \
         { "out_elev", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rc2sout_t, out_elev) }, \
         { "out_rudd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rc2sout_t, out_rudd) }, \
         { "out_thrt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rc2sout_t, out_thrt) }, \
         { "control_law", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_rc2sout_t, control_law) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RC2SOUT { \
    "RC2SOUT", \
    5, \
    {  { "out_aill", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc2sout_t, out_aill) }, \
         { "out_elev", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rc2sout_t, out_elev) }, \
         { "out_rudd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rc2sout_t, out_rudd) }, \
         { "out_thrt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rc2sout_t, out_thrt) }, \
         { "control_law", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_rc2sout_t, control_law) }, \
         } \
}
#endif

/**
 * @brief Pack a rc2sout message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param out_aill  Output ailleron.
 * @param out_elev  Output elevator.
 * @param out_rudd  Output rudder.
 * @param out_thrt  Output thrust.
 * @param control_law  Active control law.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc2sout_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float out_aill, float out_elev, float out_rudd, float out_thrt, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SOUT_LEN];
    _mav_put_float(buf, 0, out_aill);
    _mav_put_float(buf, 4, out_elev);
    _mav_put_float(buf, 8, out_rudd);
    _mav_put_float(buf, 12, out_thrt);
    _mav_put_int16_t(buf, 16, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC2SOUT_LEN);
#else
    mavlink_rc2sout_t packet;
    packet.out_aill = out_aill;
    packet.out_elev = out_elev;
    packet.out_rudd = out_rudd;
    packet.out_thrt = out_thrt;
    packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC2SOUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC2SOUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
}

/**
 * @brief Pack a rc2sout message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param out_aill  Output ailleron.
 * @param out_elev  Output elevator.
 * @param out_rudd  Output rudder.
 * @param out_thrt  Output thrust.
 * @param control_law  Active control law.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc2sout_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float out_aill,float out_elev,float out_rudd,float out_thrt,int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SOUT_LEN];
    _mav_put_float(buf, 0, out_aill);
    _mav_put_float(buf, 4, out_elev);
    _mav_put_float(buf, 8, out_rudd);
    _mav_put_float(buf, 12, out_thrt);
    _mav_put_int16_t(buf, 16, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC2SOUT_LEN);
#else
    mavlink_rc2sout_t packet;
    packet.out_aill = out_aill;
    packet.out_elev = out_elev;
    packet.out_rudd = out_rudd;
    packet.out_thrt = out_thrt;
    packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC2SOUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC2SOUT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
}

/**
 * @brief Encode a rc2sout struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc2sout C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc2sout_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc2sout_t* rc2sout)
{
    return mavlink_msg_rc2sout_pack(system_id, component_id, msg, rc2sout->out_aill, rc2sout->out_elev, rc2sout->out_rudd, rc2sout->out_thrt, rc2sout->control_law);
}

/**
 * @brief Encode a rc2sout struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rc2sout C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc2sout_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rc2sout_t* rc2sout)
{
    return mavlink_msg_rc2sout_pack_chan(system_id, component_id, chan, msg, rc2sout->out_aill, rc2sout->out_elev, rc2sout->out_rudd, rc2sout->out_thrt, rc2sout->control_law);
}

/**
 * @brief Send a rc2sout message
 * @param chan MAVLink channel to send the message
 *
 * @param out_aill  Output ailleron.
 * @param out_elev  Output elevator.
 * @param out_rudd  Output rudder.
 * @param out_thrt  Output thrust.
 * @param control_law  Active control law.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rc2sout_send(mavlink_channel_t chan, float out_aill, float out_elev, float out_rudd, float out_thrt, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC2SOUT_LEN];
    _mav_put_float(buf, 0, out_aill);
    _mav_put_float(buf, 4, out_elev);
    _mav_put_float(buf, 8, out_rudd);
    _mav_put_float(buf, 12, out_thrt);
    _mav_put_int16_t(buf, 16, control_law);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SOUT, buf, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
#else
    mavlink_rc2sout_t packet;
    packet.out_aill = out_aill;
    packet.out_elev = out_elev;
    packet.out_rudd = out_rudd;
    packet.out_thrt = out_thrt;
    packet.control_law = control_law;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SOUT, (const char *)&packet, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
#endif
}

/**
 * @brief Send a rc2sout message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rc2sout_send_struct(mavlink_channel_t chan, const mavlink_rc2sout_t* rc2sout)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rc2sout_send(chan, rc2sout->out_aill, rc2sout->out_elev, rc2sout->out_rudd, rc2sout->out_thrt, rc2sout->control_law);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SOUT, (const char *)rc2sout, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_RC2SOUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rc2sout_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float out_aill, float out_elev, float out_rudd, float out_thrt, int16_t control_law)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, out_aill);
    _mav_put_float(buf, 4, out_elev);
    _mav_put_float(buf, 8, out_rudd);
    _mav_put_float(buf, 12, out_thrt);
    _mav_put_int16_t(buf, 16, control_law);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SOUT, buf, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
#else
    mavlink_rc2sout_t *packet = (mavlink_rc2sout_t *)msgbuf;
    packet->out_aill = out_aill;
    packet->out_elev = out_elev;
    packet->out_rudd = out_rudd;
    packet->out_thrt = out_thrt;
    packet->control_law = control_law;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC2SOUT, (const char *)packet, MAVLINK_MSG_ID_RC2SOUT_MIN_LEN, MAVLINK_MSG_ID_RC2SOUT_LEN, MAVLINK_MSG_ID_RC2SOUT_CRC);
#endif
}
#endif

#endif

// MESSAGE RC2SOUT UNPACKING


/**
 * @brief Get field out_aill from rc2sout message
 *
 * @return  Output ailleron.
 */
static inline float mavlink_msg_rc2sout_get_out_aill(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field out_elev from rc2sout message
 *
 * @return  Output elevator.
 */
static inline float mavlink_msg_rc2sout_get_out_elev(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field out_rudd from rc2sout message
 *
 * @return  Output rudder.
 */
static inline float mavlink_msg_rc2sout_get_out_rudd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field out_thrt from rc2sout message
 *
 * @return  Output thrust.
 */
static inline float mavlink_msg_rc2sout_get_out_thrt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field control_law from rc2sout message
 *
 * @return  Active control law.
 */
static inline int16_t mavlink_msg_rc2sout_get_control_law(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a rc2sout message into a struct
 *
 * @param msg The message to decode
 * @param rc2sout C-struct to decode the message contents into
 */
static inline void mavlink_msg_rc2sout_decode(const mavlink_message_t* msg, mavlink_rc2sout_t* rc2sout)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rc2sout->out_aill = mavlink_msg_rc2sout_get_out_aill(msg);
    rc2sout->out_elev = mavlink_msg_rc2sout_get_out_elev(msg);
    rc2sout->out_rudd = mavlink_msg_rc2sout_get_out_rudd(msg);
    rc2sout->out_thrt = mavlink_msg_rc2sout_get_out_thrt(msg);
    rc2sout->control_law = mavlink_msg_rc2sout_get_control_law(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RC2SOUT_LEN? msg->len : MAVLINK_MSG_ID_RC2SOUT_LEN;
        memset(rc2sout, 0, MAVLINK_MSG_ID_RC2SOUT_LEN);
    memcpy(rc2sout, _MAV_PAYLOAD(msg), len);
#endif
}
