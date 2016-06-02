#include "AdminCamiones.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

void cargarCamiones(Lista &listaSolicitudes, Lista &listaCamiones)
{
	PtrNodoLista cursorSolicitud = primero(listaSolicitudes); //cursor para recorrer las solicitudes
	PtrNodoLista cursorCamion; //cursor para recorrer los camiones
	float auxkg, kgtotal;
	
	//creacion del primer camion
	Camion* camion = new Camion;
	crearCamion(*camion);
	setNroCamion(*camion, 1);
	adicionarFinal(listaCamiones, camion); //agrega a la lista de camiones
	cursorCamion = ultimo(listaCamiones); //trae el ultimo camion de la lista (primer camion)
	
	while (cursorSolicitud != fin()) { //lee la solicitud entrante
		auxkg = getCantidadSolicitud(*(Solicitud*) cursorSolicitud->ptrDato); //kg de la solicitud
		kgtotal = auxkg + getCargaTotal(*(Camion*) cursorCamion->ptrDato); //suma de la solicitud con la carga del camion 
		if (kgtotal <= getKGcapacidad(*(Camion*) cursorCamion->ptrDato)){ // si no supera la capacidad total del camion actual
			setCargaTotal(*(Camion*) cursorCamion->ptrDato, kgtotal); //guarda la carga en el camion
			cursorSolicitud = siguiente(listaSolicitudes, cursorSolicitud); //pasa al a siguiente solicitud
		}
		else{ // si no entra en el camion
		//crea nuevo camion
			Camion* camion = new Camion;
			crearCamion(*camion);
			setNroCamion(*camion, (getNroCamion(*(Camion*) cursorCamion->ptrDato)+1));//sumo 1 al id
			adicionarFinal(listaCamiones, camion);
			cursorCamion = ultimo(listaCamiones); //trae el ultimo camion de la lista (camion nuevo)
			setCargaTotal(*(Camion*) cursorCamion->ptrDato, auxkg); //mete la carga de la solicitud que no entro en el camion anterior
			cursorSolicitud = siguiente(listaSolicitudes, cursorSolicitud); //pasa a la siguiente solicitud
		}
	}
}

//LISTAR CAMIONES EN PANTALLA
/*
void listarCamiones (Lista &listaCamiones) 
{
	PtrNodoLista cursorCamion = ultimo(listaCamiones); //cursor para recorrer los camiones
	cout << "Nro Camion \t cargaTotal \t porcentaje Ocupacion" << endl;
	while (cursorCamion != fin()) {
		cout << getNroCamion(*(Camion*) cursorCamion->ptrdato) << "\t" << 
		getCargaTotal(*(Camion*) cursorCamion->ptrdato) << "\t" << 
		calcularPorcentajeOcupado(*(Camion*) cursorCamion->ptrdato) << endl;
		cursorCamion = anterior(listaCamiones);
		
	}

}
*/
void utilizacionCamiones(Lista &listaCamiones) {
    PtrNodoLista cursorCamion = ultimo(listaCamiones);
	FILE *pf;
    if ((pf = fopen("UtilizacionCamiones.txt", "w")) == NULL) {
        cout << "Error al abrir el fichero de aplicaciones" << endl;
    }

    while (cursorCamion != fin()) {
        fprintf(pf, "%d;%.3f;%.2f\n", getNroCamion(*(Camion*) cursorCamion->ptrDato), getCargaTotal(*(Camion*) cursorCamion->ptrDato),
            calcularPorcentajeOcupado(*(Camion*) cursorCamion->ptrDato));

        cursorCamion = anterior(listaCamiones, cursorCamion);
    }
    fclose(pf);
}
