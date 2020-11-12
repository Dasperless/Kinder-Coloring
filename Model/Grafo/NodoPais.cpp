
/**
 * Implementacion de la clase nodo.
 */
#include "Plantilla Grafo/NodoPais.h"
#include "../String Parser/StringParser.cpp"

/**
 * @brief Construye un nevo objecto de tipo nodoPais
 * 
 * @param pIdPais 		
 * @param pColorPais 
 * @param pCoordenadas 
 */
NodoPais::NodoPais(string pIdPais, string pColorPais, string pCoordenadas ){
	setIdPais(pIdPais);
	setColorPais(pColorPais);
	setCoordenadas(pCoordenadas);
}	

/**
 * @brief Inserta un pais colindante
 * 
 * @param pPaisColindante puntero del pais colindante.
 */
void NodoPais::insertarPaisColindante(NodoPais* pPaisColindante){
	pPaisColindante->getListaPaiseColindantes().push_back(this);	//Inserta en pPaiscolindante el pais actual.
	paisesColindates.push_back(pPaisColindante);					//Inserta el pais colindante a la lista.
}

/**
 * @brief Establece el color del pais.
 * 
 * @param pColorPais El color a establecer.
 */
void NodoPais::setColorPais(string pColorPais){
	colorPais = pColorPais;
}

/**
 * @brief Establece el ID del pais.
 * 
 * @param pIdPais El nombre del pais.
 */
void NodoPais::setIdPais(string pIdPais){
	idPais = pIdPais;
}

/**
 * @brief Establece si el nodo ha sido visitado o no.
 * 
 * @param pVisitado True si ha sido visitado, False en caso contrairio.
 */
void NodoPais::setVisitado(bool pVisitado){
	visitado = pVisitado;
}

/**
 * @brief Establece las coordenadas del nodo
 * 
 * @param pCoordenadas String con coordenadas del svg.
 */
void NodoPais::setCoordenadas(string pCoordenadas){
	StringParser *parser = new StringParser();
	string coordenadasParseadas = parser->parsearCoordenadas(pCoordenadas);
	vector<string> splitCoordenadas = parser->splitString(coordenadasParseadas, ' ');

	float valorX = 0;
	float valorY = 0;
	for(int i = 0; i < splitCoordenadas.size(); i++){
		vector<string> splitXY = parser->splitString(splitCoordenadas[i], ',');
		valorX += stof(splitXY[0]);
		valorY += stof(splitXY[1]);
		coordsX.push_back(valorX);
		coordsY.push_back(valorY);
	}
}

/**
 * @brief Retorna el puntero de la lista de paises colindantes.
 * 
 * @return vector<NodoPais*> 
 */
vector<NodoPais*> NodoPais::getListaPaiseColindantes(){
	return paisesColindates;
}

/**
 * @brief Retorna el id del pais.
 * 
 * @return string 
 */
string NodoPais::getIdNombrePais(){
	return idPais;
}

/**
 * @brief Retorna si el pais ha sido visitado
 * 
 * @return true 
 * @return false
 */
bool NodoPais::isVisitado(){
	return visitado;
}

/**
 * @brief Retorna el color del pais.
 * 
 * @return string 
 */
string NodoPais::getColorPais(){
	return colorPais;
}

/**
 * @brief  Retorna un vector con las coordenadas X
 * 
 * @return vector<float> 
 */
vector<float> NodoPais::getCoordenadasX(){
	return coordsX;
}    

/**
 * @brief  Retorna un vector con las coordenadas Y
 * 
 * @return vector<float> 
 */
vector<float> NodoPais::getCoordenadasY(){
	return coordsY;
}    

