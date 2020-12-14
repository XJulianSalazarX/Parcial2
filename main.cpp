#include <iostream>
#include <caniondefensivo.h>
#include <canionofensivo.h>
#include<stdlib.h>
#include<time.h>

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

    cout << "Seleccione:" << endl;
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
            //posición del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(0);

            //posición del cañon defensivo
            defensivo->setPosx(500);
            defensivo->setPosy(100);

            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());

            //ciclo que finaliza  una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){

               //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;

                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){

                    cout << "\nSimulacion " << i+1 << ": " << endl;
                    ofensivo->Datos(true,defensivo->getPosx(),defensivo->getPosy());
                    ofensivo->destruirBala();
                    i++;
                }
            }
        }
            break;
        case 2:{
            //posición del cañon ofensivo
            ofensivo->setPosx(100);
            ofensivo->setPosy(100);

            //posición del cañon defensivo
            defensivo->setPosx(800);
            defensivo->setPosy(100);

            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());

            //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){

               //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                angle = 91 + rand() % ((180) - 91);
                angle = angle*pi/180;

                if(defensivo->simularDisparo(angle,ofensivo->getPosx(),ofensivo->getPosy(),0.025)){

                    cout << "\nSimulacion " << i+1 << ": " << endl;
                    defensivo->Datos(true,ofensivo->getPosx(),ofensivo->getPosy());
                    defensivo->destruirBala();
                    i++;
                }
            }
        }
            break;
        case 3:{
            //posición del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(100);

            //posición del cañon defensivo
            defensivo->setPosx(1000);
            defensivo->setPosy(100);

            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());

            //generar un disparo ofensivo efectivo
            while(true){

                //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;

                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
                    cout << "\nTiro hecho por el canion ofensivo:" << endl;
                    ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
                    break;
                }
            }

            //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){

                //generar numeros de manera aleatorio entre 91 y 180 que representan el angulo
                 angle = 91 + rand() % ((180) - 91);
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
            break;
        case 4:{

            //posición del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(50);

            //posición del cañon defensivo
            defensivo->setPosx(900);
            defensivo->setPosy(100);

            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());

            //generar un disparo ofensivo efectivo
            while(true){

                //generar numeros de manera aleatorio entre 91 y 180 que representan el angulo
                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;

                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
                    cout << "\nTiro hecho por el canion ofensivo:" << endl;
                    ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
                    break;
                }
            }

            //ciclo que finaliza una vez se hayan generado tres disparos de manera efectiva
            for(short i=0;i<3;){

                //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                 angle = 91 + rand() % ((180) - 91);
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
            break;
        case 5:{
            //posición del cañon ofensivo
            ofensivo->setPosx(0);
            ofensivo->setPosy(300);

            //posición del cañon defensivo
            defensivo->setPosx(500);
            defensivo->setPosy(200);

            //distancia entre los dos cañones
            ofensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());
            defensivo->setDistance(defensivo->getPosx()-ofensivo->getPosx());

            while(true){

                angle = 1 + rand() % ((90) - 1);
                angle = angle*pi/180;

                if(ofensivo->simularDisparo(angle,defensivo->getPosx(),defensivo->getPosy(),0.05)){
                    cout << "\nTiro hecho por el canion ofensivo:" << endl;
                    ofensivo->Datos(false,defensivo->getPosx(),defensivo->getPosy());
                    break;
                }
            }
            //generar un disparo defensivo efectivo
            while(true){

                //generar numeros de manera aleatorio entre 1 y 89 que representan el angulo
                 angle = 91 + rand() % ((180) - 91);
                 angle = angle*pi/180;

                 if(defensivo->simularDispDefensivo2(angle,ofensivo->copyBala())){
                     cout << "\nTiro hecho por el canion defensivo:" << endl;
                     defensivo->Informe(false);
                     break;
                 }
            }

            short flag = 0;
            for(angle=0;angle<90;angle++){

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
            break;
        default:
            cout << "Opcion no valida." << endl;

        }
        cout << "Seleccione:" << endl;
        cout << "1. Probar caso 1." << endl;
        cout << "2. Probar caso 2." << endl;
        cout << "3. Probar caso 3." << endl;
        cout << "4. Probar caso 4." << endl;
        cout << "5. Probar caso 5." << endl;
        cout << "0. salir." << endl;
        cout << "Eliga una opcion: ";cin >> opc;
    }
    delete defensivo;
    delete ofensivo;
    return 0;
}
