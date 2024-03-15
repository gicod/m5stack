#pragma once
// #include <ds_basic.h>

#include <M5Stack.h>
#include <ESP32Time.h>
#include <WiFi.h>

#include "config.h"

// ESP32Time rtc(daylightOffset_sec);
ESP32Time rtc(0);

color_t c_back;
color_t c_text;

bool lcd_enable = true;

void lcd_clear()
{
    M5.Lcd.fillScreen(c_back.get_color());
    M5.Lcd.setCursor(0, 0);
}

uint8_t rgb[3];
void colorNext_test(uint8_t value, bool isNext = false)
{
    static int index = 0;
    if(isNext)
    {
        rgb[0] = 0;
        rgb[1] = 0;
        rgb[2] = 0;
        index++;
        if(index > 5) index = 0;
    }

    if(index == 0) rgb[0] = value;
    else if(index == 1) 
    {
        rgb[0] = value;
        rgb[1] = value;
    }
    else if(index == 2) rgb[1] = value;
    else if(index == 3) 
    {
        rgb[1] = value;
        rgb[2] = value;
    }
    else if(index == 4) rgb[2] = value;
    else if(index == 5) 
    {
        rgb[2] = value;
        rgb[0] = value;
    }
}
void lcd_test()
{
    // lcd_clear();
    // M5.lcd.setBrightness(uint8_t brightness);
    // M5.Lcd.drawPixel(int16_t x, int16_t y, uint16_t color);//!+
    // M5.Lcd.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);//!+

    // lcd_clear();
    // M5.Lcd.println("fillRect");
    // // M5.Lcd.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    // M5.Lcd.fillRect(100, 50, 100, 50, GREEN); //!+
    // delay(1000);

    // M5.Lcd.fillScreen(uint16_t color); //!+

    // lcd_clear();
    // M5.Lcd.println("drawCircle");
    // // M5.Lcd.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    // M5.Lcd.drawCircle(100, 100, 50, BLUE);//!+
    // delay(1000);

    // for (size_t i = 0; i < 16; i++)
    // {
    //     lcd_clear();
    //     M5.Lcd.println("drawCircleHelper " + String(i));
    //     // M5.Lcd.drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
    //     M5.Lcd.drawCircleHelper(100, 100, 50, i, RED);
    //     delay(300);
    // }

    // lcd_clear();
    // M5.Lcd.println("fillCircle");
    // // M5.Lcd.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    // M5.Lcd.fillCircle(100, 100, 50, GREEN); //!+
    // delay(1000);

    // for (size_t i = 1; i < 4; i++) //1-bot/2-top/3-bot+top
    // {
    //     for (size_t d = 0; d < 100; d++)//сдвиг по Х
    //     {
    //         lcd_clear();
    //         M5.Lcd.println("drawCircleHelper " + String(i) + " " + String(d));
    //         // M5.Lcd.fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color);
    //         M5.Lcd.fillCircleHelper(100, 100, 50, i, d, BLUE);//!+
    //         delay(50);
    //     }
    // }

    // lcd_clear();
    // M5.Lcd.println("drawTriangle");
    // // M5.Lcd.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    // M5.Lcd.drawTriangle(50,50,150,50,200,150, RED);//!+
    // delay(1000);

    // lcd_clear();
    // M5.Lcd.println("fillTriangle");
    // // M5.Lcd.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    // M5.Lcd.fillTriangle(50, 50, 150, 50, 200, 150, BLUE); //!+
    // delay(1000);

    // lcd_clear();
    // for (size_t r = 0; r < 300; r+=1)
    // {
    //     // M5.Lcd.println("drawRoundRect " + String(r));
    //     // M5.Lcd.println(r);
    //     // M5.Lcd.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
    //     int16_t w = 120, h = 120;
    //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, GREEN);//!+
    //     delay(20);
    //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);//!+
    // }
//!
    // lcd_clear();
    // for (size_t i = 0; i < 100; i++)
    // {
    //     int16_t w = 120, h = 120;
    //     // for (size_t r = 0; r < w; r++)
    //     // {
    //     //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(0, r , 0));
    //     //     delay(2);
    //     //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     // }
    //     for (size_t r = 0; r < w; r++)
    //     {
    //         M5.Lcd.drawRoundRect(0, 0, w, h, r, M5.Lcd.color565(r, 0, 0));
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF, 0, w, h, r, M5.Lcd.color565(0, r, 0));
    //         M5.Lcd.drawRoundRect(0, lcd_ns::HEIGHT_HALF, w, h, r, M5.Lcd.color565(0, 0, r));
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF, lcd_ns::HEIGHT_HALF, w, h, r, M5.Lcd.color565(r, r, r));
    //         delay(r / 10 + 1);
    //         // M5.Lcd.drawRoundRect(0, 0, w, h, r, BLACK);
    //         // M5.Lcd.drawRoundRect(w/2, 0, w, h, r, BLACK);
    //         // M5.Lcd.drawRoundRect(0, h/2, w, h, r, BLACK);
    //         // M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF, lcd_ns::HEIGHT_HALF, w, h, r, BLACK);
    //     }
    //     // for (size_t r = w; r > 0; r--)
    //     // {
    //     //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(r, 0, 0));
    //     //     delay(2);
    //     //     M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     // }
    // }

    lcd_clear();
    for (size_t i = 0; i < 100; i++)
    {
        int16_t w = 120, h = 120;
        for (size_t r = 0; r < w; r++)
        {
            colorNext_test(r);
            M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));
            // M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color8to16(r));
            delay(5);
            M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
        }
        colorNext_test(0, true);
        for (size_t r = w; r > 0; r--)
        {
            colorNext_test(r);
            M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));
            delay(5);
            M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
        }
        colorNext_test(0, true);
    }
//!
    // M5.Lcd.println("fillRect");
    // delay(4000);
    // M5.Lcd.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
    // M5.Lcd.drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
    // M5.Lcd.drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h),
    // M5.Lcd.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
    // M5.Lcd.setCursor(uint16_t x0, uint16_t y0);
    // M5.Lcd.setTextColor(uint16_t color);
    // M5.Lcd.setTextColor(uint16_t color, uint16_t backgroundcolor);
    // M5.Lcd.setTextSize(uint8_t size);
    // M5.Lcd.setTextWrap(boolean w);
    // M5.Lcd.printf();
    // M5.Lcd.print();
    // M5.Lcd.println();
    // M5.Lcd.drawCentreString(const char *string, int dX, int poY, int font);
    // M5.Lcd.drawRightString(const char *string, int dX, int poY, int font);
    // M5.Lcd.drawJpg(const uint8_t *jpg_data, size_t jpg_len, uint16_t x, uint16_t y);
    // M5.Lcd.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);
    // M5.Lcd.drawBmpFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);
}

void lcd_lines()
{
    for (size_t y = 0; y < lcd_ns::HEIGHT; y += 2)
    {
        M5.Lcd.drawFastHLine(0, y, lcd_ns::WIDTH, color_t::get_color("CYAN"));
        // M5.Lcd.draw(0, y, lcd_ns::WIDTH, color_t::get_color("CYAN"));
    }
}

void lcd_print(String msg)
{
    if (M5.Lcd.getCursorY() >= lcd_ns::HEIGHT - 1)
        lcd_clear();
    M5.Lcd.println(msg);
}

void rtc_test()
{
    lcd_print(rtc.getTime());
}

void time_routine2()
{
    // static int last_sec = -1;
    // int now_sec = rtc.getSecond();
    // if(last_sec == now_sec)
    //     return;
    // last_sec = now_sec;
    // M5.Lcd.fillScreen(c_back.get_color());
    // M5.Lcd.println(msg);

    static int last_min = -1;
    int now_min = rtc.getMinute();
    if (last_min == now_min)
        return;
    last_min = now_min;

    M5.Lcd.fillScreen(c_back.get_color());
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println(rtc.getTime());
    // M5.Lcd.println(c_back.get_colorName());

    Serial.println(rtc.getTime() + String("  ") + String(millis()));
}

void time_routine()
{
    // static int last_sec = -1;
    // int now_sec = rtc.getSecond();
    // if(last_sec == now_sec)
    //     return;
    // last_sec = now_sec;

    static int last_min = -1;
    int now_min = rtc.getMinute();
    if (last_min == now_min)
        return;
    last_min = now_min;

    M5.Lcd.fillScreen(c_back.get_color());
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println(rtc.getTime());
    // M5.Lcd.println(c_back.get_colorName());

    Serial.println(rtc.getTime() + String("  ") + String(millis()));
}

void textSize_test()
{
    for (size_t i = 0; i < 9; i++)
    {
        M5.Lcd.fillScreen(TFT_BLACK);

        M5.Lcd.setTextSize(i); // 0=1,2,3,4,5,6,7,8
        // M5.Lcd.setFreeFont(FreeMono9pt7b);
        // if(i == 0)          M5.Lcd.setFreeFont(LOAD_GFXFF);
        // else if(i == 1)     M5.Lcd.setFreeFont(LOAD_FONT2);
        // else if(i == 2)     M5.Lcd.setFreeFont(LOAD_FONT4);
        // else if(i == 3)     M5.Lcd.setFreeFont(LOAD_FONT6);
        // else if(i == 4)     M5.Lcd.setFreeFont(LOAD_FONT7);
        // else if(i == 5)     M5.Lcd.setFreeFont(LOAD_FONT8);
        // else if(i == 6)     M5.Lcd.setFreeFont(SMOOTH_FONT);

        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println(i);
        for (size_t c = 0; c < 20; c++)
        {
            M5.Lcd.println(F("0123456789"));
        }
        delay(1000);
    }
}

void btns_routine()
{
    if (M5.BtnA.pressedFor(10, 300))
    {
        lcd_print("Btn A: " + String(millis()));
        lcd_print("getCursor: " + String(M5.Lcd.getCursorY()));
        // lcd_print("getPivot: " + String(M5.Lcd.getPivotY()));

        Serial.println("BtnA wasPressed: " + String(millis()));
    }
    if (M5.BtnB.pressedFor(10, 300))
    {
        // lcd_print("Btn B: " + String(rtc.getTime()));
        // lcd_print("Привет");//!
        // lcd_lines();
        lcd_test();
        Serial.println("BtnB wasPressed: " + String(millis()));
    }
    if (M5.BtnC.pressedFor(10, 50))
    {
        Serial.println("BtnC wasPressed: " + String(millis()));
        // lcd_clear();
        // int32_t x = random() % lcd_ns::WIDTH;
        // int32_t y = random() % lcd_ns::HEIGHT;
        // lcd_print("x: " + String(x) + " / y: " + String(y));
        // M5.Lcd.drawPixel(x, y, color_t::get_color("YELLOW"));

        int32_t x = random() % lcd_ns::WIDTH;
        int32_t y = random() % lcd_ns::HEIGHT;
        int32_t x2 = random() % lcd_ns::WIDTH;
        int32_t y2 = random() % lcd_ns::HEIGHT;
        M5.Lcd.drawLine(x, y, x2, y2, COLORS[random(COLORS_COUNT)].code);

        return;
        lcd_enable = !lcd_enable;
        lcd_enable ? M5.lcd.wakeup() : M5.lcd.sleep();
    }
}

void test_init()
{
    // Connect to Wi-Fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");

    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    // printLocalTime();

    // rtc.setTime(DateTime(F(__DATE__), F(__TIME__))); // 17th Jan 2021 15:24:30
    // rtc.setTime(30, 24, 15, 17, 1, 2021); // 17th Jan 2021 15:24:30
    /*---------set with NTP---------------*/
    // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);//!-
    // struct tm timeinfo;
    // if (getLocalTime(&timeinfo))
    // {
    //     rtc.setTimeStruct(timeinfo);
    // }

    M5.begin();
    M5.Power.begin();
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(0, 0);
    // M5.Lcd.fillRect

    Serial.setTimeout(20);
    M5.Lcd.println(F("Upload: "));
    M5.Lcd.println(F(__DATE__));
    M5.Lcd.println(F(__TIME__));
    // M5.Lcd.println(F(CIRCUIT_NAME));
    // M5.Lcd.println(F("Init done!"));
    delay(1000);
    // textSize_test();
}

void test_routine()
{
    if (Serial.available())
    {
        String msg = Serial.readString();
        if (msg == "+")
        {
            c_back.index++;
        }
        else
        {
            // size_t number = atoi(msg.c_str());
            c_back.index = atoi(msg.c_str()) % COLORS_COUNT;
        }
        Serial.println(msg);
        Serial.println(c_back.get_color());

        lcd_print(msg);
    }

    M5.update(); // btns, spk check
    btns_routine();
    time_routine();
}