#define EN1 15
#define IN1 4
#define IN2 5

const int channel=0;
const int resolution=8;
const int freq=20000;
int dmin = 155;
int dmax = 255;
int dutycicle = dmin;

int f1 = 28;
int f2 = 28;
int f3 = 24;
int f4 = 16;
int f5 = 4;
int f6 = 2;
int f7 = 4;
int f8 = 16;
int f9 = 24;
int f10 = 28;

 
void setup() {
 Serial.begin(115200);
 ledcSetup(channel, freq, resolution);
 ledcAttachPin(EN1, channel);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 //pinMode(EN1, OUTPUT);
}

void loop() {
  //freq1();
  freq2();
  freq3();
  freq4();
//  freq5();
//  freq6();
//  freq7();
  freq8();
  freq9();
  freq10();
}

void freq1(){
   digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f1);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f1);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f1);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f1);
  }
  dutycicle=dmin;
}

void freq2(){
  /*Segunda Frecuencia*/
   digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f2);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f2);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f2);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f2);
  }
  dutycicle=dmin;
}
void freq3(){
  /* Tercera frecuencia*/
  
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f3);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f3);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f3);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f3);
  }
  dutycicle=dmin;
}
void freq4(){
  /* Cuarta frecuencia*/
  
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f4);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f4);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f4);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f4);
  }
  dutycicle=dmin;
}
void freq5(){
  /* Quinta frecuencia*/
  
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f5);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f5);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f5);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f5);
  }
  dutycicle=dmin;
}
void freq6(){
  /* Sexta frecuencia*/
  
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f6);//2
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f6);//2
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f6);//6
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f6);//6
  }
  dutycicle=dmin;

}
void freq7(){
  /* Septima frecuencia*/
     
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f7);//4
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f7);//4
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f7);//6
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f7);//6
  }
  dutycicle=dmin;
}
void freq8(){
 /*Octava Frecuencia*/
   
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f8);//7
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f8);//7
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f8);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f8);
  }
  dutycicle=dmin; 
}

void freq9(){
  /*Novena Frecuencia*/
  
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f9);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f9);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f9);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f9);
  }
  dutycicle=dmin;
}

void freq10(){
  /*Decima Frecuencia*/
  
    digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f10);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f10);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
   while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f10);
  }
  dutycicle=dmax;
    while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f10);
  }
  dutycicle=dmin;
}
