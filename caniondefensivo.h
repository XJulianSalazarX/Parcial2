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
};

#endif // CANIONDEFENSIVO_H
