#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Teks utama yang ingin ditampilkan
String pesanQuote = "Segala Hal yang Baik Adanya.";

// Variabel untuk menampung teks yang sudah ditambahkan spasi
String textBerjalan; 

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();

  // Baris pertama menampilkan tulisan "QUOTE" secara tetap di tengah
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
  
  // Teknik running text:
  // Ditambahkan spasi kosong di depan dan belakang teks.
  // Tujuannya supaya teks terlihat muncul dari kanan layar
  // lalu menghilang perlahan ke kiri hingga selesai.
  textBerjalan = "                " + pesanQuote + "                ";
}

void loop() {
  // Perulangan untuk menggeser tampilan teks sedikit demi sedikit
  // Akan berhenti saat sisa teks kurang dari lebar LCD (16 karakter)
  for (int i = 0; i <= textBerjalan.length() - 16; i++) {
    
    lcd.setCursor(0, 1); // Posisi kursor tetap di kiri baris kedua
    
    // Mengambil sebagian teks sepanjang 16 karakter
    // yang digeser satu per satu setiap iterasi
    lcd.print(textBerjalan.substring(i, i + 16));
    
    // Delay untuk mengatur kecepatan pergeseran teks
    // Bisa dipercepat (misal 100) atau diperlambat (misal 200)
    delay(150); 
  }
}