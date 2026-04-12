#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD I2C menggunakan alamat 0 (MCP23008 pada Tinkercad)
Adafruit_LiquidCrystal lcd(0);

// ================= KONFIGURASI =================
const int kolom = 16;        // Jumlah kolom LCD
const int baris = 2;         // Jumlah baris LCD
const int delayScroll = 80;  // Kecepatan pergerakan teks (semakin kecil semakin cepat)

// Teks yang akan ditampilkan secara berjalan pada baris kedua
String pesan = "Kesuksesan dimulai dari usaha dan doa";
int panjangTeks;

// ================= FUNGSI =================

// Fungsi untuk membersihkan isi baris kedua LCD
void clearBarisBawah() {
  lcd.setCursor(0, 1);              // Posisikan kursor di awal baris kedua
  lcd.print("                ");    // Cetak 16 spasi untuk menghapus teks sebelumnya
}

// ================= SETUP =================
void setup() {
  lcd.begin(kolom, baris);   // Inisialisasi LCD sesuai ukuran
  lcd.setBacklight(HIGH);    // Mengaktifkan lampu latar LCD

  // Menampilkan judul pada baris pertama secara terpusat
  String judul = "QUOTE";
  int posisi = (kolom - judul.length()) / 2; // Menghitung posisi tengah

  lcd.setCursor(posisi, 0);  // Set posisi kursor di baris pertama
  lcd.print(judul);          // Menampilkan judul

  // Menghitung panjang teks untuk kebutuhan pergeseran (scroll)
  panjangTeks = pesan.length();
}

// ================= LOOP =================
void loop() {

  // Perulangan untuk menghasilkan efek teks berjalan dari kanan ke kiri
  for (int geser = 0; geser < kolom + panjangTeks; geser++) {

    clearBarisBawah();  // Membersihkan baris kedua sebelum menampilkan frame berikutnya

    // Menentukan posisi awal teks berdasarkan nilai pergeseran
    int posisiAwal = kolom - geser;

    // Menampilkan karakter satu per satu sesuai posisi yang dihitung
    for (int i = 0; i < panjangTeks; i++) {
      int posisiKolom = posisiAwal + i;

      // Hanya menampilkan karakter yang berada dalam area tampilan LCD
      if (posisiKolom >= 0 && posisiKolom < kolom) {
        lcd.setCursor(posisiKolom, 1);  // Set posisi di baris kedua
        lcd.print(pesan[i]);            // Cetak karakter
      }
    }

    delay(delayScroll); // Memberikan jeda agar animasi terlihat halus
  }

  // Jeda sebelum animasi diulang kembali dari awal
  delay(1000);
}