# Scrolling Text LCD I2C - Arduino

**oleh: *Andyka Zefanya Bramantyo - H1H024039***

Proyek ini menampilkan teks statis pada baris pertama dan teks berjalan (dinamis) pada baris kedua menggunakan modul LCD 16x2 dengan interface I2C.

## Spesifikasi Sistem
- Baris 0 (Atas): Menampilkan kata "QUOTE" secara statis tepat di tengah.
- Baris 1 (Bawah): Menampilkan quotes/kutipan dinamis yang muncul pertama kali dari sisi kanan dan bergerak ke kiri.

## Diagram Koneksi (Tinkercad)

1. GND LCD -> GND ARDUINO
2. VCC LCD -> 5V ARDUINO
3. SDA LCD -> A4 ARDUINO
4. SCL LCD -> A5 ARDUINO

## Alur Logika Kode

Penjelasan alur kerja program:

1.  Inisialisasi Hardware dan Library
    - Program memanggil library Wire.h untuk komunikasi I2C dan LiquidCrystal_I2C.h untuk mengontrol layar. Alamat I2C (0x27) dan dimensi layar (16x2) ditetapkan agar Arduino dapat mengirim data ke modul yang tepat.

2. Konfigurasi Teks Statis (Baris 0)
    - Pada fungsi setup(), kursor diarahkan ke baris pertama (indeks 0). Kata "QUOTE" dicetak di kolom 5 agar posisinya berada tepat di tengah layar (mengimbangi 5 karakter kata dengan 11 ruang kosong yang tersisa).

3. Penentuan Titik Awal Baris Dinamis (Baris 1)
    - Di dalam fungsi loop(), sebuah variabel perulangan (i) diatur mulai dari angka 15. Ini merepresentasikan kolom paling kanan pada LCD 16x2 sebagai titik awal munculnya teks kutipan.

4. Pembersihan Baris Berkala (Refresh)
    - Setiap kali teks akan bergeser, program mencetak 16 karakter spasi (" ") khusus di baris kedua. Hal ini berfungsi untuk menghapus karakter dari posisi sebelumnya agar tidak terjadi tumpang tindih atau teks yang membekas (ghosting).

5. Logika Pergerakan Kiri (Decrement)
    - Program menggunakan perintah lcd.setCursor(i, 1). Karena nilai i terus berkurang (15, 14, 13, dst.), teks yang dicetak akan terlihat seolah-olah bergerak satu langkah ke kiri pada setiap putaran loop.

6. Penanganan Teks Keluar Layar (Substring)
    - Saat nilai i menjadi negatif (kurang dari 0), teks tidak bisa lagi dicetak dari koordinat tersebut. Program kemudian menggunakan fungsi substring(-i) untuk memotong bagian awal kalimat dan mencetak sisanya mulai dari kolom 0, sehingga transisi teks yang "menghilang" ke kiri terlihat halus.

7. Pengaturan Kecepatan (Delay)
    - Fungsi delay(200) memberikan jeda waktu selama 200 milidetik di setiap pergeseran. Jeda ini krusial agar mata manusia dapat membaca teks dengan nyaman; tanpa jeda ini, teks akan bergerak terlalu cepat dan tidak terbaca.

8. Reset Perulangan
    - Setelah seluruh kalimat (termasuk panjang karakternya) melewati batas kiri layar, perulangan for selesai. Program akan otomatis mengulang kembali dari i = 15, memulai kembali alur munculnya teks dari sisi kanan secara terus-menerus.


## Cara Penggunaan
1. Buka Tinkercad
2. Susun komponen sesuai tabel koneksi di atas.
3. Masukkan kode C++ yang tersedia ke dalam editor kode.
4. Pastikan library **LiquidCrystal I2C** sudah ditambahkan.
5. Jalankan simulasi.
