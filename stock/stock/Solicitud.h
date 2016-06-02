#ifndef SOLICITUD_H
#define SOLICITUD_H




#include <string>
using namespace std;

/* Tipo de Estructura solicitud. */
typedef struct  {
    int idSolicitud;
    int codigoSucursal;
	int codigoArticulo;
	float cantidad;
	float cantidadCumplida;
	string hora;
}Solicitud;

void constructorSolicitud(Solicitud &solicitud);

void destructorSolicitud(Solicitud &solicitud);

int getIdSolicitud(Solicitud &solicitud);

void setIdSolicitud(Solicitud &solicitud, int idSolicitud);

int getCodigoSucursal(Solicitud &solicitud);

void setCodigoSucursal(Solicitud &solicitud, int codigo);

int getCodigoArticulo(Solicitud &solicitud);

void setCodigoArticulo(Solicitud &solicitud, int codigo);

float getCantidadSolicitud(Solicitud &solicitud);

void setCantidadSolicitud(Solicitud &solicitud, float cantidad);

float getCantidadCumplida(Solicitud &solicitud);

void setCantidadCumplida(Solicitud &solicitud, float cantidad);


string getHoraSolicitud(Solicitud &solicitud);

void setHoraSolicitud(Solicitud &solicitud, string hora);

#endif // SOLICITUD_H
