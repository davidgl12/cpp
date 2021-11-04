#include <iostream>

using namespace std;

#include "archivosdec.h"

//COPIAR EL METODO DE LA BURBUJA QUE ORDENA CADENAS
void BurbujaDsc(char vec[50][25], int n)
        {
            /*int comp = 0;
            int interc = 0;
            comp = interc = 0;
            */
            for (int i = 0; i < n-1; i++)
            {
                for (int j = n - 1; i < j; j--)
                {
                    //comp++;
                    //if (vec[j - 1] < vec[j])
                    if(strcmp(vec[j-1],vec[j])<0)
                    {
                        //int aux = vec[j - 1];
                        char *cadaux = new char[10];
                        //vec[j - 1] = vec[j];
                        strcpy(cadaux,vec[j-1]);
                        //vec[j] = aux;
                        strcpy(vec[j-1],vec[j]);
                       // interc++;
                        strcpy(vec[j],cadaux);
                    }
                }
            }

        }


int main()
{
    //copiar aqui el arreglo de nombres que se uso en la evaluacion
    char nombres[10][25] = {"Juan","Juana","Carlos","ALMA","ana","Jose","Luis","LUISA","BEATRIZ","SAra"};
    //char apellidos[10][25]= {"PEREZ","LOPEZ","CISENA","RUIZ","RIOS","ALCALA","CASTANEDA","ESQUIVEL","RIVERA","GIL"};

    /*TAREA DOMINGO 26:
    APP. MANEJO DE ARCHIVOS EN C. IMPLEMENTARLA UTILIZANDO UN MENU
    DONDE SE PERMITA AL USUARIO:
    1. CONCATENAR DOS ARCHIVOS CREADOS EN UN EDITOR DE TEXTO Y
    2. PARA INCLUIR LAS CADENAS QUE FUERON INICIALIZADAS EN LA APP.  Y QUE TAMBIEN SE PUEDEN CAPTURAR
    NOMBRES PARA ASIGNARLOS A UN ARREGLO BIDIMENSIONAL.*/

    string nombreArchString, path, pathOriginal;
    cout<<"NOMBRE DEL ARCHIVO DE TEXTO (sin extension) : ";
    cin>>nombreArchString;
    nombreArchString += ".txt";
    cout << "Path del archivo: (Ej. en windows: c:\\\\users\\\\david\\\\Desktop\\\\ )";
    cin >> pathOriginal;
    //path = "c:\\users\\david\\Desktop\\";
    path = pathOriginal + nombreArchString;

    ArchivosDeC archivo;  //OBJETO ESTATICO //ArchivosDeC *archivo1 = new ArchivosDeC();  // OBJETO DINAMICO

    //COMO SE CAPTURO con string hay que cambiarlo a char[]
    char pathEnChars[100];
    strncpy(pathEnChars, path.c_str() ,sizeof(pathEnChars));
    cout << "CONTENIDO DEL ARCHIVO " << nombreArchString << ".txt :" << endl;
    archivo.abrir(pathEnChars);

    int respuesta = 0;
    do{
        cout << "\n\nQue desea hacer con el archivo?" << endl;
        cout << "Escriba 1 si desea: \n" << "\tconcatenarle el contenido de otro archivo (en el mismo path)" << endl;
        cout << "Escriba 2 si desea: \n" << "\tconcatenarle otras otras cadenas" << endl;
        cout << "Escriba 3 si desea: \n" << "\tsalir de la aplicación" << endl;
        cin >> respuesta;

        if(respuesta == 1){
            cout<<"NOMBRE DEL ARCHIVO DE TEXTO A CONCATENAR (sin extension) : ";
            cin>>nombreArchString;
            nombreArchString += ".txt";
            path = pathOriginal + nombreArchString;

            char pathEnChars2[100];
            char elementosEnPath2[50][25];
            int cantElementos;
            strncpy(pathEnChars2, path.c_str() ,sizeof(pathEnChars2));
            archivo.abrir(pathEnChars2, elementosEnPath2, cantElementos);
            archivo.agregar(pathEnChars, elementosEnPath2, cantElementos);
            cout << "Se agregaron contenidos de " << nombreArchString << " al documento original" << endl;
        }
        else if(respuesta == 2){
            int respuesta2 = 0;
            cout << "\n\nQuieres agregarle tus propias cadenas(1) o las de la aplicacion(2)?" << endl;
            cin >> respuesta2;

            if(respuesta2 == 1){
                int n = 0;
                cout << "Cuantas cadenas vas a agregar?" << endl;
                cin >> n;
                char cadenasNuevas[n][25];
                for(int i = 0; i < n; i++){
                    char valor[25];
                    string valorStr;
                    cout << "Insertar valor de cadena " << i;
                    cin >> valorStr;
                    strncpy(valor, valorStr.c_str(), sizeof(valor));
                    strncpy(cadenasNuevas[i], valor, sizeof(cadenasNuevas[i]));
                }
                archivo.agregar(pathEnChars, cadenasNuevas, n);
                cout << "Se agregaron las cadenas al archivo original, felicidades" << endl;
            }
            else if(respuesta2 == 2){
                archivo.agregar(pathEnChars,nombres,10);
                cout << "Se agrego el arreglo de nombres al archivo original";
            }
        }
        else if(respuesta > 3 || respuesta < 3 ){
                cout << "Escribir alguno de los numeros que te pido no es algo dificil, por favor intentalo de nuevo" << endl;
            }

    }while(respuesta != 3);

//    char nomsEnArchivo[50][25]; // PARA DEJAR EN ESTE ARREGLO LOS DATOS DEL ARCHIVO
 //   int cantNombres;
//    archivo.abrir(narch,nomsEnArchivo,cantNombres);
//    cout<<"\n\t\a\a NOMBRES EN EL ARREGLO BIDIMENSIONAL  "<<endl;
//    for(int ren = 0; ren < 10 /*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
//        cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;
 //PROBAR EL METODO AGREGAR

   // string path2 = "/Users/martinvaldes/Desktop/";
   // string path2 = "C:\\Users\\mosva\\Desktop\\";
   // path2+= "nombres.txt";

   // char narch2[100];
   // strncpy(narch2, path2.c_str() ,sizeof(narch));
 //   archivo.agregar(narch,apellidos);//10

 //   archivo.abrir(narch,nomsEnArchivo,cantNombres);
 //   cout<<"\n\t\a\a NOMBRES AGREGADOS EN EL ARREGLO BIDIMENSIONAL  "<<endl;
//    for(int ren = 0; ren < 20/*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
  //      cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;

    //ORDENAR LOS NOMBRES DEL ARCHIVO

//    BurbujaDsc(nomsEnArchivo,20);//cantNombres);
  //  cout<<"\a\a\a\a \tNOMBRES ORDENADOS "<<endl;
  //  for(int ren = 0; ren < 20 /*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
   //     cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;





    return 0;
}
