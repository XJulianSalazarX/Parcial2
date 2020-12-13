#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "canion.h"

class CanionOfensivo: public Canion
{
public:
    CanionOfensivo();
    bool simularDispOfensivo(float angle,float x,float y);
    void disparoOfensivo();
};

#endif // CANIONOFENSIVO_H
