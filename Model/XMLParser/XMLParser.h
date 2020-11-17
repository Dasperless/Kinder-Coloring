#ifndef XMLParser_H
#define XMLParser_H

#include "../pugixml/pugixml.hpp"
#include <iostream>
#include "../Grafo/GrafoPaises.h"
using namespace std;

class XMLParser{

    private:
        GrafoPaises * datosPaises; //Grafo de Paises
        const char* path;
        pugi::xml_document doc;
        pugi::xml_parse_result result;
        
    public:
        XMLParser(const char* pPath); // Constructor
        void iniciarParse(); // Parseo del archivo
        GrafoPaises* obtenerGrafo(); // Obtener el grafo de paises
        void ModificarColor(string idPais, string color); // Modifica el color del pais segun el ID.
};

#endif /* XMLParser_H */