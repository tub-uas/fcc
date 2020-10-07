// MESSAGE DataPsu support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataPsu message
 *
 * Data from Psu
 */
struct DataPsu : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60000;
    static constexpr size_t LENGTH = 49;
    static constexpr size_t MIN_LENGTH = 49;
    static constexpr uint8_t CRC_EXTRA = 202;
    static constexpr auto NAME = "DataPsu";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float mainVolt; /*<  Voltage of battery */
    float mainCurr; /*<  Current drawn from battery */
    float mainPow; /*<  Power drawn from battery */
    float pwrVolt; /*<  Voltage of servo supply (5V) */
    float pwrCurr; /*<  Current drawn from servo supply (5V) */
    float pwrPow; /*<  Power drawn from servo supply (5V) */
    float sysVolt; /*<  Voltage of system supply (5V) */
    float sysCurr; /*<  Current drawn from system supply (5V) */
    float sysPow; /*<  Power drawn from system supply (5V) */
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
        ss << "  mainVolt: " << mainVolt << std::endl;
        ss << "  mainCurr: " << mainCurr << std::endl;
        ss << "  mainPow: " << mainPow << std::endl;
        ss << "  pwrVolt: " << pwrVolt << std::endl;
        ss << "  pwrCurr: " << pwrCurr << std::endl;
        ss << "  pwrPow: " << pwrPow << std::endl;
        ss << "  sysVolt: " << sysVolt << std::endl;
        ss << "  sysCurr: " << sysCurr << std::endl;
        ss << "  sysPow: " << sysPow << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << mainVolt;                      // offset: 12
        map << mainCurr;                      // offset: 16
        map << mainPow;                       // offset: 20
        map << pwrVolt;                       // offset: 24
        map << pwrCurr;                       // offset: 28
        map << pwrPow;                        // offset: 32
        map << sysVolt;                       // offset: 36
        map << sysCurr;                       // offset: 40
        map << sysPow;                        // offset: 44
        map << alive;                         // offset: 48
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> mainVolt;                      // offset: 12
        map >> mainCurr;                      // offset: 16
        map >> mainPow;                       // offset: 20
        map >> pwrVolt;                       // offset: 24
        map >> pwrCurr;                       // offset: 28
        map >> pwrPow;                        // offset: 32
        map >> sysVolt;                       // offset: 36
        map >> sysCurr;                       // offset: 40
        map >> sysPow;                        // offset: 44
        map >> alive;                         // offset: 48
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
