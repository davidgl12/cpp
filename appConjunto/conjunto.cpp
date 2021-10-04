#include "conjunto.h"

Conjunto::Conjunto()
{
    nelem = 0;
}

Mensaje Conjunto::agregarElemento(int valor)
{
    if(nelem >= MAX){
        return overflow;
    }else if(pertenece(valor)){
        return yaExiste;
    }else{
        elementos[nelem] = valor;
        nelem++;
        return ok;
    }
}

bool Conjunto::pertenece(const int valor)
{
    bool resultado = false;
    for(int i = 0; i < nelem; i++){
        if(elementos[i] == valor)
            resultado = true;
    }
    return resultado;
}

bool Conjunto::pertenece(const int valor, int &pos)
{
    bool resultado = false;
    for(int i = 0; i < nelem; i++){
        if(elementos[i] == valor){
            resultado = true;
            pos = i;
        }
    }
    return resultado;
}

void Conjunto::borrarElemento(int e)
{
    int pos;
    if(pertenece(e,pos)){
        nelem--;
        for(int i = 0; i < nelem; i++){
            if(i >= pos){
                elementos[i] = elementos[i+1];
            }
        }
    }

}

void Conjunto::mostrarElementos(string set)
{
    cout << "\a\a\t CONJUNTO: "<< set << endl;
    cout << "{ ";
    int i;
    for(i = 0 ; i < nelem-1; i++)
        cout << elementos[i] << ",";

    if(nelem > 0)
        cout << elementos[i];
    cout << " } "<< endl;
}

//setA.copiar(setB) copia setA en setB
void Conjunto::copiar(Conjunto *set)
{
    for(int i = 0; i < nelem; i++){
        set->agregarElemento(elementos[i]);
    }

    set->nelem = this->nelem;
}

bool Conjunto::esIgual(Conjunto *set) const
{
    if(nelem == set->nelem){
        for(int i=0; i < nelem; i++){
            if(elementos[i] != set->elementos[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

Conjunto Conjunto::interseccionElem(Conjunto *set)
{
    Conjunto resultado;

    for(int i=0; i < set->nelem; i++){
        if(pertenece(set->elementos[i])){
            resultado.agregarElemento(set->elementos[i]);
        }
    }

    return resultado;
}

Conjunto Conjunto::unionElem(Conjunto *set)
{
    Conjunto resultado;
    this->copiar(&resultado);

    for(int i=0; i < set->nelem; i++){
        if(!pertenece(set->elementos[i])){
            resultado.agregarElemento(set->elementos[i]);
        }
    }

    return resultado;
}

void Conjunto::Interseccion(Conjunto *set2, Conjunto *set3){
    set3->nelem=0;
    for(int i=0; i<this->nelem; i++){
        for(int j=0; j<set2->nelem; j++){
            set3->elementos[set3->nelem++] = this->elementos[i];
            break; //?
        }
    }
}

/*Mensaje Conjunto::Union(Conjunto &s2, Conjunto &s3)
{
    s2.copiar(&s3);
    for(int i = 0; i < this -> nelem; i++)
        if(s3.agregarElemento(this->elementos[]))
}*/

void Conjunto::mostrar()
{
    cout <<  "{";
    for(int i=0; i<nelem; i++){
        cout << elementos[i];

        if(nelem-1 == i)
            break;
        else
            cout << ",";

    }
    //respuesta.pop_back();
    cout << "}";
}
