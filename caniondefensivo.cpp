#include "caniondefensivo.h"

CanionDefensivo::CanionDefensivo()
{

}

CanionDefensivo::~CanionDefensivo()
{
    delete bala;
}

bool CanionDefensivo::simularDispDefensivo(float angle,Bala balaE)
{
    bala = new Bala(posx,posy,distance,0.025);
    Bala *copy_bala = new Bala(balaE);
    float Vx=0,Vy=0,x=0,y=0,xE=0,yE=0,VxE=0,VyE=0;

    //velocidad inicil de la vala enemiga
    VxE = copy_bala->getV_inicial()*cos(copy_bala->getAngulo());
    VyE = copy_bala->getV_inicial()*sin(copy_bala->getAngulo());

    for(bala->setV_inicial(50);bala->getV_inicial()<=350;bala->setV_inicial(bala->getV_inicial()+1)){

        Vx = bala->getV_inicial()*cos(angle);
        Vy = bala->getV_inicial()*sin(angle);

        for(bala->setTiempo(0),copy_bala->setTiempo(2);bala->getTiempo()<=100;bala->setTiempo(bala->getTiempo()+0.5),copy_bala->setTiempo(copy_bala->getTiempo()+0.5)){

           x = posx + Vx * bala->getTiempo();
           y = posy + Vy*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());
           xE = copy_bala->getPosx() + VxE*copy_bala->getTiempo();
           yE = copy_bala->getPosy() + VyE*copy_bala->getTiempo() -(0.5*copy_bala->getG()*copy_bala->getTiempo()*copy_bala->getTiempo());

           if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=bala->getRadio() and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>copy_bala->getRadio()){

               if(y>0){

                   bala->setAngulo(angle);
                   delete copy_bala;
                   return true;
               }
           }
        }
    }
    delete bala;
    delete copy_bala;
    return false;
}

bool CanionDefensivo::simularDispDefensivo2(float angle,Bala balaE)
{
    bala = new Bala(posx,posy,distance,0.025);
    Bala *copy_bala = new Bala(balaE);
    float Vx=0,Vy=0,x=0,y=0,xE,yE,VxE,VyE;

    //velocidad inicail de la vala enemiga
    VxE = copy_bala->getV_inicial()*cos(copy_bala->getAngulo());
    VyE = copy_bala->getV_inicial()*sin(copy_bala->getAngulo());

    for(bala->setV_inicial(50);bala->getV_inicial()<=350;bala->setV_inicial(bala->getV_inicial()+1)){

        Vx = bala->getV_inicial()*cos(angle);
        Vy = bala->getV_inicial()*sin(angle);

        for(bala->setTiempo(0),copy_bala->setTiempo(2);bala->getTiempo()<=100;bala->setTiempo(bala->getTiempo()+0.5),copy_bala->setTiempo(copy_bala->getTiempo()+0.5)){

           x = posx + Vx * bala->getTiempo();
           y = posy + Vy*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());
           xE = copy_bala->getPosx() + VxE*copy_bala->getTiempo();
           yE = copy_bala->getPosy() + VyE*copy_bala->getTiempo() -(0.5*copy_bala->getG()*copy_bala->getTiempo()*copy_bala->getTiempo());

           if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=bala->getRadio() and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>copy_bala->getRadio()){

               if(y>0 and sqrt(pow((x-copy_bala->getPosx()),2)+pow((y-copy_bala->getPosy()),2))>bala->getRadio()){

                   bala->setAngulo(angle);
                   delete copy_bala;
                   return true;
               }
           }
        }
    }
    delete bala;
    delete copy_bala;
    return false;
}

void CanionDefensivo::disparoOfensivo()
{
    cout << endl;
    cout << "cordenadas canion defensivo: ("<<posx<<","<<posy<<")"<<endl;
    cout << "Velocidad inical de la bala: "<<bala->getV_inicial()<<" m/s."<<endl;
    cout << "angulo de disparo:" << bala->getAngulo()*180/pi<< " angulos." << endl;
    cout << "Tiempo en el que se espera que detone la bala: "<<bala->getTiempo()<<" seg."<<endl;
    cout << endl;
}

void CanionDefensivo::Informe(bool objetivo)
{
    cout << endl;
    cout << "------------ Parametros de la bala defensiva ------------" << endl;
    disparoOfensivo();
    cout << "------------------ Resultados de la bala ------------------" << endl;
    bala->Datos(objetivo);
}
