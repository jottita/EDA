#include <iostream>
#include "evento.h"
#include "conciertos.h"
#include "unizar.h"

using namespace std;

void introducirConcierto( conciertos<int, evento>& c){
    evento event;
    int codigo;
    bool esta_dentro = false;

    cout << "Codigo del evento: ";
    cin >> codigo;

    esta_dentro = existeClave(c,codigo);

    //if(){
    ayadirCodigo(event,codigo);
    ayadirDatos(event);
    insertar(c,codigo,event);
        if(esta_dentro){
            cout << "ACTUALIZACION REALIZADA: "<< endl;
        }else{
            cout << "INSERCION REALIZADA: "<< endl;
        }
    /*}else{
        cout << "INSERCION DESCARTADA"<< endl;
    }*/
}
void mostrarConcierto(conciertos<int, evento>& c){
    int codigo;
    evento v;

    cout << "Codigo del evento: ";
    cin >> codigo;
    if(obtenerDato( c, codigo, v)){
        cout << hacerCadena(v)<< endl;
    }else {
        cout <<"Concierto no existe"<< endl;
    }
}
void eliminarConcierto(conciertos<int, evento>& c){
    int codigo;
    evento v;

    cout << "Codigo del evento: ";
    cin >> codigo;


    if(existeClave(c,codigo)){
        borrar(c, codigo);
        cout << "CONCIERTO BORRADO: " << codigo<< endl;

    }else{

        cout << "BORRADO DESCARTADO: " << codigo << endl;

    }
}

void inscribirClientes(unizar& u ){

    string nombre,titulacion;

    if(darNombre(u).empty()){

        cout << "Escriba el nombre del alumno: ";
        cin >> nombre;
        cout << "Escriba la titulacion del alumno: ";
        cin >> titulacion;

        crearExp(nombre,titulacion,u);
        cout<< "Cliente INSCRITO"<<endl;

    }else{

        cout<< "No se pudo inscribir al cliente" << endl;

    }

}

void mostrarCliente(const unizar& u){

    if(darNombre(u).empty()){

        cout << "Aun no se ha inscrito un cliente"<<endl;

    }else {


        cout << generaCadena(u);

    }

}

void comprarTicket(unizar &u,conciertos<int,evento>& c){

    int codigo,p;
    evento v;


    if(!darNombre(u).empty()){
        if(!esVacio(c)){
            cout << listar(c);

            cout << "Codigo del ticket que desea comprar: ";
            cin >> codigo;

            if(existeClave(c,codigo)){

                obtenerDato(c,codigo,v);
                p = darPrecio(v);

                if(precioLimite(u,p)){

                    ayadirTicket(u,codigo);
                    ayadirPrecio(u,codigo,darPrecio(v));
                    cout << "El ticket del concierto " << codigo << " ha sido comprado" << endl;

                }else {

                    cout << "Se ha alcanzado el precio maximo" << endl;

                }
            }else{

                cout << "EL CODIGO NO PERTENECE A NINGUN CONCIERTO" << endl;
            }

        }else{

            cout << "NO HAY CONCIERTOS" << endl;
        }
    }else{

        cout << "NO HAY CLIENTES" << endl;
    }
}



int main()
{
    int opcion ;
    conciertos<int, evento> conchertos;
    unizar u;
    crear(conchertos);
       do{
        cout << "*------------------------------*" << endl;
        cout << " Venta y inscripcion de eventos" << endl;
        cout << "*------------------------------*"<<endl;
        cout << "1.- Introducir Concierto" << endl;
        cout << "2.- Mostrar Concierto " << endl;
        cout << "3.- Eliminar Concierto"<<endl;
        cout << "4.- Listar Conciertos"<<endl;
        cout << "5.- Inscribir Cliente"<<endl;
        cout << "6.- Mostrar cliente"<<endl;
        cout << "7.- Comprar Tickets"<<endl;
        cout << "0.- Salir" << endl<<endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                introducirConcierto(conchertos);
                break;

            case 2:
                mostrarConcierto(conchertos);
                break;

            case 3:
                eliminarConcierto(conchertos);
                break;

            case 4:
                cout << listar(conchertos);
                break;

            case 5:
                inscribirClientes(u);
                break;

            case 6:
                mostrarCliente(u);
                break;

            case 7:
                comprarTicket(u, conchertos);
                break;
        }
       } while (opcion != 0);

}


