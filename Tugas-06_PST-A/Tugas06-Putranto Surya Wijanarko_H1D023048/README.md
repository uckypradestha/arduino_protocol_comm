
# Scrolling Text

## Identitas
Nama : Putranto Surya Wijanarko

NIM : H1D023048

## Peralatan dan Bahan
- Arduino UNO
- PCF8574-based, 39 (0x27) LCD 16 x 2 (I2C)
- Jumper

## Penjelasan
* Baris pertama (row 0): menampilkan teks "QUOTE" secara statis dan berada di tengah layar
* Baris kedua (row 1): menampilkan isi quote yang bergerak (scrolling) dari kanan ke kiri

---

### Cara Kerja

LCD 16x2 memiliki 16 kolom (0–15), sehingga teks yang lebih panjang dari 16 karakter tidak dapat ditampilkan sekaligus. Untuk mengatasi hal ini, digunakan teknik scrolling manual.

### Konsep Scrolling

Scrolling dilakukan dengan cara menampilkan sebagian teks sepanjang 16 karakter yang berubah setiap waktu menggunakan substring.

Setiap frame menampilkan potongan teks yang bergeser satu karakter ke kiri, sehingga menghasilkan efek pergerakan.

---

### Efek Muncul dari Kanan

Agar teks terlihat muncul dari sisi kanan, ditambahkan spasi di awal dan akhir teks:

```
"                Dihina-hina saya tetap sigma                "
```

Fungsi spasi:

* Spasi di depan membuat teks muncul dari kanan
* Spasi di belakang membuat teks keluar secara halus ke kiri


## Dokumentasi
### Schematics
![](Dokumentasi\Schematics.png)  
### Quotes Display
![](Dokumentasi\Screenshot.png)
### Live
![](Dokumentasi\Live.gif)
[Tinkercad](https://www.tinkercad.com/things/lFkO6aOw7Gd-serial-comm)
