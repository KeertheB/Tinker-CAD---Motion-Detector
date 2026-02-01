// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(1);
}

void loop()
{
  if(digitalRead(7)==HIGH){
    digitalWrite(12, HIGH);
    delay(50);
  }
  
  else
  {
    digitalWrite(12, LOW);
    delay(50);
  }
}