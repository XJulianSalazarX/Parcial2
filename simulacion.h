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

    //pedir al usuario que simulacion quiere realizar
    void Menu();
    //pedir las coordenadas de los caniones
    void PedirDatos();
    //comprobar que las distancas se encuentren entre los rangos
    bool comprobarDistancia();

    //generar tres disparos efenctivos cañon ofensivo
    void GenerarTresDispOfensivos();
    //generar tres disparos efenctivos cañon defensivo
    void GenerarTresDispDefensivos();
    //generar un disparo ofensivo y tres de defensa
    void GenerarTresDispDeDefensa();
    //generar un disparo ofensivo y tres de defensa sin comprometer el cañon ofensivo
    void GenerarTresDispdeDefensa2();
    //generar un disparo ofensivo, udo defensivo y tres disparos que neutralicen el disparo defensivo
    void GenerarDispApoyoOfensivo();
private:
    CanionOfensivo *ofensivo;
    CanionDefensivo *defensivo;

    short opc;
    float angle;
    int a_menor,a_mayor;
};

#endif // SIMULACION_H
