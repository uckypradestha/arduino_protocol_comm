# Scrolling Text dengan I2C

## Identitas

Nama : Ferdi Waskito<br>
NIM : H1D024100<br>
Mata Kuliah : Pemrograman Sistem Tertanam

## Deskripsi Proyek

Proyek ini bertujuan untuk membuat tampilan teks berjalan (scrolling text) pada layar LCD 16x2 menggunakan komunikasi I2C. Teks berjalan akan ditampilkan pada baris kedua layar LCD, sementara baris pertama akan menampilkan tulisan statis "QUOTE". Proyek ini menggunakan library Adafruit LiquidCrystal untuk mempermudah pengendalian layar LCD.

### Fitur Utama

- Baris pertama menampilkan tulisan statis "QUOTE" yang berada di tengah layar.
- Baris kedua menampilkan teks berjalan yang bergerak dari kanan ke kiri.
- Teks berjalan dapat diatur sesuai kebutuhan dengan mengubah isi variabel `quoteText` di dalam kode.
- Menggunakan logika perhitungan posisi untuk memastikan hanya karakter yang terlihat pada layar yang ditampilkan.

## Alat dan Bahan

1. **Arduino Uno** atau board Arduino lainnya.
2. **LCD 16x2 dengan modul I2C**: Untuk menampilkan teks.
3. **Kabel Jumper**: Untuk menghubungkan komponen.

## Simulasi dengan Tinkercad

Simulasi proyek ini dapat dilakukan menggunakan platform Tinkercad dengan langkah-langkah berikut:

1. **Buat Proyek Baru**:
   - Masuk ke akun Tinkercad dan buat proyek baru di bagian "Circuits".
2. **Tambahkan Komponen**:
   - Tambahkan Arduino Uno ke workspace.
   - Tambahkan LCD 16x2 dengan modul I2C.
   - Hubungkan pin I2C (SDA dan SCL) dari LCD ke pin Arduino (A4 untuk SDA dan A5 untuk SCL pada Arduino Uno).
   - Sambungkan pin VCC dan GND dari LCD ke pin 5V dan GND Arduino.
3. **Upload Kode**:
   - Salin kode dari file `quote.ino` ke editor kode di Tinkercad.
   - Klik tombol "Start Simulation" untuk menjalankan simulasi.
4. **Amati Hasil**:
   - Baris pertama LCD akan menampilkan teks statis "QUOTE".
   - Baris kedua akan menampilkan teks berjalan sesuai dengan kode.

Dengan simulasi ini, Anda dapat memverifikasi bahwa kode dan rangkaian bekerja sesuai dengan yang diharapkan sebelum menerapkannya pada perangkat keras.

## Penjelasan Kode

Kode ini terdiri dari beberapa bagian utama:

1. **Inisialisasi LCD**:
   - Menggunakan library `Adafruit_LiquidCrystal` untuk mengontrol LCD melalui I2C.
   - LCD diinisialisasi dengan ukuran 16x2 dan backlight diaktifkan.

2. **Variabel Global**:
   - `quoteText`: Berisi teks yang akan ditampilkan sebagai teks berjalan.
   - `textLen`: Menyimpan panjang teks yang akan ditampilkan.
   - `LCD_COLS` dan `LCD_ROWS`: Konstanta untuk ukuran layar LCD.
   - `SCROLL_DELAY`: Konstanta untuk mengatur kecepatan scrolling.

3. **Fungsi `clearRow1`**:
   - Membersihkan baris kedua LCD dengan menampilkan 16 spasi.

4. **Fungsi `setup`**:
   - `lcd.begin(16, 2)` menginisialisasi LCD dengan lebar 16 kolom dan 2 baris.
   - `lcd.setBacklight(HIGH)` menyalakan lampu latar LCD.
   - Menampilkan teks statis "QUOTE" di baris pertama, tepat di tengah layar `lcd.setCursor(5, 0)`.
   - Menghitung panjang teks yang akan ditampilkan.

5. **Fungsi `loop`**:
   - Menangani logika scrolling teks pada baris kedua.
   - Menggeser teks dari kanan ke kiri dengan menghitung posisi awal. Pendekatannya adalah kalkulasi posisi manual per frame, bukan menggunakan scrollDisplayLeft().
   - Memberikan jeda di akhir scrolling sebelum memulai kembali dari awal.

     #### Cara kerja per iterasi offset:

     | offset | startCol | Tampilan Baris 1                            |
     | ------ | -------- | ------------------------------------------- |
     | 0      | 15       | [ Y] ← Karakter pertama muncul di kolom 15  |
     | 1      | 14       | [ Ya]                                       |
     | 15     | 0        | [Yang terbaik mas] ← 16 karakter penuh      |
     | 16     | -1       | [ang terbaik mas ] ← Mulai keluar dari kiri |
     | ...    | ...      | ...                                         |
     | 53     | -38      | [ .] ← Karakter terakhir keluar             |
     - startCol = 15 - offset → titik awal teks di layar
     - Karakter hanya dicetak jika col >= 0 && col < 16 (masih dalam layar)
     - Loop berjalan LCD_COLS + textLen kali hingga teks keluar sepenuhnya

Kode ini dirancang agar fleksibel, sehingga teks yang ditampilkan dapat diubah dengan mudah hanya dengan mengganti isi variabel `quoteText`.

## Video

https://github.com/user-attachments/assets/c354ef92-eb03-4ae4-b35d-019c1a5dada6
