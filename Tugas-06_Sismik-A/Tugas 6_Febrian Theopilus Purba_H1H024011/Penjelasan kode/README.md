Nama:Febrian Theopilus Purba<br>
NIM:H1H024011<br>
Kelas:A<br>

Kode ini menggunakan library Wire.h untuk komunikasi I2C <br>
Adafruit_LiquidCrystal.h untuk mengontrol LCD 16x2.<br>
Objek lcd(0) digunakan untuk menginisialisasi LCD dengan alamat I2C default.<br>
Variabel teks berisi kalimat yang akan ditampilkan sebagai running text, dengan tambahan spasi di depan agar teks muncul dari sisi kanan layar.<br>
Pada fungsi setup(), perintah lcd.begin(16,2) mengatur LCD menjadi 16 kolom dan 2 baris,<br>
lcd.setCursor(5,0) menempatkan tulisan "QUOTE" di tengah baris pertama.<br>
Pada fungsi loop(), perulangan for digunakan untuk menggeser teks satu karakter demi satu karakter. <br>
Perintah lcd.print(teks.substring(i, i+16)) menampilkan 16 karakter secara bergeser pada baris kedua sehingga menghasilkan efek running text dari kanan ke kiri. <br>
Nilai delay(50) mengatur kecepatan pergeseran teks agar tampil halus di LCD.<br>
