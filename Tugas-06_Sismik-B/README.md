# 📟 Scrolling Text Dengan I2C

## 📌 Deskripsi
Program ini menggunakan **LCD 16x2 berbasis I2C** pada Arduino untuk menampilkan teks dalam dua baris.

- Baris pertama menampilkan teks statis
- Baris kedua menampilkan teks berjalan (scrolling)

---

## ⚙️ Spesifikasi Sistem

- Terdiri dari **2 Kalimat**

### 🔹 Baris [0]
- Bertuliskan: `QUOTE`
- Bersifat **statis**
- Ditampilkan **tepat di tengah LCD**

### 🔹 Baris [1]
- Berisi teks quote
- Bersifat **dinamis (scrolling)**
- Muncul dari **sisi kanan (cursor 15,1)**
- Bergerak dari kanan ke kiri

---

## 🧰 Komponen

- Arduino Uno
- LCD 16x2 I2C
- Kabel jumper

---

## 🔌 Koneksi

| LCD I2C | Arduino Uno |
|--------|------------|
| GND    | GND        |
| VCC    | 5V         |
| SDA    | A4         |
| SCL    | A5         |

---

## 💻 Cara Kerja

1. LCD diinisialisasi menggunakan I2C  
2. Tulisan **"QUOTE"** ditampilkan di tengah  
3. Teks panjang ditambahkan spasi di awal & akhir  
4. Program mengambil substring 16 karakter  
5. Teks bergeser ke kiri (scrolling)

---

## ▶️ Contoh Output
