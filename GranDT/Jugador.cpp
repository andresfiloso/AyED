#include <string>
#include "Jugador.h"

void constructor(Jugador &jugador){
    jugador.idJugador = 0;
    jugador.posicion = INDEF;
    jugador.nombre = "";
    jugador.valor = 0;
}

void destructor(Jugador &jugador){}

void setIdJugador(Jugador &jugador, int idJugador){
    jugador.idJugador = idJugador;
}

int getIdJugador(Jugador &jugador){
    return jugador.idJugador;
}

string getNombre(Jugador &jugador){
    return jugador.nombre;
}

void setNombre(Jugador &jugador, string nombre){
    jugador.nombre = nombre;
}

Posicion& getPosicion(Jugador &jugador){
    return jugador.posicion;
}

void setPosicion(Jugador &jugador, Posicion posicion){
    jugador.posicion = posicion;
}

float getValor(Jugador &jugador){
    return jugador.valor;
}

void setValor(Jugador &jugador, float valor){
    jugador.valor = valor;
}
