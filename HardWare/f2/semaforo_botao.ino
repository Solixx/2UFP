// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
}

void loop()
{
  
  if(digitalRead(8) == HIGH){
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  } else{
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(100);
    digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
    delay(10000);
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    delay(125);
  }
}