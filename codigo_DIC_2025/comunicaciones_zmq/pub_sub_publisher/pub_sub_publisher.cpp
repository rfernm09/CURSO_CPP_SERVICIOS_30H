// pub_sub_publisher.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <zmq.hpp>
#include <string>

#include <cstdlib>
#include <ctime>


int main()
{
    // Inicializar numeros aleatorios con una semilla:
    std::srand(std::time(nullptr)); // Inicializar con el tiempo del sistema

    // Crear el socket y el contexto:
    zmq::context_t contexto(1);
    zmq::socket_t socket(contexto, zmq::socket_type::pub);

    socket.bind("tcp://*:5556");
    std::string medidas[] = { "temperatura", "humedad", "viento" };
    int valor;
    std::string mensaje;

    while (true) {

        for (std::string m : medidas) {

            valor = std::rand() % 100;
            mensaje = m + " " + std::to_string(valor);
            socket.send(zmq::buffer(m + " " + mensaje));
            std::cout << "publicando: " << mensaje << std::endl;
        }

        // Parar la ejecución 1 sg.
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
