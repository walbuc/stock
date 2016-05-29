//
//  main.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <iostream>
#include "AdminArticulos.h"
#include "AdminEstanteria.h"
#include "estanteria.h"
#include "Piso.h"
#include "Ubicacion"
#include "lista.h"
#include "funciones.h"

#include "Articulo.h"
#include "AdminOperaciones.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    Lista listaArticulo;
    Lista listaIndice;
    
    crearLista(listaArticulo, &compararDatoArticulo);
    
    cargarMaestroDeArticulos(listaArticulo, listaIndice);
    
    
    leerArchivosOperaciones();
    
    /*Prueba de las estanterias*/
     /*creo estanteria*/
    Estanteria estanteria;
    construirEstanteria(estanteria);
    configurarEstanteria(estanteria);//Levanto los parametros de .confg

    setNroCalle(estanteria,1);//Seteo el nro de calle

    /*Creo tres articulos para probar*/
    Articulo articulo;
    constructor(articulo);
    setCodigoArticulo(articulo,1);
    Articulo articulo2;
    constructor(articulo2);
    setCodigoArticulo(articulo2,2);
    Articulo articulo3;
    constructor(articulo3);
    setCodigoArticulo(articulo3,3);
    
    /*Creo un solo piso para probar*/
    crearPiso(estanteria,1);
   
   /*creo las 3 ubicaciones en el piso creado*/
    crearUbicacion(estanteria,1,articulo);
    crearUbicacion(estanteria,2,articulo2);
    crearUbicacion(estanteria,3,articulo3);
    
    /*Imprimo la estanteria completa, Pero no lee bien la listaUbicaciones*/
    imprimirEstanteria(estanteria);
 
 
    
    
    cout << "Hello, World!\n";
    return 0;
}
