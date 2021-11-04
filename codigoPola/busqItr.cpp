// Busca valores en listas generadas aleatoriamente
// regresa -1 si no se encuentra
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
#include "Lista.h"

// método de búsqueda SECUENCIAL
// Complejidad: O(n) ... mejor O(1)
int busqSec(Lista<int> &lista, int valor) {
    for (int pos = 0; pos < lista.getSize(); pos++) {
        cout << "pos: " << pos << endl;
        if (valor == lista.getData(pos))
            return pos;
    }
    return -1;
}

// método de búsqueda binaria
int busqBin(vector<int> &vec, int valor) {
    int izq = 0, der = vec.size() - 1;

    while (izq <= der) {
        int medio = (izq + der) / 2;
        cout << "izq: " << izq << " med: " << medio << " der: " << der << endl;
        if (valor == vec[medio])
            return medio;
        if (valor < vec[medio])
            der = medio - 1;
        else
            izq = medio + 1;
    }
    return -1;
}

int main() {
    int n;
    Lista<int> lista;
    int valor;

    cout << "Cantidad de valores? ";
    cin >> n;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista.insert(rand() % (2 * n) + 1);
    }
    lista.print();

    // pedir el valor a buscar
    cout << "Valor a buscar? ";
    cin >> valor;

    // Buscar usando búsqueda secuencial
    cout << "BUSQUEDA SECUENCIAL" << endl;
    int pos = busqSec(lista, valor);
    if (pos == -1)
        cout << "Valor No Encontrado" << endl;
    else
        cout << "Valor " << valor << " encontrado en la posicion " << pos << endl;

    // crear un vector con los datos de la lista
    vector<int> vec(n);
    for (int i=0; i < n; i++)
        vec[i] = lista.getData(i);

    // ordenar el vector con los datos de la lista
    sort(vec.begin(), vec.end());
    cout << "Vector ordenado: ";
    for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Buscar usando búsqueda binaria
    cout << "BUSQUEDA BINARIA" << endl;
    pos = busqBin(vec, valor);
    if (pos == -1)
        cout << "Valor No Encontrado" << endl;
    else
        cout << "Valor " << valor << " encontrado en la posicion " << pos << endl;

    return 0;
}