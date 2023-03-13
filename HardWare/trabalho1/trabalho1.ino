//LedScale
//Date: 23/02/2023
  int matrix[16][7] = {{0,9,8,7,6,5,4} //0
                       ,{7,6,0,0,0,0,0} //1
                       ,{8,7,10,5,4,0,0} //2
                       ,{8,7,10,6,5,0,0} //3
                       ,{10,9,7,6,0,0,0} //4
                       ,{8,9,10,6,5,0,0}//5
                       ,{10,9,8,0,6,5,4}//6
                       ,{8,7,6,0,0,0,0}//7
                       ,{10,9,8,7,6,5,4}//8
                       ,{10,9,8,7,6,5,0}};//9
int senha[4]={1,1,1,1};
int seq[4] = {-1,-1,-1,-1};
int i, learnM = 0, learnTimer = 0, senhaEmpty = 0, senhaIndex = 0;

void setup() {
  pinMode(1,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(13,OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
 
  attachInterrupt(1, sequencia, FALLING );
}

void sequencia(){
  tone(1,300);
      
  int b;
  if(learnM == 0){
    for(int j = 0;j < 4;j++){
    if(seq[j]==-1){
    	seq[j]=i;
      break;
    }
  }
   for(int j = 0;j < 4;j++){
     if(seq[j]==-1){
       b=1;
       break;
     }
     b=0;
  }
  if(b==0){
    for(int j=0;j < 4;j++){
      if(seq[j]!=senha[j]){
      	b=1;
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
        seq[0] = -1;
    	seq[1] = -1;
    	seq[2] = -1;
    	seq[3] = -1;
        tone(1,231);
               
        break;
      }
      b=0;
    }
    if(b==0){
    	digitalWrite(12,HIGH);
      	digitalWrite(11,LOW);
      	seq[0] = -1;
    	seq[1] = -1;
    	seq[2] = -1;
    	seq[3] = -1;
      tone(1,291);
      
      
      	learnTimer = 10;
    }
  }
  } else{
    if(senhaIndex < 4){
      	senha[senhaIndex] = i;
    	senhaIndex++;
      if(senhaIndex == 4){
        learnM = 0;
        senhaIndex = 0;
      }
    }/*
    for(int j = 0; j < 4; j++){
      seq[j] = -1;
    }*/
  }
};

void loop() {
  delay(100);
  noTone(1);
  int valor = analogRead(A0);
  if (valor < 113) {
    i=0;
  desligar();
    ligarNum(i);
  }
    if (valor >= 113 && valor <226) {
    i=1;
      desligar();
      ligarNum(i);
  }
 else if (valor >= 226 && valor <339) {
    i=2;
   desligar();
   ligarNum(i);
  }
 else if (valor >= 339 && valor <452) {
   i=3;
   desligar();
   ligarNum(i);
  }
 else if (valor >= 452 && valor <565) {
 	i=4;
   desligar();
   ligarNum(i);
  }
 else if (valor >= 565 && valor <678) {
	i=5;
desligar();
   ligarNum(i);
  }
 else if (valor >= 678 && valor <791) {
   i=6;
  desligar();
   ligarNum(i);
  }
  else if (valor >= 791 && valor <904) {
   i=7;
  desligar();
    ligarNum(i);
  }
  else if (valor >= 904 && valor <1017) {
   i=8;
  desligar();
    ligarNum(i);
  }
  else if (valor >= 1017) {
   i=9;
    desligar();
    ligarNum(i);
  }
  
  if(learnTimer != 0){
    
    if(digitalRead(2) == 0){
    int count = 0;
  	delay(1000);
    count++;
    if(digitalRead(2) == 0){
      	delay(1000);
  		count++;
      	if(count == 2){
    		learnM = 1;
    		learnTimer = 0;
          	digitalWrite(13,HIGH);
          	delay(1000);
          	digitalWrite(13,LOW);
  		}
      	else	count = 0;
    }
  	 else	count = 0;
  	}
   
    delay(1000);
  	learnTimer--;
  } else{
    learnM = 0;
    digitalWrite(12,LOW);
  }
  
  if(digitalRead(11) == 1){
      delay(2000);
      digitalWrite(11, LOW);
    }
}
                       
void ligarNum(int i){
  for(int j = 0;j < 7;j++){
    digitalWrite(matrix[i][j],!HIGH);
  }
                       }
 void desligar(){
      digitalWrite(10,!LOW);
      digitalWrite(9,!LOW);
      digitalWrite(8,!LOW);
      digitalWrite(7,!LOW);
      digitalWrite(6,!LOW);
      digitalWrite(5,!LOW);
      digitalWrite(4,!LOW);
 }
                       