// MESSAGE DataRaiIn support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief DataRaiIn message
 *
 * Data from rc2s in
 */
struct DataRaiIn : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10000;
    static constexpr size_t LENGTH = 55;
    static constexpr size_t MIN_LENGTH = 55;
    static constexpr uint8_t CRC_EXTRA = 45;
    static constexpr auto NAME = "DataRaiIn";


    uint64_t time; /*<  Time. */
    float senseTime; /*<  Sensetime. */
    std::array<uint16_t, 12> channels; /*<  Channels. */
    float roll; /*<  Setpoint ailleron. */
    float pitch; /*<  Setpoint elevator. */
    float yaw; /*<  Setpoint rudder. */
    float thr; /*<  Setpoint thrust. */
    uint16_t fltmode; /*<  Flightmode. */
    uint8_t alive; /*<   Alive. */


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
        ss << "  channels: [" << to_string(channels) << "]" << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  thr: " << thr << std::endl;
        ss << "  fltmode: " << fltmode << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << roll;                          // offset: 12
        map << pitch;                         // offset: 16
        map << yaw;                           // offset: 20
        map << thr;                           // offset: 24
        map << channels;                      // offset: 28
        map << fltmode;                       // offset: 52
        map << alive;                         // offset: 54
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> roll;                          // offset: 12
        map >> pitch;                         // offset: 16
        map >> yaw;                           // offset: 20
        map >> thr;                           // offset: 24
        map >> channels;                      // offset: 28
        map >> fltmode;                       // offset: 52
        map >> alive;                         // offset: 54
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
