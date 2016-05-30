#ifndef DEPOSITO_H
#define DEPOSITO_H

#include "Estanteria.h"
#include "Lista.h"



typedef struct {
    int nroDeposito;
    int cPisos;
    int cUbicaciones;
    float kc;
    Lista listaEstanteria;
} Deposito;


void construirDeposito(Deposito &deposito);


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
int getCPisos(Deposito &deposito);


 /**
 SET_cPisos
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 cPisos: cantidad de pisos. TOPE.
 RETORNO:
 no aplica.
 **/
void setCPisos(Deposito &deposito, int cPisos);


/**
 GET_cUbicaciones
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de Ubicaciones.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de cUbicaciones..
 **/
 int getCUbicaciones(Deposito deposito);


 /**
 SET_cUbicaciones
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Cambia el numero de cantidad de ubicaciones. TOPE
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 cUbicaciones
 RETORNO:
 no aplica.
 **/
 void setCUbicaciones(Deposito &deposito, int cUbicaciones);



 /**
 GET_KC
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de kc. Kilos por camion
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el numero de kc..
 **/
 float getKc (Deposito &deposito);


 /**
 SET_KC
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve el numero de calle.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 kc: numero a setear en KC.
 RETORNO:
 No aplica.
 **/
 void setKc(Deposito &deposito, float kc);

/**
 GET_LISTA_Estanteria
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve Lista de Pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve Ptrdato Lista de Pisos.
 **/

 PtrDato getListaEstanteria(Deposito &deposito);


 /**
 SET_LISTA_PISOS
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Asigna lista pasada por parametro.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 listaPisos: Lista pasada por parametro.
 RETORNO:
 Asigna lista pasada por parametro.
 **/
void setListaEstanteria(Deposito &deposito, Lista listaEstanteria);







#endif // DEPOSITO_H
