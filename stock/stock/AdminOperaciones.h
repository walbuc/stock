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

/*
 pre : lista Creada con crearLista(), deposito creado con construirDeposito().
 post: lee los archivos de operaciones ingreso y solicitud y llama a las
 funciones requeridas de proceso.
 
 lista : lista sobre la cual se leen las estanterias.
 lista : lista sobre la cual se leen los indices.
 deposito: sobre el cual se accede a los valores de configuracion.
 return void.
 */
void leerArchivosOperaciones(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice);

/*
 post: compara dos horarios y determina si el primero es menor igual o mayor al segundo
 
 hora : hora  sobre la cual se compara.
 minuto : minuto sobre la cual se compara.
 segundo: segundo sobre el cual se compara.
 return 0 si son iguales, -1 si el primero horario es menor 1 si el primer horario es mayor,
 -2 si ocurre un error
 */
int compararHoras(int hora, int minuto, int segundo, int hora1, int minuto1, int segundo1);

/*
 pre : todas las listas creadas con crearLista(), deposito creado con construirDeposito().
 post: carga el maestro de articulos y una lista indice de los articulos.
 
 lista : lista sobre la cual se cargan los articulos.
 lista : lista sobre la cual se cargan los indices.
 deposito: sobre el cual se accede a las estanterias.
 return void.
 */
void procesarIngreso(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, int idArticulo, float cantidad);

/*
 pre : lista Creada con crearLista().
 post: busca ubicacion de un articuo en una lista de de estanterias y retorna el puntero al nodo.
 
 listaEstanteria : lista de estanterias sobre la cual se busca el articulo
 c: calle sobre la cual se encuentra el articulo.
 p: piso sobre e.l cual se encuentra el articulo.
 u: ubicacion sobre la cual se encuentra el articulo
 return void.
 */
PtrNodoLista buscarUbicacionArticulo(Lista &listaEstanteria, int c, int p, int u);

#endif /* AdminOperaciones_h */