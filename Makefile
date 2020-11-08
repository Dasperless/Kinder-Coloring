KINDER-COLORING: Model/pugixml/pugixml.o Model/XMLParser/XMLParser.o Model/Grafo/NodoPais.o Model/Grafo/GrafoPaises.o
	g++ Model/pugixml/pugixml.o Model/XMLParser/XMLParser.o Model/Grafo/NodoPais.o Model/Grafo/GrafoPaises.o -o colorear

GrafoPaises: Model/Grafo/GrafoPaises.cpp
	g++ -c Model/Grafo/GrafoPaises.cpp

NodoPais: Model/Grafo/NodoPais.cpp
	g++ -c Model/Grafo/NodoPais.cpp

XMLParser: Model/XMLParser/XMLParser.cpp
	g++ -c Model/XMLParser/XMLParser.cpp

pugixml: Model/pugixml/pugixml.cpp
	g++ -c Model/pugixml/pugixml.cpp
	
clean:
	rm *.o colorear.exe