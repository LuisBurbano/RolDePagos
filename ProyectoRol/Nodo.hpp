/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
        INGENIERA DE SOFTWARE

    AUTORES:
        Mateo Javier Condor Sosa
        Luis Ariel Burbano Pacheco
    FECHA DE CREACION:
        21/11/2022
    FECHA DE MODIFICACION:
        22/11/2022
*/
#pragma once
#include <iostream>

using namespace std;
template <typename T>

class Nodo {
private:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

public:

    Nodo(T dato) {
        this->dato = dato;
        this->siguiente = nullptr;
        this->anterior = nullptr;
    }

    ~Nodo() {

    }


    void setDato(T dato) {
        this->dato = dato;
    }

    void setSiguiente(Nodo* sig) {
        this->siguiente = sig;
    }

    void setAnterior(Nodo* ant) {
        this->anterior = ant;
    }

    T getDato() {
        return this->dato;
    }

    Nodo* getSiguiente() {
        return this->siguiente;
    }

    Nodo* getAnterior() {
        return this->anterior;
    }

};