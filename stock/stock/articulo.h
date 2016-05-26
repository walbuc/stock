//
//  articulo.h
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#ifndef articulo_h
#define articulo_h
#include <string>

using namespace std;

/* Tipo de Estructura Articulo. */
struct Articulo {
    int codigoArticulo;
    float precio;
    string descripcion;
};

/* Tipo de Estructura Indice. */
struct Indice {
    int codigoArticulo;
    int c, p, u;
};

/**
 PRE:
 La instancia del TDA (circulo) no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
 POST:
 Deja la instancia del TDA (circulo) listo para ser usado. El valor por defecto del radio es 1.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 */

void constructor(Articulo &articulo);

/**
 PRE:
 La instancia del TDA (articulo) no debe haberse creado ni destruido  con anterioridad.
 POST:
 Deja la instancia del TDA (articulo) listo para ser usado.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 No aplica.
 */

void destructor(Articulo &articulo);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el codigo del articulo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el codigo del articulo.
 */
int getCodigoArticulo(Articulo &articulo);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 El articulo queda con el nuevo codigo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 codigo: valor del codigo a asignar al articulo.
 RETORNO:
 No aplica.
 */
void setCodigoArticulo(Articulo &articulo, int codigo);

/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el precio del articulo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el precio del articulo.
 */
float getPrecioArticulo(Articulo &articulo);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 El articulo queda con el nuevo precio.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 precio: valor del codigo a asignar al articulo.
 RETORNO:
 No aplica.
 */
void setPrecioArticulo(Articulo &articulo, float precio);

/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 POST:
 Devuelve el precio del articulo.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 RETORNO:
 Devuelve el precio del articulo.
 */
string getDescripcionArticulo(Articulo &articulo);


/**
 PRE:
 La instancia del TDA (articulo) debe haberse creado (crear) pero no debe estar destruida (destruir).
 El codigo debe ser mayor o igual a cero.
 POST:
 El articulo queda con el nuevo precio.
 ATRIBUTOS:
 articulo: instancia sobre la cual se aplica la primitiva.
 precio: valor del codigo a asignar al articulo.
 RETORNO:
 No aplica.
 */
void setDescripcionArticulo(Articulo &articulo, string descripcion);


#endif /* articulo_h */
