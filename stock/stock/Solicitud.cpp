include <cstdlib>;
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
	// debo validar el string para dar robustez
	solicitud.hora = hora;
}
