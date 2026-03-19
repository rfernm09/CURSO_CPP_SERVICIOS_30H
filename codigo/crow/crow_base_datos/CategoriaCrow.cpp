#include <crow.h>
#include "CategoriaCrow.h"

CategoriaCrow::CategoriaCrow(const CategoriaRepositorio& repo):repo(repo)
{
}

void CategoriaCrow::run()
{
	crow::SimpleApp app;

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::GET)([this](int id) {});

	CROW_ROUTE(app, "/categorias").methods(crow::HTTPMethod::GET)([this]() {});

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::PUT)([this](const crow::request& req, int id) {});

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::Delete)([this](int id) {});
}

CategoriaCrow::~CategoriaCrow()
{
}
