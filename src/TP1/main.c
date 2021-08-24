#include "function.h"



int main() {
    puts("Punto 1:");
    int RAM_total, RAM_libre, RAM_disponible,SwapOcupada;

    iYii(&RAM_total,&RAM_libre,&RAM_disponible,&SwapOcupada);//Metodo que devuelve mediante puntero los valores requeridos
    printf("i.\nla Ram disponible es: %dMb\nla Ram libre es: %dMb\nla Ram total es: %dMb\n\nii.\nLa Swap Ocupada es: %dKb\n"
           ,RAM_disponible,RAM_libre,RAM_total,SwapOcupada);

    char *Cpu=(char*)malloc(sizeof(char)*64);//No hay un criterio para alocar esta cantidad de memoria, el unico fin es que la info del cpu entre
    int Cores,Thread;

    iii(Cpu,&Cores,&Thread);//Metodo que devuelve mediante puntero los valores requeridos
    printf("\niii.\nCpu:%s \nCantidad de Cores: %d \nCantidad de Threads por Core: %d",Cpu,Cores,Thread);

    free(Cpu);

    puts("\n\n");
    puts("Punto 2:");

    char **texto;
    texto=(char**) malloc(sizeof(char*));
    int cantpalabras=0;

    punto2(&texto,&cantpalabras);

    for(int i=0;i<cantpalabras ; i++)
    {
        puts(texto[i]);
    }

    free(texto);//libero memoria

    puts("Punto 3:");

    /*
     * Agrego un conjunto de valores al azar, para verificar que se almacenan al final
     * de la lista es necesario recurrir a revisar al codigo o un debug linea a linea.
     */

    Lista lista;

    init(&lista);
    add(&lista,1);
    add(&lista,2);
    add(&lista,3);
    add(&lista,4);
    add(&lista,5);
    add(&lista,6);
    add(&lista,67);

    //Se implemento asi y no de otra forma para dejar en evidencia el enlace
    printf("%d %d %d %d %d %d %d",lista.head->dato,lista.head->siguiente->dato,lista.head->siguiente->siguiente->dato
           ,lista.head->siguiente->siguiente->siguiente->dato,lista.head->siguiente->siguiente->siguiente->siguiente->dato
           ,lista.head->siguiente->siguiente->siguiente->siguiente->siguiente->dato
           ,lista.head->siguiente->siguiente->siguiente->siguiente->siguiente->siguiente->dato);

    return 0;
}
