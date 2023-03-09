//
// Created by samla on 18/02/2023.
//

#ifndef SACNET_RDMCONSTS_H
#define SACNET_RDMCONSTS_H

#include <cstdint>
#include "consts.h"

namespace sACNET::RDM {
    // What follows below is from ANSI E1.20
    // Will be updated to E1.33 in the future

    OPCODE08 SC_RDM = 0xCC; // Slot 0

    OPCODE08 SC_SUB_MESSAGE = 0x01; // Slot 1

    // Broadcast all manufacturers
    uint64_t BROADCAST_ALL_DEVICES_ID_A = 0xFFFFFF;
    uint64_t BROADCAST_ALL_DEVICES_ID_B = 0xFFFFFF;

    // m is specific manufacturer ID
    //uint64_t ALL_DEVICES_ID_A = 0xmmmmFF;
    //uint64_t ALL_DEVICES_ID_B = 0xFFFFFF;

    OPCODE16 SUB_DEVICE_ALL_CALL = 0xFFFF;

    enum class RDM_Command_Class : sACNET::OPCODE08 {
        DISCOVERY_COMMAND = 0x10,
        DISCOVERY_COMMAND_RESPONSE = 0x11,
        GET_COMMAND = 0x20,
        GET_COMMAND_RESPONSE = 0x21,
        SET_COMMAND = 0x30,
        SET_COMMAND_RESPONSE = 0x31,
    };

    enum class RDM_Response_Type :: sACNET::OPCODE08 {
        RESPONSE_TYPE_ACK = 0x00, // Response available now
        RESPONSE_TYPE_ACK_TIMER = 0x01, // Response available after given time interval
        RESPONSE_TYPE_NACK_REASON = 0x02, // Table A-17 in E1.20
        RESPONSE_TYPE_ACK_OVERFLOW = 0x03,
    };

    enum class RDM_Parameter_ID :: sACNET::OPCODE16 {
        // Network Management
        DISC_UNIQUE_BRANCH = 0x0001,
        DISC_MUTE = 0x0002,
        DISC_UN_MUTE = 0x0003,
        PROXIED_DEVICES = 0x0010,
        PROXIED_DEVICE_COUNT = 0x0011,
        COMMS_STATUS = 0x0015,

        // Status Collection
        QUEUED_MESSAGE = 0x0020, // See Table A-4, E1.20
        STATUS_MESSAGES = 0x0030,// See Table A-4, E1.20
        STATUS_ID_DESCRIPTION = 0x0031,
        CLEAR_STATUS_ID = 0x0032,
        SUB_DEVICE_STATUS_REPORT_THRESHOLD = 0x0033, // See Table A-4, E1.20

        // RDM Information
        SUPPORTED_PARAMETERS = 0x0050,
        PARAMETER_DESCRIPTION = 0x0051,

        // Product Information
        DEVICE_INFO = 0x0060,
        PRODUCT_DETAIL_ID_LIST = 0x0070,
        DEVICE_MODEL_DESCRIPTION = 0x0080,
        MANUFACTURER_LABEL = 0x0081,
        DEVICE_LABEL = 0x0082,
        FACTORY_DEFAULTS = 0x0090,
        LANGUAGE_CAPABILITIES = 0x00A0,
        LANGUAGE = 0x00B0,
        SOFTWARE_VERSION_LABEL = 0x00C0,
        BOOT_SOFTWARE_VERSION_ID = 0x00C1,
        BOOT_SOFTWARE_VERSION_LABEL = 0x00C2,

        // DMX512 Setup
        DMX_PERSONALITY = 0x00E0,
        DMX_PERSONALITY_DESCRIPTION = 0x00E1,
        DMX_START_ADDRESS = 0x00F0,
        SLOT_INFO = 0x0120,
        SLOT_DESCRIPTION = 0x0121,
        DEFAULT_SLOT_VALUE = 0x0122,

        // Sensors  0x02xx
        SENSOR_DEFINITION = 0x0200,
        SENSOR_VALUE = 0x0201,
        RECORD_SENSORS = 0x0202,

        // Dimmer Settings (Reserved for future)

        // Power/Lamp Settings
        DEVICE_HOURS = 0x0400,
        LAMP_HOURS = 0x0401,
        LAMP_STRIKES = 0x0402,
        LAMP_STATE = 0x0403, // See Table A-8, E1.20
        LAMP_ON_MODE = 0x0405,

        // Display Settings 0x05xx
        DISPLAY_INVERT = 0x0500,
        DISPLAY_LEVEL = 0x0501,

        // Configuration 0x06xx
        PAN_INVERT = 0x0600,
        TILT_INVERT = 0x0601,
        PAN_TILT_SWAP = 0x0602,
        REAL_TIME_CLOCK = 0x0603,

        // Control 0x10xx
        IDENTIFY_DEVICE = 0x1000,
        RESET_DEVICE = 0x1001,
        POWER_STATE = 0x1010, // See Table A-11, E1.20
        PERFORM_SELFTEST = 0x1020, // See Table A-10, E1.20
        SELF_TEST_DESCRIPTION = 0x1021,
        CAPTURE_PRESET = 0x1030,
        PRESET_PLAYBACK = 0x1031, // See Table A-7, E1.20

        // ESTA Reserved Future RDM Development 0x7FE0-0x7FFF

        // Manufacturer-specific PIDs 0x8000-0xFFDF

        // ESTA Reserved Future RDM Development 0xFFE0-0xFFFf
    };

    enum class Status_Type_Defines sACNET::OPCODE08 {
        NONE = 0x00, // Not allowed with GET: QUEUED_MESSAGE
        GET_LAST_MESSAGE = 0x01,
        ADVISORY = 0x02,
        WARNING = 0x03,
        ERROR = 0x04,
        ADVISORY_CLEARED = 0x12,
        WARNING_CLEARED = 0x13,
        ERROR_CLEARED = 0x14,
    };

    // A-5
    // Most two significant bits, followed by the LSB for "fine control"
    enum class Product_Category_Defines sACNET::OPCODE16 {
        NOT_DECLATED  = 0x0000,

        // Fixture sources of illumination
        FIXTURE = 0x0100,
        FIXTURE_FIXUED = 0x0101,
        FIXTURE_MOVING_YOKE = 0x0102,
        FIXTURE_MOVING_MIRROR = 0x0103,
        FIXTURE_OTHER = 0x01FF,

        // Accessories - add-ons to fixtures of projectors
        FIXTURE_ACCESSORY = 0x0200,
        FIXTURE_ACCESSORY_COLOR = 0x0201, // Scrollers / Color Changers
        FIXTURE_ACCESSORY_YOKE = 0x0202, // Yoke add-on
        FICTURE_ACCESSORY_MIRROR = 0x0203, // Moving mirror add-on
        FIXTURE_ACCESSORY_EFFECT = 0x0204, // Effect discs
        FIXTURE_ACCESSORY_BEAM = 0x0205, // Gobo Rotators / Iris / Shutters / Dousers / Beam Modifiers
        FIXTURE_ACCESSORY_OTHER = 0x02FF,

        // Projectors - Light source capable of producing realistic images from another media
        PROJECTOR = 0x0300,
        PROJECTOR_FIXED = 0x0301, // No pan / tilt functions
        PROJECTOR_MOVING_YOKE = 0x0302,
        PROJECTOR_MOVING_MIRROR = 0x0303,
        PROJECTOR_OTHER = 0x03FF,

        // Atmospheric Effect - Earth/Wind/Fire
        ATMOSPHERIC = 0x0400,
        ATMOSPHERIC_EFFECT = 0x0401, // Fogger / Hazer / Flame, etc
        ATMOSPHERIC_PYRO = 0x0402,
        ATMOSPHERIC_OTHER = 0x04FF,

        // Intensity control (dimming)
        DIMMER = 0x0500,
        DIMMER_AC_INCANDESCENT = 0x0500, // AC > 50VAC
        DIMMER_AC_FLOURESCENT = 0x0502,
        DIMMER_AC_COLDCATHODE = 0x0503, // High voltage outputs such as Neon or other cold cathode
        DIMMER_AC_NONDIM = 0x0504, // Non-dim module in dimmer rack
        DIMMER_AC_ELV = 0x0505,// AC <= 50VAC such as 12/24V AC low voltage lamps
        DIMMER_AC_OTHER = 0x0506,
        DIMMER_DC_LEVEL = 0x0507, // Variable DC level output
        DIMMER_DC_PWM = 0x0507, // Chopped (PWM) output
        DIMMER_CS_LED = 0x0509, // Specialised LED dimmer
        DIMMER_OTHER = 0x05FF,

        // Power control (other than dimming equipment)
        POWER = 0x0600,
        POWER_CONTROL = 0x0601, // Contractor racks, other forms of power controllers
        POWER_SOURCE = 0x0602, // Generators
        POWER_OTHER = 0x06FF,

        // Scenic drive - including motorized efects unrelated to light source
        SCENIC = 0x0700,
        SCENIC_DRIVE = 0x0701, // Rotators / Kabuki drops, etc
        SCENIC_OTHER = 0x07FF,

        // DMX Infrastructure, conversion and interfaces
        DATA = 0x0800,
        DATA_DISTRIBUTION = 0x0801, // Splitters / repeaters / data patch / Ethernet products used to distribute DMX universes
        DATA_CONVERSION = 0x0802, // Protocol Conversion analog decoders
        DATA_OTHER = 0x08FF,

        // Audio-Visual Equipment
        AV = 0x0900,
        AV_AUDIO = 0x0901, // Audio controller or device
        AV_VIDEO = 0x0902, // Video controller or display
        AV_OTHER = 0x09FF,

        // Parameter monitoring equipment
        MONITOR = 0x0A00,
        MONITOR_ACLINEPOWER = 0x0A01, // Product that monitors AC line voltage, current or power
        MONITOR_DCPOWER = 0x0A02, // Product that monitors DC line voltage, current or power
        MONITOR_ENVIRONMENTAL = 0x0A03, // Temperature or other environmental parameter
        MONITOR_OTHER = 0x0AFF,

        // Controllers, backup devices
        CONTROL = 0x7000,
        CONTROL_CONTROLLER = 0x7001,
        CONTROL_BACKUPDEVICE = 0x7002,
        CONTROL_OTHER = 0x70FF,

        // Test equipment
        TEST = 0x7100,
        TEST_EQUIPMENT = 0x7101,
        TEST_EQUIPMENT_OTHER = 0x71FF,

        // Miscellaneous
        OTHER = 0x7FFF // For devices that aren't described within this table

        // Manufacturer specific categories, 0x8000 to 0xDFFF
    };

    // A6
    enum class Product_Detail : sACNET::OPCODE16 {
        NOT_DECLARED = 0x0000,

        // Fixture types
        ARC = 0x001, // Intended for constant light output
        METAL_HALIDE = 0x0002,
        INCANDESCENT = 0x0003,
        LED = 0x0004,
        FLUROESCENT = 0x0005,
        COLDCATHODE = 0x0006, // includes Neon/Argon
        ELECTROLUMINESCENT = 0x0007,
        LASER = 0x0008,
        FLASHTUBE = 0x0009, // Stobes or flashes

        // Fixture Accessories
        COLORSCROLLER = 0x0100,
        COLORWHEEL = 0x0101,
        COLORCHANGE = 0x0102, // Semaphore or other type
        IRIS_DOUSER = 0x0103,
        DIMMING_SHUTTER = 0x0104,
        PROFILE_SHUTTER = 0x0105, // Hard-edge beam masking
        BARNDOOR_SHUTTER = 0x0106, // Soft-edge beam masking
        EFFECTS_DISC = 0x0107,
        GOBO_ROTATOR = 0x0108,

        // Projectors
        VIDEO = 0x0200,
        SLIDE = 0x0201,
        FILM = 0x0202,
        OILWHEEL = 0x0203,
        LCDGATE = 0x0204,

        // Atmospheric Effects
        FOGGER_GLYCOL = 0x0300, // Glycol / Glycerin hazer
        FOGGER_MINERALOIL = 0x0301, // White Mineral oil hazer
        FOGGER_WATER = 0x0302, // Water hazer
        CO2 = 0x0303, // Dry Ice / Carbon Dioxide based
        LN2 = 0x0304, // Nitrogen based
        BUBBLE = 0x0305, // Including foam
        FLAME_PROPANE = 0x0306,
        FLAME_OTHER = 0x0307,
        OLEFACTORY_STIMULATOR = 0x0308, // Scents
        SNOW = 0x0309,
        WATER_JET = 0x030A, // Fountain controls etc
        WIND = 0x030B, // Air mover
        CONFETTI = 0x030C,
        HAZARD = 0x030D, // Any form of pyrotechnic control device

        // Dimmer / Power controllers
        PHASE_CONTROL = 0x0400,
        REVERSE_PHASE_CONTROL = 0x0401, // Includes FET/IGBT
        SINE = 0x0402,
        PWM = 0x0403,
        DC = 0x0404, // Variable voltage
        HFBALLAST = 0x0405, // For Fluroescent
        HFHV_NEONBALLAST = 0x0406, // For Neon/Argon and other coldcathode
        HFHV_EL = 0x0407, // For Electroluminscent
        MHR_BALLAST = 0x0408, // For Metal Halide
        BITANGLE)MODULATION = 0x0409,
        FREQUENCY_MODULATION = 0x040A,
        HIGHFREQUENCY_12V = 0x04B, // As commonly used with MR16 lamps
        RELAY_MECHANICAL = 0x040C,
        RELAY_ELECTRONIC = 0x040D,
        SWITCH_ELECTRONIC = 0x040E,
        CONTACTOR = 0x040F,

        // Scenic Drive
        MIRRORBALL_ROTATOR = 0x0500,
        OTHER_ROTATOR = 0x0501, // Includes turntables
        KABUKI_DROP = 0x0502,
        CURTAIN = 0x0503, // Flown or traveller,
        LINESET = 0x0504,
        MOTOR_CONTROL = 0x0505,
        DAMPER_CONTROL = 0x0506, // HVAC Damper

        // Data Distribution
        SPLITTER = 0x0600, // Includes buffers / repeaters
        ETHERNET_NODE = 0x0601, // DMX512 to/from ethernet
        MERGE = 0x0602, // DMX512 combiner
        DATAPATCH = 0x0603, // Electronic Datalink Patch
        WIRELESS_LINK = 0x0604, // Radio / Infrared

        // Data conversion and Interfaces
        PROTOCOL_CONVERTOR = 0x0701, // D54/AMX192/Non DMX serial links etc to/from DMX512
        ANALOG_DEMULTIPLEX = 0x0702, // DMX to DC voltage
        ANALOG_MULTIPLEX = 0x0703, // DC Voltage to DMX
        SWITCH_PANEL = 0x0704, // Pushbuttons to DMX or polled using RDM,

        // Audio-visual devices
        ROUTER = 0x0800, // Switching device
        FADER = 0x0801, // Single channel
        MIXER = 0x0802, // Multi channel

        // Controllers, backup devices, and test equipment
        CHANGEOVER_MANUAL = 0x0900, // Manual intervention to assume control of DMX line
        CHANGEOVER_AUTO = 0x0901, // May automatically assume control of DMX Line
        TEST = 0x0902, // Test equipment

        // Could be applied to any category
        GFI_RCD = 0x0A00, // Device includes GFI/RCD trip
        BATTERY = 0x0A01, // Device is battery operated
        CONTROLLABLE_BREAKER = 0x0A02,

        // Manufacturer Specific Types = 0x80000-DFFF

        OTHER = 0x7FFF, // For use where the Manufacturer believes that none of the defined details apply
    };

    // A-7
    enum class Preset_Playback_Defines : sACNET::OPCODE16 {
        OFF = 0x0000, // Returns to Normal DMX512 Input
        ALL = 0xFFFF, // Plays Scenes in Sequence if supported
        SCENE = 0x0001, // This can be from 0x0001 to 0xFFFE
    }

    // A-8
    enum class Lamp_State_Defines : sACNET::OPCODE08 {
        OFF = 0x00, // No demonstrable light output
        ON = 0x01,
        STRIKE = 0x02, // Arc-Lamp ignite
        STANDBY = 0x03, // Arc-Lamp Reduced Power Mode
        NOT_PRESENT = 0x04, // Lamp not present
        ERROR = 0x7F,

        // 0x80-0xDF define manufacturer specific states
    };

    // A-9
    enum class Lamp_On_Mode_Defines : sACNET:OPCODE08 {
        OFF = 0x00, // Lamp Stays off until directly instructed to strike
        DMX = 0x01, // Lamp Strikes upon receiving a DMX512 signal
        ON  = 0x02, // Lamp Strikes up automatically at power-up
        AFTER_CAL = 0x03, // Lamp Strikes up after calibration or homing procedure
        // 0x80-0xDF defines manufacturer specific states
    };

    // A-10
    enum class Self_Test_Defines : sACNET::OPCODE08 {
        OFF = 0x00, // Turns Self Tests Off
        // 0x01-0xFE defines manufacturer self tests
        SELF_TEST_ALL = 0xFF, // Self Test All, if applicable
    };

    // A-11
    enum class Power_State_Defines : sACNET::OPCODE08 {
        FULL_OFF = 0x00, // Completely disengages power to device. Device can no longer respond
        SHUTDOWN = 0x01, // Reduced power mode, may require device reset to return to normal operation. Still responds to messages
        STANDBY = 0x02, // Reduced power mode, device can return to NORMAL without reset
        NORMAL = 0xFF, // Normal Operating mode
    }

    // A-12
    enum class Sensor_Type_Defines : sACNET::OPCODE08 {
        TEMPERATURE = 0x00,
        VOLTAGE = 0x01,
        CURRENT = 0x02,
        FREQUENCY = 0x03,
        RESISTANCE = 0x04, // Eg: Cable resistance
        POWER = 0x05,
        MASS = 0x06, // Eg: Truss load cell
        LENGTH = 0x07,
        AREA = 0x08,
        VOLUME = 0x09, // Eg: Smoke Fluid
        DENSITY = 0x0A,
        VELOCITY = 0x0B,
        ACCELERATION = 0x0C,
        FORCE = 0x0D,
        ENERGY = 0x0E,
        PRESSURE = 0x0F,
        TIME = 0x10,
        ANGLE = 0x11,
        POSITION_X = 0x12, // Eg: Lamp position on Truss
        POSITION_Y = 0x13,
        POSITION_Z = 0x14,
        ANGULAR_VELOCITY = 0x15, // Eg: wind speed
        LUMINOUS_INTENSITY = 0x16,
        LUMINOUS_FLUX = 0x17,
        ILLUMINANCE = 0x18,
        CHROMINANCE_RED = 0x19,
        CHROMINANCE_GREEN = 0x1A,
        CHROMINANCE_BLUE = 0x1B,
        CONTACTS = 0x1C, // Eg: switch inputs
        MEMORY = 0x1D, // Eg: ROM size
        ITEMS = 0x1E, // Eg: scroller gel frames
        HUMIDITY = 0x1F,
        COUNTER_16BIT = 0x20,
        OTHER = 0x7F,
        // 0x80-0xFF defines Manufacturer-Specific Sensors
    };

    // A-13
    // Need a way to link this with enum E-12, enums aren't the ideal solution but they'll do for now
    enum class Sensor_Unit_Defines : sACNET::OPCODE08 {
        NONE = 0x00, // CONTACTS
        CENTIGRADE = 0x01, // TEMPERATURE
        VOLTS_DC = 0x02, // VOLTAGE
        VOLTS_AC_PEAK = 0x03, // VOLTAGE
        VOLTS_AC_RMS = 0x04, // VOLTAGE
        AMPERE_DC = 0x05, // CURRENT
        AMPERE_AC_PEAK = 0x06, // CURRENT
        AMPERE_AC_RMS = 0x07, // CURRENT
        HERTZ = 0x08, // FREQUENCY / ANG_VEL
        OHM = 0x09, // RESISTANCE
        WATT = 0x0A, // POWER
        KILOGRAM = 0x0B, // MASS
        METERS = 0x0C, // LENGTH / POSITION_X/Y/Z
        METERS_SQUARED = 0x0D, // AREA
        METERS_CUBED = 0x0E, // VOLUME
        KILOGRAMMES_PER_METER_CUBED = 0x0F, // DENSITY
        METERS_PER_SECOND = 0x10, // VELOCITY
        METERS_PER_SECOND_SQUARED = 0x11, // ACCELERATION
        NEWTON = 0x12, // FORCE
        JOULE = 0x13, // ENERGY
        PASCAL = 0x14, // PRESSURE
        SECOND = 0x15, // TIME
        DEGREE = 0x16, // ANGLE
        STERADIAN = 0x17, // ANGLE
        CANDELA = 0x18, // LUMINOUS_INTENSITY
        LUMEN = 0x19, // LUMINOUS_FLUX
        LUX = 0x1A, // ILLUMINANCE
        IRE = 0x1B, // CHROMINANCE
        BYTE = 0x1C, // MEMORY
        // 0x80-0xFF defines Manufacturer-Specific units
    };


    // A-14
    enum class Sensor_Unit_Prefix_Defines : sACNET::OPCODE08 {
        NONE = 0x00,
        DECI = 0x01,
        CENTI = 0x02,
        MILLI = 0x03,
        MICRO = 0x04,
        NANO = 0x05,
        PICO = 0x06,
        FEMPTO = 0x07,
        ATTO = 0x08,
        XEPTO = 0x09,
        YOCTO = 0x0A,
        DECA = 0x11,
        HECTO = 0x12,
        KILO = 0x13,
        MEGA = 0x14,
        GIGA = 0x15,
        TERRA = 0x16,
        PETA = 0x17,
        EXA = 0x18,
        ZETTA = 0x19,
        YOTTA = 0x1A,
    };

    // A-15
    enum class Data_Type_Defines : sACNET::OPCODE08 {
        NOT_DEFINED = 0x00,
        BIT_FIELD = 0x01, // Bit packed
        ASCII = 0x02, // String
        UNSIGNED_BYTE = 0x03, // Array of unsigned bytes
        SIGNED_BYTE = 0x04, // Array of signed bytes
        UNSIGNED_WORD = 0x05, // Array of unsigned 16-bit words
        SIGNED_WORD = 0x06, // Array of signed 16-bit words
        UNSIGNED_DWORD = 0x07, // Array of unsigned 32-bit words
        SIGNED_DWORD = 0x08, // Array of signed 32-bit words
        // 0x80-0xDF Manufacturer-Specific Data types
    };

    // A-16
    enum class Command_Class_Defines : sACNET::OPCODE08 {
        GET = 0x01, // PID Supports GET only
        SET = 0x02, // PID Supports SET only
        GET_SET = 0x03,
    };

    enum class NACK_Reason_Code_Defines : sACNET::OPCODE16 {
        UNKNOWN_PID = 0x0000, // Message is not implemented in responder
        FORMAT_ERROR = 0x0001, // Controller data not formatted correctly
        HARDWARE_FAULT = 0x0002, // Internal hardware fault on receiver
        PROXY_REJECT = 0x0003, // Proxy is not RDM line master and cannot comply with message
        WRITE_PROTECT = 0x0004, // SET command normally allowed but being blocked
        DATA_OUT_OF_RANGE = 0x0006, // Value for given parameter out of allowable range
        BUFFER_FULL = 0x0007, // No spare buffer or queue space to store data
        PACKET_SIZE_UNSUPPORTED = 0x0008, // Incoming message exceeds buffer capacity
        SUB_DEVICE_OUT_OF_RANGE = 0x0009, // Sub-device is out of range or unknown
        PROXY_BUFFER_FULL = 0x000A, // Buffer full and cannot store any more Queued Message or Status Message responses
    }


};
#endif //SACNET_RDMCONSTS_H
