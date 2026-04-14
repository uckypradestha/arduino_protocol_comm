Program ini digunakan untuk menampilkan teks berjalan (scrolling text) pada LCD 16x2 menggunakan modul I2C.

Pada bagian setup(), LCD diinisialisasi lalu menampilkan tulisan "QUOTE" di baris pertama. Kemudian pada loop(), program secara berkala (setiap 120 ms) mengambil potongan 16 karakter dari teks panjang (fullPesan) dan menampilkannya di baris kedua, sehingga terlihat seperti teks berjalan.

Variabel pos berfungsi menggeser posisi teks sedikit demi sedikit. Ketika sudah mencapai akhir teks, posisi akan di-reset ke awal agar animasi berjalan terus menerus.
