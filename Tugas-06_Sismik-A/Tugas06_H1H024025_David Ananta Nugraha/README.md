# 📟 LCD Scrolling Quote — Arduino I2C

Proyek sederhana menggunakan Arduino dengan layar LCD 16x2 berbasis I2C untuk menampilkan **judul statis** di baris pertama dan **teks berjalan (scrolling)** di baris kedua.
[🔗 Lihat Simulasi di Tinkercad](https://www.tinkercad.com/things/3sn6yBAJOOQ-scrolling-text-dengan-i2c?sharecode=uzcN6vQ6pvQ3N2iynMykDXUITcx4OUEPj9qrja8m4bA)

## Library yang Digunakan

Pastikan library berikut sudah terinstal di Arduino IDE:

- [`Wire.h`]
- [`LiquidCrystal_I2C`]

---

## Penjelasan Kode

### Inisialisasi LCD

```cpp
LiquidCrystal_I2C layar(0x27, 16, 2);
```

Membuat objek `layar` dengan alamat I2C `0x27`, lebar 16 kolom, dan tinggi 2 baris.

---

### Variabel Utama

```cpp
String judul = "QUOTE";
String teks = "Kesuksesan dimulai dari langkah kecil";
String teksPanjang = "                " + teks + "                ";
```

Variabel       Fungsi                                                                       

`judul`        Teks statis yang ditampilkan di baris pertama (tengah)                       
`teks`         Isi kutipan yang akan di-scroll                                              
`teksPanjang`  Teks dengan padding 16 spasi di kiri & kanan agar efek scroll terlihat mulus 

---

### Setup — `void setup()`

```cpp
layar.init();
layar.backlight();
layar.setCursor((16 - judul.length()) / 2, 0);
layar.print(judul);
```

- `layar.init()` — menginisialisasi LCD
- `layar.backlight()` — menyalakan lampu latar
- Posisi kursor dihitung otomatis agar judul tampil **di tengah baris pertama**
- `judul` hanya dicetak sekali di `setup()` karena tidak bergerak

---

### Loop — `void loop()`

```cpp
unsigned long waktuSekarang = millis();
if (waktuSekarang - waktuSebelum >= delayScroll) {
    waktuSebelum = waktuSekarang;
    layar.setCursor(0, 1);
    String potongan = teksPanjang.substring(posisi, posisi + 16);
    layar.print(potongan);
    posisi++;
    if (posisi > teksPanjang.length() - 16) {
        posisi = 0;
    }
}
```

- Menggunakan **non-blocking timer** (`millis()`) agar Arduino tetap responsif
- Setiap `delayScroll` milidetik (120 ms), posisi teks digeser 1 karakter ke kiri
- `substring(posisi, posisi + 16)` mengambil 16 karakter yang akan ditampilkan
- Ketika teks sudah habis tergeser, `posisi` direset ke `0` → teks **berulang terus**

---

### Konstanta Waktu Scroll

```cpp
const int delayScroll = 120;
```

Mengatur kecepatan scroll dalam milidetik. Nilai lebih kecil = scroll lebih cepat.


---
