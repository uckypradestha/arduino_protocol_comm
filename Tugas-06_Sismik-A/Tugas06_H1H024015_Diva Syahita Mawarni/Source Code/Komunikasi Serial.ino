const int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("Hello World");
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}