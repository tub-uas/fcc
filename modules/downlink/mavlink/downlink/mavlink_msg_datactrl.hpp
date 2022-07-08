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
    static constexpr size_t LENGTH = 73;
    static constexpr size_t MIN_LENGTH = 73;
    static constexpr uint8_t CRC_EXTRA = 247;
    static constexpr auto NAME = "DataCtrl";


    uint64_t time; /*<  System time at publication */
    float xi_setpoint; /*<  xi controller output (aka. setpoint) */
    float eta_setpoint; /*<  eta controller output (aka. setpoint) */
    float zeta_setpoint; /*<  zeta controller output (aka. setpoint) */
    float throttle_setpoint; /*<  Throttle controller output (aka. setpoint) */
    float flaps_setpoint; /*<  Flaps controller output (aka. setpoint) */
    float roll_setpoint; /*<  Roll controller output (aka. setpoint) */
    float roll_rate_setpoint; /*<  Rollrate controller output (aka. setpoint) */
    float pitch_setpoint; /*<  Pitch controller output (aka. setpoint) */
    float pitch_rate_setpoint; /*<  Pitchrate controller output (aka. setpoint) */
    float yaw_setpoint; /*<  Yaw controller output (aka. setpoint) */
    float yaw_rate_setpoint; /*<  Yaw_rate controller output (aka. setpoint) */
    float tas_setpoint; /*<  TAS controller output (aka. setpoint) */
    float tas_rate_setpoint; /*<  TAS controller output (aka. setpoint) */
    float hgt_setpoint; /*<  Hgt controller output (aka. setpoint) */
    float hgt_rate_setpoint; /*<  Hgt_rate controller output (aka. setpoint) */
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
        map << xi_setpoint;                   // offset: 8
        map << eta_setpoint;                  // offset: 12
        map << zeta_setpoint;                 // offset: 16
        map << throttle_setpoint;             // offset: 20
        map << flaps_setpoint;                // offset: 24
        map << roll_setpoint;                 // offset: 28
        map << roll_rate_setpoint;            // offset: 32
        map << pitch_setpoint;                // offset: 36
        map << pitch_rate_setpoint;           // offset: 40
        map << yaw_setpoint;                  // offset: 44
        map << yaw_rate_setpoint;             // offset: 48
        map << tas_setpoint;                  // offset: 52
        map << tas_rate_setpoint;             // offset: 56
        map << hgt_setpoint;                  // offset: 60
        map << hgt_rate_setpoint;             // offset: 64
        map << flight_mode;                   // offset: 68
        map << flight_fct;                    // offset: 70
        map << alive;                         // offset: 72
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> xi_setpoint;                   // offset: 8
        map >> eta_setpoint;                  // offset: 12
        map >> zeta_setpoint;                 // offset: 16
        map >> throttle_setpoint;             // offset: 20
        map >> flaps_setpoint;                // offset: 24
        map >> roll_setpoint;                 // offset: 28
        map >> roll_rate_setpoint;            // offset: 32
        map >> pitch_setpoint;                // offset: 36
        map >> pitch_rate_setpoint;           // offset: 40
        map >> yaw_setpoint;                  // offset: 44
        map >> yaw_rate_setpoint;             // offset: 48
        map >> tas_setpoint;                  // offset: 52
        map >> tas_rate_setpoint;             // offset: 56
        map >> hgt_setpoint;                  // offset: 60
        map >> hgt_rate_setpoint;             // offset: 64
        map >> flight_mode;                   // offset: 68
        map >> flight_fct;                    // offset: 70
        map >> alive;                         // offset: 72
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
