#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "canion.h"

class CanionOfensivo: public Canion
{
private:
    Bala *apoyo;
public:
    CanionOfensivo();
    bool simularDispOfensivo(float angle,Bala balaE);
    void disparoOfensivo();
};

#endif // CANIONOFENSIVO_H
