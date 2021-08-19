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
    puts("Punto2:");

    char *texto;
    FILE *archivo;

    archivo=fopen("/proc/version","r");

    /*guardo en una variable el tamaño del archivo al cual apunta, como el texto 
     * posee solo texto, la idea es obtener almenos, la memoria minima necesaria
    */
    int longitud= sizeof(*archivo);
    texto= (char*)malloc(sizeof (char )*longitud);
    fgets(texto,longitud,archivo);//con fgets guardo en un string la cadena de caracteres del archivo
    fclose(archivo);

    /*aprovechamos el arreglo dinamico y realocamos la memoria, y colocamos unicamente 
     * el texto que contine.
    */
    texto=realloc(texto, sizeof(char)*strlen(texto));
    strupr(texto);//Esto me sorprendio, tuve que implemetar el metodo strupr, hubiera jurado que estaba en la lib strings.h
    puts(texto);
    free(texto);//libero memoria

    puts("\n");
    puts("Punto3:");

    /*agrego un conjunto de valores al azar, para verificar que se almacenan al final
     *de la lista es necesario recurrir a revisar al codigo o un debug linea a linea.
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

    imprimirlista(*lista.head);

    return 0;
}
