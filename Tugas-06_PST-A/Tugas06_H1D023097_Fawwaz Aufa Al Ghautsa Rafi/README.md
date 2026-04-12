# Tugas Praktikum: Scrolling Text pada I2C LCD

Repositori ini berisi dokumentasi dan source code Arduino (`Scrolling_text.ino`) untuk menampilkan teks campuran (statis dan bergerak) pada sebuah layar LCD berukuran 16x2 menggunakan modul ekstensi I2C di Tinkercad.

## Deskripsi Logic Simulasi
Pada program ini, saya membuat animasi pergerakan teks di baris kedua menggunakan logika algoritma per-karakter berbasis **String Buffer**.

Teks di dalam proyek kita mensimulasikan:
- **Baris Atas (Statis)**: `Fufufafa` yang posisinya dipusatkan sejajar di tengah.
- **Baris Bawah (Scrolling)**: Menggeser untaian kata `'19 Juta Lapangan Pekerjaan'` berjalan bergulir masuk dari titik ujung yang paling berlawanan (dari tepi luar frame sisi Kanan kemudian raib ke sisi border Kiri).

---

## 💻 Penjelasan Source Code

Berikut cara kerja program di dalam file `Scrolling_text.ino`:

### 1. Library & Inisialisasi Objek Simulator Hardware
```cpp
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
```
- Program ini memakai library modular Tinkercad yaitu `Adafruit_LiquidCrystal.h` sehingga tidak memerlukan setting byte tambahan dan bebas dari driver crash I2C bawaan lama.
- Angka `0` di dalam `lcd(0);` men-generate dan mengkompensasi pin address default hardware I2C bawaan yang tersedia di pallete komponen simulator agar langsung bekerja.

### 2. Deklarasi Parameter Variabel State
```cpp
String textBawah = "'19 Juta Lapangan Pekerjaan'";
int scrollPos = 16; 
```
- `textBawah`: String yang akan ditampilkan.
- `scrollPos`: Pointer variabel integer yang menjadi basis posisi start awal animasi tulisan digeser. Diset awal langsung dengan angka ekstrem `16` (berada di ujung batas batas maksimal visual LCD), agar teks tersebut di detik awal disembunyikan lebih dahulu, lalu akan muncul mulus huruf-demi-huruf meluncur ke layar utama.

### 3. Setup (Pondasi Tampilan dan Teks Statis)
```cpp
void setup() {
  lcd.begin(16,2);
  lcd.clear();    
  lcd.setBacklight(HIGH); 
  
  lcd.setCursor(4, 0); 
  lcd.print("Fufufafa");
}
```
- `lcd.begin(16, 2)`: Inisialisai LCD selebar 16 cell huruf & vertikal 2 baris.
- `lcd.setCursor(4, 0)`: Menge-set alamat matriks awal penulisan untuk teks pada baris `0` (Baris pertama). Lokasi ini sengaja dicetak mulai dari indeks `4`, karena panjang teks "Fufufafa" adalah 8 huruf, Jadi: `(16 total kolom  - 8 huruf ruang yang digunakan) / 2 = 4 sel diapit di sisi tepi`. Rumus ini menjadikannya **Center Aligned**.

### 4. Loop (Mesin Pergerakan Teks - Render Aktual)
```cpp
void loop() {
  lcd.setCursor(0, 1);
  
  String buffer = "";
  for (int i = 0; i < 16; i++) {
    int index = i - scrollPos;
    if (index >= 0 && index < textBawah.length()) {
      buffer += textBawah[index];
    } else {
      buffer += " ";
    }
  }
  
  lcd.print(buffer);
  
  scrollPos--;
  if (scrollPos < -(int)textBawah.length()) {
    scrollPos = 16; 
  }
  delay(100); 
}
```
* **Mempersiapkan Wadah Buffer (`String buffer`)**: Program utama merancang variabel string bayangan. Barisan *for loop* akan memanen 16 iterasi kolom imajiner dan memutuskan mana huruf yang harus ditampilkan di persekian detiknya. Poin pointer perhitunan karakter sesungguhnya memakai rumus index posisi (`index = i - scrollPos;`).
* **Menggambar Teks dan Ruang Kosong**: Selama angka indeks valid (lebih dari `0` dan tak lebih panjang dari jumlah huruf kalimat), maka susunan satu demi satu abjad kalimat dirakit memanjang. Apabila `if` posisi tidak ketemu di memori kalimat, program akan otomatis membungkam/menggelar karpet spasi celah (`" "`) alias merender kekosongan di LCD.
* **Cegak Blink LCD (Layar Kedip)**: Kita tidak memakai sistem iterasi cetak dan hapus bertubi-tubi agar layar terhindar flicker. Untaian `lcd.print(buffer)` dikerjakan tunggal, mencetak satu balok papan utuh secara serentak sehingga layar nyaman dipandang tanpa jeda berkedip.
* **Arah Gulir Tulisan (`scrollPos--`)**: Dari indeks `16` di atas perlahan dikurangi secara kontinyu... `15`.. `14`.. ke nominal minus di kiri, menimbulkan efek ilusi visual animasi teks tergeret dari pinggiran kanan melaju menggeser menjauhi pinggiran kiri. 
* **Perulangan Batas Terakhir (`if scrollPos...`)**: Layaknya roda, di saat angka posisinya mentok terjun melampaui jumlah karakter paling maksimal dari teks (alias seluruh tulisan selesai lewat batas margin pinggiran LCD), reset segera posisi kemudi pointer ke `16`. Loop tulisan bergulung merunut tiada habisnya lagi.
* **Metronom Render Frame (`delay(100)`)**: Laju jeda diatur santai selama `100` millisekon tiap update geseran satu sel ke kiri.

---

## 🔌 Referensi Rangkaian / Wiring Diagram Hardware Simulator
Secara esensial pada Arduino IDE, pastikan konektor *breakout board I2C* dari bagian belakang LCD dicolok akurat agar data bisa bertukar.

| Pin I2C Module | Terminal Pin Arduino Uno R3 | Penjelasan Fungsi Hardware |
| :---: | :---: | :--- |
| **GND** | **GND** | *Ground*. Pemasok grounding ke papan board utama |
| **VCC** | **5V** | Menghubungkan *Supply Voltage* utama modul elektronik (*Penting, dilarang mencolok VCC ini ke AREF!*) |
| **SDA** | **SDA** / *atau* **A4** | Lalulintas pertukaran jalur parameter Data Utama LCD |
| **SCL** | **SCL** / *atau* **A5** | Memainkan sinyal pulsa Clock (Pola irama sinyal detak mesin sinkronisasi) |
