#ifndef UBICACION_H
#define UBICACION_H
#include "Articulo.h"
#include "Lista.h"


typedef struct {
    int nroUbicacion;
    float cantidad;
    Articulo articulo;

}Ubicacion;

void construirUbicacion(Ubicacion &ubicacion);

int getNroUbicacion(Ubicacion &ubicacion);

void setNroUbicacion(Ubicacion &ubicacion, int nroUbicacion);

Articulo getArticulo (Ubicacion &ubicacion);

void setArticulo (Ubicacion &ubicacion, Articulo articulo);

void setCantidad (Ubicacion &ubicacion, float cantidad);

float getCantidad (Ubicacion &ubicacion);

#endif // UBICACION_H
