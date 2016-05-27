

#ifndef AdminSolicituides_h
#define AdminSolicitudes_h

#include "lista.h"
//#inlcude "cola.h"
#include "solicitud.h"
#include "funciones.h"


void cargarSolicitudes(Lista &listaSolicitudes);

void cargarMaestroDeSolicitudess(Lista &listaSolicitudes, Lista &listaIndice);

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

#endif /* AdminSolicitud_h */
