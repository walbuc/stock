#include "Estanteria.h"
#include "AdminEstanteria.h"
#include "Funciones.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 PRE:
 La instancia del TDA (estanteria) no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Deja la instancia del TDA (estanteria) listo para ser usado.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 **/
void construirEstanteria (Estanteria &estanteria){
     estanteria.nroCalle=0;
     /*Setea la listaPisos, Ubicacion no tendria, no ser�a necesario inicializar*/
     Lista auxLista;
     crearLista(auxLista,&compararDatoPiso);
     estanteria.listaPisos=auxLista;
}

/**
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Elimina la instancia del TDA (estanteria).
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 **/
 void destruirEstanteria(Estanteria &estanteria){}


 /**
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de calle..
 **/
 int getNroCalle(Estanteria &estanteria){
    return estanteria.nroCalle;
 }


 /**
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 no aplica.
 **/
 void setNroCalle(Estanteria &estanteria, int nro){
    estanteria.nroCalle= nro;
 }


/**
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve Lista de Pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve Lista de Pisos.
 **/
Lista& getListaPisos(Estanteria &estanteria){
    return estanteria.listaPisos;
 }


 /**
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Asigna lista pasada por parametro.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 listaPisos: Lista pasada por parametro.
 RETORNO:
 Asigna lista pasada por parametro.
 **/
 void setListaPisos(Estanteria &estanteria, Lista listaPisos){
    estanteria.listaPisos= listaPisos;
 }


 /**
 CREAR_PISO
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Se crea un piso con el numero de piso asignado.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 nroPiso: ID del piso a crear.
 RETORNO:
 No aplica. Solo se crea un piso con los parametros pasados.
 **/


PtrNodoLista crearPiso(Lista &listaPisos, int nroPiso){
    Piso* punteroPiso = new Piso();
    construirPiso(*punteroPiso);
    setNroPisos(*punteroPiso, nroPiso);
    PtrNodoLista prtNodo = adicionarFinal(listaPisos, punteroPiso);
     return prtNodo;
   }

/**
 CREAR_UBICACION
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad. y el piso debe estar creado
 POST:Asigna lista pasada por parametro.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 nroUbicacion: ID de la ubicacion a crear.
 kc: es la cantidad de Kilos que va a tener esa ubicacion, segun el Archivo de configuracion.
 RETORNO:
 No aplica. Solo se crea la ubicacion.
 **/
PtrNodoLista crearUbicacion(Lista &listaUbicacion, int nroUbicacion, Articulo &articulo){

    Ubicacion* punteroUbicacion = new Ubicacion();
    construirUbicacion(*punteroUbicacion);

    setNroUbicacion(*punteroUbicacion, nroUbicacion);
    setArticulo(*punteroUbicacion, articulo);

    PtrNodoLista ptrNodo = adicionarFinal(listaUbicacion, punteroUbicacion);
    return ptrNodo;

    }

PtrNodoLista crearEstanteria(Lista &listaEstanteria, int nroCalle){

    Estanteria* punteroEstanteria = new Estanteria();
    construirEstanteria(*punteroEstanteria);
    setNroCalle(*punteroEstanteria, nroCalle);

    PtrNodoLista prtNodo = adicionarFinal(listaEstanteria, punteroEstanteria);

    return prtNodo;

}











