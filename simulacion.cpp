#include "simulacion.h"

Simulacion::Simulacion()
{
    //instancia de la clase CanionOfensivo
    ofensivo = new CanionOfensivo();
    //instancia de la clase CanionDefensivo
    defensivo = new CanionDefensivo();
}

Simulacion::~Simulacion()
{
    delete ofensivo;
    delete defensivo;
}

void Simulacion::Menu()
{
    srand(time(NULL));
    opc= 0;
    angle = 0;

    cout << "Seleccione:" << endl;
    cout << "1. Generar tres disparos canion ofensivo." << endl;
    cout << "2. Generar tres disparos canion defensivo." << endl;
    cout << "3. Generar tres disparos de defensa." << endl;
    cout << "4. Generar tres disparos de defensa que no destruya el canion ofensivo." << endl;
    cout << "5. Generar tres disparos para evitar que la bala ofensiva sea destruida." << endl;
    cout << "0. salir." << endl;
    cout << "Eliga una opcion: ";cin >> opc;

    while(opc!=0){
        switch (opc) {
        case 1:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispOfensivos();
            }
            else
                cout << "las cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 10000.\n";

        }
            break;
        case 2:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispDefensivos();
            }
            else
                cout << "las cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 10000.\n";

        }
            break;
        case 3:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispDeDefensa();
            }
            else
                cout << "las cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 10000.\n";
        }
            break;
        case 4:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispdeDefensa2();
            }
            else
                cout << "las cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 10000.\n";
        }
            break;
        case 5:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarDispApoyoOfensivo();
            }
            else
                cout << "las cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 10000.\n";
        }
            break;
        default:
            cout << "Opcion no valida.\n";

        }
        cout << "Seleccione:" << endl;
        cout << "1. Generar tres disparos canion ofensivo." << endl;
        cout << "2. Generar tres disparos canion defensivo." << endl;
        cout << "3. Generar tres disparos de defensa." << endl;
        cout << "4. Generar tres disparos de defensa que no destruya el canion ofensivo." << endl;
        cout << "5. Generar tres disparos para evitar que la bala ofensiva sea destruida." << endl;
        cout << "0. salir." << endl;
        cout << "Eliga una opcion: ";cin >> opc;
    }
}

void Simulacion::PedirDatos()
{
    float num;
    cout << "Ingrese la posicion x del canion ofensivo: ";
    cin >> num;
    ofensivo->setPosx(num);
    cout << "Ingrese la posicion y del canion ofensivo: ";
    cin >> num;
    ofensivo->setPosy(num);
    cout << "Ingrese la posicion x del canion defensivo: ";
    cin >> num;
    defensivo->setPosx(num);
    cout << "Ingrese la posicion y del canion defensivo: ";
    cin >> num;
    defensivo->setPosx(num);
}

bool Simulacion::comprobarDistancia()
{

    if(defensivo->getPosy()>1000 or defensivo->getPosy()>1000)
        return false;
    else if(abs(defensivo->getPosx()-ofensivo->getPosx())>10000 or abs(defensivo->getPosx()-ofensivo->getPosx())<500)
        return false;
    else if(defensivo->getPosy()<0 or defensivo->getPosy()<0 or defensivo->getPosy()<0 or defensivo->getPosy()<0)
            return false;

    return true;
}

void Simulacion::GenerarTresDispOfensivos()
{
    //distancia entre los dos cañones
    ofensivo->setDistance(abs(defensivo->getPosx()-ofensivo->getPosx()));
    defensivo->setDistance(abs(defensivo->getPosx()-ofensivo->getPosx()));

    //rango de los angulos
    if(ofensivo->getPosx()<defensivo->getPosx()){
        a_menor = 1;
        a_mayor = 90;
    }
    else{
        a_menor = 91;
        a_mayor = 180;
    }

    //ciclo que finaliza  una vez se hayan generado tres disparos de manera efectiva
    for(short i=0;i<3;){


       //generar numeros de manera aleatorio que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){

            cout << "\nSimulacion " << i+1 << ": " << endl;
            ofensivo->Datos(true,defensivo->getPosx(),defensivo->getPosy());
            ofensivo->destruirBala();
            i++;
        }
    }
}

void Simulacion::GenerarTresDispDefensivos()
{
    //distancia entre los dos cañones
    ofensivo->setDistance(abs(defensivo->getPosx()-ofensivo->getPosx()));
    defensivo->setDistance(abs(defensivo->getPosx()-ofensivo->getPosx()));

    //rango de los angulos
    if(ofensivo->getPosx()<defensivo->getPosx()){
        a_menor = 91;
        a_mayor = 180;
    }
    else{
        a_menor = 1;
        a_mayor = 90;
    }

    //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
    for(short i=0;i<3;){

        //generar numeros de manera aleatorio que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(defensivo->simularDisparo(angle,ofensivo->getPosx(),ofensivo->getPosy(),0.025)){

            cout << "\nSimulacion " << i+1 << ": " << endl;
            defensivo->Datos(true,ofensivo->getPosx(),ofensivo->getPosy());
            defensivo->destruirBala();
            i++;
        }
    }

}
