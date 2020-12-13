#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "canion.h"
#include "caniondefensivo.h"

class CanionOfensivo: public Canion
{
public:
    CanionOfensivo();
    bool simularDispOfensivo(float angle,Bala balaE);
    void disparoOfensivo();
};

#endif // CANIONOFENSIVO_H
