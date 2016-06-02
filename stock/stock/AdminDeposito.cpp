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

    fdeposito.open("configuracion.conf");

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

	PtrNodoLista cursorEstanteria, cursorPiso, cursorUbicacion;
    cursorEstanteria = primero(getListaEstanteria(deposito));
    ofstream fSaldosDetallados("SaldosDetallados.txt");

        while(cursorEstanteria != fin()) {
                int nroCalle= getNroCalle(*((Estanteria*)cursorEstanteria->ptrDato));
                cursorPiso = primero(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato));

                while(cursorPiso != fin()){
                    int nroPiso= getNroPisos(*((Piso*)cursorPiso->ptrDato));
                    cursorUbicacion=primero(getListaUbicacion(*(Piso*)cursorPiso->ptrDato));
                    while(cursorUbicacion!= fin()){

                        int nroUbicacion =(getNroUbicacion(*(Ubicacion*)cursorUbicacion->ptrDato));
                        int codArticulo=(getArticulo(*(Ubicacion*)cursorUbicacion->ptrDato).codigoArticulo);
                        float cantidad=(getCantidad(*(Ubicacion*)cursorUbicacion->ptrDato));

                        fSaldosDetallados<<nroCalle;
                        fSaldosDetallados<<";";
                        fSaldosDetallados<<nroPiso;
                        fSaldosDetallados<<";";
                        fSaldosDetallados<< nroUbicacion;
                        fSaldosDetallados<<";";
                        fSaldosDetallados<<codArticulo;
                        fSaldosDetallados<<";";
                        fSaldosDetallados<<cantidad;
                        fSaldosDetallados<<endl;

                        cursorUbicacion= siguiente((getListaUbicacion(*(Piso*)cursorPiso->ptrDato)),cursorUbicacion);

                        }
                    cursorPiso = siguiente(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato), cursorPiso);
            }

            cursorEstanteria = siguiente(getListaEstanteria(deposito), cursorEstanteria);

    }
}
