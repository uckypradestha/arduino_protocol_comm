# Penjelasan kode program
## 1. Inisialisasi dan Pembuatan Variabel
```c++
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
```
- ```#include <Adafruit_LiquidCrystal.h>```: Memanggil library khusus buatan Adafruit untuk mengontrol layar LCD.
- ```Adafruit_LiquidCrystal lcd(0);```: Membuat objek bernama ```lcd```. Angka ```0``` di dalam kurung adalah trik khusus di Tinkercad untuk secara otomatis mendeteksi modul I2C tanpa perlu menuliskan alamat heksadesimalnya.

```c++
String teksDiam = "QUOTE:"; 
String teksJalan = "                POKOKNYA ADA DEH                ";
```
- teksDiam: Variabel string untuk menyimpan teks statis yang akan ditampilkan di baris atas.
- teksJalan: Variabel string untuk teks yang akan di-scroll. Perhatikan bahwa temanmu memberikan 16 spasi kosong di awal dan di akhir kalimat. Spasi awal berfungsi agar teks muncul perlahan dari ujung kanan, dan spasi akhir berfungsi agar teks menghilang perlahan ke ujung kiri.
## 2. Pengaturan Awal (```void setup```)
Fungsi ini berjalan satu kali saat Arduino pertama kali dinyalakan.
```c++
lcd.begin(16, 2);        
  lcd.clear();       
  lcd.setBacklight(HIGH);
```
- ```lcd.begin(16, 2);```: Memberitahu Arduino bahwa LCD yang digunakan memiliki ukuran 16 kolom dan 2 baris.
- ```lcd.clear();```: Membersihkan layar dari sisa-sisa karakter yang mungkin masih menempel.
- ```lcd.setBacklight(HIGH);```: Menyalakan lampu latar (backlight) LCD agar tulisan terlihat jelas.
```c++
int posisiTengah = (16 - teksDiam.length()) / 2;
  lcd.setCursor(posisiTengah, 0); 
  lcd.print(teksDiam);
```
- Bagian ini sangat cerdas. Alih-alih menebak kursor keberapa, temanmu membuat rumus dinamis untuk mencari titik tengah layar.
- Logikanya: Lebar layar (16) dikurangi panjang karakter ```teksDiam``` (kata "QUOTE:" = 6 huruf), lalu dibagi 2. Hasilnya adalah 5.
- ```lcd.setCursor(5, 0);```: Meletakkan kursor di kolom ke-5 (indeks 5), baris ke-0 (baris pertama), lalu mencetak kata "QUOTE:". Posisinya akan tepat berada di tengah layar.
## 3. Logika Perulangan / Scrolling (```void loop```)
Fungsi ini berjalan terus-menerus dan menangani animasi pergerakan teks di baris kedua.
```c++
for (int i = 0; i <= teksJalan.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(teksJalan.substring(i, i + 16));
    delay(100); 
  }
```
- ```for (...)```: Ini adalah perulangan yang akan bergeser satu persatu. Batas akhirnya dikurangi 16 (```- 16```) agar program tidak mencoba mengambil huruf di luar batas teks yang ada (yang bisa membuat program error).

- ```lcd.setCursor(0, 1);```: Selalu meletakkan kursor di awal baris (kolom 0) pada baris bawah (baris 1).

- ```teksJalan.substring(i, i + 16)```: Ini adalah teknik Sliding Window. Fungsi ```substring``` memotong teks sepanjang 16 karakter.
Pada putaran pertama (```i=0```), layar menampilkan karakter ke-0 sampai 16.
Pada putaran kedua (```i=1```), layar menampilkan karakter ke-1 sampai 17 (seolah-olah bergeser ke kiri).
Begitu seterusnya sampai teks habis.

- ```delay(100);```: Memberikan jeda waktu 100 milidetik sebelum perulangan berlanjut. Ini menentukan kecepatan teks bergeser.
