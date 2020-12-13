#include "bala.h"

float Bala::getDistance() const
{
    return distance;
}

void Bala::setDistance(float value)
{
    distance = value;
}

float Bala::getRadio() const
{
    return radio;
}

void Bala::setRadio(float value)
{
    radio = value;
}

float Bala::getG() const
{
    return g;
}

float Bala::getV_inicial() const
{
    return V_inicial;
}

void Bala::setV_inicial(float value)
{
    V_inicial = value;
}

float Bala::getAngulo() const
{
    return angulo;
}

void Bala::setAngulo(float value)
{
    angulo = value;
}

float Bala::getPosx() const
{
    return posx;
}

void Bala::setPosx(float value)
{
    posx = value;
}

float Bala::getPosy() const
{
    return posy;
}

void Bala::setPosy(float value)
{
    posy = value;
}

float Bala::getTiempo() const
{
    return tiempo;
}

void Bala::setTiempo(float value)
{
    tiempo = value;
}

Bala::Bala()
{
    g = 9.81;
}