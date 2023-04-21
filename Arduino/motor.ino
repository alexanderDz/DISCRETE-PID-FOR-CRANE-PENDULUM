#define EN 15
#define IN1 4
#define IN2 5
void setup() {
  pinMode(EN,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()>0){
    char dato = Serial.read();
    Serial.println(dato);
    switch(dato){
      case '1':
      digitalWrite(EN,HIGH);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      delay(790);
      digitalWrite(EN,LOW);

      digitalWrite(EN,HIGH);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      delay(790);
      digitalWrite(EN,LOW);
      break;
      case '2':

      break;
      default:
      break;
    }
    
  }

}
