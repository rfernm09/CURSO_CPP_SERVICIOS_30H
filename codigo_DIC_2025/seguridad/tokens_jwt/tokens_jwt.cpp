// tokens_jwt.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <chrono>
#include <crow.h>

#include <nlohmann/json.hpp>
#include <jwt-cpp/jwt.h>

using json = nlohmann::json;

int main()
{
    crow::SimpleApp app;
        
    CROW_ROUTE(app, "/login").methods("POST"_method)([](const crow::request& request) {

        try {

            // Obtener las credenciales de la request:
            auto j = json::parse(request.body);


        }
        catch (const std::exception& e) {
            return crow::response(400, std::string("Json incorrecto: ") + e.what());
        }

        });

    // Poner en marcha el servidor:
    //app.multithreaded().run();
    app.multithreaded().concurrency(std::thread::hardware_concurrency()).port(8000).run();
    return 0;
}

