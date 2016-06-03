//
//  funciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/15/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//


#include "funciones.h"
#include "lista.h"
#include "articulo.h"
#include "estanteria.h"
#include "Solicitud.h"
#include "Camion.h"
using namespace std;

ResultadoComparacion compararDatoArticulo(PtrDato ptrDato1, PtrDato ptrDato2) {

    if ( (*(Articulo*)ptrDato1).codigoArticulo > (*(Articulo*)ptrDato2).codigoArticulo ) {
        return MAYOR;
    }
    else if (((Articulo*)ptrDato1)->codigoArticulo < ((Articulo*)ptrDato2)->codigoArticulo) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararDatoIndice(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( (*(Indice*)ptrDato1).codigoArticulo > (*(Indice*)ptrDato2).codigoArticulo ) {
        return MAYOR;
    }
    else if (((Indice*)ptrDato1)->codigoArticulo < ((Indice*)ptrDato2)->codigoArticulo) {
        return MENOR;
    }
    else {
        return IGUAL;
    }

}

ResultadoComparacion compararDatoEstanteria(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Estanteria*)ptrDato1)->nroCalle > ((Estanteria*)ptrDato2)->nroCalle ) {
        return MAYOR;
    }
    else if (((Estanteria*)ptrDato1)->nroCalle < ((Estanteria*)ptrDato2)->nroCalle) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararDatoPiso(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Piso*)ptrDato1)->nroPiso > ((Piso*)ptrDato2)->nroPiso ) {
        return MAYOR;
    }
    else if (((Piso*)ptrDato1)->nroPiso < ((Piso*)ptrDato2)->nroPiso) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararDatoUbicacion(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Ubicacion*)ptrDato1)->nroUbicacion > ((Ubicacion*)ptrDato2)->nroUbicacion ) {
        return MAYOR;
    }
    else if (((Ubicacion*)ptrDato1)->nroUbicacion < ((Ubicacion*)ptrDato2)->nroUbicacion) {
        return MENOR;
    }
    else {

  return IGUAL;
    }
}

ResultadoComparacion compararDatoSolicitud(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Solicitud*)ptrDato1)->idSolicitud > ((Solicitud*)ptrDato2)->idSolicitud ) {
        return MAYOR;
    }
    else if (((Solicitud*)ptrDato1)->idSolicitud < ((Solicitud*)ptrDato2)->idSolicitud) {
        return MENOR;
    }
    else {

  return IGUAL;
    }
}

ResultadoComparacion compararDatoCamion(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Camion*)ptrDato1)->nroCamion > ((Camion*)ptrDato2)->nroCamion ) {
        return MAYOR;
    }
    else if (((Camion*)ptrDato1)->nroCamion < ((Camion*)ptrDato2)->nroCamion) {
        return MENOR;
    }
    else {

  return IGUAL;
    }
}


//////////////////////////////////////////////

// Funciones para convertir los datos  //////

////////////////////////////////////////////

/*de string a entero*/

int cadenaAentero(string dato){

    int num;

    stringstream ss(dato);

    ss >> num;

    return num;

}

float cadenaAfloat(string dato){

    float num;

    stringstream ss(dato);

    ss >> num;

    return num;

}

/*de string a char*/

char cadenaACaracter(string dato){

    char num;

    stringstream ss (dato);

    ss >> num;

    return num;

}

//Función quita los espacios en blanco del string

string quitar_espacios(string cadena){

    int inicio_pos;

    int longitud;

    int actual_pos = 0;



    //Avanza en la cadena hasta que detecta un caracter valido

    while(cadena[actual_pos] == ' ' || cadena[actual_pos] == '\n' || cadena[actual_pos] == '\t'){

        actual_pos ++;

    }

    inicio_pos = actual_pos;



    //Retrocede en la cadena hasta encontrar un caracter valido

    actual_pos = cadena.size() - 1;

    while(cadena[actual_pos] == ' ' || cadena[actual_pos] == '\n' || cadena[actual_pos] == '\t'){

        actual_pos --;

    }

    longitud = actual_pos - inicio_pos + 1;

    return cadena.substr(inicio_pos, longitud);

}

///////////////////////////////////////////
////FUNCIONES PARA LIBERAR MEMORIA////////
//////////////////////////////////////////

void eliminarListaAriticulos(Lista &listaArticulos){

     if(!listaVacia(listaArticulos)){
        PtrNodoLista nodo = primero(listaArticulos);
        Articulo* articulo = (Articulo*) nodo->ptrDato;
        destructor(*articulo);
        delete articulo;

        nodo = siguiente(listaArticulos, nodo);
        while(nodo != fin()){
            articulo = (Articulo*) nodo->ptrDato;
            destructor(*articulo);
            delete articulo;

            nodo = siguiente(listaArticulos, nodo);
        }
     }
}//fin void elimina articulos

void eliminarListaEstanteria(Lista &listaEstanteria){

     if(!listaVacia(listaEstanteria)){
        PtrNodoLista nodo = primero(listaEstanteria);
        Estanteria* estanteria = (Estanteria*) nodo->ptrDato;
        destruirEstanteria(*estanteria);
        delete estanteria;

        nodo = siguiente(listaEstanteria, nodo);
        while(nodo != fin()){
            estanteria = (Estanteria*) nodo->ptrDato;
            destruirEstanteria(*estanteria);
            delete estanteria;

            nodo = siguiente(listaEstanteria, nodo);
        }
     }
}//fin void elimina estanterias

void eliminarListaIndice(Lista &listaIndice){

     if(!listaVacia(listaIndice)){
        PtrNodoLista nodo = primero(listaIndice);
        Indice* indice = (Indice*) nodo->ptrDato;
        delete indice;

        nodo = siguiente(listaIndice, nodo);
        while(nodo != fin()){
            indice = (Indice*) nodo->ptrDato;
            delete indice;

            nodo = siguiente(listaIndice, nodo);
        }
     }
}//fin void elimina estanterias
void eliminarListaSolicitud(Lista &listaSolicitud){

     if(!listaVacia(listaSolicitud)){
        PtrNodoLista nodo = primero(listaSolicitud);
        Solicitud* solicitud = (Solicitud*) nodo->ptrDato;
        destructorSolicitud(*solicitud);
        delete solicitud;

        nodo = siguiente(listaSolicitud, nodo);
        while(nodo != fin()){
            solicitud = (Solicitud*) nodo->ptrDato;
            destructorSolicitud(*solicitud);
            delete solicitud;

            nodo = siguiente(listaSolicitud, nodo);
        }
     }
}//fin void elimina estanterias
void eliminarListaCamiones(Lista &listaCamiones){

     if(!listaVacia(listaCamiones)){
        PtrNodoLista nodo = primero(listaCamiones);
        Camion* camion = (Camion*) nodo->ptrDato;
        destruirCamion(*camion);
        delete camion;

        nodo = siguiente(listaCamiones, nodo);
        while(nodo != fin()){
            camion = (Camion*) nodo->ptrDato;
            destruirCamion(*camion);
            delete camion;

            nodo = siguiente(listaCamiones, nodo);
        }
     }
}//fin void elimina estanterias
void eliminarColas(Cola &colaPendiente){
     while(!colaVacia(colaPendiente)){

       Solicitud* ptrSolicitud = (Solicitud*) desencolar(colaPendiente);
       destructorSolicitud(*ptrSolicitud);

       delete ptrSolicitud;
     }
}//fin void elimina colas




