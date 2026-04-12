# Scrolling Text dengan I2C

## Identitas

**Nama** : Muhammad Nabil Putra Monti<br>
**NIM** : H1D023063<br>
**Mata Kuliah** : Pemrograman Sistem Tertanam

## Deskripsi Proyek

Proyek ini bertujuan untuk membuat tampilan teks berjalan (*scrolling text*) pada layar LCD 16x2 menggunakan komunikasi I2C. Teks berjalan akan ditampilkan pada baris kedua layar LCD, sementara baris pertama akan menampilkan tulisan statis "QUOTE". Proyek ini menggunakan library **Adafruit LiquidCrystal** dengan pendekatan manipulasi *String* (Sub-string) untuk menciptakan pergerakan teks yang lebih efisien dan halus.

### Fitur Utama

  - Baris pertama menampilkan tulisan statis "QUOTE" yang posisinya dihitung secara otomatis agar selalu berada di tengah layar.
  - Baris kedua menampilkan teks berjalan "**Disiplin adalah kunci kesuksesan. - (Nabil)**" yang bergerak muncul dari sisi kanan ke kiri.
  - Menggunakan logika *Sliding Window* (penggalan teks) untuk memastikan tampilan di baris kedua selalu bersih tanpa perlu fungsi hapus layar manual.
  - Teks sangat fleksibel untuk diubah melalui variabel `message`.

## Alat dan Bahan

1.  **Arduino Uno R3**: Sebagai unit pemroses utama.
2.  **LCD 16x2 dengan modul I2C**: Untuk menampilkan informasi visual dengan hanya menggunakan 2 pin data (SDA & SCL).
3.  **Kabel Jumper**: Untuk menghubungkan jalur VCC, GND, dan I2C.

## Simulasi dengan Tinkercad

Simulasi proyek ini dapat dilakukan menggunakan platform Tinkercad dengan langkah-langkah berikut:

1.  **Buat Proyek Baru**:
      - Masuk ke akun Tinkercad dan buat proyek baru di bagian "Circuits".
2.  **Tambahkan Komponen**:
      - Masukkan **Arduino Uno R3**.
      - Masukkan **LCD 16x2 (I2C)**.
      - Hubungkan pin **SDA** LCD ke pin **A4** Arduino dan pin **SCL** ke pin **A5**.
      - Hubungkan **VCC** ke 5V dan **GND** ke GND Arduino.
3.  **Upload Kode**:
      - Pilih mode **Text** pada bagian Code, hapus kode bawaan, dan tempel kode yang telah disiapkan.
      - Klik tombol **"Start Simulation"** untuk menjalankan perangkat.
4.  **Amati Hasil**:
      - Baris pertama akan menampilkan "QUOTE" di tengah.
      - Baris kedua akan memunculkan teks kutipan Nabil dari sisi kanan layar.

## Penjelasan Kode

Kode ini dirancang agar lebih ringkas dan mudah dipahami dengan pembagian sebagai berikut:

1.  **Inisialisasi LCD**:

      - Menggunakan library `Adafruit_LiquidCrystal` dengan alamat I2C default (0).
      - Lampu latar (*backlight*) diaktifkan pada bagian `setup()`.

2.  **Logika Auto-Centering (Baris 0)**:

      - Program menghitung lebar sisa layar: `(16 - panjang_teks) / 2`.
      - Hal ini membuat posisi "QUOTE" tetap simetris di tengah secara otomatis (`setCursor(5, 0)`).

3.  **Logika Padding & Substring (Baris 1)**:

      - **Padding**: Kalimat ditambahkan 16 spasi kosong di awal agar teks terlihat mulai masuk dari kolom paling kanan.

      - **Sliding Window**: Menggunakan fungsi `substring(pos, pos + 16)`. Program mengambil "jendela" karakter sepanjang 16 kolom dari variabel kalimat secara berurutan.

        #### Ilustrasi Pergerakan Jendela:

        | pos | Hasil `substring(pos, 16)` | Tampilan di Layar (Baris 1) |
        | --- | ------------------------- | -------------------------- |
        | 0   | "                "        | [                ] (Kosong) |
        | 1   | "               D"        | [               D]         |
        | 10  | "      Disiplin a"        | [      Disiplin a]         |
        | 16  | "Disiplin adalah "        | [Disiplin adalah ]         |

      - Dengan teknik ini, kita tidak perlu menghapus baris 1 secara manual, karena spasi dalam jendela *substring* akan otomatis menimpa karakter sebelumnya.

## Video
