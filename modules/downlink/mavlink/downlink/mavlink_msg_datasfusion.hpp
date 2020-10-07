// MESSAGE DataSFusion support class

#pragma once

namespace mavlink {
namespace downlink {
namespace msg {

/**
 * @brief DataSFusion message
 *
 * Data from SFusion
 */
struct DataSFusion : mavlink::Message {
    static constexpr msgid_t MSG_ID = 40000;
    static constexpr size_t LENGTH = 133;
    static constexpr size_t MIN_LENGTH = 133;
    static constexpr uint8_t CRC_EXTRA = 36;
    static constexpr auto NAME = "DataSFusion";


    uint64_t time; /*<  System time at publication */
    float senseTime; /*<  Time of data creation at sensor */
    float gyrX; /*<  Gyro X-Axis */
    float gyrY; /*<  Gyro Y-Axis */
    float gyrZ; /*<  Gyro Z-Axis */
    float accX; /*<  Accelerometer X-Axis */
    float accY; /*<  Accelerometer Y-Axis */
    float accZ; /*<  Accelerometer Z-Axis */
    float magX; /*<  Magnetometer X-Axis */
    float magY; /*<  Magnetometer Y-Axis */
    float magZ; /*<  Magnetometer Z-Axis */
    float temp; /*<  Temperature */
    float press; /*<  Barometric pressure */
    float phi; /*<  Phi */
    float the; /*<  Theta */
    float psi; /*<  Psi */
    float q0; /*<  Quaternion 0 */
    float q1; /*<  Quaternion 1 */
    float q2; /*<  Quaternion 2 */
    float q3; /*<  Quaternion 3 */
    float posN; /*<  Position north estimation */
    float posE; /*<  Position east estimation */
    float posD; /*<  Position down estimation */
    float speedN; /*<  Speed north estimation */
    float speedE; /*<  Speed east estimation */
    float speedD; /*<  Speed down estimation */
    float WindN; /*<  Wind north estimation */
    float WindE; /*<  Wind east estimation */
    float WindD; /*<  Wind down estimation */
    float ssa; /*<  Sideslip angle estimation */
    float aoa; /*<  Angle of attack estimation */
    float gamma; /*<  Pathangle estimation */
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
        ss << "  gyrX: " << gyrX << std::endl;
        ss << "  gyrY: " << gyrY << std::endl;
        ss << "  gyrZ: " << gyrZ << std::endl;
        ss << "  accX: " << accX << std::endl;
        ss << "  accY: " << accY << std::endl;
        ss << "  accZ: " << accZ << std::endl;
        ss << "  magX: " << magX << std::endl;
        ss << "  magY: " << magY << std::endl;
        ss << "  magZ: " << magZ << std::endl;
        ss << "  temp: " << temp << std::endl;
        ss << "  press: " << press << std::endl;
        ss << "  phi: " << phi << std::endl;
        ss << "  the: " << the << std::endl;
        ss << "  psi: " << psi << std::endl;
        ss << "  q0: " << q0 << std::endl;
        ss << "  q1: " << q1 << std::endl;
        ss << "  q2: " << q2 << std::endl;
        ss << "  q3: " << q3 << std::endl;
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
        map << senseTime;                     // offset: 8
        map << gyrX;                          // offset: 12
        map << gyrY;                          // offset: 16
        map << gyrZ;                          // offset: 20
        map << accX;                          // offset: 24
        map << accY;                          // offset: 28
        map << accZ;                          // offset: 32
        map << magX;                          // offset: 36
        map << magY;                          // offset: 40
        map << magZ;                          // offset: 44
        map << temp;                          // offset: 48
        map << press;                         // offset: 52
        map << phi;                           // offset: 56
        map << the;                           // offset: 60
        map << psi;                           // offset: 64
        map << q0;                            // offset: 68
        map << q1;                            // offset: 72
        map << q2;                            // offset: 76
        map << q3;                            // offset: 80
        map << posN;                          // offset: 84
        map << posE;                          // offset: 88
        map << posD;                          // offset: 92
        map << speedN;                        // offset: 96
        map << speedE;                        // offset: 100
        map << speedD;                        // offset: 104
        map << WindN;                         // offset: 108
        map << WindE;                         // offset: 112
        map << WindD;                         // offset: 116
        map << ssa;                           // offset: 120
        map << aoa;                           // offset: 124
        map << gamma;                         // offset: 128
        map << alive;                         // offset: 132
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time;                          // offset: 0
        map >> senseTime;                     // offset: 8
        map >> gyrX;                          // offset: 12
        map >> gyrY;                          // offset: 16
        map >> gyrZ;                          // offset: 20
        map >> accX;                          // offset: 24
        map >> accY;                          // offset: 28
        map >> accZ;                          // offset: 32
        map >> magX;                          // offset: 36
        map >> magY;                          // offset: 40
        map >> magZ;                          // offset: 44
        map >> temp;                          // offset: 48
        map >> press;                         // offset: 52
        map >> phi;                           // offset: 56
        map >> the;                           // offset: 60
        map >> psi;                           // offset: 64
        map >> q0;                            // offset: 68
        map >> q1;                            // offset: 72
        map >> q2;                            // offset: 76
        map >> q3;                            // offset: 80
        map >> posN;                          // offset: 84
        map >> posE;                          // offset: 88
        map >> posD;                          // offset: 92
        map >> speedN;                        // offset: 96
        map >> speedE;                        // offset: 100
        map >> speedD;                        // offset: 104
        map >> WindN;                         // offset: 108
        map >> WindE;                         // offset: 112
        map >> WindD;                         // offset: 116
        map >> ssa;                           // offset: 120
        map >> aoa;                           // offset: 124
        map >> gamma;                         // offset: 128
        map >> alive;                         // offset: 132
    }
};

} // namespace msg
} // namespace downlink
} // namespace mavlink
