# Penjelasan Source Code I2C Scrolling Text

## 1. Penggunaan Library
Program ini terdapat dua library utama
- #include <Wire.h> - Library bawaan Arduino untuk mengaktifkan protokol komunikasi I2C pada pin SDA dan SCL
- #include <LiquidCrystal_I2C.h> - Library khusus untuk mengontrol layar LCD yang menggunakan modul I2C (chip PCF8574)

## 2. Inisialisasi (Setup)
Pada blok void setup(), dilakukan beberapa pengaturan awal
- lcd.init() dan lcd.backlight() digunakan untuk menyalakan layar dan lampu latar LCD
- Pencetakan Baris Statis, Menggunakan lcd.setCursor(5, 0) untuk menaruh kursor di kolom ke-6 baris pertama. Kemudian mencetak kata QUOTE agar posisinya berada tepat di tengah layar

## 3. Looping (Logika Scrolling)
Program ini menggunakan manipulasi string pada blok void loop() agar baris pertama tetap statis.

- Menghitung Panjang Teks - isiquote.length() digunakan untuk mengetahui jumlah karakter yang ada
- Offset Kursor - Terdapat perulangan for dengan variabel offset yang dimulai dari angka 15 (ujung kanan) hingga nilai minus panjang teks
- Pembentukan Frame - Program membaca karakter satu per satu. Jika posisi sesuai dengan huruf pada isiquote, karakter ditampilkan. Jika posisinya kosong, program otomatis menggantinya dengan spasi
- Hasil - Logika ini menciptakan animasi teks berjalan hanya pada baris kedua, muncul dari kanan dan menghilang di sebelah kiri secara mulus dengan delay(150)