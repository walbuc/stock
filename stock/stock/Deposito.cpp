#include "Deposito.h"
#include "Lista.h"
#include "Funciones.h"



void construirDeposito(Deposito &deposito){

    deposito.nroDeposito=1;
    deposito.cPisos=0;
    deposito.cUbicaciones=0;
    deposito.kc=0;
    Lista auxLista;
    crearLista(auxLista, &compararDatoEstanteria);
   deposito.listaEstanteria=auxLista;
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
int getCPisos(Deposito &deposito){
    return deposito.cPisos;
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
void setCPisos(Deposito &deposito, int cPisos){
    deposito.cPisos= cPisos;
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
 int getCUbicaciones(Deposito &deposito){
    return deposito.cUbicaciones;
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
 void setCUbicaciones(Deposito &deposito, int cUbicaciones){
    deposito.cUbicaciones=cUbicaciones;
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
 float getKc (Deposito &deposito){
     return deposito.kc;
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
 void setKc(Deposito &deposito, float kc){
    deposito.kc= kc;
 }


 /**
 PRE:
 La instancia del TDA (deposito) debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:Devuelve Lista de Pisos.
 ATRIBUTOS:
 Estanteria: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve Lista de Pisos.
 **/

 Lista& getListaEstanteria(Deposito &deposito){
    return deposito.listaEstanteria;
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
 void setListaPisos(Deposito &deposito, Lista listaEstanteria){
    deposito.listaEstanteria= listaEstanteria;
 }

