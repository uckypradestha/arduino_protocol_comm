#include <Adafruit_LiquidCrystal.h> 
Adafruit_LiquidCrystal lcd(0); = menggunakan library lcd I2C dengan alamat lcd(0)

String textAtas = "QUOTE"; merupakan deklarasi variabel untuk text baris atas
String textBawah = "     quote     "; merupakan deklarasi variabel untuk teks baris bawah
int posisi = 0; merupakan deklarasi variabel untuk posisi teks
int panjang; = merupakan deklarasi variabel untuk panjang

lcd.begin(16, 2); membuat lcd ukuran 16 kolom dan 2 baris
lcd.clear(); membersihkan layar
lcd.setBacklight(HIGH); menyalakan lampu lcd


lcd.setCursor((16 - textAtas.length()) / 2, 0); agar teks rata tengah dan di baris atas
lcd.print(textAtas); mencetak teks atas

panjang = textBawah.length(); mengitung panjang disamakan dengan teks baawah digunakan saat looping

lcd.setCursor(0, 1); mengatur agar teks dibaawah
for (int i = 0; i < 16; i++) { 
  int index = (posisi + i) % panjang; 
  lcd.print(textBawah[index]);
} = membuat perintah loop dari 1 sampai 16 sesuai lebar lcd


if (posisi >= panjang) {
  posisi = 0;
} agar teks kembali ke awal jika sudah sampai akhir

delay(300); mengatur kecepatan scroll
