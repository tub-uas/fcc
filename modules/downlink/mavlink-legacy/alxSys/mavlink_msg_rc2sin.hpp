// MESSAGE RC2SIN support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief RC2SIN message
 *
 * Data from rc2s in
 */
struct RC2SIN : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10000;
    static constexpr size_t LENGTH = 18;
    static constexpr size_t MIN_LENGTH = 18;
    static constexpr uint8_t CRC_EXTRA = 176;
    static constexpr auto NAME = "RC2SIN";


    float setPoint_aill; /*<  Setpoint ailleron. */
    float setPoint_elev; /*<  Setpoint elevator. */
    float setPoint_rudd; /*<  Setpoint rudder. */
    float setPoint_thrt; /*<  Setpoint thrust. */
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
        ss << "  setPoint_rudd: " << setPoint_rudd << std::endl;
        ss << "  setPoint_thrt: " << setPoint_thrt << std::endl;
        ss << "  control_law: " << control_law << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << setPoint_aill;                 // offset: 0
        map << setPoint_elev;                 // offset: 4
        map << setPoint_rudd;                 // offset: 8
        map << setPoint_thrt;                 // offset: 12
        map << control_law;                   // offset: 16
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> setPoint_aill;                 // offset: 0
        map >> setPoint_elev;                 // offset: 4
        map >> setPoint_rudd;                 // offset: 8
        map >> setPoint_thrt;                 // offset: 12
        map >> control_law;                   // offset: 16
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
