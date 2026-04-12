<h1>Protokol Inter-Integrated Circuit (I2C)</h1>

Inter-Integrated Circuit atau I2C merupakan sebuah protokol komunikasi yang digunakan untuk pertukaran data antar perangkat mikrokontroler dan sensor atau pun perangkat lainnya. I2C dirancang untuk menghubungkan berbagai perangkat dalam sebuah sistem menggunakan jalur komunikasi bersama.

![lcd i2c ucky](https://github.com/user-attachments/assets/55bb3ac9-6474-4573-8281-723fe48dbf01)

<h2>Mengetahui Alamat I2C</h2>

Bayangkan protokol komunikasi I2C sebagai sebuah Bus Sekolah.

- Arduino adalah Supir Bus (Master).
- Sensor & Layar adalah Penumpang (Slave).

Hebatnya I2C, semua penumpang ini duduk di jalur kabel yang sama (hanya dua kabel: SDA dan SCL). Agar Pak Supir (Arduino) bisa berbicara ke penumpang tertentu tanpa yang lain ikut menyahut, setiap penumpang wajib memiliki Nomor Kursi yang unik.

Nah, Nomor Kursi itulah yang disebut I2C Address.

<h3>Mengapa ditulis 0x?</h3>

Format seperti 0x3C adalah penulisan bilangan Hexadesimal (bilangan basis 16).

0x hanyalah kode bagi komputer yang berarti: “Hei, angka di belakang ini adalah Hexadesimal.”

Meskipun Anda bisa menulisnya dalam bentuk desimal, standar internasional dalam pemrograman hardware selalu menggunakan format 0x ini.

<h3>Daftar Lengkap Alamat I2C</h3>

Berikut adalah daftar perangkat yang paling populer di kalangan maker, dikelompokkan berdasarkan fungsinya. Simpan tabel ini agar Anda tidak perlu bolak-balik mencari datasheet.

- Display (Layar Tampilan)

  Display adalah komponen yang paling sering membuat bingung karena satu jenis barang bisa memiliki alamat berbeda tergantung pabriknya.

  <img width="995" height="616" alt="Screenshot 2026-04-06 084154" src="https://github.com/user-attachments/assets/18df9272-14bc-4c1e-946e-3d4825c51732" />

- Sensor Lingkungan (Suhu, Cuaca, Cahaya)

  Kelompok sensor ini sering digunakan untuk proyek Stasiun Cuaca atau Smart Garden.

  <img width="994" height="691" alt="Screenshot 2026-04-06 084259" src="https://github.com/user-attachments/assets/6f59ed5d-8e18-433a-a7a3-eee842a00a41" />

- Motion & Time (Gerak & Waktu)

  Perhatian: Ini adalah zona rawan konflik! Banyak modul di kategori ini menggunakan alamat yang sama (0x68).

  <img width="996" height="616" alt="Screenshot 2026-04-06 084404" src="https://github.com/user-attachments/assets/d27ffe81-d8ad-4eae-8691-5a1e8577151d" />

- Kontrol Tambahan

  <img width="991" height="463" alt="Screenshot 2026-04-06 084439" src="https://github.com/user-attachments/assets/cc3811b6-3626-40b7-aa94-24f357574287" />

<h4>Memeriksa Alamat Display I2C</h4>

```cpp
#include <Arduino.h>
#include <Wire.h>   // Library untuk komunikasi I2C

void setup()
{
  Wire.begin();           // Inisialisasi komunikasi I2C sebagai master
  Serial.begin(9600);     // Inisialisasi komunikasi serial dengan baudrate 9600
}
  
void loop()
{
  byte error, address;    // Variabel untuk menyimpan status error dan alamat I2C
  int nDevices;           // Variabel untuk menghitung jumlah device yang terdeteksi

  Serial.println("Scanning...");  // Menampilkan pesan scanning ke serial monitor
  nDevices = 0;                  // Reset jumlah device

  // Loop untuk mengecek semua alamat I2C dari 1 sampai 126
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);  // Mulai komunikasi ke alamat tertentu
    error = Wire.endTransmission();   // Mengakhiri komunikasi dan cek apakah ada respon
  
    // Jika tidak ada error (device merespon)
    if (error == 0)
    {
      Serial.print("I2C terbaca pada alamat 0x");
      
      // Jika alamat < 16, tambahkan 0 di depan (format hex)
      if (address < 16)
        Serial.print("0");
      
      Serial.print(address, HEX); // Tampilkan alamat dalam format HEX
      Serial.println("  !");
  
      nDevices++; // Tambah jumlah device yang ditemukan
    }
    
    // Jika error = 4 (error tidak diketahui)
    else if (error == 4)
    {
      Serial.print("Ada error yang tidak diketahui pada alamat 0x");
      
      if (address < 16)
        Serial.print("0");
      
      Serial.println(address, HEX);
    }    
  }

  // Jika tidak ada device ditemukan
  if (nDevices == 0)
    Serial.println("Tidak ada satupun alamat I2C yang ditemukan\n");
  else
    Serial.println("selesai\n");  // Jika ada device, tampilkan selesai
  
  delay(5000); // Delay 5 detik sebelum scanning ulang
}
```

Berikut penerapannya melalui Tinkercad

https://github.com/user-attachments/assets/7efbadcc-b761-4d92-8c29-9699a539d226

Ada perbedaan jika diterapkan pada Wokwi

https://github.com/user-attachments/assets/9bdc8718-454d-48f3-b8a3-3c6fca5dcb8a

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
