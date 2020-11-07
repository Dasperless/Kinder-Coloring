KINDER-COLORING: HashTable/HashTable.o pugixml/pugixml.o XMLParser/XMLParser.o
	g++ HashTable/HashTable.o pugixml/pugixml.o XMLParser/XMLParser.o -o colorear

HashTable.o: HashTable/HashTable.cpp
	g++ -c HashTable/HashTable.cpp
XMLParser.o: XMLParser/XMLParser.cpp
	g++ -c XMLParser/XMLParser.cpp
pugixml.o: pugixml/pugixml.cpp
	g++ -c pugixml/pugixml.cpp
clean:
	rm *.o colorear