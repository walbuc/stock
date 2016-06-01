//
//  AdminOperaciones.hpp
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#ifndef AdminOperaciones_h
#define AdminOperaciones_h

#include <stdio.h>
#include "funciones.h"
#include "Deposito.h"

void leerArchivosOperaciones(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice);

int compararHoras(int hora, int minuto, int segundo, int hora1, int minuto1, int segundo1);

void procesarIngreso(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, int idArticulo, float cantidad);

PtrNodoLista buscarUbicacionArticulo(Lista &listaEstanteria, int c, int p, int u);

#endif /* AdminOperaciones_h */