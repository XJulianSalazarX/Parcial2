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
    void balaApoyo(bool objetivo);
    void informe(bool objetivo);
};

#endif // CANIONOFENSIVO_H
