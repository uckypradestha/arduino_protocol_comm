# Library & Inisialisasi LCD
```
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
```
> - include → memanggil library LCD dari Adafruit
> - lcd(0) → membuat objek LCD dengan alamat I2C 0
# Variabel Teks
```
String quote = "Jatuh 7 kali bangkit 8 kali";
```
> Menyimpan kalimat yang nanti akan ditampilkan di LCD <br>
Tipe String → bisa pakai .length() untuk menghitung panjang teks
# Fungsi setup()
```
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}
```
> - lcd.begin(16, 2) → LCD ukuran 16 kolom, 2 baris
> - lcd.setBacklight(1) → menyalakan lampu LCD
> - lcd.setCursor(5, 0) → posisi kolom ke-5, baris pertama
> - lcd.print("QUOTE") → menampilkan judul "QUOTE" di baris atas
#Fungsi loop() (Inti Program
```
void loop() {
  int panjang = quote.length();
```
> Mengambil panjang teks → disimpan di variabel panjang
# Perulangan untuk efek scroll
```
for (int i = 15; i >= -panjang; i--) {
```
> - i = 15 → mulai dari kanan layar (kolom paling kanan)
> - i >= -panjang → berhenti saat teks sudah keluar semua ke kiri
> - i-- → bergerak ke kiri (efek jalan)
# Meampilkan teks
```
  lcd.setCursor(i, 1);
  lcd.print(quote);
```
> - lcd.setCursor(i,1) → menggeser posisi teks sesuai nilai i
> - lcd.print(quote) → mencetak teks
