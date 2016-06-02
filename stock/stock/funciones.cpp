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
