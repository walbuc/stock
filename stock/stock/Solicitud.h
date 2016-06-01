#include <string>


/* Tipo de Estructura solicitud. */
struct Solicitud {
    int codigoSucursal;
	int codigoArticulo;
	float cantidad;
	string hora;
};

void constructor(Solicitud &solicitud);

void destructor(Solicitud &solicitud);

int getCodigoSucursal(Solicitud &solicitud);

void setCodigoSucursal(Solicitud &solicitud, int codigo);

int getCodigoArticulo(Solicitud &solicitud);

void setCodigoArticulo(Solicitud &solicitud, int codigo);

float getCantidadSolicitud(Solicitud &solicitud);

void setCantidadSolicitud(Solicitud &solicitud, float cantidad);

string getHoraSolicitud(Solicitud &solicitud);

void setHoraSolicitud(Solicitud &solicitud, string hora);


