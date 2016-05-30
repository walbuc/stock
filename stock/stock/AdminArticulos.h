//
//  AdminArticulos.h
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#ifndef AdminArticulos_h
#define AdminArticulos_h

#include "lista.h"
#include "articulo.h"
#include "funciones.h"
#include "Deposito.h"



void cargarArticulos(Lista &listaArticulos);


void cargarMaestroDeArticulos(Deposito &deposito, Lista &listaArticulos, Lista &listaIndice);


void estadoListaArticulos(Lista &listaArticulos);

#endif /* AdminArticulos_h */