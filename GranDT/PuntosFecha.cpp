#include "PuntosFecha.h"

void constructor(PuntosFecha &puntosFecha){
    int idJugador = 0;
    int fecha = 0;
    int puntos = -100;
}

void destructor(PuntosFecha &puntosFecha){}

void setIdJugador(PuntosFecha &puntosFecha, int idJugador){
    puntosFecha.idJugador = idJugador;
}

int getIdJugador(PuntosFecha &puntosFecha){
    return puntosFecha.idJugador;
}

void setFecha(PuntosFecha &puntosFecha, int fecha){
    puntosFecha.fecha = fecha;
}

int getFecha(PuntosFecha &puntosFecha){
    return puntosFecha.fecha;
}

void setPuntos(PuntosFecha &puntosFecha, int puntos){
    puntosFecha.puntos = puntos;
}

int getPuntos(PuntosFecha &puntosFecha){
    return puntosFecha.puntos;
}
