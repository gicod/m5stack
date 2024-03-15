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

void lcd_test_def()
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

//!
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

    // lcd_clear();
    // for (size_t i = 0; i < 100; i++)
    // {
    //     int16_t w = 120, h = 120;
    //     for (size_t r = 0; r < w; r++)
    //     {
    //         colorNext_test(r);
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));
    //         // M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color8to16(r));
    //         delay(5);
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     }
    //     colorNext_test(0, true);
    //     for (size_t r = w; r > 0; r--)
    //     {
    //         colorNext_test(r);
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));
    //         delay(5);
    //         M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     }
    //     colorNext_test(0, true);
    // }
//!
    // lcd_clear();
    // for (size_t i = 0; i < 100; i++)
    // {
    //     int16_t w = 120, h = 120;
    //     size_t cycle = w;
    //     for (size_t r = 0; r < cycle; r++)
    //     {
    //         colorNext_test(r);
    //         // M5.Lcd.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
    //         M5.Lcd.fillRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));//!+
    //         // M5.Lcd.drawRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color8to16(r));
    //         delay(100);
    //         M5.Lcd.fillRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     }
    //     colorNext_test(0, true);
    //     for (size_t r = cycle; r > 0; r--)
    //     {
    //         colorNext_test(r);
    //         M5.Lcd.fillRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, M5.Lcd.color565(rgb[0], rgb[1], rgb[2]));
    //         delay(100);
    //         M5.Lcd.fillRoundRect(lcd_ns::WIDTH_HALF - w/2, lcd_ns::HEIGHT_HALF - h/2, w, h, r, BLACK);
    //     }
    //     colorNext_test(0, true);
    // }

    // M5.Lcd.drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);//!-
    // M5.Lcd.drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);//!-

    // lcd_clear();
    // M5.Lcd.println("drawChar");
    // // M5.Lcd.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
    // {
    //     for (char c = '0',i = 48; c < '}'; c++, i++)
    //     {
    //         M5.Lcd.setTextColor(WHITE, BLACK);
    //         M5.Lcd.setCursor(220, 0);
    //         M5.Lcd.println(i, 10);

    //         // for (size_t s = 1; s < 10; s++)
    //         M5.Lcd.drawChar(0, 40, c, WHITE, BLACK, 1);//!+
    //         M5.Lcd.drawChar(60, 40, c, WHITE, BLACK, 2);
    //         M5.Lcd.drawChar(120, 40, c, WHITE, BLACK, 3);
    //         M5.Lcd.drawChar(180, 40, c, WHITE, BLACK, 4);
    //         M5.Lcd.drawChar(240, 40, c, WHITE, BLACK, 5);

    //         M5.Lcd.drawChar(0, 80, c, WHITE, BLACK, 6);
    //         M5.Lcd.drawChar(80, 80, c, WHITE, BLACK, 7);
    //         M5.Lcd.drawChar(160, 80, c, WHITE, BLACK, 8);
    //         M5.Lcd.drawChar(240, 80, c, WHITE, BLACK, 9);

    //         M5.Lcd.drawChar(0, 145, c, WHITE, BLACK, 10);
    //         M5.Lcd.drawChar(80, 145, c, WHITE, BLACK, 11);
    //         M5.Lcd.drawChar(160, 145, c, WHITE, BLACK, 12);
    //         M5.Lcd.drawChar(240, 145, c, WHITE, BLACK, 13);
    //         delay(500);
    //     }        
    // }    
    
    // M5.Lcd.setCursor(uint16_t x0, uint16_t y0);//!+
    // M5.Lcd.setTextColor(uint16_t color);//!+
    // M5.Lcd.setTextColor(uint16_t color, uint16_t backgroundcolor);//!+
    // M5.Lcd.setTextSize(uint8_t size);//!+

    // lcd_clear();
    // M5.Lcd.println("setTextWrap");
    // // M5.Lcd.setTextWrap(boolean w);
    // M5.Lcd.setTextSize(4);
    // M5.Lcd.setTextWrap(true);//!+
    // M5.Lcd.println("true");
    // M5.Lcd.println("01234567890123456789");
    // M5.Lcd.println("false");
    // M5.Lcd.setTextWrap(false);
    // M5.Lcd.println("01234567890123456789");
    // delay(3000);

    // lcd_clear();
    // M5.Lcd.printf();//!+-
    // M5.Lcd.printf("printf");
    // delay(3000);

    // M5.Lcd.print();//!+
    // M5.Lcd.println();//!+

    // lcd_clear();
    // M5.Lcd.println("drawCentreString");
    // M5.Lcd.setTextColor(BLUE, BLACK);
    // // M5.Lcd.drawCentreString(const char *string, int dX, int poY, int font);
    // for (size_t i = 1; i < 9; i++)
    // {
    //     M5.Lcd.setCursor(0, 50);
    //     M5.Lcd.println(i);
    //     M5.Lcd.drawCentreString("01", 160, 50, i);//!+ не раб шрифт 3 5 7 9 и выше
    //     delay(500);        
    // }
    // lcd_clear();
    // for (size_t i = 1; i < 9; i++)
    // {
    //     M5.Lcd.setCursor(0, 0);
    //     M5.Lcd.println(i);
    //     M5.Lcd.drawCentreString("012345678", 160, 50, i);//!+ в шрифт 4 уже помещается
    //     delay(2000);        
    // }
    // lcd_clear();
    // M5.Lcd.drawCentreString("69", 160, 120, 8);//!+
    // delay(3000);

    // lcd_clear();
    // M5.Lcd.println("drawRightString");
    // M5.Lcd.setTextColor(GREEN, BLACK);
    // // M5.Lcd.drawRightString(const char *string, int dX, int poY, int font);
    // for (size_t i = 1; i < 8; i++)
    // {
    //     M5.Lcd.setCursor(0, 30);
    //     M5.Lcd.println(i);
    //     M5.Lcd.drawRightString("01", 320, 50, i);//!+ не раб шрифт 3 5
    //     delay(2000);        
    // }

    // M5.Lcd.drawJpg(const uint8_t *jpg_data, size_t jpg_len, uint16_t x, uint16_t y);//! ?
    // M5.Lcd.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);//! ?
    // M5.Lcd.drawBmpFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);//! ?
}
