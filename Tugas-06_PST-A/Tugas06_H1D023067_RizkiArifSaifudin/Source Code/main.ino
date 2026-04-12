#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C layar(0x20, 16, 2);


String pesan = "                to be all in, you need to B ALL IN.                ";

int giliranPrint = 0;

void setup() {
  layar.init();
  layar.backlight();

  
  String header = "QUOTE";
  int tengah = (16 - header.length()) / 2;
  layar.setCursor(tengah, 0);
  layar.print(header);
}

void loop() {

  tampilkanRunningText();

  giliranPrint++;

  
  if (giliranPrint > pesan.length() - 16) {
    giliranPrint = 0;
  }

  delay(250);
}


void tampilkanRunningText() {
  
  layar.setCursor(0, 1);

  
  for (int i = 0; i < 16; i++) {
    int posisiChar = giliranPrint + i;

    if (posisiChar < pesan.length()) {
      layar.print(pesan[posisiChar]);
    } else {
      layar.print(" ");
    }
  }
}