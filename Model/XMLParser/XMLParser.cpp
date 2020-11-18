#include "XMLParser.h"
#include <cstring>
#include <windows.h>
#include <list>
XMLParser::XMLParser(const char* pPath){
    datosPaises = new GrafoPaises();
    this->path=pPath;
    result = doc.load_file(path); // Leer el documento
}

/*
* Iniciar el parseo del archivo segun el path.
*/
void XMLParser::iniciarParse(){
    
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

/*
 *Retorna el grafo de paises 
*/
GrafoPaises* XMLParser::obtenerGrafo(){
    return this->datosPaises;
}

/**
 * Modifica el color del pais segun su ID.
 * Recibe como parametros el ID del pais y el color a colocar.
*/
void XMLParser::ModificarColor(string pID, string color){
    pugi::xml_node svgNode = doc.child("svg");
    
    string colorNuevo = "fill:"+color+";fill-rule:evenodd";

    for(pugi::xml_node nodo= svgNode.child("path"); nodo; nodo = nodo.next_sibling("path")){
        if(nodo.attribute("id").value()==pID){
            pugi::xml_attribute attr = nodo.attribute("style");
            attr.set_value(colorNuevo.c_str());
        }
    }
    doc.save_file(path,"\t",pugi::format_indent_attributes);
}
