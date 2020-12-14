#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include "canion.h"

class CanionDefensivo: public Canion
{

public:
    CanionDefensivo();
    bool simularDispDefensivo(float angle,Bala balaE);
    bool simularDispDefensivo2(float angle,Bala balaE);
    void disparoOfensivo();
    void Informe(bool objetivo);
};

#endif // CANIONDEFENSIVO_H
