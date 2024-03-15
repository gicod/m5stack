#include "test.h"
void rtc_test()
{
    // Serial.println(rtc.getTime()); //  (String) 15:24:38
    // Serial.println(rtc.getSecond());    //  (int)     38    (0-59)
    // Serial.println(rtc.getMinute());    //  (int)     24    (0-59)
    // Serial.println(rtc.getHour());      //  (int)     3     (0-12)
    // Serial.println(rtc.getHour(true));  //  (int)     15    (0-23)
    // Serial.println(rtc.getAmPm());      //  (String)  pm
    // Serial.println(rtc.getAmPm(true));  //  (String)  PM
    // Serial.println(rtc.getDay());       //  (int)     17    (1-31)
    // Serial.println(rtc.getDayofWeek()); //  (int)     0     (0-6)
    // Serial.println(rtc.getDayofYear()); //  (int)     16    (0-365)
    // Serial.println(rtc.getMonth());     //  (int)     0     (0-11)
    // Serial.println(rtc.getYear());      //  (int)     2021
    // Serial.println(rtc.getTimeDate()); //  (String) 15:24:38 Sun, Jan 17 2021
    // Serial.println(rtc.getTimeDate(true));  //  (String) 15:24:38 Sunday, January 17 2021
    
    // struct tm timeinfo;
    // if (!getLocalTime(&timeinfo))
    // {
    //     Serial.println("Failed to obtain time");
    //     return;
    // }
    // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

    // lcd_print(rtc.getTime());
}

void lcd_test()
{
    // lcd_clear();
    // M5.lcd.setBrightness(uint8_t brightness);
    // M5.Lcd.drawPixel(int16_t x, int16_t y, uint16_t color);
    // M5.Lcd.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color); 
    // M5.Lcd.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color); 
    // M5.Lcd.fillScreen(uint16_t color); 
    // M5.Lcd.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color); 
    // M5.Lcd.drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,uint16_t color);
    // M5.Lcd.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    // M5.Lcd.fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color); 
    // M5.Lcd.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    // M5.Lcd.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color); 
    // M5.Lcd.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
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