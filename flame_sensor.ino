int flameDigital = A0;   // DO pin
int flameAnalog = A3;    // AO pin

int pin5V_1 = 6;
int pin5V_2 = 5;
int pin5V_3 = 4;
int pinGND = 7;

void setup() {
  Serial.begin(9600);

  pinMode(flameDigital, INPUT);
  pinMode(flameAnalog, INPUT);

  pinMode(pin5V_1, OUTPUT);
  pinMode(pin5V_2, OUTPUT);
  pinMode(pin5V_3, OUTPUT);
  pinMode(pinGND, OUTPUT);

  digitalWrite(pin5V_1, HIGH);
  digitalWrite(pin5V_2, HIGH);
  digitalWrite(pin5V_3, HIGH);
  digitalWrite(pinGND, LOW);
}

void loop() {
  int digitalState = digitalRead(flameDigital);
  int rawValue = analogRead(flameAnalog);
  float voltage = (rawValue / 1023.0) * 5.0;

  Serial.print("Digital: ");
  Serial.print(digitalState);
  Serial.print(" | Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);

  delay(200);
}
