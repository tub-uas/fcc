// MESSAGE DataRaiIn support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataRaiIn message
 *
 * Data from RaiIn
 */
struct DataRaiIn : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10000;
    static constexpr size_t LENGTH = 101;
    static constexpr size_t MIN_LENGTH = 101;
    static constexpr uint8_t CRC_EXTRA = 21;
    static constexpr auto NAME = "DataRaiIn";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    std::array<uint16_t, 12> chnl; /*<  Channels with raw PWM values */
    float xi_setpoint; /*<  xi input from pilot (aka. setpoint) */
    float eta_setpoint; /*<  eta input from pilot (aka. setpoint) */
    float zeta_setpoint; /*<  zeta input from pilot (aka. setpoint) */
    float throttle_setpoint; /*<  Throttle input from pilot (aka. setpoint) */
    float flaps_setpoint; /*<  Flaps input from pilot (aka. setpoint) */
    float roll_setpoint; /*<  Roll input from pilot (aka. setpoint) */
    float roll_rate_setpoint; /*<  Rollrate input from pilot (aka. setpoint) */
    float pitch_setpoint; /*<  Pitch input from pilot (aka. setpoint) */
    float pitch_rate_setpoint; /*<  Pitchrate input from pilot (aka. setpoint) */
    float yaw_setpoint; /*<  Yaw input from pilot (aka. setpoint) */
    float yaw_rate_setpoint; /*<  Yaw_rate input from pilot (aka. setpoint) */
    float tas_setpoint; /*<  TAS input from pilot (aka. setpoint) */
    float tas_rate_setpoint; /*<  TAS rate input from pilot (aka. setpoint) */
    float hgt_setpoint; /*<  Hgt input from pilot (aka. setpoint) */
    float hgt_rate_setpoint; /*<  Hgt_rate input from pilot (aka. setpoint) */
    uint16_t flight_mode; /*<  Flightmode set by pilot */
    uint16_t flight_fct; /*<  Flightfunction set by pilot */
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
        ss << "  chnl: [" << to_string(chnl) << "]" << std::endl;
        ss << "  xi_setpoint: " << xi_setpoint << std::endl;
        ss << "  eta_setpoint: " << eta_setpoint << std::endl;
        ss << "  zeta_setpoint: " << zeta_setpoint << std::endl;
        ss << "  throttle_setpoint: " << throttle_setpoint << std::endl;
        ss << "  flaps_setpoint: " << flaps_setpoint << std::endl;
        ss << "  roll_setpoint: " << roll_setpoint << std::endl;
        ss << "  roll_rate_setpoint: " << roll_rate_setpoint << std::endl;
        ss << "  pitch_setpoint: " << pitch_setpoint << std::endl;
        ss << "  pitch_rate_setpoint: " << pitch_rate_setpoint << std::endl;
        ss << "  yaw_setpoint: " << yaw_setpoint << std::endl;
        ss << "  yaw_rate_setpoint: " << yaw_rate_setpoint << std::endl;
        ss << "  tas_setpoint: " << tas_setpoint << std::endl;
        ss << "  tas_rate_setpoint: " << tas_rate_setpoint << std::endl;
        ss << "  hgt_setpoint: " << hgt_setpoint << std::endl;
        ss << "  hgt_rate_setpoint: " << hgt_rate_setpoint << std::endl;
        ss << "  flight_mode: " << flight_mode << std::endl;
        ss << "  flight_fct: " << flight_fct << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << xi_setpoint;                   // offset: 12
        map << eta_setpoint;                  // offset: 16
        map << zeta_setpoint;                 // offset: 20
        map << throttle_setpoint;             // offset: 24
        map << flaps_setpoint;                // offset: 28
        map << roll_setpoint;                 // offset: 32
        map << roll_rate_setpoint;            // offset: 36
        map << pitch_setpoint;                // offset: 40
        map << pitch_rate_setpoint;           // offset: 44
        map << yaw_setpoint;                  // offset: 48
        map << yaw_rate_setpoint;             // offset: 52
        map << tas_setpoint;                  // offset: 56
        map << tas_rate_setpoint;             // offset: 60
        map << hgt_setpoint;                  // offset: 64
        map << hgt_rate_setpoint;             // offset: 68
        map << chnl;                          // offset: 72
        map << flight_mode;                   // offset: 96
        map << flight_fct;                    // offset: 98
        map << alive;                         // offset: 100
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> xi_setpoint;                   // offset: 12
        map >> eta_setpoint;                  // offset: 16
        map >> zeta_setpoint;                 // offset: 20
        map >> throttle_setpoint;             // offset: 24
        map >> flaps_setpoint;                // offset: 28
        map >> roll_setpoint;                 // offset: 32
        map >> roll_rate_setpoint;            // offset: 36
        map >> pitch_setpoint;                // offset: 40
        map >> pitch_rate_setpoint;           // offset: 44
        map >> yaw_setpoint;                  // offset: 48
        map >> yaw_rate_setpoint;             // offset: 52
        map >> tas_setpoint;                  // offset: 56
        map >> tas_rate_setpoint;             // offset: 60
        map >> hgt_setpoint;                  // offset: 64
        map >> hgt_rate_setpoint;             // offset: 68
        map >> chnl;                          // offset: 72
        map >> flight_mode;                   // offset: 96
        map >> flight_fct;                    // offset: 98
        map >> alive;                         // offset: 100
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
