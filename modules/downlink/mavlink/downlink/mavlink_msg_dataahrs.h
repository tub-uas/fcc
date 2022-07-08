#pragma once
// MESSAGE DataAhrs PACKING

#define MAVLINK_MSG_ID_DataAhrs 20000


typedef struct __mavlink_dataahrs_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float gyrX; /*<  Gyro X-Axis*/
 float gyrY; /*<  Gyro Y-Axis*/
 float gyrZ; /*<  Gyro Z-Axis*/
 float accX; /*<  Accelerometer X-Axis*/
 float accY; /*<  Accelerometer Y-Axis*/
 float accZ; /*<  Accelerometer Z-Axis*/
 float magX; /*<  Magnetometer X-Axis*/
 float magY; /*<  Magnetometer Y-Axis*/
 float magZ; /*<  Magnetometer Z-Axis*/
 float temperature; /*<  Temperature*/
 float barometric_pressure; /*<  Barometric pressure*/
 float phi; /*<  Phi*/
 float the; /*<  Theta*/
 float psi; /*<  Psi*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_dataahrs_t;

#define MAVLINK_MSG_ID_DataAhrs_LEN 69
#define MAVLINK_MSG_ID_DataAhrs_MIN_LEN 69
#define MAVLINK_MSG_ID_20000_LEN 69
#define MAVLINK_MSG_ID_20000_MIN_LEN 69

#define MAVLINK_MSG_ID_DataAhrs_CRC 55
#define MAVLINK_MSG_ID_20000_CRC 55



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataAhrs { \
    20000, \
    "DataAhrs", \
    17, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataahrs_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataahrs_t, senseTime) }, \
         { "gyrX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataahrs_t, gyrX) }, \
         { "gyrY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataahrs_t, gyrY) }, \
         { "gyrZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataahrs_t, gyrZ) }, \
         { "accX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataahrs_t, accX) }, \
         { "accY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataahrs_t, accY) }, \
         { "accZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataahrs_t, accZ) }, \
         { "magX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataahrs_t, magX) }, \
         { "magY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataahrs_t, magY) }, \
         { "magZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataahrs_t, magZ) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataahrs_t, temperature) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataahrs_t, barometric_pressure) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataahrs_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataahrs_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataahrs_t, psi) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_dataahrs_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataAhrs { \
    "DataAhrs", \
    17, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataahrs_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataahrs_t, senseTime) }, \
         { "gyrX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataahrs_t, gyrX) }, \
         { "gyrY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataahrs_t, gyrY) }, \
         { "gyrZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataahrs_t, gyrZ) }, \
         { "accX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataahrs_t, accX) }, \
         { "accY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataahrs_t, accY) }, \
         { "accZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataahrs_t, accZ) }, \
         { "magX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataahrs_t, magX) }, \
         { "magY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dataahrs_t, magY) }, \
         { "magZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dataahrs_t, magZ) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dataahrs_t, temperature) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dataahrs_t, barometric_pressure) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dataahrs_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dataahrs_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dataahrs_t, psi) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_dataahrs_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataahrs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temperature  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataahrs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temperature, float barometric_pressure, float phi, float the, float psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, barometric_pressure);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_uint8_t(buf, 68, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAhrs_LEN);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temperature = temperature;
    packet.barometric_pressure = barometric_pressure;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
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
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temperature  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataahrs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float gyrX,float gyrY,float gyrZ,float accX,float accY,float accZ,float magX,float magY,float magZ,float temperature,float barometric_pressure,float phi,float the,float psi,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, barometric_pressure);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_uint8_t(buf, 68, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAhrs_LEN);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temperature = temperature;
    packet.barometric_pressure = barometric_pressure;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
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
    return mavlink_msg_dataahrs_pack(system_id, component_id, msg, dataahrs->time, dataahrs->senseTime, dataahrs->gyrX, dataahrs->gyrY, dataahrs->gyrZ, dataahrs->accX, dataahrs->accY, dataahrs->accZ, dataahrs->magX, dataahrs->magY, dataahrs->magZ, dataahrs->temperature, dataahrs->barometric_pressure, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->alive);
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
    return mavlink_msg_dataahrs_pack_chan(system_id, component_id, chan, msg, dataahrs->time, dataahrs->senseTime, dataahrs->gyrX, dataahrs->gyrY, dataahrs->gyrZ, dataahrs->accX, dataahrs->accY, dataahrs->accZ, dataahrs->magX, dataahrs->magY, dataahrs->magZ, dataahrs->temperature, dataahrs->barometric_pressure, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->alive);
}

/**
 * @brief Send a dataahrs message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temperature  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataahrs_send(mavlink_channel_t chan, uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temperature, float barometric_pressure, float phi, float the, float psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAhrs_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, barometric_pressure);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_uint8_t(buf, 68, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, buf, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#else
    mavlink_dataahrs_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temperature = temperature;
    packet.barometric_pressure = barometric_pressure;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
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
    mavlink_msg_dataahrs_send(chan, dataahrs->time, dataahrs->senseTime, dataahrs->gyrX, dataahrs->gyrY, dataahrs->gyrZ, dataahrs->accX, dataahrs->accY, dataahrs->accZ, dataahrs->magX, dataahrs->magY, dataahrs->magZ, dataahrs->temperature, dataahrs->barometric_pressure, dataahrs->phi, dataahrs->the, dataahrs->psi, dataahrs->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, (const char *)dataahrs, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataAhrs_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataahrs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temperature, float barometric_pressure, float phi, float the, float psi, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, barometric_pressure);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_uint8_t(buf, 68, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAhrs, buf, MAVLINK_MSG_ID_DataAhrs_MIN_LEN, MAVLINK_MSG_ID_DataAhrs_LEN, MAVLINK_MSG_ID_DataAhrs_CRC);
#else
    mavlink_dataahrs_t *packet = (mavlink_dataahrs_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->gyrX = gyrX;
    packet->gyrY = gyrY;
    packet->gyrZ = gyrZ;
    packet->accX = accX;
    packet->accY = accY;
    packet->accZ = accZ;
    packet->magX = magX;
    packet->magY = magY;
    packet->magZ = magZ;
    packet->temperature = temperature;
    packet->barometric_pressure = barometric_pressure;
    packet->phi = phi;
    packet->the = the;
    packet->psi = psi;
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
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_dataahrs_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from dataahrs message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_dataahrs_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gyrX from dataahrs message
 *
 * @return  Gyro X-Axis
 */
static inline float mavlink_msg_dataahrs_get_gyrX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gyrY from dataahrs message
 *
 * @return  Gyro Y-Axis
 */
static inline float mavlink_msg_dataahrs_get_gyrY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gyrZ from dataahrs message
 *
 * @return  Gyro Z-Axis
 */
static inline float mavlink_msg_dataahrs_get_gyrZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field accX from dataahrs message
 *
 * @return  Accelerometer X-Axis
 */
static inline float mavlink_msg_dataahrs_get_accX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field accY from dataahrs message
 *
 * @return  Accelerometer Y-Axis
 */
static inline float mavlink_msg_dataahrs_get_accY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field accZ from dataahrs message
 *
 * @return  Accelerometer Z-Axis
 */
static inline float mavlink_msg_dataahrs_get_accZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field magX from dataahrs message
 *
 * @return  Magnetometer X-Axis
 */
static inline float mavlink_msg_dataahrs_get_magX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field magY from dataahrs message
 *
 * @return  Magnetometer Y-Axis
 */
static inline float mavlink_msg_dataahrs_get_magY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field magZ from dataahrs message
 *
 * @return  Magnetometer Z-Axis
 */
static inline float mavlink_msg_dataahrs_get_magZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field temperature from dataahrs message
 *
 * @return  Temperature
 */
static inline float mavlink_msg_dataahrs_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field barometric_pressure from dataahrs message
 *
 * @return  Barometric pressure
 */
static inline float mavlink_msg_dataahrs_get_barometric_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field phi from dataahrs message
 *
 * @return  Phi
 */
static inline float mavlink_msg_dataahrs_get_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field the from dataahrs message
 *
 * @return  Theta
 */
static inline float mavlink_msg_dataahrs_get_the(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field psi from dataahrs message
 *
 * @return  Psi
 */
static inline float mavlink_msg_dataahrs_get_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field alive from dataahrs message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_dataahrs_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  68);
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
    dataahrs->gyrX = mavlink_msg_dataahrs_get_gyrX(msg);
    dataahrs->gyrY = mavlink_msg_dataahrs_get_gyrY(msg);
    dataahrs->gyrZ = mavlink_msg_dataahrs_get_gyrZ(msg);
    dataahrs->accX = mavlink_msg_dataahrs_get_accX(msg);
    dataahrs->accY = mavlink_msg_dataahrs_get_accY(msg);
    dataahrs->accZ = mavlink_msg_dataahrs_get_accZ(msg);
    dataahrs->magX = mavlink_msg_dataahrs_get_magX(msg);
    dataahrs->magY = mavlink_msg_dataahrs_get_magY(msg);
    dataahrs->magZ = mavlink_msg_dataahrs_get_magZ(msg);
    dataahrs->temperature = mavlink_msg_dataahrs_get_temperature(msg);
    dataahrs->barometric_pressure = mavlink_msg_dataahrs_get_barometric_pressure(msg);
    dataahrs->phi = mavlink_msg_dataahrs_get_phi(msg);
    dataahrs->the = mavlink_msg_dataahrs_get_the(msg);
    dataahrs->psi = mavlink_msg_dataahrs_get_psi(msg);
    dataahrs->alive = mavlink_msg_dataahrs_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataAhrs_LEN? msg->len : MAVLINK_MSG_ID_DataAhrs_LEN;
        memset(dataahrs, 0, MAVLINK_MSG_ID_DataAhrs_LEN);
    memcpy(dataahrs, _MAV_PAYLOAD(msg), len);
#endif
}
