#include <LiquidCrystal_I2C.h>

// inisialisasi LCD alamat 0x27 ukuran 16 kolom 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

// teks baris atas (statis)
String top = "QUOTE:";

// teks baris bawah (dinamis / scrolling)
String bottom = "Man Jadda Wajada - Barang siapa bersungguh-sungguh, maka ia akan berhasil";

void setup() {
  lcd.init();        // memulai LCD
  lcd.backlight();   // menyalakan lampu LCD

  // hitung posisi tengah otomatis
  int posisi = (16 - top.length()) / 2;

  lcd.setCursor(posisi, 0);
  lcd.print(top);

  // menambahkan spasi depan & belakang agar muncul dari kanan
  bottom = "                " + bottom + "                ";
}

void loop() {

  // perulangan untuk menggeser teks
  for (int i = 0; i < bottom.length() - 16; i++) {

    lcd.setCursor(0, 1);  // posisi baris kedua
    lcd.print(bottom.substring(i, i + 16)); // tampilkan 16 karakter

    delay(150); // kecepatan scroll
  }
}