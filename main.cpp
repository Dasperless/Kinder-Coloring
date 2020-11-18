#include <string>
#include <iostream>
#include "Model/Grafo/NodoPais.h"
#include "Model/Grafo/GrafoPaises.h"
#include "Model/Paises Vecinos/Bucket.h"
#include "Model/pugixml/pugixml.cpp"
#include "Model/XMLParser/XMLParser.cpp"
using namespace std;
int main()
{
	XMLParser *xml = new XMLParser("ArchivosXML/world.svg");
	xml->iniciarParse();
	GrafoPaises *g = xml->obtenerGrafo();
	string color = g->obtenerListaNodos().at(0)->getColorPais();
	// vector<NodoPais *>  nodos = g->obtenerListaNodos();
	// vector<Bucket *> b = g->obtenerBucket();
	// int bSize = b.size();
	// for(int i =0; i < bSize ;i++){
	// 	cout << b.at(i)->getVectorPaises().size()<<endl;;
	// }


}