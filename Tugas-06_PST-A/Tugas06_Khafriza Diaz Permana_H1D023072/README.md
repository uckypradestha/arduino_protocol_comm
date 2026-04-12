# Scrolling Text LCD 16x2 dengan I2C (Adafruit Library)

## 👤 Identitas

- **Nama** : Khafriza Diaz Permana
- **NIM** : H1D023072
- **Prodi** : Informatika
- **Mata Kuliah** : Pemrograman Sistem Tertanam

---

## Deskripsi Proyek

Proyek ini mengimplementasikan sistem tampilan teks pada LCD 16x2 menggunakan protokol komunikasi **I2C**. Sistem ini dirancang untuk menampilkan dua jenis informasi secara bersamaan: sebuah label statis dan sebuah kalimat berjalan (_scrolling text_).

### Spesifikasi Sistem:

1.  **Baris 0 (Atas):** Menampilkan kata **"QUOTE"**. Sifatnya statis dan diposisikan tepat di tengah (kolom 5).
2.  **Baris 1 (Bawah):** Menampilkan kalimat kutipan secara dinamis. Teks muncul pertama kali dari sisi paling kanan (Kolom 15) dan bergerak ke arah kiri hingga keluar sepenuhnya dari layar.

---

## Alat dan Bahan

- **Arduino Uno R3** (sebagai mikrokontroler utama).
- **LCD 16x2 dengan I2C Backpack** (sebagai output display).
- **Kabel Jumper** (untuk koneksi pin).
- **Library**: `Adafruit_LiquidCrystal`.

---

## Skema Koneksi (Wiring)

Koneksi I2C pada Arduino Uno dilakukan melalui pin analog **A4** dan **A5** atau pin khusus SDA/SCL.

| Pin LCD I2C | Pin Arduino | Fungsi                     |
| :---------- | :---------- | :------------------------- |
| **GND**     | GND         | Ground                     |
| **VCC**     | 5V          | Catu Daya 5V               |
| **SDA**     | SDA         | Jalur Data (Serial Data)   |
| **SCL**     | SCL         | Jalur Detak (Serial Clock) |

---

## Penjelasan Kode

Dokumentasi teknis ini menjelaskan bagaimana program menangani tampilan statis dan dinamis pada LCD 16x2 menggunakan library **Adafruit LiquidCrystal**.

---

## 1. Inisialisasi Alamat I2C

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Pada library Adafruit yang disimulasikan di Tinkercad, parameter `0` merujuk pada alamat I2C default. Protokol I2C memungkinkan komunikasi antar perangkat hanya dengan dua kabel data (SDA dan SCL).

## 2. Baris Statis: Teknik Centering

Untuk memastikan tulisan "QUOTE" berada tepat di tengah baris pertama (baris 0), digunakan perhitungan berbasis lebar kolom:

- **Lebar LCD:** 16 Kolom
- **Lebar Kata "QUOTE":** 5 Karakter
- **Rumus:** (16 - 5) / 2 = 5.5
- **Implementasi:** Kita mengambil nilai `5`. Jadi, kursor diletakkan pada kolom ke-5.

```cpp
lcd.setCursor(5, 0);
lcd.print("QUOTE");
```

## 3. Baris Dinamis: Teknik Sliding Window

Berbeda dengan fungsi geser bawaan LCD yang menggeser seluruh layar, kita menggunakan manipulasi string agar baris atas tetap diam.

### A. Penyiapan Buffer (Padding)

```cpp
String fullText = "               " + quote + "                ";
```

- **15 Spasi Depan:** Berperan sebagai jalan masuk agar teks muncul satu per satu dari kolom paling kanan (Kolom 15).
- **15 Spasi Belakang:** Berperan sebagai jalan keluar agar teks hilang sepenuhnya ke kiri sebelum mengulang loop.

### B. Fungsi Substring

Program mengambil "potongan" string sepanjang 16 karakter yang bergeser seiring waktu.

```cpp
lcd.print(fullText.substring(i, i + 16));
```

Variabel `i` yang bertambah dalam perulangan `for` berfungsi menggeser titik awal pengambilan string, menciptakan efek visual teks yang berjalan ke kiri.

## 4. Tabel Parameter Kontrol

| Parameter             | Nilai   | Fungsi                                                                                              |
| :-------------------- | :------ | :-------------------------------------------------------------------------------------------------- |
| `fullText.length()`   | Dinamis | Menentukan batas akhir perulangan agar tidak terjadi error pengambilan data di luar panjang string. |
| `lcd.setCursor(0, 1)` | Baris 2 | Memastikan teks berjalan hanya muncul di baris bawah.                                               |

## 5. Stabilitas Tampilan

Di dalam fungsi `loop()`, perintah cetak pada baris 0 tetap dipanggil ulang untuk menjaga agar teks statis tidak berkedip (_flickering_) atau tertutup data sisa saat LCD melakukan _refresh rate_.
