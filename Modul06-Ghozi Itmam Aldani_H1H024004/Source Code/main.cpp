#include <Adafruit_LiquidCrystal.h> 

Adafruit_LiquidCrystal lcd(0);

String textAtas = "QUOTE";
String textBawah = "     quote     ";

int posisi = 0;
int panjang;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor((16 - textAtas.length()) / 2, 0);
  lcd.print(textAtas);

  panjang = textBawah.length();
}

void loop() {
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    int index = (posisi + i) % panjang;
    lcd.print(textBawah[index]);
  }

  posisi++;

  // Reset otomatis
  if (posisi >= panjang) {
    posisi = 0;
  }

  delay(300);
}