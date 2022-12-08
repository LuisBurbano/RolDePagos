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

#include <iostream>

class Funciones {
	int tam = 0;
public:
	virtual int calcularMCM(int a, int b) = 0;
	virtual int calcularMCD(int a, int b) = 0;

};