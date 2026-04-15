# Tugas 6

```
Nama    : Bintang Nugraha Putra
NIM     : H1H024045
Kelas   : B
```

# Source Code

## Library

```c++
#include "Adafruit_LiquidCrystal.h"
```

Menggunakan library Adafruit_LiquidCrystal untuk memudahkan berinteraksi dengan LCD

## Inisialisasi

```c++
// Global
Adafruit_LiquidCrystal lcd(0); // object untuk mengakses lcd
String text[2] = { // text yang akan di tampilkan
    "QUOTE",
    "                Terima kasih sudah mengingatkan "
};

int startIndex = 0; // menampung index per loop
int strLength; // variabel penampung panjang string text[1]
```

Pada inisiasi global, terdapat:

- Object lcd yang digunakan untuk berinteraksi dengan LCD.
- Variabel text, variabel `array of string` untuk menampung teks yang akan di tampilkan
- Variabel startIndex, variabel penampung index keberapa pada saat fungsi loop dijalankan
- Variabel strLength, variabel penampung panjang string dari variabel `text[1]`

<br />

```c++
// inisialisasi Arduino
void setup() {
    if (!lcd.begin(16, 2)) { // menyiapkan lcd
        while (1);
    }

    strLength = text[1].length(); // menghitung panjang teks text[1]

    lcd.setBacklight(HIGH); // menyalakan backlight
    lcd.clear(); // membersihkan lcd
    lcd.setCursor((16 / 2) - (text[0].length() / 2 + 1), 0); // mengatur cursor agar menempatkan text di tengah secara otomatis
    lcd.print(text[0]); // menampilkan text[0]
}
```

Pada inisiasi Arduino, akan melakukan:

- Mempersiapkan lcd dengan `lcd.begin(16,2)`, pada kode tersebut lcd akan di cek sampai lcd siap untuk digunakan
- Melakukan perhitungan untuk mengetahui panjang teks yang berjalan;
- Menyalakan backlight(lampu belakang);
- Membersihkan tampilan LCD
- Mengatur kursor LCD agar `text[0]` tepat di tengah layar
- Menampilkan tulisan dari `text[0]`

## Looping

```c++
void loop() {
    String cur = ""; // variabel penampung text yang akan di tampilkan secara scrolling

    for (int i = 0; i < 16; i++) { // looping untuk scroll text (text[1])
        int curIndex = (startIndex + i) % strLength; // mendapatkan index untuk menampilkan text berdasarkan ukuran layar
        cur += text[1][curIndex]; // mendapatkan char sesuai curIndex
    }

    lcd.setCursor(0, 1); // memindahkan kursor ke (0, 1)
    lcd.print(cur); // menampilkan scrolling text
    startIndex++;
}
```

Pada fungsi looping, akan menjalankan:

- Membuat variabel penampung dari text yang akan ditampilkan
- Looping untuk mengatur text yang akan di tampilkan sesuai posisi dari `startIndex` agar text terasa seperti berjalan.
- Mengatur posisi kursor ke kolom ke 0, baris ke 2
- Menampilkan text
- Menambahkan `startIndex`

# Documentation

Jika video demo tidak dapat dilihat, bisa di akses lewat:
[Github](Dokumentasi/video-demo.mp4)<br />
[GDrive](https://drive.google.com/file/d/14Kbh8GlZDSDmGYbHfB-HmFaNKGHxS-WD/view?usp=sharing)

# Folders

[Dokumentasi](Dokumentasi/)<br />
[Source Code](Source%20Code/)
