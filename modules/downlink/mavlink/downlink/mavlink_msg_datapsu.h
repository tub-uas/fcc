#pragma once
// MESSAGE DataPsu PACKING

#define MAVLINK_MSG_ID_DataPsu 60000


typedef struct __mavlink_datapsu_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float main_volt; /*<  Voltage of battery*/
 float main_curr; /*<  Current drawn from battery*/
 float main_pwr; /*<  Power drawn from battery*/
 float pwr_volt; /*<  Voltage of servo supply (5V)*/
 float pwr_curr; /*<  Current drawn from servo supply (5V)*/
 float pwr_pwr; /*<  Power drawn from servo supply (5V)*/
 float sys_volt; /*<  Voltage of system supply (5V)*/
 float sys_curr; /*<  Current drawn from system supply (5V)*/
 float sys_pwr; /*<  Power drawn from system supply (5V)*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_datapsu_t;

#define MAVLINK_MSG_ID_DataPsu_LEN 49
#define MAVLINK_MSG_ID_DataPsu_MIN_LEN 49
#define MAVLINK_MSG_ID_60000_LEN 49
#define MAVLINK_MSG_ID_60000_MIN_LEN 49

#define MAVLINK_MSG_ID_DataPsu_CRC 217
#define MAVLINK_MSG_ID_60000_CRC 217



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataPsu { \
    60000, \
    "DataPsu", \
    12, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datapsu_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datapsu_t, senseTime) }, \
         { "main_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datapsu_t, main_volt) }, \
         { "main_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datapsu_t, main_curr) }, \
         { "main_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datapsu_t, main_pwr) }, \
         { "pwr_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datapsu_t, pwr_volt) }, \
         { "pwr_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datapsu_t, pwr_curr) }, \
         { "pwr_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datapsu_t, pwr_pwr) }, \
         { "sys_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datapsu_t, sys_volt) }, \
         { "sys_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datapsu_t, sys_curr) }, \
         { "sys_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datapsu_t, sys_pwr) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_datapsu_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataPsu { \
    "DataPsu", \
    12, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datapsu_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datapsu_t, senseTime) }, \
         { "main_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datapsu_t, main_volt) }, \
         { "main_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datapsu_t, main_curr) }, \
         { "main_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datapsu_t, main_pwr) }, \
         { "pwr_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datapsu_t, pwr_volt) }, \
         { "pwr_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datapsu_t, pwr_curr) }, \
         { "pwr_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datapsu_t, pwr_pwr) }, \
         { "sys_volt", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datapsu_t, sys_volt) }, \
         { "sys_curr", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datapsu_t, sys_curr) }, \
         { "sys_pwr", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datapsu_t, sys_pwr) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_datapsu_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datapsu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param main_volt  Voltage of battery
 * @param main_curr  Current drawn from battery
 * @param main_pwr  Power drawn from battery
 * @param pwr_volt  Voltage of servo supply (5V)
 * @param pwr_curr  Current drawn from servo supply (5V)
 * @param pwr_pwr  Power drawn from servo supply (5V)
 * @param sys_volt  Voltage of system supply (5V)
 * @param sys_curr  Current drawn from system supply (5V)
 * @param sys_pwr  Power drawn from system supply (5V)
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datapsu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float main_volt, float main_curr, float main_pwr, float pwr_volt, float pwr_curr, float pwr_pwr, float sys_volt, float sys_curr, float sys_pwr, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataPsu_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, main_volt);
    _mav_put_float(buf, 16, main_curr);
    _mav_put_float(buf, 20, main_pwr);
    _mav_put_float(buf, 24, pwr_volt);
    _mav_put_float(buf, 28, pwr_curr);
    _mav_put_float(buf, 32, pwr_pwr);
    _mav_put_float(buf, 36, sys_volt);
    _mav_put_float(buf, 40, sys_curr);
    _mav_put_float(buf, 44, sys_pwr);
    _mav_put_uint8_t(buf, 48, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataPsu_LEN);
#else
    mavlink_datapsu_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.main_volt = main_volt;
    packet.main_curr = main_curr;
    packet.main_pwr = main_pwr;
    packet.pwr_volt = pwr_volt;
    packet.pwr_curr = pwr_curr;
    packet.pwr_pwr = pwr_pwr;
    packet.sys_volt = sys_volt;
    packet.sys_curr = sys_curr;
    packet.sys_pwr = sys_pwr;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataPsu_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataPsu;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
}

/**
 * @brief Pack a datapsu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param main_volt  Voltage of battery
 * @param main_curr  Current drawn from battery
 * @param main_pwr  Power drawn from battery
 * @param pwr_volt  Voltage of servo supply (5V)
 * @param pwr_curr  Current drawn from servo supply (5V)
 * @param pwr_pwr  Power drawn from servo supply (5V)
 * @param sys_volt  Voltage of system supply (5V)
 * @param sys_curr  Current drawn from system supply (5V)
 * @param sys_pwr  Power drawn from system supply (5V)
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datapsu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float main_volt,float main_curr,float main_pwr,float pwr_volt,float pwr_curr,float pwr_pwr,float sys_volt,float sys_curr,float sys_pwr,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataPsu_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, main_volt);
    _mav_put_float(buf, 16, main_curr);
    _mav_put_float(buf, 20, main_pwr);
    _mav_put_float(buf, 24, pwr_volt);
    _mav_put_float(buf, 28, pwr_curr);
    _mav_put_float(buf, 32, pwr_pwr);
    _mav_put_float(buf, 36, sys_volt);
    _mav_put_float(buf, 40, sys_curr);
    _mav_put_float(buf, 44, sys_pwr);
    _mav_put_uint8_t(buf, 48, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataPsu_LEN);
#else
    mavlink_datapsu_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.main_volt = main_volt;
    packet.main_curr = main_curr;
    packet.main_pwr = main_pwr;
    packet.pwr_volt = pwr_volt;
    packet.pwr_curr = pwr_curr;
    packet.pwr_pwr = pwr_pwr;
    packet.sys_volt = sys_volt;
    packet.sys_curr = sys_curr;
    packet.sys_pwr = sys_pwr;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataPsu_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataPsu;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
}

/**
 * @brief Encode a datapsu struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datapsu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datapsu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datapsu_t* datapsu)
{
    return mavlink_msg_datapsu_pack(system_id, component_id, msg, datapsu->time, datapsu->senseTime, datapsu->main_volt, datapsu->main_curr, datapsu->main_pwr, datapsu->pwr_volt, datapsu->pwr_curr, datapsu->pwr_pwr, datapsu->sys_volt, datapsu->sys_curr, datapsu->sys_pwr, datapsu->alive);
}

/**
 * @brief Encode a datapsu struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datapsu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datapsu_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datapsu_t* datapsu)
{
    return mavlink_msg_datapsu_pack_chan(system_id, component_id, chan, msg, datapsu->time, datapsu->senseTime, datapsu->main_volt, datapsu->main_curr, datapsu->main_pwr, datapsu->pwr_volt, datapsu->pwr_curr, datapsu->pwr_pwr, datapsu->sys_volt, datapsu->sys_curr, datapsu->sys_pwr, datapsu->alive);
}

/**
 * @brief Send a datapsu message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param main_volt  Voltage of battery
 * @param main_curr  Current drawn from battery
 * @param main_pwr  Power drawn from battery
 * @param pwr_volt  Voltage of servo supply (5V)
 * @param pwr_curr  Current drawn from servo supply (5V)
 * @param pwr_pwr  Power drawn from servo supply (5V)
 * @param sys_volt  Voltage of system supply (5V)
 * @param sys_curr  Current drawn from system supply (5V)
 * @param sys_pwr  Power drawn from system supply (5V)
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datapsu_send(mavlink_channel_t chan, uint64_t time, float senseTime, float main_volt, float main_curr, float main_pwr, float pwr_volt, float pwr_curr, float pwr_pwr, float sys_volt, float sys_curr, float sys_pwr, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataPsu_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, main_volt);
    _mav_put_float(buf, 16, main_curr);
    _mav_put_float(buf, 20, main_pwr);
    _mav_put_float(buf, 24, pwr_volt);
    _mav_put_float(buf, 28, pwr_curr);
    _mav_put_float(buf, 32, pwr_pwr);
    _mav_put_float(buf, 36, sys_volt);
    _mav_put_float(buf, 40, sys_curr);
    _mav_put_float(buf, 44, sys_pwr);
    _mav_put_uint8_t(buf, 48, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataPsu, buf, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
#else
    mavlink_datapsu_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.main_volt = main_volt;
    packet.main_curr = main_curr;
    packet.main_pwr = main_pwr;
    packet.pwr_volt = pwr_volt;
    packet.pwr_curr = pwr_curr;
    packet.pwr_pwr = pwr_pwr;
    packet.sys_volt = sys_volt;
    packet.sys_curr = sys_curr;
    packet.sys_pwr = sys_pwr;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataPsu, (const char *)&packet, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
#endif
}

/**
 * @brief Send a datapsu message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datapsu_send_struct(mavlink_channel_t chan, const mavlink_datapsu_t* datapsu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datapsu_send(chan, datapsu->time, datapsu->senseTime, datapsu->main_volt, datapsu->main_curr, datapsu->main_pwr, datapsu->pwr_volt, datapsu->pwr_curr, datapsu->pwr_pwr, datapsu->sys_volt, datapsu->sys_curr, datapsu->sys_pwr, datapsu->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataPsu, (const char *)datapsu, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataPsu_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datapsu_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float main_volt, float main_curr, float main_pwr, float pwr_volt, float pwr_curr, float pwr_pwr, float sys_volt, float sys_curr, float sys_pwr, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, main_volt);
    _mav_put_float(buf, 16, main_curr);
    _mav_put_float(buf, 20, main_pwr);
    _mav_put_float(buf, 24, pwr_volt);
    _mav_put_float(buf, 28, pwr_curr);
    _mav_put_float(buf, 32, pwr_pwr);
    _mav_put_float(buf, 36, sys_volt);
    _mav_put_float(buf, 40, sys_curr);
    _mav_put_float(buf, 44, sys_pwr);
    _mav_put_uint8_t(buf, 48, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataPsu, buf, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
#else
    mavlink_datapsu_t *packet = (mavlink_datapsu_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->main_volt = main_volt;
    packet->main_curr = main_curr;
    packet->main_pwr = main_pwr;
    packet->pwr_volt = pwr_volt;
    packet->pwr_curr = pwr_curr;
    packet->pwr_pwr = pwr_pwr;
    packet->sys_volt = sys_volt;
    packet->sys_curr = sys_curr;
    packet->sys_pwr = sys_pwr;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataPsu, (const char *)packet, MAVLINK_MSG_ID_DataPsu_MIN_LEN, MAVLINK_MSG_ID_DataPsu_LEN, MAVLINK_MSG_ID_DataPsu_CRC);
#endif
}
#endif

#endif

// MESSAGE DataPsu UNPACKING


/**
 * @brief Get field time from datapsu message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datapsu_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from datapsu message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_datapsu_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field main_volt from datapsu message
 *
 * @return  Voltage of battery
 */
static inline float mavlink_msg_datapsu_get_main_volt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field main_curr from datapsu message
 *
 * @return  Current drawn from battery
 */
static inline float mavlink_msg_datapsu_get_main_curr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field main_pwr from datapsu message
 *
 * @return  Power drawn from battery
 */
static inline float mavlink_msg_datapsu_get_main_pwr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pwr_volt from datapsu message
 *
 * @return  Voltage of servo supply (5V)
 */
static inline float mavlink_msg_datapsu_get_pwr_volt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pwr_curr from datapsu message
 *
 * @return  Current drawn from servo supply (5V)
 */
static inline float mavlink_msg_datapsu_get_pwr_curr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field pwr_pwr from datapsu message
 *
 * @return  Power drawn from servo supply (5V)
 */
static inline float mavlink_msg_datapsu_get_pwr_pwr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field sys_volt from datapsu message
 *
 * @return  Voltage of system supply (5V)
 */
static inline float mavlink_msg_datapsu_get_sys_volt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field sys_curr from datapsu message
 *
 * @return  Current drawn from system supply (5V)
 */
static inline float mavlink_msg_datapsu_get_sys_curr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field sys_pwr from datapsu message
 *
 * @return  Power drawn from system supply (5V)
 */
static inline float mavlink_msg_datapsu_get_sys_pwr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field alive from datapsu message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_datapsu_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Decode a datapsu message into a struct
 *
 * @param msg The message to decode
 * @param datapsu C-struct to decode the message contents into
 */
static inline void mavlink_msg_datapsu_decode(const mavlink_message_t* msg, mavlink_datapsu_t* datapsu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datapsu->time = mavlink_msg_datapsu_get_time(msg);
    datapsu->senseTime = mavlink_msg_datapsu_get_senseTime(msg);
    datapsu->main_volt = mavlink_msg_datapsu_get_main_volt(msg);
    datapsu->main_curr = mavlink_msg_datapsu_get_main_curr(msg);
    datapsu->main_pwr = mavlink_msg_datapsu_get_main_pwr(msg);
    datapsu->pwr_volt = mavlink_msg_datapsu_get_pwr_volt(msg);
    datapsu->pwr_curr = mavlink_msg_datapsu_get_pwr_curr(msg);
    datapsu->pwr_pwr = mavlink_msg_datapsu_get_pwr_pwr(msg);
    datapsu->sys_volt = mavlink_msg_datapsu_get_sys_volt(msg);
    datapsu->sys_curr = mavlink_msg_datapsu_get_sys_curr(msg);
    datapsu->sys_pwr = mavlink_msg_datapsu_get_sys_pwr(msg);
    datapsu->alive = mavlink_msg_datapsu_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataPsu_LEN? msg->len : MAVLINK_MSG_ID_DataPsu_LEN;
        memset(datapsu, 0, MAVLINK_MSG_ID_DataPsu_LEN);
    memcpy(datapsu, _MAV_PAYLOAD(msg), len);
#endif
}
