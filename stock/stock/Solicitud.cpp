
#include "lista.h"
#include "Solicitud.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

void constructorSolicitud(Solicitud &solicitud)
{
    solicitud.idSolicitud=0;
    solicitud.codigoSucursal = 0;
	solicitud.codigoArticulo = 0;
    solicitud.cantidad = 0.0;
    solicitud.cantidadCumplida=0.0;
	solicitud.hora = "";
}


void destructorSolicitud(Solicitud &solicitud)
{
}

int getIdSolicitud(Solicitud &solicitud){
    return solicitud.idSolicitud;
}

void setIdSolicitud(Solicitud &solicitud, int idSolicitud){
    solicitud.idSolicitud=idSolicitud;
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

float getCantidadCumplida(Solicitud &solicitud){
return solicitud.cantidadCumplida;
}

void setCantidadCumplida(Solicitud &solicitud, float cantidad){
solicitud.cantidadCumplida=cantidad;
}


string getHoraSolicitud(Solicitud &solicitud)
{
    return solicitud.hora;
}

void setHoraSolicitud(Solicitud &solicitud, string hora)
{
	solicitud.hora = hora;
}


