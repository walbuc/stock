#include "AdminDeposito.h"
#include "Funciones.h"
#include "Solicitud.h"
#include "Camion.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;


string procesaString(string dato){

  std::string str=dato;
  std::size_t pos = str.find("=");      // position of "live" in str

  std::string str3 = str.substr (pos+1);     // get from "live" to the end

return str3;
}

void configurarDeposito(Deposito &deposito){

    ifstream fdeposito;
    string dato;

    fdeposito.open("configuracion.conf");

    if (fdeposito.is_open()){

        while (fdeposito.good()){
            getline(fdeposito,dato);
            dato= procesaString(dato);
            setCPisos(deposito, cadenaAentero(dato));
            getline (fdeposito, dato);
            dato= procesaString(dato);
            setCUbicaciones(deposito, cadenaAentero(dato));
            getline (fdeposito,dato);
            dato= procesaString(dato);
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
    if (fSaldosDetallados.is_open()){

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
   fSaldosDetallados.close();
    }
    else{
          cout << "Error al abrir el archivo." << endl << endl;
          system ("PAUSE");
    }
}
void saldosAgrupados (Deposito &deposito){
    PtrNodoLista cursorEstanteria, cursorPiso, cursorUbicacion;
    cursorEstanteria = primero(getListaEstanteria(deposito));
    ofstream fSaldosAgrupados("SaldosAgrupados.txt");
    float total=0;

    if (fSaldosAgrupados.is_open()){

        while(cursorEstanteria != fin()) {
               cursorPiso = primero(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato));
                while(cursorPiso != fin()){
                    cursorUbicacion=primero(getListaUbicacion(*(Piso*)cursorPiso->ptrDato));
                    while(cursorUbicacion!= fin()){

                        int codArticulo=(getArticulo(*(Ubicacion*)cursorUbicacion->ptrDato).codigoArticulo);
                        float cantidad=(getCantidad(*(Ubicacion*)cursorUbicacion->ptrDato));


                        fSaldosAgrupados<<codArticulo;
                        fSaldosAgrupados<<";";
                        fSaldosAgrupados<<cantidad;
                        fSaldosAgrupados<<";";
                        total= total+cantidad;
                        fSaldosAgrupados<<total;
                        fSaldosAgrupados<<endl;

                        cursorUbicacion= siguiente((getListaUbicacion(*(Piso*)cursorPiso->ptrDato)),cursorUbicacion);

                        }
                    cursorPiso = siguiente(getListaPisos(*(Estanteria*)cursorEstanteria->ptrDato), cursorPiso);
            }

            cursorEstanteria = siguiente(getListaEstanteria(deposito), cursorEstanteria);

    }
    fSaldosAgrupados.close();
    }
    else{
          cout << "Error al abrir el archivo." << endl << endl;
          system ("PAUSE");
    }
}
void escribirFaltantes(Cola &colaPendiente){
    PtrDato dato;
    Cola auxCola;
    crearCola(auxCola);
    ofstream fFaltantes("Faltantes.txt");
    if (fFaltantes.is_open()){
     ///recorremos la cola de pendientes
     while (colaFrente(colaPendiente)!= finCola()){
        dato= desencolar(colaPendiente); //saca el dato
        int codSucural= (getCodigoSucursal(*((Solicitud*)dato)));//imprime la solicitud
        int codArticulo= getCodigoArticulo(*((Solicitud*)dato));
        float cantidadOriginal= getCantidadSolicitud(*((Solicitud*)dato));
        float cantidaCumplida= getCantidadCumplida(*((Solicitud*)dato));
        float porcentaje= (cantidaCumplida*100)/cantidadOriginal;
        fFaltantes<<codSucural;
        fFaltantes<<";";
        fFaltantes<<codArticulo;
        fFaltantes<<";";
        fFaltantes<<cantidadOriginal;
        fFaltantes<<";";
        fFaltantes<<cantidaCumplida;
        fFaltantes<<";";
        fFaltantes<<"%";
        fFaltantes<< porcentaje;
        fFaltantes<<endl;

        encolar(auxCola, dato);//guarda la solicitud en una cola auxiliar para no perderla
     }
    colaPendiente=auxCola; //sobreescribe la colaPendiente original
    fFaltantes.close();
    }
    else{
          cout << "Error al abrir el archivo." << endl << endl;
          system ("PAUSE");

    }

}

void escribirVentas(Lista &listaSolicitud){
    PtrNodoLista cursor;
    cursor=primero(listaSolicitud);
    ofstream fVentas("Ventas.txt");
    if (fVentas.is_open()){

    while (cursor != fin()){

        int codSucursal= getCodigoSucursal(*((Solicitud*)cursor->ptrDato));
        float total= getCantidadCumplida(*((Solicitud*)cursor->ptrDato));
        fVentas<<codSucursal;
        fVentas<<";";
        fVentas<<total;
        fVentas<<endl;


        cursor=siguiente(listaSolicitud,cursor);
    }
    fVentas.close();
    }
    else{
       cout << "Error al abrir el archivo." << endl << endl;
       system ("PAUSE");
       }
}



void ordenarListaCamion(Lista &listaCamiones){

    Lista auxLista;
    crearLista(auxLista,compararDatoCamion);

    Camion* ptrCamion1;
    Camion* ptrAuxCamion;
    PtrNodoLista cursor1= primero(listaCamiones);///tomamos el 1er elemento en cursor1 de listaCamiones
    PtrNodoLista cursor2;


    while (cursor1!= fin()){///while para recorrer la listaCamiones

        ptrCamion1=(Camion*)cursor1->ptrDato;
        int idCamion1=getNroCamion(*ptrCamion1);

        if (listaVacia(auxLista)){
            adicionarPrincipio(auxLista,ptrCamion1);
           }
        else {

            ///tomamos 1er elemento en cursor2 de lista aux!
            cursor2=primero(auxLista);
            bool seguir=true;

            while (seguir==true){///while para recorrer la lista auxiliar e ir comparando

                    ptrAuxCamion=(Camion*)cursor2->ptrDato;

                    int idCamionAux=getNroCamion(*ptrAuxCamion);
                    if (idCamion1>=idCamionAux){///si el idCamion es mayor al aux que esta comparando se agrega antes

                        adicionarPrincipio(auxLista,ptrCamion1);
                        seguir=false;
                    }
                    else{
                    cursor2= siguiente(auxLista,cursor2);
                    if (cursor2== fin()){
                        adicionarFinal(auxLista,ptrCamion1);

                        seguir=false;
                        }
                    }
                    cursor2= siguiente(auxLista,cursor2);

            }///fin while2

        }///else1

         cursor1=siguiente(listaCamiones,cursor1);

    }///fin while1

    listaCamiones=auxLista;///pisamos la lista por la listaAux ordenada desc
}




void utilizacionDeCamiones(Lista &listaCamiones){
     ordenarListaCamion(listaCamiones); 
    PtrNodoLista cursor;
    cursor=primero(listaCamiones);
    ofstream fUtilizacionCamiones("UtilizacionDeCamiones.txt");
    if (fUtilizacionCamiones.is_open()){

    while (cursor != fin()){

        int nroCamion= getNroCamion(*((Camion*)cursor->ptrDato));
        float cargaTotal= getCargaTotal(*((Camion*)cursor->ptrDato));
        float porcentajeOcupacion= getPorcentajeCarga(*((Camion*)cursor->ptrDato));

        fUtilizacionCamiones<<nroCamion;
        fUtilizacionCamiones<<";";
        fUtilizacionCamiones<<cargaTotal;
        fUtilizacionCamiones<<";";
        fUtilizacionCamiones<<"%";
        fUtilizacionCamiones<<porcentajeOcupacion;
        fUtilizacionCamiones<<endl;


        cursor=siguiente(listaCamiones,cursor);
    }
    fUtilizacionCamiones.close();
    }
    else{
       cout << "Error al abrir el archivo." << endl << endl;
       system ("PAUSE");
       }
}
