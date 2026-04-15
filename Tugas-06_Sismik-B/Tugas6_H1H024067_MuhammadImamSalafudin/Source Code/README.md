
## Library & Inisialisasi LCD
```ino
#include 
Adafruit_LiquidCrystal lcd(0);
```
- `include` → memanggil library LCD dari Adafruit
- `lcd(0)` → membuat objek LCD dengan alamat I2C 0
---
## Variabel Teks
```cpp
String kata = "Jawa adalah kunci";
```
- Menyimpan kalimat yang nanti akan ditampilkan di LCD
- Tipe `String` → bisa pakai `.length()` untuk menghitung panjang teks
---
## Fungsi `setup()`
```cpp
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(3, 0);
  lcd.print("Kata-Kata");
}
```
- `lcd.begin(16, 2)` → LCD ukuran 16 kolom, 2 baris
- `lcd.setBacklight(1)` → menyalakan lampu LCD
- `lcd.setCursor(3, 0)` → posisi kolom ke-3, baris pertama
- `lcd.print("Kata-Kata")` → menampilkan judul di baris atas, diam tidak bergerak
---
## Fungsi `loop()` — Inti Program
```cpp
void loop() {
  int panjang = kata.length();
```
- Mengambil panjang teks → disimpan di variabel `panjang`
---
## Perulangan untuk Efek Scroll
```cpp
for (int i = 15; i >= -panjang; i--) {
```
- `i = 15` → mulai dari kanan layar (kolom paling kanan)
- `i >= -panjang` → berhenti saat teks sudah keluar semua ke kiri
- `i--` → bergerak ke kiri satu langkah tiap iterasi
---
## Membangun Baris 16 Karakter
```cpp
String baris = "";
for (int j = 0; j < 16; j++) {
  int idx = j - i;
  if (idx >= 0 && idx < panjang) {
    baris += kata[idx];
  } else {
    baris += " ";
  }
}
```
- Membuat string sepanjang tepat **16 karakter** setiap frame
- `idx = j - i` → menghitung huruf mana yang tampil di kolom `j`
- Jika `idx` valid → ambil huruf dari `kata`
- Jika tidak → isi dengan spasi agar karakter lama tertimpa
---
## Menampilkan Teks
```cpp
lcd.setCursor(0, 1);
lcd.print(baris);
delay(200);
```
- `lcd.setCursor(0, 1)` → selalu mulai dari kolom 0, baris bawah
- `lcd.print(baris)` → mencetak 16 karakter sekaligus tanpa kedip
- `delay(200)` → jeda antar frame, makin kecil makin cepat scrollnya
---
