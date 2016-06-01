
#include "lista.h"
#include "Solicitud.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

void constructor(Solicitud &solicitud)
{
    solicitud.codigoSucursal = 0;
	solicitud.codigoArticulo = 0;
    solicitud.cantidad = 0.0;
	solicitud.hora = "";
}


void destructor(Solicitud &solicitud)
{
}

int getCodigoSucursal(Solicitud &solicitud)
{
	return solicitud.codigoSucursal;
}

void setCodigoSucursal(Solicitud &solicitud, int codigoSucursal)
{
	if (codigoSucursal >= 0) 
	{
		solicitud.codigoSucursal = codigoSucursal;
	}
}

int getCodigoArticulo(Solicitud &solicitud)
{
	return solicitud.codigoArticulo;
}

void setCodigoArticulo(Solicitud &solicitud, int codigoArticulo)
{
	if (codigoArticulo >= 0) 
	{
		solicitud.codigoArticulo = codigoArticulo;
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


