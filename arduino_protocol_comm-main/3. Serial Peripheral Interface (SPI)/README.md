<h1>Serial Peripheral Interface (SPI)</h1>

SPI adalah singkatan dari Serial Peripheral Interface . SPI adalah protokol komunikasi serial yang digunakan untuk menghubungkan perangkat berkecepatan rendah. Ini dikembangkan oleh Motorola pada pertengahan 1980 untuk komunikasi antar-chip. Biasanya digunakan untuk komunikasi dengan memori flash, sensor, jam waktu nyata (RTC), konverter analog-ke-digital, dan banyak lagi. Ini adalah komunikasi serial sinkron dupleks penuh, yang berarti bahwa data dapat dikirim secara bersamaan dari kedua arah.

Keuntungan utama SPI adalah mentransfer data tanpa gangguan apa pun. Banyak bit yang dapat dikirim atau diterima sekaligus dalam protokol ini.

Dalam protokol ini, perangkat dikomunikasikan dalam hubungan master-slave. Perangkat master mengontrol perangkat budak, dan perangkat budak mengambil instruksi dari perangkat master. Konfigurasi paling sederhana dari Serial Peripheral Interface (SPI) adalah kombinasi dari satu slave dan satu master. Namun, satu perangkat master dapat mengontrol beberapa perangkat slave. Gambar menunjukkan antarmuka SPI.

<img width="938" height="306" alt="image" src="https://github.com/user-attachments/assets/cf3ace5a-c76a-47dc-bcdc-e040b275d76f" />

##

Berikut adalah poin-poin penting mengenai SPI Arduino:

- Arsitektur Master-Slave: Arduino umumnya bertindak sebagai Master yang mengendalikan Clock (SCK) dan memilih Slave menggunakan pin Slave Select (SS).
- Kecepatan Tinggi: SPI mendukung pertukaran data yang jauh lebih cepat dibandingkan protokol I2C, cocok untuk data besar.
- Full Duplex: Data dapat dikirim (Master in Slave In/MOSI) dan diterima (Master in Slave Out/MISO) secara bersamaan.
- Pin SPI pada Arduino (Uno/Nano):
  - MOSI (Master Out Slave In): Pin 11.
  - MISO (Master In Slave Out): Pin 12.
- SCK (Serial Clock): Pin 13.
- SS/CS (Slave Select/Chip Select): Pin 10 (atau pin digital lainnya).
- Penggunaan Library: Komunikasi SPI di Arduino menggunakan library #include <SPI.h> untuk mengatur kecepatan, mode, dan urutan data

SPI (Serial Peripheral Interface) merupakan protokol komunikasi master-slave yang menggunakan empat jalur (line). Dalam SPI, hanya terdapat satu master, tetapi dapat memiliki banyak slave. Master biasanya berupa mikrokontroler, sedangkan slave dapat berupa mikrokontroler lain, sensor, ADC, DAC, LCD, dan sebagainya. Diagram komunikasi SPI pada Arduino menunjukkan arsitektur master-slave yang menggunakan empat sinyal utama. Memahami konfigurasi pin SPI pada Arduino ini sangat penting untuk implementasi yang berhasil.

Di bawah ini adalah representasi diagram blok dari SPI dengan satu master dan beberapa slave. Konfigurasi dasar komunikasi SPI Arduino ke Arduino melibatkan satu master yang mengendalikan satu perangkat slave.

<div align="center">
  <img width="650" height="321" alt="image" src="https://github.com/user-attachments/assets/c02ad9c4-c872-494a-915f-a2f5b8f8ad04" />
</div>

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
