#include <Ultrassonic.h>

//Trig no pino 8
//Echo no pino 9
Ultrassonic sensor1(8, 9);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float dist;
  dist = sensor1.getDistancia(CENTIMETRO);
  Serial.print(dist);
  Serial.print("cm  \t");
  
  dist = sensor1.converter(dist, CENTIMETRO, METRO);
  Serial.print(dist);
  Serial.println("m");
  delay(250);
}
