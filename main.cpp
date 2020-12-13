#include <iostream>
#include <caniondefensivo.h>
#include <canionofensivo.h>
#include<stdlib.h>
#include<time.h>

//#define pi 3.14159265358979323846
using namespace std;

int main()
{
    //instancia de la clase CanionOfensivo
    CanionOfensivo *ofensivo = new CanionOfensivo();
    //instancia de la clase CanionDefensivo
    CanionDefensivo *defensivo = new CanionDefensivo();
    short opc=0;
    float angle = 0;
    srand(time(NULL));
    cout << "Seliccione:" << endl;
    cout << "1. Probar caso 1." << endl;
    cout << "2. Probar caso 2." << endl;
    cout << "3. Probar caso 3." << endl;
    cout << "4. Probar caso 4." << endl;
    cout << "5. Probar caso 5." << endl;
    cout << "0. salir." << endl;
    cout << "Eliga una opcion: ";cin >> opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            //posicon del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(0);
            //poscion del cañon defensivo
            defensivo->setPosx(500);
            defensivo->setPosy(100);
            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            //radio de destruccion cañon ofensivo
            ofensivo->radioDestruccion(ofensivo->getDistance()*0.05);
            //ciclo que finaliza  una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){
               //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;
                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy())){
                    ofensivo->generarDisparo(defensivo->getPosx(),defensivo->getPosy());
                    i++;
                }
            }
        }
            break;
        case 2:{
            //posicon del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(100);
            //poscion del cañon defensivo
            defensivo->setPosx(1000);
            defensivo->setPosy(100);
            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            //radio de destruccion cañon defensivo
            defensivo->radioDestruccion(defensivo->getDistance()*0.025);
            //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){
               //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                angle = 91 + rand() % ((180) - 91);
                angle = angle*pi/180;
                if(defensivo->simularDisparo(angle,ofensivo->getPosx(),ofensivo->getPosy())){
                    defensivo->generarDisparo(ofensivo->getPosx(),ofensivo->getPosy());
                    i++;
                }
            }

        }
            break;
        case 3:{
            //posicon del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(100);
            //poscion del cañon defensivo
            defensivo->setPosx(1000);
            defensivo->setPosy(100);
            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            //radio de destruccion cañon defensivo y ofensivo
            defensivo->radioDestruccion(defensivo->getDistance()*0.025);
            ofensivo->radioDestruccion(ofensivo->getDistance()*0.05);
            //generar un disparo ofensivo
            while(true){
                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;
                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy())){
                    ofensivo->generarDisparo(defensivo->getPosx(),defensivo->getPosy());
                    break;
                }
            }
            //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){
                //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                 angle = 91 + rand() % ((180) - 91);
                 angle = angle*pi/180;
                 if(defensivo->simularDispDefensivo(angle,ofensivo->copyBala())){
                     defensivo->disparoOfensivo();
                     i++;
                 }
            }


        }
            break;
        case 4:{

        }
            break;
        case 5:{

        }
            break;
        default:
            cout << "Opcion no valida." << endl;

        }
        cout << "Seliccione:" << endl;
        cout << "1. Probar caso 1." << endl;
        cout << "2. Probar caso 2." << endl;
        cout << "3. Probar caso 3." << endl;
        cout << "4. Probar caso 4." << endl;
        cout << "5. Probar caso 5." << endl;
        cout << "0. salir." << endl;
        cout << "Eliga una opcion: ";cin >> opc;
    }
    return 0;
}
