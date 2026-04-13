# Tugas 6 Sistem Mikrokontroler A

Nama : Maharani Tri Wahyuningrum\
NIM : H1H024012

## Kode Program
```cpp
#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd_1(0);

String quote = "Say The Name, SEVENTEEN!";

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setCursor(5, 0);
  lcd_1.print("QUOTE");
}

void loop() {
  String fullText = "                " + quote + "                ";
  for (int i = 0; i < fullText.length() - 16; i++) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(fullText.substring(i, i + 16));
    delay(100); 
  }
}
