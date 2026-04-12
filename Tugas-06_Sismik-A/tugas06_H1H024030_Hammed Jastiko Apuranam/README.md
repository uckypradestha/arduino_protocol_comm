#  LCD Scrolling Quote with Arduino (I2C)

Project sederhana menggunakan Arduino dan LCD I2C untuk menampilkan teks berjalan (scrolling text).

Baris pertama menampilkan judul **"QUOTE"**, dan baris kedua menampilkan teks berjalan:
> "alon alon asal kelakon"

---

##  Tujuan Project
- Memahami penggunaan LCD I2C pada Arduino  
- Mempelajari komunikasi I2C (SDA & SCL)  
- Membuat efek scrolling text pada LCD  

---

##  Alat dan Bahan
- Arduino Uno (atau kompatibel)
- LCD 16x2 dengan modul I2C
- Kabel jumper

---

##  Skema Pemasangan (Wiring)

| LCD I2C Pin | Arduino Pin | Keterangan |
| :--- | :--- | :--- |
| GND | GND | Ground |
| VCC | 5V | Power |
| SDA | A4 | Serial Data |
| SCL | A5 | Serial Clock |

---

##  Library yang Digunakan

### 1. Wire.h
Library bawaan Arduino untuk komunikasi I2C.

### 2. LiquidCrystal_I2C.h
Library untuk mengontrol LCD menggunakan modul I2C (lebih hemat pin).

> Pastikan library ini sudah diinstall di Arduino IDE.

---

## penjelasan kode
### 1. inisiasi kode
```cpp 
LiquidCrystal_I2C lcd(0x27, 16, 2);
```
digunakan untuk menginisiasi lcd

### 2. deklarasi variabel
```cpp
String quoteText = "alon alon asal kelakon"; 
String paddedText;
```
quoteText berisi teks utama yang akan ditampilkan dan paddedText digunakan untuk menyimpan teks yang sudah ditambahkan spasi di kiri dan kanan untuk efek scrolling

### 3.  setup
```cpp
lcd.init();
lcd.backlight();
```
digunakan untuk mengaktifkan lcd dan menyalakan baclinght lcd

### 4. menampilkan judul
```cpp
lcd.setCursor(5, 0);
lcd.print("QUOTE");
```
menampilakan baris pertama dan quote untuk baris 0

### 5. efek scroll
```cpp
paddedText = "                " + quoteText + "                ";
```
Menambahkan spasi di awal dan akhir teksdenga tujuan agar teks bisa masuk dari kanan dan keluar ke kiri dengan mulus tampahambatan.

### 6. loop scrolling
```cpp
for (int i = 0; i <= paddedText.length() - 16; i++) {
  lcd.setCursor(0, 1); 
  lcd.print(paddedText.substring(i, i + 16));
  
  delay(200); 
}
```
digunakan untuk mengulang tulisan lcd baris ke 1 dengan delay 200 mili detik