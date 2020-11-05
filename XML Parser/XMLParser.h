#ifndef XMLParser_H
#define XMLParser_H

#include "../HashTable/HashTable.h";
#include "pugixml.hpp"
#include <iostream>
using namespace std;

class XMLParser{

    private:
        HashTable *tablaDatos;
        
    public:
        XMLParser(const char* pPath);
        void iniciarParse();
        string getId(string pCoordenada);
        string getColor(string pID);
        list<string> getCoordenadas();

};

#endif /* XMLParser_H */