#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//kata yanga akan ditampilkan
//diisi 16 karakter kosong agar layar menampilkan kosong terlebih dahulu dan kosong lagi diakhir
String kata = "                Fake it until you make it                ";

//setup program awal
//menyalakan lcd dan lampunya
//set teks QUOTES ditengah
void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(5, 0);
  lcd.print("Quotes");
}

//program yang akan terus berjalan
void loop() {
  
  //looping
  //selama i lebih dari kata.length/25+16+16=57, i++
  for (int i = 0; i <= kata.length() - 16; i++) {
    //set cursor di baris ke 2, kolom 0 (paling kiri)
    lcd.setCursor(0, 1);
    //tampilkan kata dari index i ke i+16
    //untuk awal kosong hingga F
    String potong = kata.substring(i, i + 16);
    lcd.print(potong);
    //delay 150 ms sebelum ganti teks
    delay(150);
  }
}