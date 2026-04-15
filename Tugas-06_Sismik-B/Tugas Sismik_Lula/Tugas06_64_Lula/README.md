# Tugas 6 - Sistem Mikroprosesor (Sismik) 🚀

Repositori ini berisi implementasi kode Arduino untuk menampilkan teks berjalan (*scrolling text*) pada LCD 16x2 menggunakan library **Adafruit LiquidCrystal**. Program ini menggunakan algoritma kustom `pingPongScroll` untuk menciptakan efek teks yang bergerak dari kanan ke kiri dan kembali lagi secara otomatis.

---

## 👤 Informasi Mahasiswa
- **Nama:** Lula
- **NIM:** H1H024064
- **Mata Kuliah:** Sistem Mikroprosesor (Sismik)

---

## 📝 Deskripsi Proyek
Proyek ini bertujuan untuk mendemonstrasikan kontrol output visual pada modul LCD. Fitur utama dari kode ini meliputi:

* **Efek Ping-Pong:** Teks tidak hanya berjalan searah, tetapi "memantul" kembali setelah mencapai ujung layar.
* **Modular Function:** Menggunakan fungsi `renderFrame` dan `hapusBaris1` agar kode lebih terstruktur, bersih, dan mudah dimodifikasi.
* **Custom Timing:** Pengaturan delay yang dioptimalkan untuk memastikan teks tetap nyaman dibaca selama pergerakan.

---

## 🛠️ Komponen & Library
### Hardware
* Arduino (Uno / Nano / Mega)
* Modul LCD 16x2 dengan I2C Adapter

### Software & Library
* **Arduino IDE**
* **Library:** [Adafruit LiquidCrystal](https://github.com/adafruit/Adafruit_LiquidCrystal)

---

## ⚙️ Konfigurasi Kode
Anda dapat menyesuaikan variabel berikut di dalam file `.ino` untuk mengubah perilaku tampilan:

| Variabel | Fungsi | Nilai Default |
| :--- | :--- | :--- |
| `quoteText` | Teks yang akan ditampilkan di baris ke-2 | `"Lulassssss, cintaa sismik"` |
| `SCROLL_DELAY` | Kecepatan pergerakan teks (milidetik) | `280` |
| `PAUSE_END` | Jeda saat teks mencapai batas akhir (milidetik) | `1200` |

---

## 💻 Cara Penggunaan
1.  **Persiapan:** Pastikan library **Adafruit LiquidCrystal** sudah terinstal melalui *Library Manager* di Arduino IDE.
2.  **Koneksi Hardware:** Hubungkan pin I2C LCD ke Arduino:
    * **GND** -> GND
    * **VCC** -> 5V
    * **SDA** -> A4 (Arduino Uno)
    * **SCL** -> A5 (Arduino Uno)
3.  **Upload:** Buka file `.ino`, pilih board yang sesuai, dan klik **Upload**.
4.  **Selesai:** Teks akan muncul di layar LCD dengan efek *ping-pong*.
