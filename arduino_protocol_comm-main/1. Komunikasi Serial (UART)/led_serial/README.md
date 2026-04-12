<h1>LED Blink dengan Serial Monitor</h1>

Serial monitor dalam Arduino IDE adalah fitur bawaan berbentuk jendela pop-up yang memfasilitasi komunikasi dua arah antara papan Arduino dan komputer. Alat ini memungkinkan pengguna mengirim data dari Arduino ke PC (misalnya hasil sensor) dan mengirim perintah dari PC ke Arduino (misalnya tombol kontrol) secara real-time melalui kabel USB.

<img width="1920" height="991" alt="serial_uart _ Arduino IDE 2 3 8 05_04_2026 19_53_53" src="https://github.com/user-attachments/assets/550a9abd-dac1-40b9-adee-df0689b55969" />

<h3>Alat dan Bahan</h3>
<p>Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:</p>

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr>
    <th>Arduino</th>
    <th>LED</th>
    <th>Resistor</th>
    <th>Bradboard</th>
    <th>Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="333" height="236" alt="arduino_uno" src="https://github.com/user-attachments/assets/b5b0c26f-9547-421f-81d7-797fc487e10c" /><br>
    </td>
    <td>
      <img width="108" height="268" alt="RedLED_Fritzing" src="https://github.com/user-attachments/assets/a1726590-6b0c-49b8-ab84-96ff8e243ae2" /><br>
    </td>
    <td>
      <img width="224" height="65" alt="Resistor220_Fritzing" src="https://github.com/user-attachments/assets/b925fae3-2191-4f7e-96b1-796ea142c62f" /><br>
    </td>
    <td>
      <img width="500" height="326" alt="breadboard" src="https://github.com/user-attachments/assets/0d1b7929-81f3-4bb2-a0de-757ef79bc916" /><br>
    </td>
    <td>
      <img width="229" height="344,5" alt="pngwing com" src="https://github.com/user-attachments/assets/0acc9c70-b288-4152-864e-e7bc8372ad91" /><br>
    </td>
  </tr>

  <tr align="center">
    <td>Arduino Uno, Leonardo, atau lainnya</td>
    <td>Red LED</td>
    <td>220Ω Resistor atau lainnya</td>
    <td>Breadboard Mini</td>
    <td>Kabel Jumper</td>
  </tr>
</table>
</div>

<h2>Implementasi Menggunakan Tinkercad</h2>

Berikut adalah penerapan LED Blink dengan Serial Monitor dengan menggunakan Tinkercad. Setelah di compile dan di upload serial monitor akan menampilkan "Hello World" setiap LED menyala.

LED Blink dengan Serial Monitor untuk source code dapat diakses melalui [LED_SERIAL](https://github.com/uckypradestha/arduino_protocol_comm/blob/59e754559cb41431d42d24dddd3ce2a3320c212d/1.%20Komunikasi%20Serial%20(UART)/led_serial/serial_uart.ino)

https://github.com/user-attachments/assets/18792670-12ba-41f7-9803-f5fed2185dd4

<h2>Menyalakan dan Menghidupkan LED Melalui Serial Monitor</h2>

Selain menampilkan status LED dengan `Serial.print()`, Serial Monitor juga dapat digunakan sebagai "tombol" digital untuk menyalakan LED. Dengan latihan ini, mahasiswa diharapkan mampu mengirimkan perintah sederhana dari Serial Monitor untuk menyalakan dan mematikan LED, serta memahami bagaimana Arduino membaca dan merespons data yang diterima secara real-time.

<h3>Spesifikasi Sistem</h3>

Sistem harus memenuhi spesifikasi berikut:
- Menginisialisasi komunikasi serial dengan baud rate 9600
- Menerima input 1 karakter dari Serial Monitor
- Menyalakan LED jika menerima perintah '1'
- Mematikan LED jika menerima perintah '0'
- Menampilkan status LED (“LED ON” / “LED OFF”) pada Serial Monitor
- Menampilkan pesan error jika perintah tidak dikenali
- Mengabaikan karakter newline (\n) dan carriage return (\r)
- Implementasikan melalui Tinkercad

https://github.com/user-attachments/assets/6fc8db8b-fb54-4f20-b2e8-d7c47bca6ac0

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
