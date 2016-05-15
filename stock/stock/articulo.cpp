//
//  articulo.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "articulo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void cargarArchivo(const char ruta[]) {
    
    int codigo;
    float precio;
    char descripcion[100]; //no lo uso todavia

    FILE *fin = fopen(ruta, "r");
    
    if (fin != NULL) {
        while (fscanf(fin,"%d;%f", &codigo, &precio) > 0) {
            
            cout << codigo << " "  << precio ;
            //puedo tener varios constructores y pasar directamente?
            Articulo articulo;
            setCodigoArticulo(articulo, codigo);
            setPrecioArticulo(articulo, precio);
            
            //
            
        
        }
        
        fclose(fin);
    } else
    {  
        cout << "No se puede abrir el archivo";
    }
}



void cargarMaestroDeArtículos() {

    const char ruta[] = "/Users/walter/Documents/personal-repositories/stock/stock/stock/articulos.db";
    
    cargarArchivo(ruta);
}


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

void constructor(Articulo &articulo){}

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

void destructior(Articulo &articulo){}


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
int getCodigoArticulo(Articulo &articulo){
    return articulo.codigoArticulo;
}


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
void setCodigoArticulo(Articulo &articulo, int codigo){
    // Agrego robustez aunque estoy protegido con la pre.
    if (codigo >= 0) {
        articulo.codigoArticulo = codigo;
    }
}

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
float getpPrecioArticulo(Articulo &articulo){
    return articulo.precio;
}


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
void setCodigoArticulo(Articulo &articulo, float precio){
    // Agrego robustez aunque estoy protegido con la pre.
    if (precio > 0) {
        articulo.precio = precio;
    }
}

//falta descripcion
