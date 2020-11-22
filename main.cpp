#include <string>
#include <iostream>
#include "Model/Grafo/NodoPais.h"
#include "Model/Grafo/GrafoPaises.h"
#include "Model/Paises Vecinos/Bucket.h"
#include "Model/pugixml/pugixml.cpp"
#include "Model/XMLParser/XMLParser.cpp"
#include "Model/DivideAndConquer/DivideAndConquer.cpp"
#include "Model/ColoringAlgorithm/ColoringAlgorithm.cpp"
using namespace std;
int main()
{
	XMLParser *xml = new XMLParser("ArchivosXML/world.svg");
	xml->iniciarParse();
	GrafoPaises *g = xml->obtenerGrafo();
	DivideAndConquer divide(g);
	vector<pair<string,string>> vectorAPintar = divide.iniciarAlgoritmo(11);
	for(auto x: vectorAPintar){
		xml->ModificarColor(x.first,x.second,"0");
	}
}