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

void iii(char *Cpu,char *Cores,char *Thread){
    char temp[12];

    char palabra[64];
    FILE *archivo;
    archivo = fopen("/proc/cpuinfo", "r");
    do{
        int j=0;
        fgets(palabra,64,archivo);
        for(int i=0; i<12;i++){
            temp[i]='\000';
        }
        for(int i=0; palabra[i]!=':';i++){
            temp[i]=palabra[i];
            j=i;
        }
        if(!strcmp(temp,"model name\t")){
            while (palabra[j]!='\n'){
                *Cpu=palabra[j];
                j++;
                Cpu++;
            };
        }
        else if(!strcmp(temp,"siblings\t")){
            while (palabra[j]!='\n'){
                *Cores=palabra[j];
                j++;
                Cores++;
            };
        }
        else if(!strcmp(temp,"cpu cores\t")){
            while (palabra[j]!='\n'){
                *Thread=palabra[j];
                j++;
                Thread++;
            };
        }
        else if(!strcmp(temp,"flags\t\t")){
            break;
        }
    }while (!feof(archivo));
    fclose(archivo);
}

void iYii(int *RAM_total,int *RAM_Libre,int *RAM_disponible, int *SwapOcupada){
    int SwapLibre,SwapTotal,temp;
    char palabra[20];
    FILE *archivo1;

    archivo1 = fopen("/proc/meminfo", "r");
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
            break;
        }
    };
    fclose(archivo1);

    deKbaMb(RAM_disponible);
    deKbaMb(RAM_Libre);
    deKbaMb(RAM_total);
    *SwapOcupada=SwapTotal-SwapLibre;
}

//Punto2

void strupr ( char *texto )
{
    while( *texto )
    {
        *texto=toupper( *texto );
        texto++;
    }
}

//Punto3

void init(Lista *lista){
    lista->head=NULL;
    lista->tail=malloc(sizeof(struct Nodo));
    lista->tail->dato=(uintptr_t)NULL;
}

void add(Lista *lista,int valor){
    if (lista->head==NULL) {
        nodo temp;
        temp.dato=valor;
        temp.siguiente=lista->tail;
        lista->head=&temp;
    }else if(lista->tail->dato==(uintptr_t)NULL){
        lista->tail->dato=valor;
    }
    else {
        nodo *temp= malloc(sizeof(struct Nodo));
        temp->dato=valor;
        temp->siguiente=NULL;
        lista->tail->siguiente=temp;
        lista->tail=temp;
    }
}

void imprimirlista(nodo node){
    do{
        printf("%d ",node.dato );
        node=*node.siguiente;
    }while(node.siguiente!=NULL);
    printf("%d ",node.dato );
}

#endif
