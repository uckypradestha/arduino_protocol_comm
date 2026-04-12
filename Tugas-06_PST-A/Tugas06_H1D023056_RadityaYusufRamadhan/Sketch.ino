#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Pesan aslinya
String pesanQuote = "Pendidikan adalah senjata paling mematikan di dunia.";

// Variabel untuk menyimpan pesan yang sudah dimodifikasi
String textBerjalan;

void setup()
{
    lcd.begin(16, 2);
    lcd.setBacklight(HIGH);
    lcd.clear();

    // Kalimat 1: "QUOTE" statis di tengah baris [0]
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");

    // TRIK RUNNING TEXT:
    // Kita tambahkan 16 spasi kosong di awal dan di akhir pesan.
    // Ini agar teks seolah-olah "masuk" dari ujung kanan layar
    // dan "keluar" perlahan ke ujung kiri layar sampai habis.
    textBerjalan = "                " + pesanQuote + "                ";
}

void loop()
{
    // Loop untuk menggeser "jendela" bacaan sepanjang teks
    // Berhenti ketika sisa teks kurang dari 16 karakter (ukuran LCD)
    for (int i = 0; i <= textBerjalan.length() - 16; i++)
    {

        lcd.setCursor(0, 1); // Kursor selalu stay di pojok kiri baris kedua

        // Mengambil potongan kalimat sebanyak 16 karakter,
        // lalu bergeser 1 huruf setiap perulangan
        lcd.print(textBerjalan.substring(i, i + 16));

        // Kecepatan pergerakan.
        // 150ms adalah kecepatan standar papan LED agar cepat tapi tetap bisa dibaca.
        // Ubah ke 100 jika ingin lebih ngebut, atau 200 jika terlalu cepat.
        delay(150);
    }
}