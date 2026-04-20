1. Inisialisasi & Konfigurasi
Library: Menggunakan #include <Adafruit_LiquidCrystal.h> yang kompatibel dengan modul I2C di Tinkercad (khususnya tipe MCP23008).

Objek LCD: Adafruit_LiquidCrystal lcd_1(0); menginisialisasi LCD pada alamat default.

Variabel Kontrol:

SCROLL_DELAY (280): Mengatur kecepatan pergerakan huruf (semakin kecil semakin cepat).

PAUSE_END (1200): Memberikan jeda waktu saat teks sudah sampai di ujung sebelum berbalik arah.

2. Struktur Tampilan (Layout)
Baris 0 (Atas): Menampilkan kata "QUOTE" secara statis (diam) di posisi tengah (setCursor(5, 0)).

Baris 1 (Bawah): Menampilkan isi quote yang bergerak dengan metode Ping-Pong Scroll.

3. Logika Pergerakan (Ping-Pong Scroll)
Program tidak hanya menggeser teks satu arah, tetapi menggunakan logika offset untuk menciptakan efek masuk dan keluar:

renderFrame(): Fungsi inti yang bertugas menggambar "potongan" teks pada baris kedua berdasarkan nilai offset tertentu. Ia akan menghapus baris kedua terlebih dahulu sebelum mencetak karakter baru agar tidak ada teks yang menempel (ghosting).

Maju (Kanan ke Kiri): Teks mulai muncul dari kolom paling kanan (kolom 15), bergeser ke kiri hingga teks hilang di sisi kiri layar.

Mundur (Kiri ke Kanan): Setelah jeda PAUSE_END, teks akan bergerak mundur dari kiri kembali ke kanan hingga kembali ke posisi awal.

4. Alur Kerja loop()
Fungsi loop() menjalankan fungsi pingPongScroll() secara terus-menerus. Hal ini memastikan teks quote akan selalu bergerak bolak-balik selama perangkat Arduino menyala, memberikan efek visual yang dinamis namun tetap terbaca.
