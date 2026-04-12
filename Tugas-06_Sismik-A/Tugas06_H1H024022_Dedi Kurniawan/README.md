# Penjelasan Kode

## Penggunaan Library & Deklarasi Variabel Awal
Bagian ini berada di paling atas kode, sebelum fungsi setup(). Fungsinya adalah untuk mempersiapkan semua "alat" dan "bahan" yang akan digunakan oleh program.

- ```cpp
  #include <Adafruit_LiquidCrystal.h>
  ```
  Mengimpor library LCD I2C.
  
- ```cpp
  Adafruit_LiquidCrystal lcd(0);
  ```
  Membuat objek LCD dengan alamat I2C default.
  
- ```cpp
  scrollText
  ```
  Menambahkan spasi di awal & akhir untuk efek scrolling.
  
- ```cpp
  posisiScroll
  ```
  Menyimpan posisi pergeseran teks.
  
---

## Inisialisasi
```cpp
void setup()
```
Fungsi **setup()** hanya dieksekusi satu kali saat Arduino pertama kali dinyalakan atau di-reset. Fungsinya adalah untuk melakukan pengaturan awal (setting dasar).

- ```cpp
  lcd.begin(16, 2);
  ```
  Mengatur LCD 16x2.
  
- ```cpp
  lcd.clear();
  ```
  Membersihkan layar.
  
- ```cpp
  lcd.setBacklight(HIGH);
  ```
  Menyalakan lampu latar.
  
- ```cpp
  lcd.setCursor(5, 0);
  ```
  Mengatur posisi kursor.
  
- ```cpp
  lcd.print("QUOTE");
  ```
  Menampilkan teks "QUOTE".
  
---

## Looping
```cpp
void loop()
```
Fungsi **loop()** akan dieksekusi berulang-ulang tanpa henti selama Arduino menyala. Di sinilah animasi pergerakan teks (dinamis) dibuat.

- ```cpp
  String textTampil = scrollText.substring(posisiScroll, posisiScroll + 16);
  ```
  Perintah **substring()** berfungsi untuk "memotong" teks panjang menjadi bagian kecil. Di sini, kita hanya mengambil 16 karakter dari scrollText, dimulai dari indeks **posisiScroll**.
  
- ```cpp
  lcd.setCursor(0, 1);
  ```
  Mengembalikan kursor ke ujung paling kiri bawah (Kolom 0, Baris 1).
  
- ```cpp
  lcd.print(textTampil);
  ```
  Menampilkan teks hasil pemotongan tersebut ke layar.
  
- ```cpp
  posisiScroll++;
  ```
  Menggeser titik awal pengambilan substring pada iterasi berikutnya, sehingga menghasilkan efek teks berjalan.
  
- ```cpp
  if (posisiScroll > scrollText.length() - 16) { posisiScroll = 0; }
  ```
  Mekanisme pengulangan agar animasi kembali ke awal setelah mencapai akhir teks.

- ```cpp
  delay(300);
  ```
  Memberikan jeda selama 300 milidetik untuk mengatur kecepatan pergerakan teks agar tetap terbaca.
    
---







