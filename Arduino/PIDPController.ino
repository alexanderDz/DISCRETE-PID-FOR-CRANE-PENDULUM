#include <Arduino.h>
#include <analogWrite.h>
#define EN1 15
#define IN1 4
#define IN2 5
// declaraciones sensor posicion
#define echoPin 19
#define trigPin 18

#include <AS5600.h> 
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// definiciones acelerometro 
Adafruit_MPU6050 mpu;

// definiciones angulo
AMS_5600 ams5600;

const int channel = 0;
const int resolution = 8;
const int freq = 20000;
int dutycicle;

//variables
float pos;
float ac;
float ang;
//variables del PID
//float Kp=-0.00737,Ki=-0.0109,Kd=0;
float Kp=-0.0026,Ki=-0.0754,Kd=0;
float yi;
int r=6;
unsigned long Tact,Ts,Tant;
float a,b,c;
float e,e_1,e_2;
float u=0,u_1=0,um=0;

TaskHandle_t Task1;
void setup() {
    xTaskCreatePinnedToCore(
    task1,
    "Task_1",
    1000,
    NULL,
    1,
    &Task1,
    1);  //Nucleo 0
  Serial.begin(115200);
  // declaraciones sensor posicion
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
//----------------------------------------------------------------------- 
  //Wire.begin();
   
//    if(ams5600.detectMagnet() == 0 ){
//      while(1){
//          if(ams5600.detectMagnet() == 1 ){
//              Serial.print("Current Magnitude: ");
//              Serial.println(ams5600.getMagnitude());
//              break;
//          }
//          else{
//              Serial.println("Can not detect magnet");
//          }
//          delay(1000);
//      }
//    }
//----------------------------------------------------------------------- 
// Wire.beginTransmission(0x68);
// Wire.write(0x6B); 
// Wire.write(0);    
// Wire.endTransmission(true);
// if (!mpu.begin(0x68)) {
//   Serial.println("Failed to find MPU6050 chip");
//   while (1) {
//     delay(10);
//   }
// }
// mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
// 
//  Serial.println("");
//  delay(100);
//----------------------------------------------------------------------- 
ledcSetup(channel, freq, resolution);
ledcAttachPin(EN1, channel);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
}


void task1(void *parameters){
  for(;;){
    if(e<0){
      //ledcWrite(channel, dutycicle);
      digitalWrite(IN1, LOW);  //Derecha
      digitalWrite(IN2, HIGH);
    }
    else if(e>0){
      //ledcWrite(channel, dutycicle);
      digitalWrite(IN1, HIGH);  //IZQUIERDA
      digitalWrite(IN2, LOW);
    }
    analogWrite(15, dutycicle);
    vTaskDelay(10/portTICK_PERIOD_MS);
    }
  
}
String dato;
int filtro = 30;
void loop() {
  if(Serial.available() > 0){
      dato = Serial.readString();
      r=dato.toInt();
      }
  pos = posicion();
  //ang = 246-angulo(ams5600.getRawAngle());
  //ac = aceleracion();
  yi = pos;
  pid();
  imprime_arduino();
  delay(10);
}
float u_ant;
void pid(){
  //tiempo entre muestras
  Tact = millis();
  Ts = float(Tact - Tant);
  Tant = Tact;
  //Constantes de la aproximacion trapezoidal 
  a = (Kp + Ki*Ts/2 + Kd/Ts);
  b = (-Kp + Ki*(Ts/2) - 2*Kd/Ts);
  c = Kd/Ts;
  //Error y muestras anteriores al mismo tiempo
  e = r - yi; 
  e_2 = e_1;
  e_1 = e;
  //calculo de la salida
  u = u_1 + a*e + b*e_1 + c*e_2;
  u_ant=u;
  if(abs(e)<=0.2)u=0;
  u_1 = u;
  //salida  
  if (u<0)
    um = map(-u,0,100,0,20);
  else um = map(u,0,100,0,20);
  if(um <= 0){
    um = 0;
  }
  if(um > 100){
    um = 100;
  }      

  dutycicle=um;

}


float posicion(){
  float duration; // variable for the duration of sound wave travel
  float distance; // variable for the distance measurement
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
  return distance;
  delay(20);
}

float angulo(word newAngle){
    /* Raw data reports 0 - 4095 segments, which is 0.087 of a degree */
  float retVal = newAngle * 0.087;
  return retVal;
}

float aceleracion(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  return a.acceleration.x;
  delay(10);
}

void imprime_arduino(){
//  Serial.print("AccelX:");
//  Serial.print(ac);
//  Serial.print(",");
  Serial.print("posicion_X:");
  Serial.print(pos);
  Serial.print(",");
//  Serial.print("Angulo:");
//  Serial.print(ang);
//  Serial.print(",");
  Serial.print("r:");
  Serial.print(r);
//  Serial.print(",");
//  Serial.print("yi:");
//  Serial.print(yi);
  Serial.print(",");
  Serial.print("um:");
  Serial.print(um);
Serial.print(",");
  Serial.print("error:");
  Serial.print(e);
//  Serial.print(",");
//  Serial.print("u:");
//  Serial.print(u);
    Serial.print(",");
  Serial.print("10Xpos:");
  Serial.println(10*pos);
}
