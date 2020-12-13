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
    bala->setDistance(value);
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
    bala->setPosx(value);
}

float Canion::getPosy() const
{
    return posy;
}

void Canion::setPosy(float value)
{
    posy = value;
    bala->setPosy(value);
}

void Canion::generarDisparo(float x_,float y_)
{
    cout << endl;
    cout << "cordenadas canion que ataca: ("<<posx<<","<<posy<<")"<<endl;
    cout << "cordenadas canion que defiende: ("<<x_<<","<<y_<<")"<<endl;
    cout << "Velocidad inical de la bala: "<<bala->getV_inicial()<<" m/s"<<endl;
    cout << "angulo de disparo:" << bala->getAngulo()*180/pi << endl;
    cout << "tiempo en el que la bala detona: "<<bala->getTiempo()<<" seg."<<endl;
    cout << endl;
}

bool Canion::simularDisparo(float angle, float x_, float y_)
{
    float Vx=0,Vy=0,x,y;
    //for(Vo=50;Vo<=500;Vo++){
    for(bala->setV_inicial(50);bala->getV_inicial()<350;bala->setV_inicial(bala->getV_inicial()+1)){
        Vx = bala->getV_inicial()*cos(angle);
        Vy = bala->getV_inicial()*sin(angle);
        //for(float t=0;t<100;t++){
        for(bala->setTiempo(0);bala->getTiempo()<=100;bala->setTiempo(bala->getTiempo()+0.5)){
            x = posx + Vx * bala->getTiempo();
            y = posy + Vy*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());
            if(sqrt(pow((x-x_),2)+pow((y-y_),2)) <= bala->getRadio()){
                bala->setAngulo(angle);
                return true;
            }
        }
    }
    return false;
}

void Canion::radioDestruccion(float radio_)
{
    bala->setRadio(radio_);
}

