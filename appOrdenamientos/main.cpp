#include <iostream>
#include <time.h>

using namespace std;

void insercion(int vec[], int n)
{
    int comp,interc;
    comp = interc = 0;

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = vec[i];
        j = i - 1;
        comp++;
        while (j >= 0 && vec[j] > key )
        {
            vec[j + 1] = vec[j];
            j = j - 1;
            interc++;
        }
        vec[j + 1] = key;
    }

    printf("\n Numero de comparaciones : %d", comp);
    cout<<"\n Numero de intercambios : "<<interc<<endl;
}

void burbuja(int *vec, int n)
        {
            int comp = 0;
            int interc = 0;
            for (int i = 0; i < n-1-1; i++)
            {
                for (int j = n - 1; i < j; j--)
                {
                    comp++;
                    if (vec[j - 1] < vec[j])
                    {
                        int aux = vec[j - 1];
                        vec[j - 1] = vec[j];
                        vec[j] = aux;
                        interc++;
                    }
                }
            }
            printf("\nNo. de Comparaciones : %d ",comp);
            printf("\nNo. de intercambios  : %d \n", interc);
}

// quick

void intercambiar(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int particion (int vec[], int inicio, int fin,int &comp, int &inte)
{
    int pivote = vec[fin];   
    int i = (inicio - 1);  //i va a representar la posición del elemento menor
 
    comp++;
    for (int j = inicio; j <= fin- 1; j++)
    {
        if (vec[j] <= pivote)
        {
            inte++;
            i++;   
            intercambiar(&vec[i], &vec[j]);
        }
    }
    intercambiar(&vec[i + 1], &vec[fin]);
    return (i + 1);
}
 

void quickSort(int vec[], int inicio, int fin, int &comp, int &inte)
{
    if (inicio < fin)
    {
        //regresa el pivote ahora en la posición correcta del veceglo
        int pivote = particion(vec, inicio, fin, comp, inte);
 
        //Primero realiza la recursión hasta ordenar el elemento menor
        quickSort(vec, inicio, pivote - 1, comp, inte);
        quickSort(vec, pivote + 1, fin, comp, inte);
    }
}



void imprimirveceglo(int *vec, int n)
{
    for(int i=0; i<n; i++)
        cout << vec[i] << " , "<<endl;
    cout << endl;
}

int main()
{
    //int vec[] = {6,5,3,1,8,7,2,4};
    //int n = sizeof (vec) / sizeof(vec[0]);

    const int tam = 500;
    int *vec = new int[tam];
    srand(unsigned(time(NULL)));

    for(int i = 0; i < tam; i++)
        vec[i] = rand() % 900 +100;

    cout << "datos en el veceglo: "<<endl;
    imprimirveceglo(vec, tam);
    cout << "INSERCION"<<endl;
    insercion(vec, tam);
    cout << "BURBUJA"<<endl;
    burbuja(vec, tam);
    cout << "QUICKSORT"<<endl;
    int comparaciones = 0;
    int intercambios = 0;
    quickSort(vec,0, tam-1, comparaciones, intercambios);
    cout<< "comparaciones : "<< comparaciones << endl;
    cout<< "intercambios : "<< intercambios << endl;

    imprimirveceglo(vec, tam);
    return 0;
}
