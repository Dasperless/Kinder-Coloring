#ifndef StringParser_h
#define StringParser_h

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class StringParser
{
public:
	StringParser();
	string eliminarComandosCoordenadas(string pCoordenadas);
	string eliminarEspaciosExtra(string pString);
	vector<string> splitString(string pString, char pDelimitador);
	string parsearCoordenadas(string pCoordenadas);
};


#endif
