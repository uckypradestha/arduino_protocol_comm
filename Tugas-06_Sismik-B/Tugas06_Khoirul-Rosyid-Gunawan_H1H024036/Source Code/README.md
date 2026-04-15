# Tugas 6 - Sistem Mikrokontroler: Tampilan LCD I2C

**Nama** : Khoirul Rosyid Gunawan

**NIM** : H1H024036

**Kelas** : B 

**Mata Kuliah** : Sistem Mikrokontroler 


---

## Penjelasan Source Code

Berikut adalah penjelasan dari cara kerja program berdasarkan potongan kodenya:

### 1. Persiapan Library dan Variabel
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

String isiQuote = "Dihina tidak tumbang, dipuji makasih mas"; 

```
Program memanggil Wire.h dan LiquidCrystal_I2C.h agar Arduino dapat mengontrol LCD melalui modul I2C.

Objek lcd diinisialisasi dengan alamat I2C 0x27 untuk ukuran layar 16 kolom dan 2 baris.

Teks yang akan dijadikan animasi berjalan disimpan ke dalam variabel bertipe data String bernama isiQuote.

### 2. Inisialisasi Awal (Setup)
``` cpp
C++
void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(5, 0);
  lcd.print("Hidup");
}

```
Blok kode ini hanya berjalan satu kali saat Arduino pertama kali dinyalakan.

lcd.init() dan lcd.backlight() bertugas menyalakan modul layar LCD beserta lampu latarnya.

Perintah lcd.setCursor(5, 0) memosisikan titik awal penulisan teks pada kolom ke-6 (indeks 5) di baris pertama (indeks 0). Posisi ini dihitung secara spesifik agar kata statis "Hidup" tercetak persis di tengah-tengah layar.
 
 ### 3. Logika Teks Berjalan (Loop)
```cpp
C++
void loop() {
  String teksJalan = "               " + isiQuote + "                ";

  for (int i = 0; i <= teksJalan.length() - 16; i++) {

  ```
Di dalam perulangan yang berjalan terus-menerus ini, teks kutipan dimodifikasi. Program menambahkan 15 spasi kosong di depan kalimat dan 16 spasi di belakang kalimat.

Spasi ini adalah trik (padding) agar huruf pertama bisa perlahan muncul dari ujung paling kanan layar, dan kalimat bisa perlahan menghilang saat mencapai ujung kiri layar.

Perulangan for digunakan untuk menentukan titik awal pembacaan karakter yang akan terus bergeser ke kanan seiring bertambahnya nilai i.

### 4. Menampilkan Efek Animasi
``` cpp
C++
    lcd.setCursor(0, 1);
    
    lcd.print(teksJalan.substring(i, i + 16));
    
    delay(250); 
  }
}
```
Pada setiap putaran, kursor layar selalu di-reset ke ujung kiri baris bawah menggunakan lcd.setCursor(0, 1).

Fungsi substring(i, i + 16) adalah kunci dari animasinya. Fungsi ini akan memotong kalimat panjang tadi sebanyak 16 karakter secara presisi. Karena titik awal i selalu bergeser, teks yang ditampilkan di layar seolah-olah terlihat bergerak.

delay(250) memberikan jeda waktu seperempat detik di setiap pergeseran frame agar teks berjalan dalam kecepatan yang nyaman untuk dibaca.