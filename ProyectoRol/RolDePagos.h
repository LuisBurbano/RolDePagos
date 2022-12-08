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

#if !defined(__ProyectoUnidad1_RolDePagos_h)
#define __ProyectoUnidad1_RolDePagos_h

#include "Ingresos.h"
#include "Egresos.h"
#include "Trabajador.h"
#include "Validacion.hpp"
#include <iostream>
//
//class Ingresos;
//class Egresos;
//class Trabajador;
class RolDePagos
{
public:

	Ingresos* getIngresos(void);
	void setIngresos(Ingresos* newIngresos);
	Egresos* getEgresos(void);
	void setEgresos(Egresos* newEgresos);
	Trabajador* getTrabajador(void);
	void setTrabajador(Trabajador* newTrabajador);
	RolDePagos* getRolDePagos(void);
	void setRolDePagos(RolDePagos* newRolDePagos);
	double getSalario(void);
	void setSalario(double newSalario);

	void imprimirRol(Trabajador*, Ingresos*, Egresos*);
	Trabajador* generarTrabajador();
	Ingresos* generarIngresos();
	Egresos* generarEgresos(double);

	RolDePagos();
	void menuRolDePagos();
	std::string toString(Trabajador *trabajador, Ingresos *ingresos, Egresos *egresos);
	void guardarArchivoTxt(std::string a);

	void verRolesDePago();
	void generarRolDePagos();
	void buscarRolDePagos();
	void borrarRolDePagos();
	void verRolesDePagoEnLista();
	void modificarRolDePagos();
	Validacion validacion;
protected:
private:
	Ingresos* ingresos;
	Egresos* egresos;
	Trabajador* trabajador;
	double sueldo;
};

#endif