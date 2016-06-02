
#include <stdio.h>
#include "AdminSolicitudes.h"
#include "Solicitud.h"
#include "cola.h"
#include "fstream"
#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;



PtrNodoLista crearSolicitud(Lista &listaSolicitudes,int idSucursal, int idArticuloSucursal, float cantidadSucursal, float cantidadCumplida){


    Solicitud* punteroSolicitud= new Solicitud();

    constructorSolicitud(*punteroSolicitud);
    //imprimirSolicitud(*punteroSolicitud);
    PtrNodoLista cursor;
    cursor=ultimo(listaSolicitudes);

    int id;



   if (longitud(listaSolicitudes)==0){
    id=0;
   }else{
       id= getIdSolicitud(*((Solicitud*)cursor->ptrDato));
       //id=setIdSolicitud(*punteroSolicitud);
       id=id+1;
      // cout<< "id: "<<id<<endl;
   }
    setIdSolicitud(*punteroSolicitud, id);
    setCodigoSucursal(*punteroSolicitud,idSucursal);
    setCodigoArticulo(*punteroSolicitud, idArticuloSucursal);
    setCantidadSolicitud(*punteroSolicitud, cantidadSucursal);
    setCantidadCumplida(*punteroSolicitud, cantidadCumplida);
    setHoraSolicitud(*punteroSolicitud,"");

    PtrNodoLista ptrNodo= adicionarFinal(listaSolicitudes, punteroSolicitud);

  return ptrNodo;

}

PtrNodoCola crearPendiente(Cola &colaPendiente, int idSucursal, int idArticuloSucursal, float cantidadSucursal, float cantidadCumplida){

    Solicitud* punteroSolicitud= new Solicitud();
    constructorSolicitud(*punteroSolicitud);
    PtrNodoCola cursor;
    cursor=colaFin(colaPendiente);

    int id;
    if (colaVacia(colaPendiente)){
    id=0;
   }else{
       id= getIdSolicitud(*((Solicitud*)cursor->ptrDato));
       //id=setIdSolicitud(*punteroSolicitud);
       id=id+1;
      // cout<< "id: "<<id<<endl;
   }
    setIdSolicitud(*punteroSolicitud, id);
    setCodigoSucursal(*punteroSolicitud,idSucursal);
    setCodigoArticulo(*punteroSolicitud, idArticuloSucursal);
    setCantidadSolicitud(*punteroSolicitud, cantidadSucursal);
    setCantidadCumplida(*punteroSolicitud, cantidadCumplida);
    setHoraSolicitud(*punteroSolicitud,"");

   PtrNodoCola ptrNodo= encolar(colaPendiente, punteroSolicitud);
return ptrNodo;
}


void estadoListaSolicitud(Lista &listaSolicitud) {

    PtrNodoLista cursor;
    cursor=primero(listaSolicitud);

    cout<<"------------------------------"<<endl;
    cout<<"Solicitudes Procesadas"<<endl;
    cout<<"------------------------------"<<endl;

    while (cursor != fin()){

        imprimirSolicitud(*((Solicitud*)cursor->ptrDato));

        cursor=siguiente(listaSolicitud,cursor);
    }
}
void estadoColaPendiente(Cola &colaPendiente) {
    PtrDato dato;
    Cola auxCola;
    crearCola(auxCola);
     cout<<"------------------------------"<<endl;
     cout<<"Solicitudes Pendientes"<<endl;
     cout<<"------------------------------"<<endl;

    while (colaFrente(colaPendiente)!= finCola()){



        dato= desencolar(colaPendiente); //saca el dato
        imprimirSolicitud(*((Solicitud*)dato));//imprime la solicitud
        encolar(auxCola, dato);//guarda la solicitud en una cola auxiliar para no perderla
     }
    colaPendiente=auxCola; //sobreescribe la colaPendiente original

}

void imprimirSolicitud(Solicitud &solicitud){
    cout<<"--------------------------------------"<<endl;
    cout<<"Cod. de Sucursal: "<<solicitud.codigoSucursal<<endl;
    cout<<"Cod. de Articulo: "<<solicitud.codigoArticulo<<endl;
    cout<<"Cantidad de Kg.: "<<solicitud.cantidad<<endl;
    cout<<"Cantidad cumplidad: "<<solicitud.cantidadCumplida<<endl;
    cout<<"--------------------------------------"<<endl;
}



