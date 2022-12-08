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

#if !defined(__ProyectoUnidad1_Egresos_h)
#define __ProyectoUnidad1_Egresos_h
#include <iostream>
class Egresos
{
public:
	

	// getters y setters
	double getIngresosTotales(void);
	void setIngresosTotales(double newIngresosTotales);
	double getAporteIESS(void);
	void setAporteIESS(double newAporteIESS);
	double getImpuestoRenta(void);
	void setImpuestoRenta(double newImpuestoRenta);
	double getMultas(void);
	void setMultas(double newMultas);
	double getAnticipoQuincena(void);
	void setAnticipoQuincena(double newAnticipoQuincena);
	double getTotalEgresos(void);
	void setTotalEgresos(double newTotalEgresos);

	//metodos
	double calcularTotalEgresos();
	double calcularAporteIESS();
	double calcularImpuestoRenta();
	double calcularMultas();
	double calcularAnticipoQuincena();
	void ingresarDatos(double);
	void mostrarDatos(void);
	Egresos();

	std::string toString();


protected:
private:
	double ingresosTotales;
	double aporteIESS;
	double impuestoRenta;
	double multas;
	double anticipoQuincena;
	double totalEgresos;

};

#endif