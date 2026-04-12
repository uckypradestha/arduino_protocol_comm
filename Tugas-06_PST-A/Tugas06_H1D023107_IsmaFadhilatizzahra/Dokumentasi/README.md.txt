# Folder ini berisi Dokumentasi Wiring Diagram

## 1. Skema Rangkaian
Rangkaian ini dibangun menggunakan protokol I2C, yang memungkinkan pengendalian LCD hanya dengan sedikit kabel. Berikut adalah rincian koneksinya:

- Jalur Tegangan
Kabel Merah dihubungkan ke pin 5V Arduino untuk menyuplai daya ke LCD.

Kabel Hitam/Ungu dihubungkan ke pin GND Arduino sebagai jalur negatif.

- Jalur Komunikasi (I2C Bus)
SDA (Serial Data) menggunakan kabel Hijau yang dihubungkan ke pin A4. Jalur ini bertugas mengirimkan data karakter ke LCD.

SCL (Serial Clock) menggunakan kabel Kuning yang dihubungkan ke pin A5. Jalur ini berfungsi sebagai pengatur tempo pengiriman data agar sinkron.

## 2. Kesesuaian dengan Instruksi Tugas
Berdasarkan hasil pengujian pada simulasi Tinkercad, sistem telah memenuhi seluruh kriteria yang ditetapkan:

| Kriteria Tugas     | Hasil Implementasi | Penjelasan Teknis                                                                 |
|------------------|-------------------|----------------------------------------------------------------------------------|
| Metode Komunikasi | I2C Protocol      | Menggunakan pin khusus A4 (SDA) dan A5 (SCL) untuk menghemat penggunaan port I/O. |
| Kapasitas Teks    | 2 Baris Terpisah  | Berhasil membagi konten menjadi judul di baris atas dan quote di baris bawah.     |
| Posisi Judul      | Statis & Center   | Kata "QUOTE:" diposisikan di tengah kolom agar tampilan terlihat simetris.       |
| Animasi Teks      | Scrolling Dinamis | Kalimat kedua bergerak secara mulus dari kanan ke kiri tanpa memengaruhi teks di baris pertama. |
| Arah Pergerakan   | Dari Sisi Kanan   | Logika perulangan `for` dimulai dari indeks kolom 16 sehingga teks muncul dari luar layar kanan. |

