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

#if !defined(__ProyectoUnidad1_Trabajador_h)
#define __ProyectoUnidad1_Trabajador_h

#include<string>
class Trabajador
{
public:
	std::string getCedula(void);
	void setCedula(std::string newCedula);
	std::string getNombre(void);
	void setNombre(std::string newNombre);
	std::string getApellido(void);
	void setApellido(std::string newApellido);
	std::string getTelefono(void);
	void setTelefono(std::string newTelefono);
	std::string getDireccion(void);
	void setDireccion(std::string newDireccion);
	std::string getCorreo(void);
	void setCorreo(std::string newCorreo);
	std::string getCargo(void);
	void setCargo(std::string newCargo);
	std::string getDepartamento(void);
	void setDepartamento(std::string newDepartamento);

	std::string validarCedula(std::string);
	std::string ingresarCedula(void);
	std::string ingresarNombre(void);
	std::string ingresarApellido(void);
	std::string ingresarTelefono(void);
	std::string ingresarDireccion(void);
	std::string ingresarCorreo(void);
	std::string ingresarCargo(void);
	std::string ingresarDepartamento(void);
	void ingresarDatos(void);
	void mostrarDatos(void);
	Trabajador();
	~Trabajador();

	std::string toString();

protected:
private:
	std::string nombre;
	std::string apellido;
	std::string cedula;
	std::string telefono;
	std::string direccion;
	std::string correo;
	std::string cargo;
	std::string departamento;
};

#endif