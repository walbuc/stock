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
    leerArchivosOperaciones(deposito, getListaEstanteria(deposito), listaIndice);
    //imprimo lasubicaciones de la primera calle
    
    
    estadoPisos(getListaPisos(*(Estanteria*)((getListaEstanteria(deposito).primero)->ptrDato)));
    estadoUbicaciones(getListaUbicacion(*(Piso*)((getListaPisos(estanteria).primero)->ptrDato)));
    
    //Imprimir Todo
    PtrNodoLista cursorEstanteria, cursorPiso, cursorUbicacion;
    cursorEstanteria = primero(getListaEstanteria(deposito));
    cursorPiso = primero(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato));
    cursorUbicacion = primero(getListaUbicacion(*(Piso*)cursorPiso->ptrDato));
    
    
    /*
    while(cursorEstanteria != fin()){
        int nroCalle= getNroCalle(*((Estanteria*)cursorEstanteria->ptrDato));
        cout<<"------------------------------------------------"<<endl;
        cout<<"Nro.de Calle: "<<nroCalle<<endl;
        cout<<"------------------------------------------------"<<endl;
        
        while(cursorPiso != fin()){
            
            int nroPiso= getNroPisos(*((Piso*)cursorPiso->ptrDato));
            cout<<"------------------------------------------------"<<endl;
            cout<<"Nro. Piso: "<<nroPiso<<endl;
            cout<<"------------------------------------------------"<<endl;
            
            while(cursorUbicacion != fin()){
                int nroUbicacion= getNroUbicacion(*((Ubicacion*)cursorUbicacion->ptrDato));
                cout<<"------------------------------------------------"<<endl;
                cout<<"Nro. Ubicacion: "<<nroUbicacion<<endl;
                Articulo articulo = getArticulo(*((Ubicacion*)cursorUbicacion->ptrDato));
                cout<<"Nro. Articulo: "<< articulo.codigoArticulo<<endl;
                cout<<"Cantidad: "<< getCantidad(*((Ubicacion*)cursorUbicacion->ptrDato))<<endl;
                cout<<"------------------------------------------------"<<endl;

                siguiente(getListaUbicacion(*(Piso*)cursorPiso->ptrDato), cursorUbicacion);
            }
            
            siguiente(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato), cursorPiso);
        }
        
        siguiente(getListaEstanteria(deposito), cursorEstanteria);
        
    }
    
    */
    cout << "Hello, World!\n";
    return 0;
}
