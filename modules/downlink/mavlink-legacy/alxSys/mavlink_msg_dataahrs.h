#pragma once
// MESSAGE DataAhrs PACKING

#define MAVLINK_MSG_ID_DataAhrs 20000


typedef struct __mavlink_dataahrs_t {
 uint64_t time; /*<  Time.*/
 float senseTime; /*<  Sensetime.*/
 float gX; /*<  gyro X-axis.*/
 float gY; /*<  gyro Y-axis.*/
 float gZ; /*<  gyro Z-axis.*/
 float aX; /*<  accl X-axis.*/
 float aY; /*<  accl Y-axis.*/
 float aZ; /*<  accl Z-axis.*/
 float mX; /*<  magn X-axis.*/
 float mY; /*<  magn Y-axis.*/
 float mZ; /*<  magn Z-axis.*/
 float temp; /*<  Temperature.*/
 float baro_ahrs; /*<  Barometric pressure ahrs.*/
 float phi; /*<  Phi.*/
 float the; /*<  Theta.*/
 float psi; /*<  Psi.*/
 float q0; /*<  q0.*/
 float q1; /*<  q1.*/
 float q2; /*<  q2.*/
 float q3; /*<  q3.*/
 uint8_t alive; /*<  Alive.*/
} mavlink_dataahrs_t;

#define MAVLINK_MSG_ID_DataAhrs_LEN 85
#define MAVLINK_MSG_ID_DataAhrs_MIN_LEN 85
#define MAVLINK_MSG_ID_20000_LEN 85
#define MAVLINK_MSG_ID_20000_MIN_LEN 85

#define MAVLINK_MSG_ID_DataAhrs_CRC 106
#define MAVLINK_MSG_ID_20000_CRC 106



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataAhrs { \
    20000, \
    "DataAhrs", \
    21, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataahrs_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataahrs_t, senseTime) }, \
         { "gX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataahrs_t, gX) }, \
         { "gY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataahrs_t, gY) }, \
         { "gZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataahrs_t, gZ) }, \
         { "aX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataahrs_t, aX) }, \
         { "aY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataahrs_t, aY) }, \
         { "aZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataahrs_t, aZ) }, \
         { "mX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataahrs_t, mX) }, \
         { "mY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataahrs_t, mY) }, \
         { "mZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataahrs_t, mZ) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataahrs_t, temp) }, \
         { "baro_ahrs", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataahrs_t, baro_ahrs) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataahrs_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataahrs_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataahrs_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dataahrs_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_dataahrs_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_dataahrs_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_dataahrs_t, q3) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_dataahrs_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataAhrs { \
    "DataAhrs", \
    21, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataahrs_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataahrs_t, senseTime) }, \
         { "gX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataahrs_t, gX) }, \
         { "gY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataahrs_t, gY) }, \
         { "gZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataahrs_t, gZ) }, \
         { "aX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataahrs_t, aX) }, \
         { "aY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataahrs_t, aY) }, \
         { "aZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataahrs_t, aZ) }, \
         { "mX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataahrs_t, mX) }, \
         { "mY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataahrs_t, mY) }, \
         { "mZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataahrs_t, mZ) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataahrs_t, temp) }, \
         { "baro_ahrs", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataahrs_t, baro_ahrs) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataahrs_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataahrs_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataahrs_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dataahrs_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_dataahrs_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_dataahrs_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_dataahrs_t, q3) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_dataahrs_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataahrs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param temp  Temperature.
 * @param baro_ahrs  Barometric pressure ahrs.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param alive  Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataahrs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float temp, float baro_ahrs, float phi, float the, float psi, float q0, float q1, float q2, float q3, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gX);
    _mav_put_float(buf, 16, gY);
    _mav_put_float(buf, 20, gZ);
    _mav_put_float(buf, 24, aX);
    _mav_put_float(buf, 28, aY);
    _mav_put_float(buf, 32, aZ);
    _mav_put_float(buf, 36, mX);
    _mav_put_float(buf, 40, mY);
    _mav_put_float(buf, 44, mZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, baro_ahrs);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_uint8_t(buf, 84, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAhrs_LEN);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.temp = temp;
    packet.baro_ahrs = baro_ahrs;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataAhrs_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataAhrs;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
}

/**
 * @brief Pack a dataahrs message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param temp  Temperature.
 * @param baro_ahrs  Barometric pressure ahrs.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param alive  Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataahrs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float gX,float gY,float gZ,float aX,float aY,float aZ,float mX,float mY,float mZ,float temp,float baro_ahrs,float phi,float the,float psi,float q0,float q1,float q2,float q3,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gX);
    _mav_put_float(buf, 16, gY);
    _mav_put_float(buf, 20, gZ);
    _mav_put_float(buf, 24, aX);
    _mav_put_float(buf, 28, aY);
    _mav_put_float(buf, 32, aZ);
    _mav_put_float(buf, 36, mX);
    _mav_put_float(buf, 40, mY);
    _mav_put_float(buf, 44, mZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, baro_ahrs);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_uint8_t(buf, 84, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAhrs_LEN);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.temp = temp;
    packet.baro_ahrs = baro_ahrs;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataAhrs_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataAhrs;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
}

/**
 * @brief Encode a dataahrs struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dataahrs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataahrs_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dataahrs_t* dataahrs)
{
    return mavlink_msg_dataahrs_pack(system_id, component_id, msg, dataahrs->time, dataahrs->senseTime, dataahrs->gX, dataahrs->gY, dataahrs->gZ, dataahrs->aX, dataahrs->aY, dataahrs->aZ, dataahrs->mX, dataahrs->mY, dataahrs->mZ, dataahrs->temp, dataahrs->baro_ahrs, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->q0, dataahrs->q1, dataahrs->q2, dataahrs->q3, dataahrs->alive);
}

/**
 * @brief Encode a dataahrs struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dataahrs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataahrs_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dataahrs_t* dataahrs)
{
    return mavlink_msg_dataahrs_pack_chan(system_id, component_id, chan, msg, dataahrs->time, dataahrs->senseTime, dataahrs->gX, dataahrs->gY, dataahrs->gZ, dataahrs->aX, dataahrs->aY, dataahrs->aZ, dataahrs->mX, dataahrs->mY, dataahrs->mZ, dataahrs->temp, dataahrs->baro_ahrs, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->q0, dataahrs->q1, dataahrs->q2, dataahrs->q3, dataahrs->alive);
}

/**
 * @brief Send a dataahrs message
 * @param chan MAVLink channel to send the message
 *
 * @param time  Time.
 * @param senseTime  Sensetime.
 * @param gX  gyro X-axis.
 * @param gY  gyro Y-axis.
 * @param gZ  gyro Z-axis.
 * @param aX  accl X-axis.
 * @param aY  accl Y-axis.
 * @param aZ  accl Z-axis.
 * @param mX  magn X-axis.
 * @param mY  magn Y-axis.
 * @param mZ  magn Z-axis.
 * @param temp  Temperature.
 * @param baro_ahrs  Barometric pressure ahrs.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param alive  Alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataahrs_send(mavlink_channel_t chan, uint64_t time, float senseTime, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float temp, float baro_ahrs, float phi, float the, float psi, float q0, float q1, float q2, float q3, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gX);
    _mav_put_float(buf, 16, gY);
    _mav_put_float(buf, 20, gZ);
    _mav_put_float(buf, 24, aX);
    _mav_put_float(buf, 28, aY);
    _mav_put_float(buf, 32, aZ);
    _mav_put_float(buf, 36, mX);
    _mav_put_float(buf, 40, mY);
    _mav_put_float(buf, 44, mZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, baro_ahrs);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_uint8_t(buf, 84, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, buf, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gX = gX;
    packet.gY = gY;
    packet.gZ = gZ;
    packet.aX = aX;
    packet.aY = aY;
    packet.aZ = aZ;
    packet.mX = mX;
    packet.mY = mY;
    packet.mZ = mZ;
    packet.temp = temp;
    packet.baro_ahrs = baro_ahrs;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, (const char *)&packet, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#endif
}

/**
 * @brief Send a dataahrs message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dataahrs_send_struct(mavlink_channel_t chan, const mavlink_dataahrs_t* dataahrs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dataahrs_send(chan, dataahrs->time, dataahrs->senseTime, dataahrs->gX, dataahrs->gY, dataahrs->gZ, dataahrs->aX, dataahrs->aY, dataahrs->aZ, dataahrs->mX, dataahrs->mY, dataahrs->mZ, dataahrs->temp, dataahrs->baro_ahrs, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->q0, dataahrs->q1, dataahrs->q2, dataahrs->q3, dataahrs->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, (const char *)dataahrs, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataAhrs_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataahrs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float gX, float gY, float gZ, float aX, float aY, float aZ, float mX, float mY, float mZ, float temp, float baro_ahrs, float phi, float the, float psi, float q0, float q1, float q2, float q3, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gX);
    _mav_put_float(buf, 16, gY);
    _mav_put_float(buf, 20, gZ);
    _mav_put_float(buf, 24, aX);
    _mav_put_float(buf, 28, aY);
    _mav_put_float(buf, 32, aZ);
    _mav_put_float(buf, 36, mX);
    _mav_put_float(buf, 40, mY);
    _mav_put_float(buf, 44, mZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, baro_ahrs);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_uint8_t(buf, 84, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, buf, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#else
    mavlink_dataahrs_t *packet = (mavlink_dataahrs_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->gX = gX;
    packet->gY = gY;
    packet->gZ = gZ;
    packet->aX = aX;
    packet->aY = aY;
    packet->aZ = aZ;
    packet->mX = mX;
    packet->mY = mY;
    packet->mZ = mZ;
    packet->temp = temp;
    packet->baro_ahrs = baro_ahrs;
    packet->phi = phi;
    packet->the = the;
    packet->psi = psi;
    packet->q0 = q0;
    packet->q1 = q1;
    packet->q2 = q2;
    packet->q3 = q3;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, (const char *)packet, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#endif
}
#endif

#endif

// MESSAGE DataAhrs UNPACKING


/**
 * @brief Get field time from dataahrs message
 *
 * @return  Time.
 */
static inline uint64_t mavlink_msg_dataahrs_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from dataahrs message
 *
 * @return  Sensetime.
 */
static inline float mavlink_msg_dataahrs_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gX from dataahrs message
 *
 * @return  gyro X-axis.
 */
static inline float mavlink_msg_dataahrs_get_gX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gY from dataahrs message
 *
 * @return  gyro Y-axis.
 */
static inline float mavlink_msg_dataahrs_get_gY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gZ from dataahrs message
 *
 * @return  gyro Z-axis.
 */
static inline float mavlink_msg_dataahrs_get_gZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field aX from dataahrs message
 *
 * @return  accl X-axis.
 */
static inline float mavlink_msg_dataahrs_get_aX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field aY from dataahrs message
 *
 * @return  accl Y-axis.
 */
static inline float mavlink_msg_dataahrs_get_aY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field aZ from dataahrs message
 *
 * @return  accl Z-axis.
 */
static inline float mavlink_msg_dataahrs_get_aZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field mX from dataahrs message
 *
 * @return  magn X-axis.
 */
static inline float mavlink_msg_dataahrs_get_mX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field mY from dataahrs message
 *
 * @return  magn Y-axis.
 */
static inline float mavlink_msg_dataahrs_get_mY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field mZ from dataahrs message
 *
 * @return  magn Z-axis.
 */
static inline float mavlink_msg_dataahrs_get_mZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field temp from dataahrs message
 *
 * @return  Temperature.
 */
static inline float mavlink_msg_dataahrs_get_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field baro_ahrs from dataahrs message
 *
 * @return  Barometric pressure ahrs.
 */
static inline float mavlink_msg_dataahrs_get_baro_ahrs(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field phi from dataahrs message
 *
 * @return  Phi.
 */
static inline float mavlink_msg_dataahrs_get_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field the from dataahrs message
 *
 * @return  Theta.
 */
static inline float mavlink_msg_dataahrs_get_the(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field psi from dataahrs message
 *
 * @return  Psi.
 */
static inline float mavlink_msg_dataahrs_get_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field q0 from dataahrs message
 *
 * @return  q0.
 */
static inline float mavlink_msg_dataahrs_get_q0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field q1 from dataahrs message
 *
 * @return  q1.
 */
static inline float mavlink_msg_dataahrs_get_q1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field q2 from dataahrs message
 *
 * @return  q2.
 */
static inline float mavlink_msg_dataahrs_get_q2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field q3 from dataahrs message
 *
 * @return  q3.
 */
static inline float mavlink_msg_dataahrs_get_q3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field alive from dataahrs message
 *
 * @return  Alive.
 */
static inline uint8_t mavlink_msg_dataahrs_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  84);
}

/**
 * @brief Decode a dataahrs message into a struct
 *
 * @param msg The message to decode
 * @param dataahrs C-struct to decode the message contents into
 */
static inline void mavlink_msg_dataahrs_decode(const mavlink_message_t* msg, mavlink_dataahrs_t* dataahrs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dataahrs->time = mavlink_msg_dataahrs_get_time(msg);
    dataahrs->senseTime = mavlink_msg_dataahrs_get_senseTime(msg);
    dataahrs->gX = mavlink_msg_dataahrs_get_gX(msg);
    dataahrs->gY = mavlink_msg_dataahrs_get_gY(msg);
    dataahrs->gZ = mavlink_msg_dataahrs_get_gZ(msg);
    dataahrs->aX = mavlink_msg_dataahrs_get_aX(msg);
    dataahrs->aY = mavlink_msg_dataahrs_get_aY(msg);
    dataahrs->aZ = mavlink_msg_dataahrs_get_aZ(msg);
    dataahrs->mX = mavlink_msg_dataahrs_get_mX(msg);
    dataahrs->mY = mavlink_msg_dataahrs_get_mY(msg);
    dataahrs->mZ = mavlink_msg_dataahrs_get_mZ(msg);
    dataahrs->temp = mavlink_msg_dataahrs_get_temp(msg);
    dataahrs->baro_ahrs = mavlink_msg_dataahrs_get_baro_ahrs(msg);
    dataahrs->phi = mavlink_msg_dataahrs_get_phi(msg);
    dataahrs->the = mavlink_msg_dataahrs_get_the(msg);
    dataahrs->psi = mavlink_msg_dataahrs_get_psi(msg);
    dataahrs->q0 = mavlink_msg_dataahrs_get_q0(msg);
    dataahrs->q1 = mavlink_msg_dataahrs_get_q1(msg);
    dataahrs->q2 = mavlink_msg_dataahrs_get_q2(msg);
    dataahrs->q3 = mavlink_msg_dataahrs_get_q3(msg);
    dataahrs->alive = mavlink_msg_dataahrs_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataAhrs_LEN? msg->len : MAVLINK_MSG_ID_DataAhrs_LEN;
        memset(dataahrs, 0, MAVLINK_MSG_ID_DataAhrs_LEN);
    memcpy(dataahrs, _MAV_PAYLOAD(msg), len);
#endif
}
