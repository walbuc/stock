#include "Ubicacion.h"


void construirUbicacion(Ubicacion &ubicacion){
    ubicacion.nroUbicacion=0;
    ubicacion.cantidad=0;
    Articulo articulo;
    constructor(articulo);
    ubicacion.articulo= articulo;
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

float getCantidad (Ubicacion &ubicacion){
    return ubicacion.cantidad;

}

void setCantidad (Ubicacion &ubicacion, float cantidad){
    ubicacion.cantidad=cantidad;
}
