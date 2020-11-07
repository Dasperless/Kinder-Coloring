#include "XMLParser.h"

XMLParser::XMLParser(const char* pPath){
    datosPaises = new GrafoPaises();
    this->path=pPath;
}

/*
* Iniciar el parseo del archivo segun el path.
*/
void XMLParser::iniciarParse(){
    
    pugi::xml_document doc; // inicialización del documento
    pugi::xml_parse_result result = doc.load_file(path); // Leer el documento
    cout<<result.description()<<endl;

    // Abrir el nodo svg
    pugi::xml_node svgNode = doc.child("svg");

    // Variables para almacenar datos
    string id;
    string coordenada;
    string color;

    // Ciclo en el cual se obtiene los ids, coordenadas y colores.
    for(pugi::xml_node nodo= svgNode.child("path"); nodo; nodo = nodo.next_sibling("path")){
        id = nodo.attribute("id").value();
        coordenada =nodo.attribute("d").value();
        color = nodo.attribute("style").value();
        this->datosPaises->insertaNodo(id,color,coordenada);
    }
}

