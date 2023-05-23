#include <Servo.h>
int butaoA = 13, butaoB = 12, butaoC = 11, green = 10, blue = 9, red = 8;
int rand1;
int rand2;
int num = 0;
int resposta = 0;
int resultado;
int b = 0;
int sinal;
int rodar = 0;
int contador = 0;
int jokers = 1;

int resp1;
int resp2;
int pos1;
int pos2;
int pos3;

int opcao[3];
Servo servo;



int speakerPin = 7;

int length = 10;               // the number of notes
char notes[] = "fefeca a#a ";  // a space represents a rest
int beats[] = {
  4,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
};
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'd#', 'e', 'f', 'g', 'g#', 'a', 'a#' };
  int tones[] = { 1915, 1700, 1608, 1519, 1432, 1275, 1205, 1136, 1073 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
void musica() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo);  // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo / 2);
  }
}

void operacao() {
  Serial.print("\n");
  Serial.print(rand1);
  switch (sinal) {
    case 0:
      Serial.print("+");
      resultado = rand1 + rand2;
      break;
    case 1:
      Serial.print("-");
      resultado = rand1 - rand2;
      break;
    case 2:
      Serial.print("*");
      resultado = rand1 * rand2;
      break;
    case 3:
      Serial.print("/");
      if (rand2 == 0) rand2 = rand2 + 1;
      resultado = rand1 / rand2;
      break;
  }

  Serial.print(rand2);
  Serial.print("=");
  Serial.print("?");
  Serial.print("\n");
}

void opcoes() {
  pos1 = random(11, 14);
  pos2 = random(11, 14);
  while (pos1 == pos2) {
    pos2 = random(11, 14);
  }
  pos3 = random(11, 14);
  while (pos1 == pos3 || pos2 == pos3) {
    pos3 = random(11, 14);
  }
  if (pos1 == 11) {
    Serial.print("A) ");
    Serial.print(resp1);
    Serial.print("\n");
    opcao[0] = resp1;
  } else if (pos2 == 11) {
    Serial.print("A) ");
    Serial.print(resp2);
    Serial.print("\n");
    opcao[0] = resp2;
  } else if (pos3 == 11) {
    Serial.print("A) ");
    Serial.print(resultado);
    Serial.print("\n");
    opcao[0] = resultado;
  }
  if (pos1 == 12) {
    Serial.print("B) ");
    Serial.print(resp1);
    Serial.print("\n");
    opcao[1] = resp1;
  } else if (pos2 == 12) {
    Serial.print("B) ");
    Serial.print(resp2);
    Serial.print("\n");
    opcao[1] = resp2;
  } else if (pos3 == 12) {
    Serial.print("B) ");
    Serial.print(resultado);
    Serial.print("\n");
    opcao[1] = resultado;
  }
  if (pos1 == 13) {
    Serial.print("C) ");
    Serial.print(resp1);
    Serial.print("\n");
    opcao[2] = resp1;
  } else if (pos2 == 13) {
    Serial.print("C) ");
    Serial.print(resp2);
    Serial.print("\n");
    opcao[2] = resp2;
  } else if (pos3 == 13) {
    Serial.print("C) ");
    Serial.print(resultado);
    Serial.print("\n");
    opcao[2] = resultado;
  }
}

void gerarRespRandom() {
  resp1 = random(1, 20);
  resp2 = random(1, 20);
  resp2 = resp2 - resultado;
  resp1 = resp1 + resultado;
  if (resp1 == resp2) {
    resp1 = resp1 + 5;
  }
  if (resp1 == resultado) {
    resp1 = resp1 + 1;
  } else if (resp2 == resultado) {
    resp2 = resp2 - 1;
  }
  opcoes();
}
void randolas() {
  sinal = random(0, 4);
  rand1 = random(0, 10);
  rand2 = random(0, 10);
  operacao();
  gerarRespRandom();
}
void setup() {
  Serial.begin(9600);
  pinMode(butaoA, INPUT_PULLUP);
  pinMode(butaoB, INPUT_PULLUP);
  pinMode(butaoC, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  servo.attach(A2);
  servo.write(0);

  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  randomSeed(analogRead(0));
  randolas();
}


void loop() {
  if (Serial.read() == 'j') {
    if (jokers > 0) {
      Serial.print("Joker\n");
      randolas();
      jokers--;
    } else {
      Serial.print("Joker indisponivel\n");
    }
  } else {
    if (digitalRead(butaoA) == LOW) {
      Serial.print("A analisar a resposta...\n");
      delay(1000);
      if (opcao[0] == resultado) {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        Serial.print("Certo\n");
        if (contador == 10) {
          Serial.print("10 CERTAS");
          musica();
          jokers = jokers + 3;
        }
        contador = contador + 1;
        rodar = rodar + 18;
        resposta = 0;
        servo.write(rodar);
        randolas();
      } else {
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        Serial.print("Errado\n");
        rodar = 0;
        contador = 0;
        servo.write(rodar);
        resposta = 0;
      }
    } else if (digitalRead(butaoB) == LOW) {

      Serial.print("A analisar a resposta...\n");
      delay(1000);
      if (opcao[1] == resultado) {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        Serial.print("Certo\n");
        if (contador == 10) {
          Serial.print("10 CERTAS");
          musica();
          jokers = jokers + 3;
        }
        contador = contador + 1;
        rodar = rodar + 18;
        resposta = 0;
        servo.write(rodar);
        randolas();
      } else {
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        Serial.print("Errado\n");
        rodar = 0;
        contador = 0;
        servo.write(rodar);
        resposta = 0;
      }
    } else if (digitalRead(butaoC) == LOW) {

      Serial.print("A analisar a resposta...\n");
      delay(1000);
      if (opcao[2] == resultado) {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        Serial.print("Certo\n");
        if (contador == 10) {
          Serial.print("10 CERTAS");
          musica();
          jokers = jokers + 3;
        }
        contador = contador + 1;
        rodar = rodar + 18;
        resposta = 0;
        servo.write(rodar);
        randolas();
      } else {
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        Serial.print("Errado\n");
        rodar = 0;
        contador = 0;
        servo.write(rodar);
        resposta = 0;
      }
    }
  }



  /*
  while (Serial.available()) {
    num = Serial.read();
    if(num == 45){
      resultado = resultado * -1;
    }else if (num != 10) {
      resposta = resposta * 10 + (num - 48);
    } else {
      if (resposta == resultado) {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        Serial.print("Certo\n");
        if(contador ==10){
          Serial.print("10 CERTAS");
          musica();
        }
        contador = contador+1;
        rodar = rodar +18;
        resposta = 0;
        servo.write(rodar);
        randolas();

      } else {
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        Serial.print("Errado\n");
        rodar = 0;
        contador = 0;
        servo.write(rodar);
        resposta = 0;
      }
    }
  }*/
}
