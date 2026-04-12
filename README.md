# 📡 Tugas 06 – Implementasi Komunikasi Serial dan I2C pada LCD

**Nama:** Nayla Zazki Kirani
**NIM:** H1H024007

---

## 📌 Latar Belakang

Dalam sistem embedded, komunikasi data antar perangkat merupakan aspek penting untuk memastikan sistem dapat bekerja secara terintegrasi. Dua metode yang umum digunakan adalah komunikasi serial dan komunikasi I2C. Komunikasi serial digunakan untuk pertukaran data antara mikrokontroler dan komputer, sedangkan I2C digunakan untuk menghubungkan perangkat seperti LCD dengan jumlah pin yang lebih efisien.

---

## 🎯 Tujuan

* Memahami konsep komunikasi serial
* Mengimplementasikan komunikasi I2C pada LCD
* Melakukan scanning alamat I2C
* Menampilkan teks pada LCD
* Mengembangkan efek teks berjalan (*scrolling text*)

---

## 🧰 Alat dan Bahan

* Arduino Uno
* LCD 16x2 dengan modul I2C
* Kabel jumper
* Breadboard
* Laptop dengan Arduino IDE

---

## ⚙️ Metodologi

Tahapan yang dilakukan dalam praktikum ini meliputi:

1. **Scanning I2C Address**
   Mengidentifikasi alamat perangkat LCD pada bus I2C
2. **Komunikasi Serial**
   Mengirim dan menerima data melalui serial monitor
3. **Menampilkan Teks (Print LCD)**
   Menampilkan data ke LCD menggunakan library I2C
4. **Scrolling Text**
   Membuat teks bergerak untuk meningkatkan tampilan visual

---

## 🔄 Alur Sistem

```id="flow567"
Serial Monitor → Mikrokontroler → I2C Communication → LCD → Output (Scrolling Text)
```

---

## 💻 Implementasi Program

### 1️⃣ I2C Scanning

Digunakan untuk mendeteksi alamat LCD pada bus I2C.
Hasil scanning biasanya berupa alamat seperti `0x27` atau `0x3F`.

### 2️⃣ Komunikasi Serial

* Menggunakan `Serial.begin()` untuk inisialisasi
* Data ditampilkan pada Serial Monitor
* Digunakan untuk debugging dan monitoring sistem

### 3️⃣ Print ke LCD (I2C)

* Menggunakan library `LiquidCrystal_I2C`
* Fungsi utama:

  * `lcd.init()` → inisialisasi
  * `lcd.setCursor()` → posisi teks
  * `lcd.print()` → menampilkan teks

### 4️⃣ Scrolling Text

* Menggunakan perulangan (*loop*)
* Teks digeser ke kiri secara bertahap
* Delay digunakan untuk mengatur kecepatan

---

## 📂 Struktur Folder

```id="struct99"
Serial-Komunikasi/
│
├── Tugas-06_Sismik-A/
│   └── Tugas06_H1H024007_Nayla Zazki Kirani/
│       ├── SourceCode/
│       │   ├── i2c_scanner.ino
│       │   ├── lcd_print.ino
│       │   ├── scrolling.ino
│       │   └── serial.ino
│       │
│       ├── Dokumentasi/
│       │   └── (gambar hasil percobaan)
│
├── README.md
└── .gitignore
```

---

## 📷 Dokumentasi

Dokumentasi berupa hasil percobaan tersedia pada folder `Dokumentasi`.

---

## 🎥 Video Demo

Berikut hasil implementasi yang mencakup:

* Komunikasi Serial
* I2C Scanning
* Print LCD
* Scrolling Text

👉 https://drive.google.com/drive/folders/1G816GOHY0k5MPHwOE0PhTqrnsygOPbm5?usp=drive_link

---

## 📊 Hasil dan Pembahasan

Berdasarkan hasil pengujian:

* Sistem berhasil mendeteksi alamat I2C dengan benar
* Komunikasi serial berjalan stabil
* LCD mampu menampilkan teks sesuai input
* Efek scrolling berjalan dengan baik

Analisis:

* Keberhasilan scanning menentukan koneksi I2C
* Komunikasi serial membantu proses debugging
* Delay mempengaruhi kenyamanan pembacaan teks
* Integrasi serial dan I2C meningkatkan fleksibilitas sistem

---

## 🧠 Kesimpulan

Sistem berhasil mengintegrasikan komunikasi serial dan I2C dalam satu rangkaian. Penggunaan I2C terbukti efisien dalam mengurangi penggunaan pin, sementara komunikasi serial mempermudah proses monitoring dan debugging. Penambahan fitur scrolling memberikan nilai tambah pada aspek tampilan sistem.

