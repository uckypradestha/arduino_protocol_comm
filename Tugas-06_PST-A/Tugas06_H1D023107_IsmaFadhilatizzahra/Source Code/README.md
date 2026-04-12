# Folder ini berisi penjelasan mengenai Source Code dan penjelasan detail tiap line nya

Berikut adalah penjelasan mendalam mengenai logika program yang digunakan dalam file `Sketch.ino`:

| Baris Kode | Penjelasan Fungsi |
| :--- | :--- |
| `#include <Adafruit_LiquidCrystal.h>` | Memasukkan library khusus untuk mengontrol LCD melalui protokol I2C di lingkungan Tinkercad. |
| `Adafruit_LiquidCrystal lcd(0);` | Menyiapkan objek LCD dengan alamat I2C 0 (default Tinkercad) agar bisa dikontrol oleh Arduino. |
| `String quote = "...";` | Menyimpan kalimat "Manusia boleh berencana, tetapi saldo yang menentukan" ke dalam variabel teks. |
| **`void setup() {`** | **Fungsi persiapan yang dijalankan satu kali saat Arduino pertama kali dinyalakan.** |
| `lcd.begin(16, 2);` | Memberitahu Arduino bahwa LCD yang digunakan memiliki ukuran 16 kolom dan 2 baris. |
| `lcd.setBacklight(1);` | Menyalakan lampu latar LCD agar tulisan terlihat jelas (seperti menyalakan lampu layar HP). |
| **`void loop() {`** | **Fungsi utama yang akan terus dijalankan berulang-ulang oleh Arduino.** |
| `lcd.setCursor(5, 0);` | Mengatur posisi kursor ke kolom 5 di baris atas (baris 0) agar teks berada di posisi tengah. |
| `lcd.print("QUOTE:");` | Menampilkan tulisan statis "QUOTE:" yang tidak akan ikut bergerak. |
| `for (int pos = 16; ...)` | Memulai perulangan untuk menggerakkan teks, dimulai dari kolom 16 (paling kanan luar). |
| `String displayStr = "";` | Membuat wadah string kosong untuk menyusun teks yang akan muncul di layar tiap detiknya. |
| `if (pos > 0) { ... }` | Jika teks belum mencapai pinggir kiri, tambahkan spasi kosong di depannya agar teks terlihat bergeser. |
| `else { ...substring(-pos) }` | Jika teks sudah mulai keluar ke kiri, potong huruf bagian depan agar transisi keluar layar terlihat mulus. |
| `while (displayStr.length() < 16)` | Memastikan panjang teks selalu 16 karakter agar tidak ada sisa huruf lama yang tertinggal di layar. |
| `lcd.setCursor(0, 1);` | Mengarahkan kursor ke baris bawah (baris 1) tempat teks quote akan berjalan. |
| `lcd.print(displayStr.substring(0, 16));` | Menampilkan 16 karakter hasil olahan ke layar LCD secara berkelanjutan. |
| `delay(200);` | Memberikan jeda 0,2 detik untuk mengatur kecepatan gerak teks agar nyaman dibaca. |

