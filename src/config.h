#pragma once

constexpr char CIRCUIT_NAME[] = "test_m5stack";

// wifi
const char *ssid = "test_quest";
const char *password = "indestroom";
// rtc
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600 * 3;
// lcd
/** @brief WIDTH == X / HEIGHT == Y */
namespace lcd_ns
{
    constexpr int32_t WIDTH = 320;  // X
    constexpr int32_t HEIGHT = 240; // Y
    constexpr int32_t WIDTH_HALF = WIDTH / 2;
    constexpr int32_t HEIGHT_HALF = HEIGHT / 2;
}
// color
struct color_code_t
{
    String name;
    uint32_t code;
};
const color_code_t COLORS[] = {
    {"BLACK", 0x0000},       /*   0,   0,   0 */
    {"NAVY", 0x000F},        /*   0,   0, 128 */
    {"DARKGREEN", 0x03E0},   /*   0, 128,   0 */
    {"DARKCYAN", 0x03EF},    /*   0, 128, 128 */
    {"MAROON", 0x7800},      /* 128,   0,   0 */
    {"PURPLE", 0x780F},      /* 128,   0, 128 */
    {"OLIVE", 0x7BE0},       /* 128, 128,   0 */
    {"LIGHTGREY", 0xC618},   /* 192, 192, 192 */
    {"DARKGREY", 0x7BEF},    /* 128, 128, 128 */
    {"BLUE", 0x001F},        /*   0,   0, 255 */
    {"GREEN", 0x07E0},       /*   0, 255,   0 */
    {"CYAN", 0x07FF},        /*   0, 255, 255 */
    {"RED", 0xF800},         /* 255,   0,   0 */
    {"MAGENTA", 0xF81F},     /* 255,   0, 255 */
    {"YELLOW", 0xFFE0},      /* 255, 255,   0 */
    {"WHITE", 0xFFFF},       /* 255, 255, 255 */
    {"ORANGE", 0xFD20},      /* 255, 165,   0 */
    {"GREENYELLOW", 0xAFE5}, /* 173, 255,  47 */
};
constexpr size_t COLORS_COUNT = sizeof(COLORS) / sizeof(COLORS[0]);

struct color_t
{
    size_t index = 0;
    uint32_t get_color()
    {
        return COLORS[index].code;
    }
    static uint32_t get_color(String name)
    {
        for (size_t i = 0; i < COLORS_COUNT; i++)
        {
            if (name == COLORS[i].name)
                return COLORS[i].code;
        }
    }
    String get_colorName()
    {
        return COLORS[index].name;
    }
};

struct text_t
{
    struct pos_t
    {
        int16_t x;
        int16_t y;
    };
    color_t color;
    uint8_t size;
};

// String days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; // days in week