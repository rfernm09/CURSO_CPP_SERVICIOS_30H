#pragma once

#include <soci/soci.h>
#include <optional>
#include <vector>
#include "empleado.h"

class EmpleadoRepositorio
{
public:
	EmpleadoRepositorio(soci::session&);
	std::optional<Empleado> read(int);
	bool create(const Empleado&);
	bool update(const Empleado&);
	bool delete_(int);
	std::vector<Empleado> select();

private:
	soci::session& sql;
};

