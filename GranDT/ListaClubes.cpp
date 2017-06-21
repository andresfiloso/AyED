#include "ListaClubes.h"
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
ResultadoComparacionC compararDato(DatoC dato1, DatoC dato2) {
    if (getIdClub(dato1) > getIdClub(dato2)) {
        return MAYOR_C;
    }
    else if (getIdClub(dato1) < getIdClub(dato2)) {
        return MENOR_C;
    }
    else {
        return IGUAL_C;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(ListaC &lista) {
  lista.primero = fin_C();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(ListaC &lista) {

  return (primero(lista) == fin_C());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC fin_C() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC primero(ListaC &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC siguiente(ListaC &lista, PtrNodoListaC ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != fin_C()))
    return ptrNodo->sgte;
  else
    return fin_C();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC anterior(ListaC &lista, PtrNodoListaC ptrNodo) {

  PtrNodoListaC ptrPrevio = fin_C();
  PtrNodoListaC ptrCursor = primero(lista);

  while (( ptrCursor != fin_C()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC ultimo(ListaC &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,fin_C());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC crearNodoLista(DatoC dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaC ptrAux = new NodoListaC;

  ptrAux->dato = dato;
  ptrAux->sgte = fin_C();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC adicionarPrincipio(ListaC &lista, DatoC dato) {

  /* crea el nodo */
  PtrNodoListaC ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC adicionarDespues(ListaC &lista, DatoC dato, PtrNodoListaC ptrNodo) {

  PtrNodoListaC ptrNuevoNodo = fin_C();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != fin_C()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC adicionarFinal(ListaC &lista, DatoC dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC adicionarAntes(ListaC &lista, DatoC dato, PtrNodoListaC ptrNodo) {

  PtrNodoListaC ptrNuevoNodo = fin_C();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(ListaC &lista, DatoC &dato, PtrNodoListaC ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != fin_C()))
    ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(ListaC &lista, DatoC &dato, PtrNodoListaC ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != fin_C()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaC &lista, PtrNodoListaC ptrNodo) {

  PtrNodoListaC ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != fin_C())) {

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
void eliminarNodoPrimero(ListaC &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaC &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaC &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC localizarDato(ListaC &lista, DatoC dato) {

   bool encontrado = false;
   DatoC datoCursor;
   PtrNodoListaC ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin_C()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL_C)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin_C();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(ListaC &lista, DatoC dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaC ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != fin_C())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaC insertarDato(ListaC &lista, DatoC dato) {

  PtrNodoListaC ptrPrevio = primero(lista);
  PtrNodoListaC ptrCursor = primero(lista);
  PtrNodoListaC ptrNuevoNodo;
  DatoC datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin_C()) && (! ubicado)) {

    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == MAYOR_C)
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

void reordenar(ListaC &lista) {

  ListaC temp = lista;
  PtrNodoListaC ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != fin_C() ) {
        DatoC dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(ListaC &lista){
  PtrNodoListaC ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != fin_C() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
