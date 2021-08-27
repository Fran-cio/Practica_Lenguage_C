#ifndef FUNCIONES
#define FUNCIONES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "struct.h"
//Punto1
void deKbaMb(int *numero);
void iYii(int *RAM_total, int *RAM_Libre, int *RAM_disponible, int *SwapOcupada);
void iii(char *Cpu, int *Cores, int *Thread);
//Punto2
void strupr(char *texto);
void punto2(char ***texto, int *cantpalabras);
//Punto3
//Coloca los valores iniciales en los nodos de la lista
void init(Lista *lista);
void agregarnodo(nodo **node, int valor);
void add(Lista *lista, int valor);
#endif
