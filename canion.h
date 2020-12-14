#ifndef CANION_H
#define CANION_H
#include "bala.h"

class Canion
{
protected:
    float posx,posy,distance;
    Bala *bala;
public:
    //constructor
    Canion();
    //simular un disparo hacia el objetivo x, y
    bool simularDisparo(float angle,float x,float y,float radio_);
    //mostrar parametros de salida de la bala
    void generarDisparo(float x_,float y_);
    //delete bala
    void destruirBala();
    //mostar parametros de salida de la bala e informacion de la bala
    void Datos(bool objetivo,float x_,float y_);

    //funciones getter and setter
    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
    float getDistance() const;
    void setDistance(float value);

    //retorna bala
    Bala copyBala();
};

#endif // CANION_H
