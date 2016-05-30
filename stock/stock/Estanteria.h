#ifndef ESTANTERIA_H
#define ESTANTERIA_H


#include "Articulo.h"
#include "Ubicacion.h"
#include "Piso.h"
#include "Lista.h"
#include "Pila.h"


typedef struct{

    int nroCalle;
    Lista listaPisos;

}  Estanteria;

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
 PtrDato construirEstanteria (Estanteria &estanteria);


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
 GET_LISTA_PISOS
 PRE:
 La instancia del TDA (estanteria) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve Lista de Pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve Ptrdato Lista de Pisos.
 **/
PtrDato getListaPisos(Estanteria &estanteria);


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
void crearPiso(Lista &listaPisos, int nroPiso);



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

 void crearUbicacion(Lista &listaUbicacion, int nroUbicacion, Articulo &articulo);

 /**************************************************************/
 void crearEstanteria(Lista &listaEstanteria, int nroCalle);












#endif // ESTANTERIA_H
