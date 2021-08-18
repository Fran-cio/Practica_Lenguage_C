#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    int dato;
    struct Nodo *siguiente;
}nodo;

typedef struct{
    nodo *head;
    nodo *tail;
}Lista;

void init(Lista *lista);
void add(Lista *lista,int valor);
void agregaralnodo(nodo **node,int valor);

int main(){
    Lista lista;
    //nodo *head=(struct Nodo*) malloc(sizeof(struct Nodo));;
    init(&lista);
    add(&lista,1);
    add(&lista,2);
    add(&lista,3);

    printf("%d %d %d ",lista.head->dato,lista.head->siguiente->siguiente->dato
    ,lista.head->siguiente->siguiente->siguiente->dato);
    return 0;
}

void init(Lista *lista){
    lista->head=NULL;
    lista->tail=malloc(sizeof(struct Nodo));
}

void add(Lista *lista,int valor){
    if (lista->head==NULL) {
        nodo temp;
        temp.dato=valor;
        temp.siguiente=lista->tail;
        lista->head=&temp;
    }
    else {
        nodo *temp= malloc(sizeof(struct Nodo));
        temp->dato=valor;
        temp->siguiente=NULL;
        lista->tail->siguiente=temp;
        lista->tail=temp;
    }
}
