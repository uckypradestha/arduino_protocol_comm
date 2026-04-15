#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0); // object untuk mengakses lcd
String text[2] = { // text yang akan di tampilkan
    "QUOTE",
    "                Terima kasih sudah mengingatkan "
};

int startIndex = 0; // menampung index per loop
int strLength; // variabel penampung panjang string text[1]

void setup() {
    if (!lcd.begin(16, 2)) { // menyiapkan lcd
        while (1);
    }

    strLength = text[1].length(); // menghitung panjang teks text[1]

    lcd.setBacklight(HIGH); // menyalakan backlight
    lcd.clear(); // membersihkan lcd
    lcd.setCursor((16 / 2) - (text[0].length() / 2 + 1), 0); // mengatur cursor agar menempatkan text di tengah secara otomatis
    lcd.print(text[0]); // menampilkan text[0]
}

void loop() {
    String cur = ""; // variabel penampung text yang akan di tampilkan secara scrolling

    for (int i = 0; i < 16; i++) { // looping untuk scroll text (text[1])
        int curIndex = (startIndex + i) % strLength; // mendapatkan index untuk menampilkan text berdasarkan ukuran layar
        cur += text[1][curIndex]; // mendapatkan char sesuai curIndex
    }

    lcd.setCursor(0, 1); // memindahkan kursor ke (0, 1)
    lcd.print(cur); // menampilkan scrolling text
    startIndex++;
}