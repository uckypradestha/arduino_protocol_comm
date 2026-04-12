<h3>I2C Liquid Crystal Displays</h3>

Display digunakan untuk menampilkan informasi dari sistem embedded. Display ini memiliki jenis yang cukup beragam. Beberapa di antaranya adalah sebagai berikut.
- LED (Light Emitting Diode)
- 7 Segment LED
- LCD (Liquid Crystal Display)
- OLED (Organic LED)
- TFT (Thin-Film Transistor)

LCD (Liquid Crystal Display) adalah jenis media tampilan dengan layar panel datar yang menggunakan kristal cair dalam pengoperasian utamanya. LCD ini sudah banyak digunakan di berbagai bidang hingga sekarang ini, seperti televisi, kalkulator, dan layar laptop atau komputer. LCD membutuhkan daya listrik yang rendah, memiliki bentuk yang tipis, mengeluarkan sedikit panas, dan memiliki resolusi yang tinggi. Kualitas tampilan layar LCD ditentukan oleh jumlah piksel. Semakin banyak jumlah piksel, maka akan semakin tinggi resolusi yang ditampilkan pada layar. Dalam sistem embedded, LCD dapat digunakan sebagai display sederhana yang dihubungkan langsung dengan board untuk mencetak data sensor, hitungan mundur sederhana, menampilkan scrolling text, dan masih banyak lagi.

![71iv4XG9uXL _AC_UF1000,1000_QL80_](https://github.com/user-attachments/assets/128075a8-994d-4caa-a5d1-41579c29ff35)

LCD pada dasarnya terdiri dari dua bagian utama, yaitu backlight (lampu latar belakang) dan liquid crystal (kristal cair). Meskipun demikian, ada beberapa jenis layar LCD yang tidak menggunakan lapisan backlight. LCD ini tidak dapat menghasilkan cahaya, melainkan hanya akan merefleksikan dan mentransmisikan cahaya yang melaluinya. Oleh karena itu, LCD membutuhkan backlight sebagai sumber cahayanya. Backlight akan memberikan pencahayaan pada kristal cair. Apabila ingin menghasilkan warna, maka kristal cair ini dibuka selebar-lebarnya sehingga cahaya dapat masuk. Sebaliknya, apabila ingin menampilkan warna hitam, maka kristal cair harus ditutup serapat-rapatnya supaya tidak ada cahaya yang menembus. Untuk menampilkan gambar atau tulisan pada layar LCD, kristal cair ini akan diatur sehingga cahaya yang nantinya tidak dapat mencapai layar akan membuat piksel berwarna sangat gelap yang membentuk tampilan gambar atau tulisan.

Berikut adalah contoh penerapan dengan menggunakan Tinkercad
```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);        // Inisialisasi LCD
  lcd.clear();       // Membersihkan tampilan LCD
  lcd.setBacklight(HIGH);   // Menghidupkan lampu latar (backlight)

  // Menampilkan pesan pada LCD
  lcd.setCursor(2, 0);  // Posisi kolom ke-2, baris ke-0
  lcd.print("Hello World!");

  lcd.setCursor(2, 1);  // Posisi kolom ke-2, baris ke-1
  lcd.print("Tutorial LCD");
}

void loop() {
  // Tidak ada perintah berulang
}
```

Berikutnya compile dan upload program ke dalam Arduino board. Perhatikan hasil yang terjadi, apakah sesuai dengan spesifikasi atau tidak.

https://github.com/user-attachments/assets/f093c6b6-7f0c-47d5-9ed7-c90b6afa22fa

<h2></h2>

<br>
<div align="center">
  <a href="https://github.com/uckypradestha"><img src="https://github.com/uckypradestha/assets/raw/main/social/logo-social-github.png" width="3%" alt="Ultralytics GitHub"></a>
  <img src="https://github.com/uckypradestha/assets/raw/main/social/logo-transparent.png" width="3%" alt="space">
  <a href="https://www.linkedin.com/uckypradestha/"><img src="https://github.com/uckypradestha/assets/raw/main/social/logo-social-linkedin.png" width="3%" alt="Ultralytics LinkedIn"></a>
  <img src="https://github.com/uckypradestha/assets/raw/main/social/logo-transparent.png" width="3%" alt="space">
  <a href="https://twitter.com/uckypradestha"><img src="https://github.com/uckypradestha/assets/raw/main/social/logo-social-twitter.png" width="3%" alt="Ultralytics Twitter"></a>
  <img src="https://github.com/uckypradestha/assets/raw/main/social/logo-transparent.png" width="3%" alt="space">
  <a href="https://www.youtube.com/@ckypradestha"><img src="https://github.com/uckypradestha/assets/raw/main/social/logo-social-youtube.png" width="3%" alt="Ultralytics YouTube"></a>
  <img src="https://github.com/uckypradestha/assets/raw/main/social/logo-transparent.png" width="3%" alt="space">
  <a href="https://www.tiktok.com/@pradestha"><img src="https://github.com/uckypradestha/assets/raw/main/social/logo-social-tiktok.png" width="3%" alt="Ultralytics TikTok"></a>
  <img src="https://github.com/uckypradestha/assets/raw/main/social/logo-transparent.png" width="3%" alt="space">
</div>
