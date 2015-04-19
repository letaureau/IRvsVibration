int analogInPin0 = A0;
int analogInPin1 = A1;
int analogInPin2 = A2;
int analogInPin3 = A3;
int analogInPin4 = A4;
int analogInPin5 = A5;
int analogInPin6 = A6;
int analogInPin7 = A7;

int analogOutPin0 = 2;
int analogOutPin1 = 4;
int analogOutPin2 = 6;
int analogOutPin3 = 8;
int analogOutPin4 = 10;
int analogOutPin5 = 12;
int analogOutPin6 = 14;
int analogOutPin7 = 16;

int analogEnPin0 = 3;
int analogEnPin1 = 5;
int analogEnPin2 = 7;
int analogEnPin3 = 9;
int analogEnPin4 = 11;
int analogEnPin5 = 13;
int analogEnPin6 = 15;
int analogEnPin7 = 17;

int sensorValue0 = 0;           
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;          
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;          
int sensorValue7 = 0;

int outputValue0 = 0;          
int outputValue1 = 0;          
int outputValue2 = 0;          
int outputValue3 = 0;          
int outputValue4 = 0;          
int outputValue5 = 0;          
int outputValue6 = 0;          
int outputValue7 = 0;          

void setup()
{
  Serial.begin(9600);
  // set digital i/o pins as outputs:   
  pinMode(analogOutPin0, OUTPUT);   
  pinMode(analogOutPin1, OUTPUT);   
  pinMode(analogOutPin2, OUTPUT);   
  pinMode(analogOutPin3, OUTPUT);   
  pinMode(analogOutPin4, OUTPUT);   
  pinMode(analogOutPin5, OUTPUT);   
  pinMode(analogOutPin6, OUTPUT);   
  pinMode(analogOutPin7, OUTPUT);   

  pinMode(analogEnPin0, OUTPUT); 
  pinMode(analogEnPin1, OUTPUT); 
  pinMode(analogEnPin2, OUTPUT); 
  pinMode(analogEnPin3, OUTPUT); 
  pinMode(analogEnPin4, OUTPUT); 
  pinMode(analogEnPin5, OUTPUT); 
  pinMode(analogEnPin6, OUTPUT); 
  pinMode(analogEnPin7, OUTPUT); 
}

void loop()
{
  float volts0 = analogRead(analogInPin0)*0.00273;  //    value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue0= analogRead(analogInPin0);
  float distance0 = 65*pow(volts0, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk
 
  float volts1 = analogRead(analogInPin1)*0.00273;      //value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue1 = analogRead(analogInPin1);
  float distance1 = 65*pow(volts1, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk
 
  float volts2 = analogRead(analogInPin2)*0.000273;     // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue2 = analogRead(analogInPin2);
  float distance2 = 65*pow(volts2, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  float volts3 = analogRead(analogInPin3)*0.00273;    //  value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue3= analogRead(analogInPin3);
  float distance3 = 65*pow(volts3, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  float volts4 = analogRead(analogInPin4)*0.00273;      //value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue4= analogRead(analogInPin4);
  float distance4 = 65*pow(volts4, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  float volts5 = analogRead(analogInPin5)*0.00273;     // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue5= analogRead(analogInPin5);
  float distance5 = 65*pow(volts5, -1.10);          //   worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  float volts6 = analogRead(analogInPin6)*0.00273;   //   value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue6= analogRead(analogInPin6);
  float distance6 = 65*pow(volts6, -1.10);         //    worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  float volts7 = analogRead(analogInPin7)*0.00273;  //    value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  sensorValue7= analogRead(analogInPin7);
  float distance7 = 65*pow(volts7, -1.10);          //   worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

  if(distance0<30)
  {
   digitalWrite(analogEnPin0, LOW);   
  }
  if(distance0>150)
  {
   digitalWrite(analogEnPin0,HIGH);
   analogWrite(analogOutPin0,255);
  }
  if(distance0>30 && distance0<150)
  {  
    outputValue0 = map(distance0, 30, 150, 255, 0);
    analogWrite(analogOutPin0,outputValue0);
  }  
  if(distance1<30)
  {
   digitalWrite(analogEnPin1, LOW);   
  }
  if(distance1>150)
  {
   digitalWrite(analogEnPin1,HIGH);
   analogWrite(analogOutPin1,255);
  }
  if(distance1>30 && distance1<150)
  {  
    outputValue1 = map(distance1, 30, 150, 255, 0);
    analogWrite(analogOutPin1,outputValue1);
  }
  if(distance2<30)
  {
   digitalWrite(analogEnPin2, LOW);   
  }
  if(distance2>150)
  {
   digitalWrite(analogEnPin2,HIGH);
   analogWrite(analogOutPin2,255);
  }
  if(distance2>30 && distance2<150)
  {  
    outputValue2 = map(distance2, 30, 150, 255, 0);
    analogWrite(analogOutPin2,outputValue2);
  }  
  if(distance3<30)
  {
   digitalWrite(analogEnPin3, LOW);   
  }
  if(distance3>150)
  {
   digitalWrite(analogEnPin3,HIGH);
   analogWrite(analogOutPin3,255);
  }
  if(distance3>30 && distance3<150)
  {  
    outputValue3 = map(distance3, 30, 150, 255, 0);
    analogWrite(analogOutPin3,outputValue3);
  }
  if(distance4<30)
  {
   digitalWrite(analogEnPin4, LOW);   
  }
  if(distance4>150)
  {
   digitalWrite(analogEnPin4,HIGH);
   analogWrite(analogOutPin4,255);
  }
  if(distance4>30 && distance4<150)
  {  
    outputValue4 = map(distance4, 30, 150, 255, 0);
    analogWrite(analogOutPin4,outputValue4);
  }  
  if(distance5<30)
  {
   digitalWrite(analogEnPin5, LOW);   
  }
  if(distance5>150)
  {
   digitalWrite(analogEnPin5,HIGH);
   analogWrite(analogOutPin5,255);
  }
  if(distance5>30 && distance5<150)
  {  
    outputValue5 = map(distance5, 30, 150, 255, 0);
    analogWrite(analogOutPin5,outputValue5);
  }
  if(distance6<30)
  {
   digitalWrite(analogEnPin6, LOW);   
  }
  if(distance6>150)
  {
   digitalWrite(analogEnPin6,HIGH);
   analogWrite(analogOutPin6,255);
  }
  if(distance6>30 && distance6<150)
  {  
    outputValue6 = map(distance6, 30, 150, 255, 0);
    analogWrite(analogOutPin6,outputValue6);
  }  
  if(distance7<30)
  {
   digitalWrite(analogEnPin7, LOW);   
  }
  if(distance7>150)
  {
   digitalWrite(analogEnPin7,HIGH);
   analogWrite(analogOutPin7,255);
  }
  if(distance7>30 && distance7<150)
  {  
    outputValue7 = map(distance7, 30, 150, 255, 0);
    analogWrite(analogOutPin7,outputValue7);
  }
  Serial.print("      ");
  Serial.print(outputValue0);
  Serial.print("      ");
  Serial.print(outputValue1);
  Serial.print("      ");
  Serial.print(outputValue2);
  Serial.print("      ");
  Serial.print(outputValue3);
  Serial.print("      ");
  Serial.println();
  Serial.print(outputValue4);
  Serial.print("      ");
  Serial.print(outputValue5);
  Serial.print("      ");
  Serial.print(outputValue6);
  Serial.print("      ");
  Serial.print(outputValue7);
  Serial.print("      ");
  delay(1000);
}
