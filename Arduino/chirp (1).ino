#define EN1 15
#define IN1 4
#define IN2 5

const int channel=0;
const int resolution=8;
const int freq=20000;
int d_min = 165;
int dmax = 255;
int dutycicle = d_min;

 
void setup() {
 Serial.begin(115200);
 ledcSetup(channel, freq, resolution);
 ledcAttachPin(EN1, channel);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 //pinMode(EN1, OUTPUT);
}

void loop() {
  frecuencia(20,160);
  frecuencia(18,140);
  frecuencia(14,120);
  frecuencia(18,140);


}

void frecuencia(int f,int dmin){
  digitalWrite(IN1, HIGH);      //Derecha
  digitalWrite(IN2, LOW);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f);
  }
  dutycicle=dmax;
  while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f);
  }
  dutycicle=dmin;
  digitalWrite(IN1, LOW);      //IZQUIERDA
  digitalWrite(IN2, HIGH);
  while(dutycicle<=dmax){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle+5;
    Serial.println(dutycicle);
    delay(f);
  }
  dutycicle=dmax;
  while(dutycicle>=dmin){
    ledcWrite(channel, dutycicle);
    dutycicle=dutycicle-5;
    Serial.println(dutycicle);
    delay(f);
  }
  dutycicle=dmin;
}
