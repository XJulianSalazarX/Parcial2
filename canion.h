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
    void generarDisparo(float x_,float y_);
    void radioDestruccion(float radio_);
    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
    float getDistance() const;
    void setDistance(float value);

    Bala copyBala();
};

#endif // CANION_H
