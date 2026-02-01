// C++ code
//
int ultrasonicsensor = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  ultrasonicsensor = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(ultrasonicsensor);
  if (ultrasonicsensor < 100) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
  if (ultrasonicsensor < 100) {
    tone(10, 440 * pow(2.0, (constrain(int((50 + 20)), 35, 127) - 57) / 12.0), 100);
  } else {
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}