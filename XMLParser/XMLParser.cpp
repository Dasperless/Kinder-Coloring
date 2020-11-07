#include "XMLParser.h"

XMLParser::XMLParser(const char* pPath){
    this->tablaDatos= new HashTable(211);
}

void XMLParser::iniciarParse(){
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("world.svg");
    cout<<result.description()<<endl;
    pugi::xml_node svgNode = doc.child("svg");
    string id;
    string coordenada;
    string color;
    for(pugi::xml_node nodo= svgNode.child("path"); nodo; nodo = nodo.next_sibling("path")){
        id = nodo.attribute("id").value();
        coordenada =nodo.attribute("d").value();
        color = nodo.attribute("style").value();
        this->tablaDatos->insertar(coordenada,id,color);
    }
}

string XMLParser::getColor(string pID){
    return this->tablaDatos->getColor(pID);
}

string XMLParser::getId(string pCoordenada){
    return this->tablaDatos->getID(pCoordenada);
}

list<string> XMLParser::getCoordenadas(){
    return this->tablaDatos->obtenerCoordenadas();
}
