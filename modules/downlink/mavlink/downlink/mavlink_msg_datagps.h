#pragma once
// MESSAGE DataGps PACKING

#define MAVLINK_MSG_ID_DataGps 80000


typedef struct __mavlink_datagps_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float lat; /*<  Latitude in deg*/
 float lon; /*<  Longitude in deg*/
 float alt; /*<  Altitude in m*/
 float speed; /*<  Speed in m/s*/
 float cog; /*<  Course over ground in deg*/
 float sats; /*<  Number of satellites currently using*/
 float fix; /*<  0=No fix, 1=Fix, 2=Differential fix*/
 float fixMode; /*<  1=No fix, 2=2D fix, 3=3D fix*/
 float dopP; /*<  Positional dilution of precision*/
 float dopH; /*<  Horizontal dilution of precision*/
 float dopV; /*<  Vertical dilution of precision*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_datagps_t;

#define MAVLINK_MSG_ID_DataGps_LEN 57
#define MAVLINK_MSG_ID_DataGps_MIN_LEN 57
#define MAVLINK_MSG_ID_80000_LEN 57
#define MAVLINK_MSG_ID_80000_MIN_LEN 57

#define MAVLINK_MSG_ID_DataGps_CRC 34
#define MAVLINK_MSG_ID_80000_CRC 34



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataGps { \
    80000, \
    "DataGps", \
    14, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datagps_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datagps_t, senseTime) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datagps_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datagps_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datagps_t, alt) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datagps_t, speed) }, \
         { "cog", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datagps_t, cog) }, \
         { "sats", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datagps_t, sats) }, \
         { "fix", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datagps_t, fix) }, \
         { "fixMode", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datagps_t, fixMode) }, \
         { "dopP", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datagps_t, dopP) }, \
         { "dopH", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datagps_t, dopH) }, \
         { "dopV", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datagps_t, dopV) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_datagps_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataGps { \
    "DataGps", \
    14, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datagps_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datagps_t, senseTime) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datagps_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datagps_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datagps_t, alt) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datagps_t, speed) }, \
         { "cog", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datagps_t, cog) }, \
         { "sats", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datagps_t, sats) }, \
         { "fix", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datagps_t, fix) }, \
         { "fixMode", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datagps_t, fixMode) }, \
         { "dopP", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datagps_t, dopP) }, \
         { "dopH", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datagps_t, dopH) }, \
         { "dopV", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datagps_t, dopV) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_datagps_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datagps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param lat  Latitude in deg
 * @param lon  Longitude in deg
 * @param alt  Altitude in m
 * @param speed  Speed in m/s
 * @param cog  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fixMode  1=No fix, 2=2D fix, 3=3D fix
 * @param dopP  Positional dilution of precision
 * @param dopH  Horizontal dilution of precision
 * @param dopV  Vertical dilution of precision
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datagps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float lat, float lon, float alt, float speed, float cog, float sats, float fix, float fixMode, float dopP, float dopH, float dopV, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, lat);
    _mav_put_float(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_float(buf, 24, speed);
    _mav_put_float(buf, 28, cog);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, fix);
    _mav_put_float(buf, 40, fixMode);
    _mav_put_float(buf, 44, dopP);
    _mav_put_float(buf, 48, dopH);
    _mav_put_float(buf, 52, dopV);
    _mav_put_uint8_t(buf, 56, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataGps_LEN);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.speed = speed;
    packet.cog = cog;
    packet.sats = sats;
    packet.fix = fix;
    packet.fixMode = fixMode;
    packet.dopP = dopP;
    packet.dopH = dopH;
    packet.dopV = dopV;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataGps_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataGps;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
}

/**
 * @brief Pack a datagps message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param lat  Latitude in deg
 * @param lon  Longitude in deg
 * @param alt  Altitude in m
 * @param speed  Speed in m/s
 * @param cog  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fixMode  1=No fix, 2=2D fix, 3=3D fix
 * @param dopP  Positional dilution of precision
 * @param dopH  Horizontal dilution of precision
 * @param dopV  Vertical dilution of precision
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datagps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float lat,float lon,float alt,float speed,float cog,float sats,float fix,float fixMode,float dopP,float dopH,float dopV,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, lat);
    _mav_put_float(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_float(buf, 24, speed);
    _mav_put_float(buf, 28, cog);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, fix);
    _mav_put_float(buf, 40, fixMode);
    _mav_put_float(buf, 44, dopP);
    _mav_put_float(buf, 48, dopH);
    _mav_put_float(buf, 52, dopV);
    _mav_put_uint8_t(buf, 56, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataGps_LEN);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.speed = speed;
    packet.cog = cog;
    packet.sats = sats;
    packet.fix = fix;
    packet.fixMode = fixMode;
    packet.dopP = dopP;
    packet.dopH = dopH;
    packet.dopV = dopV;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataGps_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataGps;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
}

/**
 * @brief Encode a datagps struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datagps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datagps_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datagps_t* datagps)
{
    return mavlink_msg_datagps_pack(system_id, component_id, msg, datagps->time, datagps->senseTime, datagps->lat, datagps->lon, datagps->alt, datagps->speed, datagps->cog, datagps->sats, datagps->fix, datagps->fixMode, datagps->dopP, datagps->dopH, datagps->dopV, datagps->alive);
}

/**
 * @brief Encode a datagps struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datagps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datagps_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datagps_t* datagps)
{
    return mavlink_msg_datagps_pack_chan(system_id, component_id, chan, msg, datagps->time, datagps->senseTime, datagps->lat, datagps->lon, datagps->alt, datagps->speed, datagps->cog, datagps->sats, datagps->fix, datagps->fixMode, datagps->dopP, datagps->dopH, datagps->dopV, datagps->alive);
}

/**
 * @brief Send a datagps message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param lat  Latitude in deg
 * @param lon  Longitude in deg
 * @param alt  Altitude in m
 * @param speed  Speed in m/s
 * @param cog  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fixMode  1=No fix, 2=2D fix, 3=3D fix
 * @param dopP  Positional dilution of precision
 * @param dopH  Horizontal dilution of precision
 * @param dopV  Vertical dilution of precision
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datagps_send(mavlink_channel_t chan, uint64_t time, float senseTime, float lat, float lon, float alt, float speed, float cog, float sats, float fix, float fixMode, float dopP, float dopH, float dopV, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, lat);
    _mav_put_float(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_float(buf, 24, speed);
    _mav_put_float(buf, 28, cog);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, fix);
    _mav_put_float(buf, 40, fixMode);
    _mav_put_float(buf, 44, dopP);
    _mav_put_float(buf, 48, dopH);
    _mav_put_float(buf, 52, dopV);
    _mav_put_uint8_t(buf, 56, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, buf, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.speed = speed;
    packet.cog = cog;
    packet.sats = sats;
    packet.fix = fix;
    packet.fixMode = fixMode;
    packet.dopP = dopP;
    packet.dopH = dopH;
    packet.dopV = dopV;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, (const char *)&packet, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#endif
}

/**
 * @brief Send a datagps message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datagps_send_struct(mavlink_channel_t chan, const mavlink_datagps_t* datagps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datagps_send(chan, datagps->time, datagps->senseTime, datagps->lat, datagps->lon, datagps->alt, datagps->speed, datagps->cog, datagps->sats, datagps->fix, datagps->fixMode, datagps->dopP, datagps->dopH, datagps->dopV, datagps->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, (const char *)datagps, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataGps_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datagps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float lat, float lon, float alt, float speed, float cog, float sats, float fix, float fixMode, float dopP, float dopH, float dopV, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, lat);
    _mav_put_float(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_float(buf, 24, speed);
    _mav_put_float(buf, 28, cog);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, fix);
    _mav_put_float(buf, 40, fixMode);
    _mav_put_float(buf, 44, dopP);
    _mav_put_float(buf, 48, dopH);
    _mav_put_float(buf, 52, dopV);
    _mav_put_uint8_t(buf, 56, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, buf, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#else
    mavlink_datagps_t *packet = (mavlink_datagps_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->speed = speed;
    packet->cog = cog;
    packet->sats = sats;
    packet->fix = fix;
    packet->fixMode = fixMode;
    packet->dopP = dopP;
    packet->dopH = dopH;
    packet->dopV = dopV;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, (const char *)packet, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#endif
}
#endif

#endif

// MESSAGE DataGps UNPACKING


/**
 * @brief Get field time from datagps message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datagps_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from datagps message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_datagps_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field lat from datagps message
 *
 * @return  Latitude in deg
 */
static inline float mavlink_msg_datagps_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field lon from datagps message
 *
 * @return  Longitude in deg
 */
static inline float mavlink_msg_datagps_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field alt from datagps message
 *
 * @return  Altitude in m
 */
static inline float mavlink_msg_datagps_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field speed from datagps message
 *
 * @return  Speed in m/s
 */
static inline float mavlink_msg_datagps_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field cog from datagps message
 *
 * @return  Course over ground in deg
 */
static inline float mavlink_msg_datagps_get_cog(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field sats from datagps message
 *
 * @return  Number of satellites currently using
 */
static inline float mavlink_msg_datagps_get_sats(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field fix from datagps message
 *
 * @return  0=No fix, 1=Fix, 2=Differential fix
 */
static inline float mavlink_msg_datagps_get_fix(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field fixMode from datagps message
 *
 * @return  1=No fix, 2=2D fix, 3=3D fix
 */
static inline float mavlink_msg_datagps_get_fixMode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field dopP from datagps message
 *
 * @return  Positional dilution of precision
 */
static inline float mavlink_msg_datagps_get_dopP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field dopH from datagps message
 *
 * @return  Horizontal dilution of precision
 */
static inline float mavlink_msg_datagps_get_dopH(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field dopV from datagps message
 *
 * @return  Vertical dilution of precision
 */
static inline float mavlink_msg_datagps_get_dopV(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field alive from datagps message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_datagps_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Decode a datagps message into a struct
 *
 * @param msg The message to decode
 * @param datagps C-struct to decode the message contents into
 */
static inline void mavlink_msg_datagps_decode(const mavlink_message_t* msg, mavlink_datagps_t* datagps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datagps->time = mavlink_msg_datagps_get_time(msg);
    datagps->senseTime = mavlink_msg_datagps_get_senseTime(msg);
    datagps->lat = mavlink_msg_datagps_get_lat(msg);
    datagps->lon = mavlink_msg_datagps_get_lon(msg);
    datagps->alt = mavlink_msg_datagps_get_alt(msg);
    datagps->speed = mavlink_msg_datagps_get_speed(msg);
    datagps->cog = mavlink_msg_datagps_get_cog(msg);
    datagps->sats = mavlink_msg_datagps_get_sats(msg);
    datagps->fix = mavlink_msg_datagps_get_fix(msg);
    datagps->fixMode = mavlink_msg_datagps_get_fixMode(msg);
    datagps->dopP = mavlink_msg_datagps_get_dopP(msg);
    datagps->dopH = mavlink_msg_datagps_get_dopH(msg);
    datagps->dopV = mavlink_msg_datagps_get_dopV(msg);
    datagps->alive = mavlink_msg_datagps_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataGps_LEN? msg->len : MAVLINK_MSG_ID_DataGps_LEN;
        memset(datagps, 0, MAVLINK_MSG_ID_DataGps_LEN);
    memcpy(datagps, _MAV_PAYLOAD(msg), len);
#endif
}
