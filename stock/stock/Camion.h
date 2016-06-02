#ifndef CAMION_H
#define CAMION_H
#include "Pila.h"

using namespace std;

/******************************************************************************/

/* Definiciones de Tipos de Datos */

/*-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

/* Tipo de Informacion que esta contenida en una plataforma*/

typedef struct{
	int nroCamion;
	float kgCapacidad;
	float cargaTotal;
	float porcentajeOcupado;

} Camion;

/******************************************************************************/

/* Definicion de Primitivas */

/**
PRE:
    La instancia del TDA (camion) no debe haberse creado ni destruido con anterioridad.
POST:
    Deja la instancia del TDA (camion) listo para ser usado.
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
    No aplica.
*/

void crearCamion(Camion &camion);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Destruye la instancia del TDA y ya no podrá ser utilizada.
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
    No aplica.
*/

void destruirCamion(Camion &camion);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    El campo nroCamion pasa a tener el dato ingresado.
PARAMETROS:
    camion: instancia sobre la cual se aplica la primitiva.
    dato: valor utilizado para asignar a la instancia de camion.
RETORNO:
    No aplica.
*/

void setNroCamion(Camion &camion, int dato);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    El campo koCapacidad pasa a tener el dato ingresado.
PARAMETROS:
    camion: instancia sobre la cual se aplica la primitiva.
    dato: valor utilizado para asignar a la instancia de camion.
RETORNO:
    No aplica.
*/

void setKGcapacidad(Camion &camion, float dato);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    El campo cargaTotal pasa a tener el dato ingresado.
PARAMETROS:
    camion: instancia sobre la cual se aplica la primitiva.
    dato: valor utilizado para asignar a la instancia de camion.
RETORNO:
    No aplica.
*/

void setCargaTotal(Camion &camion, float dato);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el Numero de Camion
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
    Numero de camion en formato int.
*/

int getNroCamion(Camion &camion);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve la Capicidad en Kilogramos
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
    Capicidad en Kilogramos en formato float.
*/

float getKGcapacidad(Camion &camion);

/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve la Carga total de kilogramos
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
    Carga total de kilogramos en formato float.
*/

float getCargaTotal(Camion &camion);


/**
PRE:
    La instancia del TDA (camion) debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve la pila de solicitudes
ATRIBUTOS:
    camion: instancia sobre la cual se aplica la primitiva.
RETORNO:
   	Pila de solicitudes.
*/

float getPorcentajeCarga(Camion &camion);

void setPorcentajeCarga(Camion &camion, float porcentaje);



float calcularPorcentajeOcupado(Camion &camion);

#endif // CAMION_H
