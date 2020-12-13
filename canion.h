#ifndef CANION_H
#define CANION_H
#include "bala.h"

class Canion
{
protected:
    float posx,posy,distance;
    Bala *bala;
public:
    Canion();
    bool simularDisparo(float angle,float x,float y);
    void generarDisparo();
};

#endif // CANION_H
