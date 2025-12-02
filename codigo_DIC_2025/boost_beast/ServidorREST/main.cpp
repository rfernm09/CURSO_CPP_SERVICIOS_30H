
#include <iostream>
#include "ServidorREST.h"

void testServidorREST() {
    boost::asio::io_context ioc;
    ServidorREST server(ioc, 8080);
    server.run();
}

int main()
{
    testServidorREST();
    return 0;
}
