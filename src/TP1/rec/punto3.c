#include "../headers/function.h"

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


