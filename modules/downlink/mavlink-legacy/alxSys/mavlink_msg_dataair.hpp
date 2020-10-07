// MESSAGE DataAir support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief DataAir message
 *
 * Data from AIR
 */
struct DataAir : mavlink::Message {
    static constexpr msgid_t MSG_ID = 30000;
    static constexpr size_t LENGTH = 29;
    static constexpr size_t MIN_LENGTH = 29;
    static constexpr uint8_t CRC_EXTRA = 111;
    static constexpr auto NAME = "DataAir";


    uint64_t time; /*<  Time. */
    float senseTime; /*<  Sensetime. */
    float TAS; /*<  Velocity (TAS). */
    float baro_air; /*<  Barometric pressure air. */
    float density; /*<  Density. */
    float temp; /*<  Temperature. */
    uint8_t alive; /*<  Alive. */


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
        ss << "  TAS: " << TAS << std::endl;
        ss << "  baro_air: " << baro_air << std::endl;
        ss << "  density: " << density << std::endl;
        ss << "  temp: " << temp << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << TAS;                           // offset: 12
        map << baro_air;                      // offset: 16
        map << density;                       // offset: 20
        map << temp;                          // offset: 24
        map << alive;                         // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> TAS;                           // offset: 12
        map >> baro_air;                      // offset: 16
        map >> density;                       // offset: 20
        map >> temp;                          // offset: 24
        map >> alive;                         // offset: 28
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
