# Laporan Tugas 6 Sistem Mikrokontroler

**Nama :** Muhammad Aziz Ihza Fahriza Salam <br>
**NIM  :** H1H024050 <br>
**Kelas:** B<br>
**Mata Kuliah :** Sistem Mikrokontroler

-----
 ## penjelasan kode

 Program ini mendemostarikan penggunaan Layar LCD menggunakan protokol I2C untuk menampilkan teks statis dan dinamis pada lcd

 ## Library yang digunakan
 ```
 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 ```
 <wire.h> : Library bawaan untuk I2C

<LiquidCrystal_I2C.h> : Libary untuk LCD dengan modul I2C.berfungsi untuk mengontrol LCD

## Variabel Quote scrolling
```
String quote = "Selamat Berjuang, Sukse";
String scrollquote = "                " + quote + "                ";
```
quote : Teks Dinamis yang akan ditampilkan Secara Berjalan Pada LCD

scrollquote : Menambahkan 16 spasi didepan dan belakang supaya teks muncul dari sisi kanan

## setup()
```
void setup() {
  lcd.init();       
  lcd.backlight();  
  lcd.setCursor(5, 0);  
  lcd.print("QUOTE");
}
```
lcd.init() : inisiasi LCD

lcd.backlight() : Menyalakan lampu pada latar belakang LCD

lcd.setCursor(5, 0) : Memulai menampilkan teks Statis dari kolom 5 baris 0

lcd.print("QUOTE") : Teks statis pada baris nol yang akan ditampilkan di layar LCD

## loop()
```
for (int i = 0; i <= scrollquote.length() - 16; i++) {
    lcd.setCursor(0, 1);
    String tampilan = scrollquote.substring(i, i + 16);
    lcd.print(tampilan);
    delay(200);
}
```
i <= scrollquote.length() - 16 : membatas iterasi agar tidak melebihi string

lcd.setCursor(0, 1) : Menampilkan teks pada baris 2 disetiap iterasi

string tampilan = scrollquote.substring(i, i + 16); : Variabel untuk menampilkan teks dari variabel yang sudah di inisiasi di setup 

delay(300) : Kecepatan scroll quote pada baris 2

----

## Link Simulasi Tinkercad

Link Tinkercad :(https://www.tinkercad.com/things/cxalQzmyOzW-tugas6sistem-mikrokontroler?sharecode=extre74jt_Pch9FUNXns5RxaPaozPA9leLjWqs2QqZ4)
