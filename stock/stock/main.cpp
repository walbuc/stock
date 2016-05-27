//
//  main.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <iostream>
#include "AdminArticulos.h"
#include "AdminEstanteria.h"
#include "lista.h"
#include "funciones.h"
#include "estanteria.h"
#include "Articulo.h"
#include "AdminOperaciones.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    Lista listaArticulo;
    Lista listaIndice;
    
    crearLista(listaArticulo, &compararDatoArticulo);
    
    cargarMaestroDeArticulos(listaArticulo, listaIndice);
    
    Estanteria estanteria;
    //construirEstanteria(estanteria);
    
    //configurarEstanteria(estanteria);
    //imprime el nro de calle, cantidad de pisos y ubicaciones, y Kilos por camion
    //imprimirEstanteria(estanteria);
    
    leerArchivosOperaciones();
    
    
    cout << "Hello, World!\n";
    return 0;
}
