// MESSAGE SFUSION support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief SFUSION message
 *
 * Data from SFUSION
 */
struct SFUSION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 40000;
    static constexpr size_t LENGTH = 4;
    static constexpr size_t MIN_LENGTH = 4;
    static constexpr uint8_t CRC_EXTRA = 229;
    static constexpr auto NAME = "SFUSION";


    int32_t timestamp; /*<  Timestamp. */


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

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
