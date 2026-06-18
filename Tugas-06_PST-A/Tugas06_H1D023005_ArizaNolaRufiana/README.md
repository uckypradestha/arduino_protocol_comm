## Penjelasan Program

### 1. Library LCD
`#include <Adafruit_LiquidCrystal.h>`  
Bagian ini digunakan untuk memanggil library LCD I2C bawaan Tinkercad agar Arduino bisa mengontrol tampilan LCD.

---

### 2. Inisialisasi LCD
`Adafruit_LiquidCrystal lcd_1(0);`  
Kode ini digunakan untuk membuat objek LCD dengan nama `lcd_1`.  
Angka `0` menunjukkan alamat default I2C pada Tinkercad.

---

### 3. Variabel Quote
`String quote = "Ngopi Dulu Bro!";`  
Variabel ini berisi teks quote yang akan ditampilkan pada baris kedua LCD.

---

### 4. Variabel Posisi
`int posisi = 15;`  
Variabel `posisi` digunakan untuk menentukan letak awal tulisan pada LCD.  
Nilai `15` dipilih karena sesuai instruksi tugas yaitu teks muncul dari sisi kanan pada cursor `(15,1)`.

---

### 5. Variabel Index Huruf
`int indexHuruf = 0;`  
Variabel ini digunakan untuk mengatur jumlah huruf yang tampil secara bertahap.

---

### 6. Fungsi setup()
Pada bagian ini LCD diatur pertama kali saat program dijalankan.

`lcd_1.begin(16, 2);`  
Mengatur LCD dengan ukuran **16 kolom dan 2 baris**.

`lcd_1.setBacklight(1);`  
Menyalakan lampu backlight LCD agar tulisan terlihat.

`lcd_1.setCursor(5, 0);`  
Menentukan posisi cursor pada kolom ke-5 baris pertama supaya tulisan **QUOTE** berada di tengah.

`lcd_1.print("QUOTE");`  
Menampilkan tulisan **QUOTE** yang bersifat statis.

---

### 7. Fungsi loop()
Bagian ini akan dijalankan berulang-ulang.

`lcd_1.setCursor(0, 1);`  
Memindahkan cursor ke awal baris kedua.

`lcd_1.print("                ");`  
Menghapus isi baris kedua agar animasi tidak bertumpuk.

---

### 8. Menampilkan Huruf Bertahap
`String tampil = quote.substring(0, indexHuruf + 1);`  
Kode ini mengambil sebagian huruf dari quote, mulai dari huruf pertama sampai huruf sesuai nilai `indexHuruf`.  
Tujuannya agar tulisan muncul sedikit demi sedikit.

---

### 9. Menampilkan Teks Dinamis
`lcd_1.setCursor(posisi, 1);`  
Mengatur posisi tulisan di baris kedua sesuai nilai variabel `posisi`.

`lcd_1.print(tampil);`  
Menampilkan teks hasil substring ke LCD.

---

### 10. Delay
`delay(300);`  
Memberikan jeda 300 ms agar pergerakan teks terlihat jelas.

---

### 11. Geser ke Kiri
`posisi--;`  
Menggeser posisi tulisan satu langkah ke kiri setiap perulangan.

`indexHuruf++;`  
Menambah jumlah huruf yang ditampilkan.

---

### 12. Reset Animasi
`if (indexHuruf >= quote.length())`  
Mengecek apakah semua huruf sudah tampil.

`posisi = 15;`  
Mengembalikan posisi tulisan ke kanan lagi.

`indexHuruf = 0;`  
Mengulang tampilan huruf dari awal.