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
};

#endif // BALA_H
