#include "Ubicacion.h"



void construirUbicacion(Ubicacion &ubicacion){
    setNroUbicacion(ubicacion, 0);
    constructor(ubicacion.articulo);
}

int getNroUbicacion(Ubicacion &ubicacion){
    return ubicacion.nroUbicacion;
}

void setNroUbicacion(Ubicacion &ubicacion, int nroUbicacion){
    ubicacion.nroUbicacion=nroUbicacion;

}

Articulo getArticulo (Ubicacion &ubicacion){
    return ubicacion.articulo;

}

void setArticulo (Ubicacion &ubicacion, Articulo articulo){
    ubicacion.articulo=articulo;
}
