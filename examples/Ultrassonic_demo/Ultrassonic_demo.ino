#include <Ultrassonic.h>

//Trig no pino 8
//Echo no pino 9
Ultrassonic sensor1(8, 9);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int dist;
  dist = sensor1.getDistancia();
  Serial.print(dist);
  Serial.println("cm");
  delay(250);
}
