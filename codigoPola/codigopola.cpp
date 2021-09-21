#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//Acentos
#include <wchar.h>
#include <locale.h>

using namespace std;

//-----------ORDENAMIENTO-----------

// despliega el contenido de un vector de enteros
void despVector(vector<int> &vec) {
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << " " << *i;
    }
    cout << endl;
}

// intercambia 2 posiciones en un vector
void swap(vector<int> &vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// ordena vector mendiante el sort de intercambio
// Complejidad: peor O(n^2) ... mejor O(n^2)
void sortIntercambio(vector<int> &vec) {
    int comparaciones = 0;
    int intercambios = 0;
    for (int inf = 0; inf < vec.size() - 1; inf++) { // posiciones que voy ordenando
        for (int r = inf + 1; r < vec.size(); r++) {
            comparaciones++;
            if (vec[r] < vec[inf]) {
                swap(vec, inf, r);
                intercambios++;
            }
        }
        // cout << "La posicion " << inf << " quedo ordenada" << endl;
    }
    cout << "# comparaciones = " << comparaciones << endl;
    cout << "# intercambios = " << intercambios << endl;
}

// ordena vector mendiante el sort de burbuja
// Complejidad: peor O(n^2) ... mejor O(n)
void sortBurbuja(vector<int> &vec)
{
    int comparaciones = 0;
    int intercambios = 0;
    bool ordenado = false; // bandera para determinar anticipadamente un vector ordenado
    for (int may = vec.size() - 1; may > 0 && ! ordenado; may--) { // posiciones que voy ordenando
        ordenado = true; // asumo que ya esta ordenado
        for (int b = 0; b < may; b++) {
            comparaciones++;
            if (vec[b+1] < vec[b])
            {
                swap(vec, b, b+1);
                intercambios++;
                ordenado = false; // si hice intercambio no estaba ordenado
            }
        }
        // cout << "La posicion " << may << " quedo ordenada" << endl;
    }
    cout << "# comparaciones = " << comparaciones << endl;
    cout << "# intercambios = " << intercambios << endl;
}

// ordena vector mendiante merge sort (ordenamiento por mezcla)
// Complejidad: peor O(n log n) ... mejor O(n log n)

// mezcla dos mitades ordenadas de un vector
void mezcla(vector<int> &vec, int inicio, int fin) {
    int medio = (inicio + fin) / 2;
    int tam = fin - inicio + 1;
    vector<int> temp(tam);

    int pos1 = inicio;
    int pos2 = medio + 1;
    for (int pos = 0; pos < tam; pos++) {
        if (pos1 > medio) { // se me acabaron los de la primera mitad
            temp[pos] = vec[pos2];
            pos2++;
        }
        else if (pos2 > fin) { // se acabaron los de la 2da mitad
            temp[pos] = vec[pos1];
            pos1++;
        }
        else if (vec[pos2] < vec[pos1]) { // todavía hay elementos
            temp[pos] = vec[pos2];
            pos2++;
        }
        else {
            temp[pos] = vec[pos1];
            pos1++;
        }
    }
    // copiarlo dentro del vector
    for (int i = 0; i < tam; i++) {
        vec[i + inicio] = temp[i];
    }
}

// implementa la lógica recursiva del sort por mezcla
void mergeAux(vector<int> &vec, int inicio, int fin, int &comparaciones) {
    if (inicio < fin) { // al menos tiene 2 elementos
        int medio = (inicio + fin) / 2;
        int comp1 = 0, comp2 = 0;
        mergeAux(vec, inicio, medio, comp1);
        mergeAux(vec, medio + 1, fin, comp2);
        mezcla(vec, inicio, fin);
        comparaciones = comp1 + comp2 + fin - inicio + 1;
    }
}

void mergeSort(vector<int> &vec) {
    int comparaciones = 0;
    mergeAux(vec, 0, vec.size() - 1, comparaciones);
    cout << "# comparaciones = " << comparaciones << endl;
}

//----------BÚSQUEDAS----------

// método de búsqueda SECUENCIAL
// Complejidad: O(n) ... mejor O(1)
int busqSec(vector<int> &vec, int valor) {
    for (int pos = 0; pos < vec.size(); pos++) {
        cout << "pos: " << pos << endl;
        if (valor == vec[pos])
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

int main(){

    vector<int> vec;
    int n;
    cout << "¿Cuántos números tendrá el vector?" << endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout << "Inserte el valor del número "<<(i+1)<<" (índice: "<<i<<" ): "<<endl;
        cin >> vec[i];
    }

    int b;
    cout << "¿Cuántas búsquedas va a realizar?" << endl;
    cin >> b;
    int busquedas[b];

    for(int i=0; i<b; i++)
    {
        cout << "Valor del número "<<(i+1)<<" que va a buscar: "<<endl;
        cin >> busquedas[i];
    }

    

    return 0;
}