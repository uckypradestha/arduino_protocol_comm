# Praktikum Sistem Mikrokontroler - LCD I2C Quote Display
## Identitas
Nursyafika_H1H024023

## Deskripsi
Proyek ini merupakan implementasi dasar sistem embedded menggunakan Arduino dengan memanfaatkan LCD 16x2 berbasis I2C untuk menampilkan teks statis dan teks berjalan (scrolling text).
Program menampilkan tulisan "QUOTE" pada baris pertama LCD, kemudian menampilkan teks "Be Kind Always" yang bergerak dari kanan ke kiri pada baris kedua secara berulang.
Seluruh program telah diuji menggunakan simulasi Tinkercad, dan dokumentasi berupa video simulasi tersedia pada folder /dokumentasi.

LCD Scrolling Text
Link Tinkercad :
https://www.tinkercad.com/things/bblFqP7XbHE-scrolling

##Penjelasan Program
Program ini menggunakan LCD 16x2 berbasis I2C untuk menampilkan teks pada layar. Pada baris pertama LCD, program menampilkan tulisan "QUOTE" sebagai judul. Pada baris kedua, program menampilkan teks "Be Kind Always" yang bergerak dari kanan ke kiri secara berulang.
Pada fungsi setup(), LCD diinisialisasi terlebih dahulu dengan ukuran 16 kolom dan 2 baris. Setelah itu, lampu latar LCD dinyalakan menggunakan lcd.setBacklight(1) agar tampilan terlihat jelas. Selanjutnya, kursor diarahkan ke kolom ke-5 pada baris pertama, lalu tulisan "QUOTE" ditampilkan.
Pada fungsi loop(), program menghitung panjang teks menggunakan strlen(). Setelah itu, program melakukan perulangan untuk menggeser teks sedikit demi sedikit dari sisi kanan ke kiri. Sebelum menampilkan posisi teks yang baru, baris kedua dibersihkan terlebih dahulu dengan menampilkan spasi pada seluruh kolom LCD. Kemudian, setiap karakter dari teks dicetak sesuai posisi kolom yang telah dihitung. Proses ini diberi jeda dengan delay(DELAY_TIME) agar efek animasi scrolling terlihat jelas.
Setelah seluruh teks selesai bergeser, program memberikan jeda singkat selama 800 milidetik sebelum mengulangi animasi dari awal. Dengan demikian, teks akan terus bergerak secara berulang pada LCD.

##rec 
https://github.com/user-attachments/assets/df8e2d2f-b782-4f59-85ec-93dec755682c
<img width="1883" height="735" alt="Screenshot 2026-04-12 195119" src="https://github.com/user-attachments/assets/2aa33c6a-a4af-4ac9-8937-00f1325fe040" />






Kesimpulan
Proyek ini menunjukkan penerapan dasar Arduino dalam mengontrol LCD 16x2 berbasis I2C sebagai perangkat output. Program berhasil menampilkan teks statis pada baris pertama dan teks berjalan pada baris kedua dengan memanfaatkan perulangan, pengaturan posisi kursor, serta delay.
Penggunaan Tinkercad sebagai media simulasi memungkinkan pengujian program secara virtual sebelum diterapkan pada perangkat keras nyata.
