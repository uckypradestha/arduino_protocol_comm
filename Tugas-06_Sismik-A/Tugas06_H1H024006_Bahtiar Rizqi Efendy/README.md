# 📟 LCD Scrolling Quote — Arduino I2C

✨ Menampilkan **judul statis di tengah** dan **teks berjalan (scrolling)** menggunakan LCD 16x2 berbasis I2C dengan Arduino.

---

Fitur utama:

* Judul **"QUOTE"** tampil di tengah (baris 1)
* Teks berjalan JANGAN LUPA MAKAN dari kanan ke kiri (baris 2)
* Efek scroll halus
* Loop otomatis

---

## ALAT DAN BAHAN

* 🔌 Arduino UNO
* 📟 LCD 16x2 I2C
* 📚 Library:

  * `Wire.h`
  * `LiquidCrystal_I2C`

---

## Wiring

| LCD I2C | Arduino UNO |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

---

## PENJELASAN

### Static Title (Centered)

```cpp
printCentered(0, "QUOTE");
```

* Menghitung posisi tengah otomatis
* Ditampilkan hanya sekali di `setup()`

---

### Scrolling Text

```cpp
String scrollText = "                " + quoteText + "                ";
```

* Menambahkan padding spasi
* Membuat efek teks muncul dari kanan

```cpp
lcd.print(scrollText.substring(i, i + 16));
```

* Mengambil 16 karakter untuk ditampilkan
* Menggeser teks setiap iterasi

---

### Scroll Speed Control

```cpp
delay(250);
```

* Mengatur kecepatan animasi
* Lebih kecil = lebih cepat

---


## Troubleshooting

💡 LCD tidak tampil?

Coba ubah alamat I2C:

```cpp
LiquidCrystal_I2C lcd(0x3F, 16, 2);
```

---


