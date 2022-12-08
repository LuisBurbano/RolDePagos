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

#include "Trabajador.h"
#include "Validacion.hpp"

Validacion validacion;

std::string Trabajador::getCedula(void)
{
    return this->cedula;
}

void Trabajador::setCedula(std::string newCedula)
{

    this->cedula = newCedula;
}

std::string Trabajador::getNombre(void)
{
    return this->nombre;
}

void Trabajador::setNombre(std::string newNombre)
{
    this->nombre = newNombre;
}

std::string Trabajador::getApellido(void)
{
    return this->apellido;
}

void Trabajador::setApellido(std::string newApellido)
{
    this->apellido = newApellido;
}

std::string Trabajador::getTelefono(void)
{
    return this->telefono;
}

void Trabajador::setTelefono(std::string newTelefono)
{
    this->telefono = newTelefono;
}

std::string Trabajador::getDireccion(void)
{
    return this->direccion;
}

void Trabajador::setDireccion(std::string newDireccion)
{
    this->direccion = newDireccion;
}

std::string Trabajador::getCorreo(void)
{
    return correo;
}

void Trabajador::setCorreo(std::string newCorreo)
{
    this->correo = newCorreo;
}

std::string Trabajador::getCargo(void)
{
    return cargo;
}

void Trabajador::setCargo(std::string newCargo)
{
    this->cargo = newCargo;
}
std::string Trabajador::getDepartamento(void)
{
    return departamento;
}

void Trabajador::setDepartamento(std::string newDepartamento)
{
    this->departamento = newDepartamento;
}

Trabajador::Trabajador()
{

}

Trabajador::~Trabajador()
{

}


std::string Trabajador::validarCedula(std::string cedulaIngresada)
{
    string cedula;
    char *cedulaPares= new char[10];
    char *cedulaImpares= new char[10];

	int *cedulaParte1 = new int[10];
	int *cedulaParte2 = new int[10];

    int sumaPares = 0;
    int sumaImpares = 0;
    int sumaTotal = 0;
    int digitoVerificador = 0;
    cedula = cedulaIngresada;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            cedulaPares[i] = cedulaIngresada[i];
            cedulaParte1[i] = atoi(&cedulaPares[i]);
            cedulaParte1[i] = cedulaParte1[i] * 2;
            if (cedulaParte1[i] > 9)
            {
                cedulaParte1[i] = cedulaParte1[i] - 9;
            }
            sumaPares = sumaPares + cedulaParte1[i];
        }
        else if (i % 2 != 0)
        {
            cedulaImpares[i] = cedulaIngresada[i];
            cedulaParte2[i] = atoi(&cedulaImpares[i]);

            if (i != 9)
            {
                sumaImpares = sumaImpares + cedulaParte2[i];
            }
        }
        if (i == 9)
        {
            sumaTotal = sumaPares + sumaImpares;
            digitoVerificador = sumaTotal % 10;

            if (digitoVerificador != 0)
            {
                digitoVerificador = 10 - digitoVerificador;
            }
        }
    }

    if (digitoVerificador == atoi(&(cedulaIngresada[9])))
    {
        cout << " Cedula Valida" << endl;
    }
    else if (digitoVerificador != atoi(&(cedulaIngresada[9])))
    {

        cout << " Cedula Invalida" << endl;
        cedula = "0";
    }
	delete [] cedulaParte1;
	delete [] cedulaParte2;
    delete [] cedulaPares;
    delete [] cedulaImpares;
    return cedula;
}

std::string Trabajador::ingresarCedula()
{

    char* cedulaIngresada;
    std::string cedulaValidada;
    std::string cedulaIngresadaAux;
    bool usuarioExiste = false;
    do
    {
        cedulaIngresada = validacion.integerImput("> ");
        cedulaIngresadaAux = cedulaIngresada;
        if (cedulaIngresadaAux.size()==10)
        {
            cedulaValidada = validarCedula(cedulaIngresadaAux);
        }
        else
        {
            cedulaValidada = "0";
        }

        if (cedulaValidada == "0")
        {
            cout << " Cedula Invalida, Ingrese nuevamente" << endl;
        }
        usuarioExiste = validacion.verificarUsuario(cedulaValidada);
        if (usuarioExiste == true) {
            cout << " El trabajador ya existe, ingrese uno valido" << endl;
        }

    } while (cedulaIngresadaAux != cedulaValidada || usuarioExiste == true);

    return cedulaIngresadaAux;
}

std::string Trabajador::ingresarNombre()
{
    std::string nombreIngresado;
    nombreIngresado = validacion.ingresoNombreApellido("> ");
    if (validacion.verificarUsuario(nombreIngresado) == true) {
        cout << " El trabajador ya existe, ingrese uno valido" << endl;
        nombreIngresado = ingresarNombre();
    }
    return nombreIngresado;
}

std::string Trabajador::ingresarApellido()
{
    std::string apellidoIngresado;
    apellidoIngresado = validacion.ingresoNombreApellido("> ");
    if (validacion.verificarUsuario(apellidoIngresado) == true) {
        cout << " El trabajador ya existe, ingrese uno valido" << endl;
        apellidoIngresado = ingresarApellido();
    }
    return apellidoIngresado;
}

std::string Trabajador::ingresarTelefono()
{
    std::string telefonoIngresado;
    telefonoIngresado = validacion.ingresoNumeroCelular("> ");
    return telefonoIngresado;
}

std::string Trabajador::ingresarDireccion()
{
    std::string direccionIngresada;
    direccionIngresada = validacion.ingresoDireccion("> ");
    return direccionIngresada;
}

std::string Trabajador::ingresarCorreo()
{
    std::string correoIngresado;
    correoIngresado = validacion.ingresoCorreo("> ");
    return correoIngresado;
}
std::string Trabajador::ingresarCargo()
{
    std::string cargoIngresado;
    cargoIngresado = validacion.charImput("> ");
    return cargoIngresado;
}

std::string Trabajador::ingresarDepartamento()
{
    std::string departamentoIngresado;
    departamentoIngresado = validacion.charImput("> ");
    return departamentoIngresado;
}

void Trabajador::ingresarDatos()
{
    std::string cedulaIngresada;
    std::string nombreIngresado;
    std::string apellidoIngresado;
    std::string telefonoIngresado;
    std::string direccionIngresada;
    std::string correoIngresado;
    std::string cargoIngresado;
    std::string departamentoIngresado;

    cout << endl << " \nIngrese la cedula del trabajador: " << endl;
    cedulaIngresada = ingresarCedula();
    this->setCedula(cedulaIngresada);
    cout << endl << "\nIngrese el nombre del trabajador: " << endl;
    nombreIngresado = ingresarNombre();
    this->setNombre(nombreIngresado);
    cout << endl << " \nIngrese el apellido del trabajador: " << endl;
    apellidoIngresado = ingresarApellido();
    this->setApellido(apellidoIngresado);
    cout << endl << " \nIngrese el telefono del trabajador: " << endl;
    telefonoIngresado = ingresarTelefono();
    this->setTelefono(telefonoIngresado);
    telefonoIngresado = this->getTelefono();
    cout << endl << " \nIngrese la direccion del trabajador: " << endl;
    direccionIngresada = ingresarDireccion();
    this->setDireccion(direccionIngresada);
    cout << endl << " \nIngrese el correo del trabajador: " << endl;
    correoIngresado = ingresarCorreo();
    this->setCorreo(correoIngresado);
    cout << endl << " \nIngrese el cargo del trabajador: " << endl;
    cargoIngresado = validacion.charImput("> ");
    this->setCargo(cargoIngresado);
    cout << endl << " \nIngrese el departamento del trabajador: " << endl;
    departamentoIngresado = validacion.charImput("> ");
    this->setDepartamento(departamentoIngresado);

    cout << " \nTrabajador ingresado con exito" << endl;
}

void Trabajador::mostrarDatos()
{
    string cedulaMostrada;
    cedulaMostrada = this->getCedula();
    string nombreMostrado;
    nombreMostrado = this->getNombre();
    string apellidoMostrado;
    apellidoMostrado = this->getApellido();
    string telefonoMostrado;
    telefonoMostrado = this->getTelefono();
    string direccionMostrada;
    direccionMostrada = this->getDireccion();
    string correoMostrado;
    correoMostrado = this->getCorreo();
    string cargoMostrado;
    cargoMostrado = this->getCargo();
    string departamentoMostrado;
    departamentoMostrado = this->getDepartamento();

    cout << "Cedula: " << cedulaMostrada << endl;
    cout << "Nombre: " << nombreMostrado << endl;
    cout << "Apellido: " << apellidoMostrado << endl;
    cout << "Telefono: " << telefonoMostrado << endl;
    cout << "Direccion: " << direccionMostrada << endl;
    cout << "Correo: " << correoMostrado << endl;
    cout << "Cargo: " << cargoMostrado << endl;
    cout << "Departamento: " << departamentoMostrado << endl;
}

std::string Trabajador::toString() {
    return this->getCedula() + " " + this->getNombre() + " " + this->getApellido() + " " + this->getTelefono() + " " + this->getCargo();
}