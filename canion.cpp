#include "canion.h"

Canion::Canion()
{

}

float Canion::getDistance() const
{
    return distance;
}

void Canion::setDistance(float value)
{
    distance = value;
}

Bala Canion::copyBala()
{
    return *bala;
}

float Canion::getPosx() const
{
    return posx;
}

void Canion::setPosx(float value)
{
    posx = value;
}

float Canion::getPosy() const
{
    return posy;
}

void Canion::setPosy(float value)
{
    posy = value;
}

bool Canion::simularDisparo(float angle, float x_, float y_,float radio_)
{

    bala = new Bala(posx,posy,distance,radio_);

    float Vx=0,Vy=0,x,y;

    for(bala->setV_inicial(50);bala->getV_inicial()<350;bala->setV_inicial(bala->getV_inicial()+1)){

        Vx = bala->getV_inicial()*cos(angle);
        Vy = bala->getV_inicial()*sin(angle);

        for(bala->setTiempo(0);bala->getTiempo()<=100;bala->setTiempo(bala->getTiempo()+0.5)){

            x = posx + Vx * bala->getTiempo();
            y = posy + Vy*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());

            if(sqrt(pow((x-x_),2)+pow((y-y_),2)) <= bala->getRadio()){

                bala->setAngulo(angle);
                return true;
            }
        }
    }
    delete bala;
    return false;
}

void Canion::generarDisparo(float x_,float y_)
{
    cout << "Cordenadas canion que ataca: ("<<posx<<","<<posy<<")"<<endl;
    cout << "Cordenadas del objetivo: ("<<x_<<","<<y_<<")"<<endl;
    cout << "Velocidad inical de la bala: "<<bala->getV_inicial()<<" m/s."<<endl;
    cout << "Angulo de disparo: " << bala->getAngulo()*180/pi << " grados." << endl;
    cout << "Tiempo en el que se espera que detone la bala: "<<bala->getTiempo()<<" seg."<<endl;
    cout << endl;
}

void Canion::Datos(bool objetivo,float x_,float y_)
{
    cout << endl;
    cout << "------------ Parametros de la salida de la bala ------------" << endl;
    generarDisparo(x_,y_);
    cout << "------------------ Resultados de la bala ------------------" << endl;
    bala->Datos(objetivo);



}

void Canion::destruirBala()
{
    delete bala;
}
