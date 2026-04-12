#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

String isiquote = "Yang patah tumbuh, yang hilang berganti";

void setup() {
  lcd.init();       // Memulai LCD
  lcd.backlight();  // Menyalakan lampu latar LCD

  // Baris Statis
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
}

void loop() {
  // Menggunakan isiquote.length()
  int panjangTeks = isiquote.length();

  // 'offset' adalah posisi awal teks
  for (int offset = 15; offset > -panjangTeks; offset--) {
    
    lcd.setCursor(0, 1); // Selalu set ke awal baris ke-2
    String frame = "";   // Penampung teks sementara
    
    // Looping untuk membuat persis 16 karakter yang pas di layar
    for (int i = 0; i < 16; i++) {
      int indexKarakter = i - offset;
      
      // Jika posisi kursor pas dengan huruf pada isiquote, tampilkan hurufnya
      if (indexKarakter >= 0 && indexKarakter < panjangTeks) {
        frame += isiquote[indexKarakter];
      } 
      // Jika tidak (sebelum/sesudah isiquote), isi dengan spasi otomatis
      else {
        frame += " ";
      }
    }
    
    lcd.print(frame); // Tampilkan frame berisi 16 karakter ke layar
    
    delay(150); // Kecepatan scroll
  }
}