#include "Plantilla StringParser/StringParser.h"
StringParser::StringParser(){
}


/**
 * @brief Parsea el string para eliminar los comandos del svg. 
 * 
 * @param pCoordenadas 
 * @return string 
 */
string StringParser::eliminarComandosCoordenadas(string pCoordenadas){
	string stringSinComandos = pCoordenadas;

	stringSinComandos.erase(remove(stringSinComandos.begin(), stringSinComandos.end(), 'm'), stringSinComandos.end());
	stringSinComandos.erase(remove(stringSinComandos.begin(), stringSinComandos.end(), 'z'), stringSinComandos.end());	
	
	return stringSinComandos;
}

/**
 * @brief Elimina los espacios extra de un string
 * 
 * @param pString String a eliminar los espacios extra
 * @return string sin espacios extra
 */
string StringParser::eliminarEspaciosExtra(string pString){
	string stringSinEspaciosExtra = "";
	for(int i = 0; i < pString.size(); i++){
		char caracterActual = pString.at(i);
		if( caracterActual == ' '){
			if(i != 0 && i + 1 < pString.size()){
				if(pString.at(i + 1) != ' ')
					stringSinEspaciosExtra += caracterActual;
			}
		}else{
			stringSinEspaciosExtra += caracterActual;
		}
	}
	return stringSinEspaciosExtra;
}

/**
 * @brief Parte el string mediante un delimitador y lo guarda en un vector.
 * 
 * @param pString 		El string a partir.
 * @param pDelimitador 	El delimitador por el que se partira el string.
 * @return vector<string> 
 */
vector<string> StringParser::splitString(string pString, char pDelimitador){
	stringstream ss(pString);
	string item;
	vector<string> vectorPartido;
	while(getline(ss,item,pDelimitador)){
		vectorPartido.push_back(item);
	}
	return vectorPartido;
}

string StringParser::parsearCoordenadas(string pCoordenadas){
	string coordenadasParseadas = eliminarComandosCoordenadas(pCoordenadas);
	coordenadasParseadas = eliminarEspaciosExtra(coordenadasParseadas);
	return coordenadasParseadas;
}
