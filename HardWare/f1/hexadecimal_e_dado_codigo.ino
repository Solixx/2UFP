// C++ code
//

int matrix[16][7] = {{7, 8, 9, 10, 11, 12, -1},
  						{7, -1, -1, 10, -1, -1, -1},
  {-1, 8, 9, 10, 11, -1, 6},
  {11, 10, 6, 7, 8, -1, -1},
  {12, 6, 10, 7, -1, -1, -1},
  {11, 12, 6, 7, 8, -1, -1},
  {12, 9, 6, 7, 8, 11, -1},
  {11, 10, 7, -1, -1, -1, -1},
  {11, 10, 6, 7, 8, 12, 9},
  {11, 10, 6, 7, 8, 12, -1},
  {11, 10, 6, 7, -1, 12, 9},
  {11, 10, 6, 7, 8, 12, 9},
  {11, 12, 9, 8, -1, -1, -1},
  {11, 10, -1, 7, 8, 12, 9},
  {11, -1, 6, -1, 8, 12, 9},
  {11, -1, 6, -1, -1, 12, 9}};

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  //hexadeciamlCount();
  dado();
}

void hexadeciamlCount(){
	for(int i = 0; i < 16; i++){
    	for(int j = 0; j < 7; j++){
      		digitalWrite(matrix[i][j], HIGH);
    	}
    	delay(1000);
    	digitalWrite(7, LOW);
    	digitalWrite(8, LOW);
    	digitalWrite(9, LOW);
    	digitalWrite(10, LOW);
    	digitalWrite(11, LOW);
    	digitalWrite(12, LOW);
    	digitalWrite(6, LOW);
  	}
}

void dado(){
  int num = rand()%7;
   for(int j = 0; j < 7; j++){
    	digitalWrite(matrix[num][j], HIGH);
   }
   delay(1000);
  digitalWrite(7, LOW);
    	digitalWrite(8, LOW);
    	digitalWrite(9, LOW);
    	digitalWrite(10, LOW);
    	digitalWrite(11, LOW);
    	digitalWrite(12, LOW);
    	digitalWrite(6, LOW);
}

