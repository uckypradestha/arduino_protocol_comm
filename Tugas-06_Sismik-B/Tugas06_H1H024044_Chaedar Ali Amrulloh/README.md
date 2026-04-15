# Laporan Proyek Scrolling Text LCD
## Akses Simulasi

Untuk mengakses simulasi dari proyek ini bisa dengan mengklik link [berikut](https://www.tinkercad.com/things/6pFFgSM7nr0-text-scrolling-display?sharecode=HVikBQR3IQpW7yaaa5nCcl7R57StvdlRyX7ipdsSwZw)

# Penjelasan Program
## Overview
```cpp
  // Menambahkan library Adafruit_LiquidCrystal
  #include <Adafruit_LiquidCrystal.h>

  // Memberi tahu memori mana yang akan dikontrol (default)
  Adafruit_LiquidCrystal lcd(0);

  //  VARIABLE
  char quote[] = "Jagoan neon bukan sembarang jagoan";  // Array untuk menyimpan quote
  int COL_POSITION = 15;                                // Menyimpan posisi kursor
  int DELAY = 500;                                      // Lama delay
  const int MAX_DISPLAY_DIGIT = 16;                     // Limit char yang dapat diprint
  
  void setup() {
    lcd.begin(16, 2);    // Menyalakan lcd dengan 16 kolom dan 2 baris
    lcd.setCursor(5, 0); // Memindahkan kursor ke kolom 5 baris 0
    lcd.print("QUOTES"); // Menampilkan/print QUOTES pada kursor
    delay(DELAY);        // Jeda selama DELAY
  }

  // Fungsi untuk pengulangan print array
  void printChars(char arr[], int i = 0) {
    for(int j=i; j < strlen(arr); j++) {

      // Stop print apabila j (indeks) lebih besar dari limit
      if(j < MAX_DISPLAY_DIGIT+i) lcd.print(arr[j]);
    }
    lcd.print(" ");  // Menghapus kata yang tertinggal saat bergerak kek kiri
  }
  
  void loop() {
    // Kondisi apabila quotes sudah mencapai kolom 0
    if(COL_POSITION < 1) {

      // Pengulangan untuk menampilkan quote dengan menimpa hasil print sebelumnya
      for(int i=0; i <= strlen(quote); i++) {
        lcd.setCursor(0, 1);    // Memindahkan kursor ke kiri bawah
        printChars(quote, i);   // Memanggil fungsi print array
        delay(DELAY);
      }
      COL_POSITION = 15;  // Set posisi kolom kembali semula
      delay(DELAY);
    }

    // Kondisi apabila quotes baru muncul dari kanan (kondisi awal)
    else {
      lcd.setCursor(COL_POSITION, 1);  // Memindahkan kursor ke pojok kanan bawah
      printChars(quote);
      delay(DELAY);
      COL_POSITION--;  // Decrement agar quotes bergerak ke kiri
    }
  }
```

## Library
```cpp
  #include <Adafruit_LiquidCrystal.h>
  Adafruit_LiquidCrystal lcd(0);
```

Baris yang berfungsi untuk menambahkan library LiquidCrystal buatan Adafruit sehingga kita tidak perlu repot membuat fungsi untuk memanipulasi LCD.

Baris kedua menginisialisasi lcd untuk membaca memori default yakni 0x20 agar bisa mengontrol LCD.

## Variabel
```cpp
  char quote[] = "Jagoan neon bukan sembarang jagoan";
  int COL_POSITION = 15;
  int DELAY = 500;
  const int MAX_DISPLAY_DIGIT = 16;
```

Terdapat 4 variabel utama dalam program ini yang melengkapi fungsi penting dalam menjalankan program dengan lancar.

>- quote[]  = Merupakan sebuah variabel array bertipe char untuk menampung quote yang akan ditampilkan dalam LCD display.
>- COL_POSITION  = Merupakan variabel yang menyimpan posisi kursor pada LCD. Diberi nilai 15 agar posisi awal kursor berada di pojok kanan bawah.
>- DELAY  = Variabel simpel yang menyimpan durasi delay untuk fungsi delay().
>- MAX_DISPLAY_DIGIT  = Merupakan variabel yang berfungsi untuk melimitasi banyak char yang diprint guna menjaga performa. Dibatasi sebanyak lebar display digit.

## Fungsi
```cpp
  void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(5, 0);
    lcd.print("QUOTES");
    delay(DELAY);
  }
```

Salah satu fungsi utama dalam pemrograman mikrokontroler dengan fungsi umum untuk setup mode pin. Untuk kali ini fungsi setup digunakan untuk menjalankan kode yang perlu dijalankan sekali saja. <hr>


```cpp
  void printChars(char arr[], int i = 0) {
    for(int j=i; j < strlen(arr); j++) {
      if(j < MAX_DISPLAY_DIGIT+i) lcd.print(arr[j]);
    }
    lcd.print(" ");
  }
```

Fungsi sederhana untuk menampilkan isi dari array char. Char yang ditampilkan dilimit sebanyak 16 char saja guna mengikis waktu dan memberikan delay yang konstan apabila quote yang diberikan terlalu panjang. <hr>

```cpp
  void loop() {
    if(COL_POSITION < 1) {
      for(int i=0; i <= strlen(quote); i++) {
        lcd.setCursor(0, 1);
        printChars(quote, i);
        delay(DELAY);
      }
      COL_POSITION = 15;
      delay(DELAY);
    } else {
      lcd.setCursor(COL_POSITION, 1);
      printChars(quote);
      delay(DELAY);
      COL_POSITION--;
    }
  }
```

Fungsi inti untuk melakukan pengulangan selama mikrokontroler menyala. Dalam fungsi ini terdapat dua state/kondisi dalam menampilkan quote pada LCD display, 

Kondisi pertama adalah teks dimulai dari kanan ke kiri lalu bergerak hingga mencapai kolom 0 pada LCD untuk melengkapi syarat kondisi kedua.

Kondisi kedua adalah apabila posisi kolom kurang dari 1, kursor berhenti bergerak dan teks mulai ditampilkan dengan melakukan increment pada indeks default array itu sendiri pada setiap pengulangan guna menciptakan ilusi bahwa teks bergerak ke kiri.
Jadi setiap pengulangan akan menambahkan default i sebanyak 1 (i=0 -> i=1 -> dst) hingga i lebih besar dari panjang array quote.
