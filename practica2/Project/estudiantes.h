#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED
#include "unizar.h"
#include <iostream>
using namespace std;
const int MAX=40;
/* Jorge aclaraciones:
    //? = están medio hechas pero probablemente haya algo mal
    // = están creo acabadas
    //-- = no están empezadas
*/
template<typename V> struct estudiantes;
template<typename V> void crear(estudiantes<V>& est);//
template<typename V> int cardinal(const estudiantes<V>& est);//
template<typename V> bool esVacia(const estudiantes<V>& est);//
template<typename V> bool pertenece(const estudiantes<V>& est, const string c);//
template<typename V> bool obtenerValor(const estudiantes<V>& est, const string c, V& v);//?
template<typename V> bool enMatricula(const estudiantes<V>& est);//?
template<typename V> bool anyadir(estudiantes<V>& est, const string c, const V& v);//
template<typename V> bool quitar(estudiantes<V>& est, const string c);//?
template<typename V> void cerrarInscripcion(estudiantes<V>& est);//--
template<typename V> int pasarTurno(estudiantes<V>& est);//?
template<typename V> int obtenerCandidatoSuClave(const estudiantes<V>& est, string& c);//
template<typename V> int obtenerCandidatoSuValor(const estudiantes<V>& est, V& v);//?
template<typename V> int actualizarCandidato(estudiantes<V>& est, const V& v);//?
template<typename V> int eliminarCandidato(estudiantes<V>& est);//?
template<typename V> void listar(estudiantes<V>& est);//--
template<typename V> void iniciarIterador(estudiantes<V>& est);//
template<typename V> bool existeSiguiente(const estudiantes<V>& est);//
template<typename V> bool siguienteClaveValor(estudiantes<V>& est, string& c, V& v);//
template<typename V> bool avanza(estudiantes<V>& est);//?

template<typename V>
struct estudiantes{
    friend void crear<V>(estudiantes<V>& est);

    friend int cardinal<V>(const estudiantes<V>& est);

    friend bool esVacia<V>(const estudiantes<V>& est);

    friend bool pertenece<V>(const estudiantes<V>& est, const string c);

    friend bool obtenerValor<V>(const estudiantes<V>& est, const string c, V& v);

    friend bool enMatricula<V>(const estudiantes<V>& est);

    friend bool anyadir<V>(estudiantes<V>& est, const string c, const V& v);

    friend bool quitar<V>(estudiantes<V>& est, const string c);

    friend void cerrarInscripcion<V>(estudiantes<V>& est);

    friend int pasarTurno<V>(estudiantes<V>& est);

    friend int obtenerCandidatoSuClave<V>(const estudiantes<V>& est, string& c);//

    friend int obtenerCandidatoSuValor<V>(const estudiantes<V>& est, V& v);//

    friend int actualizarCandidato<V>(estudiantes<V>& est, const V& v);

    friend int eliminarCandidato<V>(estudiantes<V>& est);

    friend void listar<V>(estudiantes<V>& est);

    friend void iniciarIterador<V>(estudiantes<V>& est);

    friend bool existeSiguiente<V>(const estudiantes<V>& est);

    friend bool siguienteClaveValor<V>(estudiantes<V>& est, string& c, V& v);

    friend bool avanza<V>(estudiantes<V>& est);

private:
    struct Celda{
        string clave;
        V valor;// valor que tipo de valor tiene que ser
        Celda *sig;

    };
	Celda *pri;
	int numEstudiantes;
	Celda *iter;
	Celda *candidato;//tendria que ser el puntero de la matriculación
	bool inscripcion;
	int turno;
};

template<typename V> void crear(estudiantes<V>& est){//inicializa estudiantes


    est.inscripcion=true;
    est.pri = nullptr;
    est.candidato = nullptr;
    est.numEstudiantes = 0;
    est.turno = 0;
}

template<typename V> int cardinal(const estudiantes<V>& est ){//devuelve el tamaño del diccionario

    return est.numEstudiantes;
}

template<typename V> bool esVacia(const estudiantes<V>& est){

    return est.numEstudiantes == 0;
}

template<typename V> bool pertenece(const estudiantes<V>& est,const string c){
    typename estudiantes<V>::Celda *pAux;
    pAux=est.pri;

    while(pAux != nullptr and c>pAux->clave){

        pAux = pAux->sig;

    }
    if(pAux==nullptr){
        return false;
    }else{
        if(pAux->clave==c){
            return true;
        }else{
            return false;
        }

    }

}

template<typename V> bool obtenerValor(const estudiantes<V>& est, const string c, V& v){
    typename estudiantes<V>::Celda *pAux;
    pAux=est.pri;
    while(pAux != nullptr){
        if(pAux->clave == c){
            v=pAux->valor;
            return true;
        }
        pAux = pAux->sig->sig;
    }
     return false;
}

template<typename V> bool enMatricula(const estudiantes<V>& est){//??

    return !est.inscripcion;

}
template<typename V> bool anyadir(estudiantes<V>& est, const string c, const V& v){
    if (enMatricula(est)){
        return false;
    }
    typename estudiantes<V>::Celda*nodo;
    typename estudiantes<V>::Celda*pAux;


    if (est.pri == nullptr) {

        est.pri = new typename estudiantes<V>::Celda;
        est.pri->clave = c;
        est.pri->valor = v;
        est.pri->sig = nullptr;
        est.numEstudiantes++;
        est.candidato=est.pri;


    } else if (c < est.pri->clave ) {

        pAux = est.pri;
        est.pri = new typename estudiantes<V>::Celda;
        est.pri->clave = c;
        est.pri->valor = v;
        est.pri->sig = pAux;
        est.numEstudiantes++;

    }else if (c == est.pri->clave){
        est.pri->valor = v;
    }else {
         pAux = est.pri;
         while (pAux->sig != nullptr && c > pAux->sig->clave){
            pAux = pAux->sig;
         }
         if (pAux->sig != nullptr && c == pAux->sig->clave){
                pAux->sig->valor = v;
         }else{
             nodo = new typename estudiantes<V>::Celda;
             nodo->clave = c;
             nodo->valor = v;
             nodo->sig = pAux->sig;
             pAux->sig = nodo;
             est.numEstudiantes++;
        }
    }

    return true;
}

template<typename V> bool quitar(estudiantes<V>& est, const string c){
    typename estudiantes<V>::Celda* pAux;
    pAux=est.pri;

    while(pAux->sig!=nullptr && c>=pAux->clave){
        if(c==est.pri->clave){

            est.pri=est.pri->sig;
            est.candidato=est.pri;
            est.numEstudiantes--;
            return true;

        }else if(c==pAux->sig->clave){

            pAux->sig=pAux->sig->sig;
            est.numEstudiantes--;
            return true;
        }
        pAux=pAux->sig;
    }
    return false;
 }
template<typename V> void cerrarInscripcion(estudiantes<V>& est){
    if(!enMatricula(est) && !esVacia(est)){

        est.candidato=est.pri;
        est.inscripcion=false;

    }

}

template<typename V> int pasarTurno(estudiantes<V>& est){

    if(!enMatricula(est) && existeSiguiente(est)){
        if(est.candidato->sig==nullptr ){
            est.candidato=est.pri;
            est.turno=1;

        }else{
            est.candidato=est.candidato->sig;
            est.turno++;
        }

    }
    return est.turno;
}

template<typename V> int obtenerCandidatoSuClave(const estudiantes<V>& est,string& c){

    if(enMatricula(est)){
        c=est.candidato->clave;

    }
    return est.turno;
 }

template<typename V> int obtenerCandidatoSuValor(const estudiantes<V>& est,V& v){

    if(enMatricula(est)){
        v=est.candidato->valor;

    }
    return est.turno;
 }
template<typename V> int actualizarCandidato(estudiantes<V>& est, const V& v){
    if(enMatricula(est) && !esVacia(est)){
        est.candidato->valor = v;

    }
    return est.turno;
}

template<typename V> int eliminarCandidato(estudiantes<V>& est){
    if(!enMatricula(est)){
        quitar(est.candidato->clave);
        pasarTurno(est);
    }
    return est;
}

template<typename V> void listar(estudiantes<V>& est){
    iniciarIterador(est);
    while(existeSiguiente(est)){
        cout<<"TOTAL DE ESTUDIANTES: "<<est.numEstudiantes<<endl
        <<"NIP: "<<est.iter->clave<<endl
        <<generaCadena(est.iter->valor)
        <<endl<<"---------------"<<endl;
        avanza(est);
    }
}

 template<typename V> void iniciarIterador(estudiantes<V>& est){
    est.iter = est.pri;
 }

 template<typename V> bool existeSiguiente(const estudiantes<V>& est){
    return est.iter != nullptr;
 }

template<typename V> bool siguienteClaveValor(estudiantes<V>& est, string& c, V& v){

   if(existeSiguiente(est)){
        c = est.iter->clave;
        v = est.iter->valor;
        return true;
   }
   return false;
}

template<typename V> bool avanza(estudiantes<V>& est){

    if(existeSiguiente(est)){
        est.iter=est.iter->sig;

        return true;
    }
    return false;
}
#endif // ESTUDIANTES_H_INCLUDED
