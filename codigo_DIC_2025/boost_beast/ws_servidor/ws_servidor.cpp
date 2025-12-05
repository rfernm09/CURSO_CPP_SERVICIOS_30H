// ws_servidor.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

void do_session(tcp::socket socket) {
	try {

		// DEfinir un stream con un socket TCP:
		websocket::stream<tcp::socket> ws(std::move(socket));
		ws.accept();

		for (;;) {
			// DEfinir un buffer para leer y escribir:;
			beast::flat_buffer buffer;

			ws.read(buffer);
			ws.text(ws.got_text());

			// Devolvemos lo mismo que hemos leido
			ws.write(buffer.data());
		}

	}
	catch (const beast::system_error& se) {
		if (se.code() != websocket::error::closed) {
			std::cerr << "Error en session: " << se.what() << std::endl;
		}
		else {
			std::cout << "Cliente desconectado" << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error inesperado " << e.what() << std::endl;
	}

}


int main()
{
	net::io_context ioc;

	// Inicializar acceptor con el contexto de entrada/salida y un endpoint en el puerto 80
	tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 80));

	// Capturar el numero de hilos que soportar el procesador:
	unsigned int num_threads = std::thread::hardware_concurrency();

	// Inicializar un pool de hilos con el numero que disponemos:
	boost::asio::thread_pool pool(num_threads);

	std::cout << "Servidor ok, numero de hilos: " << num_threads << std::endl;

	for (;;) {

		// DEfinir un 1 socket por conexion:
		tcp::socket socket(ioc);

		std::cout << "Esperando clientes " << std::endl;
		
		// Aceptar un cliente:
		acceptor.accept(socket);

		// Lanzar un hilo con boost para atender al cliente conectado:
		boost::asio::post(pool, [s = std::move(socket)]() mutable {
			do_session(std::move(s));
		});
	}
   
}
