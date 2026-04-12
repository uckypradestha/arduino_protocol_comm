# Program Scrolling Text LCD I2C

Program ini menggunakan Arduino Uno dan LCD 16x2 I2C untuk menampilkan:

- Baris pertama : **QUOTES** (statis)
- Baris kedua : **Tetaplah Hidup** (bergerak dari kanan ke kiri)

---

## Source Code

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "Tetaplah Hidup";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor(5, 0);
  lcd.print("QUOTES");
}

void loop() {

  int totalLength = text.length() + 32;

  for (int i = 0; i <= totalLength - 16; i++) {

    lcd.setCursor(0, 1);

    for (int j = 0; j < 16; j++) {

      int index = i + j - 16;

      if (index < 0 || index >= text.length()) {
        lcd.print(" ");
      } else {
        lcd.print(text[index]);
      }
    }

    delay(250);
  }
}
````

---

# Penjelasan Program Per Baris

## Library LCD

```cpp
#include <Adafruit_LiquidCrystal.h>
```

Digunakan untuk memanggil library LCD I2C agar Arduino dapat mengontrol LCD.

---

## Membuat Objek LCD

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Membuat objek LCD bernama `lcd`.

Angka `0` adalah alamat I2C LCD pada Tinkercad.

---

## Variabel Text

```cpp
String text = "Tetaplah Hidup";
```

Menyimpan teks yang akan ditampilkan berjalan pada baris kedua.

---

# Fungsi setup()

Dijalankan satu kali saat Arduino menyala.

---

## Inisialisasi LCD

```cpp
lcd.begin(16, 2);
```

Menentukan ukuran LCD:

* 16 kolom
* 2 baris

---

## Membersihkan LCD

```cpp
lcd.clear();
```

Menghapus isi layar LCD.

---

## Menyalakan Lampu LCD

```cpp
lcd.setBacklight(HIGH);
```

Menyalakan backlight LCD.

---

## Mengatur Posisi Cursor

```cpp
lcd.setCursor(5, 0);
```

Cursor dipindah ke:

* kolom ke-5
* baris ke-0

---

## Menampilkan Judul

```cpp
lcd.print("QUOTES");
```

Menampilkan tulisan QUOTES di baris atas.

---

# Fungsi loop()

Berjalan terus menerus.

---

## Menghitung Panjang Area Scroll

```cpp
int totalLength = text.length() + 32;
```

Digunakan untuk membuat area scrolling.

Terdiri dari:

* 16 spasi kiri
* panjang text
* 16 spasi kanan

Tujuannya agar teks:

* muncul dari kanan
* berjalan di layar
* keluar ke kiri

---

## Perulangan Geser Text

```cpp
for (int i = 0; i <= totalLength - 16; i++)
```

Digunakan untuk menggeser tampilan teks.

Variabel `i` adalah posisi pergeseran animasi.

Semakin besar `i`, teks semakin bergerak ke kiri.

---

## Posisi Cursor Baris Kedua

```cpp
lcd.setCursor(0, 1);
```

Cursor dipindah ke:

* kolom 0
* baris 1

Agar penulisan dimulai dari kiri baris kedua.

---

## Mengisi 16 Kolom LCD

```cpp
for (int j = 0; j < 16; j++)
```

Perulangan untuk mengisi seluruh kolom LCD.

Karena LCD memiliki 16 kolom.

---

## Menentukan Huruf Yang Ditampilkan

```cpp
int index = i + j - 16;
```

Menentukan karakter keberapa dari text yang ditampilkan.

`-16` digunakan agar teks awalnya berada di luar layar kanan.

---

## Jika Index Tidak Valid

```cpp
if (index < 0 || index >= text.length())
```

Jika index:

* kurang dari 0
* melebihi panjang text

Maka tidak ada huruf yang ditampilkan.

---

## Menampilkan Spasi

```cpp
lcd.print(" ");
```

Jika index tidak valid, LCD menampilkan spasi kosong.

---

## Menampilkan Huruf

```cpp
lcd.print(text[index]);
```

Jika index valid, huruf dari text ditampilkan.

Contoh:

* text[0] = T
* text[1] = e

---

## Delay Gerakan

```cpp
delay(250);
```

Memberikan jeda 250 ms agar scrolling terlihat.

Semakin kecil delay, semakin cepat gerakan teks.

---

# Cara Kerja Program

Baris pertama:

```text
     QUOTES
```

Baris kedua:

```text
               T
              Te
             Tet
            Teta
           Tetap
...
Tetaplah Hidup
...
```

Lalu keluar ke kiri dan mengulang terus.

---
