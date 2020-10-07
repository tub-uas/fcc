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
    static constexpr size_t LENGTH = 55;
    static constexpr size_t MIN_LENGTH = 55;
    static constexpr uint8_t CRC_EXTRA = 252;
    static constexpr auto NAME = "DataRaiIn";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    std::array<uint16_t, 12> chnl; /*<  Channels with raw PWM values */
    float roll; /*<  Roll input from pilot (aka. setpoint) */
    float pitch; /*<  Pitch input from pilot (aka. setpoint) */
    float yaw; /*<  Yaw input from pilot (aka. setpoint) */
    float thr; /*<  Thr input from pilot (aka. setpoint) */
    uint16_t fltMode; /*<  Flightmode set by pilot */
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
        ss << "  senseTime: " << senseTime << std::endl;
        ss << "  chnl: [" << to_string(chnl) << "]" << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  thr: " << thr << std::endl;
        ss << "  fltMode: " << fltMode << std::endl;
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
        map << chnl;                          // offset: 28
        map << fltMode;                       // offset: 52
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
        map >> chnl;                          // offset: 28
        map >> fltMode;                       // offset: 52
        map >> alive;                         // offset: 54
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
