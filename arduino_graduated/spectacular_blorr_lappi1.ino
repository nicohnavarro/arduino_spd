void setup()
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop()
{
  int x,i;
  /*analogWrite(3,0);
  delay(100);
  analogWrite(3,10);
  delay(100);
  analogWrite(3,64);
  delay(100);
  analogWrite(3,100);
  delay(100);
  analogWrite(3,160);
  delay(100);
  analogWrite(3,255);
  delay(100);
  analogWrite(3,160);
  delay(100);
  analogWrite(3,100);
  delay(100);
  analogWrite(3,64);
  delay(100);
  analogWrite(3,10);
  delay(100);
  analogWrite(3,0);
  delay(100);
  analogWrite(3,255);
  analogWrite(3,0);*/
  for(i=0;i<255;i++)
  {
    analogWrite(3,i);
    delay(5);
  }
  for(i=255;i<1;i--)
  {
  	analogWrite(3,i);
    delay(5);
  }
  
  x=analogRead(A0);
  
  
  //Imprimimos por el monitor serie
  Serial.print("El valor es = ");
  Serial.println(x);
  delay(1000);
}