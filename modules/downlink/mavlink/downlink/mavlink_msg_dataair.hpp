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
    static constexpr size_t LENGTH = 33;
    static constexpr size_t MIN_LENGTH = 33;
    static constexpr uint8_t CRC_EXTRA = 175;
    static constexpr auto NAME = "DataAir";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float dynamicPress; /*<  Dynamic Pressure */
    float velocity; /*<  Velocitiy (TAS) */
    float baroPress; /*<  Barometric pressure */
    float density; /*<  Density */
    float temp; /*<  Temperature */
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
        ss << "  dynamicPress: " << dynamicPress << std::endl;
        ss << "  velocity: " << velocity << std::endl;
        ss << "  baroPress: " << baroPress << std::endl;
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
        map << dynamicPress;                  // offset: 12
        map << velocity;                      // offset: 16
        map << baroPress;                     // offset: 20
        map << density;                       // offset: 24
        map << temp;                          // offset: 28
        map << alive;                         // offset: 32
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> dynamicPress;                  // offset: 12
        map >> velocity;                      // offset: 16
        map >> baroPress;                     // offset: 20
        map >> density;                       // offset: 24
        map >> temp;                          // offset: 28
        map >> alive;                         // offset: 32
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
