#include <iostream>

using namespace std;

#include <stdio.h>

int main()
{
   FILE *fichero;

   //fichero = fopen("BURBUJA.txt", "r");
   fichero = fopen("C:\\Users\\david\\Google Drive\\Semestre 5\\BURBUJA.txt", "r");
   cout << "C:\\Users\\david\\Google Drive\\Semestre 5\\7. Lenguajes y Aut\162matas\\BURBUJA.txt" << endl;
   while(!feof(fichero))
       fputc(fgetc(fichero), stdout);

   rewind(fichero);

   while(!feof(fichero))
       fputc(fgetc(fichero), stdout);

   fclose(fichero);

   getchar();
   return 0;
}
