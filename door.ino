int value1;
#define relay 9
const int buzzer = 7; 
#include <Servo.h>
Servo myservo;
int pos = 0;    
void setup()
{
    Serial.begin(9600);
    pinMode(relay, OUTPUT);
    pinMode(buzzer, OUTPUT); 
    digitalWrite(relay, HIGH);
    myservo.attach(10);
}
void loop()
{
  Serial.print("Reading");
  while(Serial.available()==0);
  value1 = Serial.read();
  Serial.print(value1);
  if (value1==1)
  { 
    Serial.print("Unlocking");
    digitalWrite(relay, LOW);
    digitalWrite(buzzer, HIGH); 
    delay(1000);        
    digitalWrite(buzzer, LOW);
    for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  }
  if (value1==0)
  {
      digitalWrite(relay, HIGH);
      Serial.print("Locking");
      for (pos = 180; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(15);                       
  } 
  }
}
