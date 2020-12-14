#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include "canion.h"

class CanionDefensivo: public Canion
{

public:
    //constructor
    CanionDefensivo();

    //simular un disparo de defensa
    bool simularDispDefensivo(float angle,Bala balaE);
    //simular un disparo de defensa cuidando la integridad del cañon ofensivo
    bool simularDispDefensivo2(float angle,Bala balaE);
    //imprimir parametros de salida de la ma
    void disparoOfensivo();
    //mostar parametros de salida de la bala e informacion de la bala
    void Informe(bool objetivo);
};

#endif // CANIONDEFENSIVO_H
