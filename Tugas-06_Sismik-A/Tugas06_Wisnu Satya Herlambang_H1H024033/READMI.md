Nama    : Wisnu Satya Herlambang
NIM     : H1H024033
Mata Kuliah : Sistem Mikrokontroler
Kelas       : A

Link Tinkercad: https://www.tinkercad.com/things/2ktBzniGn9U-tugas-i2c/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=RQh7cPw_XF2q0LMNw1kmDJsmpgv78F3zecr5Qqbptf8

Penjelasan Source Code LCD I2C
Program ini menggunakan teknik manipulasi teks (substring) untuk menciptakan efek teks berjalan hanya pada satu baris, tanpa mengganggu teks statis di baris lainnya. Berikut adalah penjelasan per bagiannya:

1. Persiapan dan Deklarasi Variabel

- #include <LiquidCrystal_I2C.h>: Memasukkan library khusus untuk mengontrol LCD menggunakan jalur komunikasi I2C (hanya 4 kabel).

- LiquidCrystal_I2C lcd(0x20, 16, 2);: Mendeklarasikan objek LCD dengan alamat I2C 0x20 (atau 0x27), dengan ukuran layar 16 kolom dan 2 baris.

- Variabel Teks: Teks utama digabungkan dengan 16 spasi kosong di awal dan akhir (teksBerjalan = spasi + isiQuote + spasi). Hal ini bertujuan agar saat animasi dimulai, tulisan benar-benar masuk dari luar tepi kanan layar secara perlahan, dan menghilang perlahan di tepi kiri.

2. Fungsi setup() (Kondisi Awal)

- lcd.init() & lcd.backlight(): Menyalakan layar dan lampu latar (backlight) LCD.

- Baris Statis: Perintah lcd.setCursor(5, 0) meletakkan kursor di baris pertama (indeks 0), tepat pada kolom ke-5. Karena layar memiliki 16 kolom dan kata "QUOTE" terdiri dari 5 huruf, posisi kolom ke-5 akan membuat kata tersebut tercetak persis di tengah layar. Kata ini diam dan tidak akan pernah diperbarui lagi oleh program.

3. Fungsi loop() (Efek Scrolling)
Fungsi ini berjalan terus-menerus untuk memperbarui tampilan teks di baris kedua.

- lcd.setCursor(0, 1): Kursor dikembalikan ke pojok kiri bawah (baris indeks 1) sebelum mencetak teks baru.

- teksBerjalan.substring(posisiScroll, posisiScroll + 16): Ini adalah inti dari efek berjalannya. Fungsi ini mengambil "potongan" teks sebanyak 16 huruf dari kalimat panjang tadi.

- posisiScroll++: Setiap siklus, posisi awal pemotongan teks digeser ke kanan satu huruf. Hasilnya, saat dicetak berulang-ulang, teks terlihat bergerak dari kanan ke kiri.

Logika Reset (if) & delay(): Jika posisi pergeseran sudah mencapai akhir kalimat, variabel posisiScroll dikembalikan ke 0 agar animasi mengulang dari awal. Perintah delay(300) digunakan untuk mengatur kecepatan gulungan teks sebesar 300 milidetik per huruf.