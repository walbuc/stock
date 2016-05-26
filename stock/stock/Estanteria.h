#ifndef ESTANTERIA_H
#define ESTANTERIA_H
#include "Lista.h"
#include "Pila.h"
#include "Articulo.h"

/** Definicion de las estructuras**/
struct Ubicacion{
    int nroUbicacion;
    Articulo articulo;

};
struct Piso{
    int nroPiso;
    Pila pilaUbicacion;

};

struct Estanteria{
int nroCalle;

int cPisos;
int cUbicaciones;
float kc;

Lista listaPiso;

};

/**
CONSTRUIR_ESTANTERIA
 PRE:
 La instancia del TDA (estanteria) no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Deja la instancia del TDA (estanteria) listo para ser usado.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 **/
 void construirEstanteria (Estanteria &estanteria);


/**
DESTRUIR_ESTANTERIA
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Elimina la instancia del TDA (estanteria).
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 **/
 void destruirEstanteria(Estanteria &estanteria);


 /**
 GET_NUMERO_CALLE
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de calle..
 **/
 int getNroCalle(Estanteria &estanteria);


 /**
 SET_NUMERO_CALLE
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 no aplica.
 **/
 void setNroCalle(Estanteria &estanteria, int nro);


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
int getCPisos(Estanteria &estanteria);


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
void setCPisos(Estanteria &estanteria, int cPisos);


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
 int getCUbicaciones(Estanteria &estanteria);


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
 void setCUbicaciones(Estanteria &estanteria, int cUbicaciones);



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
 float getKc (Estanteria &estanteria);


 /**
 SET_KC
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 kc: numero a setear en KC.
 RETORNO:
 No aplica.
 **/
 void setKc(Estanteria &estanteria, float kc);


 /**
 GET_LISTA_PISOS
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve Lista de Pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve Lista de Pisos.
 **/
Lista getListaPisos(Estanteria &estanteria);


 /**
 SET_LISTA_PISOS
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Asigna lista pasada por parametro.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 listaPisos: Lista pasada por parametro.
 RETORNO:
 Asigna lista pasada por parametro.
 **/
void setListaPisos(Estanteria &estanteria, Lista listaPisos);


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
void crearPiso(Estanteria &estanteria, int nroPiso);



 /**
 CREAR_UBICACION
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Asigna lista pasada por parametro.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 nroUbicacion: ID de la ubicacion a crear.
 Articulo : es el articulo que va a tener esa ubicacion, segun el Archivo de configuracion.
 RETORNO:
 No aplica. Solo se crea la ubicacion.
 **/
void crearUbicacion(Estanteria &estanteria, int nroUbicacion, Articulo &articulo);













#endif // ESTANTERIA_H
