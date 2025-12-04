// clienteREST.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
	
	// Peticion GET:
	auto response = cpr::Get(cpr::Url{ "http://localhost:8000/empleados/1" });
	std::string respuesta = response.text;
	std::cout << respuesta << std::endl;

	return 0;
}

