#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
using namespace std;

template<typename T> struct PilaDinamica;
template<typename T> void crear(PilaDinamica<T>& l);
template<typename T> void push(PilaDinamica<T>& l, const T& e);
template<typename T> T pop(PilaDinamica<T>& l);
template<typename T> bool esVacia(const PilaDinamica<T>& l);
template<typename T> int tamanyo(const PilaDinamica<T>& l);
template<typename T> void liberar(PilaDinamica<T>& l);
template<typename T> bool existe(const PilaDinamica<T>& l);



template<typename T>
struct PilaDinamica {

    friend void crear<T>(PilaDinamica<T>& l);
    friend void push<T>(PilaDinamica<T>& l, const T& e);
    friend T pop<T>(PilaDinamica<T>& l);
    friend bool esVacia<T>(const PilaDinamica<T>& l);
    friend int tamanyo<T>(const PilaDinamica<T>& l);
    friend void liberar<T>(PilaDinamica<T>& l);
    friend bool existe<T>(const PilaDinamica<T>& l);




private:

    struct Nodo {

        T valor;
        Nodo* siguiente;

    };


    Nodo* elPrimero ;
    int numDatos;

};

template<typename T>
void crear (PilaDinamica<T>& l){

    l.elPrimero = nullptr;
    l.numDatos = 0;
}
template<typename T>
void push (PilaDinamica<T>& l, const T& e){
    typename PilaDinamica<T>::Nodo *pAux;

    pAux = l.elPrimero;
    l.elPrimero = new typename PilaDinamica<T>::Nodo;
    l.elPrimero->valor = e;
    l.elPrimero->siguiente = pAux;
    l.numDatos++;

}
template<typename T>
T pop(PilaDinamica<T>& l){//devuelve el dato eliminado
    typename PilaDinamica<T>::Nodo *pAux;
    T aux;
    if(l.numDatos !=0){


        pAux = l.elPrimero;
        aux = pAux->valor;
        l.elPrimero = pAux->siguiente;
        pAux = nullptr;
        l.numDatos--;

    }

    return  aux;

}
template<typename T>
bool esVacia(const PilaDinamica<T>& l){

    return l.numDatos == 0;

}
template<typename T>
int tamanyo(const PilaDinamica<T>& l){

    return l.numDatos;

}
template<typename T>
void liberar(PilaDinamica<T>& l){

    typename PilaDinamica<T>::Nodo *pAux;
    pAux = l.elPrimero;

    while(pAux != nullptr){

        l.elPrimero = l.elPrimero->siguiente;
        pAux = nullptr;
        pAux = l.elPrimero;

    }

    l.numDatos = 0;

}
template<typename T>

bool existe(const PilaDinamica<T>& l){

    return l.elPrimero->siguiente != nullptr;


}


#endif // PILA_H_INCLUDED
