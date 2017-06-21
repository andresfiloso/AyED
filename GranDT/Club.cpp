#include "Club.h"

void constructor(Club &club){
   club.idClub = 0;
   club.nombre = "";
}

void destructor(Club &club){
}

int getIdClub(Club &club){
    return club.idClub;
}

void setIdClub(Club &club, int idClub){
    club.idClub = idClub;
}

string getNombre(Club &club){
    return club.nombre;
}

void setNombre(Club &club, string nombre ){
    club.nombre = nombre;
}
