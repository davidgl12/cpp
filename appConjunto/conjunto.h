#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
using namespace std;


const int MAX = 20;

//TIPO DE DATO ENUM asocia un dato a un valor numérico, por default inica en 0
enum Mensaje{overflow, ok, yaExiste};

class Conjunto
{
//private:
    int elementos[MAX];
    int nelem;

public:
    Conjunto();
    ~Conjunto(){cout << "Me destruyeron :c " << endl;}

    inline void vacio(){nelem = 0;}

    Mensaje agregarElemento(int);

    bool pertenece(const int);

    bool pertenece(const int, int&); //devuelve en la address la posición del elemento

    void borrarElemento(int);

    void mostrarElementos(string set);

    void copiar(Conjunto *);

    bool esIgual(Conjunto *) const;
    //Palabra reservada const en una función no permite cambiar la información de un puntero, creo

    Conjunto interseccionElem(Conjunto *);

    Conjunto unionElem(Conjunto *);

    void Interseccion(Conjunto *, Conjunto *); //Método del profe

    Mensaje Union(Conjunto &, Conjunto &);

    void mostrar();
};

#endif // CONJUNTO_H
