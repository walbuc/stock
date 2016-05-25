//
//  solicitud.h
//  stock
//
//  Created by Sandra Gargiulo on 5/22/16.
//  Copyright © 2016 Sandra Gargiulo. All rights reserved.
//

#ifndef solicitud_h
#define solicitud_h


/* Tipo de Estructura solicitud. */
struct Solicitud {
    Sucursal codigoSucursal;
	Articulo codigoArticulo;
	float cantidad;
	string hora;
} solicitud;

void cargarArchivo(const char ruta[]);

/**
 PRE:
 La instancia del TDA (solicitud) no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Deja la instancia del TDA (solicitud) listo para ser usado.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 */

void constructor(Solicitud &solicitud);

/**
 PRE:
 La instancia del TDA (solicitud) no debe haberse creado ni destruido  con anterioridad.
 POST:
 Deja la instancia del TDA (solicitud) listo para ser usado.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 */

void destructor(Solicitud &solicitud);


/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el codigo de la solicitud.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 
 */

int getCodigoSucursal(Sucursal &sucursal);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 La sucursal queda con el nuevo codigo.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 codigo: valor del codigo a asignar a la sucursal
 RETORNO:
 No aplica.
 */
void setCodigoSucursal(Sucursal &sucursal, int codigo);

/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el precio del articulo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el precio del articulo.
 */

/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el codigo de la solicitud.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 
 */

int getCodigoArticulo(Articulo &articulo);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 La sucursal queda con el nuevo codigo.
 ATRIBUTOS:
 solicitud: instancia sobre la cual se aplica la primitiva.
 codigo: valor del codigo a asignar a la sucursal
 RETORNO:
 No aplica.
 */
void setCodigoArticulo(Articulo &articulo, int codigo);

/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el precio del articulo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el precio del articulo.
 */


float getCantidadSolicitud(Solicitud &solicitud);


/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 El articulo queda con el nuevo precio.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 precio: valor del codigo a asignar al articulo.
 RETORNO:
 No aplica.
 */
void setCantidadSolicitud(Solicitud &solicitud, float cantidad);

//falta descripcion


string getHoraSolicitud(Solicitud &solicitud);


/**
 PRE:
 La instancia del TDA (solicitud) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 El articulo queda con el nuevo precio.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 precio: valor del codigo a asignar al articulo.
 RETORNO:
 No aplica.
 */
void setHoraSolicitud(Solicitud &solicitud, string hora);

/* verifica el stock de un determinado articulo*/
bool existeArticulo();

/*verifica la existencia del articulo*/
bool existeStockArticulo();

/* si el articulo no cumple con la totalidad o la parcialidad
de las 2 condiciones anteriores,
carga el articulo en la cola de articulos pendientes */
void agregarPendiente();

/* en caso contrario,
carga el articulo en la lista de pedido */
void agregarSolicitud();

#endif /* solicitud_h */