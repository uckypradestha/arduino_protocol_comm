#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);

char quote[] = "Jagoan neon bukan sembarang jagoan";
int COL_POSITION = 15;
int DELAY = 500;
const int MAX_DISPLAY_DIGIT = 16;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("QUOTES");
  delay(DELAY);
}

void printChars(char arr[], int i = 0) {
  for(int j=i; j < strlen(arr); j++) {
    if(j < MAX_DISPLAY_DIGIT+i) lcd.print(arr[j]);
  }
  lcd.print(" ");
}

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
