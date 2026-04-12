<h1>Protokol Komunikasi Pada Mikrokontroler</h1>

![GITHUB BANNER](https://github.com/user-attachments/assets/1cf624dc-dc01-48fc-9ac3-7fa95902dde5)

Mikrokontroler seperti Arduino merupakan bagian penting dari berbagai proyek DIY, termasuk robotika. Pada pembahasan sebelumnya, kita telah melihat tata letak pin dan fungsi GPIO pada Arduino Uno. Pin GPIO dapat digunakan untuk membaca atau menulis data digital, yaitu tegangan tinggi atau rendah secara kontinu, atau bekerja dengan data analog berupa sinyal PWM yang bergantian antara tegangan tinggi dan rendah dalam rentang waktu yang sangat singkat. Kita juga telah melihat bahwa mikrokontroler dan single-board computer ini mendukung berbagai fungsi GPIO, termasuk protokol untuk berkomunikasi data dengan perangkat keras lainnya.

Protokol komunikasi adalah seperangkat aturan yang menentukan bagaimana data ditransfer antar perangkat elektronik. Protokol ini mengatur bagaimana bit dikemas, dikirim, dan diinterpretasikan. Dalam Arduino, protokol ini memungkinkan mikrokontroler untuk berkomunikasi dengan sensor, modul, Arduino lain, bahkan komputer.

Pada Arduino ada beberapa jenis protokol komunikasi yaitu Serial (UART), I2C, and SPI

<h3><a href="1. Komunikasi Serial (UART)">⛓️ Komunikasi Serial (UART)</a></h3>
Komunikasi serial melibatkan pengiriman data bit demi bit melalui pin yang ditentukan pada Arduino.

<h3><a href="2. Protokol Inter-Integrated Circuit (I2C)">📟 Inter-Integrated Circuit (I2C)</a></h3>
I2C merupakan protokol komunikasi yang memungkinkan beberapa perangkat terhubung dalam satu jaringan menggunakan dua jalur komunikasi yaitu Serial Clock (SCL) dan Serial Data (SDA).

<h3><a href="3. Serial Peripheral Interface (SPI)">🎛️ Serial Peripheral Interface (SPI)</a></h3>
Serial Peripheral Interface (SPI) merupakan protokol komunikasi yang digunakan untuk menghubungkan perangkat digital dengan kecepatan tinggi.

# Percobaan Pendahuluan

Menampilkan "Hello World" menggunakan Serial Monitor. Menampilkan "Hello World" di Serial Monitor Arduino dilakukan dengan menginisialisasi komunikasi serial menggunakan `Serial.begin(9600)` di `setup()` dan mencetak teks dengan `Serial.println("Hello World")` di `loop()` atau `setup()`.

```cpp
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

Berikutnya compile dan upload program ke dalam Arduino board. Perhatikan hasil yang terjadi, apakah sesuai dengan spesifikasi atau tidak.

https://github.com/user-attachments/assets/e9060247-f35a-4681-83f7-c23eae0d51bb

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
