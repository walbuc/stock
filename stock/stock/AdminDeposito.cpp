#include "AdminDeposito.h"
#include "Funciones.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

void configurarDeposito(Deposito &deposito){

    ifstream fdeposito;
    string dato;

    fdeposito.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/configuracion.conf");

    if (fdeposito.is_open()){

        while (fdeposito.good()){
            getline(fdeposito,dato);
            setCPisos(deposito, cadenaAentero(dato));
            getline (fdeposito, dato);
            setCUbicaciones(deposito, cadenaAentero(dato));
            getline (fdeposito,dato);
            setKc(deposito,cadenaAfloat(dato));
       }

        fdeposito.close();

    }

    else{

        cout << "Error al abrir el archivo configuracion." << endl << endl;

// system ("PAUSE");

    }
}

void imprimirDeposito(Deposito &deposito){
    cout<<"--------------------------------------"<<endl;
    cout<<"Nro Deposito: "<<deposito.nroDeposito<<endl;
    cout<<"Cantidad de Pisos: "<<deposito.cPisos<<endl;
    cout<<"Cantidad de Ubicaciones: "<<deposito.cUbicaciones<<endl;
    cout<<"Kilos por Camion: "<<deposito.kc<<endl;
    cout<<"--------------------------------------"<<endl;



}

void saldosDetallados (Deposito &deposito){
	
	PtrNodoLista cursorEstanteria = primero(getListaEstanteria(deposito));
	PtrNodoLista cursorPiso;
	PtrNodoLista cursorUbicacion;
	Articulo art;
	FILE *pf;
	
    if ((pf = fopen("Saldos Detallados.txt", "w")) == NULL) {
        cout << "Error al abrir el fichero de aplicaciones" << endl;
    }
	
	while (cursorEstanteria != fin()) { //recorre todas las estanterias
		cursorPiso = primero(getListaPisos(*(Estanteria*) cursorEstanteria->ptrDato)); //trae el piso de la estanteria apuntada
	    while (cursorPiso != fin()) { //recorre todos los pisos de la estanteria aputanda
	    	cursorUbicacion = primero(getListaUbicacion(*(Piso*) cursorPiso->ptrDato)); //trae la abicacion de el piso apuntaoo 
	    	while (cursorUbicacion != fin()){ //recorre todas las ubicaciones
	    		art = getArticulo(*(Ubicacion*) cursorUbicacion->ptrDato); //trae el articulo de la ubicacion
	    		fprintf(pf, "%d,%d,%d,%d,%d\n", getNroCalle(*(Estanteria*) cursorEstanteria->ptrDato), getNroPisos(*(Piso*) cursorPiso->ptrDato),
	    		getNroUbicacion(*(Ubicacion*) cursorUbicacion->ptrDato), getCodigoArticulo(art), getCantidad(*(Ubicacion*) cursorUbicacion->ptrDato)); //revisar nombres
	    		cursorUbicacion = siguiente(getListaUbicacion(*(Piso*) cursorPiso->ptrDato), cursorUbicacion); //escribe en el txt
			}
	        cursorPiso = siguiente(getListaPisos(*(Estanteria*) cursorEstanteria->ptrDato), cursorPiso); //pasa al siguiente piso
	    }
	}
    fclose(pf);
}

void saldosAgrupados (Deposito &deposito){
	
	Lista listaUbicaciones;
	crearLista(listaUbicaciones, compararDatoUbicacion);
	PtrNodoLista cursorEstanteria = primero(getListaEstanteria(deposito));
	PtrNodoLista cursorPiso;
	PtrNodoLista cursorUbicacion;
	PtrNodoLista cursorI, cursorJ;
	PtrNodoLista cursor;
	Ubicacion ubAux;
	Articulo art;
	float acumu = 0;
	FILE *pf;
	
    if ((pf = fopen("Saldos Agrupados.txt", "w")) == NULL) {
        cout << "Error al abrir el fichero de aplicaciones" << endl;
    }
	
	while (cursorEstanteria != fin()) { //recorre todas las estanterias
		cursorPiso = primero(getListaPisos(*(Estanteria*) cursorEstanteria->ptrDato)); //trae el piso de la estanteria apuntada
	    while (cursorPiso != fin()) { //recorre todos los pisos de la estanteria aputanda
	    	cursorUbicacion = primero(getListaUbicacion(*(Piso*) cursorPiso->ptrDato)); //trae la abicacion de el piso apuntaoo 
	    	while (cursorUbicacion != fin()){ //recorre todas las ubicaciones
	    		insertarDato(listaUbicaciones, cursorUbicacion->ptrDato); //inserta la ubicacion en la nueva lista
	    		cursorUbicacion = siguiente(getListaUbicacion(*(Piso*) cursorPiso->ptrDato), cursorUbicacion); //escribe en el txt
			}
	        cursorPiso = siguiente(getListaPisos(*(Estanteria*) cursorEstanteria->ptrDato), cursorPiso); //pasa al siguiente piso
	    }
	}
	
	//ordenacion burbuja de la lista de ubicaciones de forma descendiente
	cursorI = primero(listaUbicaciones);
	while (cursorI != fin()){
		cursorJ = siguiente(listaUbicaciones, cursorI);
		while (cursorJ != fin()){
			if ((getCantidad(*(Ubicacion*) cursorI->ptrDato)) < (getCantidad(*(Ubicacion*) cursorJ->ptrDato))){
				ubAux = (*(Ubicacion*) cursorI->ptrDato);
				(*(Ubicacion*) cursorJ->ptrDato) = (*(Ubicacion*) cursorI->ptrDato);
				(*(Ubicacion*) cursorI->ptrDato) = ubAux;
			}
			cursorJ = siguiente(listaUbicaciones, cursorJ);
		}
		cursorI = siguiente(listaUbicaciones, cursorI);
		cursorJ = siguiente(listaUbicaciones, cursorI);
	}
	
	cursor = primero(listaUbicaciones); //cursor para guardar
	while (cursor != fin()){
		art = getArticulo(*(Ubicacion*) cursor->ptrDato);
		acumu = acumu + getCantidad(*(Ubicacion*) cursor->ptrDato);
		fprintf(pf, "%d,%.3f,%.3f\n", getCodigoArticulo(art),
		getCantidad(*(Ubicacion*) cursor->ptrDato), acumu);
	}
}

