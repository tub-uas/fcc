// MESSAGE GIMBAL_DEVICE_INFORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief GIMBAL_DEVICE_INFORMATION message
 *
 * Information about a low level gimbal. This message should be requested by the gimbal manager or a ground station using MAV_CMD_REQUEST_MESSAGE. The maximum angles and rates are the limits by hardware. However, the limits by software used are likely different/smaller and dependent on mode/settings/etc..
 */
struct GIMBAL_DEVICE_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 283;
    static constexpr size_t LENGTH = 144;
    static constexpr size_t MIN_LENGTH = 144;
    static constexpr uint8_t CRC_EXTRA = 33;
    static constexpr auto NAME = "GIMBAL_DEVICE_INFORMATION";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    std::array<char, 32> vendor_name; /*<  Name of the gimbal vendor. */
    std::array<char, 32> model_name; /*<  Name of the gimbal model. */
    std::array<char, 32> custom_name; /*<  Custom name of the gimbal given to it by the user. */
    uint32_t firmware_version; /*<  Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    uint32_t hardware_version; /*<  Version of the gimbal hardware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    uint64_t uid; /*<  UID of gimbal hardware (0 if unknown). */
    uint16_t cap_flags; /*<  Bitmap of gimbal capability flags. */
    uint16_t custom_cap_flags; /*<  Bitmap for use for gimbal-specific capability flags. */
    float tilt_max; /*< [rad] Maximum hardware tilt/pitch angle (positive: up, negative: down) */
    float tilt_min; /*< [rad] Minimum hardware tilt/pitch angle (positive: up, negative: down) */
    float tilt_rate_max; /*< [rad/s] Maximum hardware tilt/pitch angular rate (positive: up, negative: down) */
    float pan_max; /*< [rad] Maximum hardware pan/yaw angle (positive: to the right, negative: to the left) */
    float pan_min; /*< [rad] Minimum hardware pan/yaw angle (positive: to the right, negative: to the left) */
    float pan_rate_max; /*< [rad/s] Maximum hardware pan/yaw angular rate (positive: to the right, negative: to the left) */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  vendor_name: \"" << to_string(vendor_name) << "\"" << std::endl;
        ss << "  model_name: \"" << to_string(model_name) << "\"" << std::endl;
        ss << "  custom_name: \"" << to_string(custom_name) << "\"" << std::endl;
        ss << "  firmware_version: " << firmware_version << std::endl;
        ss << "  hardware_version: " << hardware_version << std::endl;
        ss << "  uid: " << uid << std::endl;
        ss << "  cap_flags: " << cap_flags << std::endl;
        ss << "  custom_cap_flags: " << custom_cap_flags << std::endl;
        ss << "  tilt_max: " << tilt_max << std::endl;
        ss << "  tilt_min: " << tilt_min << std::endl;
        ss << "  tilt_rate_max: " << tilt_rate_max << std::endl;
        ss << "  pan_max: " << pan_max << std::endl;
        ss << "  pan_min: " << pan_min << std::endl;
        ss << "  pan_rate_max: " << pan_rate_max << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << uid;                           // offset: 0
        map << time_boot_ms;                  // offset: 8
        map << firmware_version;              // offset: 12
        map << hardware_version;              // offset: 16
        map << tilt_max;                      // offset: 20
        map << tilt_min;                      // offset: 24
        map << tilt_rate_max;                 // offset: 28
        map << pan_max;                       // offset: 32
        map << pan_min;                       // offset: 36
        map << pan_rate_max;                  // offset: 40
        map << cap_flags;                     // offset: 44
        map << custom_cap_flags;              // offset: 46
        map << vendor_name;                   // offset: 48
        map << model_name;                    // offset: 80
        map << custom_name;                   // offset: 112
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> uid;                           // offset: 0
        map >> time_boot_ms;                  // offset: 8
        map >> firmware_version;              // offset: 12
        map >> hardware_version;              // offset: 16
        map >> tilt_max;                      // offset: 20
        map >> tilt_min;                      // offset: 24
        map >> tilt_rate_max;                 // offset: 28
        map >> pan_max;                       // offset: 32
        map >> pan_min;                       // offset: 36
        map >> pan_rate_max;                  // offset: 40
        map >> cap_flags;                     // offset: 44
        map >> custom_cap_flags;              // offset: 46
        map >> vendor_name;                   // offset: 48
        map >> model_name;                    // offset: 80
        map >> custom_name;                   // offset: 112
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
