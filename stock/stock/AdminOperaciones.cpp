//
//  AdminOperaciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "AdminOperaciones.h"

#include <string.h>
#include "fstream"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>


using namespace std;

void leerArchivosOperaciones(){
    
    ifstream fingresos, fsolicitudes;
    string dato;
    int idArticulo, hora =0, minuto=0, segundo=0, idArticuloSucursal=0, idSucursal=0, horaS=0, minutoS=0, segundoS=0, resultado=0;
    float cantidad, cantidadSucursal;
    bool flagIngreso = false;
    bool flagSolicitud = false;
    bool compararSolicitud = true;
    bool compararIngreso = true;
    
    fingresos.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/ingresos.db");
    fsolicitudes.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/solicitudes.db");
    
    if (fingresos.is_open() && fsolicitudes.is_open()){
        
        while (fingresos.good() || fsolicitudes.good()){
            
            if(flagSolicitud == false){
            
                getline(fingresos,dato,';');
                idArticulo = cadenaAentero(dato);
            
                getline(fingresos,dato,';');
                cantidad = cadenaAfloat(dato);
            
                getline(fingresos,dato,':');
                hora = cadenaAentero(dato);
                getline(fingresos,dato,':');
                minuto = cadenaAentero(dato);
                getline(fingresos,dato);
                segundo = cadenaAentero(dato);
                
                if(dato.length() == 0) {
                    compararIngreso = false;
                }
        
            }
            
            if(flagIngreso == false){
                getline(fsolicitudes,dato,';');
                idSucursal = cadenaAentero(dato);
            
                getline(fsolicitudes,dato,';');
                idArticuloSucursal = cadenaAentero(dato);
            
                getline(fsolicitudes,dato,';');
                cantidadSucursal = cadenaAfloat(dato);
            
                getline(fsolicitudes,dato,':');
                horaS = cadenaAentero(dato);
                getline(fsolicitudes,dato,':');
                minutoS = cadenaAentero(dato);
                getline(fsolicitudes,dato);
                segundoS = cadenaAentero(dato);
                
                if(dato.length() == 0) {
                    compararSolicitud = false;
                }
            }
            
            dato = "";
            
            
            if(!compararIngreso && compararSolicitud){
                //procesarSolicitud
                cout << "proceso solicitud\n";
                flagSolicitud= true;
                flagIngreso = false;
            }
            
            if(compararIngreso && !compararSolicitud){
                //procesarIngreso
                cout << "proceso ingreso\n";
                flagIngreso = true;
                flagSolicitud =false;
            }
            
            if(compararIngreso && compararSolicitud){
                resultado = compararHoras(hora, minuto, segundo, horaS, minutoS, segundoS);
                
                if (resultado > 0) {
                    //procesarSolicitud
                    cout << "proceso solicitud\n";
                    flagSolicitud= true;
                    flagIngreso = false;
                } else if(resultado < 0) {
                    //procesarIngreso
                    cout << "proceso ingreso\n";
                    flagIngreso = true;
                    flagSolicitud =false;
                }
            }
            
        }
        
        fingresos.close();
        fsolicitudes.close();
        
    }
    
    else{
        
        cout << "Error al abrir los archivos." << endl << endl;
        
        system ("PAUSE");
        
    }
}

int compararHoras(int hora, int minuto, int segundo, int hora1, int minuto1, int segundo1) {
    
    if(hora > hora1){
        return 1;
    }
    else if(hora < hora1){
        return -1;
    }else if(hora == hora1){
        if (minuto > minuto1){
            return 1;
        } else if (minuto < minuto1){
            return -1;
        } else if (minuto == minuto1){
            if (segundo > segundo1){
                return 1;
            } else if (segundo < segundo1){
                return -1;
            } else if (segundo == segundo1){
                return 0;
            }
        }
    }
    
    return -2;
}

