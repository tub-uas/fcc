// MESSAGE RC2SPUBLISHER support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief RC2SPUBLISHER message
 *
 * Data from rc2s in
 */
struct RC2SPUBLISHER : mavlink::Message {
    static constexpr msgid_t MSG_ID = 8811;
    static constexpr size_t LENGTH = 10;
    static constexpr size_t MIN_LENGTH = 10;
    static constexpr uint8_t CRC_EXTRA = 215;
    static constexpr auto NAME = "RC2SPUBLISHER";


    float setPoint_aill; /*<  Setpoint ailleron. */
    float setPoint_elev; /*<  Setpoint elevator. */
    int16_t control_law; /*<  Active control law. */


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
        ss << "  setPoint_aill: " << setPoint_aill << std::endl;
        ss << "  setPoint_elev: " << setPoint_elev << std::endl;
        ss << "  control_law: " << control_law << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << setPoint_aill;                 // offset: 0
        map << setPoint_elev;                 // offset: 4
        map << control_law;                   // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> setPoint_aill;                 // offset: 0
        map >> setPoint_elev;                 // offset: 4
        map >> control_law;                   // offset: 8
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
