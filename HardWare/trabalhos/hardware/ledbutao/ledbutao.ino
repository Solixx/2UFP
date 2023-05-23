//LedScale
//Date: 23/02/2023


int i = 11;
void setup()
{
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{

 if(digitalRead(12)== LOW){
   if(i>6 && i<12){
     digitalWrite(i,HIGH);
     i--;
     delay(200);
   }else{
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     i=11;
     delay(200);
   }
}
}