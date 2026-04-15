# Laporan Tugas 6 Sistem Mikrokontroler

**Nama :** M.Fawaz Akbar <br>
**NIM  :** H1H024046 <br>
**Kelas:** B

-----
 ## penjelasan kode

 Program ini mendemostarikan penggunaan Layar LCD menggunakan protokol I2C untuk menampilkan teks yang dapat berjalan (running text).

 ## Library yang digunakan
 ```
 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 ```
 <wire.h> : Library bawaan dari arduino untuk I2C

<LiquidCrystal_I2C.h> : Libary tambahan untuk LCD dengan modul I2C.Digunakan untuk mengontrol LCD

## Variabel teks scrolling
```
String quote = "Tugas Sistem Mikrokontroler.";
String scrollText = "                " + quote + "                ";
```
quote : Teks yang akan ditampilkan (teks yang akan menjadi running text)

scrollText : Pemanbahan 16 spasi  didepan dan belakang agar teks muncul dari sisi kanan dan menghilang dari sisi kiri.

## Fungsi dari setup()
```
void setup() {
  lcd.init();       
  lcd.backlight();  
  lcd.setCursor(5, 0);  
  lcd.print("TUGAS");
}
```
lcd.init() : inisiasi LCD

lcd.backlight() : Menyalakan lampu pada lata belakang

lcd.setCursor(5, 0) : Memulai menampilkan teks dari kolom 5 baris 0(baris atas yang tidak menjadi scrolling text)

lcd.print("TUGAS") : Teks pada baris nol yang akan ditampilkan

## Fungsi dari loop()
```
for (int i = 0; i <= scrollText.length() - 16; i++) {
    lcd.setCursor(0, 1);
    String tampilan = scrollText.substring(i, i + 16);
    lcd.print(tampilan);
    delay(200);
}
```
i <= scrollText.length() - 16 : Batas iterasi agar tidak melebihi string

lcd.setCursor(0, 1) : Menampilkan teks pada baris 2 disetiap iterasi

tring tampilan = scrollText.substring(i, i + 16); : Menapilkan teks dari variabel yang sudah di inisiasi 

delay(200) : Kecepatan scroll teks yang akan di tampilkan

----

## Dokumentasi & Source Code

Vidio dokumentasi : bisa cek di folder `Dokumentasi`
Source Code : bisa di cek di folder `Source Code`



