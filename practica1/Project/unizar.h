#ifndef UNIZAR_H_INCLUDED
#define UNIZAR_H_INCLUDED
#include<iostream>


using namespace std;

const int TAM_MAX=40;
struct unizar;
void crearExp(string nombre,string titulacion,unizar& expediente);
string darNombre(const unizar& expediente);
void ayadirSignature(unizar& expediente,int codigo);
void ayadirCali(unizar& expediente,int codigo,double calificacion);
string generaCadena(const unizar& expediente);
void eliminarAsignatura(unizar& expediente,int codigo);
void eliminarExp(unizar& expediente);

struct unizar{
    friend void crearExp(string nombre,string titulacion,unizar& expediente);
    friend string darNombre(const unizar& expediente);

    friend void ayadirSignature(unizar& expediente,int codigo);
    friend void ayadirCali(unizar& expediente,int codigo,double calificacion);
    friend string generaCadena(const unizar& expediente);
    friend void eliminarAsignatura(unizar& expediente,int codigo);
    friend void eliminarExp(unizar& expediente);
private:
    string nombre;
    string titulacion;
    struct signature{
        int codigo=0;
        double calificacion=0;// Hay que revisar porque con floats da problemas
    };
    signature asignaturas[TAM_MAX];
    int tamanio=0;
};

#endif // UNIZAR_H_INCLUDED
