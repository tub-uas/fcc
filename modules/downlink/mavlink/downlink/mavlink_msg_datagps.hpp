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
    static constexpr size_t LENGTH = 57;
    static constexpr size_t MIN_LENGTH = 57;
    static constexpr uint8_t CRC_EXTRA = 34;
    static constexpr auto NAME = "DataGps";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float lat; /*<  Latitude in deg */
    float lon; /*<  Longitude in deg */
    float alt; /*<  Altitude in m */
    float speed; /*<  Speed in m/s */
    float cog; /*<  Course over ground in deg */
    float sats; /*<  Number of satellites currently using */
    float fix; /*<  0=No fix, 1=Fix, 2=Differential fix */
    float fixMode; /*<  1=No fix, 2=2D fix, 3=3D fix */
    float dopP; /*<  Positional dilution of precision */
    float dopH; /*<  Horizontal dilution of precision */
    float dopV; /*<  Vertical dilution of precision */
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
        ss << "  lat: " << lat << std::endl;
        ss << "  lon: " << lon << std::endl;
        ss << "  alt: " << alt << std::endl;
        ss << "  speed: " << speed << std::endl;
        ss << "  cog: " << cog << std::endl;
        ss << "  sats: " << sats << std::endl;
        ss << "  fix: " << fix << std::endl;
        ss << "  fixMode: " << fixMode << std::endl;
        ss << "  dopP: " << dopP << std::endl;
        ss << "  dopH: " << dopH << std::endl;
        ss << "  dopV: " << dopV << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << lat;                           // offset: 12
        map << lon;                           // offset: 16
        map << alt;                           // offset: 20
        map << speed;                         // offset: 24
        map << cog;                           // offset: 28
        map << sats;                          // offset: 32
        map << fix;                           // offset: 36
        map << fixMode;                       // offset: 40
        map << dopP;                          // offset: 44
        map << dopH;                          // offset: 48
        map << dopV;                          // offset: 52
        map << alive;                         // offset: 56
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> lat;                           // offset: 12
        map >> lon;                           // offset: 16
        map >> alt;                           // offset: 20
        map >> speed;                         // offset: 24
        map >> cog;                           // offset: 28
        map >> sats;                          // offset: 32
        map >> fix;                           // offset: 36
        map >> fixMode;                       // offset: 40
        map >> dopP;                          // offset: 44
        map >> dopH;                          // offset: 48
        map >> dopV;                          // offset: 52
        map >> alive;                         // offset: 56
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
