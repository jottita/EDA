#include "unizar.h"

void crearExp(string nombre,string titulacion,unizar& expediente){
        expediente.nombre=nombre;
        expediente.titulacion=titulacion;
}

void ayadirSignature(unizar &expediente,int codigo){
    for(int i = 0;i<expediente.asignaturas.size()-1;i++){
        if(expediente.asignaturas[i].codigo==0){
            expediente.asignaturas[i].codigo=codigo;

        }

    }


}
