// MESSAGE DataAhrs support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataAhrs message
 *
 * Data from Ahrs
 */
struct DataAhrs : mavlink::Message {
    static constexpr msgid_t MSG_ID = 20000;
    static constexpr size_t LENGTH = 69;
    static constexpr size_t MIN_LENGTH = 69;
    static constexpr uint8_t CRC_EXTRA = 55;
    static constexpr auto NAME = "DataAhrs";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float gyrX; /*<  Gyro X-Axis */
    float gyrY; /*<  Gyro Y-Axis */
    float gyrZ; /*<  Gyro Z-Axis */
    float accX; /*<  Accelerometer X-Axis */
    float accY; /*<  Accelerometer Y-Axis */
    float accZ; /*<  Accelerometer Z-Axis */
    float magX; /*<  Magnetometer X-Axis */
    float magY; /*<  Magnetometer Y-Axis */
    float magZ; /*<  Magnetometer Z-Axis */
    float temperature; /*<  Temperature */
    float barometric_pressure; /*<  Barometric pressure */
    float phi; /*<  Phi */
    float the; /*<  Theta */
    float psi; /*<  Psi */
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
        ss << "  senseTime: " << senseTime << std::endl;
        ss << "  gyrX: " << gyrX << std::endl;
        ss << "  gyrY: " << gyrY << std::endl;
        ss << "  gyrZ: " << gyrZ << std::endl;
        ss << "  accX: " << accX << std::endl;
        ss << "  accY: " << accY << std::endl;
        ss << "  accZ: " << accZ << std::endl;
        ss << "  magX: " << magX << std::endl;
        ss << "  magY: " << magY << std::endl;
        ss << "  magZ: " << magZ << std::endl;
        ss << "  temperature: " << temperature << std::endl;
        ss << "  barometric_pressure: " << barometric_pressure << std::endl;
        ss << "  phi: " << phi << std::endl;
        ss << "  the: " << the << std::endl;
        ss << "  psi: " << psi << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << gyrX;                          // offset: 12
        map << gyrY;                          // offset: 16
        map << gyrZ;                          // offset: 20
        map << accX;                          // offset: 24
        map << accY;                          // offset: 28
        map << accZ;                          // offset: 32
        map << magX;                          // offset: 36
        map << magY;                          // offset: 40
        map << magZ;                          // offset: 44
        map << temperature;                   // offset: 48
        map << barometric_pressure;           // offset: 52
        map << phi;                           // offset: 56
        map << the;                           // offset: 60
        map << psi;                           // offset: 64
        map << alive;                         // offset: 68
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> gyrX;                          // offset: 12
        map >> gyrY;                          // offset: 16
        map >> gyrZ;                          // offset: 20
        map >> accX;                          // offset: 24
        map >> accY;                          // offset: 28
        map >> accZ;                          // offset: 32
        map >> magX;                          // offset: 36
        map >> magY;                          // offset: 40
        map >> magZ;                          // offset: 44
        map >> temperature;                   // offset: 48
        map >> barometric_pressure;           // offset: 52
        map >> phi;                           // offset: 56
        map >> the;                           // offset: 60
        map >> psi;                           // offset: 64
        map >> alive;                         // offset: 68
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
