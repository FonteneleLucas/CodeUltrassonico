//Codigo para 4 sensores
#include <Ultrasonic.h>

#define echoUp   29
#define trigUp   28

#define echoDown 27
#define trigDown 26

#define echoEsq  25
#define trigEsq  24

#define echoDir  23
#define trigDir  22

Ultrasonic ultrasonic(trigDown, echoDown);
Ultrasonic ultrasonic2(trigUp, echoUp);
Ultrasonic ultrasonic3(trigEsq, echoEsq);
Ultrasonic ultrasonic4(trigDir, echoDir);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop(){
  sensorDist(2);
}

float sensorDist(int numSensor){
  // 1 - Frete Baixo | 2 - Frente Cima | 3 - Lat Esq | 4 - Lat Dir
  float distancia;
  if(numSensor == 1){
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  }else if(numSensor == 2){
    long microsec = ultrasonic2.timing();
    distancia = ultrasonic2.convert(microsec, Ultrasonic::CM);
  }else if(numSensor == 3){
    long microsec = ultrasonic3.timing();
    distancia = ultrasonic3.convert(microsec, Ultrasonic::CM);
  }else{
    long microsec = ultrasonic4.timing();
    distancia = ultrasonic4.convert(microsec, Ultrasonic::CM);
  }
  return distancia;
}

