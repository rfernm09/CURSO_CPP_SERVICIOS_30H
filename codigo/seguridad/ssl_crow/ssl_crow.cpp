// ssl_crow.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Hola seguro con HTTPS";
    });

    app.port(8080).multithreaded().run();
}

