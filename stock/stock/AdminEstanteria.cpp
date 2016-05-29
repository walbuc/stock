#include "AdminEstanteria.h"


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;



void configurarEstanteria(Estanteria &estanteria){

    ifstream festanteria;
    string dato;

    festanteria.open("configuracion.conf");

    if (festanteria.is_open()){

        while (festanteria.good()){


            getline(festanteria,dato);

            setCPisos(estanteria, cadenaAentero(dato));

            getline (festanteria, dato);

            setCUbicaciones(estanteria, cadenaAentero(dato));

            getline (festanteria,dato);
            setKc(estanteria,cadenaAfloat(dato));




        }

        festanteria.close();

    }

    else{

        cout << "Error al abrir el archivo." << endl << endl;

// system ("PAUSE");

    }
}






void imprimirUbicacion(Ubicacion &ubicacion){

    Articulo articulo;
    constructor(articulo);

    articulo= ubicacion.articulo;

    cout<<"------------------------"<<endl;
    cout<< "Nro de Ubicacion: " << ubicacion.nroUbicacion<<endl;
    cout<< "Nro de Articulo: " << articulo.codigoArticulo<<endl;
    cout<<"------------------------"<<endl;


}


void estadoUbicacion (Lista &listaUbicacion, int piso){

    cout<<"ESTADO UBICACION, LONGITUD LISTA: "<<longitud(listaUbicacion)<<endl;
     PtrNodoLista ptrNodoListaUbicacion;
     cout<<"PISO NRO: "<< piso<<endl;

    for(int i = 0; i<longitud(listaUbicacion); i++){

        if(i==0){
            ptrNodoListaUbicacion= primero(listaUbicacion);
            Ubicacion* ptrUbicacion = (Ubicacion*)ptrNodoListaUbicacion->ptrDato;
            Ubicacion ubicacion= *ptrUbicacion;
            imprimirUbicacion(ubicacion);
        }
        else {
            PtrNodoLista ptrNodoListaSiguiente = siguiente(listaUbicacion, ptrNodoListaUbicacion);
            Ubicacion* ptrSiguiente = (Ubicacion*) ptrNodoListaSiguiente->ptrDato;
            Ubicacion siguiente = *ptrSiguiente;
            imprimirUbicacion(siguiente);
            ptrNodoListaUbicacion = ptrNodoListaSiguiente;

        }

    }



}/**hacer de nuevo el recorrido*/

void estadoPiso(Lista &listaPiso){
    cout<<"ESTADO PISO, LONGITUD LISTA_PISO: "<<longitud(listaPiso)<<endl;
    PtrNodoLista ptrNodoListaPiso;
   // Piso piso;
    //construirPiso(piso);
    Lista auxListaUbicacion;
    crearLista(auxListaUbicacion,compararDatoUbicacion);

    for(int i = 1; i<=longitud(listaPiso); i++){

        if(i==1){
            ptrNodoListaPiso= primero(listaPiso);
            Piso* ptrPiso = (Piso*)ptrNodoListaPiso->ptrDato;
            cout<<longitud(ptrPiso->listaUbicacion)<<endl;
            estadoUbicacion(ptrPiso->listaUbicacion, ptrPiso->nroPiso);
        }
        else {
            PtrNodoLista ptrNodoListaSiguiente = siguiente(listaPiso, ptrNodoListaPiso);
            Piso* ptrSiguiente = (Piso*) ptrNodoListaSiguiente->ptrDato;
            estadoUbicacion(ptrSiguiente->listaUbicacion, ptrSiguiente->nroPiso);

            ptrNodoListaPiso = ptrNodoListaSiguiente;

        }

    }




}




void imprimirEstanteria(Estanteria &estanteria){


    cout<<"Nro de calle: "<< getNroCalle(estanteria)<<endl;
    cout<<"cantidad de pisos: " << getCPisos(estanteria)<<endl;
    cout<<"cantidad de ubicaciones: " << getCUbicaciones(estanteria)<<endl;
    cout<<"Kilos por Camión: "<< getKc(estanteria)<<endl;

    Lista lista;
    crearLista(lista,compararDatoPiso);

    lista= getListaPisos(estanteria);
    //cout<<"cantidad "<< longitud(lista)<<endl;

    estadoPiso(lista);




    }
