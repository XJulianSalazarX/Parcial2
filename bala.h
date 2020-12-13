#ifndef BALA_H
#define BALA_H
#include <math.h>

class Bala
{
private:
    float V_inicial,angulo,posx,posy,distance,radio,tiempo,g;
public:
    Bala();
    void Disparar();
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
