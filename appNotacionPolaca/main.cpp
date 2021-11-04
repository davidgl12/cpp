#include <iostream>

using namespace std;

#include "notacionpolaca.h"

int main()
{
    //string expInfija = "a+b-c";
    //cout << "Expresion infija: ";
    string expInfija = "1^a*((3-4)+5)/(6*8+9)";//TAREA : ANALIZAR LA CADENA DE ENTRADA QUE NO CONTENGA ESPACIOS EN BLANCO
    //string expInfija;                                   // SI HAY, SE DEBERAN ELIMINAR
    //cin >> expInfija;

    cout<<"Expresion Infija : "<<expInfija<<endl;

    NotacionPolaca *expresion = new NotacionPolaca();

    char *resul = new char[expInfija.length()];

    resul = expresion->ConvertirAPosFija(expInfija);

    cout<<"\n EXPRESION POSTFIJA = "<<resul<<endl;

    double resultado = expresion->hacerOperacion(resul);
    cout<<"Resultado de la expresion postfija= " << resultado << endl;

    delete expresion;
    delete []resul;
    return 0;
}
