//
//  articulo.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "articulo.h"
#include "lista.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


void constructor(Articulo &articulo){
    articulo.codigoArticulo = 0;
    articulo.precio =0;
    articulo.descripcion = "";
}


void destructor(Articulo &articulo){}


int getCodigoArticulo(Articulo &articulo){
    return articulo.codigoArticulo;
}

void setCodigoArticulo(Articulo &articulo, int codigo){
    // Agrego robustez aunque estoy protegido con la pre.
    if (codigo >= 0) {
        articulo.codigoArticulo = codigo;
    }
}


float getpPrecioArticulo(Articulo &articulo){
    return articulo.precio;
}


void setPrecioArticulo(Articulo &articulo, float precio){
    // Agrego robustez aunque estoy protegido con la pre.
    if (precio > 0) {
        articulo.precio = precio;
    }
}

string getDescripcionArticulo(Articulo &articulo){
    return articulo.descripcion;
}

void setDescripcionArticulo(Articulo &articulo, string descripcion){
    articulo.descripcion = descripcion;
}

