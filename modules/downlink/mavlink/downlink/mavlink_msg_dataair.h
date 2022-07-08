#pragma once
// MESSAGE DataAir PACKING

#define MAVLINK_MSG_ID_DataAir 30000


typedef struct __mavlink_dataair_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float dynamic_pressure; /*<  Dynamic Pressure*/
 float true_airspeed; /*<  TAS*/
 float indicated_airspeed; /*<  IAS*/
 float barometric_pressure; /*<  Barometric pressure*/
 float barometric_height; /*<  Barometric height*/
 float density; /*<  Density*/
 float temperature; /*<  Temperature*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_dataair_t;

#define MAVLINK_MSG_ID_DataAir_LEN 41
#define MAVLINK_MSG_ID_DataAir_MIN_LEN 41
#define MAVLINK_MSG_ID_30000_LEN 41
#define MAVLINK_MSG_ID_30000_MIN_LEN 41

#define MAVLINK_MSG_ID_DataAir_CRC 215
#define MAVLINK_MSG_ID_30000_CRC 215



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataAir { \
    30000, \
    "DataAir", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataair_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataair_t, senseTime) }, \
         { "dynamic_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataair_t, dynamic_pressure) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataair_t, true_airspeed) }, \
         { "indicated_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataair_t, indicated_airspeed) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataair_t, barometric_pressure) }, \
         { "barometric_height", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataair_t, barometric_height) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataair_t, density) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataair_t, temperature) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_dataair_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataAir { \
    "DataAir", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataair_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataair_t, senseTime) }, \
         { "dynamic_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataair_t, dynamic_pressure) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataair_t, true_airspeed) }, \
         { "indicated_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataair_t, indicated_airspeed) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataair_t, barometric_pressure) }, \
         { "barometric_height", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataair_t, barometric_height) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dataair_t, density) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dataair_t, temperature) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_dataair_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a dataair message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param dynamic_pressure  Dynamic Pressure
 * @param true_airspeed  TAS
 * @param indicated_airspeed  IAS
 * @param barometric_pressure  Barometric pressure
 * @param barometric_height  Barometric height
 * @param density  Density
 * @param temperature  Temperature
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataair_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float dynamic_pressure, float true_airspeed, float indicated_airspeed, float barometric_pressure, float barometric_height, float density, float temperature, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamic_pressure);
    _mav_put_float(buf, 16, true_airspeed);
    _mav_put_float(buf, 20, indicated_airspeed);
    _mav_put_float(buf, 24, barometric_pressure);
    _mav_put_float(buf, 28, barometric_height);
    _mav_put_float(buf, 32, density);
    _mav_put_float(buf, 36, temperature);
    _mav_put_uint8_t(buf, 40, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAir_LEN);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamic_pressure = dynamic_pressure;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.barometric_pressure = barometric_pressure;
    packet.barometric_height = barometric_height;
    packet.density = density;
    packet.temperature = temperature;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataAir_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataAir;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
}

/**
 * @brief Pack a dataair message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param dynamic_pressure  Dynamic Pressure
 * @param true_airspeed  TAS
 * @param indicated_airspeed  IAS
 * @param barometric_pressure  Barometric pressure
 * @param barometric_height  Barometric height
 * @param density  Density
 * @param temperature  Temperature
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataair_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float dynamic_pressure,float true_airspeed,float indicated_airspeed,float barometric_pressure,float barometric_height,float density,float temperature,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamic_pressure);
    _mav_put_float(buf, 16, true_airspeed);
    _mav_put_float(buf, 20, indicated_airspeed);
    _mav_put_float(buf, 24, barometric_pressure);
    _mav_put_float(buf, 28, barometric_height);
    _mav_put_float(buf, 32, density);
    _mav_put_float(buf, 36, temperature);
    _mav_put_uint8_t(buf, 40, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAir_LEN);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamic_pressure = dynamic_pressure;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.barometric_pressure = barometric_pressure;
    packet.barometric_height = barometric_height;
    packet.density = density;
    packet.temperature = temperature;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataAir_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataAir;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
}

/**
 * @brief Encode a dataair struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dataair C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataair_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dataair_t* dataair)
{
    return mavlink_msg_dataair_pack(system_id, component_id, msg, dataair->time, dataair->senseTime, dataair->dynamic_pressure, dataair->true_airspeed, dataair->indicated_airspeed, dataair->barometric_pressure, dataair->barometric_height, dataair->density, dataair->temperature, dataair->alive);
}

/**
 * @brief Encode a dataair struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dataair C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dataair_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dataair_t* dataair)
{
    return mavlink_msg_dataair_pack_chan(system_id, component_id, chan, msg, dataair->time, dataair->senseTime, dataair->dynamic_pressure, dataair->true_airspeed, dataair->indicated_airspeed, dataair->barometric_pressure, dataair->barometric_height, dataair->density, dataair->temperature, dataair->alive);
}

/**
 * @brief Send a dataair message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param dynamic_pressure  Dynamic Pressure
 * @param true_airspeed  TAS
 * @param indicated_airspeed  IAS
 * @param barometric_pressure  Barometric pressure
 * @param barometric_height  Barometric height
 * @param density  Density
 * @param temperature  Temperature
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataair_send(mavlink_channel_t chan, uint64_t time, float senseTime, float dynamic_pressure, float true_airspeed, float indicated_airspeed, float barometric_pressure, float barometric_height, float density, float temperature, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamic_pressure);
    _mav_put_float(buf, 16, true_airspeed);
    _mav_put_float(buf, 20, indicated_airspeed);
    _mav_put_float(buf, 24, barometric_pressure);
    _mav_put_float(buf, 28, barometric_height);
    _mav_put_float(buf, 32, density);
    _mav_put_float(buf, 36, temperature);
    _mav_put_uint8_t(buf, 40, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, buf, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamic_pressure = dynamic_pressure;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.barometric_pressure = barometric_pressure;
    packet.barometric_height = barometric_height;
    packet.density = density;
    packet.temperature = temperature;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, (const char *)&packet, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#endif
}

/**
 * @brief Send a dataair message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dataair_send_struct(mavlink_channel_t chan, const mavlink_dataair_t* dataair)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dataair_send(chan, dataair->time, dataair->senseTime, dataair->dynamic_pressure, dataair->true_airspeed, dataair->indicated_airspeed, dataair->barometric_pressure, dataair->barometric_height, dataair->density, dataair->temperature, dataair->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, (const char *)dataair, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataAir_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataair_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float dynamic_pressure, float true_airspeed, float indicated_airspeed, float barometric_pressure, float barometric_height, float density, float temperature, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamic_pressure);
    _mav_put_float(buf, 16, true_airspeed);
    _mav_put_float(buf, 20, indicated_airspeed);
    _mav_put_float(buf, 24, barometric_pressure);
    _mav_put_float(buf, 28, barometric_height);
    _mav_put_float(buf, 32, density);
    _mav_put_float(buf, 36, temperature);
    _mav_put_uint8_t(buf, 40, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, buf, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#else
    mavlink_dataair_t *packet = (mavlink_dataair_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->dynamic_pressure = dynamic_pressure;
    packet->true_airspeed = true_airspeed;
    packet->indicated_airspeed = indicated_airspeed;
    packet->barometric_pressure = barometric_pressure;
    packet->barometric_height = barometric_height;
    packet->density = density;
    packet->temperature = temperature;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, (const char *)packet, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#endif
}
#endif

#endif

// MESSAGE DataAir UNPACKING


/**
 * @brief Get field time from dataair message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_dataair_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from dataair message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_dataair_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field dynamic_pressure from dataair message
 *
 * @return  Dynamic Pressure
 */
static inline float mavlink_msg_dataair_get_dynamic_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field true_airspeed from dataair message
 *
 * @return  TAS
 */
static inline float mavlink_msg_dataair_get_true_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field indicated_airspeed from dataair message
 *
 * @return  IAS
 */
static inline float mavlink_msg_dataair_get_indicated_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field barometric_pressure from dataair message
 *
 * @return  Barometric pressure
 */
static inline float mavlink_msg_dataair_get_barometric_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field barometric_height from dataair message
 *
 * @return  Barometric height
 */
static inline float mavlink_msg_dataair_get_barometric_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field density from dataair message
 *
 * @return  Density
 */
static inline float mavlink_msg_dataair_get_density(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field temperature from dataair message
 *
 * @return  Temperature
 */
static inline float mavlink_msg_dataair_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field alive from dataair message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_dataair_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Decode a dataair message into a struct
 *
 * @param msg The message to decode
 * @param dataair C-struct to decode the message contents into
 */
static inline void mavlink_msg_dataair_decode(const mavlink_message_t* msg, mavlink_dataair_t* dataair)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dataair->time = mavlink_msg_dataair_get_time(msg);
    dataair->senseTime = mavlink_msg_dataair_get_senseTime(msg);
    dataair->dynamic_pressure = mavlink_msg_dataair_get_dynamic_pressure(msg);
    dataair->true_airspeed = mavlink_msg_dataair_get_true_airspeed(msg);
    dataair->indicated_airspeed = mavlink_msg_dataair_get_indicated_airspeed(msg);
    dataair->barometric_pressure = mavlink_msg_dataair_get_barometric_pressure(msg);
    dataair->barometric_height = mavlink_msg_dataair_get_barometric_height(msg);
    dataair->density = mavlink_msg_dataair_get_density(msg);
    dataair->temperature = mavlink_msg_dataair_get_temperature(msg);
    dataair->alive = mavlink_msg_dataair_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataAir_LEN? msg->len : MAVLINK_MSG_ID_DataAir_LEN;
        memset(dataair, 0, MAVLINK_MSG_ID_DataAir_LEN);
    memcpy(dataair, _MAV_PAYLOAD(msg), len);
#endif
}
