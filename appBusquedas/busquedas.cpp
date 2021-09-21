#include "busquedas.h"

Busqueda::Busqueda(){

}

void Busqueda::secuencialDatosNoOrdenados(int *vec, int n, int dato, int &p){
/**/
    p = -1;
    int i = 0;
    cout << "direccion de p: "<< &p<<endl;
    while(p == -1 && i < n)
            {
                if(vec[i] == dato)
                {
                    p = i;
                }
                i++;
            }
}

void Busqueda::secuencialDatosOrdenados(int *vec, int n, int dato, int &p){

}
