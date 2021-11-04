#include <iostream>
//#include <cstring> o:
#include <string.h>

using namespace std;

int main () {

   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   int  len ;

   // copy str1 into str3
   //strcpy( str3, str1);
   //cout << "strcpy( str3, str1) : " << str3 << endl;

   /*strncpy(str3, str1, strlen(str1));
   cout << "strncpy(str3, str1, strlen(str1)) : " << str3 << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;*/

   char texto[50];
   char opcion;
   do
   {
       cout << "Escribe una cadena: ";
       //cin >> texto; sólo captura la primera linea hasta el primer espacio
       cin.getline(texto, sizeof(texto));

       cout << "El texto es: "<<texto<<endl;
       cout << "Otro texto? (s/n)";
       cin >> opcion;
       cin.get(); // deshacer enter del buffer
       //opcion = tolower(opcion);
   }while(strchr("Ss",opcion));

   return 0;
}
