# Scrolling Text Dengan I2C

NAMA     : Gerard Roland Kusuma Sarwoko
NIM      : H1H024047
KELAS    : B
MATKUL   : Sistem Mikrokontroller

## Spesifikasi Sistem:
- Terdiri dari 2 Kalimat.
- Kalimat 1 (baris [0]) bertulisan QUOTE, sifatnya statis
- Kalimat 2 (baris [1]) bertulisan Quote nya yang sifatnya dinamis
- Tulisan QUOTE tepat di tengah tampilan LCD
- Tulisan Quote nya pada baris [1] langsung muncul dari sisi kanan (Cursor 15, 1)

---

## Komponen yang Digunakan:
- Arduino Uno R3
- LCD 16x2 (I2C) 
- Kabel jumper

## Wiring:
| Pin Arduino | Pin LCD I2C |
|---|---|
| 5V  | VCC |
| GND | GND |
| SDA | SDA |
| SCL | SCL |

---

## Kode Program:

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "                Kerja keras tidak akan mengkhianati hasil!                ";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  // Baris 0: "QUOTE" statis di tengah
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  for (int i = 0; i < text.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(i, i + 16));
    delay(200);
  }
}
```

---

## Penjelasan Kode:
- `lcd.setCursor(5, 0)` → Menempatkan teks **QUOTE** di tengah baris pertama (kolom 5)
- `text` diawali dengan 16 spasi agar teks muncul dari sisi kanan (Cursor 15, 1)
- Loop `for` menggeser teks sebanyak 16 karakter per iterasi dari kanan ke kiri
- `delay(200)` mengatur kecepatan scroll

---

## Hasil Simulasi:
Simulasi berhasil dijalankan di **Tinkercad** dengan tampilan:
- Baris [0]: `     QUOTE     ` (statis di tengah)
- Baris [1]: Teks scroll dari kanan → `Kerja keras tidak akan mengkhianati hasil!`

---

## Link Simulasi Tinkercad: https://www.tinkercad.com/things/esgbQkRxV65-h1h024047scrolling-text-roland?sharecode=mT16bDnxUdazvvIW44AUP-LSWbQ3tWiYiU6nOBBNJRI
