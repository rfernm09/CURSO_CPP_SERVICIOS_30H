// conversorcsv.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <nlohmann/json.hpp>

void testJson() {
    nlohmann::json doc;

    doc["mensaje"] = "Hello World";
    std::cout << doc.dump(4) << std::endl;

}

int main()
{
    testJson();

    return 0;
}
