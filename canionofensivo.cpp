#include "canionofensivo.h"

CanionOfensivo::CanionOfensivo()
{
    bala = new Bala();
}

bool CanionOfensivo::simularDispOfensivo(float angle,Bala balaE)
{
    Bala *copy_bala = new Bala(balaE);
    Bala *Bsoporte = new Bala();
    Bsoporte->setPosx(posx);
    Bsoporte->setPosy(posy);

    //datos para bala enemiga
    float xE,yE,VxE,VyE;
    //daatos para bala ya disparada
    float xA,yA,VxA,VyA;
    //datos bala a disparar
    float x,y,Vx,Vy;

    //velocidad inicail de la vala enemiga
    VxE = copy_bala->getV_inicial()*cos(copy_bala->getAngulo());
    VyE = copy_bala->getV_inicial()*sin(copy_bala->getAngulo());

    //velocidad inicail de la vala lanzada
    VxA = bala->getV_inicial()*cos(bala->getAngulo());
    VyA = bala->getV_inicial()*sin(bala->getAngulo());

    //radio de impacto de la bala
    Bsoporte->setRadio(0.005*distance);

    //Buscar disparo que destruya la bala del enemigo
    for(Bsoporte->setV_inicial(50);Bsoporte->getV_inicial()<500;Bsoporte->setV_inicial(bala->getV_inicial()+1)){

        Vx = Bsoporte->getV_inicial()*cos(angle);
        Vy = Bsoporte->getV_inicial()*sin(angle);

        bala->setTiempo(3);
        copy_bala->setTiempo(1);
        for(Bsoporte->setTiempo(0);Bsoporte->getTiempo()<=100;Bsoporte->setTiempo(Bsoporte->getTiempo()+0.5)){

            //posicion bala a disparar
            x = posx + Vx * Bsoporte->getTiempo();
            y = posy + Vy*Bsoporte->getTiempo() - (0.5*Bsoporte->getG()*Bsoporte->getTiempo()*Bsoporte->getTiempo());

            //poscion bala aliada lanzada
            xA = posx + Vx * bala->getTiempo();
            yA = posy + Vy*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());
            //posicion bala enemiga
            xE = copy_bala->getPosx() + VxE*copy_bala->getTiempo();
            yE = copy_bala->getPosy() + VyE*copy_bala->getTiempo() -(0.5*copy_bala->getG()*copy_bala->getTiempo()*copy_bala->getTiempo());

            if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=Bsoporte->getRadio() and sqrt(pow((x-xA),2)+pow((y-yA),2))>Bsoporte->getRadio()){
                if(y>0){
                Bsoporte->setAngulo(angle);
                return true;
                }
            }
            bala->setTiempo(bala->getTiempo()+0.5);
            copy_bala->setTiempo(copy_bala->getTiempo()+0.5);
        }
    }

    return false;
}

void CanionOfensivo::disparoOfensivo()
{
    cout << endl;
    cout << "cordenadas canion que ataca: ("<<posx<<","<<posy<<")"<<endl;
    cout << "Velocidad inical de la bala: "<<bala->getV_inicial()<<" m/s"<<endl;
    cout << "Aqui va el angulo........" << endl;
    cout << "tiempo en el que la bala detona: "<<bala->getTiempo()<<" seg."<<endl;
    cout << endl;
}
