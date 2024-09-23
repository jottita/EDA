#include <iostream>

using namespace std;

struct celda{
    int tamanio=0;
    int clave,valor;
    celda*puntero;
};

int main(){
    celda z,y;

    z.clave=1;
    z.valor=54;
    z.tamanio++;
    z.puntero=&y;c
    celda*ptCelda;
    ptCelda=&z;

    cout<<ptCelda->clave<<" "<<ptCelda->valor<<" "<<ptCelda->tamanio;


}
