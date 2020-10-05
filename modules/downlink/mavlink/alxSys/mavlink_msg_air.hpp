// MESSAGE AIR support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief AIR message
 *
 * Data from AIR
 */
struct AIR : mavlink::Message {
    static constexpr msgid_t MSG_ID = 30000;
    static constexpr size_t LENGTH = 13;
    static constexpr size_t MIN_LENGTH = 13;
    static constexpr uint8_t CRC_EXTRA = 56;
    static constexpr auto NAME = "AIR";


    int32_t timestamp; /*<  Timestamp. */
    float aspd; /*<  airspeed. */
    float altb; /*<  altitude baro. */
    uint8_t alive; /*<  AIR alive. */


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
        ss << "  aspd: " << aspd << std::endl;
        ss << "  altb: " << altb << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << aspd;                          // offset: 4
        map << altb;                          // offset: 8
        map << alive;                         // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> aspd;                          // offset: 4
        map >> altb;                          // offset: 8
        map >> alive;                         // offset: 12
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
