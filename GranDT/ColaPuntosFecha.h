//TDA Cola, DEFINICIONES
#ifndef COLAPUNTOSFECHA_H_INCLUDED
#define COLAPUNTOSFECHA_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

#include "PuntosFecha.h"
//Puntero a void para datos de la cola
typedef PuntosFecha ptrDato;

//Estructura de la cola
struct nodoCola{
       ptrDato ptrdato; //Dato almacenado en la cola
       nodoCola *siguiente;
};

//Puntero a la cola, para acceder al primer elemento de la misma
typedef nodoCola *ptrNodoCola;

//Estructura de la cola
struct Cola {
       ptrNodoCola primero;
};

//Funciones
void crearCola (Cola &cola);
void eliminarCola (Cola &cola);
ptrNodoCola crearNodo (Cola &cola, ptrDato dato);
void eliminarNodo(Cola &cola, ptrNodoCola nodo);
void encolar(Cola &cola, ptrDato dato);//Lo pone al final
void desencolar (Cola &cola);//Saca al primer nodo
ptrNodoCola primero (Cola &cola);
ptrNodoCola anterior (Cola &cola, ptrNodoCola &nodo);
ptrNodoCola siguiente (ptrNodoCola &nodo);
ptrNodoCola ultimo (Cola &cola);
ptrNodoCola finCola();
ptrDato getDato(ptrNodoCola &nodo);
//void setDato (ptrNodoLista &nodo, ptrDato dato);
bool colaVacia (Cola &cola);
bool validarCola (Cola &cola, ptrNodoCola &nodo);
#endif

