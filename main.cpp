#include <string>
#include <iostream>
#include "Model/Grafo/NodoPais.h"
#include "Model/Grafo/GrafoPaises.h"
#include "Model/Paises Vecinos/Bucket.h"
#include "Model/pugixml/pugixml.cpp"
#include "Model/XMLParser/XMLParser.cpp"
// #include "Model/Paises Vecinos/Bucket.cpp"
using namespace std;
int main()
{
	XMLParser *xml = new XMLParser("C:/Users/dvarg/Desktop/TEC/2020/Segundo Semestre/Análisis/Proyectos/Proyecto I/Kinder-Coloring/ArchivosXML/world.svg");
	xml->iniciarParse();
	GrafoPaises *g = xml->obtenerGrafo();
	vector<Bucket *> b = g->obtenerBucket();
	int bSize = b.size();
	for(int i =0; i < bSize ;i++){
		cout << b.at(i)->getBucketPaises().size()<<endl;;
	}


}