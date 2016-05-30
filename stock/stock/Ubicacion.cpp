#include "Ubicacion.h"


PtrDato construirUbicacion(Ubicacion &ubicacion){
    PtrDato puntero= new Ubicacion;
    ubicacion.nroUbicacion=0;
    Articulo articulo;
    constructor(articulo);
    ubicacion.articulo= articulo;
    return puntero;
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
