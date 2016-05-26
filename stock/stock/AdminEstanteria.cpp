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






void imprimirUbicacion(Ubicacion ubicacion){

    Articulo articulo;
    constructor(articulo);

    articulo= ubicacion.articulo;

    cout<<"------------------------"<<endl;
    cout<< "Nro de Ubicacion: " << ubicacion.nroUbicacion<<endl;
    cout<< "Nro de Articulo" << articulo.codigoArticulo<<endl;
    cout<<"------------------------"<<endl;


}


void estadoUbicacion (Pila &pilaUbicacion, int piso){

   cout<<"Piso Nro: "<< piso<< endl;

   while(pilaVacia(pilaUbicacion)!=true){

        Ubicacion* ptrUbicacion;
        ptrUbicacion=((Ubicacion*)sacar(pilaUbicacion));

        imprimirUbicacion(*ptrUbicacion);

   }


}

void estadoPiso(Lista &listaPiso){

    PtrNodoLista ptrNodoListaPiso;

    for(int i = 0; i<longitud(listaPiso); i++){

        if(i==0){
            ptrNodoListaPiso= primero(listaPiso);
            Piso* ptrPiso = (Piso*)ptrNodoListaPiso->ptrDato;
            Piso piso= *ptrPiso;
            Pila auxPila;
            auxPila= piso.pilaUbicacion;
            estadoUbicacion(auxPila, i);
        }
        else {
            PtrNodoLista ptrNodoListaSiguiente = siguiente(listaPiso, ptrNodoListaPiso);
            Piso* ptrSiguiente = (Piso*) ptrNodoListaSiguiente->ptrDato;
            Piso siguiente = *ptrSiguiente;
            Pila auxPila;
            auxPila= siguiente.pilaUbicacion;

            estadoUbicacion(auxPila, i);

            ptrNodoListaPiso = ptrNodoListaSiguiente;

        }

    }




}




void imprimirEstanteria(Estanteria &estanteria){


    cout<<"Nro de calle: "<< getNroCalle(estanteria)<<endl;
    cout<<"cantidad de pisos: " << getCPisos(estanteria)<<endl;
    cout<<"cantidad de ubicaciones: " << getCUbicaciones(estanteria)<<endl;
    cout<<"Kilos por Camión: "<< getKc(estanteria)<<endl;


    }
