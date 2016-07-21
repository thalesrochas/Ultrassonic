/*
  Ultrassonic.h - Biblioteca para uso no sensor ultrassonico HC-SR04.
  Escrito por Francisco T. R. Sousa, 29 de dezembro de 2015.
*/

#ifndef Ultrassonic_h
#define Ultrassonic_h

#include <Arduino.h>

#define ERRO -1
#define CENTIMETRO 0
#define POLEGADA 1
#define PALMO 2
#define PE 3
#define JARDA 4
#define METRO 5

class Ultrassonic {
public:
    Ultrassonic(int trig, int echo);

    int getDistancia();
    float getDistancia(int unidade);
    float converter(float val, int de, int para);

private:
    int _trig;
    int _echo;
    float _tempo;
    float _dist;
};

#endif
