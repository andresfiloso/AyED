#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <string>

using namespace std;

enum Posicion{
       INDEF,
       ARQ,
       DEF,
       MED,
       DEL
    };

typedef struct  {
    int idJugador;
    string nombre;
    Posicion posicion;
    float valor;
} Jugador;

void constructor(Jugador &jugador);

void destructor(Jugador &jugador);

void setIdJugador(Jugador &jugador, int idJugador);

int getIdJugador(Jugador &jugador);

string getNombre(Jugador &jugador);

void setNombre(Jugador &jugador, string nombre);

Posicion& getPosicion(Jugador &jugador);

void setPosicion(Jugador &jugador, Posicion posicion);

float getValor(Jugador &jugador);

void setValor(Jugador &jugador, float valor);

#endif // CLUB_H_INCLUDED
