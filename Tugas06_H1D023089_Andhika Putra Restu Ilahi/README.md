# Modul 06: Scrolling Text Dengan I2C LCD

Repositori ini berisi tugas mata kuliah Pemrograman Sistem Tertanam untuk membuat tampilan *scrolling text* dinamis menggunakan modul LCD 16x2 I2C dan mikrokontroler Arduino.

## 📌 Spesifikasi Sistem
1. Tampilan LCD terdiri dari 2 kalimat pada baris yang berbeda.
2. **Baris 0:** Menampilkan tulisan statis `QUOTE` yang diposisikan tepat di tengah layar.
3. **Baris 1:** Menampilkan kalimat *quote* dinamis yang berjalan (scrolling).
4. Tulisan pada Baris 1 muncul pertama kali tepat dari sisi paling kanan, yaitu pada `Cursor(15, 1)`.

## ⚙️ Komponen yang Digunakan (Simulasi Tinkercad)
* Arduino Uno R3
* LCD 16x2 dengan modul I2C
* Kabel Jumper

## 💡 Logika Pemrograman
Karena fungsi standar `scrollDisplayLeft()` akan menggeser keseluruhan layar (termasuk baris 0 yang seharusnya statis), kode ini menggunakan logika manipulasi `String.substring()`. 
Program menghitung posisi indeks teks secara terus-menerus dan hanya memperbarui karakter yang di-print pada baris ke-1 secara sekuensial, menciptakan ilusi teks yang berjalan ke kiri tanpa mengganggu tulisan `QUOTE` di baris atas.

## 📂 Struktur Direktori
- `Sketch.ino`: Berisi *source code* utama.
- `/Dokumentasi`: Berisi file video *screen-record* saat simulasi Tinkercad dijalankan.