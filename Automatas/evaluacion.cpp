#include <iostream>
using namespace std;
 
int main () {
   double estatico[2];
   int *dinamico = new int[3];
   dinamico[0]=1;
   dinamico[1]=2;
   dinamico[2]=3;

   cout << "sizeof(estatico) = "<<sizeof(estatico) << endl;
   cout << "sizeof(*dinamico) = "<<sizeof(*dinamico) << endl;
   cout << "sizeof(dinamico) = "<<sizeof(dinamico) << endl;
   cout << "dinamico = "<< dinamico << endl;
   cout << "*dinamico = "<< *dinamico << endl;

   //Iterar un arreglo
   for(unsigned int i = 0; i < sizeof(estatico)/sizeof(estatico[0]); i++){
      cout << "Valor de index " << i << " de estatico = "<< estatico[i]<<endl;
   }

   for(unsigned int i = 0; i < sizeof(dinamico)/sizeof(dinamico[0]); i++){
      cout << "Valor de index " << i << " de dinamico = "<< dinamico[i]<<endl;
   }


   delete [] dinamico;
}