#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Falla {
    int fecha;
    string mes;
    int dia;
    string hora;
    string dirIp;
    string razon;
};

// Codificacion del mes y dia como un entero de fecha
//int codifica ( string mes, int dia ) {}

int main(){
    string filename = "bitacora.txt";
    Falla reg;  // Accesar a los campos de la estructura con "."
    vector<Falla> fallas;
    ifstream bitacora;

    // Abre el archivo.
    bitacora.open(filename);
    // Error que indca que no existe.
    if(!bitacora){
        cerr << "Error: el archivo " << filename << "no se encontro" << endl;
        return 1;
    }


    // Se lee el archivo bitacora y se coloca la informacion en el vector de fallas.
    while (!bitacora.eof()) {
        Falla reg;
        bitacora >> reg.mes >> reg.dia >> reg.hora >> reg.dirIp;
        getline(bitacora,reg.razon);
        fallas.push_back(reg);
    }
    bitacora.close();

    // Se desplegan los primeros registros
    for (int i = 0; i < 10; i++ ){
        cout << fallas[i].mes << endl;
    }
};