// MESSAGE DataCtrl support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataCtrl message
 *
 * Data from Ctrl
 */
struct DataCtrl : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50000;
    static constexpr size_t LENGTH = 29;
    static constexpr size_t MIN_LENGTH = 29;
    static constexpr uint8_t CRC_EXTRA = 128;
    static constexpr auto NAME = "DataCtrl";


    uint64_t time; /*<  System time at publication */
    float xi; /*<  Roll (Aileron) */
    float eta; /*<  Pich (Elevator) */
    float zeta; /*<  Yaw (Rudder) */
    float etaT; /*<  Thrust (Throttle) */
    float etaF; /*<  Flaps */
    uint8_t alive; /*<  Is message valid? */


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
        ss << "  xi: " << xi << std::endl;
        ss << "  eta: " << eta << std::endl;
        ss << "  zeta: " << zeta << std::endl;
        ss << "  etaT: " << etaT << std::endl;
        ss << "  etaF: " << etaF << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << xi;                            // offset: 8
        map << eta;                           // offset: 12
        map << zeta;                          // offset: 16
        map << etaT;                          // offset: 20
        map << etaF;                          // offset: 24
        map << alive;                         // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> xi;                            // offset: 8
        map >> eta;                           // offset: 12
        map >> zeta;                          // offset: 16
        map >> etaT;                          // offset: 20
        map >> etaF;                          // offset: 24
        map >> alive;                         // offset: 28
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
