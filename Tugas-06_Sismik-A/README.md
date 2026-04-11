# I2C LCD Running Text - Arduino

Halo! Proyek ini adalah eksperimen saya untuk memenuhi tugas Pak Ucky dalam Mata Kuliah Sistem Mikrokontroller, dalam mengontrol LCD 16x2 menggunakan komunikasi I2C. 
Di sini saya membuat tampilan teks berjalan (running text) pada baris kedua, sementara baris pertamanya tetap statis untuk menampilkan judul atau label.

##  Logic & Penjelasan Kode

Dalam mengembangkan kode ini, saya membaginya menjadi tiga bagian utama:

### 1. Library yang Saya Gunakan
Saya menggunakan dua library utama agar perangkat keras bisa saling berkomunikasi:
* **`Wire.h`**: Saya gunakan untuk mengaktifkan protokol komunikasi I2C pada Arduino.
* **`LiquidCrystal_I2C.h`**: Library ini memudahkan saya untuk mengontrol karakter pada LCD hanya dengan dua kabel data (SDA & SCL).

### 2. Inisialisasi & Persiapan
Pada bagian awal kode, saya melakukan konfigurasi dasar:
* **Alamat I2C**: Saya mengatur LCD pada alamat `0x27` dengan dimensi `16x2`.
* **Manipulasi String**: Saya menambahkan spasi kosong di awal dan akhir pesan agar teks masuk dan keluar layar dengan efek yang lebih halus (smooth).
* **Non-blocking Delay**: Alih-alih menggunakan `delay()`, saya memilih menggunakan `millis()` agar program tidak berhenti total saat menunggu jeda pergeseran teks.

### 3. Cara Kerja Looping
Logika utama yang saya terapkan di fungsi `loop()` adalah sebagai berikut:
* **Timer**: Program akan mengecek selisih waktu. Jika sudah mencapai interval (misalnya 120ms), barulah teks akan bergeser.
* **Window Sliding (Substring)**: Saya menggunakan fungsi `.substring(pos, pos + 16)` untuk mengambil 16 karakter dari pesan panjang secara bergantian. Ibarat jendela yang bergeser satu persatu ke arah kanan.
* **Reset Posisi**: Ketika posisi geser sudah mencapai ujung pesan, saya mengembalikan variabel `pos` ke `0` agar teks muncul kembali dari awal secara terus-menerus.



## Cara Menjalankan
1. Pastikan library **LiquidCrystal I2C** sudah terinstal di Arduino IDE.
2. Hubungkan pin VCC ke 5V, GND ke GND, SDA ke A4, dan SCL ke A5 (untuk Arduino Uno).
3. *Upload* kode ke papan Arduino.
4. Sesuaikan variabel `kecepatan` jika ingin teks berjalan lebih cepat atau lambat.

---
**Ardhis Alivio** *Embedded Systems Enthusiast*
