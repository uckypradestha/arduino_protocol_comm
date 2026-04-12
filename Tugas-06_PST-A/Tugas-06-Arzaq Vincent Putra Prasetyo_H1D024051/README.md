
### **Penjelasan Sederhana Kode LCD Scroll**

#### **1. Persiapan (Setup)**
* **`Adafruit_LiquidCrystal lcd(0)`**: Mengenalkan LCD ke program.
* **`daftarQuote[]`**: Daftar kalimat yang ingin ditampilkan. Kamu bisa menambah teks baru di sini.
* **`quoteIndex`**: Seperti "nomor antrean" untuk menentukan kalimat mana yang harus muncul duluan.

---

#### **2. Cara Kerja Judul (Baris Atas)**
* Program menghitung panjang kata (misal: "QUOTE").
* Kata tersebut diletakkan di tengah agar terlihat rapi (statis/tidak bergerak).

---

#### **3. Cara Kerja Teks Berjalan (Baris Bawah)**
Agar teks bisa bergerak mulus dari kanan ke kiri, program melakukan trik ini:
1. **Tambah Spasi**: Teks asli ditambah 16 spasi di depan dan di belakangnya. Ini gunanya supaya teks tidak langsung muncul tiba-tiba, tapi pelan-pelan masuk ke layar.
2. **Sistem "Intip" (Substring)**: LCD hanya bisa menampilkan 16 karakter. Program akan mengambil 16 karakter dari pesan, lalu digeser satu huruf demi satu huruf secara terus-menerus.
3. **Tanpa Kedip**: Karena program selalu mengirim 16 karakter (termasuk spasi), layar tidak perlu dihapus-hapus (`clear`), sehingga tulisan tidak bergetar atau berkedip.

---

#### **4. Alur Perulangan (Loop)**
1. Tampilkan Judul.
2. Jalankan teks berjalan sampai selesai.
3. Ganti ke kalimat berikutnya dalam daftar (`quoteIndex++`).
4. Jika sudah sampai kalimat terakhir, balik lagi ke kalimat pertama.

---

### **Istilah Penting**
* **`SPEED_TEKS`**: Angka untuk mengatur kecepatan. Kecil = Cepat, Besar = Lambat.
* **`substring`**: Memotong bagian tertentu dari sebuah kalimat.
* **`lcd.setCursor(kolom, baris)`**: Menentukan di mana tulisan akan mulai diketik (Baris 0 = Atas, Baris 1 = Bawah).
