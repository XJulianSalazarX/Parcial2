#include "canionofensivo.h"

CanionOfensivo::CanionOfensivo()
{

}

CanionOfensivo::~CanionOfensivo()
{
    delete bala;
    delete apoyo;

}

bool CanionOfensivo::simularDispOfensivo(float angle,Bala balaE)
{
    Bala *copy_bala = new Bala(balaE);
    //datos para bala enemiga
    float xE,yE,VxE,VyE;
    //daatos para bala ya disparada
    float xA,yA,VxA,VyA;
    //datos bala a disparar
    float x,y,Vx,Vy;
    apoyo = new Bala(*bala);
    //radio de impacto de la bala
    apoyo->setRadio(0.005*distance);

    //velocidad inicail de la vala enemiga
    VxE = copy_bala->getV_inicial()*cos(copy_bala->getAngulo());
    VyE = copy_bala->getV_inicial()*sin(copy_bala->getAngulo());

    //velocidad inicail de la vala lanzada
    VxA = bala->getV_inicial()*cos(bala->getAngulo());
    VyA = bala->getV_inicial()*sin(bala->getAngulo());

    for(apoyo->setV_inicial(100);apoyo->getV_inicial()<=500;apoyo->setV_inicial(apoyo->getV_inicial()+1)){

        Vx = apoyo->getV_inicial()*cos(angle);
        Vy = apoyo->getV_inicial()*sin(angle);

        copy_bala->setTiempo(1);
        bala->setTiempo(3);
        for(apoyo->setTiempo(0);apoyo->getTiempo()<=100;apoyo->setTiempo(apoyo->getTiempo()+0.5)){

           //poscion bala a disparar
           x = posx + Vx * apoyo->getTiempo();
           y = posy + Vy*apoyo->getTiempo() - (0.5*apoyo->getG()*apoyo->getTiempo()*apoyo->getTiempo());

           //poscion bala enemiga
           xE = copy_bala->getPosx() + VxE*copy_bala->getTiempo();
           yE = copy_bala->getPosy() + VyE*copy_bala->getTiempo() -(0.5*copy_bala->getG()*copy_bala->getTiempo()*copy_bala->getTiempo());

           //poscion bala aliada lanzada
           xA = posx + VxA * bala->getTiempo();
           yA = posy + VyA*bala->getTiempo() - (0.5*bala->getG()*bala->getTiempo()*bala->getTiempo());

           if(sqrt(pow((xA-xE),2)+pow((yA-yE),2))<=copy_bala->getRadio()){
               break;
           }

           else if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=apoyo->getRadio() and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>copy_bala->getRadio()){
               if(y>0 and sqrt(pow((x-xA),2)+pow((y-yA),2))>apoyo->getRadio()){
                   apoyo->setAngulo(angle);
                   delete copy_bala;
                   return true;
               }
           }
           copy_bala->setTiempo(copy_bala->getTiempo()+0.5);
           bala->setTiempo(bala->getTiempo()+0.5);
        }
    }
    delete apoyo;
    delete copy_bala;
    return false;
}

void CanionOfensivo::disparoOfensivo()
{
    cout << endl;
    cout << "cordenadas canion ofensivo: ("<<posx<<","<<posy<<")"<<endl;
    cout << "Velocidad inical de la bala: "<<apoyo->getV_inicial()<<" m/s"<<endl;
    cout << "angulo de disparo: " << apoyo->getAngulo()*180/pi<< endl;
    cout << "tiempo en el que se estima la bala detode "<<apoyo->getTiempo()<<" seg."<<endl;
    cout << endl;
}

void CanionOfensivo::balaApoyo(bool objetivo)
{
    if(objetivo){
        cout << "Tiempo en el que detona la bala: " << apoyo->getTiempo() << " seg." << endl;
        cout << "Cordenadas de detonacion: ("<<posx+apoyo->getV_inicial()*cos(apoyo->getAngulo())*apoyo->getTiempo()<<","<<
                posy+apoyo->getV_inicial()*sin(apoyo->getTiempo())*apoyo->getTiempo()-(0.5*apoyo->getG()*apoyo->getTiempo()*apoyo->getTiempo())<<")"<<endl;
        cout << "...Objetivo conseguido..." << endl;
        cout << endl;
    }
    else{
        cout << "...La bala ha sido destruida..." << endl;
        cout << "...Objetivo NO conseguido..." << endl;
        cout << endl;
    }
}

void CanionOfensivo::informe(bool objetivo)
{
    cout << endl;
    cout << "-------------- Parametros segunda bala ofensiva --------------" << endl;
    disparoOfensivo();
    cout << "------------------ Resultados de la bala ------------------" << endl;
    balaApoyo(objetivo);

    delete apoyo;
}
