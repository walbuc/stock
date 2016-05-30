#ifndef UBICACION_H
#define UBICACION_H
#include "Articulo.h"
#include "Lista.h"


typedef struct {
    int nroUbicacion;
    Articulo articulo;

}Ubicacion;

PtrDato construirUbicacion(Ubicacion &ubicacion);

int getNroUbicacion(Ubicacion &ubicacion);

void setNroUbicacion(Ubicacion &ubicacion, int nroUbicacion);

Articulo getArticulo (Ubicacion &ubicacion);

void setArticulo (Ubicacion &ubicacion, Articulo articulo);


#endif // UBICACION_H
