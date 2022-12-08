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

#include "RolDePagos.h"

#include "ListaDoble.hpp"
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>




double RolDePagos::getSalario(void)
{
    return sueldo;
}

void RolDePagos::setSalario(double newSalario)
{
    sueldo = newSalario;
}


void RolDePagos::imprimirRol(Trabajador* newTrabajador, Ingresos* newIngresos, Egresos* newEgresos)
{
    newTrabajador->mostrarDatos();
    newIngresos->mostrarDatos();
    newEgresos->mostrarDatos();
    cout << "\nSueldo Neto: " << newIngresos->getTotalIngresos() - newEgresos->getTotalEgresos() << endl;
}
Trabajador* RolDePagos::generarTrabajador()
{

    cout << "Ingrese los datos del trabajador" << endl;
    Trabajador* trabajador;
    trabajador = new Trabajador();
    trabajador->ingresarDatos();
    return trabajador;
	delete trabajador;
}

Ingresos* RolDePagos::generarIngresos()
{
    cout << "Ingrese los datos de los ingresos" << endl;
    Ingresos* ingresos;
    ingresos = new Ingresos();
    ingresos->ingresarDatos();
    return ingresos;
	delete ingresos;
}


Egresos* RolDePagos::generarEgresos(double totalIngresos)
{

    Egresos* egresos;
    egresos = new Egresos();
    egresos->ingresarDatos(totalIngresos);
    return egresos;
	delete egresos;
}


RolDePagos::RolDePagos()
{
	this->trabajador = new Trabajador();
	this->ingresos = new Ingresos();
	this->egresos = new Egresos();
	this->sueldo = 0;
}


string RolDePagos::toString(Trabajador *trabajador, Ingresos *ingresos, Egresos *egresos)
{
    double egresosTotales;
    double ingresosTotales;
    double sueldo;
	egresosTotales = egresos->getTotalEgresos();
	ingresosTotales = ingresos->getTotalIngresos();
	sueldo = ingresosTotales- egresosTotales;
    std:string texto = trabajador->toString() + " " + ingresos->toString() + " " + egresos->toString() + " " + validacion.doubleToString(sueldo);
    return texto;
}


void RolDePagos::guardarArchivoTxt(string a)
{
    ofstream archivo;
    archivo.open("RolDePagos.txt", ios::app);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    archivo << "\n"+ a;
    archivo.close();
}

void RolDePagos::verRolesDePago()
{
    string line;
    string lectura;
    lectura = validacion.leerArchivoTxt();
    stringstream input_stringstream(lectura);
    cout << "Trabajador                 Telefono  Cargo Ingresos  IESS  Anticipo  Sueldo Neto" << endl;   
    cout << "===========================================================================" << endl;
    while (getline(input_stringstream, line, '\n'))
    {
        cout << line << endl;
    }
    cout << "===========================================================================" << endl;
}


void RolDePagos::verRolesDePagoEnLista()
{
    ListaDoble<string> lista;
    string line;
    string lectura;
    string aux[100];
    int i = 0;
    lectura = validacion.leerArchivoTxt();
    stringstream input_stringstream(lectura);
    while (getline(input_stringstream, line, '\n'))
    {
        aux[i] = line;
        lista.insertarPorFin(aux[i]);
        i++;
    }
    lista.mostrar();
}



void RolDePagos::buscarRolDePagos()
{

    int opcion2;

    string datoBuscar;
    string rol;
    do
    {
        system("cls");
        cout << "\nBuscar rol de pagos por:" << endl;
        cout << "1. Cedula" << endl;
        cout << "2. Nombre" << endl;
        cout << "3. Apellido" << endl;
        cout << "4. Regresar" << endl;
        cout << "Ingrese una opcion: ";
        opcion2 = validacion.charToInt();
        switch (opcion2)
        {
        case 1:
            cout << "\nIngrese la cedula: ";
            datoBuscar = validacion.ingresoCedula("> ");
            cout << "\n";
            cout << "Trabajador              Ingresos   Egresos   Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            cout << rol << endl;
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 2:
            cout << "\nIngrese el nombre: ";
            datoBuscar = validacion.ingresoNombreApellido("> ");
            cout << "\n";
            cout << "Trabajador              Ingresos   Egresos   Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            cout << rol << endl;
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 3:
            cout << "\nIngrese el apellido: ";
            datoBuscar = validacion.ingresoNombreApellido("> ");
            cout << "\n";
            cout << "Trabajador              Ingresos   Egresos   Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            cout << rol << endl;
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 4:
            break;
        }

    } while (opcion2 != 4);
    
}

void RolDePagos::borrarRolDePagos()
{
    int opcion3;

    string datoBuscar;
    string rol;
    do
    {
        system("cls");
        cout << "\nBuscar rol de pagos por:" << endl;
        cout << "1. Cedula" << endl;        
        cout << "2. Apellido" << endl;
        cout << "3. Regresar" << endl;
        cout << "Ingrese una opcion: ";
        opcion3 = validacion.charToInt();
        switch (opcion3)
        {
        case 1:
            cout << "\nIngrese la cedula: ";
            datoBuscar = validacion.ingresoCedula("> ");
            cout << "\n";
            cout << "Trabajador                 Telefono  Cargo Ingresos  IESS  Anticipo  Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            if (rol!= "NO SE ENCONTRO")
            {
                validacion.borrarEnLista(rol);
            }
            
            cout << rol << endl;
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 2:
            cout << "\nIngrese el apellido: ";
            datoBuscar = validacion.charImput("> ");
            cout << "\n";
            cout << "Trabajador                 Telefono  Cargo Ingresos  IESS  Anticipo  Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            if (rol != "NO SE ENCONTRO")
            {
                validacion.borrarEnLista(rol);
            }
            cout << rol << endl;
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 3:
            
            cout << "ESTA SALIENDO"<<endl;
            break;
        }

    } while (opcion3 != 3);
    
}

void RolDePagos::modificarRolDePagos()
{
    int opcion3;
	Trabajador* trabajador = new Trabajador();
    Ingresos* ingresos = new Ingresos();
	Egresos* egresos = new Egresos();
    string datoBuscar;
    string rol;
    do
    {
        system("cls");
        cout << "\nBuscar rol de pagos por:" << endl;
        cout << "1. Cedula" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Regresar" << endl;
        cout << "Ingrese una opcion: ";
        opcion3 = validacion.charToInt();
        switch (opcion3)
        {
        case 1:
            cout << "\nIngrese la cedula: ";
            datoBuscar = validacion.ingresoCedula("> ");
            cout << "\n";
            cout << "Trabajador                 Telefono  Cargo Ingresos  IESS  Anticipo  Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            cout << rol << endl;
            if (rol != "NO SE ENCONTRO")
            {
                trabajador->ingresarDatos();
                ingresos->ingresarDatos();
                egresos->ingresarDatos(ingresos->getTotalIngresos());
                egresos->mostrarDatos();
                validacion.modificarEnLista(rol, this->toString(trabajador, ingresos, egresos));
            }

            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 2:
            cout << "\nIngrese el apellido: ";
            datoBuscar = validacion.charImput("> ");
            cout << "\n";
            cout << "Trabajador                 Telefono  Cargo Ingresos  IESS  Anticipo  Sueldo Neto" << endl;
            cout << "===========================================================================" << endl;
            rol = validacion.buscarEnLista(datoBuscar);
            cout << rol << endl;
            if (rol != "NO SE ENCONTRO")
            {
                trabajador->ingresarDatos();
                ingresos->ingresarDatos();
                egresos->ingresarDatos(ingresos->getTotalIngresos());
                egresos->mostrarDatos();
                validacion.modificarEnLista(rol, this->toString(trabajador, ingresos, egresos));
            }
            cout << "===========================================================================" << endl;
            system("pause");
            break;
        case 3:

            cout << "ESTA SALIENDO" << endl;
            break;
        }

    } while (opcion3 != 3);
	delete trabajador;
	delete ingresos;
	delete egresos;
}
