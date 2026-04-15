# Tugas Sistem Mikrokontroler 6
## Penjelasan Source Code Tugas
#include <Wire.h>: Memanggil library Wire yang diperlukan untuk mengatur komunikasi I2C (Inter-Integrated Circuit) pada pin Arduino.
#include <LiquidCrystal_I2C.h>: Memanggil library khusus untuk mengontrol modul layar LCD yang menggunakan modul I2C.
LiquidCrystal_I2C lcd(0x27, 16, 2);: Membuat objek bernama lcd. Angka 0x27 adalah alamat I2C default untuk modul LCD tersebut, sedangkan 16, 2 menunjukkan ukuran layar (16 kolom dan 2 baris).
String teksAtas;: Membuat variabel berjenis String untuk ditampilkan pada baris atas.
String teksBawah;: Membuat variabel berjenis String untuk ditampilkan pada baris bawah.
int posisi = 0;: Membuat variabel int dengan nilai 0. Variabel ini digunakan sebagai pointer untuk menghitung posisi huruf mana yang sedang ditampilkan saat teks berjalan.
void setup(): Fungsi ini berjalan selama satu kali saat Arduino pertama kali dinyalakan atau setelah tombol Reset ditekan.
lcd.init();: Menghidupkan dan menginisialisasi layar LCD.
lcd.backlight();: Menyalakan backlight pada layar LCD.
lcd.setCursor(4, 0);: Menempatkan titik awal penulisan (kursor) di layar pada kolom ke-5 untuk menempatkan teks ditengah layar dan pada baris ke-1 atau atas.
lcd.print(teksAtas);: Mencetak isi variabel teksAtas ke layar mulai dari posisi kursor yang diatur sebelumnya.
void loop(): Fungsi yang akan mengeksekusi kode secara looping atau berulang tanpa henti.
lcd.setCursor(0, 1);: Mengembalikan kursor layar ke posisi awal di kolom pertama (0) pada baris ke-2.
lcd.print(teksBawah.substring(posisi, posisi + 16));: Bagian utama pembuat efek teks berjalan. Fungsi substring() digunakan untuk mengambil potongan huruf dari teks yang panjang.
posisi++;: Menambah nilai posisi sebanyak 1 poin yang membuat titik awal potongan teks bergeser 1 huruf ke kanan pada putaran berikutnya, sehingga teks terlihat "berjalan" ke kiri.
if (posisi > teksBawah.length() - 16): Memeriksa (logika if) apakah nilai posisi sudah melewati batas akhir kalimat. Batas akhir dihitung dari total panjang huruf (length()) dikurangi lebar layar (16).
posisi = 0;: Jika teks sudah mencapai titik ujung terakhirnya, nilai posisi dikembalikan lagi ke 0 agar teks berjalan mengulang kembali dari awal (looping).
delay(200);: Memberi jeda waktu untuk mencetak tulisan teksBawah selama 200 milidetik atau 0,2 detik sebelum Arduino mengulang instruksi di fungsi loop().
