#define pot1 15
#define pot2 2
#define pot3 4

int val_1;
int val_2;
int val_3;
String cadena1;
String cadena2;
String cadena3;
String term = ":";
String resultado;
char dato;

void setup() {
  Serial.begin(115200);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(pot3,INPUT);

}

void loop() {
  while(Serial.available() == 0);
    if(Serial.available() > 0){
      dato = Serial.read();
    }
    if(dato == '1'){
      val_1 = analogRead(pot1);
      val_2 = analogRead(pot2);
      val_3 = analogRead(pot3);
      cadena1 = (String) val_1;
      cadena2 = (String) val_2;
      cadena3 = (String) val_3;
      resultado = cadena1 + term + cadena2 + term + cadena3;
      Serial.println(resultado);      
    }
  }
