#pragma once
// MESSAGE DataSfusion PACKING

#define MAVLINK_MSG_ID_DataSfusion 40000


typedef struct __mavlink_datasfusion_t {
 uint64_t time; /*<  Time.*/
 float phi; /*<  Phi.*/
 float the; /*<  Theta.*/
 float psi; /*<  Psi.*/
 float q0; /*<  q0.*/
 float q1; /*<  q1.*/
 float q2; /*<  q2.*/
 float q3; /*<  q3.*/
 float baro_fused; /*<  Barometric pressure sfusion.*/
 float temp_fused; /*<  Temperature.*/
 float posN; /*<  Position North.*/
 float posE; /*<  Position East.*/
 float posD; /*<  Position Down.*/
 float speedN; /*<  Speed North.*/
 float speedE; /*<  Speed East.*/
 float speedD; /*<  Speed Down.*/
 float WindN; /*<  Wind North.*/
 float WindE; /*<  Wind East.*/
 float WindD; /*<  Wind Down.*/
 float ssa; /*<  Sideslip angle estimation.*/
 float aoa; /*<  Angle of attack estimation.*/
 float gamma; /*<  Pathangle estimation.*/
 uint8_t alive; /*<  Alive.*/
} mavlink_datasfusion_t;

#define MAVLINK_MSG_ID_DataSfusion_LEN 93
#define MAVLINK_MSG_ID_DataSfusion_MIN_LEN 93
#define MAVLINK_MSG_ID_40000_LEN 93
#define MAVLINK_MSG_ID_40000_MIN_LEN 93

#define MAVLINK_MSG_ID_DataSfusion_CRC 170
#define MAVLINK_MSG_ID_40000_CRC 170



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataSfusion { \
    40000, \
    "DataSfusion", \
    23, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datasfusion_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datasfusion_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, q3) }, \
         { "baro_fused", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, baro_fused) }, \
         { "temp_fused", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, temp_fused) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "WindN", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, WindN) }, \
         { "WindE", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, WindE) }, \
         { "WindD", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, WindD) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataSfusion { \
    "DataSfusion", \
    23, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datasfusion_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datasfusion_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, q3) }, \
         { "baro_fused", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, baro_fused) }, \
         { "temp_fused", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, temp_fused) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "WindN", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, WindN) }, \
         { "WindE", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, WindE) }, \
         { "WindD", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, WindD) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datasfusion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  Time.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param baro_fused  Barometric pressure sfusion.
 * @param temp_fused  Temperature.
 * @param posN  Position North.
 * @param posE  Position East.
 * @param posD  Position Down.
 * @param speedN  Speed North.
 * @param speedE  Speed East.
 * @param speedD  Speed Down.
 * @param WindN  Wind North.
 * @param WindE  Wind East.
 * @param WindD  Wind Down.
 * @param ssa  Sideslip angle estimation.
 * @param aoa  Angle of attack estimation.
 * @param gamma  Pathangle estimation.
 * @param alive  Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float phi, float the, float psi, float q0, float q1, float q2, float q3, float baro_fused, float temp_fused, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSfusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, phi);
    _mav_put_float(buf, 12, the);
    _mav_put_float(buf, 16, psi);
    _mav_put_float(buf, 20, q0);
    _mav_put_float(buf, 24, q1);
    _mav_put_float(buf, 28, q2);
    _mav_put_float(buf, 32, q3);
    _mav_put_float(buf, 36, baro_fused);
    _mav_put_float(buf, 40, temp_fused);
    _mav_put_float(buf, 44, posN);
    _mav_put_float(buf, 48, posE);
    _mav_put_float(buf, 52, posD);
    _mav_put_float(buf, 56, speedN);
    _mav_put_float(buf, 60, speedE);
    _mav_put_float(buf, 64, speedD);
    _mav_put_float(buf, 68, WindN);
    _mav_put_float(buf, 72, WindE);
    _mav_put_float(buf, 76, WindD);
    _mav_put_float(buf, 80, ssa);
    _mav_put_float(buf, 84, aoa);
    _mav_put_float(buf, 88, gamma);
    _mav_put_uint8_t(buf, 92, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSfusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.baro_fused = baro_fused;
    packet.temp_fused = temp_fused;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSfusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSfusion;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
}

/**
 * @brief Pack a datasfusion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  Time.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param baro_fused  Barometric pressure sfusion.
 * @param temp_fused  Temperature.
 * @param posN  Position North.
 * @param posE  Position East.
 * @param posD  Position Down.
 * @param speedN  Speed North.
 * @param speedE  Speed East.
 * @param speedD  Speed Down.
 * @param WindN  Wind North.
 * @param WindE  Wind East.
 * @param WindD  Wind Down.
 * @param ssa  Sideslip angle estimation.
 * @param aoa  Angle of attack estimation.
 * @param gamma  Pathangle estimation.
 * @param alive  Alive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float phi,float the,float psi,float q0,float q1,float q2,float q3,float baro_fused,float temp_fused,float posN,float posE,float posD,float speedN,float speedE,float speedD,float WindN,float WindE,float WindD,float ssa,float aoa,float gamma,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSfusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, phi);
    _mav_put_float(buf, 12, the);
    _mav_put_float(buf, 16, psi);
    _mav_put_float(buf, 20, q0);
    _mav_put_float(buf, 24, q1);
    _mav_put_float(buf, 28, q2);
    _mav_put_float(buf, 32, q3);
    _mav_put_float(buf, 36, baro_fused);
    _mav_put_float(buf, 40, temp_fused);
    _mav_put_float(buf, 44, posN);
    _mav_put_float(buf, 48, posE);
    _mav_put_float(buf, 52, posD);
    _mav_put_float(buf, 56, speedN);
    _mav_put_float(buf, 60, speedE);
    _mav_put_float(buf, 64, speedD);
    _mav_put_float(buf, 68, WindN);
    _mav_put_float(buf, 72, WindE);
    _mav_put_float(buf, 76, WindD);
    _mav_put_float(buf, 80, ssa);
    _mav_put_float(buf, 84, aoa);
    _mav_put_float(buf, 88, gamma);
    _mav_put_uint8_t(buf, 92, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSfusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.baro_fused = baro_fused;
    packet.temp_fused = temp_fused;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSfusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSfusion;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
}

/**
 * @brief Encode a datasfusion struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datasfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datasfusion_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datasfusion_t* datasfusion)
{
    return mavlink_msg_datasfusion_pack(system_id, component_id, msg, datasfusion->time, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->baro_fused, datasfusion->temp_fused, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
}

/**
 * @brief Encode a datasfusion struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datasfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datasfusion_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datasfusion_t* datasfusion)
{
    return mavlink_msg_datasfusion_pack_chan(system_id, component_id, chan, msg, datasfusion->time, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->baro_fused, datasfusion->temp_fused, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
}

/**
 * @brief Send a datasfusion message
 * @param chan MAVLink channel to send the message
 *
 * @param time  Time.
 * @param phi  Phi.
 * @param the  Theta.
 * @param psi  Psi.
 * @param q0  q0.
 * @param q1  q1.
 * @param q2  q2.
 * @param q3  q3.
 * @param baro_fused  Barometric pressure sfusion.
 * @param temp_fused  Temperature.
 * @param posN  Position North.
 * @param posE  Position East.
 * @param posD  Position Down.
 * @param speedN  Speed North.
 * @param speedE  Speed East.
 * @param speedD  Speed Down.
 * @param WindN  Wind North.
 * @param WindE  Wind East.
 * @param WindD  Wind Down.
 * @param ssa  Sideslip angle estimation.
 * @param aoa  Angle of attack estimation.
 * @param gamma  Pathangle estimation.
 * @param alive  Alive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datasfusion_send(mavlink_channel_t chan, uint64_t time, float phi, float the, float psi, float q0, float q1, float q2, float q3, float baro_fused, float temp_fused, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSfusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, phi);
    _mav_put_float(buf, 12, the);
    _mav_put_float(buf, 16, psi);
    _mav_put_float(buf, 20, q0);
    _mav_put_float(buf, 24, q1);
    _mav_put_float(buf, 28, q2);
    _mav_put_float(buf, 32, q3);
    _mav_put_float(buf, 36, baro_fused);
    _mav_put_float(buf, 40, temp_fused);
    _mav_put_float(buf, 44, posN);
    _mav_put_float(buf, 48, posE);
    _mav_put_float(buf, 52, posD);
    _mav_put_float(buf, 56, speedN);
    _mav_put_float(buf, 60, speedE);
    _mav_put_float(buf, 64, speedD);
    _mav_put_float(buf, 68, WindN);
    _mav_put_float(buf, 72, WindE);
    _mav_put_float(buf, 76, WindD);
    _mav_put_float(buf, 80, ssa);
    _mav_put_float(buf, 84, aoa);
    _mav_put_float(buf, 88, gamma);
    _mav_put_uint8_t(buf, 92, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSfusion, buf, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.baro_fused = baro_fused;
    packet.temp_fused = temp_fused;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSfusion, (const char *)&packet, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
#endif
}

/**
 * @brief Send a datasfusion message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datasfusion_send_struct(mavlink_channel_t chan, const mavlink_datasfusion_t* datasfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datasfusion_send(chan, datasfusion->time, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->baro_fused, datasfusion->temp_fused, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSfusion, (const char *)datasfusion, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataSfusion_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datasfusion_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float phi, float the, float psi, float q0, float q1, float q2, float q3, float baro_fused, float temp_fused, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, phi);
    _mav_put_float(buf, 12, the);
    _mav_put_float(buf, 16, psi);
    _mav_put_float(buf, 20, q0);
    _mav_put_float(buf, 24, q1);
    _mav_put_float(buf, 28, q2);
    _mav_put_float(buf, 32, q3);
    _mav_put_float(buf, 36, baro_fused);
    _mav_put_float(buf, 40, temp_fused);
    _mav_put_float(buf, 44, posN);
    _mav_put_float(buf, 48, posE);
    _mav_put_float(buf, 52, posD);
    _mav_put_float(buf, 56, speedN);
    _mav_put_float(buf, 60, speedE);
    _mav_put_float(buf, 64, speedD);
    _mav_put_float(buf, 68, WindN);
    _mav_put_float(buf, 72, WindE);
    _mav_put_float(buf, 76, WindD);
    _mav_put_float(buf, 80, ssa);
    _mav_put_float(buf, 84, aoa);
    _mav_put_float(buf, 88, gamma);
    _mav_put_uint8_t(buf, 92, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSfusion, buf, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
#else
    mavlink_datasfusion_t *packet = (mavlink_datasfusion_t *)msgbuf;
    packet->time = time;
    packet->phi = phi;
    packet->the = the;
    packet->psi = psi;
    packet->q0 = q0;
    packet->q1 = q1;
    packet->q2 = q2;
    packet->q3 = q3;
    packet->baro_fused = baro_fused;
    packet->temp_fused = temp_fused;
    packet->posN = posN;
    packet->posE = posE;
    packet->posD = posD;
    packet->speedN = speedN;
    packet->speedE = speedE;
    packet->speedD = speedD;
    packet->WindN = WindN;
    packet->WindE = WindE;
    packet->WindD = WindD;
    packet->ssa = ssa;
    packet->aoa = aoa;
    packet->gamma = gamma;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSfusion, (const char *)packet, MAVLINK_MSG_ID_DataSfusion_MIN_LEN, MAVLINK_MSG_ID_DataSfusion_LEN, MAVLINK_MSG_ID_DataSfusion_CRC);
#endif
}
#endif

#endif

// MESSAGE DataSfusion UNPACKING


/**
 * @brief Get field time from datasfusion message
 *
 * @return  Time.
 */
static inline uint64_t mavlink_msg_datasfusion_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field phi from datasfusion message
 *
 * @return  Phi.
 */
static inline float mavlink_msg_datasfusion_get_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field the from datasfusion message
 *
 * @return  Theta.
 */
static inline float mavlink_msg_datasfusion_get_the(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field psi from datasfusion message
 *
 * @return  Psi.
 */
static inline float mavlink_msg_datasfusion_get_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field q0 from datasfusion message
 *
 * @return  q0.
 */
static inline float mavlink_msg_datasfusion_get_q0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field q1 from datasfusion message
 *
 * @return  q1.
 */
static inline float mavlink_msg_datasfusion_get_q1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field q2 from datasfusion message
 *
 * @return  q2.
 */
static inline float mavlink_msg_datasfusion_get_q2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field q3 from datasfusion message
 *
 * @return  q3.
 */
static inline float mavlink_msg_datasfusion_get_q3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field baro_fused from datasfusion message
 *
 * @return  Barometric pressure sfusion.
 */
static inline float mavlink_msg_datasfusion_get_baro_fused(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field temp_fused from datasfusion message
 *
 * @return  Temperature.
 */
static inline float mavlink_msg_datasfusion_get_temp_fused(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field posN from datasfusion message
 *
 * @return  Position North.
 */
static inline float mavlink_msg_datasfusion_get_posN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field posE from datasfusion message
 *
 * @return  Position East.
 */
static inline float mavlink_msg_datasfusion_get_posE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field posD from datasfusion message
 *
 * @return  Position Down.
 */
static inline float mavlink_msg_datasfusion_get_posD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field speedN from datasfusion message
 *
 * @return  Speed North.
 */
static inline float mavlink_msg_datasfusion_get_speedN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field speedE from datasfusion message
 *
 * @return  Speed East.
 */
static inline float mavlink_msg_datasfusion_get_speedE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field speedD from datasfusion message
 *
 * @return  Speed Down.
 */
static inline float mavlink_msg_datasfusion_get_speedD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field WindN from datasfusion message
 *
 * @return  Wind North.
 */
static inline float mavlink_msg_datasfusion_get_WindN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field WindE from datasfusion message
 *
 * @return  Wind East.
 */
static inline float mavlink_msg_datasfusion_get_WindE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field WindD from datasfusion message
 *
 * @return  Wind Down.
 */
static inline float mavlink_msg_datasfusion_get_WindD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field ssa from datasfusion message
 *
 * @return  Sideslip angle estimation.
 */
static inline float mavlink_msg_datasfusion_get_ssa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field aoa from datasfusion message
 *
 * @return  Angle of attack estimation.
 */
static inline float mavlink_msg_datasfusion_get_aoa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field gamma from datasfusion message
 *
 * @return  Pathangle estimation.
 */
static inline float mavlink_msg_datasfusion_get_gamma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field alive from datasfusion message
 *
 * @return  Alive.
 */
static inline uint8_t mavlink_msg_datasfusion_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  92);
}

/**
 * @brief Decode a datasfusion message into a struct
 *
 * @param msg The message to decode
 * @param datasfusion C-struct to decode the message contents into
 */
static inline void mavlink_msg_datasfusion_decode(const mavlink_message_t* msg, mavlink_datasfusion_t* datasfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datasfusion->time = mavlink_msg_datasfusion_get_time(msg);
    datasfusion->phi = mavlink_msg_datasfusion_get_phi(msg);
    datasfusion->the = mavlink_msg_datasfusion_get_the(msg);
    datasfusion->psi = mavlink_msg_datasfusion_get_psi(msg);
    datasfusion->q0 = mavlink_msg_datasfusion_get_q0(msg);
    datasfusion->q1 = mavlink_msg_datasfusion_get_q1(msg);
    datasfusion->q2 = mavlink_msg_datasfusion_get_q2(msg);
    datasfusion->q3 = mavlink_msg_datasfusion_get_q3(msg);
    datasfusion->baro_fused = mavlink_msg_datasfusion_get_baro_fused(msg);
    datasfusion->temp_fused = mavlink_msg_datasfusion_get_temp_fused(msg);
    datasfusion->posN = mavlink_msg_datasfusion_get_posN(msg);
    datasfusion->posE = mavlink_msg_datasfusion_get_posE(msg);
    datasfusion->posD = mavlink_msg_datasfusion_get_posD(msg);
    datasfusion->speedN = mavlink_msg_datasfusion_get_speedN(msg);
    datasfusion->speedE = mavlink_msg_datasfusion_get_speedE(msg);
    datasfusion->speedD = mavlink_msg_datasfusion_get_speedD(msg);
    datasfusion->WindN = mavlink_msg_datasfusion_get_WindN(msg);
    datasfusion->WindE = mavlink_msg_datasfusion_get_WindE(msg);
    datasfusion->WindD = mavlink_msg_datasfusion_get_WindD(msg);
    datasfusion->ssa = mavlink_msg_datasfusion_get_ssa(msg);
    datasfusion->aoa = mavlink_msg_datasfusion_get_aoa(msg);
    datasfusion->gamma = mavlink_msg_datasfusion_get_gamma(msg);
    datasfusion->alive = mavlink_msg_datasfusion_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataSfusion_LEN? msg->len : MAVLINK_MSG_ID_DataSfusion_LEN;
        memset(datasfusion, 0, MAVLINK_MSG_ID_DataSfusion_LEN);
    memcpy(datasfusion, _MAV_PAYLOAD(msg), len);
#endif
}
