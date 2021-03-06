#ifndef BALA_H
#define BALA_H
#include <iostream>
#include <math.h>

#define pi 3.14159265358979323846

using namespace std;

class Bala
{
private:
    float V_inicial,angulo,posx,posy,distance,radio,tiempo,g;
public:
    //constructores
    Bala();

    Bala(float posx_,float posy_,float distance_, float radio_);

    //mostrar en consola datos de la bala
    void Datos(bool objetivo);

    //funciones getter and setter
    float getDistance() const;
    void setDistance(float value);
    float getRadio() const;
    void setRadio(float value);
    float getG() const;
    float getV_inicial() const;
    void setV_inicial(float value);
    float getAngulo() const;
    void setAngulo(float value);
    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
    float getTiempo() const;
    void setTiempo(float value);
};

#endif // BALA_H
