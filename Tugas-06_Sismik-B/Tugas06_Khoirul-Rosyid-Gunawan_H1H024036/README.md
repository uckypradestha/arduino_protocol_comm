# Tugas 6 - Sistem Mikrokontroler: Tampilan LCD I2C

Repositori ini berisi source code Arduino untuk mengendalikan LCD 16x2 berbasis modul I2C. Program ini berfungsi untuk menampilkan teks statis di tengah baris pertama dan teks berjalan (scrolling) dari kanan ke kiri pada baris kedua secara bersamaan.

## Informasi Mahasiswa
- Nama: Khoirul Rosyid Gunawan
- NIM: H1H024036
- Kelas: B
- Mata Kuliah: Sistem Mikrokontroler

---

### 1. Penggunaan Library
Program ini memerlukan dua library utama agar Arduino dapat berkomunikasi dan mengendalikan layar LCD:
- Wire.h: Ini adalah library bawaan dari Arduino IDE yang berfungsi untuk menangani komunikasi data dua arah menggunakan protokol I2C (Inter-Integrated Circuit).
- LiquidCrystal_I2C.h: Library pihak ketiga yang menerjemahkan perintah teks menjadi instruksi visual untuk perangkat LCD yang dilengkapi modul PCF8574 (modul I2C). Library ini menyederhanakan proses seperti menyalakan layar, mengatur kursor, dan mencetak karakter.

### 2. Inisialisasi (Setup)
Tahap inisialisasi berada di dalam blok fungsi `setup()` dan hanya dieksekusi satu kali saat mikrokontroler pertama kali dinyalakan. Proses yang terjadi meliputi:
- Aktivasi Layar: Perintah `lcd.init()` digunakan untuk memulai komunikasi dengan LCD, diikuti dengan `lcd.backlight()` untuk menyalakan lampu latar layar agar tulisan dapat terlihat.
- Penempatan Teks Statis: Teks judul ("Hidup") dicetak pada baris pertama (baris 0). Melalui fungsi `printCentered()`, program menghitung sisa dari total 16 kolom layar dikurangi panjang karakter teks, lalu membaginya dua untuk menentukan titik awal kursor agar presisi di tengah layar.

### 3. Looping (Perulangan)
Bagian ini berada di dalam blok `loop()` dan dieksekusi secara terus-menerus. Di sinilah efek teks berjalan pada baris kedua (baris 1) dibuat melalui fungsi `scrollText()`:
- Modifikasi String (Padding): Teks kutipan ("Dihina tidak tumbang, dipuji makasih mas") tidak bisa langsung digeser. Program menambahkan 16 karakter spasi kosong di awal kalimat agar huruf pertama muncul tepat di ujung paling kanan layar. Spasi juga ditambahkan di akhir kalimat agar teks bisa bergeser hingga benar-benar hilang dari layar.
- Sliding Window: Program menggunakan perulangan `for` dan fungsi `substring()` untuk mengambil potongan 16 karakter dari kalimat yang sudah dimodifikasi tadi.
- Pencetakan Frame