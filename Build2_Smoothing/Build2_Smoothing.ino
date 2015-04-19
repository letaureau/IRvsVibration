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

const int numReadings = 10;
const int numSensor=8;
float readings[numSensor][numReadings];      // the readings from the analog input
int indexR=0;                  // the index of the current reading
int total[numReadings];                  // the running total
int average[numReadings];                // the average
int indexS=0;


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

  // initialize all the readings to 0:
  for (int thisSensor = 0; thisSensor < numSensor; thisSensor++)
  {
    for (int thisReading = 0; thisReading < numReadings; thisReading++)
    { 
     readings[thisSensor][thisReading] = 0;
     total[thisReading]=0;
     average[thisReading]=0;
    }
  }    
}

void loop() 
{
  for (indexR = 0; indexR < numReadings; indexR++)
  {
    for (int indexS = 0; indexS < numSensor; indexS++)
    {
    // subtract the last reading:
    total[indexR]= total[indexR] - readings[indexS][indexR];        
    }
    // read from the sensor:  
    float volts0 = analogRead(analogInPin0)*0.00273;  //    value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue0= analogRead(analogInPin0);
    readings[0][indexR] = 65*pow(volts0, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk
 
    float volts1 = analogRead(analogInPin1)*0.00273;      //value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue1 = analogRead(analogInPin1);
    readings[1][indexR] = 65*pow(volts1, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk
 
    float volts2 = analogRead(analogInPin2)*0.000273;     // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue2 = analogRead(analogInPin2);
    readings[2][indexR] = 65*pow(volts2, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    float volts3 = analogRead(analogInPin3)*0.00273;    //  value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue3= analogRead(analogInPin3);
    readings[3][indexR] = 65*pow(volts3, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    float volts4 = analogRead(analogInPin4)*0.00273;      //value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue4= analogRead(analogInPin4);
    readings[4][indexR] = 65*pow(volts4, -1.10);            // worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    float volts5 = analogRead(analogInPin5)*0.00273;     // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue5= analogRead(analogInPin5);
    readings[5][indexR] = 65*pow(volts5, -1.10);          //   worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    float volts6 = analogRead(analogInPin6)*0.00273;   //   value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue6= analogRead(analogInPin6);
    readings[6][indexR] = 65*pow(volts6, -1.10);         //    worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    float volts7 = analogRead(analogInPin7)*0.00273;  //    value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    sensorValue7= analogRead(analogInPin7);
    readings[7][indexR] = 65*pow(volts7, -1.10);          //   worked out from graph 65 = theoretical distance / (1/Volts)S - luckylarry.co.uk

    // add the reading to the total:
    for (int indexS = 0; indexS < numSensor; indexS++)
    {
    // subtract the last reading:
      total[indexR]= total[indexR] + readings[indexS][indexR];        
    }
  }
  for (indexR = 0; indexR < numReadings; indexR++)
  {
    average[indexR] = total[indexR] / numReadings;
  }    
  if(average[0]>150)
  {
   digitalWrite(analogEnPin0, LOW);   
  }
  if(average[0]<30)
  {
   digitalWrite(analogEnPin0,HIGH);
   analogWrite(analogOutPin0,255);
  }
  if(average[0]>30 && average[0]<150)
  {  
    outputValue0 = map(average[0], 30, 150, 255, 0);
    analogWrite(analogOutPin0,outputValue0);
  }  
  if(average[1]>150)
  {
   digitalWrite(analogEnPin1, LOW);   
  }
  if(average[1]<30)
  {
   digitalWrite(analogEnPin1,HIGH);
   analogWrite(analogOutPin1,255);
  }
  if(average[1]>30 && average[1]<150)
  {  
    outputValue1 = map(average[1], 30, 150, 255, 0);
    analogWrite(analogOutPin1,outputValue1);
  }
  if(average[2]>150)
  {
   digitalWrite(analogEnPin2, LOW);   
  }
  if(average[2]<30)
  {
   digitalWrite(analogEnPin2,HIGH);
   analogWrite(analogOutPin2,255);
  }
  if(average[2]>30 && average[2]<150)
  {  
    outputValue2 = map(average[2], 30, 150, 255, 0);
    analogWrite(analogOutPin2,outputValue2);
  }  
  if(average[3]>150)
  {
   digitalWrite(analogEnPin3, LOW);   
  }
  if(average[3]<30)
  {
   digitalWrite(analogEnPin3,HIGH);
   analogWrite(analogOutPin3,255);
  }
  if(average[3]>30 && average[3]<150)
  {  
    outputValue3 = map(average[3], 30, 150, 255, 0);
    analogWrite(analogOutPin3,outputValue3);
  }
  if(average[4]>150)
  {
   digitalWrite(analogEnPin4, LOW);   
  }
  if(average[4]<30)
  {
   digitalWrite(analogEnPin4,HIGH);
   analogWrite(analogOutPin4,255);
  }
  if(average[4]>30 && average[4]<150)
  {  
    outputValue4 = map(average[4], 30, 150, 255, 0);
    analogWrite(analogOutPin4,outputValue4);
  }  
  if(average[5]>150)
  {
   digitalWrite(analogEnPin5, LOW);   
  }
  if(average[5]<30)
  {
   digitalWrite(analogEnPin5,HIGH);
   analogWrite(analogOutPin5,255);
  }
  if(average[5]>30 && average[5]<150)
  {  
    outputValue5 = map(average[5], 30, 150, 255, 0);
    analogWrite(analogOutPin5,outputValue5);
  }
  if(average[6]>150)
  {
   digitalWrite(analogEnPin6, LOW);   
  }
  if(average[6]<30)
  {
   digitalWrite(analogEnPin6,HIGH);
   analogWrite(analogOutPin6,255);
  }
  if(average[6]>30 && average[6]<150)
  {  
    outputValue6 = map(average[6], 30, 150, 255, 0);
    analogWrite(analogOutPin6,outputValue6);
  }  
  if(average[7]>150)
  {
   digitalWrite(analogEnPin7, LOW);   
  }
  if(average[7]<30)
  {
   digitalWrite(analogEnPin7,HIGH);
   analogWrite(analogOutPin7,255);
  }
  if(average[7]>30 && average[7]<150)
  {  
    outputValue7 = map(average[7], 30, 150, 255, 0);
    analogWrite(analogOutPin7,outputValue7);
  }
  for (int i=0;i<numReadings;i++)
  {
    Serial.print("  ");
    Serial.print(average[i]);
    Serial.print("  ");
  }
  Serial.println();
  Serial.println();
  delay(1);        // delay in between reads for stability           
}
