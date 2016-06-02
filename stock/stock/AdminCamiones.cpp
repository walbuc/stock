#include "AdminCamiones.h"
#include "Solicitud.h"
#include "AdminSolicitudes.h"
#include "Funciones.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>


using namespace std;

void configurarKcCamion(Camion &camion,float kc){
    crearCamion(camion);
    setKGcapacidad(camion, kc);
}

void cargarCamiones(Deposito &deposito, Lista &listaSolicitudes, Lista &listaCamiones){
    float kc= deposito.kc;
    Camion* punteroCamion= new Camion();
    crearCamion(*punteroCamion);

    ///configuro el 1er camion
    if (longitud(listaCamiones)==0){
        configurarKcCamion(*punteroCamion,kc);
        setNroCamion(*punteroCamion, 1);
        adicionarFinal(listaCamiones, punteroCamion);
    }
    ///cursor de la listaSolicitudes
    PtrNodoLista cursorSolicitud;
    cursorSolicitud=primero(listaSolicitudes);

    Solicitud auxSolicitud;
    constructorSolicitud(auxSolicitud);

    PtrNodoLista cursorCamion;///cursorCamion


    while (cursorSolicitud != fin()){

        auxSolicitud= (*((Solicitud*)cursorSolicitud->ptrDato));
        float kgSolicitud= getCantidadCumplida(auxSolicitud);
        cursorCamion= ultimo(listaCamiones);
        float total=getCargaTotal(*((Camion*)cursorCamion->ptrDato));
        float suma= total+kgSolicitud;
        if (suma<=kc){
            setCargaTotal(*((Camion*)cursorCamion->ptrDato),suma);//piso la carga total;
            float porcentaje= calcularPorcentajeOcupado(*((Camion*)cursorCamion->ptrDato));
            setPorcentajeCarga(*((Camion*)cursorCamion->ptrDato), porcentaje);
        }
        else{
            int id= getNroCamion(*((Camion*)cursorCamion->ptrDato));///guardo id de camion a despachar.
            id=id+1;
            cout<<"camion nuevo";
            Camion* punteroCamion2= new Camion();
            crearCamion(*punteroCamion2);
            configurarKcCamion(*punteroCamion2,kc);
            setNroCamion(*punteroCamion2, id);
            setCargaTotal(*punteroCamion2,kgSolicitud);
            float porcentaje= calcularPorcentajeOcupado(*punteroCamion2);
            setPorcentajeCarga(*punteroCamion2, porcentaje);

            adicionarFinal(listaCamiones,punteroCamion2);

        }

        cursorSolicitud=siguiente(listaSolicitudes,cursorSolicitud);
    }


}

void listarCamiones (Lista &listaCamiones)
{
	PtrNodoLista cursor;
    cursor=primero(listaCamiones);

    cout<<"------------------------------"<<endl;
    cout<<"CAMIONES CARGADOS"<<endl;
    cout<<"------------------------------"<<endl;

    while (cursor != fin()){

        //imprimirSolicitud(*((Solicitud*)cursor->ptrDato));
         cout<<"-------------------------------------------------"<<endl;
        cout<<"Nro CAMION: "<< getNroCamion(*((Camion*)cursor->ptrDato))<<endl;
        cout<<"CARGA TOTAL: "<< getCargaTotal(*((Camion*)cursor->ptrDato))<<endl;
        cout<<"Porcentaje Ocupacion: "<< getPorcentajeCarga(*((Camion*)cursor->ptrDato))<<endl;
         cout<<"--------------------------------------------------"<<endl;


        cursor=siguiente(listaCamiones,cursor);
    }
	}







void utilizacionCamiones(Lista &listaCamiones){}

