//
//  articulo.h
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#ifndef articulo_h
#define articulo_h


#endif /* articulo_h */


/* Tipo de Estructura Articulo. */
struct Articulo {
    int codigoArticulo;
    float precio;
    char descripcion[];
};

void cargarMaestroDeArtículos();

void cargarArchivo(const char ruta[]);
