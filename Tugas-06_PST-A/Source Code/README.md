# Folder Source Code

Folder ini berisi source code yang telah dibuat menggunakan Arduino IDE atau PlatformIO dengan format ```.ino``` atau ```.cpp```

Nama    : Imedia Sholem Shoukat
NIM     : H1D023088

## Penjelasan Kode
#### 1. Import Library
```
#include <Adafruit_LiquidCrystal.h>
```
Digunakan library Adafruit_LiquidCrystal.h untuk mengontrol LCD berbasis I2C agar lebih mudah dan stabil, terutama pada simulasi seperti Tinkercad.
#### 2. Inisialisasi LCD
```
Adafruit_LiquidCrystal lcd(0);
```
Untuk membuat LCD dengan komunikasi I2C
#### 3. Simpan Variabel
```
String quote = "nekat dulu aja, ntar juga sampai. ~~azekkk";
```
Menyimpan text yang nantinya akan ditampilkan sebagai scrolling text pada sebuah String.
#### 4. Fungsi Setup
```
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  int pos = (16 - 5) / 2;
  lcd.setCursor(pos, 0);
  lcd.print("QUOTE");
}
```
* nilai 16 dan 2 pada lcd.begin difungsikan untuk mengatur ukuran LCD, yaitu 16 kolom dan 2 baris.
* `lcd.setBacklight` untuk menyalakan lampu latar LCD
* `int pos` untuk menghitung posisi tengah layar. Angka 5 berasal dari jumlah karakter pada kata "QUOTE"
* `lcd.setCursor` untuk menentukan posisi kursor pada LCD, yautu di kolom pos dan baris ke-0 (baris pertama)
* `lcd.print("QUOTE")` untuk menampilkan teks "QUOTE" pada baris pertama LCD.
#### 5. Fungsi Loop
```
void loop() {
  scrollText(quote);
}
```
untuk fungsi untuk memanggil fungsi scrollText dan menjalankannya secara berulang (looping) 
#### 6. Fungsi scrollText
```
void scrollText(String text) {
  String displayText = "                " + text + "                ";

  for (int i = 0; i <= displayText.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(displayText.substring(i, i + 16));

    delay(100); 
  }

  delay(300);
}
```
* `String displayText = " " + text + " "`, Digunakan untuk menambahkan spasi di depan dan belakang teks, agar teks muncul dari sebelah kanan layar dan teks bisa hilang sepenuhnya ke kiri
* `for (int i = 0; i <= displayText.length() - 16; i++)`, digunakan untuk menggeser tampilan teks secara bertahap dari kanan ke kiri.
* `lcd.setCursor(0, 1)`, mengatur posisi kursor di kolom 0, baris ke-1 (baris kedua).
* `lcd.print(displayText.substring(i, i + 16))`, mengambil 16 karakter secara berurutan dari teks, sehingga menciptakan efek scrolling.
* `delay(100)`, mengatur kecepatan pergeseran teks (semakin kecil nilainya, semakin cepat scroll).
* `delay(300)`, memberikan jeda sejenak sebelum animasi diulang kembali.