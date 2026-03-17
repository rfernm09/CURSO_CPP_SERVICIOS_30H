#pragma once

#include <string>

class Pedido
{
	std::string idpedido;
	std::string cliente;
	std::string empresa;
	std::string empleado;
	float importe;
	std::string pais;

public:
	Pedido();
	Pedido(std::string, char = ';');
	~Pedido();
};

