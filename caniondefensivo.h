#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include "canion.h"

class CanionDefensivo: public Canion
{
public:
    CanionDefensivo();
    bool simularDispDefensivo(float angle,float x,float y);
    bool simularDispDefensivo2(float angle,float x,float y);
    void disparoOfensivo();
};

#endif // CANIONDEFENSIVO_H
