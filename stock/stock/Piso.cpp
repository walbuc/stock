#include "Piso.h"
#include "AdminEstanteria.h"
#include "Funciones.h"

PtrDato construirPiso(Piso &piso){

    PtrDato puntero= new Piso;
    piso.nroPiso=0;
    Lista listaUbicacion;
    crearLista(listaUbicacion,&compararDatoUbicacion);
    piso.listaUbicacion=listaUbicacion;

    return puntero;
}

int getNroPisos(Piso &piso){
    return piso.nroPiso;
}

void setNroPisos(Piso &piso, int nro){
    piso.nroPiso=nro;

}
PtrDato getListaUbicacion(Piso &piso){
    return &piso.listaUbicacion;
}

void setListaUbicacion(Piso &piso, Lista listaUbicacion){
    piso.listaUbicacion=listaUbicacion;

}
