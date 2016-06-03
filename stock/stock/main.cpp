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
#include "AdminSolicitudes.h"
#include "Camion.h"
#include "AdminCamiones.h"
#include <windows.h>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {

    ///se crea el deposito
    Deposito deposito;
    construirDeposito(deposito);
    configurarDeposito(deposito);
    ///Se declara lista,cola, etc;
    Lista listaEstanteria;
    Lista listaArticulo;
    Lista listaIndice;
    Lista listaSolicitud;
    Lista listaCamiones;
    Cola colaPendientes;
    /// se crea todo
    crearLista(listaEstanteria,&compararDatoEstanteria);
    crearLista(listaArticulo, &compararDatoArticulo);
    crearLista(listaIndice, &compararDatoIndice);
    crearLista(listaSolicitud, &compararDatoSolicitud);
    crearLista(listaCamiones, &compararDatoCamion);
    crearCola(colaPendientes);
    setListaEstanteria(deposito, listaEstanteria);
    //cargo los articulos de articulo.db
    cargarMaestroDeArticulos(deposito, listaArticulo, listaIndice);
    ///Se procesan los archivos.
    leerArchivosOperaciones(deposito, getListaEstanteria(deposito), listaIndice,listaSolicitud,colaPendientes);


    procesarPendientes(deposito,getListaEstanteria(deposito),listaIndice,listaSolicitud,colaPendientes);
    cargarCamiones(deposito,listaSolicitud,listaCamiones);
    int opcion;

        while (opcion != 0)
    {
        system("cls");

        cout << "*******************************************************" << endl;
        cout << "****************** GestionStock ***********************" << endl;
        cout << "*******************************************************" << endl;
        cout << endl << "Seleccione la opcion deseada:" << endl << endl;
        cout << "1) Imprimir Por Pantalla." << endl;
        cout << "2) Imprimir Directamente." << endl;
        cout << "0) Salir del Proyecto." << endl << endl;

        cout << "Su eleccion: ";
        cin >> opcion;

        switch (opcion)
        {
               case 0: system("cls");
                       //   Libera memoria  a lo ultimo
                       eliminarListaAriticulos(listaArticulo);
                       eliminarListaEstanteria(listaEstanteria);
                       eliminarListaIndice(listaIndice);
                       eliminarListaSolicitud(listaSolicitud);
                       eliminarListaCamiones(listaCamiones);
                       eliminarColas(colaPendientes);

                       cout << "La memoria ha sido eliminada correctamente" << endl << endl;
                       system("pause");
                       system("cls");
                       system("color 0a");
                       cout << "\n\n" << setw(60) << "____________________________________\n";
                       cout <<           setw(60) <<" -------UNLa - Sistemas ------\n";
                       cout <<           setw(60) << "Buczacka Walter    - UNLa - Sistemas \n";
                       cout <<           setw(60) << "Cesarano Dario     - UNLa - Sistemas \n";
                       cout <<           setw(60) << "Gustavo J.Gonzalez - UNLa - Sistemas \n";
                       cout <<           setw(60) << "Sandra Gargiulo    - UNLa - Sistemas \n";
                       cout <<           setw(62) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n";
                       system("pause");
                        exit(0);
              case 1: system("cls");
                   //   Punto 1. Por Pantalla  //
                        PtrNodoLista cursorEstanteria, cursorPiso;
                        cursorEstanteria = primero(getListaEstanteria(deposito));
                        cout<<"------------------------------------------------"<<endl;
                        cout<<" Imprimir informacion: "<<endl;
                        cout<<"------------------------------------------------"<<endl;
                        while(cursorEstanteria != fin()) {
                            int nroCalle= getNroCalle(*((Estanteria*)cursorEstanteria->ptrDato));
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"Nro.de Calle: "<<nroCalle<<endl;
                            cout<<"------------------------------------------------"<<endl;
                            cursorPiso = primero(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato));
                            while(cursorPiso != fin()){
                                int nroPiso= getNroPisos(*((Piso*)cursorPiso->ptrDato));
                                cout<<"------------------------------------------------"<<endl;
                                cout<<"Nro. Piso: "<<nroPiso<<endl;
                                cout<<"------------------------------------------------"<<endl;
                                estadoUbicaciones(getListaUbicacion(*(Piso*)cursorPiso->ptrDato));
                                cursorPiso = siguiente(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato), cursorPiso);
                                }
                            cursorEstanteria = siguiente(getListaEstanteria(deposito), cursorEstanteria);
                        }
                        estadoListaSolicitud(listaSolicitud);
                        estadoColaPendiente(colaPendientes);
                        listarCamiones(listaCamiones);
                       system ("PAUSE");
                       break;
               case 2: system("cls");
                        saldosDetallados(deposito);
                        saldosAgrupados(deposito);
                        escribirFaltantes(colaPendientes);
                        escribirVentas(listaSolicitud);
                        utilizacionDeCamiones(listaCamiones);
                        cout<<"Archivos creados correctamente."<<endl;

                       system ("PAUSE");
                       break;

                default: cout << "Opcion invalida" << endl;
                                           system ("PAUSE");
                                           break;
                                  }
    }

    return 0;
}
