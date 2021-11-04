// Implementa los algoritmos de ordenamiento
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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

// ordena vector mendiante el sort de selección
// Complejidad: peor O(n^2) ... mejor O(n^2)
void sortSeleccion(vector<int> &vec)
{
    int comparaciones = 0;
    int intercambios = 0;
    for (int i = 0; i <= vec.size() - 2; i++)
    { // posiciones que voy ordenando
        int menor = i;
        for (int r = i + 1; r <= vec.size() - 1; r++) // busca la posición del menor
        {
            comparaciones++;
            if (vec[r] < vec[menor])
            {
                menor = r;
            }
        }
        if (menor != i)
        {
            swap(vec, menor, i);
            intercambios++;
        }
        // cout << "La posicion " << inf << " quedo ordenada" << endl;
    }
    cout << "# comparaciones = " << comparaciones << endl;
    cout << "# intercambios = " << intercambios << endl;
}

// ordena vector mendiante el sort de inserción
// Complejidad: peor O(n^2) ... mejor O(n)
void sortInsercion(vector<int> &vec)
{
    int comparaciones = 0;
    int intercambios = 0;
    for (int i = 1; i <= vec.size() - 1; i++)
    { // elementos que voy insertando
        for (int j = i; j > 0; j--)
        {
            comparaciones++;
            if (vec[j] < vec[j - 1])
            {
                swap(vec, j, j - 1);
                intercambios++;
            }
            else
                break;
        }
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

int main()
{
    int n;
    cout << "Cantidad de elementos? ";
    cin >> n;
    // Crea un vector con n enteros aleatorios
    vector<int> desordenado(n);
    srand(time(NULL));
    for (int i=0; i < n; i++) {
        desordenado[i] = rand() % (5 * n) + 1;
    }
     cout << "SORT DE INTERCAMBIO" << endl;
     vector<int> vec(desordenado);
     cout << "Desordenado:";
     despVector(vec);
     sortIntercambio(vec);
     cout << "Ordenado: ";
     despVector(vec);
     cout << "SORT DE BURBUJA" << endl;
     vec = desordenado;
     cout << "Desordenado:";
     despVector(vec);
     sortBurbuja(vec);
     cout << "Ordenado: ";
     despVector(vec);
     cout << "SORT DE SELECCION" << endl;
     vec = desordenado;
     cout << "Desordenado:";
     despVector(vec);
     sortSeleccion(vec);
     cout << "Ordenado: ";
     despVector(vec);
     cout << "SORT DE INSERCION" << endl;
     vec = desordenado;
     cout << "Desordenado:";
     despVector(vec);
     sortInsercion(vec);
     cout << "Ordenado: ";
     despVector(vec);
     cout << "SORT DE MERGE" << endl;
     vec = desordenado;
     cout << "Desordenado:";
     despVector(vec);
     mergeSort(vec);
     cout << "Ordenado: ";
     despVector(vec);

     return 0;
}