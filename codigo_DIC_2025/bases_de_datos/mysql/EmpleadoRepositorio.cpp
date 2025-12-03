#include "EmpleadoRepositorio.h"

EmpleadoRepositorio::EmpleadoRepositorio(soci::session&)
{
}

std::optional<Empleado> EmpleadoRepositorio::read(int)
{
	return std::optional<Empleado>();
}

bool EmpleadoRepositorio::create(const Empleado&)
{
	return false;
}

bool EmpleadoRepositorio::update(const Empleado&)
{
	return false;
}

bool EmpleadoRepositorio::delete_(int)
{
	return false;
}

std::vector<Empleado> EmpleadoRepositorio::select()
{
	return std::vector<Empleado>();
}
