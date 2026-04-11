# 📟 LCD I2C Quote Display - Arduino Uno  

Nama  : Revalina Fidiya Anugrah  
NIM   : H1D023011  
Mata Kuliah : Pemrograman Sistem Tertanam  

---
<img width="1706" height="863" alt="Tugas06_H1D023011_Revalina" src="https://github.com/user-attachments/assets/1a449d32-f979-469b-9c8b-f08da3e099cc" />

## Deskripsi Project  
Project ini merupakan implementasi tampilan **LCD I2C 16x2** menggunakan Arduino Uno untuk menampilkan dua baris teks.  

Baris pertama menampilkan teks **"QUOTE"** secara statis dan berada tepat di tengah layar, sedangkan baris kedua menampilkan **kalimat quote yang bergerak (scroll)** dari kanan ke kiri.  

Project ini bertujuan untuk memahami penggunaan komunikasi **I2C**, serta pengolahan tampilan dinamis pada LCD.

---

## Fitur Sistem  
- Menggunakan LCD 16x2 berbasis I2C  
- Baris [0]:
  - Menampilkan teks **"QUOTE"** (statis)  
  - Posisi tepat di tengah layar  
- Baris [1]:
  - Menampilkan teks quote secara **dinamis (scroll)**  
  - Teks muncul dari sisi kanan (kolom 15)  
  - Bergerak dari kanan ke kiri  
- Tampilan berjalan secara looping (berulang)  
- Kecepatan scroll dapat diatur menggunakan delay  

---

## Konsep yang Digunakan  
- Komunikasi I2C (`Wire`)  
- Library LCD (`Adafruit_LiquidCrystal`)  
- Manipulasi posisi cursor (`setCursor`)  
- Perulangan (`for loop`)  
- Logika tampilan dinamis (scrolling text)  
- Struktur dasar Arduino (`setup()` dan `loop()`)  

---

## Wiring Diagram  
Koneksi antara Arduino Uno dan LCD I2C:

- GND → GND  
- VCC → 5V  
- SDA → SDA  
- SCL → SCL 

Lihat pada folder:  
`arduino_protocol_comm\Tugas-06_PST-A\Tugas06_H1D023011_REVALINA`

---

## Hasil Simulasi  
Lihat pada folder:  
`arduino_protocol_comm\Tugas-06_PST-A\Tugas06_H1D023011_REVALINA\Dokumentasi`  

---

## Source Code  
Lihat pada folder:  
`arduino_protocol_comm\Tugas-06_PST-A\Tugas06_H1D023011_REVALINA\Source Code`

---

## 🔗 Link Tinkercad  
https://www.tinkercad.com/things/asRRewlvVni-tugas06h1d023011revalina

---


## Catatan  
Project ini telah memenuhi spesifikasi sistem:  
- Terdiri dari 2 baris tampilan  
- Baris [0] menampilkan "QUOTE" secara statis di tengah  
- Baris [1] menampilkan teks secara dinamis (scroll)  
- Teks dimulai dari sisi kanan layar (kolom 15)  
- Sistem berjalan secara terus-menerus (loop)  

Kecepatan pergerakan teks dapat disesuaikan dengan nilai delay untuk mendapatkan tampilan yang optimal.

---

## Alur Sistem  

1. Inisialisasi LCD  
2. Menampilkan teks "QUOTE" di tengah baris [0]  
3. Menghitung panjang teks quote  
4. Teks pada baris [1] mulai muncul dari sisi kanan  
5. Teks bergerak ke kiri secara bertahap (scroll)  
6. Setelah teks selesai tampil, sistem mengulang dari awal  

---
