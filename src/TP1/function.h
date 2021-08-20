#ifndef FUNCIONES
#define FUNCIONES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "struct.h"

//Punto 1

void deKbaMb(int *numero){
    *numero/=1024;
}
//apartado i y ii del punto 1. Como se usa el mismo archivo lo hice todo junto aca
void iYii(int *RAM_total,int *RAM_Libre,int *RAM_disponible, int *SwapOcupada){
    int SwapLibre,SwapTotal,temp;
    char palabra[20];
    FILE *archivo1;

    archivo1 = fopen("/proc/meminfo", "r");
    /* Con scanf aprovechamos que los  datos estan ordenados en patrones regualres
     * entonces esperamos un string int string y asi filtramos el numero unicamente,
     * y posterior mentente lo guardamos en la variable*/
    while (fscanf(archivo1, "%s %d %*s", palabra, &temp)) {
        if (!strcmp(palabra, "MemTotal:")) {
            *RAM_total=temp;
        }
        else if(!strcmp(palabra, "MemFree:")) {
            *RAM_Libre=temp;
        }
        else if (!strcmp(palabra, "MemAvailable:")) {
            *RAM_disponible=temp;
        }
        else if (!strcmp(palabra, "SwapTotal:")) {
            SwapTotal=temp;
        }
        else if (!strcmp(palabra, "SwapFree:")) {
            SwapLibre=temp;
            /*esta es una decision poco escalable ya que aprovechamos que de entrada
             *sabemos la distribucion de los datos en el texto.
            */
            break;
        }
    };
    fclose(archivo1);

    deKbaMb(RAM_disponible);
    deKbaMb(RAM_Libre);
    deKbaMb(RAM_total);
    //No sabia si swap cached era el dato asi que saque la dif entre la total y la libre
    *SwapOcupada=SwapTotal-SwapLibre;
}

//apartado iii del punto 1
void iii(char *Cpu,int *Cores,int *Thread){
    char temp[13];
    char cores[3],thread[3];

    char palabra[64];
    FILE *archivo;
    archivo = fopen("/proc/cpuinfo", "r");
    do{
        int j=0;
        fgets(palabra,64,archivo);
        /*Setea todos los espacios de temp como el
        * caracter de vacio para evitar que de ciclo a ciclo se
        * acumulen caracteres previos.
        */
        for(int i=0; i<13;i++){
            temp[i]='\000';
        }
        //filtramos y agregamos a temp hasta encontrar :
        for(int i=0; palabra[i]!=':';i++){
            temp[i]=palabra[i];
            j=i;
        }
        j++;
        //se agrega el : para facilitar el paso a int
        temp[j]=palabra[j];
        j++;
        /*apartir de aca discriminamos los datos que no sean de interes
         *ya que en la variable temp, se acumulan los nombres de estos datos
         *y en el resto del arreglo palabra, el dato.
         */
        if(!strcmp(temp,"model name\t:")){
            while (palabra[j]!='\n'){
                *Cpu=palabra[j];
                j++;
                Cpu++;
            };
        }
        //Se usan arreglos y no la variable recibida para despues castearlos a int
        else if(!strcmp(temp,"siblings\t:")){
            int i=0;
            while (palabra[j]!='\n'){
                thread[i]=palabra[j];
                j++;
                i++;
            };
        }
        else if(!strcmp(temp,"cpu cores\t:")){
            int i=0;
            while (palabra[j]!='\n'){
                cores[i]=palabra[j];
                j++;
                i++;
            };
        }
        /* Para no recorrer todo el archivo de manera inncesaria
         * se espera a detectar flags, siendo el ultimo de la lista
         * de valores de interes, hace un break para dejar de leer.
         * */
        else if(!strcmp(temp,"flags\t\t:")){
            break;
        }
    }while (!feof(archivo));
    fclose(archivo);
    //Con atoi pasamos el arreglo a entero.
    *Cores= atoi(cores);
    *Thread= atoi(thread)/(*Cores);
}
//Punto2
//Pasa a mayusculas los valores en un string
void strupr ( char *texto )
{
    while( *texto )
    {
        *texto=toupper( *texto );
        texto++;
    }
}

//Punto3
//Coloca los valores iniciales en los nodos de la lista

void init(Lista *lista){
    lista->head=NULL;
}


void agregarnodo(nodo **node,int valor){
    //El mismo concepto que antes pero ahora es un nodo de una pos n
    if ((*node)==NULL) {
        nodo temp;
        temp.dato=valor;
        temp.siguiente=NULL;
        (*node)=&temp;
    }
    else {
        //Asi hasta llegar al ultimo nodo
        agregarnodo(&(*node)->siguiente,valor);
    }
}

void add(Lista *lista,int valor){
    /* En el primer dato la head va a ser null, entoces creamos un
     * nodo temporal, colocamos el dato 
     */
    if (lista->head==NULL) {
        nodo temp;
        temp.dato=valor;
        temp.siguiente=NULL;
        lista->head=&temp;
    }
    else {
        //Ya el resto de datos se agregan mediante la siguiente func recursiva
        agregarnodo(&lista->head->siguiente,valor);
    }
}

#endif
