// Busca el caracter único en una secuencia de strings
// Autor: Dr. Santiago Enrique Conant Pablos, Agosto 2021
#include <iostream>
#include <vector>

using namespace std;

// búsqueda secuencial del caracter único
char unicoSec(string cadena, int &comps) {
    comps = 0;
    int pos = 0;
    while (pos < cadena.size() - 1) {
        comps++;
        if (cadena[pos] != cadena[pos+1]) {
            return cadena[pos];
        }
        pos += 2;
    }
    return cadena[pos]; // es el último
}

// búsqueda binaria del caracter único
char unicoBin(string cadena, int &comps) {
    comps = 0;
    int izq = 0, der = cadena.size() - 1;
    while (izq < der) {
        int medio = (izq + der) / 2;
        comps++;
        if ((cadena[medio] != cadena[medio-1]) && (cadena[medio] != cadena[medio+1]))
            return cadena[medio];
        if (cadena[medio] != cadena[medio - 1]) {
            if ((medio - izq) % 2 == 1)
                der = medio - 1;
            else
                izq = medio + 2;
        }
        else if ((medio - izq) % 2 == 0)
            der = medio - 2;
        else
            izq = medio + 1;
   }
   return cadena[izq];
}

int main() {
    int n;
    cin >> n;
    vector<string> cadena(n);
    // lee las strings
    for(int i = 0; i < n; i++) {
        cin >> cadena[i];
    }
    // busca el caracter único: se supone que las strings respetan el formato establecido
    char unico; // caracter único
    int comps;  // # de comparaciones realizadas
    for(int i = 0; i < n; i++) {
        // búsqueda secuencial
        unico = unicoSec(cadena[i], comps);
        cout << unico << " " << comps << " ";
        unico = unicoBin(cadena[i], comps);
        cout << unico << " " << comps << endl;
    }

    return 0;
}