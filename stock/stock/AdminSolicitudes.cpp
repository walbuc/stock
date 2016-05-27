
#include <stdio.h>
#include "AdminSolicitudes.h"
#include "fstream"
#include <iostream>

using namespace std;

void cargarSolicitudes(Lista &listaSolicitudes)
{
    
    ifstream fsolicitudes;
    string dato;
    
    fsolicitudes.open("solicitudes.db");
    
    if (fsolicitudes.is_open())
	{

        while (farticulos.good())
		{

            //new devuelve puntero al tipo de dato
            Solicitud* ptrSolicitud = new Solicitud;
            
            constructor(*ptrSolicitud);
            
			//seteo codigo de Sucursal (int)
            getline(fsolicitudes,dato,';');
            getCodigoSucursal(*ptrSucursal, cadenaAentero(dato));

			//seteo codigo de Articulo (int)
			getline (fsolicitudes, dato,';');
			getCodigoArticulo(*ptrSucursal, cadenaAentero(dato));

			//seteo la cantidad (float) de kg de la solicitud
			getline (fsolicitudes, dato,';');
            setCantidadSolicitud(*ptrSolicitud, cadenaAfloat(dato));
            
			//seteo la hora (string) de la solicitud
			getline (fsolicitudes, dato,';');
            setHoraSolicitud(*ptrSolicitud, dato);

			// En este lugar del codigo debo validad el stock de las solicitudes

			//Agrego los datos de la solicitud a una lista de solicitudes
            adicionarFinal(listaSolicitudes, ptrSolicitud);
        }
        
        fsolicitudes.close();
        
    }
    
    else
	{

        cout << "Error al abrir el archivo." << endl << endl;
        system ("PAUSE");

    }

}


void cargarMaestroDeSolicitudes(Lista &listaSolicitudes, Lista &listaIndice) 
{

	cargarSolicitudes(listaSolicitudes);  

}

bool existeArticulo()
{

}

/*verifica la existencia del articulo*/
bool existeStockArticulo();

/* si el articulo no cumple con la totalidad o la parcialidad
de las 2 condiciones anteriores,
carga el articulo en la cola de articulos pendientes */
void agregarPendiente();

/* en caso contrario,
carga el articulo en la lista de pedido */
void agregarSolicitud();
