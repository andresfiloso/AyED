#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED
#include <string>

using namespace std;

typedef struct  {
    int idClub;
    string nombre;
} Club;

void constructor(Club &club);

void destructor(Club &club);

void setIdClub(Club &club, int idClub);

int getIdClub(Club &club);

string getNombre(Club &club);

void setNombre(Club &club, string nombre);

#endif // CLUB_H_INCLUDED
