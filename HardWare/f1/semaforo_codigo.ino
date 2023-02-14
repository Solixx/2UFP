// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  //semaforoNormal();
  semaforoBritanico();
  //semaforoBritanico2();
}

void semaforoNormal(){
  digitalWrite(11, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(13, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}

void semaforoBritanico(){
  	digitalWrite(13, HIGH);
  	delay(3000);
  	digitalWrite(12, HIGH);
  	delay(1000);
  	digitalWrite(11, HIGH);
  	digitalWrite(13, LOW);
  	digitalWrite(12, LOW);
  	delay(3000);
  	digitalWrite(11, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
}

void semaforoBritanico2(){
  	digitalWrite(13, HIGH);
  	delay(3000);
  	for(int i = 0; i < 3; i++){
  		digitalWrite(12, HIGH);
      	delay(300);
      	digitalWrite(12, LOW);
      	delay(300);
  	}
  	digitalWrite(13, LOW);
  	digitalWrite(11, HIGH);
  	delay(3000);
  	digitalWrite(11, LOW);
  	delay(1000);
  	digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
}