// multicliente.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <vector>
#include <string>

#include <boost/beast/core.hpp>
#include <boost/asio.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;


int main()
{
	net::io_context ioc;

	// Inicializar acceptor con el contexto de entrada/salida y un endpoint en el puerto 80
	tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 8080));

	//do_accept(acceptor);

	std::cout << "Servidor multicliente en el puerto 8080" << std::endl;

	// DEfinir un vector para lanzar los hilos:
	std::vector<std::thread> hilos;
	for (int i = 0; i < std::thread::hardware_concurrency(); i++) {

		// Creamos un hilo dentro del vector sin hacer una copia:
		hilos.emplace_back([&ioc] { ioc.run();  });
	}

	for (auto& h : hilos) {
		h.join();
	}

	// SI SOLO QUEREMOS UN HILO EN EJECUCION
	//ioc.run()

	return 0;
}
