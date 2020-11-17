#ifndef NodoPais_h
#define NodoPais_h

#include <vector>
#include <string>
#include "../String Parser/StringParser.h"
/**
 * Clase Nodo que almacena los datos del SVG
 */
using namespace std;
class NodoPais
{
private:
	string idPais;							//Nombre del pais.
	vector<NodoPais *> paisesColindates;	//Vector de paises colindantes.
	vector<float> coordsX;                  //Vector con las cordenadas X.
	vector<float> coordsY;                  //Vector con las coordenadas Y.
	float maxCoordX = 0;					//Maximo coordenada X
	float maxCoordY = 0;					//Minimo coordenada Y
	float minCoordX = INT_MAX;				//Maximo coordenada Y
	float minCoordY = INT_MAX;				//Minimo coordenada X
	string colorPais;						//Color del pais en hexadecimal.
	bool visitado;							//Verifica si el nodo fue visitado.
	
public:
	NodoPais(string pIdPais, string pColorPais, string pCoordenadas);	//Constructor.
	void insertarPaisColindante(NodoPais *pPaisColindante);				//Inserta un pais colindante.
	void setColorPais(string pColorPais);								//Setea el color del pais.
	void setVisitado(bool pVisited);									//Setea si el pais ha sido visitado.
	void setIdPais(string pIdPais);										//Setea el id del pais.
	void setCoordenadas(string pCoordenas);								//Setea las coordenadas.
	void asignarMinMaxCoordXY(float pValorX, float pValorY);
	string getColorPais();												//Obtiene el color del pais.
	bool isVisitado();						    						//Obtiene si el pais ha sido visitado.
	string getIdNombrePais();											//Obtiene el id del pais.
	vector<NodoPais *> getListaPaiseColindantes();						//Retorna la lista de paises colindantes.
	vector<float> getCoordenadasX();									//Obtiene las coordenadas.
	vector<float> getCoordenadasY();
	float getMaxCoordX();
	float getMaxCoordY();
	float getMinCoordX();
	float getMinCoordY();

};

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
	int tamStringCoordenadas = splitCoordenadas.size();
	for(int i = 0; i < tamStringCoordenadas; i++){
		vector<string> splitXY = parser->splitString(splitCoordenadas[i], ',');
		try {
			valorX += stof(splitXY[0]);
			valorY += stof(splitXY[1]);
		}catch(const std::invalid_argument& ia){
 			std::cerr << "Invalid argument: " << ia.what() << '\n';
		}
		asignarMinMaxCoordXY(valorX,valorY);
		coordsX.push_back(valorX);
		coordsY.push_back(valorY);
	}
}

void NodoPais::asignarMinMaxCoordXY(float pValorX, float pValorY){
	if(maxCoordX < pValorX)
		maxCoordX = pValorX;
	else if(minCoordX > pValorX)
		minCoordX = pValorX;
	if(maxCoordY < pValorY)
		maxCoordY = pValorY;
	else if(minCoordY > pValorY)
		minCoordY = pValorY;
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

/**
 * @brief Obitne la coordenada más grande en X
 * 
 * @return int 
 */
float NodoPais::getMaxCoordX(){
	return maxCoordX;
}

/**
 * @brief OBtiene la coordenadas más grande en Y
 * 
 * @return int 
 */
float NodoPais::getMaxCoordY(){
	return maxCoordY;
}

/**
 * @brief Obtiene la coordenada más pequeña en X
 * 
 * @return int 
 */
float NodoPais::getMinCoordX(){
	return minCoordX;
}

/**
 * @brief Obtiene la coordenada más pequeña en Y
 * 
 * @return int 
 */
float NodoPais::getMinCoordY(){
	return minCoordY;
}


#endif
