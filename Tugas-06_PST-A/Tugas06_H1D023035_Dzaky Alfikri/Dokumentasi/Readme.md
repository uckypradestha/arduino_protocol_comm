# Dokumentasi - Scrolling Text dengan I2C

## Deskripsi
Folder ini berisi dokumentasi lengkap untuk proyek "Scrolling Text Dengan I2C" yang menggunakan Arduino UNO dan LCD 16x2.

## Isi Dokumentasi
https://www.tinkercad.com/things/aQM1y0dxbeY-h1d023035scrolling-text-i2c?sharecode=B5Zkx4NvGcvhR0Yrknqa0Bj4JCqvZ7AuBj2OSzNKkg0

### Skema Rangkaian
Dokumentasi ini mencakup skema wiring (diagram rangkaian) yang menunjukkan:
- **Komponen Utama:**
  - Arduino UNO (Microcontroller)
  - LCD 16x2 (Display)
  - Modul I2C (I2C Serial Interface)
  - Power Supply

### Koneksi I2C
- **SDA (Serial Data)** - Pin A4 Arduino UNO
- **SCL (Serial Clock)** - Pin A5 Arduino UNO
- **VCC** - 5V Power Supply
- **GND** - Ground

## Fungsi Proyek
Proyek ini menampilkan teks scrolling (teks berjalan) pada layar LCD 16x2 menggunakan protokol komunikasi I2C sebagai pengganti koneksi langsung.

## Catatan
- Komunikasi menggunakan protokol **I2C (Inter-Integrated Circuit)**
- LCD dikontrol melalui modul I2C hingga mengurangi jumlah pin yang digunakan
- Teks yang ditampilkan: "Man Jadda Wajada" (Siapa yang bersungguh-sungguh akan berhasil)
