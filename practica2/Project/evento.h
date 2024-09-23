#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include <iostream>

using namespace std;


struct evento;

void ayadirCodigo(evento& dat, int codigo);
void ayadirDatos(evento& dat);
string hacerCadena(const evento& dat);
int darPrecio(evento& dat);

struct evento{

    friend void ayadirCodigo(evento& dat, int codigo);
    friend void ayadirDatos(evento& dat);
    friend string hacerCadena(const evento& dat);
    friend int darPrecio(evento& dat);


private:


        int precio;
        int codigo;

        string nombre;
        string lugar;

        int dia;
        int mes;
        int horas;
        int minutos;



};




#endif // EVENTO_H_INCLUDED
