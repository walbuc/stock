//
//  funciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/15/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <stdio.h>
#include "funciones.h"
#include "lista.h"
#include "articulo.h"


ResultadoComparacion compararDatoArticulo(PtrDato ptrDato1, PtrDato ptrDato2) {
    if ( ((Articulo*)ptrDato1)->codigoArticulo > ((Articulo*)ptrDato2)->codigoArticulo ) {
        return MAYOR;
    }
    else if (((Articulo*)ptrDato1)->codigoArticulo < ((Articulo*)ptrDato2)->codigoArticulo) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}
