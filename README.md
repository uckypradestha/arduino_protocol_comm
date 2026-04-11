#
 LCD I2C Quotes Scroller 📝

Proyek ini menampilkan teks statis di baris pertama dan teks berjalan (*scrolling text*) secara dinamis di baris kedua menggunakan LCD 16x2 berbasis I2C pada platform Arduino.

---

## 👤 Identitas Pengembang
* **Nama**: Muhammad Faizal Khabibi
* **NIM**: [H1H024003]
* **Mata Kuliah**: Sistem Mikrokontroler

---

## 🔗 Tautan Penting
* **Dokumentasi Project**: [https://drive.google.com/drive/folders/1UmvzX9VzSyuwt3QRjAmuEvVWszXSFLjd?usp=drive_link]
* **Simulasi Tinkercad**: [https://www.tinkercad.com/things/cFYrnTUh8yO-modul-6muhammad-faizal-khabibih1h024003?sharecode=1jOS1lLcVEkJ1Dt-tJ3DtIryYM357nhkbGh01Yz6-SY]

---

## 🛠️ Komponen & Skema
1. **Arduino Uno**
2. **LCD 16x2 dengan Modul I2C** (Alamat: `0x27` atau `0x20`)
3. **Kabel Jumper**

| LCD I2C | Arduino |
|---------|---------|
| GND     | GND     |
| VCC     | 5V      |
| SDA     | A4      |
| SCL     | A5      |

---

## 💻 Kode Program

```cpp
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD pada alamat 0x27, 16 kolom, 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init();      // Inisialisasi hardware LCD
  lcd.backlight(); // Menyalakan lampu latar LCD
}

void loop() {
  // Kalimat yang akan ditampilkan
  String quote = "Jangan berkembang biak sebelum berkembang baik";
  int len = quote.length();
  
  // Perulangan untuk mengatur posisi teks dari kanan ke kiri
  for (int pos = 15; pos >= -len; pos--) {
    
    // 1. Tampilkan Baris Statis (Baris Atas)
    lcd.setCursor(5, 0);
    lcd.print("QUOTES");
    
    // 2. Logika Gerak Baris 2 (Baris Bawah)
    if (pos >= 0) {
      // Fase teks mulai muncul dari sisi kanan layar
      lcd.setCursor(pos, 1);
      lcd.print(quote.substring(0, 16 - pos));
    } else {
      // Fase teks bergeser keluar layar ke arah kiri
      lcd.setCursor(0, 1);
      lcd.print(quote.substring(-pos, -pos + 16));
    }
    
    delay(300); // Mengatur kecepatan pergerakan teks (300ms)
    
    // Membersihkan baris bawah secara spesifik agar tidak terjadi penumpukan karakter
    lcd.setCursor(0, 1);
    lcd.print("                "); 
  }
}
