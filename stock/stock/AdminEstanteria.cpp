#include "AdminEstanteria.h"


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;


void imprimirUbicacion(Ubicacion &ubicacion){

    Articulo articulo;
    constructor(articulo);

    articulo= ubicacion.articulo;

    cout<<"------------------------"<<endl;
    cout<< "Nro de Ubicacion: " << ubicacion.nroUbicacion<<endl;
    cout<< "Nro de Articulo: " << articulo.codigoArticulo<<endl;
    cout<<"------------------------"<<endl;

}

void estadoUbicaciones(Lista &listaUbicacion){

    PtrNodoLista cursor;
    cursor=primero(listaUbicacion);

    while (cursor != fin()){

        int nroUbicacion= getNroUbicacion(*((Ubicacion*)cursor->ptrDato));
        cout<<"------------------------------------------------"<<endl;
        cout<<"Nro. Ubicacion: "<<nroUbicacion<<endl;
        Articulo articulo = getArticulo(*((Ubicacion*)cursor->ptrDato));
        cout<<"Nro. Articulo: "<< articulo.codigoArticulo<<endl;
        cout<<"Cantidad: "<< getCantidad(*((Ubicacion*)cursor->ptrDato))<<endl;
        cout<<"------------------------------------------------"<<endl;

        cursor=siguiente(listaUbicacion,cursor);

    }

}/**hacer de nuevo el recorrido*/

void estadoPisos(Lista &listaPiso){

    PtrNodoLista cursor;
    cursor=primero(listaPiso);

    while (cursor != fin()){
        int nroPiso= getNroPisos(*((Piso*)cursor->ptrDato));
        cout<<"------------------------------------------------"<<endl;
        cout<<"Nro. Piso: "<<nroPiso<<endl;
        cout<<"------------------------------------------------"<<endl;
        cursor=siguiente(listaPiso,cursor);
    }
}

void estadoEstanteria(Lista &listaEstanteria){

    PtrNodoLista cursor;
    cursor=primero(listaEstanteria);

    while (cursor != fin()){

        int nroCalle= getNroCalle(*((Estanteria*)cursor->ptrDato));
        cout<<"------------------------------------------------"<<endl;
        cout<<"Nro.de Calle: "<<nroCalle<<endl;
        cout<<"------------------------------------------------"<<endl;
        cursor=siguiente(listaEstanteria,cursor);

    }
}
