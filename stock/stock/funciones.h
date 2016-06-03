//
//  funciones.h
//  stock
//
//  Created by Walter Buczacka on 5/15/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#ifndef funciones_h
#define funciones_h

#include "articulo.h"
#include "lista.h"
#include "Cola.h"
#include "estanteria.h"
#include "Ubicacion.h"
#include <string>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ResultadoComparacion compararDatoArticulo(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoIndice(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoEstanteria(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoPiso(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoUbicacion(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoSolicitud(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararDatoCamion(PtrDato ptrDato1, PtrDato ptrDato2);

int cadenaAentero(string dato);

float cadenaAfloat(string dato);

char cadenaACaracter(string dato);

///////////////////////////////////////////
////FUNCIONES PARA LIBERAR MEMORIA////////
//////////////////////////////////////////

void eliminarListaAriticulos(Lista &listaArticulos);

void eliminarListaEstanteria(Lista &listaEstanteria);

void eliminarListaIndice(Lista &listaIndice);

void eliminarListaSolicitud(Lista &listaSolicitud);

void eliminarListaCamiones(Lista &listaCamiones);

void eliminarColas(Cola &colaPendiente);



#endif /* funciones_h */
