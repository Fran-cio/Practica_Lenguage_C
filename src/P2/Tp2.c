#include <stdlib.h>
#include<stdio.h>
#include<ctype.h>

void strupr ( char *texto )
{
    while( *texto )
    {
        *texto=toupper( *texto );
        texto++;
    }
}

int main(){
    char *texto;
    FILE *archivo;

    archivo=fopen("/proc/version","r");

    int longitud= sizeof(*archivo);

    texto= malloc(longitud);
    fgets(texto,longitud,archivo);
    fclose(archivo);

    strupr(texto);
    puts(texto);
    free(texto);
}
