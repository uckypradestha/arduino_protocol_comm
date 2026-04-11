1. Import Library<br>
#include <Wire.h><br>
#include <Adafruit_LiquidCrystal.h><br>
Fungsi:<br>

Wire.h digunakan untuk komunikasi I2C antara Arduino dan LCD.<br>
Adafruit_LiquidCrystal.h berisi fungsi untuk mengontrol LCD.<br>

2. Inisialisasi LCD<br>
Adafruit_LiquidCrystal lcd(0);<br>
Membuat objek lcd untuk mengendalikan tampilan. Angka 0 menunjukkan alamat modul sesuai konfigurasi library.<br>

3. Deklarasi Variabel Teks<br>
String teks = "            tetap semangat yaa ";<br>
Variabel ini menyimpan teks yang akan ditampilkan.<br>

Spasi di awal membuat teks muncul dari sisi kanan.<br>
Spasi di akhir memberikan jeda sebelum animasi diulang.<br>

4. Fungsi setup()<br>
void setup() {<br>
  lcd.begin(16, 2);<br>
Menginisialisasi LCD dengan ukuran 16 kolom dan 2 baris.<br>
  lcd.setCursor(5, 0);<br>
  lcd.print("QUOTE");<br>
}<br>
Menampilkan teks "QUOTE" di tengah baris pertama.<br>
Perhitungan posisi tengah:<br>
(16 - 5) / 2 = 5<br>

5. Fungsi loop()
Fungsi ini berjalan berulang untuk menciptakan animasi running text.<br>
a. Perulangan Animasi<br>
for (int i = 0; i < teks.length() - 15; i++)<br>
Menggeser teks satu karakter setiap iterasi.<br>
Dikurangi 15 karena LCD hanya menampilkan 16 karakter.<br>
b. Menentukan Posisi Tampilan<br>
lcd.setCursor(0, 1);<br>

Menampilkan teks pada kolom pertama baris kedua.<br>

c. Menampilkan Running Text<br>
lcd.print(teks.substring(i, i + 16));<br>

Mengambil 16 karakter dari teks untuk ditampilkan pada LCD sehingga menghasilkan efek berjalan.<br>

d. Mengatur Kecepatan Animasi<br>
delay(50);<br>

Menentukan kecepatan pergeseran teks. Nilai lebih kecil menghasilkan animasi lebih halus.<br>