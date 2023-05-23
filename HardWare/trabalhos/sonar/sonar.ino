#include <Servo.h>


int echo = 3;
int trig = 2;
int ledVermelho = 5;
int ledVerde = 6;
int trig2 = 8;
int echo2 = 9;

Servo servoBase;

void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig, OUTPUT);
  servoBase.attach(A1);//Pin a utilizar para servo
  servoBase.write(90);  //asigno 0 al servo motor
}

void loop() {
  long duration, distanceCm,duration2,distanceCm2;
  digitalWrite(trig, LOW);
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  digitalWrite(trig2, LOW);
  duration = pulseIn(echo, HIGH);
  distanceCm = duration *  0.01723 ;
  duration2 = pulseIn(echo2, HIGH);
  distanceCm2 = duration2 *  0.01723 ;
  Serial.println("d1: ");
  Serial.println(distanceCm);
  Serial.println("\n");
  Serial.println("d2: ");
  Serial.println(distanceCm2);

  if(distanceCm == 0){
    analogWrite(ledVermelho,255);
  }else if(distanceCm > 334){
    analogWrite(ledVermelho,0);
  }else{
    analogWrite(ledVermelho,255/distanceCm);
  }

  if(distanceCm <=10){
    servoBase.write(0);
  }else if(distanceCm >10 && distanceCm2 <=10){
    servoBase.write(90);
  }
}