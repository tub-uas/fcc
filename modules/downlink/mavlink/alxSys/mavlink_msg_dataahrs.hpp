// MESSAGE DataAhrs support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief DataAhrs message
 *
 * Data from AHRS
 */
struct DataAhrs : mavlink::Message {
    static constexpr msgid_t MSG_ID = 20000;
    static constexpr size_t LENGTH = 85;
    static constexpr size_t MIN_LENGTH = 85;
    static constexpr uint8_t CRC_EXTRA = 106;
    static constexpr auto NAME = "DataAhrs";


    uint64_t time; /*<  Time. */
    float senseTime; /*<  Sensetime. */
    float gX; /*<  gyro X-axis. */
    float gY; /*<  gyro Y-axis. */
    float gZ; /*<  gyro Z-axis. */
    float aX; /*<  accl X-axis. */
    float aY; /*<  accl Y-axis. */
    float aZ; /*<  accl Z-axis. */
    float mX; /*<  magn X-axis. */
    float mY; /*<  magn Y-axis. */
    float mZ; /*<  magn Z-axis. */
    float temp; /*<  Temperature. */
    float baro_ahrs; /*<  Barometric pressure ahrs. */
    float phi; /*<  Phi. */
    float the; /*<  Theta. */
    float psi; /*<  Psi. */
    float q0; /*<  q0. */
    float q1; /*<  q1. */
    float q2; /*<  q2. */
    float q3; /*<  q3. */
    uint8_t alive; /*<  Alive. */


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
        ss << "  gX: " << gX << std::endl;
        ss << "  gY: " << gY << std::endl;
        ss << "  gZ: " << gZ << std::endl;
        ss << "  aX: " << aX << std::endl;
        ss << "  aY: " << aY << std::endl;
        ss << "  aZ: " << aZ << std::endl;
        ss << "  mX: " << mX << std::endl;
        ss << "  mY: " << mY << std::endl;
        ss << "  mZ: " << mZ << std::endl;
        ss << "  temp: " << temp << std::endl;
        ss << "  baro_ahrs: " << baro_ahrs << std::endl;
        ss << "  phi: " << phi << std::endl;
        ss << "  the: " << the << std::endl;
        ss << "  psi: " << psi << std::endl;
        ss << "  q0: " << q0 << std::endl;
        ss << "  q1: " << q1 << std::endl;
        ss << "  q2: " << q2 << std::endl;
        ss << "  q3: " << q3 << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << gX;                            // offset: 12
        map << gY;                            // offset: 16
        map << gZ;                            // offset: 20
        map << aX;                            // offset: 24
        map << aY;                            // offset: 28
        map << aZ;                            // offset: 32
        map << mX;                            // offset: 36
        map << mY;                            // offset: 40
        map << mZ;                            // offset: 44
        map << temp;                          // offset: 48
        map << baro_ahrs;                     // offset: 52
        map << phi;                           // offset: 56
        map << the;                           // offset: 60
        map << psi;                           // offset: 64
        map << q0;                            // offset: 68
        map << q1;                            // offset: 72
        map << q2;                            // offset: 76
        map << q3;                            // offset: 80
        map << alive;                         // offset: 84
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> gX;                            // offset: 12
        map >> gY;                            // offset: 16
        map >> gZ;                            // offset: 20
        map >> aX;                            // offset: 24
        map >> aY;                            // offset: 28
        map >> aZ;                            // offset: 32
        map >> mX;                            // offset: 36
        map >> mY;                            // offset: 40
        map >> mZ;                            // offset: 44
        map >> temp;                          // offset: 48
        map >> baro_ahrs;                     // offset: 52
        map >> phi;                           // offset: 56
        map >> the;                           // offset: 60
        map >> psi;                           // offset: 64
        map >> q0;                            // offset: 68
        map >> q1;                            // offset: 72
        map >> q2;                            // offset: 76
        map >> q3;                            // offset: 80
        map >> alive;                         // offset: 84
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
