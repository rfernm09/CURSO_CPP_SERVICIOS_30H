// punteros.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Vector.h"

int main()
{
    Vector v1;

    v1.add(1);
    v1.add(2);
    v1.add(3);
    v1.add(41);

    v1.imprimir();

    Vector v2(v1);
    v2.imprimir();

    Vector v3;
    v3 = v1;
    v3.imprimir();


    return 0;
}
