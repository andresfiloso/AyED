#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED

#include <string>
#include "ListaJugadores.h"

using namespace std;

typedef struct  {
    int idEquipo;
    string nombreEquipo;
    string nombreUsuario;
    float monto;
    ListaJ ARQ;
    ListaJ DEF;
    ListaJ MED;
    ListaJ DEL;
} Equipo;


void constructor(Equipo &equipo);

void destructor(Equipo &equipo);

void setIdEquipo(Equipo &equipo, int idEquipo);

int getIdEquipo(Equipo &equipo);

string getNombreEquipo(Equipo &equipo);

void setNombreEquipo(Equipo &equipo, string nombreEquipo);

string getNombreUsuario(Equipo &equipo);

void setNombreUsuario(Equipo &equipo, string nombreUsuario);

float getMonto(Equipo &equipo);

void setMonto(Equipo &equipo, float monto);

ListaJ& getListaARQ(Equipo &equipo);

void setListaARQ(Equipo &equipo, ListaJ &ARQ);

ListaJ& getListaDEF(Equipo &equipo);

void setListaDEF(Equipo &equipo, ListaJ &DEF);

ListaJ& getListaMED(Equipo &equipo);

void setListaMED(Equipo &equipo, ListaJ &MED);

ListaJ& getListaDEL(Equipo &equipo);

void setListaDEL(Equipo &equipo, ListaJ &DEL);









#endif // EQUIPO_H_INCLUDED
