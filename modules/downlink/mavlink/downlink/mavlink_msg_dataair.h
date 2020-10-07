#pragma once
// MESSAGE DataAir PACKING

#define MAVLINK_MSG_ID_DataAir 30000


typedef struct __mavlink_dataair_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float dynamicPress; /*<  Dynamic Pressure*/
 float velocity; /*<  Velocitiy (TAS)*/
 float baroPress; /*<  Barometric pressure*/
 float density; /*<  Density*/
 float temp; /*<  Temperature*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_dataair_t;

#define MAVLINK_MSG_ID_DataAir_LEN 33
#define MAVLINK_MSG_ID_DataAir_MIN_LEN 33
#define MAVLINK_MSG_ID_30000_LEN 33
#define MAVLINK_MSG_ID_30000_MIN_LEN 33

#define MAVLINK_MSG_ID_DataAir_CRC 175
#define MAVLINK_MSG_ID_30000_CRC 175



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataAir { \
    30000, \
    "DataAir", \
    8, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataair_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataair_t, senseTime) }, \
         { "dynamicPress", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataair_t, dynamicPress) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataair_t, velocity) }, \
         { "baroPress", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataair_t, baroPress) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataair_t, density) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataair_t, temp) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_dataair_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataAir { \
    "DataAir", \
    8, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dataair_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dataair_t, senseTime) }, \
         { "dynamicPress", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dataair_t, dynamicPress) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dataair_t, velocity) }, \
         { "baroPress", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dataair_t, baroPress) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dataair_t, density) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dataair_t, temp) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_dataair_t, alive) }, \
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
 * @param dynamicPress  Dynamic Pressure
 * @param velocity  Velocitiy (TAS)
 * @param baroPress  Barometric pressure
 * @param density  Density
 * @param temp  Temperature
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataair_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float dynamicPress, float velocity, float baroPress, float density, float temp, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamicPress);
    _mav_put_float(buf, 16, velocity);
    _mav_put_float(buf, 20, baroPress);
    _mav_put_float(buf, 24, density);
    _mav_put_float(buf, 28, temp);
    _mav_put_uint8_t(buf, 32, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAir_LEN);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamicPress = dynamicPress;
    packet.velocity = velocity;
    packet.baroPress = baroPress;
    packet.density = density;
    packet.temp = temp;
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
 * @param dynamicPress  Dynamic Pressure
 * @param velocity  Velocitiy (TAS)
 * @param baroPress  Barometric pressure
 * @param density  Density
 * @param temp  Temperature
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dataair_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float dynamicPress,float velocity,float baroPress,float density,float temp,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamicPress);
    _mav_put_float(buf, 16, velocity);
    _mav_put_float(buf, 20, baroPress);
    _mav_put_float(buf, 24, density);
    _mav_put_float(buf, 28, temp);
    _mav_put_uint8_t(buf, 32, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataAir_LEN);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamicPress = dynamicPress;
    packet.velocity = velocity;
    packet.baroPress = baroPress;
    packet.density = density;
    packet.temp = temp;
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
    return mavlink_msg_dataair_pack(system_id, component_id, msg, dataair->time, dataair->senseTime, dataair->dynamicPress, dataair->velocity, dataair->baroPress, dataair->density, dataair->temp, dataair->alive);
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
    return mavlink_msg_dataair_pack_chan(system_id, component_id, chan, msg, dataair->time, dataair->senseTime, dataair->dynamicPress, dataair->velocity, dataair->baroPress, dataair->density, dataair->temp, dataair->alive);
}

/**
 * @brief Send a dataair message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param dynamicPress  Dynamic Pressure
 * @param velocity  Velocitiy (TAS)
 * @param baroPress  Barometric pressure
 * @param density  Density
 * @param temp  Temperature
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dataair_send(mavlink_channel_t chan, uint64_t time, float senseTime, float dynamicPress, float velocity, float baroPress, float density, float temp, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataAir_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamicPress);
    _mav_put_float(buf, 16, velocity);
    _mav_put_float(buf, 20, baroPress);
    _mav_put_float(buf, 24, density);
    _mav_put_float(buf, 28, temp);
    _mav_put_uint8_t(buf, 32, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, buf, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#else
    mavlink_dataair_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.dynamicPress = dynamicPress;
    packet.velocity = velocity;
    packet.baroPress = baroPress;
    packet.density = density;
    packet.temp = temp;
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
    mavlink_msg_dataair_send(chan, dataair->time, dataair->senseTime, dataair->dynamicPress, dataair->velocity, dataair->baroPress, dataair->density, dataair->temp, dataair->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, (const char *)dataair, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataAir_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dataair_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float dynamicPress, float velocity, float baroPress, float density, float temp, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, dynamicPress);
    _mav_put_float(buf, 16, velocity);
    _mav_put_float(buf, 20, baroPress);
    _mav_put_float(buf, 24, density);
    _mav_put_float(buf, 28, temp);
    _mav_put_uint8_t(buf, 32, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataAir, buf, MAVLINK_MSG_ID_DataAir_MIN_LEN, MAVLINK_MSG_ID_DataAir_LEN, MAVLINK_MSG_ID_DataAir_CRC);
#else
    mavlink_dataair_t *packet = (mavlink_dataair_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->dynamicPress = dynamicPress;
    packet->velocity = velocity;
    packet->baroPress = baroPress;
    packet->density = density;
    packet->temp = temp;
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
 * @brief Get field dynamicPress from dataair message
 *
 * @return  Dynamic Pressure
 */
static inline float mavlink_msg_dataair_get_dynamicPress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field velocity from dataair message
 *
 * @return  Velocitiy (TAS)
 */
static inline float mavlink_msg_dataair_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field baroPress from dataair message
 *
 * @return  Barometric pressure
 */
static inline float mavlink_msg_dataair_get_baroPress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field density from dataair message
 *
 * @return  Density
 */
static inline float mavlink_msg_dataair_get_density(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field temp from dataair message
 *
 * @return  Temperature
 */
static inline float mavlink_msg_dataair_get_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field alive from dataair message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_dataair_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
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
    dataair->dynamicPress = mavlink_msg_dataair_get_dynamicPress(msg);
    dataair->velocity = mavlink_msg_dataair_get_velocity(msg);
    dataair->baroPress = mavlink_msg_dataair_get_baroPress(msg);
    dataair->density = mavlink_msg_dataair_get_density(msg);
    dataair->temp = mavlink_msg_dataair_get_temp(msg);
    dataair->alive = mavlink_msg_dataair_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataAir_LEN? msg->len : MAVLINK_MSG_ID_DataAir_LEN;
        memset(dataair, 0, MAVLINK_MSG_ID_DataAir_LEN);
    memcpy(dataair, _MAV_PAYLOAD(msg), len);
#endif
}
