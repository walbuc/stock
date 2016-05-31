//
//  main.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright Â© 2016 Walter Buczacka. All rights reserved.
//

#include <iostream>
#include "AdminArticulos.h"
#include "AdminEstanteria.h"
#include "estanteria.h"
#include "Piso.h"
#include "Ubicacion.h"
#include "Deposito.h"
#include "AdminDeposito.h"
#include "lista.h"
#include "funciones.h"
#include "Articulo.h"
#include "AdminOperaciones.h"


using namespace std;

int main(int argc, const char * argv[]) {
    
    /*Prueba deposito y las estanterias*/
    /*se crea el deposito y se configura*/
    
    Deposito deposito;
    construirDeposito(deposito);
    configurarDeposito(deposito);
    
    imprimirDeposito(deposito);
    
    
    Lista listaEstanteria;
    Lista listaArticulo;
    Lista listaIndice;
    
    crearLista(listaEstanteria,&compararDatoEstanteria);
    crearLista(listaArticulo, &compararDatoArticulo);
    crearLista(listaIndice, &compararDatoIndice);
    
    
    setListaEstanteria(deposito, listaEstanteria);
    //cargo los articulos de articulo.db
    cargarMaestroDeArticulos(deposito, listaArticulo, listaIndice);
    
    //imprimo las estanterias
    estadoEstanteria(getListaEstanteria(deposito));
    //imprimo los pisos de la primer estanteria
    estadoPisos(getListaPisos(*(Estanteria*)((getListaEstanteria(deposito).primero)->ptrDato)));
    Estanteria& estanteria = *(Estanteria*)((getListaEstanteria(deposito).primero)->ptrDato);
    //imprimo lasubicaciones del primer piso
    estadoUbicaciones(getListaUbicacion(*(Piso*)((getListaPisos(estanteria).primero)->ptrDato)));
    
    //leo los archivos de operaciones ingreso y solicitud paralelamente
    leerArchivosOperaciones(getListaEstanteria(deposito), listaIndice);
    
    
    estadoUbicaciones(getListaUbicacion(*(Piso*)((getListaPisos(estanteria).primero)->ptrDato)));
    
    /*Creo tres articulos para probar*/
    //Articulo articulo;
    //constructor(articulo);
    //setCodigoArticulo(articulo,1);
    //Articulo articulo2;
    //constructor(articulo2);
    //setCodigoArticulo(articulo2,2);
    //Articulo articulo3;
    //constructor(articulo3);
    //setCodigoArticulo(articulo3,3);
    
    /*Creo lista estanteria para probar*/
    //Lista listaEstanteria;
    //crearLista(listaEstanteria,&compararDatoEstanteria);
    
    //crearEstanteria(listaEstanteria,1);
    
    //estadoEstanteria(listaEstanteria);
    
    /*saco estanteria de la lista*/
    //Estanteria estanteria;
    //estanteria= (*(Estanteria*)ultimo(listaEstanteria)->ptrDato);
    /*Llamo para crear el piso*/
    //crearPiso(estanteria.listaPisos,1);
    //estadoPisos(estanteria.listaPisos);
    
    /*Pruebo con una lista creada acá para verificar la creacion de ubicacion y lectura*/
    //Lista auxLista;
    //crearLista(auxLista,&compararDatoUbicacion);
    //crearUbicacion(auxLista,1,articulo);
    //crearUbicacion(auxLista,2,articulo2);
    //estadoUbicaciones(auxLista);
    
    
    cout << "Hello, World!\n";
    return 0;
}
