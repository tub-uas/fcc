// MESSAGE AHRS support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief AHRS message
 *
 * Data from AHRS
 */
struct AHRS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 20000;
    static constexpr size_t LENGTH = 53;
    static constexpr size_t MIN_LENGTH = 53;
    static constexpr uint8_t CRC_EXTRA = 126;
    static constexpr auto NAME = "AHRS";


    int32_t timestamp; /*<  Timestamp. */
    float gX; /*<  gyro X-axis. */
    float gY; /*<  gyro Y-axis. */
    float gZ; /*<  gyro Z-axis. */
    float aX; /*<  accl X-axis. */
    float aY; /*<  accl Y-axis. */
    float aZ; /*<  accl Z-axis. */
    float mX; /*<  magn X-axis. */
    float mY; /*<  magn Y-axis. */
    float mZ; /*<  magn Z-axis. */
    float Phi; /*<  Phi. */
    float Tht; /*<  Theta. */
    float Psi; /*<  Psi. */
    uint8_t alive; /*<  AHRS alive. */


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
        ss << "  timestamp: " << timestamp << std::endl;
        ss << "  gX: " << gX << std::endl;
        ss << "  gY: " << gY << std::endl;
        ss << "  gZ: " << gZ << std::endl;
        ss << "  aX: " << aX << std::endl;
        ss << "  aY: " << aY << std::endl;
        ss << "  aZ: " << aZ << std::endl;
        ss << "  mX: " << mX << std::endl;
        ss << "  mY: " << mY << std::endl;
        ss << "  mZ: " << mZ << std::endl;
        ss << "  Phi: " << Phi << std::endl;
        ss << "  Tht: " << Tht << std::endl;
        ss << "  Psi: " << Psi << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << gX;                            // offset: 4
        map << gY;                            // offset: 8
        map << gZ;                            // offset: 12
        map << aX;                            // offset: 16
        map << aY;                            // offset: 20
        map << aZ;                            // offset: 24
        map << mX;                            // offset: 28
        map << mY;                            // offset: 32
        map << mZ;                            // offset: 36
        map << Phi;                           // offset: 40
        map << Tht;                           // offset: 44
        map << Psi;                           // offset: 48
        map << alive;                         // offset: 52
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> gX;                            // offset: 4
        map >> gY;                            // offset: 8
        map >> gZ;                            // offset: 12
        map >> aX;                            // offset: 16
        map >> aY;                            // offset: 20
        map >> aZ;                            // offset: 24
        map >> mX;                            // offset: 28
        map >> mY;                            // offset: 32
        map >> mZ;                            // offset: 36
        map >> Phi;                           // offset: 40
        map >> Tht;                           // offset: 44
        map >> Psi;                           // offset: 48
        map >> alive;                         // offset: 52
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
