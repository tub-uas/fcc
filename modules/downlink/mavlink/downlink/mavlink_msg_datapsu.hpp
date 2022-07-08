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
    static constexpr uint8_t CRC_EXTRA = 217;
    static constexpr auto NAME = "DataPsu";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float main_volt; /*<  Voltage of battery */
    float main_curr; /*<  Current drawn from battery */
    float main_pwr; /*<  Power drawn from battery */
    float pwr_volt; /*<  Voltage of servo supply (5V) */
    float pwr_curr; /*<  Current drawn from servo supply (5V) */
    float pwr_pwr; /*<  Power drawn from servo supply (5V) */
    float sys_volt; /*<  Voltage of system supply (5V) */
    float sys_curr; /*<  Current drawn from system supply (5V) */
    float sys_pwr; /*<  Power drawn from system supply (5V) */
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
        ss << "  main_volt: " << main_volt << std::endl;
        ss << "  main_curr: " << main_curr << std::endl;
        ss << "  main_pwr: " << main_pwr << std::endl;
        ss << "  pwr_volt: " << pwr_volt << std::endl;
        ss << "  pwr_curr: " << pwr_curr << std::endl;
        ss << "  pwr_pwr: " << pwr_pwr << std::endl;
        ss << "  sys_volt: " << sys_volt << std::endl;
        ss << "  sys_curr: " << sys_curr << std::endl;
        ss << "  sys_pwr: " << sys_pwr << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << senseTime;                     // offset: 8
        map << main_volt;                     // offset: 12
        map << main_curr;                     // offset: 16
        map << main_pwr;                      // offset: 20
        map << pwr_volt;                      // offset: 24
        map << pwr_curr;                      // offset: 28
        map << pwr_pwr;                       // offset: 32
        map << sys_volt;                      // offset: 36
        map << sys_curr;                      // offset: 40
        map << sys_pwr;                       // offset: 44
        map << alive;                         // offset: 48
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> main_volt;                     // offset: 12
        map >> main_curr;                     // offset: 16
        map >> main_pwr;                      // offset: 20
        map >> pwr_volt;                      // offset: 24
        map >> pwr_curr;                      // offset: 28
        map >> pwr_pwr;                       // offset: 32
        map >> sys_volt;                      // offset: 36
        map >> sys_curr;                      // offset: 40
        map >> sys_pwr;                       // offset: 44
        map >> alive;                         // offset: 48
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
