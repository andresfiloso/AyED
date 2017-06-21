//TDA Cola, implementación
#include "ColaPuntosFecha.h"

void crearCola (Cola &cola){
    cola.primero= finCola(); //Crea la cola con el primer elemento a NULL
}

void eliminarCola (Cola &cola){
    while (!colaVacia(cola))//Mientras no esté vacía
        eliminarNodo(cola, primero(cola));//Elimina los nodos primeros
}

ptrNodoCola crearNodo (Cola &cola, ptrDato dato){
    ptrNodoCola nuevoNodo= new nodoCola; //Reserva memoria para el nodo

    nuevoNodo->ptrdato= dato;
    nuevoNodo->siguiente= finCola();

    return nuevoNodo;
}

void eliminarNodo (Cola &cola, ptrNodoCola nodo){
    if (validarCola (cola, nodo)){
        if (nodo== primero(cola))
            cola.primero= siguiente (nodo);
    }
    else{
        ptrNodoCola predecesor= anterior(cola, nodo);
        predecesor->siguiente= nodo->siguiente;
    }
}

void encolar (Cola &cola, ptrDato dato){
    //Crea el nodo para agregarlo
    ptrNodoCola agregado= crearNodo(cola, dato);
    if (colaVacia(cola)) cola.primero= agregado;
    else{
        ptrNodoCola predecesor= ultimo (cola);
        agregado->siguiente= predecesor->siguiente;
        predecesor->siguiente= agregado;
    }
}

// cola-> a <- b <- c <- d
void desencolar (Cola &cola){
    ptrNodoCola sacado= primero(cola);
    cola.primero= sacado->siguiente;

    eliminarNodo(cola, sacado);
}

ptrNodoCola anterior (Cola &cola, ptrNodoCola &nodo){
    ptrNodoCola predecesor;
    if (nodo!= primero(cola)){
        ptrNodoCola cursor= primero(cola);

        while (cursor!= nodo){
            predecesor= cursor;
            cursor= siguiente (cursor);
        }
    }

    return predecesor;
}

ptrNodoCola primero (Cola &cola){
    return cola.primero;
}

ptrNodoCola siguiente (ptrNodoCola &nodo){
    return nodo->siguiente;
}

ptrNodoCola ultimo (Cola &cola){
    ptrNodoCola cursor= primero(cola);
    ptrNodoCola predecesor= finCola();

    if (cursor==finCola()) return cursor;
    else{
        while (cursor!=finCola()){
            predecesor= cursor;
            cursor= siguiente(cursor);
        }
        return predecesor;
    }
}

ptrNodoCola finCola(){
    return NULL;
}

ptrDato getDato (ptrNodoCola &nodo){
    return nodo->ptrdato;
}

bool colaVacia(Cola &cola){
    return (primero(cola)==finCola());
}

bool validarCola(Cola &cola, ptrNodoCola &nodo){
    return (!colaVacia(cola) && nodo!=finCola());
}

