#ifndef SIMULACION_H
#define SIMULACION_H
#include <caniondefensivo.h>
#include <canionofensivo.h>
#include<stdlib.h>
#include<time.h>

class Simulacion
{
public:
    Simulacion(); //constructor
    ~Simulacion(); //destructor

    void Menu();
    void PedirDatos();
    bool comprobarDistancia();

    void GenerarTresDispOfensivos();
    void GenerarTresDispDefensivos();
    void GenerarTresDispDeDefensa();
    void GenerarTresDispdeDefensa2();
    void GenerarDispApoyoOfensivo();
private:
    CanionOfensivo *ofensivo;
    CanionDefensivo *defensivo;

    short opc;
    float angle;
    int a_menor,a_mayor;
};

#endif // SIMULACION_H
