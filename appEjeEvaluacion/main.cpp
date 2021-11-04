#include <iostream>
#include <cstring>
using namespace std;

void aMayus(char *c){
    //for(int i = 0; c[i] != '\0'; i++){ Forma explícita
    for(int i = 0; c[i]; i++){ //Forma implícita, /0 equivale al valor de nulo
        char ch = c[i];
        int asc = int(ch);
        if(asc >= 97 && asc <= 122){ //if(ch >= 'a' && ch <= 'z')
            asc -= 32;
        }

        ch = asc;
        c[i] = ch;
    }
}
//1.- Realice las modificaciones necesarias al método Burbuja para que permita ordenar cadenas

void ordenarCadenas(char vec[][25], int n)
{
    int comp = 0;
    int interc = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            comp++;
            if (strcmp(vec[j], vec[j + 1]) > 0)
            {
                char aux[25];
                strcpy(aux, vec[j + 1]);
                strcpy(vec[j + 1], vec[j]);
                strcpy(vec[j], aux);
                interc++;
            }
        }
    }
    printf("\nNo. de Comparaciones : %d ",comp);
    printf("\nNo. de intercambios  : %d \n", interc);

}

//2.- Agregue un método para buscar una cadena. El método deberá devolver si o no lo encontró y en caso de encontrarlo regresará la posición.

int buscarCadena(char vec[][25], char s[25], int n){
    int pos = -1;

    for(int i = 0; i < n; i++){
        if(strcmp(vec[i], s) == 0){
            pos = i;
            break;
        }
    }

    return pos;
}

int main()
{
    char nombres[10][25] = {"Juan","Alma","BEATRIZ","Humberto","Roberto","Rosa","Lidia","Isaias","Rafael","Felix"};
    char apellidos[10][25] = {"PEREZ","lOPEZ","CISEÑA","RUIZ","RIOS","ALCALA","CASTAÑEDA","ESQUIVEL","GIL","GARCIA"};

    cout<<"Nombres en el arreglo bidimensional"<<endl;

   /* for(int i = 0; i < 10 ; i++){
        aMayus(nombres[i]);
        cout<<nombres[i]<< endl;
    }*/

    cout << "ARREGLO DE CADENAS DESORDENDADO: " << endl;
    for(int i = 0; i < 10 ; i++){
        strncat(nombres[i], " ", sizeof(nombres[i]));
        strncat(nombres[i], apellidos[i], sizeof(nombres[i]));
        cout << nombres[i] << endl;
    }

    ordenarCadenas(nombres, 10);

    cout << "ARREGLO DE CADENAS ORDENDADO: " << endl;
    for(int i = 0; i < 10 ; i++){
        cout << nombres[i] << endl;
    }

    char buscar[25];
    cout << "Cual cadena quieres buscar?" << endl;
    cin >> buscar;

    int pos = buscarCadena(nombres, buscar, 10);

    if(pos != -1)
        cout << "Se encontro la cadena "<<buscar<<" en la posicion "<<pos<<endl;
    else
        cout << "No se encontro la cadena" << endl;
    return 0;
}
