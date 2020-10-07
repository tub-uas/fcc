#pragma once
// MESSAGE DataCtrl PACKING

#define MAVLINK_MSG_ID_DataCtrl 50000


typedef struct __mavlink_datactrl_t {
 uint64_t time; /*<  System time at publication*/
 float xi; /*<  Roll (Aileron)*/
 float eta; /*<  Pich (Elevator)*/
 float zeta; /*<  Yaw (Rudder)*/
 float etaT; /*<  Thrust (Throttle)*/
 float etaF; /*<  Flaps*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_datactrl_t;

#define MAVLINK_MSG_ID_DataCtrl_LEN 29
#define MAVLINK_MSG_ID_DataCtrl_MIN_LEN 29
#define MAVLINK_MSG_ID_50000_LEN 29
#define MAVLINK_MSG_ID_50000_MIN_LEN 29

#define MAVLINK_MSG_ID_DataCtrl_CRC 128
#define MAVLINK_MSG_ID_50000_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataCtrl { \
    50000, \
    "DataCtrl", \
    7, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datactrl_t, time) }, \
         { "xi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datactrl_t, xi) }, \
         { "eta", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datactrl_t, eta) }, \
         { "zeta", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datactrl_t, zeta) }, \
         { "etaT", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datactrl_t, etaT) }, \
         { "etaF", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datactrl_t, etaF) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_datactrl_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataCtrl { \
    "DataCtrl", \
    7, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datactrl_t, time) }, \
         { "xi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datactrl_t, xi) }, \
         { "eta", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datactrl_t, eta) }, \
         { "zeta", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datactrl_t, zeta) }, \
         { "etaT", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datactrl_t, etaT) }, \
         { "etaF", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datactrl_t, etaF) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_datactrl_t, alive) }, \
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
 * @param xi  Roll (Aileron)
 * @param eta  Pich (Elevator)
 * @param zeta  Yaw (Rudder)
 * @param etaT  Thrust (Throttle)
 * @param etaF  Flaps
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datactrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float xi, float eta, float zeta, float etaT, float etaF, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi);
    _mav_put_float(buf, 12, eta);
    _mav_put_float(buf, 16, zeta);
    _mav_put_float(buf, 20, etaT);
    _mav_put_float(buf, 24, etaF);
    _mav_put_uint8_t(buf, 28, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataCtrl_LEN);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
    packet.xi = xi;
    packet.eta = eta;
    packet.zeta = zeta;
    packet.etaT = etaT;
    packet.etaF = etaF;
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
 * @param xi  Roll (Aileron)
 * @param eta  Pich (Elevator)
 * @param zeta  Yaw (Rudder)
 * @param etaT  Thrust (Throttle)
 * @param etaF  Flaps
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datactrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float xi,float eta,float zeta,float etaT,float etaF,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi);
    _mav_put_float(buf, 12, eta);
    _mav_put_float(buf, 16, zeta);
    _mav_put_float(buf, 20, etaT);
    _mav_put_float(buf, 24, etaF);
    _mav_put_uint8_t(buf, 28, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataCtrl_LEN);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
    packet.xi = xi;
    packet.eta = eta;
    packet.zeta = zeta;
    packet.etaT = etaT;
    packet.etaF = etaF;
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
    return mavlink_msg_datactrl_pack(system_id, component_id, msg, datactrl->time, datactrl->xi, datactrl->eta, datactrl->zeta, datactrl->etaT, datactrl->etaF, datactrl->alive);
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
    return mavlink_msg_datactrl_pack_chan(system_id, component_id, chan, msg, datactrl->time, datactrl->xi, datactrl->eta, datactrl->zeta, datactrl->etaT, datactrl->etaF, datactrl->alive);
}

/**
 * @brief Send a datactrl message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param xi  Roll (Aileron)
 * @param eta  Pich (Elevator)
 * @param zeta  Yaw (Rudder)
 * @param etaT  Thrust (Throttle)
 * @param etaF  Flaps
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datactrl_send(mavlink_channel_t chan, uint64_t time, float xi, float eta, float zeta, float etaT, float etaF, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataCtrl_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi);
    _mav_put_float(buf, 12, eta);
    _mav_put_float(buf, 16, zeta);
    _mav_put_float(buf, 20, etaT);
    _mav_put_float(buf, 24, etaF);
    _mav_put_uint8_t(buf, 28, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, buf, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#else
    mavlink_datactrl_t packet;
    packet.time = time;
    packet.xi = xi;
    packet.eta = eta;
    packet.zeta = zeta;
    packet.etaT = etaT;
    packet.etaF = etaF;
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
    mavlink_msg_datactrl_send(chan, datactrl->time, datactrl->xi, datactrl->eta, datactrl->zeta, datactrl->etaT, datactrl->etaF, datactrl->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, (const char *)datactrl, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataCtrl_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datactrl_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float xi, float eta, float zeta, float etaT, float etaF, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, xi);
    _mav_put_float(buf, 12, eta);
    _mav_put_float(buf, 16, zeta);
    _mav_put_float(buf, 20, etaT);
    _mav_put_float(buf, 24, etaF);
    _mav_put_uint8_t(buf, 28, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataCtrl, buf, MAVLINK_MSG_ID_DataCtrl_MIN_LEN, MAVLINK_MSG_ID_DataCtrl_LEN, MAVLINK_MSG_ID_DataCtrl_CRC);
#else
    mavlink_datactrl_t *packet = (mavlink_datactrl_t *)msgbuf;
    packet->time = time;
    packet->xi = xi;
    packet->eta = eta;
    packet->zeta = zeta;
    packet->etaT = etaT;
    packet->etaF = etaF;
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
 * @brief Get field xi from datactrl message
 *
 * @return  Roll (Aileron)
 */
static inline float mavlink_msg_datactrl_get_xi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field eta from datactrl message
 *
 * @return  Pich (Elevator)
 */
static inline float mavlink_msg_datactrl_get_eta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zeta from datactrl message
 *
 * @return  Yaw (Rudder)
 */
static inline float mavlink_msg_datactrl_get_zeta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field etaT from datactrl message
 *
 * @return  Thrust (Throttle)
 */
static inline float mavlink_msg_datactrl_get_etaT(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field etaF from datactrl message
 *
 * @return  Flaps
 */
static inline float mavlink_msg_datactrl_get_etaF(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field alive from datactrl message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_datactrl_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
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
    datactrl->xi = mavlink_msg_datactrl_get_xi(msg);
    datactrl->eta = mavlink_msg_datactrl_get_eta(msg);
    datactrl->zeta = mavlink_msg_datactrl_get_zeta(msg);
    datactrl->etaT = mavlink_msg_datactrl_get_etaT(msg);
    datactrl->etaF = mavlink_msg_datactrl_get_etaF(msg);
    datactrl->alive = mavlink_msg_datactrl_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataCtrl_LEN? msg->len : MAVLINK_MSG_ID_DataCtrl_LEN;
        memset(datactrl, 0, MAVLINK_MSG_ID_DataCtrl_LEN);
    memcpy(datactrl, _MAV_PAYLOAD(msg), len);
#endif
}
