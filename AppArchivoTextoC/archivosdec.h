#ifndef ARCHIVOSDEC_H
#define ARCHIVOSDEC_H

#include <stdio.h>
#include <string.h>


class ArchivosDeC{
public:
    ArchivosDeC();
    void abrir(char *nomArch, char cadenas[50][25], int &cant);

    void guardar(char *nomArch, char cadenas[50][25]);

    void agregar(char *nomArch, char cadenas[50][25]);

};

#endif // ARCHIVOSDEC_H
