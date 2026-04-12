#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

String quoteText = "Ikan hiu makan tomat tamat";

const int LCD_COLS = 16;
const int SCROLL_DELAY = 280;
const int PAUSE_END = 1200;

void setup()
{
    lcd_1.begin(16, 2);
    lcd_1.setBacklight(1);

    lcd_1.setCursor(5, 0);
    lcd_1.print("QUOTE");
}

void hapusBaris1()
{
    lcd_1.setCursor(0, 1);
    lcd_1.print("                ");
}

void scrollBaris1(String teks)
{
    int panjangTeks = teks.length();
    int totalFrame = panjangTeks + LCD_COLS;

    for (int frame = 0; frame < totalFrame; frame++)
    {
        hapusBaris1();

        for (int col = 0; col < LCD_COLS; col++)
        {
            int idx = frame - (LCD_COLS - 1) + col;
            if (idx >= 0 && idx < panjangTeks)
            {
                lcd_1.setCursor(col, 1);
                lcd_1.print(teks[idx]);
            }
        }

        delay(SCROLL_DELAY);
    }

    delay(PAUSE_END);
}

void loop()
{
    scrollBaris1(quoteText);
}