#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
String quote = "Jatuh 7 kali bangkit 8 kali";
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  // "QUOTE" di tengah
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  int panjang = quote.length();
  //teks akan muncul dari kolom ke 15, atau muncul dari kanan ke kiri
  for (int i = 15; i >= -panjang; i--) {
    lcd.setCursor(0, 1);
    lcd.setCursor(i, 1);
    lcd.print(quote); //ini teks yang akan ditampilkan
  }
}
