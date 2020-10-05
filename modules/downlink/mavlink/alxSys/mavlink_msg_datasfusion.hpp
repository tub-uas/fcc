// MESSAGE DataSfusion support class

#pragma once

namespace mavlink {
namespace alxSys {
namespace msg {

/**
 * @brief DataSfusion message
 *
 * Data from SFUSION
 */
struct DataSfusion : mavlink::Message {
    static constexpr msgid_t MSG_ID = 40000;
    static constexpr size_t LENGTH = 93;
    static constexpr size_t MIN_LENGTH = 93;
    static constexpr uint8_t CRC_EXTRA = 170;
    static constexpr auto NAME = "DataSfusion";


    uint64_t time; /*<  Time. */
    float phi; /*<  Phi. */
    float the; /*<  Theta. */
    float psi; /*<  Psi. */
    float q0; /*<  q0. */
    float q1; /*<  q1. */
    float q2; /*<  q2. */
    float q3; /*<  q3. */
    float baro_fused; /*<  Barometric pressure sfusion. */
    float temp_fused; /*<  Temperature. */
    float posN; /*<  Position North. */
    float posE; /*<  Position East. */
    float posD; /*<  Position Down. */
    float speedN; /*<  Speed North. */
    float speedE; /*<  Speed East. */
    float speedD; /*<  Speed Down. */
    float WindN; /*<  Wind North. */
    float WindE; /*<  Wind East. */
    float WindD; /*<  Wind Down. */
    float ssa; /*<  Sideslip angle estimation. */
    float aoa; /*<  Angle of attack estimation. */
    float gamma; /*<  Pathangle estimation. */
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
        ss << "  phi: " << phi << std::endl;
        ss << "  the: " << the << std::endl;
        ss << "  psi: " << psi << std::endl;
        ss << "  q0: " << q0 << std::endl;
        ss << "  q1: " << q1 << std::endl;
        ss << "  q2: " << q2 << std::endl;
        ss << "  q3: " << q3 << std::endl;
        ss << "  baro_fused: " << baro_fused << std::endl;
        ss << "  temp_fused: " << temp_fused << std::endl;
        ss << "  posN: " << posN << std::endl;
        ss << "  posE: " << posE << std::endl;
        ss << "  posD: " << posD << std::endl;
        ss << "  speedN: " << speedN << std::endl;
        ss << "  speedE: " << speedE << std::endl;
        ss << "  speedD: " << speedD << std::endl;
        ss << "  WindN: " << WindN << std::endl;
        ss << "  WindE: " << WindE << std::endl;
        ss << "  WindD: " << WindD << std::endl;
        ss << "  ssa: " << ssa << std::endl;
        ss << "  aoa: " << aoa << std::endl;
        ss << "  gamma: " << gamma << std::endl;
        ss << "  alive: " << +alive << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time;                          // offset: 0
        map << phi;                           // offset: 8
        map << the;                           // offset: 12
        map << psi;                           // offset: 16
        map << q0;                            // offset: 20
        map << q1;                            // offset: 24
        map << q2;                            // offset: 28
        map << q3;                            // offset: 32
        map << baro_fused;                    // offset: 36
        map << temp_fused;                    // offset: 40
        map << posN;                          // offset: 44
        map << posE;                          // offset: 48
        map << posD;                          // offset: 52
        map << speedN;                        // offset: 56
        map << speedE;                        // offset: 60
        map << speedD;                        // offset: 64
        map << WindN;                         // offset: 68
        map << WindE;                         // offset: 72
        map << WindD;                         // offset: 76
        map << ssa;                           // offset: 80
        map << aoa;                           // offset: 84
        map << gamma;                         // offset: 88
        map << alive;                         // offset: 92
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> phi;                           // offset: 8
        map >> the;                           // offset: 12
        map >> psi;                           // offset: 16
        map >> q0;                            // offset: 20
        map >> q1;                            // offset: 24
        map >> q2;                            // offset: 28
        map >> q3;                            // offset: 32
        map >> baro_fused;                    // offset: 36
        map >> temp_fused;                    // offset: 40
        map >> posN;                          // offset: 44
        map >> posE;                          // offset: 48
        map >> posD;                          // offset: 52
        map >> speedN;                        // offset: 56
        map >> speedE;                        // offset: 60
        map >> speedD;                        // offset: 64
        map >> WindN;                         // offset: 68
        map >> WindE;                         // offset: 72
        map >> WindD;                         // offset: 76
        map >> ssa;                           // offset: 80
        map >> aoa;                           // offset: 84
        map >> gamma;                         // offset: 88
        map >> alive;                         // offset: 92
    }
};

} // namespace msg
} // namespace alxSys
} // namespace mavlink
