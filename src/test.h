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
        // lcd_test();
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
    // M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setTextColor(WHITE, BLACK);
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