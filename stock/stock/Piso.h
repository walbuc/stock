#ifndef PISO_H
#define PISO_H
#include "Lista.h"
#include "Ubicacion.h"


typedef struct{
    int nroPiso;
    Lista listaUbicacion;

} Piso;


/*funciones extras*/

void construirPiso(Piso &piso);

int getNroPisos(Piso &piso);

void setNroPisos(Piso &piso, int nro);

Lista& getListaUbicacion(Piso &piso);

void setListaUbicacion(Piso &piso, Lista listaUbicacion);





#endif // PISO_H
