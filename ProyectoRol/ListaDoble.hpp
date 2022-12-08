/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
        INGENIERA DE SOFTWARE

    AUTORES:
        Mateo Javier Condor Sosa
        Luis Ariel Burbano Pacheco
    FECHA DE CREACION:
        21/11/2022
    FECHA DE MODIFICACION:
        29/11/2022
*/
#pragma once
#include <iostream>
#include "Nodo.hpp"
#include "Funciones.h"

using namespace std;

template <typename T>
class ListaDoble : public Funciones {
private:
    Nodo<T>* inicio = nullptr;
    Nodo<T>* fin = nullptr;
    int tam = 0;

public:

    void insertarPorInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            inicio->setAnterior(nuevo);
            nuevo->setSiguiente(inicio);
            inicio = nuevo;
        }
        tam++;
    }

    void insertarPorFin(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            fin->setSiguiente(nuevo);
            nuevo->setAnterior(fin);
            fin = nuevo;
        }
        tam++;
    }

    void insertarPorPosicion(T dato, int pos) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        Nodo<T>* aux = inicio;
        int cont = 1;
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else if (pos == 0) {
            insertarPorInicio(dato);
        }
        else if (pos == tam) {
            insertarPorFin(dato);
        }
        else {
            while (aux) {
                if (cont == pos) {
                    aux->getAnterior()->setSiguiente(nuevo);
                    nuevo->setAnterior(aux->getAnterior());
                    aux->setAnterior(nuevo);
                    nuevo->setSiguiente(aux);
                    break;
                }
                aux = aux->getSiguiente();
                cont++;
            }
            tam++;
        }
    }

    void eliminarPorInicio() {
        if (inicio == NULL) {
            cout << "\tLista vacia" << endl;
        }
        else {
            inicio = inicio->getSiguiente(); // talvez aqui se da el error de crashear
            inicio->setAnterior(nullptr);
            cout << "\n\tDato eliminado" << endl;
        }
        tam--;
    }

    void eliminarPorFin() {
        if (inicio == NULL) {
            cout << "Lista vacia" << endl;
        }
        else {
            fin = fin->getAnterior();
            fin->setSiguiente(nullptr);
            cout << "\n\tDato eliminado" << endl;
        }
        tam--;
    }

    void eliminarPorPosicion(int pos) { //
        Nodo<T>* aux = inicio;
        int cont = 0;
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else if (pos == 0) {
            eliminarPorInicio();
        }
        else if (pos == tam) {
            eliminarPorFin();
        }
        else if (pos > 0 && pos < tam - 1) {
            while (aux) {
                if (cont == pos) {
                    aux->getAnterior()->setSiguiente(aux->getSiguiente());
                    aux->getSiguiente()->setAnterior(aux->getAnterior());
                    break;
                }
                aux = aux->getSiguiente();
                cont++;
            }
            tam--;
        }
        else {
            cout << "\n\tPosicion no valida" << endl;
        }
    }

    void buscar(T dato) {
        Nodo<T>* aux = inicio;
        int cont = 1;
        bool encontrado = false;
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else {
            while (aux) {
                if (aux->getDato() == dato) {
                    encontrado = true;
                    break;
                }
                else {
                    encontrado = false;
                }
                aux = aux->getSiguiente();
                cont++;
            }
            if (encontrado == true) {
                cout << "\nEl dato " << dato << " se encuentra en la posicion " << cont + 1 << endl;
            }
            else {
                cout << "\nEl dato " << dato << " no se encuentra en la lista" << endl;
            }
        }
    }

    bool mostrar() {
        bool vacio = false;
        Nodo<T>* aux = inicio;
        if (inicio != NULL) {
            while (aux) {
                cout << aux->getDato() << " -> <- \n";
                aux = aux->getSiguiente();
            }
            cout << "NULL" << endl;
        }
        else {
            cout << "\n\tLista vacia" << endl;
            vacio = true;
            return vacio;
        }
        //cout <<"La lista tiene "<< tam <<" elementos "<< endl;
    }

    int calcularMCD(int a, int b) {
        if (a == 0) {
            return b;
        }
        else if (b == 0) {
            return a;
        }
        else if (a == b) {
            return a;
            //return calcularMCD(b, a%b);
        }
        else if (a > b) {
            return calcularMCD(a - b, b);
        }
        return calcularMCD(a, b - a);
    }

    int calcularMCM(int a, int b) {
        return (a * b) / calcularMCD(a, b);
    }

    void mcmmcdDeLista() {
        Nodo<T>* aux = inicio;
        int mcm = 0;
        int mcd = 0;
        int a = 0;
        int b = 0;
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else if (inicio->getSiguiente() == NULL) {
            cout << "\n\tSolo hay un elemento en la lista" << endl;
            cout << "\n\tSe necesitan minimo 2 elementos" << endl;
        }
        else if (inicio != NULL) {
            a = aux->getDato();
            b = aux->getSiguiente()->getDato();
            mcm = calcularMCM(a, b);
            mcd = calcularMCD(a, b);
            while (aux->getSiguiente() != NULL) {
                aux = aux->getSiguiente();
                mcm = calcularMCM(mcm, aux->getDato());
                mcd = calcularMCD(mcd, aux->getDato());
            }
            cout << "\n\t~El MCM: " << mcm << endl;
            cout << "\n\t~El MCD: " << mcd << endl;
        }
    }


};