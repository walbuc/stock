#include <cstdlib>;
#include <iostream>;
#include <string>;
#include <stdio>
#include "articulo.h";
#include "sucursal.h";

using namespace std;

#ifndef __SOLICITUD_H__
#define __SOLICITUD_H__
#ifndef NULL
#define NULL 0
#endif


void cargarArchivo(const char ruta[])
{
	Sucursal codigoSucursal;
	Articulo codigoArticulo;
	float cantidad;
	string hora;

    FILE *f = fopen(ruta, "r");
    
    if (f != NULL) {
        while (fscanf(fin,"%d;%f", &codigoSucursal, &codigoArticulo, &cantidad, &hora) > 0) {
            
            cout << codigoSucursal << " "  << codigoArticulo << " "  << cantidad << " "  << hora;
            
			Solicitud solicitud;
            constructor(solicitud, codigoSucursal, codigoArticulo, cantidad, hora);
		}
        
		fclose(fin);
    } 
	
	else
    {  
        cout << "No se puede abrir el archivo";
    }

}

void cargarSolicitudes() {
    const char ruta[] = "/Users/walter/Documents/personal-repositories/stock/stock/stock/solicitudes.db";
    cargarArchivo(ruta);
}

void constructor(Solicitud &solicitud)
{
	Sucursal.codigoSucursal = 0;
	Articulo.codigoArticulo = 0;
	float cantidad = 0.0;
	string hora = 00:00:00;
}

void destructor(Solicitud &solicitud)
{
}

int getCodigoSucursal(Sucursal &sucursal)
{
	return sucursal.codigoSucursal;
}

void setCodigoSucursal(Sucursal &sucursal, int codigoSucursal)
{
	if (codigoSucursal >= 0) 
	{
		sucursal.codigoSucursal = codigoSucursal;
	}
}

int getCodigoArticulo(Articulo &articulo)
{
	return articulo.codigoArticulo;
}

void setCodigoArticulo(Articulo &articulo, int codigoArticulo)
{
	if (codigoArticulo >= 0) 
	{
		articulo.codigoArticulo = codigoArticulo;
	}
}

float getCantidadSolicitud(Solicitud &solicitud)
{
	return solicitud.cantidad;
}

void setCantidadSolicitud(Solicitud &solicitud, float cantidad)
{
	if (cantidad >= 0) 
	{
		solicitud.cantidad = cantidad;
	}
}

string getHoraSolicitud(Solicitud &solicitud)
{
	return solicitud.hora;
}

void setHoraSolicitud(Solicitud &solicitud, string hora)
{
		solicitud.hora = hora;
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