#pragma once
// MESSAGE DataGps PACKING

#define MAVLINK_MSG_ID_DataGps 80000


typedef struct __mavlink_datagps_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float latitude; /*<  Latitude in deg*/
 float longitude; /*<  Longitude in deg*/
 float alt_msl; /*<  Altitude in m*/
 float groundspeed; /*<  Speed in m/s*/
 float course_over_ground; /*<  Course over ground in deg*/
 float sats; /*<  Number of satellites currently using*/
 float sats_in_view; /*<  Number of satellites in view*/
 float fix; /*<  0=No fix, 1=Fix, 2=Differential fix*/
 float fix_mode; /*<  1=No fix, 2=2D fix, 3=3D fix*/
 float dop_position; /*<  Positional dilution of precision*/
 float dop_horizontal; /*<  Horizontal dilution of precision*/
 float dop_velocity; /*<  Vertical dilution of precision*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_datagps_t;

#define MAVLINK_MSG_ID_DataGps_LEN 61
#define MAVLINK_MSG_ID_DataGps_MIN_LEN 61
#define MAVLINK_MSG_ID_80000_LEN 61
#define MAVLINK_MSG_ID_80000_MIN_LEN 61

#define MAVLINK_MSG_ID_DataGps_CRC 161
#define MAVLINK_MSG_ID_80000_CRC 161



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataGps { \
    80000, \
    "DataGps", \
    15, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datagps_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datagps_t, senseTime) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datagps_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datagps_t, longitude) }, \
         { "alt_msl", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datagps_t, alt_msl) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datagps_t, groundspeed) }, \
         { "course_over_ground", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datagps_t, course_over_ground) }, \
         { "sats", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datagps_t, sats) }, \
         { "sats_in_view", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datagps_t, sats_in_view) }, \
         { "fix", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datagps_t, fix) }, \
         { "fix_mode", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datagps_t, fix_mode) }, \
         { "dop_position", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datagps_t, dop_position) }, \
         { "dop_horizontal", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datagps_t, dop_horizontal) }, \
         { "dop_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datagps_t, dop_velocity) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_datagps_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataGps { \
    "DataGps", \
    15, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datagps_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datagps_t, senseTime) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datagps_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datagps_t, longitude) }, \
         { "alt_msl", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datagps_t, alt_msl) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datagps_t, groundspeed) }, \
         { "course_over_ground", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datagps_t, course_over_ground) }, \
         { "sats", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datagps_t, sats) }, \
         { "sats_in_view", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datagps_t, sats_in_view) }, \
         { "fix", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datagps_t, fix) }, \
         { "fix_mode", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datagps_t, fix_mode) }, \
         { "dop_position", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datagps_t, dop_position) }, \
         { "dop_horizontal", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datagps_t, dop_horizontal) }, \
         { "dop_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datagps_t, dop_velocity) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_datagps_t, alive) }, \
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
 * @param latitude  Latitude in deg
 * @param longitude  Longitude in deg
 * @param alt_msl  Altitude in m
 * @param groundspeed  Speed in m/s
 * @param course_over_ground  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param sats_in_view  Number of satellites in view
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fix_mode  1=No fix, 2=2D fix, 3=3D fix
 * @param dop_position  Positional dilution of precision
 * @param dop_horizontal  Horizontal dilution of precision
 * @param dop_velocity  Vertical dilution of precision
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datagps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float latitude, float longitude, float alt_msl, float groundspeed, float course_over_ground, float sats, float sats_in_view, float fix, float fix_mode, float dop_position, float dop_horizontal, float dop_velocity, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, latitude);
    _mav_put_float(buf, 16, longitude);
    _mav_put_float(buf, 20, alt_msl);
    _mav_put_float(buf, 24, groundspeed);
    _mav_put_float(buf, 28, course_over_ground);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, sats_in_view);
    _mav_put_float(buf, 40, fix);
    _mav_put_float(buf, 44, fix_mode);
    _mav_put_float(buf, 48, dop_position);
    _mav_put_float(buf, 52, dop_horizontal);
    _mav_put_float(buf, 56, dop_velocity);
    _mav_put_uint8_t(buf, 60, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataGps_LEN);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.groundspeed = groundspeed;
    packet.course_over_ground = course_over_ground;
    packet.sats = sats;
    packet.sats_in_view = sats_in_view;
    packet.fix = fix;
    packet.fix_mode = fix_mode;
    packet.dop_position = dop_position;
    packet.dop_horizontal = dop_horizontal;
    packet.dop_velocity = dop_velocity;
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
 * @param latitude  Latitude in deg
 * @param longitude  Longitude in deg
 * @param alt_msl  Altitude in m
 * @param groundspeed  Speed in m/s
 * @param course_over_ground  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param sats_in_view  Number of satellites in view
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fix_mode  1=No fix, 2=2D fix, 3=3D fix
 * @param dop_position  Positional dilution of precision
 * @param dop_horizontal  Horizontal dilution of precision
 * @param dop_velocity  Vertical dilution of precision
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datagps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float latitude,float longitude,float alt_msl,float groundspeed,float course_over_ground,float sats,float sats_in_view,float fix,float fix_mode,float dop_position,float dop_horizontal,float dop_velocity,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, latitude);
    _mav_put_float(buf, 16, longitude);
    _mav_put_float(buf, 20, alt_msl);
    _mav_put_float(buf, 24, groundspeed);
    _mav_put_float(buf, 28, course_over_ground);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, sats_in_view);
    _mav_put_float(buf, 40, fix);
    _mav_put_float(buf, 44, fix_mode);
    _mav_put_float(buf, 48, dop_position);
    _mav_put_float(buf, 52, dop_horizontal);
    _mav_put_float(buf, 56, dop_velocity);
    _mav_put_uint8_t(buf, 60, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataGps_LEN);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.groundspeed = groundspeed;
    packet.course_over_ground = course_over_ground;
    packet.sats = sats;
    packet.sats_in_view = sats_in_view;
    packet.fix = fix;
    packet.fix_mode = fix_mode;
    packet.dop_position = dop_position;
    packet.dop_horizontal = dop_horizontal;
    packet.dop_velocity = dop_velocity;
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
    return mavlink_msg_datagps_pack(system_id, component_id, msg, datagps->time, datagps->senseTime, datagps->latitude, datagps->longitude, datagps->alt_msl, datagps->groundspeed, datagps->course_over_ground, datagps->sats, datagps->sats_in_view, datagps->fix, datagps->fix_mode, datagps->dop_position, datagps->dop_horizontal, datagps->dop_velocity, datagps->alive);
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
    return mavlink_msg_datagps_pack_chan(system_id, component_id, chan, msg, datagps->time, datagps->senseTime, datagps->latitude, datagps->longitude, datagps->alt_msl, datagps->groundspeed, datagps->course_over_ground, datagps->sats, datagps->sats_in_view, datagps->fix, datagps->fix_mode, datagps->dop_position, datagps->dop_horizontal, datagps->dop_velocity, datagps->alive);
}

/**
 * @brief Send a datagps message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param latitude  Latitude in deg
 * @param longitude  Longitude in deg
 * @param alt_msl  Altitude in m
 * @param groundspeed  Speed in m/s
 * @param course_over_ground  Course over ground in deg
 * @param sats  Number of satellites currently using
 * @param sats_in_view  Number of satellites in view
 * @param fix  0=No fix, 1=Fix, 2=Differential fix
 * @param fix_mode  1=No fix, 2=2D fix, 3=3D fix
 * @param dop_position  Positional dilution of precision
 * @param dop_horizontal  Horizontal dilution of precision
 * @param dop_velocity  Vertical dilution of precision
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datagps_send(mavlink_channel_t chan, uint64_t time, float senseTime, float latitude, float longitude, float alt_msl, float groundspeed, float course_over_ground, float sats, float sats_in_view, float fix, float fix_mode, float dop_position, float dop_horizontal, float dop_velocity, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataGps_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, latitude);
    _mav_put_float(buf, 16, longitude);
    _mav_put_float(buf, 20, alt_msl);
    _mav_put_float(buf, 24, groundspeed);
    _mav_put_float(buf, 28, course_over_ground);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, sats_in_view);
    _mav_put_float(buf, 40, fix);
    _mav_put_float(buf, 44, fix_mode);
    _mav_put_float(buf, 48, dop_position);
    _mav_put_float(buf, 52, dop_horizontal);
    _mav_put_float(buf, 56, dop_velocity);
    _mav_put_uint8_t(buf, 60, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, buf, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#else
    mavlink_datagps_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.groundspeed = groundspeed;
    packet.course_over_ground = course_over_ground;
    packet.sats = sats;
    packet.sats_in_view = sats_in_view;
    packet.fix = fix;
    packet.fix_mode = fix_mode;
    packet.dop_position = dop_position;
    packet.dop_horizontal = dop_horizontal;
    packet.dop_velocity = dop_velocity;
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
    mavlink_msg_datagps_send(chan, datagps->time, datagps->senseTime, datagps->latitude, datagps->longitude, datagps->alt_msl, datagps->groundspeed, datagps->course_over_ground, datagps->sats, datagps->sats_in_view, datagps->fix, datagps->fix_mode, datagps->dop_position, datagps->dop_horizontal, datagps->dop_velocity, datagps->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, (const char *)datagps, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataGps_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datagps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float latitude, float longitude, float alt_msl, float groundspeed, float course_over_ground, float sats, float sats_in_view, float fix, float fix_mode, float dop_position, float dop_horizontal, float dop_velocity, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, latitude);
    _mav_put_float(buf, 16, longitude);
    _mav_put_float(buf, 20, alt_msl);
    _mav_put_float(buf, 24, groundspeed);
    _mav_put_float(buf, 28, course_over_ground);
    _mav_put_float(buf, 32, sats);
    _mav_put_float(buf, 36, sats_in_view);
    _mav_put_float(buf, 40, fix);
    _mav_put_float(buf, 44, fix_mode);
    _mav_put_float(buf, 48, dop_position);
    _mav_put_float(buf, 52, dop_horizontal);
    _mav_put_float(buf, 56, dop_velocity);
    _mav_put_uint8_t(buf, 60, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataGps, buf, MAVLINK_MSG_ID_DataGps_MIN_LEN, MAVLINK_MSG_ID_DataGps_LEN, MAVLINK_MSG_ID_DataGps_CRC);
#else
    mavlink_datagps_t *packet = (mavlink_datagps_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->alt_msl = alt_msl;
    packet->groundspeed = groundspeed;
    packet->course_over_ground = course_over_ground;
    packet->sats = sats;
    packet->sats_in_view = sats_in_view;
    packet->fix = fix;
    packet->fix_mode = fix_mode;
    packet->dop_position = dop_position;
    packet->dop_horizontal = dop_horizontal;
    packet->dop_velocity = dop_velocity;
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
 * @brief Get field latitude from datagps message
 *
 * @return  Latitude in deg
 */
static inline float mavlink_msg_datagps_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field longitude from datagps message
 *
 * @return  Longitude in deg
 */
static inline float mavlink_msg_datagps_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field alt_msl from datagps message
 *
 * @return  Altitude in m
 */
static inline float mavlink_msg_datagps_get_alt_msl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field groundspeed from datagps message
 *
 * @return  Speed in m/s
 */
static inline float mavlink_msg_datagps_get_groundspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field course_over_ground from datagps message
 *
 * @return  Course over ground in deg
 */
static inline float mavlink_msg_datagps_get_course_over_ground(const mavlink_message_t* msg)
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
 * @brief Get field sats_in_view from datagps message
 *
 * @return  Number of satellites in view
 */
static inline float mavlink_msg_datagps_get_sats_in_view(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field fix from datagps message
 *
 * @return  0=No fix, 1=Fix, 2=Differential fix
 */
static inline float mavlink_msg_datagps_get_fix(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field fix_mode from datagps message
 *
 * @return  1=No fix, 2=2D fix, 3=3D fix
 */
static inline float mavlink_msg_datagps_get_fix_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field dop_position from datagps message
 *
 * @return  Positional dilution of precision
 */
static inline float mavlink_msg_datagps_get_dop_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field dop_horizontal from datagps message
 *
 * @return  Horizontal dilution of precision
 */
static inline float mavlink_msg_datagps_get_dop_horizontal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field dop_velocity from datagps message
 *
 * @return  Vertical dilution of precision
 */
static inline float mavlink_msg_datagps_get_dop_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field alive from datagps message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_datagps_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  60);
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
    datagps->latitude = mavlink_msg_datagps_get_latitude(msg);
    datagps->longitude = mavlink_msg_datagps_get_longitude(msg);
    datagps->alt_msl = mavlink_msg_datagps_get_alt_msl(msg);
    datagps->groundspeed = mavlink_msg_datagps_get_groundspeed(msg);
    datagps->course_over_ground = mavlink_msg_datagps_get_course_over_ground(msg);
    datagps->sats = mavlink_msg_datagps_get_sats(msg);
    datagps->sats_in_view = mavlink_msg_datagps_get_sats_in_view(msg);
    datagps->fix = mavlink_msg_datagps_get_fix(msg);
    datagps->fix_mode = mavlink_msg_datagps_get_fix_mode(msg);
    datagps->dop_position = mavlink_msg_datagps_get_dop_position(msg);
    datagps->dop_horizontal = mavlink_msg_datagps_get_dop_horizontal(msg);
    datagps->dop_velocity = mavlink_msg_datagps_get_dop_velocity(msg);
    datagps->alive = mavlink_msg_datagps_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataGps_LEN? msg->len : MAVLINK_MSG_ID_DataGps_LEN;
        memset(datagps, 0, MAVLINK_MSG_ID_DataGps_LEN);
    memcpy(datagps, _MAV_PAYLOAD(msg), len);
#endif
}
