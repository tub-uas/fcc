#pragma once
// MESSAGE DataWatchdog PACKING

#define MAVLINK_MSG_ID_DataWatchdog 70000


typedef struct __mavlink_datawatchdog_t {
 uint64_t time; /*<  System time at publication*/
 uint8_t allAlive; /*<  Are all modules alive?*/
 uint8_t ahrsAlive; /*<  Is AHRS alive?*/
 uint8_t airAlive; /*<  Is AIR alive?*/
 uint8_t ctrlAlive; /*<  Is Ctrl alive?*/
 uint8_t downlinkAlive; /*<  Is Downlink alive?*/
 uint8_t gpsAlive; /*<  Is GPS alive?*/
 uint8_t logAlive; /*<  Is Downlink alive?*/
 uint8_t psuAlive; /*<  Is PSU alive?*/
 uint8_t raiInAlive; /*<  Is RaiIn alive?*/
 uint8_t raiOutAlive; /*<  Is RaiOut alive?*/
 uint8_t sFusionAlive; /*<  Is SFusion alive?*/
 uint8_t uplinkAlive; /*<  Is Uplink alive?*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_datawatchdog_t;

#define MAVLINK_MSG_ID_DataWatchdog_LEN 21
#define MAVLINK_MSG_ID_DataWatchdog_MIN_LEN 21
#define MAVLINK_MSG_ID_70000_LEN 21
#define MAVLINK_MSG_ID_70000_MIN_LEN 21

#define MAVLINK_MSG_ID_DataWatchdog_CRC 77
#define MAVLINK_MSG_ID_70000_CRC 77



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataWatchdog { \
    70000, \
    "DataWatchdog", \
    14, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datawatchdog_t, time) }, \
         { "allAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_datawatchdog_t, allAlive) }, \
         { "ahrsAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_datawatchdog_t, ahrsAlive) }, \
         { "airAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_datawatchdog_t, airAlive) }, \
         { "ctrlAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_datawatchdog_t, ctrlAlive) }, \
         { "downlinkAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_datawatchdog_t, downlinkAlive) }, \
         { "gpsAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_datawatchdog_t, gpsAlive) }, \
         { "logAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_datawatchdog_t, logAlive) }, \
         { "psuAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_datawatchdog_t, psuAlive) }, \
         { "raiInAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_datawatchdog_t, raiInAlive) }, \
         { "raiOutAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_datawatchdog_t, raiOutAlive) }, \
         { "sFusionAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_datawatchdog_t, sFusionAlive) }, \
         { "uplinkAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_datawatchdog_t, uplinkAlive) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_datawatchdog_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataWatchdog { \
    "DataWatchdog", \
    14, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datawatchdog_t, time) }, \
         { "allAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_datawatchdog_t, allAlive) }, \
         { "ahrsAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_datawatchdog_t, ahrsAlive) }, \
         { "airAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_datawatchdog_t, airAlive) }, \
         { "ctrlAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_datawatchdog_t, ctrlAlive) }, \
         { "downlinkAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_datawatchdog_t, downlinkAlive) }, \
         { "gpsAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_datawatchdog_t, gpsAlive) }, \
         { "logAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_datawatchdog_t, logAlive) }, \
         { "psuAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_datawatchdog_t, psuAlive) }, \
         { "raiInAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_datawatchdog_t, raiInAlive) }, \
         { "raiOutAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_datawatchdog_t, raiOutAlive) }, \
         { "sFusionAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_datawatchdog_t, sFusionAlive) }, \
         { "uplinkAlive", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_datawatchdog_t, uplinkAlive) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_datawatchdog_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datawatchdog message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param allAlive  Are all modules alive?
 * @param ahrsAlive  Is AHRS alive?
 * @param airAlive  Is AIR alive?
 * @param ctrlAlive  Is Ctrl alive?
 * @param downlinkAlive  Is Downlink alive?
 * @param gpsAlive  Is GPS alive?
 * @param logAlive  Is Downlink alive?
 * @param psuAlive  Is PSU alive?
 * @param raiInAlive  Is RaiIn alive?
 * @param raiOutAlive  Is RaiOut alive?
 * @param sFusionAlive  Is SFusion alive?
 * @param uplinkAlive  Is Uplink alive?
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datawatchdog_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, uint8_t allAlive, uint8_t ahrsAlive, uint8_t airAlive, uint8_t ctrlAlive, uint8_t downlinkAlive, uint8_t gpsAlive, uint8_t logAlive, uint8_t psuAlive, uint8_t raiInAlive, uint8_t raiOutAlive, uint8_t sFusionAlive, uint8_t uplinkAlive, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataWatchdog_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, allAlive);
    _mav_put_uint8_t(buf, 9, ahrsAlive);
    _mav_put_uint8_t(buf, 10, airAlive);
    _mav_put_uint8_t(buf, 11, ctrlAlive);
    _mav_put_uint8_t(buf, 12, downlinkAlive);
    _mav_put_uint8_t(buf, 13, gpsAlive);
    _mav_put_uint8_t(buf, 14, logAlive);
    _mav_put_uint8_t(buf, 15, psuAlive);
    _mav_put_uint8_t(buf, 16, raiInAlive);
    _mav_put_uint8_t(buf, 17, raiOutAlive);
    _mav_put_uint8_t(buf, 18, sFusionAlive);
    _mav_put_uint8_t(buf, 19, uplinkAlive);
    _mav_put_uint8_t(buf, 20, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataWatchdog_LEN);
#else
    mavlink_datawatchdog_t packet;
    packet.time = time;
    packet.allAlive = allAlive;
    packet.ahrsAlive = ahrsAlive;
    packet.airAlive = airAlive;
    packet.ctrlAlive = ctrlAlive;
    packet.downlinkAlive = downlinkAlive;
    packet.gpsAlive = gpsAlive;
    packet.logAlive = logAlive;
    packet.psuAlive = psuAlive;
    packet.raiInAlive = raiInAlive;
    packet.raiOutAlive = raiOutAlive;
    packet.sFusionAlive = sFusionAlive;
    packet.uplinkAlive = uplinkAlive;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataWatchdog_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataWatchdog;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
}

/**
 * @brief Pack a datawatchdog message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param allAlive  Are all modules alive?
 * @param ahrsAlive  Is AHRS alive?
 * @param airAlive  Is AIR alive?
 * @param ctrlAlive  Is Ctrl alive?
 * @param downlinkAlive  Is Downlink alive?
 * @param gpsAlive  Is GPS alive?
 * @param logAlive  Is Downlink alive?
 * @param psuAlive  Is PSU alive?
 * @param raiInAlive  Is RaiIn alive?
 * @param raiOutAlive  Is RaiOut alive?
 * @param sFusionAlive  Is SFusion alive?
 * @param uplinkAlive  Is Uplink alive?
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datawatchdog_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,uint8_t allAlive,uint8_t ahrsAlive,uint8_t airAlive,uint8_t ctrlAlive,uint8_t downlinkAlive,uint8_t gpsAlive,uint8_t logAlive,uint8_t psuAlive,uint8_t raiInAlive,uint8_t raiOutAlive,uint8_t sFusionAlive,uint8_t uplinkAlive,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataWatchdog_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, allAlive);
    _mav_put_uint8_t(buf, 9, ahrsAlive);
    _mav_put_uint8_t(buf, 10, airAlive);
    _mav_put_uint8_t(buf, 11, ctrlAlive);
    _mav_put_uint8_t(buf, 12, downlinkAlive);
    _mav_put_uint8_t(buf, 13, gpsAlive);
    _mav_put_uint8_t(buf, 14, logAlive);
    _mav_put_uint8_t(buf, 15, psuAlive);
    _mav_put_uint8_t(buf, 16, raiInAlive);
    _mav_put_uint8_t(buf, 17, raiOutAlive);
    _mav_put_uint8_t(buf, 18, sFusionAlive);
    _mav_put_uint8_t(buf, 19, uplinkAlive);
    _mav_put_uint8_t(buf, 20, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataWatchdog_LEN);
#else
    mavlink_datawatchdog_t packet;
    packet.time = time;
    packet.allAlive = allAlive;
    packet.ahrsAlive = ahrsAlive;
    packet.airAlive = airAlive;
    packet.ctrlAlive = ctrlAlive;
    packet.downlinkAlive = downlinkAlive;
    packet.gpsAlive = gpsAlive;
    packet.logAlive = logAlive;
    packet.psuAlive = psuAlive;
    packet.raiInAlive = raiInAlive;
    packet.raiOutAlive = raiOutAlive;
    packet.sFusionAlive = sFusionAlive;
    packet.uplinkAlive = uplinkAlive;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataWatchdog_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataWatchdog;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
}

/**
 * @brief Encode a datawatchdog struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datawatchdog C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datawatchdog_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datawatchdog_t* datawatchdog)
{
    return mavlink_msg_datawatchdog_pack(system_id, component_id, msg, datawatchdog->time, datawatchdog->allAlive, datawatchdog->ahrsAlive, datawatchdog->airAlive, datawatchdog->ctrlAlive, datawatchdog->downlinkAlive, datawatchdog->gpsAlive, datawatchdog->logAlive, datawatchdog->psuAlive, datawatchdog->raiInAlive, datawatchdog->raiOutAlive, datawatchdog->sFusionAlive, datawatchdog->uplinkAlive, datawatchdog->alive);
}

/**
 * @brief Encode a datawatchdog struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datawatchdog C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datawatchdog_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datawatchdog_t* datawatchdog)
{
    return mavlink_msg_datawatchdog_pack_chan(system_id, component_id, chan, msg, datawatchdog->time, datawatchdog->allAlive, datawatchdog->ahrsAlive, datawatchdog->airAlive, datawatchdog->ctrlAlive, datawatchdog->downlinkAlive, datawatchdog->gpsAlive, datawatchdog->logAlive, datawatchdog->psuAlive, datawatchdog->raiInAlive, datawatchdog->raiOutAlive, datawatchdog->sFusionAlive, datawatchdog->uplinkAlive, datawatchdog->alive);
}

/**
 * @brief Send a datawatchdog message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param allAlive  Are all modules alive?
 * @param ahrsAlive  Is AHRS alive?
 * @param airAlive  Is AIR alive?
 * @param ctrlAlive  Is Ctrl alive?
 * @param downlinkAlive  Is Downlink alive?
 * @param gpsAlive  Is GPS alive?
 * @param logAlive  Is Downlink alive?
 * @param psuAlive  Is PSU alive?
 * @param raiInAlive  Is RaiIn alive?
 * @param raiOutAlive  Is RaiOut alive?
 * @param sFusionAlive  Is SFusion alive?
 * @param uplinkAlive  Is Uplink alive?
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datawatchdog_send(mavlink_channel_t chan, uint64_t time, uint8_t allAlive, uint8_t ahrsAlive, uint8_t airAlive, uint8_t ctrlAlive, uint8_t downlinkAlive, uint8_t gpsAlive, uint8_t logAlive, uint8_t psuAlive, uint8_t raiInAlive, uint8_t raiOutAlive, uint8_t sFusionAlive, uint8_t uplinkAlive, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataWatchdog_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, allAlive);
    _mav_put_uint8_t(buf, 9, ahrsAlive);
    _mav_put_uint8_t(buf, 10, airAlive);
    _mav_put_uint8_t(buf, 11, ctrlAlive);
    _mav_put_uint8_t(buf, 12, downlinkAlive);
    _mav_put_uint8_t(buf, 13, gpsAlive);
    _mav_put_uint8_t(buf, 14, logAlive);
    _mav_put_uint8_t(buf, 15, psuAlive);
    _mav_put_uint8_t(buf, 16, raiInAlive);
    _mav_put_uint8_t(buf, 17, raiOutAlive);
    _mav_put_uint8_t(buf, 18, sFusionAlive);
    _mav_put_uint8_t(buf, 19, uplinkAlive);
    _mav_put_uint8_t(buf, 20, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataWatchdog, buf, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
#else
    mavlink_datawatchdog_t packet;
    packet.time = time;
    packet.allAlive = allAlive;
    packet.ahrsAlive = ahrsAlive;
    packet.airAlive = airAlive;
    packet.ctrlAlive = ctrlAlive;
    packet.downlinkAlive = downlinkAlive;
    packet.gpsAlive = gpsAlive;
    packet.logAlive = logAlive;
    packet.psuAlive = psuAlive;
    packet.raiInAlive = raiInAlive;
    packet.raiOutAlive = raiOutAlive;
    packet.sFusionAlive = sFusionAlive;
    packet.uplinkAlive = uplinkAlive;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataWatchdog, (const char *)&packet, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
#endif
}

/**
 * @brief Send a datawatchdog message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datawatchdog_send_struct(mavlink_channel_t chan, const mavlink_datawatchdog_t* datawatchdog)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datawatchdog_send(chan, datawatchdog->time, datawatchdog->allAlive, datawatchdog->ahrsAlive, datawatchdog->airAlive, datawatchdog->ctrlAlive, datawatchdog->downlinkAlive, datawatchdog->gpsAlive, datawatchdog->logAlive, datawatchdog->psuAlive, datawatchdog->raiInAlive, datawatchdog->raiOutAlive, datawatchdog->sFusionAlive, datawatchdog->uplinkAlive, datawatchdog->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataWatchdog, (const char *)datawatchdog, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataWatchdog_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datawatchdog_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, uint8_t allAlive, uint8_t ahrsAlive, uint8_t airAlive, uint8_t ctrlAlive, uint8_t downlinkAlive, uint8_t gpsAlive, uint8_t logAlive, uint8_t psuAlive, uint8_t raiInAlive, uint8_t raiOutAlive, uint8_t sFusionAlive, uint8_t uplinkAlive, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, allAlive);
    _mav_put_uint8_t(buf, 9, ahrsAlive);
    _mav_put_uint8_t(buf, 10, airAlive);
    _mav_put_uint8_t(buf, 11, ctrlAlive);
    _mav_put_uint8_t(buf, 12, downlinkAlive);
    _mav_put_uint8_t(buf, 13, gpsAlive);
    _mav_put_uint8_t(buf, 14, logAlive);
    _mav_put_uint8_t(buf, 15, psuAlive);
    _mav_put_uint8_t(buf, 16, raiInAlive);
    _mav_put_uint8_t(buf, 17, raiOutAlive);
    _mav_put_uint8_t(buf, 18, sFusionAlive);
    _mav_put_uint8_t(buf, 19, uplinkAlive);
    _mav_put_uint8_t(buf, 20, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataWatchdog, buf, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
#else
    mavlink_datawatchdog_t *packet = (mavlink_datawatchdog_t *)msgbuf;
    packet->time = time;
    packet->allAlive = allAlive;
    packet->ahrsAlive = ahrsAlive;
    packet->airAlive = airAlive;
    packet->ctrlAlive = ctrlAlive;
    packet->downlinkAlive = downlinkAlive;
    packet->gpsAlive = gpsAlive;
    packet->logAlive = logAlive;
    packet->psuAlive = psuAlive;
    packet->raiInAlive = raiInAlive;
    packet->raiOutAlive = raiOutAlive;
    packet->sFusionAlive = sFusionAlive;
    packet->uplinkAlive = uplinkAlive;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataWatchdog, (const char *)packet, MAVLINK_MSG_ID_DataWatchdog_MIN_LEN, MAVLINK_MSG_ID_DataWatchdog_LEN, MAVLINK_MSG_ID_DataWatchdog_CRC);
#endif
}
#endif

#endif

// MESSAGE DataWatchdog UNPACKING


/**
 * @brief Get field time from datawatchdog message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datawatchdog_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field allAlive from datawatchdog message
 *
 * @return  Are all modules alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_allAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ahrsAlive from datawatchdog message
 *
 * @return  Is AHRS alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_ahrsAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field airAlive from datawatchdog message
 *
 * @return  Is AIR alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_airAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field ctrlAlive from datawatchdog message
 *
 * @return  Is Ctrl alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_ctrlAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field downlinkAlive from datawatchdog message
 *
 * @return  Is Downlink alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_downlinkAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field gpsAlive from datawatchdog message
 *
 * @return  Is GPS alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_gpsAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field logAlive from datawatchdog message
 *
 * @return  Is Downlink alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_logAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field psuAlive from datawatchdog message
 *
 * @return  Is PSU alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_psuAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field raiInAlive from datawatchdog message
 *
 * @return  Is RaiIn alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_raiInAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field raiOutAlive from datawatchdog message
 *
 * @return  Is RaiOut alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_raiOutAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field sFusionAlive from datawatchdog message
 *
 * @return  Is SFusion alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_sFusionAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field uplinkAlive from datawatchdog message
 *
 * @return  Is Uplink alive?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_uplinkAlive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field alive from datawatchdog message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_datawatchdog_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a datawatchdog message into a struct
 *
 * @param msg The message to decode
 * @param datawatchdog C-struct to decode the message contents into
 */
static inline void mavlink_msg_datawatchdog_decode(const mavlink_message_t* msg, mavlink_datawatchdog_t* datawatchdog)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datawatchdog->time = mavlink_msg_datawatchdog_get_time(msg);
    datawatchdog->allAlive = mavlink_msg_datawatchdog_get_allAlive(msg);
    datawatchdog->ahrsAlive = mavlink_msg_datawatchdog_get_ahrsAlive(msg);
    datawatchdog->airAlive = mavlink_msg_datawatchdog_get_airAlive(msg);
    datawatchdog->ctrlAlive = mavlink_msg_datawatchdog_get_ctrlAlive(msg);
    datawatchdog->downlinkAlive = mavlink_msg_datawatchdog_get_downlinkAlive(msg);
    datawatchdog->gpsAlive = mavlink_msg_datawatchdog_get_gpsAlive(msg);
    datawatchdog->logAlive = mavlink_msg_datawatchdog_get_logAlive(msg);
    datawatchdog->psuAlive = mavlink_msg_datawatchdog_get_psuAlive(msg);
    datawatchdog->raiInAlive = mavlink_msg_datawatchdog_get_raiInAlive(msg);
    datawatchdog->raiOutAlive = mavlink_msg_datawatchdog_get_raiOutAlive(msg);
    datawatchdog->sFusionAlive = mavlink_msg_datawatchdog_get_sFusionAlive(msg);
    datawatchdog->uplinkAlive = mavlink_msg_datawatchdog_get_uplinkAlive(msg);
    datawatchdog->alive = mavlink_msg_datawatchdog_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataWatchdog_LEN? msg->len : MAVLINK_MSG_ID_DataWatchdog_LEN;
        memset(datawatchdog, 0, MAVLINK_MSG_ID_DataWatchdog_LEN);
    memcpy(datawatchdog, _MAV_PAYLOAD(msg), len);
#endif
}
