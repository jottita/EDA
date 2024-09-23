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

void ayadirSignature(unizar& expediente,int codigo){

   for(int i=0; i<TAM_MAX;i++){
        if(expediente.asignaturas[i].codigo==0){
            expediente.asignaturas[i].codigo=codigo;
            expediente.tamanio++;
            break;
        }
   }
}
void ayadirCali(unizar& expediente,int codigo,double calificacion){
    for(int i=0;i<expediente.tamanio;i++){
        if(expediente.asignaturas[i].codigo==codigo){
            expediente.asignaturas[i].calificacion=calificacion;

        }
    }
}
string generaCadena(const unizar& expediente){
    ostringstream cadena_listado;
    if(!expediente.nombre.empty()){
    cadena_listado<<"Nombre: "<<expediente.nombre<<endl<<"Titulacion: "<<expediente.titulacion<<endl;
    for(int i=0;i<expediente.tamanio;i++){
        if (i==0){
              cadena_listado<<"ASIGNATURAS:"<<endl;
        }
        cadena_listado<<"codigo: "<<expediente.asignaturas[i].codigo<<" "<<"Calificacion: "<<setprecision(3)<<expediente.asignaturas[i].calificacion<<endl;
    }

    }
    return cadena_listado.str();
}
void eliminarAsignatura(unizar& expediente,int codigo){
    for(int i=0;i<expediente.tamanio;i++){
        if(expediente.asignaturas[i].codigo==codigo){
            expediente.asignaturas[i].codigo=0;
            expediente.asignaturas[i].calificacion=0;
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








