#include "notacionpolaca.h"
#include <math.h>

#include <iostream>
//#include "pilat.cpp"

NotacionPolaca::NotacionPolaca()
{

}

char *NotacionPolaca::ConvertirAPosFija(string EI)
//TAREA
//QString NotacionPolaca
{
    char *Epos = new char[EI.length()];

    //LA PILA DEBE SER AL MENOS DE LA CANTIDAD DE OPERADORES EN LA EXPRESION POR LO TANTO

    pilaT<int> *stack = new pilaT<int>(EI.length());
//TAREA
    //CREAR UN METODO DONDE SE ANALICE LA EXP. INFIJA Y SE DETERMINE LA CANTIDAD DE OPERADORES
        //A UTILIZAR EN EL TAMAÑO DE LA PILA.
        //EJ: (7+8)-6*5^2  LA PILA DEBE SER DE TAMAÑO 5

        //SE REQUIEREN DOS VARIABLES PARA EL RECORRIDO, UNA PARA EL ANALISIS Y OTRA PARA LA INSERCION DE EPOS

        int i, pos = 0;
        for(i = 0; i < (int)EI.length(); i++)
        {
            char car = EI[i];
            Simbolo actual = tipoYPrecedencia(car);
            switch (actual)
            {
                case OPERANDO: Epos[pos++]=car;
                     break;
                case SUMRES:{
                  while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                      Epos[pos++] = (char)stack->pop();
                  stack->push(car);
                 }
                break;

                case MULTDIV:{
                   while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                     Epos[pos++] = (char)stack->pop();
                   stack->push(car);
                }
                break;
                case POW:{
                   while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                     Epos[pos++] = (char)stack->pop();
                   stack->push(car);
                }
                break;
            case PIZQ:  stack->push(car);
                break;
            case PDER:{
                    char x = (char)stack->pop();
                    while (tipoYPrecedencia(x) != PIZQ)
                    {
                        Epos[pos++] = x;
                        x = (char)stack->pop();
                    }
              }
                //break;
            }//FIN DEL SWITCH
        }// FIN DEL for
        while (!stack->estaVacia())
        {
            if(pos < (int)EI.length())
                Epos[pos++] = (char)stack->pop();
            else
                break;
        }
        Epos[pos]='\0';//LAS CADENAS DE C/C++ TERMINAN EN NULO = '\0'
        return Epos;

}

int NotacionPolaca::hacerOperacion(char *Epos)
{
    string epos(Epos);
    pilaT<double> pila(epos.size());
    char s;
    double operando1, operando2, resultado, temp;
    Simbolo simbolo;

    for(int i=0; i<(int)epos.size(); i++){
        s = epos[i];
        simbolo = tipoYPrecedencia(s);

        if(s > 64 && s < 173){
            cout << "Tu expresion tiene un caracter invalido: " << s << endl;
            return 0;
        }

        if(simbolo == OPERANDO){
            temp = s - '0';
            cout <<"\nS = "<< temp << endl;
            pila.push(temp);
        }else{
            operando2 = pila.pop();
            operando1 = pila.pop();

            cout <<operando1<<" "<<s<< " " <<operando2 << " = ";
            switch(s){
                case '+': resultado = operando1 + operando2; break;
                case '-': resultado = operando1 - operando2; break;
                case '*': resultado = operando1 * operando2; break;
                case '/': resultado = operando2 / operando1; break;
                case '^': resultado = pow(operando1, operando2); break;
            }
            cout << resultado <<endl;
            pila.push(resultado);
        }

    }

    return (int)pila.pop();

}

Simbolo NotacionPolaca::tipoYPrecedencia(char s)
{
    Simbolo simbolo;
    switch(s)
    {
       case '+': //simbolo = SUMRES;break;
       case '-': simbolo = SUMRES;
                 break;
       case '*':
       case '/': simbolo = MULTDIV;
                 break;
       case '^': simbolo = POW; break;
       case '(': simbolo = PIZQ; break;
       case ')': simbolo = PDER;break;

       default : simbolo = OPERANDO; break;
    }
    return simbolo;
}
