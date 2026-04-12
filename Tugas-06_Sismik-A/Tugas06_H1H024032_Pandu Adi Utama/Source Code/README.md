# Penjelasan Kode 'main.cpp'

Program ini digunakan untuk mengendalikan LCD 16x2 melalui komunikasi I2C dengan bantuan library Adafruit LiquidCrystal. Tampilan LCD terdiri dari teks tetap pada baris pertama dan teks bergerak pada baris kedua.

## 1. Import Library
```cpp
#include <Adafruit_LiquidCrystal.h>
```

Baris ini berfungsi untuk memanggil library yang diperlukan agar Arduino dapat berkomunikasi dengan LCD melalui I2C.


## 2. Inisialisasi LCD
```cpp
Adafruit_LiquidCrystal lcd(0);
```

Objek lcd dibuat dengan alamat I2C 0. Objek ini nantinya digunakan untuk mengakses berbagai fungsi LCD seperti menampilkan teks dan mengatur posisi kursor.

## 3. Deklarasi Variabel
```cpp
String teksStatis = "QUOTE";
String teksDinamis = "                Bapak Mulyono Raja Tipu-Tipu                ";
```

Teks pertama digunakan sebagai tampilan tetap di baris atas. Teks kedua digunakan sebagai teks berjalan. Spasi tambahan di awal dan akhir membantu menciptakan efek animasi yang lebih halus.

## 4. Fungsi setup()
```cpp
void setup() {
  lcd.begin(16, 2); // Mengatur LCD ukuran 16 kolom x 2 baris
  lcd.clear(); // Mengosongkan tampilan LCD saat dinyalakan
  lcd.setBacklight(HIGH); // Menyalakan lampu backlight LCD

// Mengatur posisi tengah untuk teks "QUOTE"
  int posisiTengah = (16 - teksStatis.length()) / 2;
  
  lcd.setCursor(posisiTengah, 0); // Mengatur teks agar muncul di tengah baris pertama
  lcd.print(teksStatis);  // Menampilkan teks statis
}

```

Pada bagian ini, LCD diinisialisasi dengan ukuran 16x2, kemudian layar dibersihkan dan lampu latar diaktifkan. Selanjutnya dilakukan perhitungan untuk menentukan posisi tengah agar teks dapat tampil rapi di bagian atas. Setelah itu, teks statis ditampilkan pada posisi tersebut.

## 5. Fungsi loop()
```cpp
void loop() {
  
  // Looping animasi berjalan dari kanan ke kiri
  for (int i = 0; i <= teksDinamis.length() - 16; i++) {
    lcd.setCursor(0, 1);  // Mengatur teks agar muncul di awal baris kedua
    lcd.print(teksDinamis.substring(i, i + 16)); // Menampilkan teks mulai dari indeks ke-i
    delay(300); // Delay untuk mengatur kecepatan animasi
}
```
Bagian ini bertugas menjalankan animasi teks berjalan secara terus-menerus. Program mengambil potongan teks sepanjang 16 karakter sesuai lebar LCD, kemudian menampilkannya di baris kedua. Proses ini diulang dengan menggeser posisi awal teks sehingga terlihat bergerak dari kanan ke kiri. Delay digunakan untuk mengatur kecepatan pergerakan teks.
