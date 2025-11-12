#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include <fstream>
#include "Back.h"
#include "Orden.h"
#include "Platillo.h"
#include "LinkedPlatillos.h"
using namespace std;





//Complejidad O(n x P) N=No.Ordenes P=Platillos distintos
int Back::llenaArregloPlatillos(Orden ordenes[], Platillo * platillos,long int n ){
    int capacidad=0;
    for(int i=0; i<n; i++){
        string platilloActual=ordenes[i].getPlatillo();
        bool encontrado=false;
        for(int j=0; j<capacidad; j++){
            if(platillos[j].getPlatillo()==platilloActual){
                //Incrementar la cantidad
                int cantidadActual=platillos[j].getCantidad();
                Platillo temp(platilloActual,cantidadActual+1);
                platillos[j]=temp;
                encontrado=true;
                break;
            }
        }
        if(!encontrado){
            //Agregar nuevo platillo
            Platillo temp(platilloActual,1);
            platillos[capacidad]=temp;
            capacidad++;
        }
        
    }
    return capacidad;
}


int Back::retornaNumeroLineas(){
    ifstream f;
    f.open("orders.txt",ios::in);
    if (f.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    char linea[256];
    int nLineas=0;
    while(f.getline(linea,256)){
        nLineas++;
    }
    f.close();
    return nLineas;
}

void Back::cargarOrdenes(Orden ordenes[],long int n){
    ifstream f;
    f.open("orders.txt",ios::in);
    if (f.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    char cadena[255];
    char copia[256];

    for(int i=0; i<n; i++){
        f.getline(cadena,255);
        strcpy(copia,cadena);
        //Separar los datos por comas
        char*mes=strtok(copia," ");
        char*dia=strtok(NULL," ");
        char*hora=strtok(NULL,":");
        char*minuto=strtok(NULL,":");
        char*segundo=strtok(NULL," ");
        char*garbage=strtok(NULL,":");
        char*restaurant=strtok(NULL,":");//Se deben de limpiar los últimos dos caracteres de la cadena
        char*orden=strtok(NULL,"(");
        char*precio=strtok(NULL,")");
        
        Orden temp(mes,dia,hora,minuto,segundo,restaurant,orden,precio);
        ordenes[i]=temp;
    }
    f.close();
}

int Back::preguntaMes(){
            int mesEntradaUsuario;
            bool salidaM=false;
            while(!salidaM){
                try{
                    cout<<"Ingresa el numero de mes (Ej.1=Enero):"<<endl;
                    cin>>mesEntradaUsuario; 

                    if (cin.fail()){
                        throw "Entrada invalida";
                    }
                    if(mesEntradaUsuario<1 || mesEntradaUsuario>12){
                        throw 1;
                    }

                    salidaM=true;
                } 
                catch (int i){ cout<<"Ingresa un valor dentro del rango de meses:"<<endl; }
                catch(...){
                    cout<<"Error, ingresa de nuevo el mes. Recuerda el formato:"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            return mesEntradaUsuario;
        }

int Back::preguntaDia(){
            int diaEntradaUsuario;
            bool salidaD=false;
            while(!salidaD){
                try{
                    cout<<"Ingresa el numero de dia: (Ej:1):"<<endl;
                    cin>>diaEntradaUsuario; 

                    if (cin.fail()){
                        throw "Entrada invalida";
                    }
                    if(diaEntradaUsuario<1 || diaEntradaUsuario>28){
                        throw 1;
                    }

                    salidaD=true;
                } 
                catch (int i){ cout<<"Ingresa un valor dentro del rango de días:"<<endl; }
                catch(...){
                    cout<<"Error, ingresa de nuevo el día. Recuerda el formato:"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            return diaEntradaUsuario;
        }

        //Funcion invocada para retornar un valor entero valido para la hora en el main, no requiere parametro de entrada
int Back::preguntaHora(){
            int horaEntradaUsuario;
            bool salidaH=false;
            while(!salidaH){
                try{
                    cout<<"Ingresa la hora (0-23) (Ej:18):"<<endl;
                    cin>>horaEntradaUsuario; 

                    if (cin.fail()){
                        throw "Entrada invalida";
                    }
                    if(horaEntradaUsuario<0 || horaEntradaUsuario>23){
                        throw 1;
                    }

                    salidaH=true;
                } 
                catch (int i){ cout<<"Ingresa un valor dentro del rango de horas, recuerda que es de 0 a 23 hrs:"<<endl; }
                catch(...){
                    cout<<"Error, ingresa de nuevo la hora. Recuerda el formato:"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            return horaEntradaUsuario;
        }

bool Back::preguntaArchivo(){ 
            bool respuestaB;
            char respuesta;
            bool salir=false;
            while(!salir){
                try{
                    cout<<"Quieres guardar tu archivo? \n Para guardar-> Y  \nCualquier otra letra es tomada como no"<<endl;
                    cin>>respuesta; 

                    if (cin.fail()){
                        throw "Entrada invalida";
                    }
                    if(respuesta=='Y' || respuesta=='y'){respuestaB=true; salir=true;}
                    else{respuestaB=false; salir=true;}
                } 
                catch(...){
                    cout<<"Error"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            return respuestaB;
        }



int Back::buscarFin(Orden *ordenes, int n, int fechaFin){ 
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ordenes[mid].getFechaSegundos() <= fechaFin) {
                    ans = mid;   // candidato válido
                    l = mid + 1; // sigo buscando más a la derecha
                } else {
                    r = mid - 1;
                }
            }
            return ans;
        }

int Back::buscarInicio(Orden *ordenes, int n, int fechaInicio){
            int l = 0, r = n - 1, ans = n; 
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ordenes[mid].getFechaSegundos() >= fechaInicio) {
                    ans = mid;   // candidato válido
                    r = mid - 1; // sigo buscando más a la izquierda
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        }