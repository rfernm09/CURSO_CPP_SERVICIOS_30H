#include <crow.h>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include "Categoria.h"
#include "CategoriaCrow.h"

using json = nlohmann::json;


CategoriaCrow::CategoriaCrow(const CategoriaRepositorio& repo):repo(repo)
{
}

void CategoriaCrow::run()
{
	crow::SimpleApp app;

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::GET)([this](int id) {
		
		try {
			auto cat = this->repo.read(id);
			if (cat) {
				json j = cat;
				return crow::response(200, j);
			}
			else {
				// No existe.
				return crow::response(404, "Categoria con el id: " + std::to_string(id) + " no existe");
			}
		}
		catch (const std::exception& e) {
			std::string msg = e.what();
			return crow::response(500, "Error interno en el servidor: " + msg);
		}
	});

	CROW_ROUTE(app, "/categorias").methods(crow::HTTPMethod::GET)([this]() {
		
		return crow::response("pendiente");
	});

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::PUT)([this](const crow::request& req, int id) {
	
		return crow::response("pendiente");
	});

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::Delete)([this](int id) {
		
		return crow::response("pendiente");
	});

	// Puesta en marcha del servidor
	app.port(8080).concurrency(std::thread::hardware_concurrency()).multithreaded().run();
}

CategoriaCrow::~CategoriaCrow()
{
}
