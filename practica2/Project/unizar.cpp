#include "unizar.h"
#include <iomanip>
#include<sstream>

void crearExp(string nombre,string titulacion,unizar& expediente){
    expediente.nombre=nombre;
    expediente.titulacion=titulacion;
}
string darNombre(const unizar& expediente){

    return expediente.nombre;
}

void ayadirTicket(unizar& expediente,int codigo){

   if(expediente.tamanio >= TAM_MAX){

        cout << "SE HA ALCANZADO EL NUMERO MAXIMO DE TICKETS QUE SE PUEDEN COMPRAR"<<endl;

   }else{

       for(int i=0; i<TAM_MAX;i++){

           if(expediente.asignaturas[i].codigo==0){

                expediente.asignaturas[i].codigo=codigo;
                expediente.tamanio++;
                break;

            }
       }
   }
}
void ayadirPrecio(unizar& expediente,int codigo,int precio){



    for(int i=0;i<expediente.tamanio;i++){
        if(expediente.asignaturas[i].codigo == codigo){
            expediente.asignaturas[i].precio = precio;

        }
    }
}

bool precioLimite(const unizar& expediente,int precio){

    int suma = 0;

    for(int i = 0; i < expediente.tamanio; i++){

         suma = suma + expediente.asignaturas[i].precio;


    }

    suma += precio;

    if(suma <= PRECIO_MAX){

        return true;

    }else{

        return false;

    }



};
string generaCadena(const unizar& expediente){

    ostringstream cadena_listado;
    if(!expediente.nombre.empty()){
    cadena_listado<<"Nombre: "<<expediente.nombre<<endl<<"Titulacion: "<<expediente.titulacion<<endl;
    for(int i=0;i<expediente.tamanio;i++){
        if (i==0){
              cadena_listado<<"TICKETS:"<<endl;
        }
        cadena_listado<<"codigo: "<<expediente.asignaturas[i].codigo<<" "<<"Precio: "<<setprecision(3)<<expediente.asignaturas[i].precio<<endl;
    }

    }
    return cadena_listado.str();
}
void eliminarTicket(unizar& expediente,int codigo){
    for(int i=0;i<expediente.tamanio;i++){
        if(expediente.asignaturas[i].codigo==codigo){
            expediente.asignaturas[i].codigo=0;
            expediente.asignaturas[i].precio=0;
            expediente.tamanio--;
            break;
        }
    }
}


void eliminarExp(unizar& expediente){
    expediente.nombre.clear();
    expediente.titulacion.clear();
    expediente.tamanio=0;

    cout<<"El expediente ha sido eliminado"<<endl;
}








