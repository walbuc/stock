#include "Piso.h"
#include "AdminEstanteria.h"
#include "Funciones.h"

void construirPiso(Piso &piso){
    piso.nroPiso=0;
    Lista listaUbicacion;
    crearLista(listaUbicacion,&compararDatoUbicacion);
    piso.listaUbicacion=listaUbicacion;
}

int getNroPisos(Piso &piso){
    return piso.nroPiso;
}

void setNroPisos(Piso &piso, int nro){
    piso.nroPiso=nro;

}
Lista& getListaUbicacion(Piso &piso){
    return piso.listaUbicacion;
}

void setListaUbicacion(Piso &piso, Lista listaUbicacion){
    piso.listaUbicacion=listaUbicacion;

}
