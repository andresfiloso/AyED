#include "Equipo.h"
#include <string>
#include "ListaEquipos.h"

using namespace std;

void constructor(Equipo &equipo){
    equipo.idEquipo = 0;
    equipo.nombreEquipo = "";
    equipo.nombreUsuario = "";
    equipo.monto = 0;
    crearLista(equipo.ARQ);
    crearLista(equipo.DEF);
    crearLista(equipo.MED);
    crearLista(equipo.DEL);
}

void destructor(Equipo &equipo){}


int getIdEquipo(Equipo &equipo){
    return equipo.idEquipo;
}

void setIdEquipo(Equipo &equipo, int idEquipo){
    equipo.idEquipo = idEquipo;
}

string getNombreEquipo(Equipo &equipo){
    return equipo.nombreEquipo;
}

void setNombreEquipo(Equipo &equipo, string nombreEquipo){
    equipo.nombreEquipo = nombreEquipo;
}

string getNombreUsuario(Equipo &equipo){
    return equipo.nombreUsuario;
}

void setNombreUsuario(Equipo &equipo, string nombreUsuario){
    equipo.nombreUsuario = nombreUsuario;
}
float getMonto(Equipo &equipo){
    return equipo.monto;
}

void setMonto(Equipo &equipo, float monto){
    equipo.monto = monto;
}

ListaJ& getListaARQ(Equipo &equipo){
    return equipo.ARQ;
}

void setListaARQ(Equipo &equipo, ListaJ &ARQ){
    equipo.ARQ = ARQ;
}

ListaJ& getListaDEF(Equipo &equipo){
    return equipo.DEF;
}

void setListaDEF(Equipo &equipo, ListaJ &DEF){
    equipo.DEF = DEF;
}

ListaJ& getListaMED(Equipo &equipo){
    return equipo.MED;
}

void setListaMED(Equipo &equipo, ListaJ &MED){
    equipo.MED = MED;
}

ListaJ& getListaDEL(Equipo &equipo){
    return equipo.DEL;
}

void setListaDEL(Equipo &equipo, ListaJ &DEL){
    equipo.DEL = DEL;
}
