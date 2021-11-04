#include <iostream>
#include <iomanip>
using namespace std;
 

 
int main (int argc, char *argv[]) {

//ARREGLO DINÁMICO
    int *e = new int[0];
    e[0] = 1;
    e[1] = 2;
    e[2] = 1;

    for(unsigned int i = 0; i < sizeof(e); i++){
        cout << "Elemento número " << i+1 << " = " << e[i] << endl;   
    }

//ARREGLO ESTÁTICO

    int n[ 10 ]; // n is an array of 10 integers
    // initialize elements of array n to 0          
    for ( int i = 0; i < 10; i++ ) {
        n[ i ] = i + 100; // set element at location i to i + 100
    }
    cout << "Element" << setw( 13 ) << "Value" << endl;



    // output each array element's value                      
    for ( int j = 0; j < 10; j++ ) {
        cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
    }
    
    return 0;
}