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
                cout << "ERROR.\nlas cordenadas deben ser positivas.\n"
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
                cout << "ERROR.\nlas cordenadas deben ser positivas.\n"
                "la altura maxima de los caiones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 3000.\n";

        }
            break;
        case 3:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispDeDefensa();
            }
            else
                cout << "ERROR.\nlas cordenadas deben ser positivas.\n"
                "la altura maxima de los caniones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 3000.\n";
        }
            break;
        case 4:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarTresDispdeDefensa2();
            }
            else
                cout << "ERROR.\nlas cordenadas deben ser positivas.\n"
                "la altura maxima de los caniones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 3000.\n";
        }
            break;
        case 5:{
            PedirDatos();
            if(comprobarDistancia()){
                GenerarDispApoyoOfensivo();
            }
            else
                cout << "ERROR.\nlas cordenadas deben ser positivas.\n"
                "la altura maxima de los caniones es de 1000 m.\n"
                " y la distancia entre ambos caniones debe ser >= 500 y <= 3000.\n";
        }
            break;
        default:
            cout << "Opcion no valida.\n";

        }
        cout << endl;
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
    defensivo->setPosy(num);
}

bool Simulacion::comprobarDistancia()
{

    if(defensivo->getPosy()>1000 or defensivo->getPosy()>1000)
        return false;
    else if(abs(defensivo->getPosx()-ofensivo->getPosx())>3000 or abs(defensivo->getPosx()-ofensivo->getPosx())<500)
        return false;
    else if(ofensivo->getPosy()<0 or ofensivo->getPosx()<0 or defensivo->getPosy()<0 or defensivo->getPosx()<0)
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

void Simulacion::GenerarTresDispDeDefensa()
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

    //generar un disparo ofensivo efectivo
    while(true){

        //generar numeros de manera aleatorio que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
            cout << "\nTiro hecho por el canion ofensivo:" << endl;
            ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
            break;
        }
    }

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

        //generar numeros de manera aleatorio entre 91 y 180 que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;
        if(defensivo->simularDispDefensivo(angle,ofensivo->copyBala())){
            cout << "Simulacion de defensa " << i+1 << ": " << endl;
            defensivo->Informe(true);
            defensivo->destruirBala();
            i++;
        }
    }
    ofensivo->destruirBala();
}

void Simulacion::GenerarTresDispdeDefensa2()
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

    while(true){

        //generar numeros de manera aleatorio entre 91 y 180 que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
            cout << "\nTiro hecho por el canion ofensivo:" << endl;
            ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
            break;
        }
    }

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

        //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(defensivo->simularDispDefensivo2(angle,ofensivo->copyBala())){
            cout << "Simulacion de defensa " << i+1 << ": " << endl;
            defensivo->Informe(true);
            defensivo->destruirBala();
            i++;
        }
    }
    ofensivo->destruirBala();
}

void Simulacion::GenerarDispApoyoOfensivo()
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

    while(true){

        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
            cout << "\nTiro hecho por el canion ofensivo:" << endl;
            ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
            break;
        }
    }

    //rango de los angulos
    if(ofensivo->getPosx()<defensivo->getPosx()){
        a_menor = 91;
        a_mayor = 180;
    }
    else{
        a_menor = 1;
        a_mayor = 90;
    }

    //generar un disparo defensivo efectivo
    while(true){

        //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
        angle = a_menor + rand() % ((a_mayor) - a_menor);
        angle = angle*pi/180;

        if(defensivo->simularDispDefensivo2(angle,ofensivo->copyBala())){
            cout << "\nTiro hecho por el canion defensivo:" << endl;
            defensivo->Informe(false);
            break;
        }
    }

    //rango de los angulos
    if(ofensivo->getPosx()<defensivo->getPosx()){
        a_menor = 1;
        a_mayor = 90;
    }
    else{
        a_menor = 91;
        a_mayor = 180;
    }

    short flag = 0;
    for(angle=a_menor;angle<a_mayor;angle++){

        angle = angle*pi/180;

        if(ofensivo->simularDispOfensivo(angle,defensivo->copyBala())){
            cout << "\nSimulacion de defender bala ofensiva " << flag+1 << ":\n" << endl;
            ofensivo->informe(true);
            flag ++;
        }
        angle= angle*180/pi;
        if(flag==3) break;
    }
    if(flag == 0)
        cout << "Error.\n la bala del canion defensivo no puede ser detenina.\n" << endl;

    else if(flag < 3){
        cout << "Error.\n la bala del canion defensivo solo pudo ser detenida: " << flag << " veces.\n";
        cout << endl;
    }
    ofensivo->destruirBala();
    defensivo->destruirBala();
}
