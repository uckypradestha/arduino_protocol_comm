## Laporan Tugas 6

Nama: Hana Nur Fathiyyah  
NIM: H1H024107  
Matkul: Sistem Mikrokontroller  
Kelas: A  

Penjelasan Program (sceth.ino)

Program ini menggunakan protokol I2C untuk menampilkan teks pada LCD 16x2. Terdapat dua bagian utama tampilan:

- **Statis**: Menampilkan kata "QUOTE" pada baris pertama (baris 0) dan posisinya berada di tengah layar.
- **Dinamis (Running Text)**: Menampilkan kalimat *"One Dream, Annyeonghaseyo! Tomorrow by Together!!"* pada baris kedua (baris 1) yang bergerak dari kanan ke kiri.

Fungsi Utama

- Menggunakan library `Wire.h` dan `Adafruit_LiquidCrystal.h` untuk komunikasi I2C dengan LCD.

- `lcd.begin(16, 2)`  
  Digunakan untuk menginisialisasi LCD dengan ukuran 16 kolom dan 2 baris.

- `(16 - text.length()) / 2`  
  Digunakan untuk menentukan posisi tengah teks "QUOTE" pada baris pertama.

- `quote.substring(i, i + 16)`  
  Digunakan untuk mengambil 16 karakter dari teks sehingga dapat ditampilkan sebagai running text.

- `for` loop  
  Digunakan untuk menggeser teks secara bertahap dari kanan ke kiri.

- `delay(150)`  
  Digunakan untuk mengatur kecepatan pergerakan teks agar terlihat halus.

Cara Kerja Program

1. LCD diinisialisasi dengan ukuran 16x2.
2. Teks "QUOTE" ditampilkan di tengah pada baris pertama.
3. Teks panjang ditambahkan spasi di bagian depan agar muncul dari sisi kanan.
4. Program mengambil 16 karakter dari teks secara bertahap.
5. Teks ditampilkan dan digeser terus menerus sehingga terlihat berjalan.

Hasil : https://www.tinkercad.com/things/8uJCvTYd3U9-tugas6

Kode Program (sceth.ino)

```cpp
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);

  String text = "QUOTE";
  int pos = (16 - text.length()) / 2;
  lcd.setCursor(pos, 0);
  lcd.print(text);
}

void loop() {
  String quote = "                One Dream, Tomorrow by Together!                ";

  for (int i = 0; i <= quote.length() - 16; i++) {
    lcd.setCursor(0, 1);

    String tampil = quote.substring(i, i + 16);
    lcd.print(tampil);

    delay(50);
  }
}