#include <Servo.h>
//Objeto
Servo myservo;
int pos=90;
int valor;
int valor_new;

void setup()
{
	myservo.attach(9);
    Serial.begin(9600); 
}

void loop()
{
  valor=analogRead(A0);
  delay(100);
  myservo.write(pos);
  
  if(valor!=valor_new)
  {
    pos = map(valor,0,1023,0,180);
    myservo.write(pos);
  }
  delay(10);
  valor_new=analogRead(A0);
  Serial.println(analogRead(A0));
  Serial.println(pos);
  delay(250);

}