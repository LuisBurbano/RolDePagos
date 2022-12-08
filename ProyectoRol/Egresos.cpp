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

#include "Egresos.h"
#include "Validacion.hpp"

Validacion validarEgresos;

// getters y setters
double Egresos::getIngresosTotales(void)
{
    return ingresosTotales;
}
void Egresos::setIngresosTotales(double newIngresosTotales)
{
    ingresosTotales = newIngresosTotales;
}
double Egresos::getAporteIESS(void)
{
    return aporteIESS;
}

void Egresos::setAporteIESS(double newAporteIESS)
{
    aporteIESS = newAporteIESS;
}

double Egresos::getImpuestoRenta(void)
{
    return impuestoRenta;
}


void Egresos::setImpuestoRenta(double newImpuestoRenta)
{
    impuestoRenta = newImpuestoRenta;
}


double Egresos::getMultas(void)
{
    return multas;
}


void Egresos::setMultas(double newMultas)
{
    multas = newMultas;
}


double Egresos::getAnticipoQuincena(void)
{
    return anticipoQuincena;
}

void Egresos::setAnticipoQuincena(double newAnticipoQuincena)
{
    anticipoQuincena = newAnticipoQuincena;
}


double Egresos::getTotalEgresos(void)
{
    return totalEgresos;
}


void Egresos::setTotalEgresos(double newTotalEgresos)
{
    totalEgresos = newTotalEgresos;
}


// metodos
double Egresos::calcularTotalEgresos(void)
{
    return aporteIESS + impuestoRenta + multas + anticipoQuincena;
}

double Egresos::calcularAporteIESS()
{
    double aporte = 0;
    aporte = this->getIngresosTotales() * 0.0945;
    return aporte;
}

double Egresos::calcularImpuestoRenta()
{
    double impuesto = 0;
    //5% de 0 a 942.5
    if (this->getIngresosTotales() > 942.04 && this->getIngresosTotales() <= 1200)
    {
        impuesto = this->getIngresosTotales() * 0.05;
    }
    //10% de 1200 a 1500
    else if (this->getIngresosTotales() > 1200 && this->getIngresosTotales() <= 1500)
    {
        impuesto = this->getIngresosTotales() * 0.1;
    }
    //12% de 1500 a 1802.5
    else if (this->getIngresosTotales() > 1500 && this->getIngresosTotales() <= 1802.5)
    {
        impuesto = this->getIngresosTotales() * 0.12;
    }
    //15% de 1802.5 a 2635.83
    else if (this->getIngresosTotales() > 1802.5 && this->getIngresosTotales() <= 2635.83)
    {
        impuesto = this->getIngresosTotales() * 0.15;
    }
    //20% de 2635.83 a 3469.17
    else if (this->getIngresosTotales() > 2635.83 && this->getIngresosTotales() <= 3469.17)
    {
        impuesto = this->getIngresosTotales() * 0.2;
    }
    //25% de 3469.17 a 4302.5
    else if (this->getIngresosTotales() > 3469.17 && this->getIngresosTotales() <= 4302.5)
    {
        impuesto = this->getIngresosTotales() * 0.25;
    }
    //30% de 4302 a 5135.83
    else if (this->getIngresosTotales() > 4302.5 && this->getIngresosTotales() <= 5135.83)
    {
        impuesto = this->getIngresosTotales() * 0.3;
    }
    //35% de 5135.83 a 8333.33
    else if (this->getIngresosTotales() > 5135.83 && this->getIngresosTotales() <= 8333.33)
    {
        impuesto = this->getIngresosTotales() * 0.35;
    }
    //37% de 8333.33 en adelante 
    else if (this->getIngresosTotales() > 8333.33)
    {
        impuesto = this->getIngresosTotales() * 0.37;
    }
    return impuesto;
}

double Egresos::calcularMultas()
{
    double multa = 0;
    int opcion = 0;
    double cantidadMultas;
    double valorMulta=0;
    do {
        cout << " \nEl trabajador tiene multas? 1. Si 2. No ";
        cin >> opcion;
        if (opcion == 1) {
            cout << " \nCuantas multas tiene? ";
            cantidadMultas = validarEgresos.charToInt();
            for (int i = 0; i < cantidadMultas; ) {
                cout << " \nIngrese el valor de la multa " << i + 1 << ": ";
                multa = validarEgresos.charToFloat();
                if (multa<=40)
                {
					valorMulta += multa;
                    i++;
                }else {
                    cout << "\n La multa no puede superar los 40$" << endl;
                }
            }

        }
        else {
            valorMulta = 0;
        }
        cout << " \nEl valor total de las multas es: " << multa << endl;
    } while (opcion != 1 && opcion != 2);
    return valorMulta;
}

double Egresos::calcularAnticipoQuincena()
{
    double anticipo = 0;
    int opcion = 0;
    double ingresos = 0;
    double anticipoMaximo = 0;
    ingresos = getIngresosTotales();
	anticipoMaximo = ingresos * 0.4;
    do {
        cout << " \nEl trabajador recibio anticipo de quincena? 1. Si 2. No ";
        opcion = validarEgresos.charToInt();
        if (opcion == 1) {
            cout << "\nIngrese el valor del anticipo de quincena: ";
            anticipo = validarEgresos.charToFloat();
            if (anticipo>anticipoMaximo)
            {
                opcion = 0;
                anticipo = 0;
            }
			
        }
        else {
            anticipo = 0;
        }
        cout << " \nEl valor del anticipo de quincena es: " << anticipo << endl;
    } while (opcion != 1 && opcion != 2);

    return anticipo;
}

void Egresos::ingresarDatos(double newIngresosTotales) {
    double ingresosTotales, aporteIESS, impuestoRenta, multas, anticipoQuincena, totalEgresos;
    ingresosTotales = newIngresosTotales;
    this->setIngresosTotales(ingresosTotales);
    aporteIESS = this->calcularAporteIESS();
    this->setAporteIESS(aporteIESS);
    impuestoRenta = this->calcularImpuestoRenta();
    this->setImpuestoRenta(impuestoRenta);
    multas = this->calcularMultas();
    this->setMultas(multas);
    anticipoQuincena = this->calcularAnticipoQuincena();
    this->setAnticipoQuincena(anticipoQuincena);
    totalEgresos = this->calcularTotalEgresos();
    this->setTotalEgresos(totalEgresos);


}
void Egresos::mostrarDatos() {
    double ingresosTotales, aporteIESS, impuestoRenta, multas, anticipoQuincena, totalEgresos;
    ingresosTotales = this->getIngresosTotales();
    aporteIESS = this->getAporteIESS();
    impuestoRenta = this->getImpuestoRenta();
    multas = this->getMultas();
    anticipoQuincena = this->getAnticipoQuincena();
    totalEgresos = this->getTotalEgresos();
    cout << "\nIngresos Totales: " << ingresosTotales;
    cout << "\nAporte IESS: " << aporteIESS;
    cout << "\nImpuesto Renta: " << impuestoRenta;
    cout << "\nMultas: " << multas;
    cout << "\nAnticipo Quincena: " << anticipoQuincena;
    cout << "\nTotal Egresos: " << totalEgresos;

}


Egresos::Egresos()
{
    // TODO : implement
}

std::string Egresos::toString() {    
    return validarEgresos.doubleToString(getAporteIESS()) + " " + validarEgresos.doubleToString(getAnticipoQuincena());
}


