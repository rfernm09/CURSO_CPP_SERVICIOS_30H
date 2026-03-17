// crow_basico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <crow.h>

void testCrow() {
    crow::SimpleApp app;
    
    // Configuracion de rutas:
    CROW_ROUTE(app, "/")([]() {
        return "Hello World";
    });

    



    // Iniciar el servicio:
    app.port(18000);
    app.run();

    // app.port(18000).run();
}


int main()
{
    testCrow();
    return 0;
}

