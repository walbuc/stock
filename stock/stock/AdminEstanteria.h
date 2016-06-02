#ifndef ADMINESTANTERIA_H
#define ADMINESTANTERIA_H

#include "Lista.h"
#include "Articulo.h"
#include "Pila.h"
#include "Estanteria.h"
#include "Funciones.h"
#include "Ubicacion.h"
#include "Piso.h"

void estadoUbicaciones(Lista &listaUbicacion);

void estadoPisos(Lista &listaPiso);

void imprimirUbicacion(Ubicacion &ubicacion);

void estadoEstanteria(Lista &listaEstanteria);


#endif // ADMINESTANTERIA_H
