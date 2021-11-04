#include <iostream>
#include "conjunto.h"
#include <time.h>
using namespace std;

void menu(int &op)//REGRESA LA OPCION POR REFERENCIA
{
    do
    {
        cout<<"\n 1. Agregar "; //   +
        cout<<"\n 2. Borrar ";  //   -
        cout<<"\n 3. Mostrar ";
        cout<<"\n 4. Copiar ";
        cout<<"\n 5. Iguales ";// if(set1 == set2)
        //if(set1.esIgual(set2) ...
        //USAR SOBRECARGA DE OPERADORES EN C++
        cout<<"\n 6. Union ";
        cout<<"\n 7. Interseccion ";
        cout<<"\n 8. Salir \n";
       cin>>op;
    }while(op < 1 || op > 8);
}

int main()
{
    Conjunto set1, set2, set3;
    int opc;
    set1.vacio();
    set2.vacio();
    set3.vacio();
    char resp = 's';

    while(resp == 's'){
        menu(opc);
        switch(opc)
        {
            case 1:{
                Mensaje mensaje;
                int conj, val;
                int cont = 0;
                char c;
                cout << " Agregar de forma aleatoria?(s/n)" << endl;
                cin >> c;
                while(cont < 10)
                {

                    if(c == 's'){
                        //srand((unsigned)time(0));
                        conj = (rand()%2)+1;
                    }else{
                        cout << " Conjunto(1,2) ? : ";
                        cin >> conj;
                    }

                    if(conj == 1)
                    {
                        if(c == 's'){
                            //srand((unsigned)time(0));
                            val = (rand()%100)+1;
                        }else{
                            cout << " Valor : ";
                            cin >> val;
                        }
                        cout << " VALOR PARA EL CONJUNTO 1 : " << val << endl;
                        mensaje = set1.agregarElemento(val);
                        // mensaje = set1 + val; //CON SOBRECARGA
                        if(!mensaje)
                            cout << "ESPACIO INSUFICIENTE" << endl;
                        else if(mensaje == yaExiste)
                            cout << "DATO YA EXISTE "<< val << endl;
                        else
                            cout << "DATO AGREGADO" << endl;
                    }
                    if(conj == 2)
                    {
                        if(c == 's'){
                            //srand((unsigned)time(0));
                            val = (rand()%100)+1;
                        }else{
                            cout << " Valor : ";
                            cin >> val;
                        }
                        cout << " VALOR PARA EL CONJUNTO 2 : " << val << endl;
                        mensaje = set2.agregarElemento(val);
                        // mensaje = set2 + val; //CON SOBRECARGA
                        if(!mensaje)
                            cout << "ESPACIO INSUFICIENTE" << endl;
                        else if(mensaje == yaExiste)
                            cout << "DATO YA EXISTE "<< val << endl;
                        else
                            cout << "DATO AGREGADO" << endl;
                    }
                    cont++;
                }
            }
            break;
        case 2:{
            int resp = 0;
            int valor = 0;
            cout << "De cual conjunto desea eliminar un elemento? (1,2,3)"<<endl;
            cin >> resp;
            cout << "Que elemento desea eliminar del conjunto?"<<endl;
            cin >> valor;

            if(resp == 1)
                set1.borrarElemento(valor);
            else if(resp == 2)
                set2.borrarElemento(valor);
            else if(resp == 3)
                set3.borrarElemento(valor);
        }
            break;
        case 3:
            set1.mostrarElementos(" 1 ");
            set2.mostrarElementos(" 2 ");
            set3.mostrarElementos(" 3 ");
            break;
        case 4:{
            int resp = 0;
            cout << "De cual conjunto desea hacer una copia? (1,2)"<<endl;
            cin >> resp;

            if(resp == 1)
                set1.copiar(&set3);
            else if(resp == 2)
                set2.copiar(&set3);

            cout << "Copia de set" << resp << " guardada en set 3";
            set3.mostrarElementos("SET 3:");
        }
            break;
        case 5:
            if(set1.esIgual(&set2))
                cout << "Conjuntos iguales " << endl;
            else
                cout << "Conjuntis diferentes "<< endl;
            break;

        case 6:{
            set3 = set1.unionElem(&set2);
            cout << "Union de set1 y set2 guardada en set3: ";
            set3.mostrarElementos("Set3: ");
        }
            break;

        case 7:{
            set3 = set1.interseccionElem(&set2);
            cout << "Interseccion de set1 y set2 guardada en set3: ";
            set3.mostrarElementos("Set3: ");
        }
            break;

        case 8: exit(1);
        }

        /*set1.mostrarElementos("SET 1");
        set2.mostrarElementos("SET 2");
        set3.mostrarElementos("SET 3");*/

        cout << "Continuar(s/n) : "<<endl;
        cin >> resp;
    }
    return 0;
}
