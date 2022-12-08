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
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdio.h>

using namespace std;

class Validacion
{
public:
    char* integerImput(char const* msj)
    {
        char* dato = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= '0' && c <= '9')
            {
                cout << c;
                dato[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
        }
        dato[i] = '\0';
        return dato;
    }

    char* charImput(char const* msj)
    {

        char* a = new char[100];
        char c;
        int i = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == ' ')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
        }
        a[i] = '\0';
        return a;
    }

    char* doubleAndFloatImput(char const* msj)
    {
        char* a = new char[0];
        char c;
        int i = 0, cont = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= '0' && c <= '9')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '.' && cont < 1)
            {
                cout << c;
                a[i++] = c;
                cont++;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
                cont = 0;
            }
        }
        a[i] = '\0';
        return a;
    }

    char* ingresoCedula(char const* msj)
    {
        int i = 0;
        char* dato = new char[0];
        char c;
        cout << msj;
        do
        {
            i = 0;
            while ((c = _getch()) != 13)
            {
                if (c >= '0' && c <= '9' && i <= 9)
                {
                    cout << c;
                    dato[i++] = c;
                }
                else if (c == '\b')
                {
                    i--;
                    cout << "\b \b";
                }
            }
            if (i < 9)
            {
                cout << "\n\tFaltan " << 9 - i << " digitos" << endl;
            }
        } while (i < 9);
        dato[i] = '\0';
        return dato;
        delete[]dato;
    }


    char* ingresoNombreApellido(char const* msj)
    {
        char* a = new char[100];
        char c;
        int i = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
            if (a[0] >= 'a' && a[0] <= 'z')
            {
                a[0] = a[0] - 32;
            }
        }
        a[i] = '\0';
        return a;
        delete[]a;
    }

    char* ingresoNumeroCelular(char const* msj)
    {
        int i = 0;
        char* dato = new char[10];
        char c;
        cout << msj;
        do
        {
            i = 0;
            while ((c = _getch()) != 13)
            {
                if (c >= '0' && c <= '9' && i <= 9)
                {
                    cout << c;
                    dato[i++] = c;
                }
                else if (c == '\b')
                {
                    i--;
                    cout << "\b \b";
                }
            }
            if (i < 9)
            {
                cout << "\n\tFaltan " << 9 - i << " digitos" << endl;
            }
            if (dato[0] != '0' || dato[1] != '9')
            {
                cout << "\n\tEl numero debe empezar con 09" << endl;
            }
        } while (i < 9 || dato[0] != '0' || dato[1] != '9');
        dato[i] = '\0';
        return dato;
        delete[]dato;
    }

    std::string ingresoDireccion(char const* msj)
    {

		char* a = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9' || c == '-' || c == ' ')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
        }

        
        a[i] = '\0';
        return a;
        
        
    }

    std::string ingresoCorreo(char const* msj)
    {

        char* a= new char[50];
        char c;
        int i = 0, cont1 = 0, cont2 = 0;
        cout << msj;
        while ((c = _getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9' || c == '_')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '.' && cont1 < 1)
            {
                cout << c;
                a[i++] = c;
                cont1++;
            }
            else if (c == '@' && cont2 < 1)
            {
                cout << c;
                a[i++] = c;
                cont2++;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
                cont1 = 0;
                cont2 = 0;
            }
        }
        a[i] = '\0';
        return a;
		delete[]a;
        
    }

    vector<string> split(string str, char pattern)
    {

        int posInit = 0;
        int posFound = 0;
        string splitted;
        vector<string> results;

        while (posFound >= 0)
        {
            posFound = str.find(pattern, posInit);
            splitted = str.substr(posInit, posFound - posInit);
            posInit = posFound + 1;
            results.push_back(splitted);
        }

        return results;
    }

    bool verificarUsuario(string datoBuscar)
    {

        vector<string> results;
        string line;
        string lectura;
        lectura = leerArchivoTxt();
        char delimitador = '\n';
        stringstream input_stringstream(lectura);
        

        while (getline(input_stringstream, line, '\n'))
        {

            results = split(line, ' ');

            for (int i = 0; i < results.size(); i++)
            {
                //cout << results[i] << endl;
                if (results[i] == datoBuscar)
                {
                    return true;
                    break;
                }

            }
        }
    }

    string buscarEnLista(string datoBuscar)
    {

        vector<string> results;
        string line;
        string lectura;
		string datoEncontrado;
        
        lectura = leerArchivoTxt();
        char delimitador = '\n';
        stringstream input_stringstream(lectura);

        datoEncontrado = "NO SE ENCONTRO";
        while (getline(input_stringstream, line, '\n'))
        {
            results = split(line, ' ');
            for (int i = 0; i < results.size(); i++)
            {
                if (results[i] == datoBuscar)
                {
					datoEncontrado = line;
                    
                }

            }
        }
        return datoEncontrado;
        
    }

    int charToInt()
    {
        char dato[10];
        int valor = 0;
        strcpy_s(dato, integerImput("\n> "));
        valor = atoi(dato);
        return valor;
    }

    float charToFloat()
    {
        char dato[10];
        float valor = 0;
        strcpy_s(dato, doubleAndFloatImput("\n> "));
        valor = (float)atof(dato);
        return valor;
    }


    string leerArchivoTxt()
    {
        string texto;
        string lectura;
        ifstream archivo;
        archivo.open("RolDePagos.txt", ios::in);
        if (archivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
		//cout << "ESto es lectura: " << lectura << "ESTO ES EL LINAL DE LECTURA EN VALIDACIONES" << endl;
        archivo.close();
        return lectura;

    }

    std::string doubleToString(double number) {
        std::stringstream textConverter;
        textConverter << std::fixed << std::setprecision(2) << number;
		std::string textFinal = textConverter.str();
		//cout << textFinal << endl;
        return textFinal;

    }

    
    void renombrarArchivo(char const* nombreOriginal, char const* nuevoNombre) {


        rename(nombreOriginal, nuevoNombre);

    }
    void borrarEnLista(std::string lineaBorrar) {
        string texto;
        string lectura;
        ifstream archivo;
        std::fstream archivoAux;
        int contador = 0;
        archivo.open("RolDePagos.txt", ios::in);
        if (archivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {   
            getline(archivo, texto);
            
            if (lineaBorrar!=texto)
            {
                if (contador==0)
                {
                    lectura += texto;
                    contador++;
                }
                else {
                    lectura += "\n" + texto;
                }
                   
            }
            
        }
        archivo.close();
        

        
        archivoAux.open("Aux.txt", std::ios::out);
        if (archivoAux.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        archivoAux << lectura;
        archivoAux.close();
        remove("RolDePagos.txt");
		renombrarArchivo("Aux.txt", "RolDePagos.txt");

    }
    void modificarEnLista(std::string lineaBorrar, std::string lineaNueva) {
        string texto;
        string lectura;
        ifstream archivo;
        std::fstream archivoAux;
        int contador = 0;
        archivo.open("RolDePagos.txt", ios::in);
        if (archivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto);
            if (lineaBorrar != texto)
            {
                if (contador==0)
                {
                    lectura +=texto;
                    contador++;
                }
                else {
                    lectura += "\n" + texto;

                }

            }
            else {
                if (contador == 0)
                {
                    lectura +=lineaNueva;
                    contador++;
                }
                else {
                    lectura += "\n" + lineaNueva;

                }
                
            }

        }
        archivo.close();



        archivoAux.open("Aux.txt", std::ios::out);
        if (archivoAux.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        archivoAux << lectura;
        archivoAux.close();
        remove("RolDePagos.txt");
        renombrarArchivo("Aux.txt", "RolDePagos.txt");

    }
	
    void mostrarProvincia() {

        vector<string> results;
        string line;
        string lectura;
        string datoEncontrado;
        string digitosCedula;
        lectura = leerArchivoTxt();
        stringstream input_stringstream(lectura);
        int contadorProvincias[23];
        int aux = 0;
        string provincias[23][2]={{"Azuay", "01"},{"Bolivar","02"},{"Cañar", "03"},
            {"Carchi", "04"},
            {"Cotopaxi", "05"},
            {"Chimborazo", "06"},
            {"El Oro", "07"},
            {"Esmeraldas", "08"},
            {"Guayas", "09"},
            {"Imbabura", "10"},
            {"Loja", "11"},
            {"Los rios", "12"},
            {"Manabi", "13"},
            {"Morona Santiago", "14"},
            {"Napo", "15"},
            {"Pastaza", "16"},
            {"Pichincha", "17"},
            {"Tungurahua", "18"},
            {"Zamora Chinchipe", "19"},
            {"Galapagos", "20"},
            {"Sucumbios", "21"},
            {"Santo Domingo", "22"},
            {"Santa Elena", "23"}
            
        };
        

        
        //se inicializan el array con 0
        for (int i = 0; i < 22; i++)
        {
            contadorProvincias[i] = 0;
        }

        while (getline(input_stringstream, line, '\n'))
        {            
            results = split(line, ' ');
            for (int i = 0; i < 1; i++)
            {
                datoEncontrado = results[i];                
                digitosCedula = datoEncontrado[0];
                digitosCedula += datoEncontrado[1];   
                
                for (int k = 0; k < 22; k++)
                {
                    if (digitosCedula == provincias[k][1]) {
                        cout << "CEDULAS: " << datoEncontrado << endl;
                        contadorProvincias[k] += 1;
                    }
                }
                digitosCedula = "\0";	   
            }

        }
        
        for (int i = 0; i < 22; i++)
        {          
			aux = contadorProvincias[i];
            if (aux!=0)
            {
                cout << "Provincias: " << provincias[i][0] << " Cantidad de personas: " << contadorProvincias[i] << endl;
            }
   
        }   
        
    }
	
};