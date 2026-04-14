# Scrolling Text LCD I2C

## 👤 Identitas

* **Nama**: Finda Wulan F
* **NIM**: H1H024055

---

## 📌 Deskripsi

Program ini dibuat menggunakan Arduino dan LCD 16x2 berbasis I2C untuk menampilkan teks pada layar.
Baris pertama LCD menampilkan tulisan **"QUOTE"** secara statis di tengah layar, sedangkan baris kedua menampilkan teks berjalan (scrolling) dari kanan ke kiri.

Teks berjalan berisi pesan semangat serta identitas pembuat.

---

## 🧰 Alat dan Bahan

Komponen yang digunakan dalam proyek ini adalah:

* Arduino Uno
* LCD 16x2 dengan modul I2C
* Kabel jumper
* Kabel USB Arduino
* Laptop / PC

---

## 🔌 Rangkaian

Rangkaian menggunakan komunikasi I2C sehingga hanya membutuhkan 4 kabel:

| Pin LCD I2C | Arduino Uno |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| SDA         | A4          |
| SCL         | A5          |

Penggunaan I2C membuat rangkaian lebih sederhana dan mengurangi jumlah kabel dibandingkan LCD tanpa I2C.

---

## ⚙️ Cara Kerja Sistem

1. Arduino menginisialisasi LCD menggunakan library `LiquidCrystal_I2C`.
2. Baris pertama LCD menampilkan teks **"QUOTE"** secara statis di tengah.
3. Baris kedua menampilkan teks berjalan menggunakan metode **substring**.
4. Program mengambil sebagian teks sepanjang 16 karakter (sesuai lebar LCD) menggunakan fungsi `substring`.
5. Posisi teks digeser secara bertahap menggunakan variabel `pos`.
6. Pergerakan teks diatur menggunakan fungsi `millis()` sehingga berjalan secara halus tanpa delay.
7. Ketika teks sudah habis, posisi akan di-reset sehingga teks akan berjalan ulang dari awal.

---

## 📚 Library yang Digunakan

* `Wire.h`
* `LiquidCrystal_I2C.h`

---

## 🖥️ Output Program

* **Baris pertama**:
  QUOTE (statis di tengah)

* **Baris kedua**:
  Teks berjalan:
  **"SEMANGAT YAA -- FINDA W.F -- 55"**

Teks akan bergerak dari kanan ke kiri secara terus-menerus.

---

## 🎯 Kesimpulan

Program ini berhasil menampilkan teks statis dan teks berjalan pada LCD 16x2 menggunakan modul I2C.
Metode substring yang digunakan membuat tampilan scrolling lebih rapi dan efisien, serta penggunaan `millis()` membuat pergerakan teks menjadi lebih halus.

---
