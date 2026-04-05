void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Hello World");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}