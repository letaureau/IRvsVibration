int analogOutPin0 = 2;
void setup()
{
  // set digital i/o pins as outputs:   
  pinMode(analogOutPin0, OUTPUT);   
  Serial.begin(9600);
}

void loop()
{
 for(int i=0; i<=500;)
 {
  analogWrite(analogOutPin0,i);
  i=i+10;
  Serial.print(i);
  Serial.println();
 delay(1000);
 }
}
