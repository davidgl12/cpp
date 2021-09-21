#include "archivosdec.h"

ArchivosDeC::ArchivosDeC()
{

}

void ArchivosDeC::abrir(char *nomArch, char cadenas[][25], int &cant)
{
    FILE *parchivo;

    char *cadena = new char[25];
    int i = 0;

    if((parchivo = fopen(nomArch, "r")) == NULL) //nullptr
        printf("\n ERROR al abrir el archivo \n");
    else
    {
        while(!feof(parchivo))
        {
            printf("\n Leyendo desde metodo abrir \n");
            while(fgets(cadena,25,parchivo))
            {
                printf("%s", cadena);
                strncpy(cadenas[i], cadena, sizeof(cadena));
                //strncpy_s(cadenas[i],cadena);
                i++;
            }
        }
    }

    cant = i;
    fclose(parchivo);
}

void ArchivosDeC::guardar(char *nomArch, char cadenas[][25])
{

}

void ArchivosDeC::agregar(char nombArch[], char cademas[][25])
{

}
