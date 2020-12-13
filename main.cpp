#include <iostream>
#include <caniondefensivo.h>
#include <canionofensivo.h>

using namespace std;

int main()
{
    //instancia de la clase CanionOfensivo
    CanionOfensivo *ofensivo = new CanionOfensivo();
    //instancia de la clase CanionDefensivo
    CanionDefensivo *defensivo = new CanionDefensivo();
    short opc=0;
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

        }
            break;
        case 2:{

        }
            break;
        case 3:{

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
