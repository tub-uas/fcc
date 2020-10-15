// MESSAGE DataWatchdog support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataWatchdog message
 *
 * Data from Watchdog
 */
struct DataWatchdog : mavlink::Message {
    static constexpr msgid_t MSG_ID = 70000;
    static constexpr size_t LENGTH = 21;
    static constexpr size_t MIN_LENGTH = 21;
    static constexpr uint8_t CRC_EXTRA = 77;
    static constexpr auto NAME = "DataWatchdog";


    uint64_t time; /*<  System time at publication */
    uint8_t allAlive; /*<  Are all modules alive? */
    uint8_t ahrsAlive; /*<  Is AHRS alive? */
    uint8_t airAlive; /*<  Is AIR alive? */
    uint8_t ctrlAlive; /*<  Is Ctrl alive? */
    uint8_t downlinkAlive; /*<  Is Downlink alive? */
    uint8_t gpsAlive; /*<  Is GPS alive? */
    uint8_t logAlive; /*<  Is Downlink alive? */
    uint8_t psuAlive; /*<  Is PSU alive? */
    uint8_t raiInAlive; /*<  Is RaiIn alive? */
    uint8_t raiOutAlive; /*<  Is RaiOut alive? */
    uint8_t sFusionAlive; /*<  Is SFusion alive? */
    uint8_t uplinkAlive; /*<  Is Uplink alive? */
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
        ss << "  allAlive: " << +allAlive << std::endl;
        ss << "  ahrsAlive: " << +ahrsAlive << std::endl;
        ss << "  airAlive: " << +airAlive << std::endl;
        ss << "  ctrlAlive: " << +ctrlAlive << std::endl;
        ss << "  downlinkAlive: " << +downlinkAlive << std::endl;
        ss << "  gpsAlive: " << +gpsAlive << std::endl;
        ss << "  logAlive: " << +logAlive << std::endl;
        ss << "  psuAlive: " << +psuAlive << std::endl;
        ss << "  raiInAlive: " << +raiInAlive << std::endl;
        ss << "  raiOutAlive: " << +raiOutAlive << std::endl;
        ss << "  sFusionAlive: " << +sFusionAlive << std::endl;
        ss << "  uplinkAlive: " << +uplinkAlive << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << allAlive;                      // offset: 8
        map << ahrsAlive;                     // offset: 9
        map << airAlive;                      // offset: 10
        map << ctrlAlive;                     // offset: 11
        map << downlinkAlive;                 // offset: 12
        map << gpsAlive;                      // offset: 13
        map << logAlive;                      // offset: 14
        map << psuAlive;                      // offset: 15
        map << raiInAlive;                    // offset: 16
        map << raiOutAlive;                   // offset: 17
        map << sFusionAlive;                  // offset: 18
        map << uplinkAlive;                   // offset: 19
        map << alive;                         // offset: 20
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> allAlive;                      // offset: 8
        map >> ahrsAlive;                     // offset: 9
        map >> airAlive;                      // offset: 10
        map >> ctrlAlive;                     // offset: 11
        map >> downlinkAlive;                 // offset: 12
        map >> gpsAlive;                      // offset: 13
        map >> logAlive;                      // offset: 14
        map >> psuAlive;                      // offset: 15
        map >> raiInAlive;                    // offset: 16
        map >> raiOutAlive;                   // offset: 17
        map >> sFusionAlive;                  // offset: 18
        map >> uplinkAlive;                   // offset: 19
        map >> alive;                         // offset: 20
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
