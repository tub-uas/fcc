// MESSAGE DataRaiOut support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataRaiOut message
 *
 * Data from RaiOut
 */
struct DataRaiOut : mavlink::Message {
    static constexpr msgid_t MSG_ID = 15000;
    static constexpr size_t LENGTH = 57;
    static constexpr size_t MIN_LENGTH = 57;
    static constexpr uint8_t CRC_EXTRA = 86;
    static constexpr auto NAME = "DataRaiOut";


    uint64_t time; /*<  System time at publication */
    std::array<uint16_t, 12> chnl; /*<  Channels with raw PWM values */
    float xi_setpoint; /*<  xi command from fcc */
    float eta_setpoint; /*<  eta command from fcc */
    float zeta_setpoint; /*<  zeta command from fcc */
    float throttle_setpoint; /*<  Thr command from fcc */
    float flaps_setpoint; /*<  Flaps command from fcc */
    uint16_t flight_mode; /*<  Flightmode */
    uint16_t flight_fct; /*<  Flightfunction */
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
        ss << "  chnl: [" << to_string(chnl) << "]" << std::endl;
        ss << "  xi_setpoint: " << xi_setpoint << std::endl;
        ss << "  eta_setpoint: " << eta_setpoint << std::endl;
        ss << "  zeta_setpoint: " << zeta_setpoint << std::endl;
        ss << "  throttle_setpoint: " << throttle_setpoint << std::endl;
        ss << "  flaps_setpoint: " << flaps_setpoint << std::endl;
        ss << "  flight_mode: " << flight_mode << std::endl;
        ss << "  flight_fct: " << flight_fct << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << xi_setpoint;                   // offset: 8
        map << eta_setpoint;                  // offset: 12
        map << zeta_setpoint;                 // offset: 16
        map << throttle_setpoint;             // offset: 20
        map << flaps_setpoint;                // offset: 24
        map << chnl;                          // offset: 28
        map << flight_mode;                   // offset: 52
        map << flight_fct;                    // offset: 54
        map << alive;                         // offset: 56
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> xi_setpoint;                   // offset: 8
        map >> eta_setpoint;                  // offset: 12
        map >> zeta_setpoint;                 // offset: 16
        map >> throttle_setpoint;             // offset: 20
        map >> flaps_setpoint;                // offset: 24
        map >> chnl;                          // offset: 28
        map >> flight_mode;                   // offset: 52
        map >> flight_fct;                    // offset: 54
        map >> alive;                         // offset: 56
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
