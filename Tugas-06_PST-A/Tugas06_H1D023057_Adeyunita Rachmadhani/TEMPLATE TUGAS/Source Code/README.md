# Penjelasan Source Code

Program ini digunakan untuk menampilkan **teks berjalan (scrolling text)** pada LCD 16x2 berbasis **I2C** menggunakan library `Adafruit_LiquidCrystal`. Tampilan LCD dibagi menjadi dua baris, yaitu baris pertama untuk judul statis **"QUOTE"**, sedangkan baris kedua digunakan untuk menampilkan isi kutipan yang bergerak dari kanan ke kiri.

## Library yang Digunakan

Program ini menggunakan dua library, yaitu:

- `Wire.h`  
  Library ini digunakan untuk komunikasi **I2C** antara Arduino dan LCD.

- `Adafruit_LiquidCrystal.h`  
  Library ini digunakan untuk mengontrol LCD 16x2 yang terhubung melalui modul I2C.

## Inisialisasi Objek LCD
```
Adafruit_LiquidCrystal lcd(0);
```
Baris ini digunakan untuk membuat objek LCD dengan alamat I2C default pada library yang digunakan. Objek `lcd` nantinya dipakai untuk mengatur tampilan LCD, seperti menampilkan teks, mengatur posisi kursor, membersihkan layar, dan menyalakan backlight.

## Variabel Teks
```
String teks = "Find what you love and let it kill you -Bukowski.   ";
```
Variabel `teks` digunakan untuk menyimpan isi quote yang akan ditampilkan pada baris kedua LCD. Pada bagian akhir teks ditambahkan beberapa spasi agar tampilan scroll terlihat lebih halus saat pengulangan dimulai kembali.

## Fungsi setup()
Fungsi setup() dijalankan satu kali saat Arduino dinyalakan. Pada bagian ini dilakukan inisialisasi LCD dengan ukuran 16 kolom dan 2 baris menggunakan:
```
lcd.begin(16, 2);
```
Selanjutnya backlight LCD dinyalakan dengan:
```
lcd.setBacklight(HIGH);
```
Layar LCD kemudian dibersihkan menggunakan:
```
lcd.clear();
```
Setelah itu, program menampilkan tulisan "QUOTE" pada baris pertama sebagai judul statis. Posisi kursor diletakkan di kolom ke-5 baris ke-0 agar tulisan berada mendekati tengah layar.
```
lcd.setCursor(5, 0);
lcd.print("QUOTE");
```

## Fungsi loop()
Fungsi loop() dijalankan secara berulang selama Arduino aktif. Pada bagian ini, program membuat variabel baru bernama scrollText yang berisi 16 spasi di depan dan 16 spasi di belakang teks utama.
```
String scrollText = "                " + teks + "                ";
```
Penambahan spasi di depan bertujuan agar teks terlihat masuk dari sisi kanan LCD, sedangkan spasi di belakang memberi jarak sebelum animasi diulang kembali. Selanjutnya digunakan perulangan:
```
for (int i = 0; i <= scrollText.length() - 16; i++)
```
Perulangan ini berfungsi untuk mengambil potongan teks sepanjang 16 karakter, sesuai lebar LCD, kemudian menampilkannya secara bergeser satu per satu.

Pada setiap iterasi, baris pertama tetap menampilkan tulisan "QUOTE":
```
lcd.setCursor(5, 0);
lcd.print("QUOTE");
```
Setelah itu, program menampilkan potongan teks pada baris kedua mulai dari kolom 0 baris 1:
```
Setelah itu, program menampilkan potongan teks pada baris kedua mulai dari kolom 0 baris 1:
```
Fungsi substring(i, i + 16) digunakan untuk mengambil 16 karakter dari teks panjang, sehingga terbentuk efek scrolling dari kanan ke kiri.

Untuk mengatur kecepatan pergeseran teks, digunakan:
```
delay(200);
```
Nilai delay 200 ms berarti setiap perpindahan satu karakter membutuhkan waktu 0,2 detik. Semakin kecil nilainya, semakin cepat teks bergerak.