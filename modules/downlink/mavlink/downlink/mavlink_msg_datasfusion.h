#pragma once
// MESSAGE DataSFusion PACKING

#define MAVLINK_MSG_ID_DataSFusion 40000


typedef struct __mavlink_datasfusion_t {
 uint64_t time; /*<  System time at publication*/
 double latitude; /*<  Latitude*/
 double longitude; /*<  Longitude*/
 float p; /*<  Gyro X-Axis*/
 float q; /*<  Gyro Y-Axis*/
 float r; /*<  Gyro Z-Axis*/
 float a_x; /*<  Accelerometer X-Axis*/
 float a_y; /*<  Accelerometer Y-Axis*/
 float a_z; /*<  Accelerometer Z-Axis*/
 float true_airspeed; /*<  Magnetometer X-Axis*/
 float indicated_airspeed; /*<  Magnetometer Y-Axis*/
 float density; /*<  Magnetometer Z-Axis*/
 float dynamic_pressure; /*<  Temperature*/
 float barometric_pressure; /*<  Barometric pressure*/
 float height_rate; /*<  Heightrate*/
 float height; /*<  Height*/
 float ssa; /*<  Sideslip angle*/
 float aoa; /*<  Angle of Attack*/
 float gamma; /*<  Flightpath angle*/
 float phi; /*<  Phi*/
 float the; /*<  Theta*/
 float psi; /*<  Psi*/
 float posN; /*<  Position north estimation*/
 float posE; /*<  Position east estimation*/
 float posD; /*<  Position down estimation*/
 float speedN; /*<  Speed north estimation*/
 float speedE; /*<  Speed east estimation*/
 float speedD; /*<  Speed down estimation*/
 float windN; /*<  Wind north estimation*/
 float windE; /*<  Wind east estimation*/
 float windD; /*<  Wind down estimation*/
 uint8_t alive; /*<  Is Module alive?*/
} mavlink_datasfusion_t;

#define MAVLINK_MSG_ID_DataSFusion_LEN 137
#define MAVLINK_MSG_ID_DataSFusion_MIN_LEN 137
#define MAVLINK_MSG_ID_40000_LEN 137
#define MAVLINK_MSG_ID_40000_MIN_LEN 137

#define MAVLINK_MSG_ID_DataSFusion_CRC 180
#define MAVLINK_MSG_ID_40000_CRC 180



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataSFusion { \
    40000, \
    "DataSFusion", \
    32, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "p", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, p) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, q) }, \
         { "r", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, r) }, \
         { "a_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, a_x) }, \
         { "a_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, a_y) }, \
         { "a_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, a_z) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, true_airspeed) }, \
         { "indicated_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, indicated_airspeed) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, density) }, \
         { "dynamic_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, dynamic_pressure) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, barometric_pressure) }, \
         { "height_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, height_rate) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, height) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_datasfusion_t, psi) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_datasfusion_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_datasfusion_t, longitude) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 116, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 120, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "windN", NULL, MAVLINK_TYPE_FLOAT, 0, 124, offsetof(mavlink_datasfusion_t, windN) }, \
         { "windE", NULL, MAVLINK_TYPE_FLOAT, 0, 128, offsetof(mavlink_datasfusion_t, windE) }, \
         { "windD", NULL, MAVLINK_TYPE_FLOAT, 0, 132, offsetof(mavlink_datasfusion_t, windD) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 136, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataSFusion { \
    "DataSFusion", \
    32, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "p", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, p) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, q) }, \
         { "r", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, r) }, \
         { "a_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, a_x) }, \
         { "a_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, a_y) }, \
         { "a_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, a_z) }, \
         { "true_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, true_airspeed) }, \
         { "indicated_airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, indicated_airspeed) }, \
         { "density", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, density) }, \
         { "dynamic_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, dynamic_pressure) }, \
         { "barometric_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, barometric_pressure) }, \
         { "height_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, height_rate) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, height) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_datasfusion_t, psi) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_datasfusion_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_datasfusion_t, longitude) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 116, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 120, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "windN", NULL, MAVLINK_TYPE_FLOAT, 0, 124, offsetof(mavlink_datasfusion_t, windN) }, \
         { "windE", NULL, MAVLINK_TYPE_FLOAT, 0, 128, offsetof(mavlink_datasfusion_t, windE) }, \
         { "windD", NULL, MAVLINK_TYPE_FLOAT, 0, 132, offsetof(mavlink_datasfusion_t, windD) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 136, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datasfusion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param p  Gyro X-Axis
 * @param q  Gyro Y-Axis
 * @param r  Gyro Z-Axis
 * @param a_x  Accelerometer X-Axis
 * @param a_y  Accelerometer Y-Axis
 * @param a_z  Accelerometer Z-Axis
 * @param true_airspeed  Magnetometer X-Axis
 * @param indicated_airspeed  Magnetometer Y-Axis
 * @param density  Magnetometer Z-Axis
 * @param dynamic_pressure  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param height_rate  Heightrate
 * @param height  Height
 * @param ssa  Sideslip angle
 * @param aoa  Angle of Attack
 * @param gamma  Flightpath angle
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param latitude  Latitude
 * @param longitude  Longitude
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param windN  Wind north estimation
 * @param windE  Wind east estimation
 * @param windD  Wind down estimation
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float p, float q, float r, float a_x, float a_y, float a_z, float true_airspeed, float indicated_airspeed, float density, float dynamic_pressure, float barometric_pressure, float height_rate, float height, float ssa, float aoa, float gamma, float phi, float the, float psi, double latitude, double longitude, float posN, float posE, float posD, float speedN, float speedE, float speedD, float windN, float windE, float windD, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_float(buf, 24, p);
    _mav_put_float(buf, 28, q);
    _mav_put_float(buf, 32, r);
    _mav_put_float(buf, 36, a_x);
    _mav_put_float(buf, 40, a_y);
    _mav_put_float(buf, 44, a_z);
    _mav_put_float(buf, 48, true_airspeed);
    _mav_put_float(buf, 52, indicated_airspeed);
    _mav_put_float(buf, 56, density);
    _mav_put_float(buf, 60, dynamic_pressure);
    _mav_put_float(buf, 64, barometric_pressure);
    _mav_put_float(buf, 68, height_rate);
    _mav_put_float(buf, 72, height);
    _mav_put_float(buf, 76, ssa);
    _mav_put_float(buf, 80, aoa);
    _mav_put_float(buf, 84, gamma);
    _mav_put_float(buf, 88, phi);
    _mav_put_float(buf, 92, the);
    _mav_put_float(buf, 96, psi);
    _mav_put_float(buf, 100, posN);
    _mav_put_float(buf, 104, posE);
    _mav_put_float(buf, 108, posD);
    _mav_put_float(buf, 112, speedN);
    _mav_put_float(buf, 116, speedE);
    _mav_put_float(buf, 120, speedD);
    _mav_put_float(buf, 124, windN);
    _mav_put_float(buf, 128, windE);
    _mav_put_float(buf, 132, windD);
    _mav_put_uint8_t(buf, 136, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSFusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.p = p;
    packet.q = q;
    packet.r = r;
    packet.a_x = a_x;
    packet.a_y = a_y;
    packet.a_z = a_z;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.density = density;
    packet.dynamic_pressure = dynamic_pressure;
    packet.barometric_pressure = barometric_pressure;
    packet.height_rate = height_rate;
    packet.height = height;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.windN = windN;
    packet.windE = windE;
    packet.windD = windD;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSFusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSFusion;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
}

/**
 * @brief Pack a datasfusion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param p  Gyro X-Axis
 * @param q  Gyro Y-Axis
 * @param r  Gyro Z-Axis
 * @param a_x  Accelerometer X-Axis
 * @param a_y  Accelerometer Y-Axis
 * @param a_z  Accelerometer Z-Axis
 * @param true_airspeed  Magnetometer X-Axis
 * @param indicated_airspeed  Magnetometer Y-Axis
 * @param density  Magnetometer Z-Axis
 * @param dynamic_pressure  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param height_rate  Heightrate
 * @param height  Height
 * @param ssa  Sideslip angle
 * @param aoa  Angle of Attack
 * @param gamma  Flightpath angle
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param latitude  Latitude
 * @param longitude  Longitude
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param windN  Wind north estimation
 * @param windE  Wind east estimation
 * @param windD  Wind down estimation
 * @param alive  Is Module alive?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float p,float q,float r,float a_x,float a_y,float a_z,float true_airspeed,float indicated_airspeed,float density,float dynamic_pressure,float barometric_pressure,float height_rate,float height,float ssa,float aoa,float gamma,float phi,float the,float psi,double latitude,double longitude,float posN,float posE,float posD,float speedN,float speedE,float speedD,float windN,float windE,float windD,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_float(buf, 24, p);
    _mav_put_float(buf, 28, q);
    _mav_put_float(buf, 32, r);
    _mav_put_float(buf, 36, a_x);
    _mav_put_float(buf, 40, a_y);
    _mav_put_float(buf, 44, a_z);
    _mav_put_float(buf, 48, true_airspeed);
    _mav_put_float(buf, 52, indicated_airspeed);
    _mav_put_float(buf, 56, density);
    _mav_put_float(buf, 60, dynamic_pressure);
    _mav_put_float(buf, 64, barometric_pressure);
    _mav_put_float(buf, 68, height_rate);
    _mav_put_float(buf, 72, height);
    _mav_put_float(buf, 76, ssa);
    _mav_put_float(buf, 80, aoa);
    _mav_put_float(buf, 84, gamma);
    _mav_put_float(buf, 88, phi);
    _mav_put_float(buf, 92, the);
    _mav_put_float(buf, 96, psi);
    _mav_put_float(buf, 100, posN);
    _mav_put_float(buf, 104, posE);
    _mav_put_float(buf, 108, posD);
    _mav_put_float(buf, 112, speedN);
    _mav_put_float(buf, 116, speedE);
    _mav_put_float(buf, 120, speedD);
    _mav_put_float(buf, 124, windN);
    _mav_put_float(buf, 128, windE);
    _mav_put_float(buf, 132, windD);
    _mav_put_uint8_t(buf, 136, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSFusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.p = p;
    packet.q = q;
    packet.r = r;
    packet.a_x = a_x;
    packet.a_y = a_y;
    packet.a_z = a_z;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.density = density;
    packet.dynamic_pressure = dynamic_pressure;
    packet.barometric_pressure = barometric_pressure;
    packet.height_rate = height_rate;
    packet.height = height;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.windN = windN;
    packet.windE = windE;
    packet.windD = windD;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSFusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSFusion;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
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
    return mavlink_msg_datasfusion_pack(system_id, component_id, msg, datasfusion->time, datasfusion->p, datasfusion->q, datasfusion->r, datasfusion->a_x, datasfusion->a_y, datasfusion->a_z, datasfusion->true_airspeed, datasfusion->indicated_airspeed, datasfusion->density, datasfusion->dynamic_pressure, datasfusion->barometric_pressure, datasfusion->height_rate, datasfusion->height, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->latitude, datasfusion->longitude, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->windN, datasfusion->windE, datasfusion->windD, datasfusion->alive);
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
    return mavlink_msg_datasfusion_pack_chan(system_id, component_id, chan, msg, datasfusion->time, datasfusion->p, datasfusion->q, datasfusion->r, datasfusion->a_x, datasfusion->a_y, datasfusion->a_z, datasfusion->true_airspeed, datasfusion->indicated_airspeed, datasfusion->density, datasfusion->dynamic_pressure, datasfusion->barometric_pressure, datasfusion->height_rate, datasfusion->height, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->latitude, datasfusion->longitude, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->windN, datasfusion->windE, datasfusion->windD, datasfusion->alive);
}

/**
 * @brief Send a datasfusion message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param p  Gyro X-Axis
 * @param q  Gyro Y-Axis
 * @param r  Gyro Z-Axis
 * @param a_x  Accelerometer X-Axis
 * @param a_y  Accelerometer Y-Axis
 * @param a_z  Accelerometer Z-Axis
 * @param true_airspeed  Magnetometer X-Axis
 * @param indicated_airspeed  Magnetometer Y-Axis
 * @param density  Magnetometer Z-Axis
 * @param dynamic_pressure  Temperature
 * @param barometric_pressure  Barometric pressure
 * @param height_rate  Heightrate
 * @param height  Height
 * @param ssa  Sideslip angle
 * @param aoa  Angle of Attack
 * @param gamma  Flightpath angle
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param latitude  Latitude
 * @param longitude  Longitude
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param windN  Wind north estimation
 * @param windE  Wind east estimation
 * @param windD  Wind down estimation
 * @param alive  Is Module alive?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datasfusion_send(mavlink_channel_t chan, uint64_t time, float p, float q, float r, float a_x, float a_y, float a_z, float true_airspeed, float indicated_airspeed, float density, float dynamic_pressure, float barometric_pressure, float height_rate, float height, float ssa, float aoa, float gamma, float phi, float the, float psi, double latitude, double longitude, float posN, float posE, float posD, float speedN, float speedE, float speedD, float windN, float windE, float windD, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_float(buf, 24, p);
    _mav_put_float(buf, 28, q);
    _mav_put_float(buf, 32, r);
    _mav_put_float(buf, 36, a_x);
    _mav_put_float(buf, 40, a_y);
    _mav_put_float(buf, 44, a_z);
    _mav_put_float(buf, 48, true_airspeed);
    _mav_put_float(buf, 52, indicated_airspeed);
    _mav_put_float(buf, 56, density);
    _mav_put_float(buf, 60, dynamic_pressure);
    _mav_put_float(buf, 64, barometric_pressure);
    _mav_put_float(buf, 68, height_rate);
    _mav_put_float(buf, 72, height);
    _mav_put_float(buf, 76, ssa);
    _mav_put_float(buf, 80, aoa);
    _mav_put_float(buf, 84, gamma);
    _mav_put_float(buf, 88, phi);
    _mav_put_float(buf, 92, the);
    _mav_put_float(buf, 96, psi);
    _mav_put_float(buf, 100, posN);
    _mav_put_float(buf, 104, posE);
    _mav_put_float(buf, 108, posD);
    _mav_put_float(buf, 112, speedN);
    _mav_put_float(buf, 116, speedE);
    _mav_put_float(buf, 120, speedD);
    _mav_put_float(buf, 124, windN);
    _mav_put_float(buf, 128, windE);
    _mav_put_float(buf, 132, windD);
    _mav_put_uint8_t(buf, 136, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, buf, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.p = p;
    packet.q = q;
    packet.r = r;
    packet.a_x = a_x;
    packet.a_y = a_y;
    packet.a_z = a_z;
    packet.true_airspeed = true_airspeed;
    packet.indicated_airspeed = indicated_airspeed;
    packet.density = density;
    packet.dynamic_pressure = dynamic_pressure;
    packet.barometric_pressure = barometric_pressure;
    packet.height_rate = height_rate;
    packet.height = height;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.windN = windN;
    packet.windE = windE;
    packet.windD = windD;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)&packet, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
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
    mavlink_msg_datasfusion_send(chan, datasfusion->time, datasfusion->p, datasfusion->q, datasfusion->r, datasfusion->a_x, datasfusion->a_y, datasfusion->a_z, datasfusion->true_airspeed, datasfusion->indicated_airspeed, datasfusion->density, datasfusion->dynamic_pressure, datasfusion->barometric_pressure, datasfusion->height_rate, datasfusion->height, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->latitude, datasfusion->longitude, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->windN, datasfusion->windE, datasfusion->windD, datasfusion->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)datasfusion, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataSFusion_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datasfusion_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float p, float q, float r, float a_x, float a_y, float a_z, float true_airspeed, float indicated_airspeed, float density, float dynamic_pressure, float barometric_pressure, float height_rate, float height, float ssa, float aoa, float gamma, float phi, float the, float psi, double latitude, double longitude, float posN, float posE, float posD, float speedN, float speedE, float speedD, float windN, float windE, float windD, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_float(buf, 24, p);
    _mav_put_float(buf, 28, q);
    _mav_put_float(buf, 32, r);
    _mav_put_float(buf, 36, a_x);
    _mav_put_float(buf, 40, a_y);
    _mav_put_float(buf, 44, a_z);
    _mav_put_float(buf, 48, true_airspeed);
    _mav_put_float(buf, 52, indicated_airspeed);
    _mav_put_float(buf, 56, density);
    _mav_put_float(buf, 60, dynamic_pressure);
    _mav_put_float(buf, 64, barometric_pressure);
    _mav_put_float(buf, 68, height_rate);
    _mav_put_float(buf, 72, height);
    _mav_put_float(buf, 76, ssa);
    _mav_put_float(buf, 80, aoa);
    _mav_put_float(buf, 84, gamma);
    _mav_put_float(buf, 88, phi);
    _mav_put_float(buf, 92, the);
    _mav_put_float(buf, 96, psi);
    _mav_put_float(buf, 100, posN);
    _mav_put_float(buf, 104, posE);
    _mav_put_float(buf, 108, posD);
    _mav_put_float(buf, 112, speedN);
    _mav_put_float(buf, 116, speedE);
    _mav_put_float(buf, 120, speedD);
    _mav_put_float(buf, 124, windN);
    _mav_put_float(buf, 128, windE);
    _mav_put_float(buf, 132, windD);
    _mav_put_uint8_t(buf, 136, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, buf, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#else
    mavlink_datasfusion_t *packet = (mavlink_datasfusion_t *)msgbuf;
    packet->time = time;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->p = p;
    packet->q = q;
    packet->r = r;
    packet->a_x = a_x;
    packet->a_y = a_y;
    packet->a_z = a_z;
    packet->true_airspeed = true_airspeed;
    packet->indicated_airspeed = indicated_airspeed;
    packet->density = density;
    packet->dynamic_pressure = dynamic_pressure;
    packet->barometric_pressure = barometric_pressure;
    packet->height_rate = height_rate;
    packet->height = height;
    packet->ssa = ssa;
    packet->aoa = aoa;
    packet->gamma = gamma;
    packet->phi = phi;
    packet->the = the;
    packet->psi = psi;
    packet->posN = posN;
    packet->posE = posE;
    packet->posD = posD;
    packet->speedN = speedN;
    packet->speedE = speedE;
    packet->speedD = speedD;
    packet->windN = windN;
    packet->windE = windE;
    packet->windD = windD;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)packet, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#endif
}
#endif

#endif

// MESSAGE DataSFusion UNPACKING


/**
 * @brief Get field time from datasfusion message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datasfusion_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field p from datasfusion message
 *
 * @return  Gyro X-Axis
 */
static inline float mavlink_msg_datasfusion_get_p(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field q from datasfusion message
 *
 * @return  Gyro Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_q(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field r from datasfusion message
 *
 * @return  Gyro Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field a_x from datasfusion message
 *
 * @return  Accelerometer X-Axis
 */
static inline float mavlink_msg_datasfusion_get_a_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field a_y from datasfusion message
 *
 * @return  Accelerometer Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_a_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field a_z from datasfusion message
 *
 * @return  Accelerometer Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_a_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field true_airspeed from datasfusion message
 *
 * @return  Magnetometer X-Axis
 */
static inline float mavlink_msg_datasfusion_get_true_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field indicated_airspeed from datasfusion message
 *
 * @return  Magnetometer Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_indicated_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field density from datasfusion message
 *
 * @return  Magnetometer Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_density(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field dynamic_pressure from datasfusion message
 *
 * @return  Temperature
 */
static inline float mavlink_msg_datasfusion_get_dynamic_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field barometric_pressure from datasfusion message
 *
 * @return  Barometric pressure
 */
static inline float mavlink_msg_datasfusion_get_barometric_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field height_rate from datasfusion message
 *
 * @return  Heightrate
 */
static inline float mavlink_msg_datasfusion_get_height_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field height from datasfusion message
 *
 * @return  Height
 */
static inline float mavlink_msg_datasfusion_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field ssa from datasfusion message
 *
 * @return  Sideslip angle
 */
static inline float mavlink_msg_datasfusion_get_ssa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field aoa from datasfusion message
 *
 * @return  Angle of Attack
 */
static inline float mavlink_msg_datasfusion_get_aoa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field gamma from datasfusion message
 *
 * @return  Flightpath angle
 */
static inline float mavlink_msg_datasfusion_get_gamma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field phi from datasfusion message
 *
 * @return  Phi
 */
static inline float mavlink_msg_datasfusion_get_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field the from datasfusion message
 *
 * @return  Theta
 */
static inline float mavlink_msg_datasfusion_get_the(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Get field psi from datasfusion message
 *
 * @return  Psi
 */
static inline float mavlink_msg_datasfusion_get_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  96);
}

/**
 * @brief Get field latitude from datasfusion message
 *
 * @return  Latitude
 */
static inline double mavlink_msg_datasfusion_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field longitude from datasfusion message
 *
 * @return  Longitude
 */
static inline double mavlink_msg_datasfusion_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field posN from datasfusion message
 *
 * @return  Position north estimation
 */
static inline float mavlink_msg_datasfusion_get_posN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  100);
}

/**
 * @brief Get field posE from datasfusion message
 *
 * @return  Position east estimation
 */
static inline float mavlink_msg_datasfusion_get_posE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  104);
}

/**
 * @brief Get field posD from datasfusion message
 *
 * @return  Position down estimation
 */
static inline float mavlink_msg_datasfusion_get_posD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  108);
}

/**
 * @brief Get field speedN from datasfusion message
 *
 * @return  Speed north estimation
 */
static inline float mavlink_msg_datasfusion_get_speedN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  112);
}

/**
 * @brief Get field speedE from datasfusion message
 *
 * @return  Speed east estimation
 */
static inline float mavlink_msg_datasfusion_get_speedE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  116);
}

/**
 * @brief Get field speedD from datasfusion message
 *
 * @return  Speed down estimation
 */
static inline float mavlink_msg_datasfusion_get_speedD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  120);
}

/**
 * @brief Get field windN from datasfusion message
 *
 * @return  Wind north estimation
 */
static inline float mavlink_msg_datasfusion_get_windN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  124);
}

/**
 * @brief Get field windE from datasfusion message
 *
 * @return  Wind east estimation
 */
static inline float mavlink_msg_datasfusion_get_windE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  128);
}

/**
 * @brief Get field windD from datasfusion message
 *
 * @return  Wind down estimation
 */
static inline float mavlink_msg_datasfusion_get_windD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  132);
}

/**
 * @brief Get field alive from datasfusion message
 *
 * @return  Is Module alive?
 */
static inline uint8_t mavlink_msg_datasfusion_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  136);
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
    datasfusion->latitude = mavlink_msg_datasfusion_get_latitude(msg);
    datasfusion->longitude = mavlink_msg_datasfusion_get_longitude(msg);
    datasfusion->p = mavlink_msg_datasfusion_get_p(msg);
    datasfusion->q = mavlink_msg_datasfusion_get_q(msg);
    datasfusion->r = mavlink_msg_datasfusion_get_r(msg);
    datasfusion->a_x = mavlink_msg_datasfusion_get_a_x(msg);
    datasfusion->a_y = mavlink_msg_datasfusion_get_a_y(msg);
    datasfusion->a_z = mavlink_msg_datasfusion_get_a_z(msg);
    datasfusion->true_airspeed = mavlink_msg_datasfusion_get_true_airspeed(msg);
    datasfusion->indicated_airspeed = mavlink_msg_datasfusion_get_indicated_airspeed(msg);
    datasfusion->density = mavlink_msg_datasfusion_get_density(msg);
    datasfusion->dynamic_pressure = mavlink_msg_datasfusion_get_dynamic_pressure(msg);
    datasfusion->barometric_pressure = mavlink_msg_datasfusion_get_barometric_pressure(msg);
    datasfusion->height_rate = mavlink_msg_datasfusion_get_height_rate(msg);
    datasfusion->height = mavlink_msg_datasfusion_get_height(msg);
    datasfusion->ssa = mavlink_msg_datasfusion_get_ssa(msg);
    datasfusion->aoa = mavlink_msg_datasfusion_get_aoa(msg);
    datasfusion->gamma = mavlink_msg_datasfusion_get_gamma(msg);
    datasfusion->phi = mavlink_msg_datasfusion_get_phi(msg);
    datasfusion->the = mavlink_msg_datasfusion_get_the(msg);
    datasfusion->psi = mavlink_msg_datasfusion_get_psi(msg);
    datasfusion->posN = mavlink_msg_datasfusion_get_posN(msg);
    datasfusion->posE = mavlink_msg_datasfusion_get_posE(msg);
    datasfusion->posD = mavlink_msg_datasfusion_get_posD(msg);
    datasfusion->speedN = mavlink_msg_datasfusion_get_speedN(msg);
    datasfusion->speedE = mavlink_msg_datasfusion_get_speedE(msg);
    datasfusion->speedD = mavlink_msg_datasfusion_get_speedD(msg);
    datasfusion->windN = mavlink_msg_datasfusion_get_windN(msg);
    datasfusion->windE = mavlink_msg_datasfusion_get_windE(msg);
    datasfusion->windD = mavlink_msg_datasfusion_get_windD(msg);
    datasfusion->alive = mavlink_msg_datasfusion_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataSFusion_LEN? msg->len : MAVLINK_MSG_ID_DataSFusion_LEN;
        memset(datasfusion, 0, MAVLINK_MSG_ID_DataSFusion_LEN);
    memcpy(datasfusion, _MAV_PAYLOAD(msg), len);
#endif
}
