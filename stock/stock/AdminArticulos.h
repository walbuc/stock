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


/*
 pre : lista Creada con crearLista().
 post: carga instancias de articulos en memoria dinamica
 relacionandolas en la lista.

 lista : lista sobre la cual se cargan los articulos.
 return void.
 */
void cargarArticulos(Lista &listaArticulos);


/*
 pre : lista Creada con crearLista(), deposito creado con construirDeposito().
 post: carga el maestro de articulos y una lista indice de los articulos.

 lista : lista sobre la cual se cargan los articulos.
 lista : lista sobre la cual se cargan los indices.
 deposito: sobre el cual se accede a las estanterias.
 return void.
 */
void cargarMaestroDeArticulos(Deposito &deposito, Lista &listaArticulos, Lista &listaIndice);

/*
 pre : lista Creada con crearLista().
 post: imprime el estado de la lista.

 lista : lista sobre la cual se invoca la primitiva.
 return void
 */
void estadoListaArticulos(Lista &listaArticulos);

#endif /* AdminArticulos_h */
