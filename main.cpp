#include <string>
#include <iostream>
#include "Model/Grafo/NodoPais.h"
#include "Model/Grafo/GrafoPaises.h"
#include "Model/Paises Vecinos/Bucket.h"
#include "Model/pugixml/pugixml.cpp"
#include "Model/XMLParser/XMLParser.cpp"
#include "Model/DivideAndConquer/DivideAndConquer.cpp"
#include "Model/ColoringAlgorithm/ColoringAlgorithm.cpp"
#include "Model/Program/Program.cpp"
using namespace std;
int main()
{
	Program* programaPrin = new Program();
	programaPrin->iniciarPrograma();
}