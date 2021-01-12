#include <Servo.h>

#define S0 8
#define S1 9

Servo SERVO1;
Servo SERVO2;
            
int data1, data2;


void setup() 
{
   Serial.begin(9600);
   int i;
   
  SERVO1.attach(S0);
  SERVO2.attach(S1);

  SERVO1.write(0);
  SERVO2.write(0);
  delay(1000);
 
}
void loop()
{
    int i;

      data1=analogRead(A0);
     data2=analogRead(A1);
 //     Serial.println(data1);
   //   Serial.println(data2);
      data1=map(data1, 0, 1023, 0, 180);
      data2=map(data2, 0, 1023, 0, 180);      
       
      SERVO1.write(data1);
      SERVO2.write(data2);
        Serial.println(data1);
      Serial.println(data2);
        delay(100);
  
    
}
