# LCD Scrolling Text

## Deskripsi Program
Program ini menampilkan teks berjalan (*scrolling text*) pada LCD 16x2 menggunakan komunikasi I2C.  
Baris pertama menampilkan teks statis **"QUOTE"**, sedangkan baris kedua menampilkan kalimat yang bergerak dari kanan ke kiri.

Efek scrolling dibuat dengan cara menampilkan sebagian (window) dari teks yang lebih panjang secara bertahap.

---

## Library yang Digunakan

### `#include <Adafruit_LiquidCrystal.h>`
- Library untuk mengontrol LCD berbasis I2C
- Menyederhanakan komunikasi dengan LCD tanpa perlu mengatur pin secara manual
- Mengabstraksi komunikasi menjadi fungsi yang mudah digunakan

---

## Deklarasi Global

```cpp
Adafruit_LiquidCrystal lcd(0);

String header = "QUOTE";
String quote = "setelah gelap terbit terang";

// spasi depan (masuk dari kanan) + spasi belakang (keluar ke kiri)
String scrollText = "                " + quote + "                ";
```

| Variabel | Nilai | Penjelasan |
|----------|-------|-----------|
| `header` | "QUOTE" | Judul/label yang ditampilkan di baris pertama LCD |
| `quote` | "setelah gelap terbit terang" | Teks utama yang akan discroll |
| `scrollText` | spasi + quote + spasi | Teks lengkap dengan spasi tambahan untuk efek scroll masuk dan keluar |

**Fungsi Spasi:**
- **Spasi Depan (16 spasi)**: Memberikan efek teks "masuk" dari tepi kanan LCD
- **Spasi Belakang (16 spasi)**: Memberikan efek teks "keluar" dari tepi kiri LCD

---

## Fungsi setup()

Fungsi ini dijalankan sekali saat Arduino dinyalakan:

```cpp
void setup() {
  lcd.begin(16, 2);        // Inisialisasi LCD dengan ukuran 16 kolom x 2 baris
  lcd.clear();             // Hapus semua konten LCD
  lcd.setBacklight(HIGH);  // Nyalakan backlight LCD
  
  lcd.setCursor(5, 0);     // Set posisi kursor ke kolom 5, baris 0 (baris pertama)
  lcd.print(header);       // Tampilkan "QUOTE" di baris pertama
}
```

### Penjelasan Baris per Baris:

1. **`lcd.begin(16, 2)`**
   - Mengatur ukuran LCD: 16 kolom (karakter horizontal) dan 2 baris (vertikal)
   - Inisialisasi komunikasi I2C dengan perangkat LCD

2. **`lcd.clear()`**
   - Membersihkan layar LCD dari konten sebelumnya
   - Memastikan layar dalam keadaan bersih sebelum menampilkan konten baru

3. **`lcd.setBacklight(HIGH)`**
   - Menyalakan backlight (cahaya latar) LCD
   - Membuat teks terlihat jelas di tempat gelap

4. **`lcd.setCursor(5, 0)`**
   - Memposisikan kursor di kolom ke-5 dan baris ke-0 (baris pertama, dimulai dari 0)
   - Ini membuat teks "QUOTE" berada di tengah-tengah kolom LCD (16 ÷ 2 - 3 = 5)

5. **`lcd.print(header)`**
   - Menampilkan string `header` ("QUOTE") di posisi yang sudah ditentukan

---

## Fungsi loop()

Fungsi ini dijalankan berulang kali setelah `setup()` selesai:

```cpp
void loop() {
  for (int i = 0; i <= scrollText.length() - 16; i++) {
    lcd.setCursor(0, 1);                    // Set kursor ke kolom 0, baris 1
    lcd.print(scrollText.substring(i, i + 16)); // Tampilkan 16 karakter dari posisi i
  }
}
```

### Penjelasan:

LCD hanya dapat menampilkan 16 karakter sekaligus, sehingga digunakan teknik sliding window sepanjang 16 karakter.

1. Mekanisme Scrolling
- scrollText.substring(i, i + 16) mengambil 16 karakter dari posisi ke-i
- Setiap iterasi, posisi i bertambah → window bergeser
- Efek visual: teks terlihat bergerak dari kanan ke kiri
2. Batas Perulangan
- scrollText.length() - 16 memastikan substring tidak melebihi panjang string
- Panjang scrollText = panjang quote + 32 spasi tambahan

---

## Alur Kerja Program

### Tahap 1: Inisialisasi (Setup)
```
1. LCD dinyalakan (16x2)
2. Layar dibersihkan
3. Backlight dinyalakan
4. "QUOTE" ditampilkan di baris pertama, posisi tengah
```

### Tahap 2: Eksekusi Berulang (Loop)
```
"                setel"
"               setela"
"              setelah"
...
"terang                "
```
- Muncul dari kanan
- Bergerak ke kiri
- Keluar sepenuhnya dari layar
- Proses berulang

---

## Kesimpulan

Program ini mendemonstrasikan:
- Penggunaan library Adafruit untuk LCD I2C
- Manipulasi string untuk efek scrolling
- Kontrol tampilan LCD (cursor, backlight)
- Looping untuk animasi teks berulang
- Implementasi protokol I2C komunikasi dengan LCD
