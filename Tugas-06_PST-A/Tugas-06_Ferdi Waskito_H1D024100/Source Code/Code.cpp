#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD
Adafruit_LiquidCrystal lcd(0);

// ==================== KONFIGURASI SISTEM ====================
const int LCD_LEBAR  = 16;
const int LCD_TINGGI = 2;
const int SPEED_TEKS = 200; // Semakin kecil semakin cepat

// ==================== DATA TEKS (BISA DIGANTI) ====================
// Kamu bisa menambah atau mengganti teks di sini dengan mudah
String daftarQuote[] = {
  "Sleep for a total of 800 hours per day ."
};

int jumlahQuote = 2;    // Sesuaikan dengan jumlah baris di atas
int quoteIndex = 0;     // Penanda quote mana yang sedang tampil

// ==================== SETUP ====================
void setup() {
  lcd.begin(LCD_LEBAR, LCD_TINGGI);
  lcd.setBacklight(HIGH);
}

// ==================== LOOP UTAMA ====================
void loop() {
  // Ambil quote berdasarkan index saat ini
  String teksTampil = daftarQuote[quoteIndex];

  // Jalankan fungsi scroll
  tampilkanJudul("Prescript"); // Teks statis di baris 0
  jalankanScrollTeks(teksTampil, 1); // Scroll di baris 1

  // Pindah ke quote berikutnya setelah satu putaran selesai
  quoteIndex++;
  if (quoteIndex >= jumlahQuote) {
    quoteIndex = 0; // Kembali ke quote pertama
  }

  delay(500); // Jeda sebelum ganti ke quote baru
}

// ==================== FUNGSI PEMBANTU ====================

// Fungsi untuk menampilkan judul di baris atas secara statis
void tampilkanJudul(String judul) {
  int posisi = (LCD_LEBAR - judul.length()) / 2;
  lcd.setCursor(0, 0);
  lcd.print("                "); // Bersihkan baris 0
  lcd.setCursor(posisi, 0);
  lcd.print(judul);
}

// Fungsi scroll yang lebih efisien (Anti-Flicker)
void jalankanScrollTeks(String teks, int baris) {
  // Tambahkan spasi agar teks masuk dan keluar dengan halus
  String pesanPenuh = "                " + teks + "                ";

  for (int i = 0; i < pesanPenuh.length() - LCD_LEBAR + 1; i++) {
    lcd.setCursor(0, baris);

    // Ambil potongan teks sebesar 16 karakter
    String potongan = pesanPenuh.substring(i, i + LCD_LEBAR);
    lcd.print(potongan);

    delay(SPEED_TEKS);
  }
}