# LCD Scrolling Quote (Arduino + I2C LCD)

## Deskripsi Program

Program ini dibuat untuk menampilkan **teks berjalan (scrolling text)** pada **LCD 16x2** menggunakan library **Adafruit LiquidCrystal**. Teks yang ditampilkan berupa sebuah kutipan (*quote*) yang bergerak dari **kanan ke kiri** pada baris kedua LCD.

Efek scrolling dimulai dari kondisi kosong, kemudian teks muncul secara bertahap dari sisi kanan layar hingga seluruh pesan selesai ditampilkan.

---

## Tujuan Program

Program ini bertujuan untuk:

1. Mengimplementasikan penggunaan **LCD 16x2** sebagai perangkat output.
2. Membuat efek **teks berjalan (scrolling text)** pada LCD.
3. Memahami konsep **display window** pada layar dengan jumlah karakter terbatas.
4. Menggunakan **library Adafruit LiquidCrystal** untuk mengontrol LCD.

---

## Perangkat yang Digunakan

### Hardware

* Arduino Uno (atau kompatibel)
* LCD 16x2 (I2C)
* Kabel jumper
* Breadboard (opsional)

### Software

* Arduino IDE
* Library **Adafruit LiquidCrystal**

---

## Library yang Digunakan

```cpp
#include <Adafruit_LiquidCrystal.h>
```

Library ini digunakan untuk:

* Menginisialisasi LCD
* Mengatur posisi kursor
* Menampilkan teks
* Mengontrol lampu latar (backlight)

---

## Inisialisasi LCD

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Baris ini membuat objek `lcd` untuk mengontrol LCD dengan alamat default **0**.

---

## Fungsi setup()

```cpp
void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}
```

### Penjelasan:

#### `lcd.begin(16, 2);`

Mengatur ukuran LCD:

* 16 kolom
* 2 baris

#### `lcd.setBacklight(HIGH);`

Mengaktifkan lampu latar LCD agar tampilan terlihat jelas.

#### `lcd.clear();`

Membersihkan layar sebelum digunakan.

#### `lcd.setCursor(5, 0);`

Mengatur posisi kursor pada:

* Kolom: 5
* Baris: 0 (baris pertama)

#### `lcd.print("QUOTE");`

Menampilkan teks **"QUOTE"** sebagai judul pada baris pertama LCD.

---

## Fungsi loop()

Bagian ini merupakan inti dari efek scrolling.

```cpp
void loop()
{
  String blank = "                "; 
  String quote = "andai saja kita mengerti, saat bertemu pertama kali ";
  String message = blank + quote;
```

### Penjelasan:

#### `blank`

Berisi **16 spasi kosong**.

Tujuannya:

Memberi efek bahwa teks muncul **dari luar layar sebelah kanan**.

Karena LCD hanya memiliki **16 kolom**, maka 16 spasi akan membuat tampilan awal kosong.

---

#### `quote`

Merupakan teks utama yang akan ditampilkan.

Contoh isi:

```text
andai saja kita mengerti, saat bertemu pertama kali
```

---

#### `message`

```cpp
String message = blank + quote;
```

Menggabungkan:

```text
[16 spasi] + [quote]
```

Tujuannya:

Menciptakan efek **teks masuk dari kanan layar**.

---

## Proses Scrolling Text

```cpp
for (int i = 1; i < message.length(); i++) { 
```

Loop ini berfungsi untuk:

Menggeser tampilan teks **satu karakter setiap iterasi**.

Nilai `i` menentukan:

Posisi awal karakter yang akan ditampilkan.

---

## Mengatur Posisi Kursor

```cpp
lcd.setCursor(0, 1);
```

Artinya:

Teks scrolling akan ditampilkan pada:

* Kolom: 0
* Baris: 1 (baris kedua)

---

## Menampilkan Substring

Bagian terpenting dalam efek scrolling:

```cpp
if (i < message.length() - 16) {
    lcd.print(message.substring(i, i + 16));
} else {
    lcd.print(message.substring(i));
}
```

---

# Cara Kerja Substring

LCD hanya bisa menampilkan:

```text
16 karakter sekaligus
```

Maka program mengambil **16 karakter** dari string `message`.

---

## Kondisi Pertama

```cpp
if (i < message.length() - 16)
```

Artinya:

Jika masih tersedia **minimal 16 karakter**, maka:

```cpp
message.substring(i, i + 16)
```

Ambil:

```text
16 karakter mulai dari posisi i
```

Contoh:

```text
message = "                HELLO WORLD"

i = 0 → "                "
i = 1 → "               H"
i = 2 → "              HE"
```

Ini menghasilkan efek:

```text
teks masuk dari kanan
```

---

## Kondisi Kedua (Else)

```cpp
else {
    lcd.print(message.substring(i));
}
```

Digunakan ketika:

Jumlah karakter tersisa **kurang dari 16**.

Tujuannya:

Menghindari error akibat mengambil karakter melebihi panjang string.

---

# Mekanisme Efek Scrolling

Secara visual:

```text
Awal:

[                ]

Kemudian:

[               a]
[              an]
[             and]
[            anda]
...
```

Setiap iterasi:

* teks bergeser ke kiri
* karakter baru muncul dari kanan

---

# Hal yang Perlu Ditambahkan (Rekomendasi)

Untuk efek lebih halus, biasanya ditambahkan:

```cpp
delay(200);
```

Setelah `lcd.print()`.

Tanpa delay:

Scrolling akan terlalu cepat.

Contoh:

```cpp
lcd.print(message.substring(i, i + 16));
delay(200);
```

---

# Konsep yang Digunakan

Program ini menerapkan beberapa konsep penting dalam sistem tertanam:

---

## 1. String Manipulation

Menggunakan:

```cpp
substring()
```

Untuk mengambil sebagian teks.

---

## 2. Display Window Concept

LCD bertindak sebagai:

```text
jendela 16 karakter
```

Yang bergerak sepanjang string.

---

## 3. Scrolling Text Mechanism

Efek scrolling dibuat dengan:

```text
menggeser indeks substring
```

Bukan menggeser teks secara fisik.

---

## 4. Output Device Control

LCD berfungsi sebagai:

```text
perangkat output
```

Yang menerima data dari mikrokontroler.

---

# Alur Kerja Program

Berikut alur kerja sistem:

```text
Start Program
       ↓
Inisialisasi LCD
       ↓
Tampilkan "QUOTE"
       ↓
Gabungkan blank + quote
       ↓
Loop substring
       ↓
Tampilkan 16 karakter
       ↓
Geser posisi teks
       ↓
Ulang sampai selesai
```

---

# Hasil yang Diharapkan

Program akan menampilkan:

```text
Baris 1:
     QUOTE

Baris 2:
teks berjalan dari kanan ke kiri
```

Contoh tampilan:

```text
     QUOTE
           a

     QUOTE
          an

     QUOTE
         and
```

Dan seterusnya hingga teks selesai.

---

# Potensi Pengembangan

Program ini dapat dikembangkan menjadi:

1. Running text dua arah
2. Multiple quotes
3. Teks berganti otomatis
4. Scroll dengan tombol
5. Scroll menggunakan interrupt
6. Menampilkan waktu atau sensor data

---

# Kesimpulan

Program ini berhasil mengimplementasikan efek **teks berjalan pada LCD 16x2** menggunakan teknik **substring scrolling**. Dengan memanfaatkan string kosong sebagai awalan dan pengambilan substring secara bertahap, sistem mampu menampilkan teks panjang pada layar dengan jumlah karakter terbatas. Program ini juga menunjukkan bagaimana manipulasi string dan kontrol posisi kursor dapat digunakan untuk menciptakan efek visual sederhana pada perangkat output dalam sistem tertanam.
