//
//  AdminOperaciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright � 2016 Walter Buczacka. All rights reserved.
//

#include "AdminOperaciones.h"
#include "AdminSolicitudes.h"
#include "AdminEstanteria.h"

#include <string.h>
#include "fstream"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <windows.h>


using namespace std;

void leerArchivosOperaciones(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, Lista &listaSolicitud, Cola &colaPendiente){

    ifstream fingresos, fsolicitudes;
    string dato;
    int idArticulo=0, hora =0, minuto=0, segundo=0, idArticuloSucursal=0, idSucursal=0, horaS=0, minutoS=0, segundoS=0, resultado=0;
    float cantidad=0, cantidadSucursal;
    bool flagIngreso = false;
    bool flagSolicitud = false;
    bool compararSolicitud = true;
    bool compararIngreso = true;
    //cambiar ruta
    fingresos.open("ingresos.db");
    fsolicitudes.open("solicitudes.db");


    if (fingresos.is_open() && fsolicitudes.is_open()){

        while (fingresos.good() || fsolicitudes.good()){

            if(flagSolicitud == false){

                getline(fingresos,dato,';');
                idArticulo = cadenaAentero(dato);

                getline(fingresos,dato,';');
                cantidad = cadenaAfloat(dato);

                getline(fingresos,dato,':');
                hora = cadenaAentero(dato);
                getline(fingresos,dato,':');
                minuto = cadenaAentero(dato);
                getline(fingresos,dato);
                segundo = cadenaAentero(dato);

                if(dato.length() == 0) {
                    compararIngreso = false;
                }

            }

            if(flagIngreso == false){
                getline(fsolicitudes,dato,';');
                idSucursal = cadenaAentero(dato);

                getline(fsolicitudes,dato,';');
                idArticuloSucursal = cadenaAentero(dato);

                getline(fsolicitudes,dato,';');
                cantidadSucursal = cadenaAfloat(dato);

                getline(fsolicitudes,dato,':');
                horaS = cadenaAentero(dato);
                getline(fsolicitudes,dato,':');
                minutoS = cadenaAentero(dato);
                getline(fsolicitudes,dato);
                segundoS = cadenaAentero(dato);

                if(dato.length() == 0) {
                    compararSolicitud = false;
                }
            }

            dato = "";


            if(!compararIngreso && compararSolicitud){
                 //procesarSolicitud
                procesarSolicitud(deposito, listaEstanteria,listaIndice, listaSolicitud,colaPendiente,idSucursal,idArticuloSucursal,cantidadSucursal);

                flagSolicitud= true;
                flagIngreso = false;
            }

            if(compararIngreso && !compararSolicitud){
                //procesarIngreso
                procesarIngreso(deposito, listaEstanteria, listaIndice, idArticulo, cantidad);

                flagIngreso = true;
                flagSolicitud =false;
            }

            if(compararIngreso && compararSolicitud){
                resultado = compararHoras(hora, minuto, segundo, horaS, minutoS, segundoS);

                if (resultado > 0) {
                    //procesarSolicitud
                    procesarSolicitud(deposito, listaEstanteria,listaIndice, listaSolicitud,colaPendiente,idSucursal,idArticuloSucursal,cantidadSucursal);

                    flagSolicitud= true;
                    flagIngreso = false;
                } else if(resultado < 0) {
                    //procesarIngreso
                    procesarIngreso(deposito, listaEstanteria, listaIndice, idArticulo, cantidad);

                    flagIngreso = true;
                    flagSolicitud =false;
                }
            }

        }

        fingresos.close();
        fsolicitudes.close();

    }

    else{

        cout << "Error al abrir los archivos." << endl << endl;

        system ("PAUSE");

    }
}

int compararHoras(int hora, int minuto, int segundo, int hora1, int minuto1, int segundo1) {

    if(hora > hora1){
        return 1;
    }
    else if(hora < hora1){
        return -1;
    }else if(hora == hora1){
        if (minuto > minuto1){
            return 1;
        } else if (minuto < minuto1){
            return -1;
        } else if (minuto == minuto1){
            if (segundo > segundo1){
                return 1;
            } else if (segundo < segundo1){
                return -1;
            } else if (segundo == segundo1){
                return 0;
            }
        }
    }

    return -2;
}


void procesarIngreso(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, int idArticulo, float cantidad){
    //lo creo en el stack, despues no lo voy a usar.
    Indice indiceArticulo;
    indiceArticulo.codigoArticulo = idArticulo;

    PtrNodoLista localizador = localizarDato(listaIndice, &indiceArticulo);

    if (localizador == fin()) {
        //no se encontro el dato, entonces checkear ubicaciones disponibles sino crear calle.
        //cout << "no se encontro el articulo.\n";
        PtrNodoLista ptrNodoEstanteria = ultimo(listaEstanteria);
        PtrNodoLista ptrNodoPiso = ultimo(getListaPisos(*(Estanteria*)ptrNodoEstanteria->ptrDato));
        PtrNodoLista ptrNodoUbicacion = ultimo(getListaUbicacion((*(Piso*)ptrNodoPiso->ptrDato)));

        Articulo* ptrArticulo = new Articulo;
        constructor(*ptrArticulo);
        setCodigoArticulo(*ptrArticulo, idArticulo);


        if ( ((Ubicacion*)ptrNodoUbicacion->ptrDato)->nroUbicacion < deposito.cUbicaciones ) {
            //crear la ubicaion faltante y completar
            int nroUbicacion = ((Ubicacion*)ptrNodoUbicacion->ptrDato)->nroUbicacion + 1;

            PtrNodoLista ptrNodoNuevaUbicacion = crearUbicacion(getListaUbicacion((*(Piso*)ptrNodoPiso->ptrDato)), nroUbicacion, *ptrArticulo);

            setCantidad(*(Ubicacion*)ptrNodoNuevaUbicacion->ptrDato, cantidad);
            //guardar lista indice - no es un tda entonces no llamo al constructor
            Indice* indice = new Indice;
            indice->c = getNroCalle((*(Estanteria*)ptrNodoEstanteria->ptrDato));
            indice->p = getNroPisos((*(Piso*)ptrNodoPiso->ptrDato));
            indice->u = getNroUbicacion(*(Ubicacion*)ptrNodoNuevaUbicacion->ptrDato);
            indice->codigoArticulo = idArticulo;

            adicionarFinal(listaIndice, indice);

        } else if( ((Ubicacion*)ptrNodoUbicacion->ptrDato)->nroUbicacion == deposito.cUbicaciones ) {

            if( ((Piso*)ptrNodoPiso->ptrDato)->nroPiso < deposito.cPisos ) {

                //crear el piso faltante y la ubicacion y completar
                int nroPiso = ((Piso*)ptrNodoPiso->ptrDato)->nroPiso + 1;
                int nroUbicacion = ((Ubicacion*)ptrNodoUbicacion->ptrDato)->nroUbicacion + 1;

                PtrNodoLista ptrNodoNuevoPiso = crearPiso(getListaPisos((*(Estanteria*)ptrNodoEstanteria->ptrDato)), nroPiso);

                PtrNodoLista ptrNodoNuevaUbicacion = crearUbicacion(getListaUbicacion((*(Piso*)ptrNodoNuevoPiso->ptrDato)), nroUbicacion, *ptrArticulo);

                Indice* indice = new Indice;
                indice->c = getNroCalle((*(Estanteria*)ptrNodoEstanteria->ptrDato));
                indice->p = getNroPisos((*(Piso*)ptrNodoNuevoPiso->ptrDato));
                indice->u = getNroUbicacion(*(Ubicacion*)ptrNodoNuevaUbicacion->ptrDato);
                indice->codigoArticulo = idArticulo;

                adicionarFinal(listaIndice, indice);

            } else if( ((Piso*)ptrNodoPiso->ptrDato)->nroPiso == deposito.cPisos ) {
                //crear calle, crear piso crear ubicacion y completar
                int nroCalle = ((Estanteria*)ptrNodoEstanteria->ptrDato)->nroCalle + 1;
                int nroPiso = 1;
                int nroUbicacion = 1;

                PtrNodoLista ptrNodoNuevaEstanteria = crearEstanteria(listaEstanteria, nroCalle);

                PtrNodoLista ptrNodoNuevoPiso = crearPiso(getListaPisos((*(Estanteria*)ptrNodoNuevaEstanteria->ptrDato)), nroPiso);

                crearUbicacion(getListaUbicacion((*(Piso*)ptrNodoNuevoPiso->ptrDato)), nroUbicacion, *ptrArticulo);

                Indice* indice = new Indice;
                indice->c = nroCalle;
                indice->p = nroPiso;
                indice->u = nroUbicacion;
                indice->codigoArticulo = idArticulo;

                adicionarFinal(listaIndice, indice);

            }

        }
    }
    else {
        //se encontro, entonces almaceno
        Indice indice = *((Indice*)localizador->ptrDato);

        //obtengo la ubicacion ya actualizo la cantidad
        PtrNodoLista prtNodoUbicacion = buscarUbicacionArticulo(listaEstanteria, indice.c, indice.p, indice.u);

        int total = getCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato);
        total = total + cantidad;
        setCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato, total);
    }

}

///*FUNCION PARA PROCESAR SOLICITUDES O CREAR PENDIENTES*/
void procesarSolicitud(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, Lista &listaSolicitud, Cola &colaPendiente,
                       int idSucursal, int idArticuloS, float cantidadSucursal){
    ///lo creo en el stack, despues no lo voy a usar.

    Indice indiceArticulo;
    indiceArticulo.codigoArticulo = idArticuloS;

    PtrNodoLista localizador = localizarDato(listaIndice, &indiceArticulo);

    if (localizador == fin()) {
            ///Directamente el articulo no esta en la estanteria//Directamente carga el pendiente con cantidadCumplida=0

            crearPendiente(colaPendiente, idSucursal,idArticuloS, cantidadSucursal,0);
            cout<< "se creaPendiente, no hay articulo"<<endl;
    }
    else{
        ///se encontro, obtengo la ubicacion
        Indice indice = *((Indice*)localizador->ptrDato);
        PtrNodoLista prtNodoUbicacion = buscarUbicacionArticulo(listaEstanteria, indice.c, indice.p, indice.u);

        /// paso a validar si el stock me alcanza

        float cantidadStock=getCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato);///Cantidad en la ubicacion
        if (cantidadSucursal>cantidadStock){///cantidad solicitada es mayor al STOCK
            /// se guarda lo procesado y se crea pendiente
            if (cantidadStock==0){
                crearPendiente(colaPendiente,idSucursal,idArticuloS,cantidadSucursal,cantidadStock);
            }
            else{

                crearSolicitud(listaSolicitud,idSucursal, idArticuloS, cantidadSucursal,cantidadStock);

                crearPendiente(colaPendiente,idSucursal,idArticuloS,cantidadSucursal,cantidadStock);
            ///Se actualiza stock
                cantidadStock = 0;///como se usa todo el stock se inicializa en 0
                setCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato, cantidadStock);}
        }
        else{///entonces la cantidad Solicitada es menor al Stock.
            ///se crea la solicitud procesada
            crearSolicitud(listaSolicitud, idSucursal, idArticuloS,cantidadSucursal,cantidadSucursal);
            ///Se actualiza el stock
            cantidadStock = cantidadStock-cantidadSucursal;///como se usa todo el stock se inicializa en 0
            setCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato, cantidadStock);
        }

     }///else del if principal

}///fin proceso

///*FUNCION PARA PROCESAR PENDIENTES*/
void procesarPendientes(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice, Lista &listaSolicitud, Cola &colaPendiente){

    PtrDato dato;
    Cola auxCola;
    crearCola(auxCola);
    int idArticuloS;
    int idSucursal;
    Indice indiceArticulo;
    float cantidadPendiente;

    while (colaFrente(colaPendiente)!= finCola()){

        dato= desencolar(colaPendiente); ///saca el dato, se va vaciando la cola

        idSucursal=getCodigoSucursal(*((Solicitud*)dato));///saco el idSucursal
        idArticuloS=getCodigoArticulo(*((Solicitud*)dato));///saco el idArticuloS
        cout<<"idArticulo: "<<idArticuloS<<endl;

        indiceArticulo.codigoArticulo = idArticuloS;

        PtrNodoLista localizador = localizarDato(listaIndice, &indiceArticulo);///localizo el dato en el indice

        float cantidadOriginal= getCantidadSolicitud(*((Solicitud*)dato));
        float cantidadProcesada= getCantidadCumplida(*((Solicitud*)dato));
        cantidadPendiente=cantidadOriginal-cantidadProcesada;///Calculo la cantidad pendiente a procesar
        if (localizador == fin()) {
            ///Directamente el articulo no esta en la estanteria//Se guarda en ColaAuxiliar
            crearPendiente(auxCola,idSucursal,idArticuloS,cantidadOriginal,cantidadProcesada);///guarda la solicitud en una cola auxiliar para no perderla
        }
        else{
        ///se encontro, obtengo la ubicacion
        Indice indice = *((Indice*)localizador->ptrDato);
        PtrNodoLista prtNodoUbicacion = buscarUbicacionArticulo(listaEstanteria, indice.c, indice.p, indice.u);
        float cantidadStock=getCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato);///Cantidad en la ubicacion

       /// paso a validar si el stock me alcanza
        if (cantidadPendiente>cantidadStock){///cantidad solicitada es mayor al STOCK
            /// se guarda lo procesado y se crea pendiente
            if (cantidadStock==0){
                crearPendiente(auxCola,idSucursal,idArticuloS,cantidadOriginal,cantidadProcesada);///guarda la solicitud en una cola auxiliar para no perderla
            }
            else{
                crearSolicitud(listaSolicitud,idSucursal, idArticuloS, cantidadPendiente,cantidadStock);
                float procesado= cantidadProcesada+cantidadStock;
                crearPendiente(auxCola,idSucursal,idArticuloS,cantidadOriginal,procesado);
            ///Se actualiza stock
                cantidadStock = 0;///como se usa todo el stock se inicializa en 0
                setCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato, cantidadStock);}
        }
        else{///entonces la cantidad Solicitada es menor al Stock.
            ///se crea la solicitud procesada
            crearSolicitud(listaSolicitud, idSucursal, idArticuloS,cantidadOriginal,cantidadPendiente);
            ///Se actualiza el stock
            cantidadStock = cantidadStock-cantidadPendiente;///como no se usa todo el stock, se resta
            setCantidad(*(Ubicacion*)prtNodoUbicacion->ptrDato, cantidadStock);
        }

     }///else del if principal

    }
    colaPendiente=auxCola; //sobreescribe la colaPendiente original



}


//cambiar a articulo adm. Busca directamente la calle piso y ubicacion del articulo si no lo encuentra retorna null.
PtrNodoLista buscarUbicacionArticulo(Lista &listaEstanteria, int c, int p, int u){

    Estanteria estanteria;
    construirEstanteria(estanteria);
    setNroCalle(estanteria, c);

    PtrNodoLista ptrNodoEstanteria = localizarDato(listaEstanteria, &estanteria);

    Piso piso;
    construirPiso(piso);
    setNroPisos(piso, p);

    Lista& listaPisos = getListaPisos( (*(Estanteria*)ptrNodoEstanteria->ptrDato) );

    PtrNodoLista ptrNodoPiso = localizarDato(listaPisos, &piso);

    Ubicacion ubicacion;
    construirUbicacion(ubicacion);
    setNroUbicacion(ubicacion, u);

    //otra forma de acceder, no usa get
    Lista& listaUbicaciones = ((Piso*)ptrNodoPiso->ptrDato)->listaUbicacion;

    PtrNodoLista ptrUbicacion = localizarDato(listaUbicaciones, &ubicacion);

    return ptrUbicacion;

}
