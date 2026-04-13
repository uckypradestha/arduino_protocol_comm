Cara Kerja Kode 
Program ini dirancang untuk menampilkan teks statis di baris pertama dan animasi teks berjalan (scrolling) di baris kedua pada modul LCD 16x2 I2C. Agar animasi berjalan mulus dan tidak berkedip (flicker-free), program menggunakan manipulasi String alih-alih perintah lcd.clear().

Berikut adalah tahapan kerja logikanya:
1. Persiapan Teks (Padding): Teks asli disisipkan dengan 16 spasi kosong di awal dan 16 spasi di akhir. Ini memastikan teks akan muncul perlahan dari ujung luar kanan layar dan menghilang secara natural ke ujung luar kiri layar.
2. Teks Statis: Kata "QUOTE" diatur pada fungsi setup(). Kata ini diletakkan di koordinat tengah baris atas (5, 0) dan hanya dicetak satu kali sehingga akan terus diam tanpa terganggu.
3. Animasi Pemotongan Teks (Substring): Pada fungsi loop(), mikrokontroler menggunakan perintah substring(i, i + 16) untuk memotong teks panjang tadi menjadi blok berukuran pas 16 karakter.
4. Pergeseran (Shift): Setiap 350 milidetik, titik awal pemotongan (i) digeser 1 karakter ke kanan. Potongan 16 karakter yang baru ini kemudian langsung ditimpa (di-print) ke baris bawah layar (0, 1). Teknik ini menciptakan ilusi optik teks yang sedang berjalan.