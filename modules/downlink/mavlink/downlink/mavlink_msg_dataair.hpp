// MESSAGE DataAir support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataAir message
 *
 * Data from Air
 */
struct DataAir : mavlink::Message {
    static constexpr msgid_t MSG_ID = 30000;
    static constexpr size_t LENGTH = 41;
    static constexpr size_t MIN_LENGTH = 41;
    static constexpr uint8_t CRC_EXTRA = 215;
    static constexpr auto NAME = "DataAir";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float dynamic_pressure; /*<  Dynamic Pressure */
    float true_airspeed; /*<  TAS */
    float indicated_airspeed; /*<  IAS */
    float barometric_pressure; /*<  Barometric pressure */
    float barometric_height; /*<  Barometric height */
    float density; /*<  Density */
    float temperature; /*<  Temperature */
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
        ss << "  dynamic_pressure: " << dynamic_pressure << std::endl;
        ss << "  true_airspeed: " << true_airspeed << std::endl;
        ss << "  indicated_airspeed: " << indicated_airspeed << std::endl;
        ss << "  barometric_pressure: " << barometric_pressure << std::endl;
        ss << "  barometric_height: " << barometric_height << std::endl;
        ss << "  density: " << density << std::endl;
        ss << "  temperature: " << temperature << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << dynamic_pressure;              // offset: 12
        map << true_airspeed;                 // offset: 16
        map << indicated_airspeed;            // offset: 20
        map << barometric_pressure;           // offset: 24
        map << barometric_height;             // offset: 28
        map << density;                       // offset: 32
        map << temperature;                   // offset: 36
        map << alive;                         // offset: 40
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> dynamic_pressure;              // offset: 12
        map >> true_airspeed;                 // offset: 16
        map >> indicated_airspeed;            // offset: 20
        map >> barometric_pressure;           // offset: 24
        map >> barometric_height;             // offset: 28
        map >> density;                       // offset: 32
        map >> temperature;                   // offset: 36
        map >> alive;                         // offset: 40
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
