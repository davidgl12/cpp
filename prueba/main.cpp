#include <iostream>
#include <string>

using namespace std;


//5, 3,  9 , 10, 6, 8, 1
void quicksortAsc(int *vec, int izq, int der)
{
    int i,j,pivote,aux;
    i = izq;
    j = der;
    pivote = vec[(izq+der)/2];

    do
    {

    //SE BUSCA UBICAR A LOS DATOS MENORES A LA IZQ
        while (vec[i] < pivote && i < der)
        {
            i++;
        }
   //SE BUSCA UBICAR A LOS DATOS MAYORES A LA DER
        while (vec[j] > pivote && j > izq)
        {
            j--;
        }
        if(i <= j)
        {
           aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            i++;
            j--;
        }
    }while(i <=j);

     if(izq < j)
        quicksortAsc(vec,izq,j);
    if(i < der)
        quicksortAsc(vec,i,der);
}

int main(){

    int vec[] = {5,3,9,10,6,8,1};

    quicksortAsc(vec, 0, 6);

    for(int i = 0; i < 7; i++)
        cout << vec[i] << endl;

    return 0;
}

