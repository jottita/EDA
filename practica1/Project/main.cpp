#include <iostream>

#include "estudiantes.h"
#include "unizar.h"

using namespace std;
/*
cosas que revisar:
    redondear  nota
    como borrar el vector entreo en eliminarexpediente

*/

void inscripcion(estudiantes<unizar>& est){
    string nip,titulacion,nombre;
    unizar valor;
if(!enMatricula(est)){

    cout<<"INTRODUZCA NIP: ";
    cin>>nip;
    cout<<"INTRODUZCA NOMBRE ";
    cin>>nombre;
    cout<<"INTRODUZCA SU TITULACION: ";
    cin>>titulacion;

    crearExp(nombre,titulacion,valor);

        cout<<"INSCRIPCION ABIERTA"<<endl;

        if(pertenece(est,nip)){
            anyadir(est,nip,valor);
            cout<<"ESTUDIANTE ACTUALIZADO: ";

        }else{
            anyadir(est,nip,valor);
            cout<<"ESTUDIANTE INSCRITO: ";

        }
        cout<<"NIP:" <<nip<<endl<<"NOMBRE: "<<nombre<<endl<<"TITULACION: "<<titulacion<<endl;

    }else{
        cout<<"INSCRIPCION CERRADA";

    }
    cout<<endl;
}

void borrarEstudiante(estudiantes<unizar>& est){

    if(!enMatricula(est)){

    string nip;
    cout<<"INTRODUZA SU NIP: ";
    cin>>nip;

        if(pertenece(est,nip)){

            quitar(est,nip);
            cout<<"ESTUDIANTE BORRADO: "<<nip;

        }else{
            cout<<"ESTUDIANTE NO ENCONTRADO";
        }
    }else{

        cout<<"INSCRIPCION CERRADA";

    }
    cout<<endl;
}
void mostrarEstudiante(estudiantes<unizar>& est){
    if(esVacia(est)){
        cout<<"NO EXISTEN ESTUDIANTES";
    }else{
        string nip;
        unizar valor;
        cout<<"INTRODUZCA NIP: ";
        cin>>nip;

        if(pertenece(est,nip)){

            obtenerValor(est,nip,valor);
            cout<<"NIP: "<<nip<<endl<<generaCadena(valor);

        }else{

            cout<<"ESTUDIANTE NO ENCONTRADO";
        }

    }
    cout<<endl;
}
void cerrarIns(estudiantes<unizar>& est){

    cerrarInscripcion(est);
    cout<<"INSCRIPCION CERRADA CON "<<cardinal(est)<<endl;
    cout<<"NO SE ADMITEN MAS INSCRIPCIONES"<<endl;

}
void estudiantesMatricula(estudiantes<unizar>& est){

    if(esVacia(est)){

        cout << "NO EXISTEN ESTUDAINTES"<<endl;

    }else if(enMatricula(est)){

        string c;
        unizar valor;
        obtenerCandidatoSuClave(est,c);
        obtenerCandidatoSuValor(est,valor);
        cout << "ESTUDANTE EN MATRICULA: "<<c<<" NOMBRE: "<<darNombre(valor)<<endl;


    }else{

        cout<<"TODAVIA NO HA EMPEZADO EL PROCESO DE MATRICULA"<<endl;

    }
}
void descartarEstudiantesMatricula(estudiantes<unizar>& est){

    string c;
    obtenerCandidatoSuClave(est,c);
    if(esVacia(est)){

        cout << "NO EXISTEN ESTUDIANTES"<<endl;

    }else if(enMatricula(est)){

        if(pertenece(est,c)){
         quitar(est,c);
         cout<<"ESTUDIANTE ELIMINADO:  "<< c<<endl;
        }

    }else{

        cout<<"TODAVIA NO HA EMPEZADO EL PROCESO DE MATRICULA"<<endl;
    }

}
void actualizarMatricula(estudiantes<unizar>& est){
    string c;
    unizar v;
    int codigo;
    double nota;
    int op;
    obtenerCandidatoSuClave(est,c);
    obtenerCandidatoSuValor(est,v);

    if(esVacia(est)){

         cout << "NO EXISTEN ESTUDIANTES"<<endl;

    }else if(enMatricula(est)){

        do{
            cout<<"INTRODUCE ASIGNAATURA: ";
            cin>>codigo;
            cout<<"INTRODUCE NOTA: ";
            cin>>nota;
            if(codigo>999 && codigo<10000 || nota>0.00 && nota<10.00){

                ayadirSignature(v,codigo);
                ayadirCali(v,codigo,nota);


            }else{

                cout << "ERROR AL INTRODUCIR LA ASIGNATURA"<<endl;

            }
            cout<<"¿DESEAS INTRODUCIR MAS ASIGNATURAS?(0 SI/1 NO): ";
            cin>>op;

        }while(op!=1);

            actualizarCandidato(est,v);
            cout<<"ESTUDIANTE ACTUALIZADO "<<c<<endl;
            cout<<generaCadena(v);

    }else{

        cout<<"TODAVIA NO HA COMENZADO MATRICULA"<<endl;
    }


}
void PasaTurno(estudiantes<unizar>& est){

        if(enMatricula(est) && !esVacia(est)){

            pasarTurno(est);
            string c;
            unizar v;
            obtenerCandidatoSuClave(est,c);
            obtenerCandidatoSuValor(est,v);
            cout << "TURNO DEL ESTUDIANTE "<<c<<" "<<"NOMBRE: "<<darNombre(v)<<endl;

        }else if(!enMatricula(est)){

                cout<<"TODAVIA NO HA COMENZADO EL PROCESO DE MATRICULA"<<endl;



        }else{
            cout << "NO EXISTEN ESTUDIANTES"<<endl;

        }

    }

void lista(estudiantes<unizar>& est){
    if(!esVacia(est)){

        listar(est);
        string c;
        obtenerCandidatoSuClave(est,c);
        cout<<"TURNO DE MATRICULA ESTUDIANTE: "<<c<<endl;

        if(!enMatricula(est)){
            cout<<"TODAVIA NO HA COMENZADO EL PROCESO DE MATRICULA"<<endl;

        }

    }else{

        cout << "NO EXISTEN ESTUDIANTES"<<endl;

    }

}
int main()
{
    int opcion=-1;
    estudiantes<unizar> est;
    crear(est);
    while (opcion != 0) {

        cout << "Opciones eupt seleccion" << endl;
        cout << "-----------------------"<<endl;
        cout << "1.- Inscribir ESTUDIANTE" << endl;
        cout << "2.- Borrar ESTUDIANTE" << endl;
        cout << "3.- Mostrar ESTUDIANTE"<<endl;
        cout << "4.- Cerrar inscripcion"<<endl;
        cout << "5.- Obtener estudiante en matricula"<<endl;
        cout << "6.- Descartar estudiante en matricula"<<endl;
        cout << "7.- Actualizar matricula estudiante"<<endl;
        cout << "8.- Pasar turno"<<endl;
        cout << "9.- Listar todos los estudiantes"<<endl;
        cout << "0.- Salir" << endl<<endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                inscripcion(est);
            break;

            case 2:
                borrarEstudiante(est);
            break;

            case 3:
                mostrarEstudiante(est);
            break;

            case 4:
                cerrarIns(est);
            break;

            case 5:
                estudiantesMatricula(est);
            break;

            case 6:
                descartarEstudiantesMatricula(est);
            break;

            case 7:
                actualizarMatricula(est);
            break;

            case 8:
                PasaTurno(est);
            break;

            case 9:
                lista(est);
            break;
        }
    }
}
