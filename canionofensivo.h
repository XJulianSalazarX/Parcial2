#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "canion.h"

class CanionOfensivo: public Canion
{
private:
    Bala *apoyo;
public:
    //constructor
    CanionOfensivo();
    //destructor
    ~CanionOfensivo();

    //simullar un disparo para derribar la bala del cañon defensivo
    bool simularDispOfensivo(float angle,Bala balaE);
    //parametos de salida de la bala "apoyo"
    void disparoOfensivo();
    //datos de la bala "apoyo"
    void balaApoyo(bool objetivo);
    //mostar parametros de salida de la bala "apoyo" e informacion de la bala "apoyo"
    void informe(bool objetivo);
};

#endif // CANIONOFENSIVO_H
