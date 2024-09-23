#ifndef CONCIERTOS_H_INCLUDED
#define CONCIERTOS_H_INCLUDED
#include "pila.h"
#include <sstream>
#include<iostream>
#include <iomanip>
using namespace std;

template<typename K, typename V> struct conciertos;
template<typename K, typename V> void crear(conciertos<K,V>& c);
template<typename K, typename V> bool esVacio(const conciertos<K,V>& c);
template<typename K, typename V> bool existeClave(const conciertos<K,V>& c, const K& k);
template<typename K, typename V> void insertar(conciertos<K,V>& c, const K& k, const V& v);
template<typename K, typename V> bool obtenerDato(const conciertos<K,V>& c, const K& k, V& v);
template<typename K, typename V> void borrar(conciertos<K,V>& c, const K& k);
template<typename K, typename V> int tamanyo(const conciertos<K,V>& c);
template<typename K, typename V> void vaciar(conciertos<K,V>& c);
template<typename K, typename V> string listar(conciertos<K,V>& c);
template<typename K, typename V> void iniciarIterador(conciertos<K,V>& c);
template<typename K, typename V> bool existeSiguiente(const conciertos<K,V>& c);
template<typename K, typename V> bool siguiente(conciertos<K,V>& c, K& k, V& v);
template<typename K, typename V> bool avanza(conciertos<K,V>& c);
template<typename K, typename V> bool mayorClave(conciertos<K,V>& c, K& mayor);

/**OPERACIONES INTERNAS*/

template<typename K,typename V> void insertarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, const V& v, bool& metido);
template<typename K, typename V> typename conciertos<K,V>::NodoBinario* buscarNodo(typename conciertos<K,V>::NodoBinario* nodo, const K& k);
template<typename K, typename V> void borrarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, bool& borrado);
template<typename K, typename V> void BorrarMaximo(typename conciertos<K,V>::NodoBinario* nodo, K& k, V& v);
template<typename K, typename V> void vaciarRec(typename conciertos<K,V>::NodoBinario*& nodo);

template<typename K,typename V>
struct conciertos {

    friend void crear<K,V>(conciertos<K,V>& c);
    friend bool esVacio<K,V>(const conciertos<K,V>& c);
    friend bool existeClave<K,V>(const conciertos<K,V>& c, const K& k);
    friend void insertar<K,V>(conciertos<K,V>& c, const K& k, const V& v);
    friend bool obtenerDato<K,V>(const conciertos<K,V>& c, const K& k, V& v);
    friend void borrar<K,V>(conciertos<K,V>& c, const K& k);
    friend int tamanyo<K,V>(const conciertos<K,V>& c);
    friend void vaciar<K,V>(conciertos<K,V>& c);
    friend string listar<K,V>(conciertos<K,V>& c);
    friend void iniciarIterador<K,V>(conciertos<K,V>& c);
    friend bool existeSiguiente<K,V>(const conciertos<K,V>& c);
    friend bool avanza<K,V>(conciertos<K,V>& c);
    friend bool siguiente<K,V>(conciertos<K,V>& c, K& k, V& v);
    friend bool mayorClave<K,V>(conciertos<K,V>& c, K& mayor);

private:

     struct NodoBinario {
        K clave;
        V valor;
        NodoBinario* izqda;
        NodoBinario* drcha;
     };
         NodoBinario* raiz ;
         PilaDinamica<NodoBinario*> iter;
         int numDatos;

/*OPERACIONES INTERNAS*/

    friend void insertarRec<K,V>(NodoBinario*& nodo, const K& k, const V& v, bool& metido);
    friend typename conciertos<K,V>::NodoBinario* buscarNodo<K,V>(NodoBinario* nodo, const K& k);
    friend void borrarRec<K,V>(NodoBinario*& nodo, const K& k, bool& borrado);
    friend void BorrarMaximo<K,V>(NodoBinario* nodo, K& k, V& v);
    friend void vaciarRec<K,V>(NodoBinario*& nodo);

};

template<typename K,typename V>void crear(conciertos<K,V>& c){

        c.raiz = nullptr;
        c.numDatos = 0;

}

template<typename K,typename V>bool esVacio(const conciertos<K,V>& c){

        return c.numDatos == 0;
}

template<typename K,typename V>bool existeClave(const conciertos<K,V>& c, const K& k){

    if(buscarNodo<K,V>(c.raiz,k) == nullptr){

        return false;

    }else return true;

}


template<typename K,typename V>void insertar(conciertos<K,V>& c, const K& k, const V& v){

        bool metido = false;
        insertarRec<K,V>(c.raiz,k,v,metido);

        if(metido){

            c.numDatos++;

        }
     }

template<typename K,typename V>bool obtenerDato(const conciertos<K,V>& c, const K& k, V& v){

        typename conciertos<K,V>::NodoBinario* pAux;

        if(existeClave<K,V>(c,k)){

            pAux = buscarNodo<K,V>(c.raiz,k);
            v = pAux->valor;

            return true;

        }else return false;

}

template<typename K, typename V> void borrar(conciertos<K,V>& c, const K& k){

    bool borrado = false;
    borrarRec<K,V>(c.raiz,k,borrado);

    if(borrado){

        c.numDatos--;
    }


}

template<typename K, typename V> int tamanyo(const conciertos<K,V>& c){

    return c.numDatos;

}

template<typename K, typename V> void vaciar(conciertos<K,V>& c){

    vaciarRec<K,V>(c.raiz);
    c.numDatos = 0;
    c.raiz = nullptr;

}

template<typename K, typename V> string listar(conciertos<K,V>& c){
    K codigo;
    V valor;
    ostringstream listaArbol;
    iniciarIterador(c);


    while(existeSiguiente(c)){

        siguiente<K,V>(c,codigo,valor);
        listaArbol << "Clave: " << codigo << endl
        << hacerCadena(valor) << endl <<"------------" << endl;

    }

    return listaArbol.str();
}
//Iterador
template<typename K,typename V> void iniciarIterador(conciertos<K,V>& c){
        typename conciertos<K,V>::NodoBinario *pAux;

        crear(c.iter);
        pAux = c.raiz;
        while (pAux != nullptr){
            push(c.iter,pAux);
            pAux = pAux->izqda;
        }

    }


template<typename K,typename V> bool existeSiguiente(const conciertos<K,V>& c){

        return !esVacia(c.iter);
}

template<typename K,typename V> bool siguiente(conciertos<K,V>& c, K& k, V& v){

        typename conciertos<K,V>::NodoBinario *pAux;
        typename conciertos<K,V>::NodoBinario *pAux2;

        if(existeSiguiente(c)){

            pAux = pop(c.iter);
            k = pAux->clave;
            v = pAux->valor;
            pAux = pAux->drcha;


            while (pAux != nullptr){
                push(c.iter,pAux);
                pAux = pAux->izqda;

            }
            return true;
        }else{
            return false;
        }
    }


/*OPERACIONES INTERNAS*/
template<typename K,typename V> void insertarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k,const V& v,bool& metido){

    if(nodo == nullptr){

        nodo = new typename conciertos<K,V>::NodoBinario;

        nodo->clave = k;
        nodo->valor = v;
        nodo->izqda = nullptr;
        nodo->drcha = nullptr;
        metido = true;


    }else if(k == nodo->clave) {

        nodo->valor = v;
        metido = false;

    }else if (k <= nodo->clave){

        insertarRec<K,V>(nodo->izqda,k,v,metido);

    }else{

        insertarRec<K,V>(nodo->drcha,k,v,metido);

    }

    }

template<typename K,typename V> typename conciertos<K,V>::NodoBinario* buscarNodo(typename conciertos<K,V>::NodoBinario* nodo, const K& k){

    if(nodo == nullptr){

            return nullptr;

    }else{
        if(k < nodo->clave){

           return buscarNodo<K,V>(nodo->izqda,k);

        }else if(k > nodo->clave){

           return buscarNodo<K,V>(nodo->drcha,k);

        }
        if(k == nodo->clave){

            return nodo;

        }
    }

}

template<typename K,typename V> void borrarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, bool& borrado){

    typename conciertos<K,V>::NodoBinario* pAux;

    if(nodo == nullptr){

        borrado = false;

    }else{

        if(k < nodo->clave){

            borrarRec<K,V>(nodo->izqda,k,borrado);

        }else if(k > nodo->clave){

           borrarRec<K,V>(nodo->drcha,k,borrado);

        }
        if(k == nodo->clave){

            if(nodo->izqda == nullptr){

                pAux = nodo;
                nodo = nodo->drcha;
                pAux = nullptr;

            }else {

                BorrarMaximo(nodo->izqda,nodo->clave,nodo->valor);

            }

        }
    }

}

template<typename K,typename V> void BorrarMaximo(typename conciertos<K,V>::NodoBinario* nodo, K& k, V& v){

    typename conciertos<K,V>::NodoBinario* pAux;

    if(nodo->drcha == nullptr){

        k = nodo->clave;
        v = nodo->valor;
        pAux = nodo;
        nodo = nodo->izqda;
        pAux = nullptr;


    }else{

        BorrarMaximo<K,V>(nodo->drcha,k,v);
    }
}

template<typename K, typename V> void vaciarRec(typename conciertos<K,V>::NodoBinario*& nodo){

    vaciarRec<K,V>(nodo.raiz->izqda);
    vaciarRec<K,V>(nodo.raiz->drcha);
    nodo.raiz = nullptr;

}


#endif // CONCIERTOS_H_INCLUDED
