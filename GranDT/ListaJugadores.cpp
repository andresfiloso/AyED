#include "ListaJugadores.h"
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
ResultadoComparacionJ compararDato(DatoJ dato1, DatoJ dato2) {
    if (getIdJugador(dato1) > getIdJugador(dato2)) {
        return MAYOR;
    }
    else if (getIdJugador(dato1) < getIdJugador(dato2)) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(ListaJ &lista) {
  lista.primero = fin_J();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(ListaJ &lista) {

  return (primero(lista) == fin_J());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ fin_J() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ primero(ListaJ &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ siguiente(ListaJ &lista, PtrNodoListaJ ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != fin_J()))
    return ptrNodo->sgte;
  else
    return fin_J();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ anterior(ListaJ &lista, PtrNodoListaJ ptrNodo) {

  PtrNodoListaJ ptrPrevio = fin_J();
  PtrNodoListaJ ptrCursor = primero(lista);

  while (( ptrCursor != fin_J()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ ultimo(ListaJ &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,fin_J());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ crearNodoLista(DatoJ dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaJ ptrAux = new NodoListaJ;

  ptrAux->dato = dato;
  ptrAux->sgte = fin_J();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ adicionarPrincipio(ListaJ &lista, DatoJ dato) {

  /* crea el nodo */
  PtrNodoListaJ ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ adicionarDespues(ListaJ &lista, DatoJ dato, PtrNodoListaJ ptrNodo) {

  PtrNodoListaJ ptrNuevoNodo = fin_J();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != fin_J()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ adicionarFinal(ListaJ &lista, DatoJ dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ adicionarAntes(ListaJ &lista, DatoJ dato, PtrNodoListaJ ptrNodo) {

  PtrNodoListaJ ptrNuevoNodo = fin_J();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(ListaJ &lista, DatoJ &dato, PtrNodoListaJ ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != fin_J()))
    ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(ListaJ &lista, DatoJ &dato, PtrNodoListaJ ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != fin_J()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaJ &lista, PtrNodoListaJ ptrNodo) {

  PtrNodoListaJ ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != fin_J())) {

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
void eliminarNodoPrimero(ListaJ &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaJ &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaJ &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ localizarDato(ListaJ &lista, DatoJ dato) {

   bool encontrado = false;
   DatoJ datoCursor;
   PtrNodoListaJ ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin_J()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin_J();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(ListaJ &lista, DatoJ dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaJ ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != fin_J())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJ insertarDato(ListaJ &lista, DatoJ dato) {

  PtrNodoListaJ ptrPrevio = primero(lista);
  PtrNodoListaJ ptrCursor = primero(lista);
  PtrNodoListaJ ptrNuevoNodo;
  DatoJ datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin_J()) && (! ubicado)) {

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

void reordenar(ListaJ &lista) {

  ListaJ temp = lista;
  PtrNodoListaJ ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != fin_J() ) {
        DatoJ dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(ListaJ &lista){
  PtrNodoListaJ ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != fin_J() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/

