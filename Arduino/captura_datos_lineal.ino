// definiciones acelerometro
#include <AS5600.h> 
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
// definiciones acelerometro 
Adafruit_MPU6050 mpu;
float acl;
// definiciones angulo
AMS_5600 ams5600;
int ang, lang = 0;
float grados;
float grados_2;
// declaraciones sensor posicion
#define echoPin 19
#define trigPin 18
float duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement
float distance_2;
//declaraciones para la comunicacion 
char dato;
String cadena1;
String cadena2;
String cadena3;
String term = ":";
String resultado;

void setup(void) {
  Serial.begin(115200);
//----------------------------------------------------------------------- 
  Wire.begin();
   
    if(ams5600.detectMagnet() == 0 ){
      while(1){
          if(ams5600.detectMagnet() == 1 ){
              Serial.print("Current Magnitude: ");
              Serial.println(ams5600.getMagnitude());
              break;
          }
          else{
              Serial.println("Can not detect magnet");
          }
          delay(1000);
      }
    }
//----------------------------------------------------------------------- 
 Wire.beginTransmission(0x68);
 Wire.write(0x6B); 
 Wire.write(0);    
 Wire.endTransmission(true);
 if (!mpu.begin(0x68)) {
   Serial.println("Failed to find MPU6050 chip");
   while (1) {
     delay(10);
   }
 }
 mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
 
  Serial.println("");
  delay(100);
//----------------------------------------------------------------------- 
// declaraciones sensor posicion
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  while(Serial.available() == 0);
    if(Serial.available() > 0){
      dato = Serial.read();
    }
    if(dato == '1'){
       aceleracion();
       posicion();
       grados = 243-angulo(ams5600.getRawAngle());
       
        //linealizacion
        distance_2 = 2.7*(distance) - 2;
        grados_2 = 1.2*(grados) - 7.4;

//        float acel_ant;
//        for(int i = 0; i < 5; i++){
//          acel_ant = acl;
//          acl = acel_ant + acl;
//        }
//        acel_ant = 0;
//        acl = acl/5;
      
       cadena1 = (String) acl;
       cadena2 = (String) distance_2;
       cadena3 = (String) grados_2;
       resultado = cadena1 + term + cadena2 + term + cadena3;
       Serial.println(resultado);     
    }
  

}

void aceleracion(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  acl = a.acceleration.x;
  delay(10);
}

void posicion(){
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance = distance - 3.2;
  // Displays the distance on the Serial Monitor
  delay(20);
}

float angulo(word newAngle){
    /* Raw data reports 0 - 4095 segments, which is 0.087 of a degree */
  float retVal = newAngle * 0.087;
  return retVal;
}

void imprime_arduino(){
  Serial.print("AccelX:");
  Serial.print(acl);
  Serial.print(",");
  Serial.print("posicion X:");
  Serial.print(distance);
  Serial.print(",");
  Serial.print("Angulo:");
  Serial.print(grados);
  Serial.println("");
}
