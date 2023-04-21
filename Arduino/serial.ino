void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()>0){
    char dato = Serial.read();
    if(dato=='1'){
      digitalWrite(2,HIGH);
    }
    else if(dato=='0'){
      digitalWrite(2,LOW);
    }
  }
delay(100);
}
