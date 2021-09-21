//#include <iostream>
//using namespace std;  ya están incluído en busquedas.h
#include <time.h>
#include <stdlib.h>

#include "busquedas.h"


int main()
{

    srand(time(NULL)); //generar semilla
    int tam = 7;//rand()%10+6;
    //int *vec = new int[tam];
    int vec[] = {20,30,21,15,9,13,83};

    cout<<"Valores en hexadecimal: "<<endl;
    for(int i=0; i < tam; i++){
        //vec[i] = rand() % 90 + 10;
        cout << "vec ["<<(i+1)<<"] "<<hex<<vec[i]<<dec<<endl;
    }

    cout<<"Valores en decimal: "<<endl;
    for(int i=0; i < tam; i++){
        //vec[i] = rand() % 90 + 10;
        cout << "vec ["<<(i+1)<<"] "<<vec[i]<<endl;
    }

    //Busquedas busqueda; //OBJETO ESTÁTICO
    //busqueda.secuencialDatosNoOrdenados();

    Busqueda *busqueda = new Busqueda();
    cout << "Dato a buscar: ";
    int x, pos;
    //cin >> x;
    x = 17;

    cout << "direccion de pos = " <<hex<<&pos<<endl;
    busqueda -> secuencialDatosNoOrdenados(vec,  tam, x, pos);

    if(pos != -1)
        cout << " Dato "<<x<<" se encuentra en posicion "<<(pos + 1)<<endl;
    else
        cout << "Dato no existe :c "<<endl;

    return 0;
}
