//LedScale
//Date: 23/02/2023


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  int valor = analogRead(A0);
  Serial.println(valor);
  //int div = 1024 / 5;
  if (valor < 204) {
    digitalWrite(11, 0);
    digitalWrite(10, 0);
    digitalWrite(9, 0);
    digitalWrite(8, 0);
    digitalWrite(7, 0);
  }
 if (valor >= 204) {
    digitalWrite(11, 1);
    digitalWrite(10, 0);
    digitalWrite(9, 0);
    digitalWrite(8, 0);
    digitalWrite(7, 0);
  }
 if (valor >= 409) {
   digitalWrite(11, 1);
    digitalWrite(10, 1);
    digitalWrite(9, 0);
    digitalWrite(8, 0);
    digitalWrite(7, 0);
  }
 if (valor >= 613) {
   digitalWrite(11, 1);
    digitalWrite(10, 1);
    digitalWrite(9, 1);
    digitalWrite(8, 0);
    digitalWrite(7, 0);
  }
 if (valor >= 813) {

   digitalWrite(11, 1);
    digitalWrite(10, 1);
    digitalWrite(9, 1);
    digitalWrite(8, 1);
    digitalWrite(7, 0);
  }
 if (valor == 1023) {
   
   digitalWrite(11, 1);
    digitalWrite(10, 1);
    digitalWrite(9, 1);
    digitalWrite(8, 1);
    digitalWrite(7, 1);
  }
}