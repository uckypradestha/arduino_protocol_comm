Nama	: Kaira Meilasya Nayada
NIM	: H1H024020
Kelas	: A

link tinkercad
: https://www.tinkercad.com/things/cWzjtgYZP8a-spectacular-hango

Penjelasan Program
- Library yag digunakan
#include <Adafruit_LiquidCrystal.h>
fungsinya : Library ini berfungsi untuk mengontrol LCD menggunakan Arduino, khususnya pada simulasi seperti Tinkercad.

- inisialisasi LCD
Adafruit_LiquidCrystal lcd(0);
fungsinya : Digunakan untuk mendefinisikan objek LCD yang akan digunakan dalam program.

- Deklarasi Variabel
String quote = "life must go on";
String title = "QUOTE";

quote → berisi teks yang akan ditampilkan secara dinamis (berjalan)
title → berisi teks statis yang ditampilkan di baris pertama

- Fungsi setup()
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  int posisiTengah = (16 - title.length()) / 2;
  lcd.setCursor(posisiTengah, 0);
  lcd.print(title);
}
penjelasan :
Penjelasan:

lcd.begin(16, 2) → mengatur LCD menjadi 16 kolom dan 2 baris
lcd.clear() → membersihkan tampilan LCD
lcd.setBacklight(HIGH) → menyalakan lampu latar LCD
posisiTengah → menghitung posisi tengah agar tulisan "QUOTE" berada di tengah
lcd.setCursor(posisiTengah, 0) → mengatur posisi kursor di baris pertama
lcd.print(title) → menampilkan teks "QUOTE" secara statis

- fungsi loop()
void loop() {
  int panjangQuote = quote.length();

  for (int i = 16; i >= -panjangQuote; i--) {

    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(i, 1);
    lcd.print(quote);

    delay(200);
  }
}

penjelasan:
Penjelasan:

panjangQuote → menyimpan panjang teks quote
Perulangan for digunakan untuk menggeser teks dari kanan ke kiri
Dimulai dari i = 16 (di luar layar sebelah kanan)
Berakhir di -panjangQuote (hingga teks keluar dari layar sebelah kiri)
lcd.setCursor(0, 1) + spasi → membersihkan baris kedua
lcd.setCursor(i, 1) → menentukan posisi teks pada baris kedua
lcd.print(quote) → menampilkan teks secara utuh (bukan per karakter)
delay(200) → memberi jeda agar pergerakan teks terlihat
