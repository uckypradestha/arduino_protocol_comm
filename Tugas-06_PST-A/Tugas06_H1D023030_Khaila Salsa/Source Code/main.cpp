#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD pada alamat default Tinkercad (0)
Adafruit_LiquidCrystal lcd(0);

// Kalimat dinamis yang akan di-scroll (Teksnya bebas, ini contoh aja)
String quoteText = "Mengejar Aurora di Tromso bersama keluarga pada 2030!"; 
int scrollCursor = 15; // Titik awal kemunculan teks di baris bawah (paling kanan)

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  
  // Spesifikasi: Tulisan QUOTE tepat di tengah tampilan LCD (sifatnya statis)
  // Hitungan: (16 kolom - 5 huruf "QUOTE") / 2 = 5.5 -> Ambil posisi di kolom ke-5
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
}

void loop() {
  // Membersihkan baris kedua setiap kali looping agar teks tidak bertumpuk
  lcd.setCursor(0, 1);
  lcd.print("                "); 
  
  // Logika untuk menampilkan teks berjalan (scrolling text) khusus di baris [1]
  if (scrollCursor >= 0) {
    lcd.setCursor(scrollCursor, 1);
    lcd.print(quoteText.substring(0, 16 - scrollCursor));
  } else {
    lcd.setCursor(0, 1);
    lcd.print(quoteText.substring(-scrollCursor, 16 - scrollCursor));
  }
  
  scrollCursor--; // Angka berkurang terus biar teksnya geser ke kiri
  
  // Jika teks sudah lewat semuanya dari layar, kembalikan posisinya ke ujung kanan lagi
  if (scrollCursor < -(int)quoteText.length()) {
    scrollCursor = 15;
  }
  
  delay(300); // Kecepatan scrolling. Makin kecil angkanya, makin ngebut jalannya.
}