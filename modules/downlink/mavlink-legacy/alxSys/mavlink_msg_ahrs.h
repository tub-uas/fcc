#pragma once
// MESSAGE AHRS PACKING

#define MAVLINK_MSG_ID_AHRS 20000


typedef struct __mavlink_ahrs_t {
 int32_t timestamp; /*<  Timestamp.*/
 float gX; /*<  gyro X-axis.*/
 float gY; /*<  gyro Y-axis.*/
 float gZ; /*<  gyro Z-axis.*/
 float aX; /*<  accl X-axis.*/
 float aY; /*<  accl Y-axis.*/
 float aZ; /*<  accl Z-axis.*/
 float mX; /*<  magn X-axis.*/
 float mY; /*<  magn Y-axis.*/
 float mZ; /*<  magn Z-axis.*/
 float Phi; /*<  Phi.*/
 float Tht; /*<  Theta.*/
 float Psi; /*<  Psi.*/
 uint8_t alive; /*<  AHRS alive.*/
} mavlink_ahrs_t;

#define MAVLINK_MSG_ID_AHRS_LEN 53
#define MAVLINK_MSG_ID_AHRS_MIN_LEN 53
#define MAVLINK_MSG_ID_20000_LEN 53
#define MAVLINK_MSG_ID_20000_MIN_LEN 53

#define MAVLINK_MSG_ID_AHRS_CRC 126
#define MAVLINK_MSG_ID_20000_CRC 126



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AHRS { \
    20000, \
    "AHRS", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_ahrs_t, timestamp) }, \
         { "gX", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ahrs_t, gX) }, \
         { "gY", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ahrs_t, gY) }, \
         { "gZ", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ahrs_t, gZ) }, \
         { "aX", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ahrs_t, aX) }, \
         { "aY", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ahrs_t, aY) }, \
         { "aZ", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ahrs_t, aZ) }, \
         { "mX", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ahrs_t, mX) }, \
         { "mY", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ahrs_t, mY) }, \
         { "mZ", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ahrs_t, mZ) }, \
         { "Phi", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ahrs_t, Phi) }, \
         { "Tht", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ahrs_t, Tht) }, \
         { "Psi", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ahrs_t, Psi) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_ahrs_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AHRS { \
    "AHRS", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_ahrs_t, timestamp) }, \
         { "gX", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ahrs_t, gX) }, \
         { "gY", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ahrs_t, gY) }, \
         { "gZ", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ahrs_t, gZ) }, \
         { "aX", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ahrs_t, aX) }, \
         { "aY", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ahrs_t, aY) }, \
         { "aZ", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ahrs_t, aZ) }, \
         { "mX", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ahrs_t, mX) }, \
         { "mY", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ahrs_t, mY) }, \
         { "mZ", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ahrs_t, mZ) }, \
         { "Phi", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ahrs_t, Phi) }, \
         { "Tht", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ahrs_t, Tht) }, \
         { "Psi", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ahrs_t, Psi) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_ahrs_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a ahrs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param Phi  Phi.
 * @param Tht  Theta.
 * @param Psi  Psi.
 * @param alive  AHRS alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t timestamp, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float Phi, float Tht, float Psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AHRS_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, gX);
    _mav_put_float(buf, 8, gY);
    _mav_put_float(buf, 12, gZ);
    _mav_put_float(buf, 16, aX);
    _mav_put_float(buf, 20, aY);
    _mav_put_float(buf, 24, aZ);
    _mav_put_float(buf, 28, mX);
    _mav_put_float(buf, 32, mY);
    _mav_put_float(buf, 36, mZ);
    _mav_put_float(buf, 40, Phi);
    _mav_put_float(buf, 44, Tht);
    _mav_put_float(buf, 48, Psi);
    _mav_put_uint8_t(buf, 52, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS_LEN);
#else
    mavlink_ahrs_t packet;
    packet.timestamp = timestamp;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.Phi = Phi;
    packet.Tht = Tht;
    packet.Psi = Psi;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AHRS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
}

/**
 * @brief Pack a ahrs message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param Phi  Phi.
 * @param Tht  Theta.
 * @param Psi  Psi.
 * @param alive  AHRS alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t timestamp,float gX,float gY,float gZ,float aX,float aY,float aZ,float mX,float mY,float mZ,float Phi,float Tht,float Psi,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AHRS_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, gX);
    _mav_put_float(buf, 8, gY);
    _mav_put_float(buf, 12, gZ);
    _mav_put_float(buf, 16, aX);
    _mav_put_float(buf, 20, aY);
    _mav_put_float(buf, 24, aZ);
    _mav_put_float(buf, 28, mX);
    _mav_put_float(buf, 32, mY);
    _mav_put_float(buf, 36, mZ);
    _mav_put_float(buf, 40, Phi);
    _mav_put_float(buf, 44, Tht);
    _mav_put_float(buf, 48, Psi);
    _mav_put_uint8_t(buf, 52, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS_LEN);
#else
    mavlink_ahrs_t packet;
    packet.timestamp = timestamp;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.Phi = Phi;
    packet.Tht = Tht;
    packet.Psi = Psi;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AHRS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
}

/**
 * @brief Encode a ahrs struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ahrs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ahrs_t* ahrs)
{
    return mavlink_msg_ahrs_pack(system_id, component_id, msg, ahrs->timestamp, ahrs->gX, ahrs->gY, ahrs->gZ, ahrs->aX, ahrs->aY, ahrs->aZ, ahrs->mX, ahrs->mY, ahrs->mZ, ahrs->Phi, ahrs->Tht, ahrs->Psi, ahrs->alive);
}

/**
 * @brief Encode a ahrs struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ahrs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ahrs_t* ahrs)
{
    return mavlink_msg_ahrs_pack_chan(system_id, component_id, chan, msg, ahrs->timestamp, ahrs->gX, ahrs->gY, ahrs->gZ, ahrs->aX, ahrs->aY, ahrs->aZ, ahrs->mX, ahrs->mY, ahrs->mZ, ahrs->Phi, ahrs->Tht, ahrs->Psi, ahrs->alive);
}

/**
 * @brief Send a ahrs message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param Phi  Phi.
 * @param Tht  Theta.
 * @param Psi  Psi.
 * @param alive  AHRS alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ahrs_send(mavlink_channel_t chan, int32_t timestamp, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float Phi, float Tht, float Psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AHRS_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, gX);
    _mav_put_float(buf, 8, gY);
    _mav_put_float(buf, 12, gZ);
    _mav_put_float(buf, 16, aX);
    _mav_put_float(buf, 20, aY);
    _mav_put_float(buf, 24, aZ);
    _mav_put_float(buf, 28, mX);
    _mav_put_float(buf, 32, mY);
    _mav_put_float(buf, 36, mZ);
    _mav_put_float(buf, 40, Phi);
    _mav_put_float(buf, 44, Tht);
    _mav_put_float(buf, 48, Psi);
    _mav_put_uint8_t(buf, 52, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS, buf, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
#else
    mavlink_ahrs_t packet;
    packet.timestamp = timestamp;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.Phi = Phi;
    packet.Tht = Tht;
    packet.Psi = Psi;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS, (const char *)&packet, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
#endif
}

/**
 * @brief Send a ahrs message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ahrs_send_struct(mavlink_channel_t chan, const mavlink_ahrs_t* ahrs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ahrs_send(chan, ahrs->timestamp, ahrs->gX, ahrs->gY, ahrs->gZ, ahrs->aX, ahrs->aY, ahrs->aZ, ahrs->mX, ahrs->mY, ahrs->mZ, ahrs->Phi, ahrs->Tht, ahrs->Psi, ahrs->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS, (const char *)ahrs, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
#endif
}

#if MAVLINK_MSG_ID_AHRS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ahrs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t timestamp, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float Phi, float Tht, float Psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, gX);
    _mav_put_float(buf, 8, gY);
    _mav_put_float(buf, 12, gZ);
    _mav_put_float(buf, 16, aX);
    _mav_put_float(buf, 20, aY);
    _mav_put_float(buf, 24, aZ);
    _mav_put_float(buf, 28, mX);
    _mav_put_float(buf, 32, mY);
    _mav_put_float(buf, 36, mZ);
    _mav_put_float(buf, 40, Phi);
    _mav_put_float(buf, 44, Tht);
    _mav_put_float(buf, 48, Psi);
    _mav_put_uint8_t(buf, 52, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS, buf, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
#else
    mavlink_ahrs_t *packet = (mavlink_ahrs_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->gX = gX;
    packet->gY = gY;
    packet->gZ = gZ;
    packet->aX = aX;
    packet->aY = aY;
    packet->aZ = aZ;
    packet->mX = mX;
    packet->mY = mY;
    packet->mZ = mZ;
    packet->Phi = Phi;
    packet->Tht = Tht;
    packet->Psi = Psi;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS, (const char *)packet, MAVLINK_MSG_ID_AHRS_MIN_LEN, MAVLINK_MSG_ID_AHRS_LEN, MAVLINK_MSG_ID_AHRS_CRC);
#endif
}
#endif

#endif

// MESSAGE AHRS UNPACKING


/**
 * @brief Get field timestamp from ahrs message
 *
 * @return  Timestamp.
 */
static inline int32_t mavlink_msg_ahrs_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field gX from ahrs message
 *
 * @return  gyro X-axis.
 */
static inline float mavlink_msg_ahrs_get_gX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field gY from ahrs message
 *
 * @return  gyro Y-axis.
 */
static inline float mavlink_msg_ahrs_get_gY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gZ from ahrs message
 *
 * @return  gyro Z-axis.
 */
static inline float mavlink_msg_ahrs_get_gZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field aX from ahrs message
 *
 * @return  accl X-axis.
 */
static inline float mavlink_msg_ahrs_get_aX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field aY from ahrs message
 *
 * @return  accl Y-axis.
 */
static inline float mavlink_msg_ahrs_get_aY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field aZ from ahrs message
 *
 * @return  accl Z-axis.
 */
static inline float mavlink_msg_ahrs_get_aZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field mX from ahrs message
 *
 * @return  magn X-axis.
 */
static inline float mavlink_msg_ahrs_get_mX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field mY from ahrs message
 *
 * @return  magn Y-axis.
 */
static inline float mavlink_msg_ahrs_get_mY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field mZ from ahrs message
 *
 * @return  magn Z-axis.
 */
static inline float mavlink_msg_ahrs_get_mZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field Phi from ahrs message
 *
 * @return  Phi.
 */
static inline float mavlink_msg_ahrs_get_Phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field Tht from ahrs message
 *
 * @return  Theta.
 */
static inline float mavlink_msg_ahrs_get_Tht(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field Psi from ahrs message
 *
 * @return  Psi.
 */
static inline float mavlink_msg_ahrs_get_Psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field alive from ahrs message
 *
 * @return  AHRS alive.
 */
static inline uint8_t mavlink_msg_ahrs_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Decode a ahrs message into a struct
 *
 * @param msg The message to decode
 * @param ahrs C-struct to decode the message contents into
 */
static inline void mavlink_msg_ahrs_decode(const mavlink_message_t* msg, mavlink_ahrs_t* ahrs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ahrs->timestamp = mavlink_msg_ahrs_get_timestamp(msg);
    ahrs->gX = mavlink_msg_ahrs_get_gX(msg);
    ahrs->gY = mavlink_msg_ahrs_get_gY(msg);
    ahrs->gZ = mavlink_msg_ahrs_get_gZ(msg);
    ahrs->aX = mavlink_msg_ahrs_get_aX(msg);
    ahrs->aY = mavlink_msg_ahrs_get_aY(msg);
    ahrs->aZ = mavlink_msg_ahrs_get_aZ(msg);
    ahrs->mX = mavlink_msg_ahrs_get_mX(msg);
    ahrs->mY = mavlink_msg_ahrs_get_mY(msg);
    ahrs->mZ = mavlink_msg_ahrs_get_mZ(msg);
    ahrs->Phi = mavlink_msg_ahrs_get_Phi(msg);
    ahrs->Tht = mavlink_msg_ahrs_get_Tht(msg);
    ahrs->Psi = mavlink_msg_ahrs_get_Psi(msg);
    ahrs->alive = mavlink_msg_ahrs_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AHRS_LEN? msg->len : MAVLINK_MSG_ID_AHRS_LEN;
        memset(ahrs, 0, MAVLINK_MSG_ID_AHRS_LEN);
    memcpy(ahrs, _MAV_PAYLOAD(msg), len);
#endif
}
