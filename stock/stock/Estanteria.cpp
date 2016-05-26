#include "Estanteria.h"
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


     /*numero de calle es 0*/
     estanteria.nroCalle=0;
     /*Setea la listaPisos, Ubicacion no tendria, no sería necesario inicializar*/
     estanteria.cPisos=0;
     estanteria.cUbicaciones=0;
     estanteria.kc=0;

     Lista auxLista;
     crearLista(auxLista,compararDatoPiso);

     estanteria.listaPiso=auxLista;
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
 GET_cPisos
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero cantidad de pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de cPisos..
 **/
int getCPisos(Estanteria &estanteria){
    return estanteria.cPisos;
}


 /**
 SET_cPisos
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 cPisos: cantidad de pisos. TOPE.
 RETORNO:
 no aplica.
 **/
void setCPisos(Estanteria &estanteria, int cPisos){
    estanteria.cPisos= cPisos;
}


/**
 GET_cUbicaciones
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de Ubicaciones.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de cUbicaciones..
 **/
 int getCUbicaciones(Estanteria &estanteria){
    return estanteria.cUbicaciones;
 }


 /**
 SET_cUbicaciones
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de cantidad de ubicaciones. TOPE
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 cUbicaciones
 RETORNO:
 no aplica.
 **/
 void setCUbicaciones(Estanteria &estanteria, int cUbicaciones){
    estanteria.cUbicaciones=cUbicaciones;
 }


 /**
 GET_KC
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de kc. Kilos por camion
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de kc..
 **/
 float getKc (Estanteria &estanteria){
     return estanteria.kc;
 }


 /**
 SET_NUMERO_CALLE
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 kc: numero a setear en KC.
 RETORNO:
 No aplica.
 **/
 void setKc(Estanteria &estanteria, float kc){
    estanteria.kc= kc;
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
Lista getListaPisos(Estanteria &estanteria){
    return estanteria.listaPiso;
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
    estanteria.listaPiso= listaPisos;
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
 void crearPiso(Estanteria &estanteria, int nroPiso){
    //pila vacia
    Pila auxPila;
    crearPila(auxPila);

    //crear auxiliar para el piso
     Piso auxPiso;
     auxPiso.nroPiso=nroPiso;
     auxPiso.pilaUbicacion=auxPila;



     Lista auxLista;
     crearLista(auxLista, compararDatoPiso);
     //Lista* ptrListaPiso;

     //ptrListaPiso= (Lista*)getListaPisos(estanteria);

     auxLista= getListaPisos(estanteria);



     //adicionamos el piso a la lista de pisos de la estanteria.
     adicionarFinal(auxLista, &auxPiso);
     //terminanos de sobrescribir la lista que nos creamos a la estanteria pasada por parametro
     setListaPisos(estanteria,auxLista);


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
void crearUbicacion(Estanteria &estanteria, int nroUbicacion, Articulo &articulo){

     //crea el auxiliar de ubicacion
     Ubicacion auxUbicacion;
     //Asigna los valores pasados por parametro y el articulo
     auxUbicacion.nroUbicacion= nroUbicacion;
     auxUbicacion.articulo= articulo;

     // auxiliar de piso
     Piso auxPiso;

     //creamos puntero auxiliar

     Piso* ptrPiso;

     //sacamos el ultimo piso creado
     Lista auxLista;
     crearLista(auxLista, compararDatoPiso);
     auxLista= getListaPisos(estanteria);
     ptrPiso= (Piso*)ultimo(auxLista) ;

     //guarda el piso que apunta el puntero
     auxPiso= *ptrPiso;

     //creamos pila auxiliar
     Pila auxPila;
     crearPila(auxPila);
     //guardamos la pila del piso en el auxiliar
     auxPila= auxPiso.pilaUbicacion;

     //agregamos la ubicacion creada
     agregar(auxPila, &auxUbicacion);

     //pisamos la pila del piso auxiliar
     auxPiso.pilaUbicacion=auxPila;

     //volvemos a guardar el piso en la direccion del puntero
     *ptrPiso= auxPiso;

   }

