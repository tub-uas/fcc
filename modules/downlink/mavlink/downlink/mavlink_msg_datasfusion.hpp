// MESSAGE DataSFusion support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataSFusion message
 *
 * Data from SFusion
 */
struct DataSFusion : mavlink::Message {
    static constexpr msgid_t MSG_ID = 40000;
    static constexpr size_t LENGTH = 137;
    static constexpr size_t MIN_LENGTH = 137;
    static constexpr uint8_t CRC_EXTRA = 180;
    static constexpr auto NAME = "DataSFusion";


    uint64_t time; /*<  System time at publication */
    float p; /*<  Gyro X-Axis */
    float q; /*<  Gyro Y-Axis */
    float r; /*<  Gyro Z-Axis */
    float a_x; /*<  Accelerometer X-Axis */
    float a_y; /*<  Accelerometer Y-Axis */
    float a_z; /*<  Accelerometer Z-Axis */
    float true_airspeed; /*<  Magnetometer X-Axis */
    float indicated_airspeed; /*<  Magnetometer Y-Axis */
    float density; /*<  Magnetometer Z-Axis */
    float dynamic_pressure; /*<  Temperature */
    float barometric_pressure; /*<  Barometric pressure */
    float height_rate; /*<  Heightrate */
    float height; /*<  Height */
    float ssa; /*<  Sideslip angle */
    float aoa; /*<  Angle of Attack */
    float gamma; /*<  Flightpath angle */
    float phi; /*<  Phi */
    float the; /*<  Theta */
    float psi; /*<  Psi */
    double latitude; /*<  Latitude */
    double longitude; /*<  Longitude */
    float posN; /*<  Position north estimation */
    float posE; /*<  Position east estimation */
    float posD; /*<  Position down estimation */
    float speedN; /*<  Speed north estimation */
    float speedE; /*<  Speed east estimation */
    float speedD; /*<  Speed down estimation */
    float windN; /*<  Wind north estimation */
    float windE; /*<  Wind east estimation */
    float windD; /*<  Wind down estimation */
    uint8_t alive; /*<  Is Module alive? */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time: " << time << std::endl;
        ss << "  p: " << p << std::endl;
        ss << "  q: " << q << std::endl;
        ss << "  r: " << r << std::endl;
        ss << "  a_x: " << a_x << std::endl;
        ss << "  a_y: " << a_y << std::endl;
        ss << "  a_z: " << a_z << std::endl;
        ss << "  true_airspeed: " << true_airspeed << std::endl;
        ss << "  indicated_airspeed: " << indicated_airspeed << std::endl;
        ss << "  density: " << density << std::endl;
        ss << "  dynamic_pressure: " << dynamic_pressure << std::endl;
        ss << "  barometric_pressure: " << barometric_pressure << std::endl;
        ss << "  height_rate: " << height_rate << std::endl;
        ss << "  height: " << height << std::endl;
        ss << "  ssa: " << ssa << std::endl;
        ss << "  aoa: " << aoa << std::endl;
        ss << "  gamma: " << gamma << std::endl;
        ss << "  phi: " << phi << std::endl;
        ss << "  the: " << the << std::endl;
        ss << "  psi: " << psi << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  longitude: " << longitude << std::endl;
        ss << "  posN: " << posN << std::endl;
        ss << "  posE: " << posE << std::endl;
        ss << "  posD: " << posD << std::endl;
        ss << "  speedN: " << speedN << std::endl;
        ss << "  speedE: " << speedE << std::endl;
        ss << "  speedD: " << speedD << std::endl;
        ss << "  windN: " << windN << std::endl;
        ss << "  windE: " << windE << std::endl;
        ss << "  windD: " << windD << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << latitude;                      // offset: 8
        map << longitude;                     // offset: 16
        map << p;                             // offset: 24
        map << q;                             // offset: 28
        map << r;                             // offset: 32
        map << a_x;                           // offset: 36
        map << a_y;                           // offset: 40
        map << a_z;                           // offset: 44
        map << true_airspeed;                 // offset: 48
        map << indicated_airspeed;            // offset: 52
        map << density;                       // offset: 56
        map << dynamic_pressure;              // offset: 60
        map << barometric_pressure;           // offset: 64
        map << height_rate;                   // offset: 68
        map << height;                        // offset: 72
        map << ssa;                           // offset: 76
        map << aoa;                           // offset: 80
        map << gamma;                         // offset: 84
        map << phi;                           // offset: 88
        map << the;                           // offset: 92
        map << psi;                           // offset: 96
        map << posN;                          // offset: 100
        map << posE;                          // offset: 104
        map << posD;                          // offset: 108
        map << speedN;                        // offset: 112
        map << speedE;                        // offset: 116
        map << speedD;                        // offset: 120
        map << windN;                         // offset: 124
        map << windE;                         // offset: 128
        map << windD;                         // offset: 132
        map << alive;                         // offset: 136
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> latitude;                      // offset: 8
        map >> longitude;                     // offset: 16
        map >> p;                             // offset: 24
        map >> q;                             // offset: 28
        map >> r;                             // offset: 32
        map >> a_x;                           // offset: 36
        map >> a_y;                           // offset: 40
        map >> a_z;                           // offset: 44
        map >> true_airspeed;                 // offset: 48
        map >> indicated_airspeed;            // offset: 52
        map >> density;                       // offset: 56
        map >> dynamic_pressure;              // offset: 60
        map >> barometric_pressure;           // offset: 64
        map >> height_rate;                   // offset: 68
        map >> height;                        // offset: 72
        map >> ssa;                           // offset: 76
        map >> aoa;                           // offset: 80
        map >> gamma;                         // offset: 84
        map >> phi;                           // offset: 88
        map >> the;                           // offset: 92
        map >> psi;                           // offset: 96
        map >> posN;                          // offset: 100
        map >> posE;                          // offset: 104
        map >> posD;                          // offset: 108
        map >> speedN;                        // offset: 112
        map >> speedE;                        // offset: 116
        map >> speedD;                        // offset: 120
        map >> windN;                         // offset: 124
        map >> windE;                         // offset: 128
        map >> windD;                         // offset: 132
        map >> alive;                         // offset: 136
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
