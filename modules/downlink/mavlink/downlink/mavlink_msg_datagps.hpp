// MESSAGE DataGps support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataGps message
 *
 * Data fromGps
 */
struct DataGps : mavlink::Message {
    static constexpr msgid_t MSG_ID = 80000;
    static constexpr size_t LENGTH = 61;
    static constexpr size_t MIN_LENGTH = 61;
    static constexpr uint8_t CRC_EXTRA = 161;
    static constexpr auto NAME = "DataGps";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float latitude; /*<  Latitude in deg */
    float longitude; /*<  Longitude in deg */
    float alt_msl; /*<  Altitude in m */
    float groundspeed; /*<  Speed in m/s */
    float course_over_ground; /*<  Course over ground in deg */
    float sats; /*<  Number of satellites currently using */
    float sats_in_view; /*<  Number of satellites in view */
    float fix; /*<  0=No fix, 1=Fix, 2=Differential fix */
    float fix_mode; /*<  1=No fix, 2=2D fix, 3=3D fix */
    float dop_position; /*<  Positional dilution of precision */
    float dop_horizontal; /*<  Horizontal dilution of precision */
    float dop_velocity; /*<  Vertical dilution of precision */
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
        ss << "  latitude: " << latitude << std::endl;
        ss << "  longitude: " << longitude << std::endl;
        ss << "  alt_msl: " << alt_msl << std::endl;
        ss << "  groundspeed: " << groundspeed << std::endl;
        ss << "  course_over_ground: " << course_over_ground << std::endl;
        ss << "  sats: " << sats << std::endl;
        ss << "  sats_in_view: " << sats_in_view << std::endl;
        ss << "  fix: " << fix << std::endl;
        ss << "  fix_mode: " << fix_mode << std::endl;
        ss << "  dop_position: " << dop_position << std::endl;
        ss << "  dop_horizontal: " << dop_horizontal << std::endl;
        ss << "  dop_velocity: " << dop_velocity << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << latitude;                      // offset: 12
        map << longitude;                     // offset: 16
        map << alt_msl;                       // offset: 20
        map << groundspeed;                   // offset: 24
        map << course_over_ground;            // offset: 28
        map << sats;                          // offset: 32
        map << sats_in_view;                  // offset: 36
        map << fix;                           // offset: 40
        map << fix_mode;                      // offset: 44
        map << dop_position;                  // offset: 48
        map << dop_horizontal;                // offset: 52
        map << dop_velocity;                  // offset: 56
        map << alive;                         // offset: 60
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> latitude;                      // offset: 12
        map >> longitude;                     // offset: 16
        map >> alt_msl;                       // offset: 20
        map >> groundspeed;                   // offset: 24
        map >> course_over_ground;            // offset: 28
        map >> sats;                          // offset: 32
        map >> sats_in_view;                  // offset: 36
        map >> fix;                           // offset: 40
        map >> fix_mode;                      // offset: 44
        map >> dop_position;                  // offset: 48
        map >> dop_horizontal;                // offset: 52
        map >> dop_velocity;                  // offset: 56
        map >> alive;                         // offset: 60
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
