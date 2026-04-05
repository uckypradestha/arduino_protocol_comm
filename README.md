# Protokol Komunikasi Pada Arduino

![GITHUB BANNER](https://github.com/user-attachments/assets/1cf624dc-dc01-48fc-9ac3-7fa95902dde5)

<p>Protokol komunikasi adalah seperangkat aturan yang menentukan bagaimana data ditransfer antar perangkat elektronik. Protokol ini mengatur bagaimana bit dikemas, dikirim, dan diinterpretasikan. Dalam Arduino, protokol ini memungkinkan mikrokontroler untuk berkomunikasi dengan sensor, modul, Arduino lain, bahkan komputer.</p>

<p>Pada Arduino ada beberapa jenis protokol komunikasi yaitu Serial (UART), I2C, and SPI</p>

<h3><a href="1. Komunikasi Serial (UART)">Komunikasi Serial (UART)</a></h3>
<p>Komunikasi serial melibatkan pengiriman data bit demi bit melalui pin yang ditentukan pada Arduino.</p>

<h3><a href="2. Protokol Inter-Integrated Circuit (I2C)">Inter-Integrated Circuit (I2C)</a></h3>
<p>I2C merupakan protokol komunikasi yang memungkinkan beberapa perangkat terhubung dalam satu jaringan menggunakan dua jalur komunikasi yaitu Serial Clock (SCL) dan Serial Data (SDA).</p>

<h3><a href="3. Serial Peripheral Interface (SPI)">Serial Peripheral Interface (SPI)</a></h3>
<p>Serial Peripheral Interface (SPI) merupakan protokol komunikasi yang digunakan untuk menghubungkan perangkat digital dengan kecepatan tinggi </p>

# Percobaan Pendahuluan

<p>Menampilkan "Hello World" menggunakan Serial Monitor. Menampilkan "Hello World" di Serial Monitor Arduino dilakukan dengan menginisialisasi komunikasi serial menggunakan Serial.begin(9600) di setup() dan mencetak teks dengan Serial.println("Hello World") di loop() atau setup()</p>

```cpp
const int ledPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

<h2></h2>

<a href="https://komputer.ft.unsoed.ac.id/">![Footer](https://github.com/user-attachments/assets/4db5037b-a9cc-44c6-a4cb-7618f3db244e)</a>
