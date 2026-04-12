const int ledPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  Serial.println("Hello World");
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
