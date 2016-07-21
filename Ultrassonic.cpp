/*
  Ultrassonic.cpp - Biblioteca para uso no sensor ultrassonico HC-SR04.
  Escrito por Francisco T. R. Sousa, 29 de dezembro de 2015.
*/

#include "Ultrassonic.h"

Ultrassonic :: Ultrassonic(int trig, int echo) {
    _trig = trig;
    _echo = echo;

    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW);
}

int Ultrassonic :: getDistancia() {
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    _tempo = pulseIn(_echo, HIGH);
    _dist = _tempo / 29.4 / 2;

    return _dist;
}

float Ultrassonic :: getDistancia(int unidade) {
    if (unidade == CENTIMETRO) {
    	digitalWrite(_trig, HIGH);
	    delayMicroseconds(10);
	    digitalWrite(_trig, LOW);

	    _tempo = pulseIn(_echo, HIGH);
	    _dist = _tempo / 29.4 / 2.0;

	    return _dist;
    }
    else if (unidade == POLEGADA) {
        return getDistancia(CENTIMETRO) / 2.54;
    }
    else if (unidade == PALMO) {
        return getDistancia(CENTIMETRO) / 22.86;
    }
    else if (unidade == PE) {
        return getDistancia(CENTIMETRO) / 30.48;
    }
    else if (unidade == JARDA) {
        return getDistancia(CENTIMETRO) / 91.44;
    }
    else if (unidade == METRO) {
        return getDistancia(CENTIMETRO) / 100.00;
    }
    else {
        return ERRO;
    }
}

float Ultrassonic :: converter(float val, int de, int para) {
    if (de == para) {
        return val;
    }
    else {
        switch (de) {
        	case CENTIMETRO:
	            if (para == POLEGADA) {
	                return val / 2.54;
	            }
	            else if (para == PALMO) {
	                return val / 22.86;
	            }
	            else if (para == PE) {
	                return val / 30.48;
	            }
	            else if (para == JARDA) {
	                return val / 91.44;
	            }
	            else if (para == METRO) {
	                return val / 100.00;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        case POLEGADA:
	            if (para == CENTIMETRO) {
	                return val * 2.54;
	            }
	            else if (para == PALMO) {
	                return val / 9.00;
	            }
	            else if (para == PE) {
	                return val / 12.00;
	            }
	            else if (para == JARDA) {
	                return val / 36.00;
	            }
	            else if (para == METRO) {
	                return val / 39.3701;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        case PALMO:
	            if (para == CENTIMETRO) {
	                return val * 22.86;
	            }
	            else if (para == POLEGADA) {
	                return val * 9.00;
	            }
	            else if (para == PE) {
	                return val * 0.75;
	            }
	            else if (para == JARDA) {
	                return val * 0.25;
	            }
	            else if (para == METRO) {
	                return val * 0.2286;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        case PE:
	            if (para == CENTIMETRO) {
	                return val * 30.48;
	            }
	            else if (para == POLEGADA) {
	                return val * 12.00;
	            }
	            else if (para == PALMO) {
	                return val / 0.75;
	            }
	            else if (para == JARDA) {
	                return val / 3.00;
	            }
	            else if (para == METRO) {
	                return val * 0.3048;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        case JARDA:
	            if (para == CENTIMETRO) {
	                return val * 91.44;
	            }
	            else if (para == POLEGADA) {
	                return val * 36.00;
	            }
	            else if (para == PALMO) {
	                return val * 4.00;
	            }
	            else if (para == PE) {
	                return val * 3.00;
	            }
	            else if (para == METRO) {
	                return val * 0.9144;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        case METRO:
	            if (para == CENTIMETRO) {
	                return val * 100.00;
	            }
	            else if (para == POLEGADA) {
	                return val / 0.0254;
	            }
	            else if (para == PALMO) {
	                return val / 0.2286;
	            }
	            else if (para == PE) {
	                return val / 0.3048;
	            }
	            else if (para == JARDA) {
	                return val / 0.9144;
	            }
	            else {
	                return ERRO;
	            }
	            break;

	        default:
	            return ERRO;
        }
    }
}