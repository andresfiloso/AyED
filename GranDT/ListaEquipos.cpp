#include "ListaEquipos.h"
/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
ResultadoComparacionE compararDato(DatoE dato1, DatoE dato2) {
    if (getIdEquipo(dato1) > getIdEquipo(dato2)) {
        return MAYOR_E;
    }
    else if (getIdEquipo(dato1) < getIdEquipo(dato2)) {
        return MENOR_E;
    }
    else {
        return IGUAL_E;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(ListaE &lista) {
  lista.primero = fin_E();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(ListaE &lista) {

  return (primero(lista) == fin_E());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE fin_E() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE primero(ListaE &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE siguiente(ListaE &lista, PtrNodoListaE ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != fin_E()))
    return ptrNodo->sgte;
  else
    return fin_E();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE anterior(ListaE &lista, PtrNodoListaE ptrNodo) {

  PtrNodoListaE ptrPrevio = fin_E();
  PtrNodoListaE ptrCursor = primero(lista);

  while (( ptrCursor != fin_E()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE ultimo(ListaE &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,fin_E());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE crearNodoLista(DatoE dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaE ptrAux = new NodoListaE;

  ptrAux->dato = dato;
  ptrAux->sgte = fin_E();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE adicionarPrincipio(ListaE &lista, DatoE dato) {

  /* crea el nodo */
  PtrNodoListaE ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE adicionarDespues(ListaE &lista, DatoE dato, PtrNodoListaE ptrNodo) {

  PtrNodoListaE ptrNuevoNodo = fin_E();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != fin_E()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE adicionarFinal(ListaE &lista, DatoE dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE adicionarAntes(ListaE &lista, DatoE dato, PtrNodoListaE ptrNodo) {

  PtrNodoListaE ptrNuevoNodo = fin_E();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(ListaE &lista, DatoE &dato, PtrNodoListaE ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != fin_E()))
    ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(ListaE &lista, DatoE &dato, PtrNodoListaE ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != fin_E()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaE &lista, PtrNodoListaE ptrNodo) {

  PtrNodoListaE ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != fin_E())) {

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaE &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaE &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaE &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE localizarDato(ListaE &lista, DatoE dato) {

   bool encontrado = false;
   DatoE datoCursor;
   PtrNodoListaE ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin_E()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin_E();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(ListaE &lista, DatoE dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaE ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != fin_E())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaE insertarDato(ListaE &lista, DatoE dato) {

  PtrNodoListaE ptrPrevio = primero(lista);
  PtrNodoListaE ptrCursor = primero(lista);
  PtrNodoListaE ptrNuevoNodo;
  DatoE datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin_E()) && (! ubicado)) {

    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(ListaE &lista) {

  ListaE temp = lista;
  PtrNodoListaE ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != fin_E() ) {
        DatoE dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(ListaE &lista){
  PtrNodoListaE ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != fin_E() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/


