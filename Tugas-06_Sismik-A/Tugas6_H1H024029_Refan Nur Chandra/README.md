Nama: Refan Nur Chandra
NIM : H1H024029
Mata kuliah: Sistem Mikrokontroler
Kelas: A

Penjelasan kode program sceth.ino:

Program ini menggunakan protokol I2C untuk menampilkan teks pada LCD 16x2. Terdapat dua bagian utama tampilan:

Statis: Menampilkan kata "QUOTE" di baris pertama (baris 0).

Dinamis (Running Text): Menggerakkan kalimat "Aku tahu, aku diam." di baris kedua (baris 1).

Fungsi Utama
Menggunakan library Wire.h dan Adafruit_LiquidCrystal.h
lcd.begin(16, 2): Inisialisasi dimensi LCD.

quote.substring(i, i + 16): Mengambil cuplikan string sepanjang 16 karakter untuk menciptakan efek teks berjalan.

while loop: Mengisi sisa kolom LCD dengan spasi kosong agar tampilan tetap bersih (tidak ada karakter tertinggal).

delay(100): Mengatur kecepatan scroll teks (100 ms per karakter).


## Dokumentasi Video
<video src="Dokumentasi/Tugas6-Dokumentasi.mp4" width="100%" controls></video>