#pragma once
#include  <libpq-fe.h>
#include <optional>
#include <vector>
#include "Categoria.h"

class CategoriaRepositorio
{
public:
	CategoriaRepositorio(PGconn* conn);
	std::optional<Categoria> read(int id);
	void create(const Categoria& categoria);
	void update(const Categoria& categoria);
	void deleteid(int id);
	std::vector<Categoria> selectAll();
	~CategoriaRepositorio();

private:
	PGconn* conn;
};

