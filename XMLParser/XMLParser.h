#ifndef XMLParser_H
#define XMLParser_H

#include "../HashTable/HashTable.h"
#include "../pugixml/pugixml.hpp"
#include <iostream>
#include "../Model/Grafo/Plantilla Grafo/GrafoPaises.h"
using namespace std;

class XMLParser{

    private:
        GrafoPaises * datosPaises; //Grafo de Paises
        const char* path;
        
    public:
        XMLParser(const char* pPath); // Constructor
        void iniciarParse(); // Parseo del archivo
};

#endif /* XMLParser_H */