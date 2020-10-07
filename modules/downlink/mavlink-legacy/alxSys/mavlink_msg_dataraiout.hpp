// MESSAGE DataRaiOut support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief DataRaiOut message
 *
 * Data from rc2s in
 */
struct DataRaiOut : mavlink::Message {
    static constexpr msgid_t MSG_ID = 15000;
    static constexpr size_t LENGTH = 51;
    static constexpr size_t MIN_LENGTH = 51;
    static constexpr uint8_t CRC_EXTRA = 117;
    static constexpr auto NAME = "DataRaiOut";


    uint64_t time; /*<  Time. */
    std::array<uint16_t, 12> chnls; /*<  Channels. */
    float roll; /*<  Output ailleron. */
    float pitch; /*<  Output elevator. */
    float yaw; /*<  Output rudder. */
    float thr; /*<  Output thrust. */
    uint16_t fltMode; /*<  Flightmode. */
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
        ss << "  chnls: [" << to_string(chnls) << "]" << std::endl;
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
        map << roll;                          // offset: 8
        map << pitch;                         // offset: 12
        map << yaw;                           // offset: 16
        map << thr;                           // offset: 20
        map << chnls;                         // offset: 24
        map << fltMode;                       // offset: 48
        map << alive;                         // offset: 50
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> roll;                          // offset: 8
        map >> pitch;                         // offset: 12
        map >> yaw;                           // offset: 16
        map >> thr;                           // offset: 20
        map >> chnls;                         // offset: 24
        map >> fltMode;                       // offset: 48
        map >> alive;                         // offset: 50
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
