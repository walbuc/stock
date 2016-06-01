//
//  AdminOperaciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "AdminOperaciones.h"

#include <string.h>
#include "fstream"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>


using namespace std;

void leerArchivosOperaciones(Deposito &deposito, Lista &listaEstanteria, Lista &listaIndice){
    
    ifstream fingresos, fsolicitudes;
    string dato;
    int idArticulo=0, hora =0, minuto=0, segundo=0, idArticuloSucursal=0, idSucursal=0, horaS=0, minutoS=0, segundoS=0, resultado=0;
    float cantidad=0, cantidadSucursal;
    bool flagIngreso = false;
    bool flagSolicitud = false;
    bool compararSolicitud = true;
    bool compararIngreso = true;
    //cambiar ruta
    fingresos.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/ingresos.db");
    fsolicitudes.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/solicitudes.db");
    
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
                cout << "proceso solicitud\n";
                flagSolicitud= true;
                flagIngreso = false;
            }
            
            if(compararIngreso && !compararSolicitud){
                //procesarIngreso
                
                procesarIngreso(deposito, listaEstanteria, listaIndice, idArticulo, cantidad);
                cout << "proceso ingreso\n";
                flagIngreso = true;
                flagSolicitud =false;
            }
            
            if(compararIngreso && compararSolicitud){
                resultado = compararHoras(hora, minuto, segundo, horaS, minutoS, segundoS);
                
                if (resultado > 0) {
                    //procesarSolicitud
                    cout << "proceso solicitud\n";
                    flagSolicitud= true;
                    flagIngreso = false;
                } else if(resultado < 0) {
                    //procesarIngreso
                    procesarIngreso(deposito, listaEstanteria, listaIndice, idArticulo, cantidad);
                    cout << "proceso ingreso\n";
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
        cout << "no se encontro el articulo.\n";
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
                
                PtrNodoLista ptrNodoNuevaUbicacion = crearUbicacion(getListaUbicacion((*(Piso*)ptrNodoNuevoPiso->ptrDato)), nroUbicacion, *ptrArticulo);
            
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
