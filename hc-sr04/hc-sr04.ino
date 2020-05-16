const int trigger_pin = 7;
const int echo_pin = 8;
long travel_time, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  travel_time = pulseIn(echo_pin, HIGH);
  distance = 0.01715 * travel_time;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();

  delay(500);
}
