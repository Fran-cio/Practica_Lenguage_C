#include "function.h"

int main() {
    puts("Punto 1:");
    int RAM_total, RAM_libre, RAM_disponible,SwapOcupada;

    iYii(&RAM_total,&RAM_libre,&RAM_disponible,&SwapOcupada);
    printf("i.\nla Ram disponible es: %dMb\nla Ram libre es: %dMb\nla Ram total es: %dMb\n\nii.\nLa Swap Ocupada es: %dKb\n"
           ,RAM_disponible,RAM_libre,RAM_total,SwapOcupada);

    char *Cpu=malloc(64);
    int Cores,Thread;

    iii(Cpu,&Cores,&Thread);
    printf("\niii.\nCpu:%s \nCantidad de Cores: %d \nCantidad de Threads por Core: %d",Cpu,Cores,Thread);

    free(Cpu);

    puts("\n\n");
    puts("Punto2:");

    char *texto;
    FILE *archivo;

    archivo=fopen("/proc/version","r");

    int longitud= sizeof(*archivo);

    texto= (char*)malloc(sizeof (char )*longitud);
    fgets(texto,longitud,archivo);
    fclose(archivo);
    texto=realloc(texto, sizeof(char)*strlen(texto));

    strupr(texto);
    puts(texto);
    free(texto);

    puts("\n");
    puts("Punto3:");

    Lista lista;
    init(&lista);
    add(&lista,1);
    add(&lista,2);
    add(&lista,3);
    add(&lista,4);
    add(&lista,5);
    add(&lista,6);
    add(&lista,67);

    imprimirlista(*lista.head);

    return 0;
}
