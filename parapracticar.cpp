#include <iostream>
#include <cmath> //Matematicas
#include <cstdlib> //Standard Library
#include <ctime> // O.o
using namespace std;

static int staticGlobal = 10;

void variableStatic();
void invertirValores(int *x, int *y);

int sumaOpcional(int a, int b = 10){
    return a + b;
}

int main(int argc, char *argv[]){
    //typedef da un nuevo nombre a un tipo de dato
    typedef int entero;
    entero ojos = 2;
    cout << "Ojos = " << ojos << endl;

    //Enums define un tipo de dato (direcciones) junto con una serie
    //de valores que puede tomar una variable (dir) de ese tipo
    enum direcciones {Norte, Sur, Este, Oeste} dir;
    dir = Sur; //valor de dir = 1
    direcciones dir2 = Este;

    /*Constantes: 0 para octal, 0x o 0X  para hecadecimal
    85         // decimal
    0213       // octal
    0x4b       // hexadecimal
    30         // int
    30u        // unsigned int
    30l        // long
    30ul       // unsigned long */

    string st = "Hi, \
    honii";

    const int CONSTANTE1 = 1;
    #define CONSTANTE2 2;

    /*La storage class "static" para identificadores señala
    que dicha variable local va a existir en su scope durante la duración del programa, en lugar de ser destruida
    y creada cada que entra o sale de su scope. 
    Por ejemplo una variable estática declarada dentro de una función, va a retener el valor de cada
    llamada (como en la función variableStatic)*/
    while(staticGlobal--){
        variableStatic();
    }

    cout << "dir = " << dir << " dir 2 = " << dir2 << endl;
    cout << "String = " + st << endl;
    cout << "Constante1 = " << CONSTANTE1 << " Constante2 = "<< CONSTANTE2;

    //Cast, esto va a regresar 2
    cout << int(2.234) << endl;

    int respuesta;
    cout << "Buenas tardes, numero por favor "<<endl;
    cin >> respuesta;

    string comida;
    switch(respuesta){
        case 1 : 
            cout<<"¿Que se te ofrece?"; 
            break;
        case 2 : 
            cout<<"Los switches funcionan igual que en java";
            break;
        case 3 : 
            cout<<"Que me sugieres que haga de comer?";
            cin >> comida;
            cout<<"Hmm entendido, lo pensare, gracias c:";
            break;
        default: cout << "Okey :c" << endl; 
    }

    //if alternativo 
    respuesta == 3 ? cout << "Espera, cómo hago eso de comer?" : cout << "Hace amber";

    //Las funciones en C++ pueden tener parámetros opcionales con valores default
    cout << "Suma usando ambos parámetros" << sumaOpcional(5,5) << endl; //Devuelve 10
    cout << "Suma usando sólo un parámetro" << sumaOpcional(5) << endl;   //Devuelve 15

    //Invertir valores con sus apuntadores
    int numero1 = 10;
    int numero2 = 20;
    cout << "Inicialmente n1 = "<< numero1 << " y n2 = " << numero2 << endl;
    invertirValores(&numero1, &numero2);
    cout << "Ahora n1 = "<< numero1 << " y n2 = " << numero2 << endl;

    //Matemáticas, wakis (#include <cmath>)
    cout << pow(2,2);
    cout << sqrt(4);
    cout << abs(-5);
    cout << floor(40.54); 
    
    int a = 10;
    int b = 10;
    cout << "a++ = " << a++ << endl;
    cout << "a = " << a << endl;
    cout << "++a = " << ++b << endl;

    //ARREGLO DINÁMICO
    int *e = new int[0];
    e[0] = 1;
    e[1] = 2;
    e[2] = 1;

    for(unsigned int i = 0; i < sizeof(e); i++){
        cout << "Elemento número " << i+1 << " = " << e[i] << endl;   
    }

    return 0;
}

void variableStatic(){
    static int staticLocal = 5;
    staticLocal++;
    cout<<"local = "<<staticLocal << " global = "<< staticGlobal<< endl;
}

void invertirValores(int *x, int *y){
    //Se usan apuntadores para trabajar directamente con la dirección de memoria
    //Original de las variables, cambiando por ende el valor de los parámetros originales
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int generarRandom(){
    int i, j;
    // set the seed
    srand( (unsigned)time( NULL ) );
    // generate actual random number
    j = rand();
    return j;
}
