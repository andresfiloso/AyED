#ifndef PUNTOSFECHA_H_INCLUDED
#define PUNTOSFECHA_H_INCLUDED


typedef struct  {
    int idJugador;
    int fecha;
    int puntos;
} PuntosFecha;


void constructor(PuntosFecha &puntosFecha);

void destructor(PuntosFecha &puntosFecha);

void setIdJugador(PuntosFecha &puntosFecha, int idJugador);

int getIdJugador(PuntosFecha &puntosFecha);

void setFecha(PuntosFecha &puntosFecha, int fecha);

int getFecha(PuntosFecha &puntosFecha);

void setPuntos(PuntosFecha &puntosFecha, int puntos);

int getPuntos(PuntosFecha &puntosFecha);


#endif // EQUIPO_H_INCLUDED
