// C++ code
//
static const struct { const char letter, *code; } MorseMap[] = {
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', ".-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { ' ', " " },
};
char letra;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP);
}

void loop() {

  int val = analogRead(A0);
  if (Serial.available() > 0) {
    letra = Serial.read();

    verificarletra(letra);
  }
  if (digitalRead(12) == LOW)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}

void verificarletra(char letra) {
  Serial.println(letra);
  for (int i = 0; i < 27; i++) {
    
    if (letra == MorseMap[i].letter) {
      
      char *c = MorseMap[i].code;
      Serial.println(c);
      for (int j = 0; c[j] != '\0'; j++) {
        Serial.println(c[j]);
        digitalWrite(13, HIGH);
        if (c[j] == '.') {
          delay(500);
          digitalWrite(13, LOW);

        } else if (c[j] == '-') {
          delay(1000);
          digitalWrite(13, LOW); 
        }else if(c[j] == ' '){
          digitalWrite(13,LOW);
          delay(1000);
        }
        delay(500);
      }
      delay(500);
    }
   
  }
}