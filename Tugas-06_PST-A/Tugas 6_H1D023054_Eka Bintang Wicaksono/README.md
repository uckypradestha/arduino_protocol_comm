# Tugas 6 - Scrolling Text Led I2C

```
Nama        : Eka Bintang Wicaksono
NIM         : H1D023054
Kelas       : Pemograman Sistem Tertanam A
Tugas       : Tugas 6 Scrolling Text Menggunakan LCD I2C
```

## Deskripsi Singkat Project

Project ini merupakan implementasi komunikasi I2C (Inter-Integrated Circuit) dengan menggunakan LCD 16x2 berbasis I2C. Kode ini menampilkan teks sambutan yang berisi informasi penulis pada startup, kemudian menampilkan quote "Cape Boleh Nyerah Jangan" yang bergeser secara kontinyu dari kanan ke kiri pada baris kedua LCD. Quote akan terus berulang dengan efek scrolling text.

---

## Alat dan Bahan

| No | Komponen | Jumlah | Keterangan |
|---|---|---|---|
| 1 | Arduino Board | 1 | Microcontroller utama |
| 2 | LCD 16x2 I2C Module | 1 | Display dengan I2C interface |
| 3 | Kabel Jumper | 4 | Koneksi antar komponen |
| 4 | Power Supply | 1 | Sumber daya 5V |
| 5 | USB Cable | 1 | Upload kode ke Arduino |

---

## Konfigurasi Pin

### Koneksi LCD I2C ke Arduino:

| Pin LCD I2C | Pin Arduino |
|---|---|
| GND (Ground) | GND |
| VCC (Power) | 5V |
| SDA (Serial Data) | SDA Arduino |
| SCL (Serial Clock) | SCL Arduino |
---

## Penjelasan Kode

### 1. **Include Library dan Inisialisasi**
```cpp
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
```
- Mengimpor library untuk kontrol LCD I2C
- Membuat object `lcd` dengan alamat I2C `0x20`, 16 kolom, 2 baris

### 2. **Setup Function**
```cpp
void setup() {
  lcd.init();        // Inisialisasi LCD
  lcd.clear();       // Hapus layar
  lcd.backlight();   // Nyalakan backlight
  
  // Screen 1 - Tampilan Sambutan
  lcd.setCursor(2, 0);
  lcd.print("Tugas 6 PST");
  lcd.setCursor(1, 1);
  lcd.print("Eka Bintang W");
  delay(3000);       // Tampilkan selama 3 detik
  lcd.clear();       // Bersihkan layar
}
```
**Penjelasan:**
- Menginisialisasi LCD dan mengaktifkan backlight
- Menampilkan pesan sambutan dengan nama penugas selama 3 detik
- `setCursor(x, y)` mengatur posisi cursor (kolom, baris)
- Setelah 3 detik, layar dibersihkan untuk memasuki loop

### 3. **Loop Function**
```cpp
void loop() {
  lcd.setCursor(5, 0);
  lcd.print("QUOTE:");
  
  String text = "Cape Boleh Nyerah Jangan";
  int x = text.length();  // Panjang string = 24 karakter
```
**Penjelasan:**
- Menampilkan judul "QUOTE:" di baris pertama (tetap)
- Menyimpan teks yang akan di-scroll
- `x` menyimpan panjang teks (24 karakter)

### 4. **Efek Scrolling Text**
```cpp
for (int i = 15; i >= -x; i--) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Bersihkan baris
  
  if (i >= 0) {
    lcd.setCursor(i, 1);
    lcd.print(text);
  } else {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(-i));
  }
  
  delay(200);  // Kecepatan scrolling 200ms
}
```

**Penjelasan Detail:**
- **`i` mulai dari 15:** Posisi awal teks di sebelah kanan LCD
- **`i >= -x`:** Loop berlanjut sampai teks sepenuhnya keluar dari layar
- **Pembersihan baris:** `lcd.print("                ")` menghapus sisa teks sebelumnya
- **`if (i >= 0)`:** Saat teks masih dalam rentang LCD, tampilkan seluruh teks
- **`else`:** Saat teks mulai keluar, hanya tampilkan bagian yang masih terlihat dengan `substring()`
- **`delay(200)`:** Kecepatan gerak (semakin kecil = semakin cepat)
