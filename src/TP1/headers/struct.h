#ifndef STRUCT
#define STRUCT

typedef struct Nodo{
    int dato;
    struct Nodo *siguiente;
}nodo;

typedef struct{
    nodo *head;
}Lista;

#endif
