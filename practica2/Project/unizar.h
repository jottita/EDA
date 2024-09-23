#ifndef UNIZAR_H_INCLUDED
#define UNIZAR_H_INCLUDED
#include "evento.h"
#include<iostream>


using namespace std;

const int TAM_MAX = 40;
const int PRECIO_MAX = 300;

struct unizar;
void crearExp(string nombre,string titulacion,unizar& expediente);
string darNombre(const unizar& expediente);
void ayadirTicket(unizar& expediente,int codigo);
void ayadirPrecio(unizar& expediente,int codigo,int precio);
string generaCadena(const unizar& expediente);
void eliminarTicket(unizar& expediente,int codigo);
void eliminarExp(unizar& expediente);
bool precioLimite(const unizar& expediente,int precio);

struct unizar{
    friend void crearExp(string nombre,string titulacion,unizar& expediente);
    friend string darNombre(const unizar& expediente);

    friend void ayadirTicket(unizar& expediente,int codigo);
    friend void ayadirPrecio(unizar& expediente,int codigo,int precio);
    friend string generaCadena(const unizar& expediente);
    friend void eliminarTicket(unizar& expediente,int codigo);
    friend void eliminarExp(unizar& expediente);
    friend bool precioLimite(const unizar& expediente,int precio);

private:
    string nombre = "";
    string titulacion = "";
    struct concierto{
        int codigo = 0;
        int precio = 0;// al no estar especificado hemos decidido que el precio de los tickets no tenga decimales

    };

    concierto asignaturas[TAM_MAX];
    int tamanio=0;
};

#endif // UNIZAR_H_INCLUDED
