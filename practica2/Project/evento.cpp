#include "evento.h"
#include <sstream>

void ayadirCodigo(evento& dat,int codigo){

    dat.codigo = codigo;

}

void ayadirDatos(evento& dat){
    //Precio del concierto
    int p;

    cout << "Precio del concierto: ";
    cin >> p;
    dat.precio = p;
    //Nombre del concierto
    string n;

    cout << "Nombre del concierto: ";
    cin >> n;

    dat.nombre = n;


    //Lugar del concierto
    string l;

    cout << "Lugar del concierto: ";
    cin >> l;

    dat.lugar = l;

    //Fecha del concierto

    int d,m,h,x;

    cout << "Fecha del concierto (dia mes numerico): ";
    cin >> d >> m;

    dat.dia = d;
    dat.mes = m;

    //Hora del concierto
    cout << "Hora del concierto (horas minutos): " ;
    cin >> h >> x;

    dat.horas = h;
    dat.minutos = x;


}

string hacerCadena(const evento& dat){
    ostringstream info;

    info << "Concierto: " << dat.nombre << endl
    << "Lugar: " << dat.lugar << endl
    << "Fecha: " << dat.dia << "/" << dat.mes << endl
    << "Hora: " << dat.horas << ":" << dat.minutos <<endl
    << "Precio: "<< dat.precio << " Euros";

    return info.str();



}

int darPrecio(evento& dat){

    return dat.precio;

}
