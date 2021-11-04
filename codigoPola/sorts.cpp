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
        cout << "La posicion " << inf << " quedo ordenada" << endl;
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
        cout << "La posicion " << may << " quedo ordenada" << endl;
    }
    cout << "# comparaciones = " << comparaciones << endl;
    cout << "# intercambios = " << intercambios << endl;
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

     return 0;
}