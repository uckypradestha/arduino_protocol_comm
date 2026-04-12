# DOKUMENTASI — LCD Scrolling Quote (Arduino)

## Deskripsi Singkat

Program ini mengimplementasikan **teks berjalan (scrolling text)** pada **LCD 16x2** menggunakan Arduino dan library **Adafruit LiquidCrystal**. Teks kutipan ditampilkan pada baris kedua LCD dengan efek masuk dari sisi kanan layar dan bergerak ke kiri secara bertahap.

Program memanfaatkan manipulasi **substring** untuk menampilkan sebagian teks sesuai jumlah kolom LCD (16 karakter).

---

## Fitur Program

* Menampilkan judul **"QUOTE"** pada baris pertama LCD
* Menampilkan **teks berjalan** pada baris kedua
* Efek teks masuk dari kondisi kosong (kanan layar)
* Menggunakan teknik **scrolling substring**
* Kompatibel dengan LCD 16x2 berbasis I2C

---

## Schematic View Rangkaian

Berikut adalah tampilan rangkaian yang digunakan pada simulasi:

**(Tambahkan gambar schematic di sini)**


---

## Video Simulasi

Video berikut menunjukkan hasil simulasi program berupa efek teks berjalan pada LCD.

**(Tambahkan video di sini)**


---

## Hasil Akhir

Output yang dihasilkan berupa:

* Judul **"QUOTE"** pada baris pertama
* Teks berjalan pada baris kedua
* Efek teks muncul dari kanan lalu bergeser ke kiri hingga selesai

---

## Catatan

Program ini menunjukkan implementasi dasar **output LCD** pada sistem tertanam serta penggunaan manipulasi string untuk menciptakan efek visual sederhana pada tampilan LCD.
