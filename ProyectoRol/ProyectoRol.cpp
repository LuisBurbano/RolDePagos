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
#include "Validacion.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>



int main(int argc, char *argv[])
{
	Validacion *validacion = new Validacion();
    ListaDoble<string> lista;
	RolDePagos *rol= new RolDePagos();
	rol = new RolDePagos();
    Trabajador* trabajador = new Trabajador();
    Ingresos* ingresos= new Ingresos();
    Egresos* egresos = new Egresos();


    int opcion;
    do
    {
        system("cls");
        system("cls");
        cout << "|----------------------------------------------------------------|" << endl;
        cout << "|                   .:MENU Rol De Pagos:.                        |" << endl;
        cout << "!----------------------------------------------------------------|" << endl;
        cout << "|        ~ 1. Generar Rol de Pagos ~                             |" << endl;
        cout << "|        ~ 2. Ver Roles de pagos ~                               |" << endl;
        cout << "|        ~ 3. Buscar Rol de Pagos ~                              |" << endl;
        cout << "|        ~ 4. Vizualizar trabajadores en la lista doble ~        |" << endl;
        cout << "|        ~ 5. Eliminar Registro ~                                |" << endl;
        cout << "|        ~ 6. Modificar Registro ~                               |" << endl;
        cout << "|        ~ 7. Mostrar cedulas por provincias ~                   |" << endl;
        cout << "|        ~ 8. Salir ~                                            |" << endl;
        cout << "|----------------------------------------------------------------|" << endl;

        opcion = validacion->charToInt();
        switch (opcion)
        {
        case 1:
            system("cls");
            trabajador = rol->generarTrabajador();
            ingresos = rol->generarIngresos();
            egresos = rol->generarEgresos(ingresos->getTotalIngresos());
            rol->imprimirRol(trabajador, ingresos, egresos);
            rol->guardarArchivoTxt(rol->toString(trabajador, ingresos, egresos));
            system("pause");
            break;

        case 2:
            system("cls");
			rol->verRolesDePago();
            system("pause");
            break;
        case 3:
            system("cls");
            rol->buscarRolDePagos();
            system("pause");
            break;
        case 4:
            system("cls");
            rol->verRolesDePagoEnLista();
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Borrar registro";
			rol->borrarRolDePagos();
            system("pause");
			break;
        case 6:
            system("cls");
			cout << "Modificar registro";
			rol->modificarRolDePagos();
            system("pause");
            break;
        case 7:
            system("cls");
            rol->verRolesDePago();
            validacion->mostrarProvincia();
            system("pause");
        case 8:
            cout << "\n\tSaliendo..." << endl;
            cout << "\n\tGracias por usar nuestro programa " << endl;
            system("pause");
            break;
        
        }
    } while (opcion != 8);

	delete rol;
	delete trabajador;
	delete ingresos;
	delete egresos;
	delete validacion;
	
    return 0;
}
