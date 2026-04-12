<h1>Komunikasi Serial</h1>

Komunikasi serial merupakan salah satu cara paling umum yang digunakan untuk bertukar data antar perangkat mikrokontroler, seperti Arduino. Melalui komunikasi serial, dua atau lebih perangkat dapat saling mengirim dan menerima informasi menggunakan jalur data tunggal, sehingga sistem dapat bekerja secara sinkron dan efisien. Salah satu komunikasi serial yang menjadi pembahasan pada bagian ini adalah Universal Asynchronous Receiver-Transmitter (UART).

<h2>Universal Asynchronous Receiver-Transmitter (UART)</h2>

Universal Asynchronous Receiver-Transmitter (UART) adalah jenis protokol komunikasi yang memungkinkan pengiriman data dari Arduino ke perangkat lainnya melalui metode klasik yaitu `Serial.print()`. UART memungkinkan komunikasi serial asynchronous, di mana format data dan kecepatan transmisinya dapat diatur. UART merupakan salah satu protokol serial paling awal, dan meskipun di banyak kasus telah digantikan oleh SPI dan I2C, UART masih banyak digunakan untuk aplikasi dengan kecepatan dan throughput rendah karena sangat sederhana, murah, dan mudah diimplementasikan.

<div align="center">
  <img width="890" height="501" alt="parallelSerial" src="https://github.com/user-attachments/assets/e44c4baa-b56c-438b-adeb-5f6dc8cf9544" />
</div>

UART beroperasi dengan mengirimkan data sebagai serangkaian bit, termasuk start bit, data bit, bit paritas (opsional), dan stop bit. Berbeda dengan komunikasi paralel, di mana beberapa bit dikirimkan secara bersamaan, UART mengirimkan data secara serial, yaitu satu bit pada satu waktu. Seperti namanya, protokol ini bekerja secara asinkron, yang berarti tidak bergantung pada sinyal clock bersama. Sebagai gantinya, UART menggunakan baud rate yang telah ditentukan untuk mengatur timing setiap bit data.

<h2>Serial Class</h2>

Dengan Serial class, kita dapat mengirim dan menerima data ke dan dari komputer melalui USB, atau ke perangkat lain yang terhubung melalui pin RX/TX pada Arduino.
- Saat mengirim data melalui USB, kita menggunakan `Serial`. Data ini dapat dilihat pada Serial Monitor di Arduino IDE.
- Saat mengirim data melalui pin RX/TX, kita menggunakan `Serial1`.
- Board seperti GIGA R1 WiFi, Mega 2560, dan Due juga memiliki `Serial2` dan `Serial3`.

Serial class memiliki beberapa metode, dengan beberapa yang paling penting adalah:
- `begin()` – memulai komunikasi serial dengan baud rate tertentu (banyak contoh menggunakan 9600 atau 115200).
- `print()` – menampilkan data ke Serial Monitor.
- `println()` – menampilkan data ke Serial Monitor dan menambahkan baris baru.
- `available()` – mengecek apakah ada data serial yang tersedia (misalnya saat Anda mengirim perintah dari Serial Monitor).
- `read()` – membaca data dari port serial.
- `write()` – mengirim data ke port serial.

<h2>Baud Rate</h2>

Baud rate adalah parameter dasar dalam komunikasi UART. Parameter ini menentukan kecepatan data yang ditransmisikan melalui jalur komunikasi. Baud rate dinyatakan dalam bit per detik (bps) dan menunjukkan jumlah bit yang dikirim dalam satu detik. Dalam UART, baik perangkat pengirim maupun penerima harus menggunakan baud rate yang sama agar komunikasi dapat berjalan dengan baik. Baud rate yang paling umum dipakai adalah `9600` bps, namun bisa ditingkatkan, misalnya menjadi `115200` bps, jika dibutuhkan pengiriman data yang lebih cepat. Fungsi ini harus ditempatkan pada bagian setup(), karena tanpa inisialisasi tersebut komunikasi serial tidak dapat berjalan.

Lebh lanjut berkaitan dengan Serial Komunikasi UART dapat dibuka di dokumentasi Arduino pada pembahasan [UART](https://docs.arduino.cc/learn/communication/uart/)

<h2>Implementasi Serial Komunikasi UART</h2>

Serial Komunikasi UART pada percobaan pendahuluan dengan menempatkan `Serial.print()` pada `void setup ()` sehingga Serial Monitor hanya sekali menampilkan tulisan "Hello World". Pada implementasi ini akan coba menampilkan tulisan "Hello World" di dalam `void loop ()` sehingga tulisan "Hello World" dapat dicetak berulang kali seperti halnya pada LED Blink.

```cpp
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  delay(1000);
}
```

Berikutnya compile dan upload program ke dalam Arduino board. Perhatikan hasil yang terjadi, apakah sesuai dengan spesifikasi atau tidak.

https://github.com/user-attachments/assets/1195236f-a6d0-48fb-92aa-dc3b59f97a95

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
