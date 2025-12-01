#include "Pedido.h"

Pedido::Pedido()
{
}

Pedido::Pedido(const std::string&, char)
{
}

nlohmann::json Pedido::to_json() const
{
	return nlohmann::json();
}

Pedido Pedido::from_json(const nlohmann::json&)
{
	return Pedido();
}

Pedido::~Pedido()
{
}
