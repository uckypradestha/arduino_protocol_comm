# Tugas 06 - Scrolling Text Dengan I2C

**Nama:** Khaila Salsa  
**NIM:** H1D023030  
**Kelas:** PST-A  

## Penjelasan Kode Program

**1. Penggunaan Librari**
Program ini menggunakan librari `<Adafruit_LiquidCrystal.h>` untuk mengontrol modul LCD 16x2 yang terhubung melalui antarmuka komunikasi I2C. Librari ini sangat memudahkan proses pengiriman data dan instruksi ke layar tanpa perlu mengatur pin data secara manual satu per satu.

**2. Inisialisasi**
- Pada fungsi `setup()`, layar LCD diinisialisasi menggunakan `lcd.begin(16, 2);` untuk mendefinisikan ukuran layar (16 kolom, 2 baris).
- `lcd.setBacklight(HIGH);` dipanggil untuk menyalakan lampu latar (*backlight*) agar tulisan pada LCD terlihat jelas.
- Sesuai spesifikasi tugas, untuk mencetak teks statis "QUOTE" tepat di tengah baris pertama, posisi kursor diatur menggunakan `lcd.setCursor(5, 0);` sebelum fungsi `lcd.print()` dijalankan.

**3. Looping (Logika Scrolling Text)**
- Pada fungsi `loop()`, baris kedua selalu ditimpa dengan karakter spasi kosong `lcd.print("                ");` di awal siklus untuk mencegah teks yang bertumpuk.
- Efek teks berjalan (*scrolling text*) dibuat menggunakan variabel `scrollCursor` yang diinisialisasi dengan nilai `15` (koordinat paling kanan pada LCD). 
- Fungsi `substring()` digunakan untuk memotong string kalimat secara dinamis berdasarkan posisi `scrollCursor`.
- Di setiap perulangan, nilai `scrollCursor` dikurangi (`scrollCursor--`) sehingga teks bergeser perlahan ke arah kiri.
- Terdapat kondisi logika `if` dimana apabila teks sudah sepenuhnya melewati batas kiri layar, nilai `scrollCursor` akan dikembalikan ke nilai `15` sehingga teks kembali muncul dari arah kanan layar. 
- Kecepatan animasi *scrolling* diatur menggunakan `delay(300);`.