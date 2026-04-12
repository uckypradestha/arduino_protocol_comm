# README - Source Code Arduino

Dokumen ini berisi penjelasan mengenai kode program Arduino yang terdapat dalam folder *Source Code*. Setiap program memiliki fungsi berbeda yang berkaitan dengan komunikasi serial dan penggunaan LCD berbasis I2C.

---

## 1. Komunikasi Serial & LED

### Library

Tidak menggunakan library tambahan, hanya fungsi bawaan Arduino.

### Inisialisasi

```cpp
const int ledPin = 8;
```

Mendefinisikan pin 8 sebagai output untuk LED.

```cpp
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
```

* `Serial.begin(9600)` digunakan untuk memulai komunikasi serial dengan baud rate 9600.
* `pinMode()` mengatur pin LED sebagai output.

### Looping

```cpp
digitalWrite(ledPin, HIGH);
Serial.println("Hello World");
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
```

* LED menyala selama 1 detik lalu mati selama 1 detik.
* Setiap LED menyala, Arduino mengirimkan teks **"Hello World"** ke Serial Monitor.

---

## 2. I2C LCD Print (l2c_print)

### Library

```cpp
#include <Adafruit_LiquidCrystal.h>
```

Library untuk mengontrol LCD berbasis I2C.

### Inisialisasi

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Membuat objek LCD dengan alamat I2C default.

```cpp
lcd.begin(16, 2);
lcd.clear();
lcd.setBacklight(HIGH);
```

* Mengatur LCD berukuran 16 kolom dan 2 baris.
* Membersihkan layar.
* Menyalakan backlight.

### Looping

Tidak ada proses looping (kosong), karena teks hanya ditampilkan sekali saat setup.

### Output

* Baris 1: "Hello World!"
* Baris 2: "DIVA SYAHITA"

---

## 3. I2C Scanner (l2c_scanning)

### Library

```cpp
#include <Wire.h>
```

Digunakan untuk komunikasi I2C.

### Inisialisasi

```cpp
Wire.begin();
Serial.begin(9600);
```

Memulai komunikasi I2C dan Serial.

### Looping

* Program melakukan scanning alamat I2C dari 1 hingga 126.
* Menggunakan:

```cpp
Wire.beginTransmission(address);
error = Wire.endTransmission();
```

### Fungsi

* Jika perangkat ditemukan → menampilkan alamat I2C.
* Jika tidak ada perangkat → menampilkan pesan "Tidak ada device I2C".
* Scan diulang setiap 3 detik.

---

## 4. I2C LCD Scrolling Text (l2c_scrolling)

### Library

```cpp
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
```

* `Wire.h` untuk komunikasi I2C.
* `Adafruit_LiquidCrystal` untuk kontrol LCD.

### Inisialisasi

```cpp
Adafruit_LiquidCrystal lcd(0);
const char* quote = "Belajar hari ini untuk masa depan yang lebih baik ";
```

Menyimpan teks yang akan di-scroll.

```cpp
lcd.begin(16, 2);
lcd.setBacklight(1);
```

Mengatur LCD dan menyalakan backlight.

### Looping

* Menggunakan perulangan untuk membuat efek scrolling teks.
* Teks bergerak dari kanan ke kiri pada baris kedua LCD.

```cpp
for (int offset = 0; offset < 16 + len; offset++)
```

### Fungsi

* Baris pertama menampilkan judul "QUOTE".
* Baris kedua menampilkan teks berjalan (scrolling).
* Efek animasi dibuat dengan menggeser posisi karakter satu per satu.

---

## Kesimpulan

Keempat program ini menunjukkan:

* Dasar komunikasi serial Arduino
* Penggunaan LED sebagai output
* Penggunaan LCD berbasis I2C
* Teknik scanning alamat I2C
* Implementasi teks statis dan scrolling pada LCD

Program-program ini sangat berguna untuk memahami dasar interaksi hardware dan komunikasi pada Arduino.

---
