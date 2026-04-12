# Scrolling Text LCD I2C (Arduino)

* **Nama**: Ardina Jihan Mariska
* **NIM**: H1H024018
* **Kelas**: SISTEM MIKROKONTROLER A

## Deskripsi Program

Program ini bertujuan untuk menampilkan dua jenis teks pada LCD 16x2 menggunakan komunikasi I2C, yaitu:

1. Teks statis pada baris pertama berupa tulisan QUOTE yang ditampilkan di tengah layar.
2. Teks dinamis (scrolling text)** pada baris kedua berupa kalimat motivasi yang bergerak dari kanan ke kiri.

Scrolling text digunakan untuk menampilkan teks yang lebih panjang dari kapasitas LCD (16 karakter), sehingga teks dapat tetap terbaca secara keseluruhan.


## Alat dan Bahan

* Arduino Uno
* LCD 16x2 I2C
* Kabel jumper


## Konfigurasi Pin

| LCD I2C | Arduino       |
| ------- | ------------- |
| GND     | GND           |
| VCC     | 5V            |
| SDA     | SDA (atau A4) |
| SCL     | SCL (atau A5) |


## 💻 Kode Program

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // Mengaktifkan LCD
  lcd.backlight();   // Menyalakan lampu latar
}

void loop() {

  // Teks yang akan ditampilkan
  String text = "Never give up on your dreams, keep going.";

  int panjang = text.length();

  // Perulangan untuk efek scrolling dari kanan ke kiri
  for (int posisi = 15; posisi >= -(panjang - 16); posisi--) {

    // Menampilkan teks statis di tengah baris pertama
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");

    // Membersihkan baris kedua sebelum menampilkan teks baru
    lcd.setCursor(0, 1);
    lcd.print("                ");

    // Logika menampilkan teks secara bertahap
    if (posisi >= 0) {
      lcd.setCursor(posisi, 1);
      lcd.print(text.substring(0, 16 - posisi));
    } else {
      lcd.setCursor(0, 1);
      lcd.print(text.substring(-posisi, -posisi + 16));
    }

    delay(100); // Mengatur kecepatan pergeseran teks
  }
}
```

## Penjelasan Kode

### 1. Library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
Digunakan untuk komunikasi I2C dan mengontrol LCD.

### 2. Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

* `0x27` → alamat I2C LCD
* `16, 2` → ukuran LCD (16 kolom, 2 baris)

### 3. Fungsi setup()
lcd.init();
lcd.backlight();
* Mengaktifkan LCD
* Menyalakan lampu latar

### 4. Variabel Teks
String text = "Never give up, on your dreams";
Berisi kalimat yang akan ditampilkan secara scrolling.

### 5. Perulangan Scrolling
for (int posisi = 15; posisi >= -(panjang - 16); posisi--) {
Digunakan untuk menggeser teks dari kanan ke kiri.

### 6. Menampilkan Teks Statis
lcd.setCursor(5, 0);
lcd.print("QUOTE");
Menampilkan tulisan "QUOTE" di tengah baris pertama.

### 7. Membersihkan Baris Kedua
lcd.print("                ");
Digunakan untuk menghapus sisa karakter sebelumnya agar tampilan tidak bertumpuk.

### 8. Logika Scrolling
if (posisi >= 0)
* Jika teks masih di sebelah kanan, tampilkan sebagian teks
* Jika sudah masuk layar, tampilkan bagian tengah teks

### 9. Delay
delay(100);
Mengatur kecepatan pergerakan teks agar terlihat halus.

## Kesimpulan

Program ini berhasil menampilkan teks statis dan dinamis pada LCD I2C. Teknik scrolling memungkinkan teks panjang ditampilkan secara bertahap sehingga lebih informatif dan menarik.

## Output

* Baris 1: **QUOTE:** (statis di tengah)
* Baris 2: **Scrolling text** dari kanan ke kiri

## link thinkercad 
https://www.tinkercad.com/things/7DPT8fNEex2-i2c-ardina-jihan-mariskah1h024018