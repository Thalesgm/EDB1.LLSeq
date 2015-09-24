/* Classe lista sequencial. */
#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>

#include "arraylist.h"




int main ( )
{
    ArrayList< int, std::string  >  myList( 50 ); // Lista de no máximo 50 elementos.

    std::cout << "\n>>> myList: " << myList << std::endl;

    myList.insert( 15, "dado 1" );
    myList.insert( 2, "dado 2" );
    myList.insert( 8, "dado 3" );
    std::cout << "\n>>> myList: " << myList << std::endl;
    std::string p;
    myList.remove(15, p);
    std::cout << "\n>>> myList: " << myList << std::endl;
    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}

