float temp;
//vout voltage output of temp sensor
//voutput new voltage with temp increase
//serial begin given to activate serial monitor
float vout;
float voutput;
int LED=13;
int gasSensor;
int piezo=7;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  vout=analogRead(A0);
  voutput=(vout/1023)*5000;
  temp=(voutput-500)/10;
  gasSensor=analogRead(A1);
  if (temp>=80)
  {
    digitalWrite(LED,HIGH);} 
  else
  {
    digitalWrite(LED,LOW);}
  if (gasSensor>=100)
  {
    digitalWrite(piezo,HIGH);}
  else
  {
    digitalWrite(piezo,LOW);}

  Serial.print("Temp in degree C:	"); 
  Serial.print(temp);
  Serial.print("\t\t");
  Serial.print("Gas sensor:	");
  Serial.print(gasSensor);

  Serial.print("\n ");
  delay(1000);
}