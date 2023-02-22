// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5,INPUT);
}

void loop()
{
  int checkbutao;
  int read=digitalRead(5);
 int estadoButao=digitalRead(7);
  if(read==LOW){
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  } else{
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
    delay(10000);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    delay(125);
  }


}