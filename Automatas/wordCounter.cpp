#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]){
    
    unsigned int caracteres = 0;

    for(int i = 1; i < argc; i++){
        string palabra = argv[i];
        cout << sizeof(palabra) << endl;
        for(char c : palabra){
            caracteres += 1;
        }
    }

/*
    cout<< "*argv = " << *argv << endl;
    cout<< "argv = " << argv << endl;
    cout<< "*argv[0] = " << *argv[0] << endl;
    cout<< "argv[0] = " << argv[0] << endl; */

    
    cout<< "Caracteres = " << caracteres << endl;
    cout<< "Palabras = " << argc - 1 << endl;
    return 0;
}
