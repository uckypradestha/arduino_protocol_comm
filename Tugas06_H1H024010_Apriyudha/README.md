
# Sistem Mikrokontroller A - Tugas 6

Apriyudha  |  H1H024010

---

Repository ini berisi dua percobaan penggunaan LCD I2C menggunakan Arduino, yaitu:
1. Menampilkan teks statis pada LCD
2. Menampilkan teks berjalan (scrolling text)

---

## 1. Library yang Digunakan

Pada kedua program digunakan library berikut:

```cpp
#include <Adafruit_LiquidCrystal.h>
````

Library ini digunakan untuk mengontrol LCD I2C dengan fungsi utama seperti:

* `begin()` untuk inisialisasi LCD
* `setCursor()` untuk menentukan posisi teks
* `print()` untuk menampilkan teks
* `clear()` untuk membersihkan layar
* `setBacklight()` untuk mengatur lampu latar

---

## 2. Program 1: PrintI2C.ino (Teks Statis)

### Kode Program

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);        // Inisialisasi LCD 16x2
  lcd.clear();             // Membersihkan layar
  lcd.setBacklight(HIGH);  // Menyalakan backlight

  lcd.setCursor(3, 0);     // Kolom 3, baris 0
  lcd.print("Apriyudha");

  lcd.setCursor(3, 1);     // Kolom 3, baris 1
  lcd.print("H1H024010");
}

void loop() {
}
```

### Penjelasan

**Inisialisasi:**

* Membuat objek LCD dengan `Adafruit_LiquidCrystal lcd(0)`
* Mengatur ukuran LCD 16x2
* Membersihkan layar dan menyalakan backlight

**Output:**

* Baris pertama menampilkan nama
* Baris kedua menampilkan NIM

**Looping:**

* Tidak digunakan karena tampilan bersifat statis

---

## 3. Program 2: ScrollingTextI2C.ino (Scrolling Text)

### Kode Program

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "                Ini contoh scrolling text I2C!                ";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  // Baris atas (statis)
  lcd.setCursor(3, 0);
  lcd.print("H1H024010");
}

void loop() {
  for (int i = 0; i < text.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(i, i + 16)); 

    delay(200);
  }
}
```

### Penjelasan

**Inisialisasi:**

* Variabel `text` berisi kalimat panjang dengan spasi di awal dan akhir
* Spasi digunakan agar efek scrolling lebih halus

**Tampilan:**

* Baris pertama: teks statis (NIM)
* Baris kedua: teks berjalan

**Looping:**

* Menggunakan perulangan `for`
* `substring(i, i + 16)` menampilkan 16 karakter
* `delay(200)` mengatur kecepatan scrolling

---

## 4. Dokumentasi Video

### PrintI2C.ino - Teks Statis

https://github.com/user-attachments/assets/f3b5aa6d-5c00-454d-8c08-4330dd4b470f

Thinkercad: https://www.tinkercad.com/things/gfuPMpA2tJ5/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=tZw8EN3v_A9JJjYOf_cTYIt-ROdLiHFk8ok8MvoHWqs

---

### ScrollingTextI2C.ino - Scrolling Text

https://github.com/user-attachments/assets/8357008f-1828-4353-845b-427919490a18

Thinkercad: https://www.tinkercad.com/things/lvCcVB6KBxO/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=bBLI6H8hRX6WlN9Yr2DO82-QKa7bZHI1kTaDME5Ufqg

---

## 5. Kesimpulan

* LCD I2C lebih efisien karena menggunakan sedikit pin
* Library Adafruit_LiquidCrystal mempermudah pengontrolan LCD
* Program pertama menampilkan teks statis
* Program kedua menampilkan teks berjalan (scrolling)
* Scrolling text berguna untuk menampilkan informasi panjang

---
Sistem Mikrokontroller A - Tugas 6
