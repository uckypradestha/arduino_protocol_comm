# Tugas 06 - Protokol I2C (Scrolling Text)

## Identitas
- Nama: Mukhammad Alfaen Fadillah
- NIM: H1D023032
- Kelas: PST-A

## Deskripsi Program
Program menampilkan dua baris teks pada LCD 16x2 menggunakan modul I2C:
- Baris 0: tulisan `QUOTE` ditampilkan statis dan berada di tengah.
- Baris 1: kalimat quote berjalan (scrolling) dari sisi kanan ke kiri.

## Spesifikasi yang Dipenuhi
- Terdiri dari 2 kalimat.
- Kalimat 1 (baris 0) bertulisan QUOTE, sifat statis.
- Kalimat 2 (baris 1) berupa quote dinamis (scrolling).
- Tulisan QUOTE tepat di tengah tampilan LCD.
- Tulisan quote langsung muncul dari sisi kanan.

## Library
- Wire
- LiquidCrystal_I2C

## Koneksi Hardware (Contoh Arduino Uno)
- VCC LCD -> 5V
- GND LCD -> GND
- SDA LCD -> A4
- SCL LCD -> A5

## Cara Menjalankan
1. Buka file `Source Code/main.ino` di Arduino IDE.
2. Pastikan board dan port sesuai.
3. Upload program ke board.
4. Buka LCD dan amati hasil tampilan.
