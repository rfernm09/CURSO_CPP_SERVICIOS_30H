#include "CategoriaRepositorio.h"

CategoriaRepositorio::CategoriaRepositorio(PGconn* conn)
{
}

std::optional<Categoria> CategoriaRepositorio::read(int id)
{
	return std::optional<Categoria>();
}

void CategoriaRepositorio::create(const Categoria& categoria)
{
}

void CategoriaRepositorio::update(const Categoria& categoria)
{
}

void CategoriaRepositorio::deleteid(int id)
{
}

std::vector<Categoria> CategoriaRepositorio::selectAll()
{
	return std::vector<Categoria>();
}

CategoriaRepositorio::~CategoriaRepositorio()
{
}
