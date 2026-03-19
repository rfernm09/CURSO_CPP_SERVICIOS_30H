#include <crow.h>
#include "Categoria.h"
#include "CategoriaCrow.h"

CategoriaCrow::CategoriaCrow(const CategoriaRepositorio& repo):repo(repo)
{
}

void CategoriaCrow::run()
{
	crow::SimpleApp app;

	CROW_ROUTE(app, "/categorias/<int>").methods(crow::HTTPMethod::GET)([this](int id) {
		/*/
		CROW_LOG_INFO << "Operación GET /id en usuarios, id = " << id;

		std::lock_guard<std::mutex> lock(this->mtx);
		if (this->usuarios.count(id) == 0) {
			return crow::response(404, "Usuario con el id: " + std::to_string(id) + " no existe");
		}

		// El usuario existe hay que devolverlo:
		crow::json::wvalue res;
		res["id"] = id;
		res["nombre"] = usuarios[id]["nombre"].s();
		res["edad"] = usuarios[id]["edad"].i();

		return crow::response(res);*/
		return crow::response("pendiente");
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
