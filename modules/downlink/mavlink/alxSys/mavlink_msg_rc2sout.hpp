// MESSAGE RC2SOUT support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief RC2SOUT message
 *
 * Data from rc2s in
 */
struct RC2SOUT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 15000;
    static constexpr size_t LENGTH = 18;
    static constexpr size_t MIN_LENGTH = 18;
    static constexpr uint8_t CRC_EXTRA = 202;
    static constexpr auto NAME = "RC2SOUT";


    float out_aill; /*<  Output ailleron. */
    float out_elev; /*<  Output elevator. */
    float out_rudd; /*<  Output rudder. */
    float out_thrt; /*<  Output thrust. */
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
        ss << "  out_aill: " << out_aill << std::endl;
        ss << "  out_elev: " << out_elev << std::endl;
        ss << "  out_rudd: " << out_rudd << std::endl;
        ss << "  out_thrt: " << out_thrt << std::endl;
        ss << "  control_law: " << control_law << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << out_aill;                      // offset: 0
        map << out_elev;                      // offset: 4
        map << out_rudd;                      // offset: 8
        map << out_thrt;                      // offset: 12
        map << control_law;                   // offset: 16
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> out_aill;                      // offset: 0
        map >> out_elev;                      // offset: 4
        map >> out_rudd;                      // offset: 8
        map >> out_thrt;                      // offset: 12
        map >> control_law;                   // offset: 16
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
