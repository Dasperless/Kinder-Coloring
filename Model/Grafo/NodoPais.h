#ifndef NodoPais_h
#define NodoPais_h

#include <vector>
#include <string>
#include <math.h>
#include "../String Parser/StringParser.h"
/**
 * Clase Nodo que almacena los datos del SVG
 */
using namespace std;
class NodoPais
{
private:
	vector<NodoPais *> paisesVecinos; //Vector de paises vecinos.
	void setCoordenadas(string pCoordenadas);
	void asignarMinMaxCoordXY(float pValorX, float pValorY);
	bool isInRange(int pInicio, int pFin);

public:
	string colorPais; //Color del pais en hexadecimal.
	string idPais;	  //Nombre del pais.
	vector<string> coloresNoPermitidos;
	vector<float> coordsX;
	vector<float> coordsY;

	float maxCoordX = 0;	   //Maximo coordenada X
	float maxCoordY = 0;	   //Minimo coordenada Y
	float minCoordX = INT_MAX; //Maximo coordenada Y
	float minCoordY = INT_MAX; //Minimo coordenada X

	void setColorNoPermitido(string pColor);
	void removeColorNoPermitido(string pColor);
	NodoPais(string pIdPais, string pColorPais, string pCoordenadas); //Constructor.
	void insertarPaisVecino(NodoPais *pPaisVecino);					  //Inserta un pais colindante.
	vector<NodoPais *> getListaPaiseVecinos();						  //Retorna la lista de paises vecinos.
	bool isVecino(NodoPais *pNodoPais);								  //Verifica si un pais es vecino o no.
};

/**
 * @brief Construye un nevo objecto de tipo nodoPais
 * 
 * @param pIdPais 		
 * @param pColorPais 
 * @param pCoordenadas 
 */
NodoPais::NodoPais(string pIdPais, string pColorPais, string pCoordenadas)
{
	idPais = pIdPais;
	colorPais = pColorPais;
	setCoordenadas(pCoordenadas);
}

/**
 * @brief Inserta un pais vecino en el nodo actual y en el que se inserta.
 * 
 * @param pPaisVecino puntero del pais vecino.
 */
void NodoPais::insertarPaisVecino(NodoPais *pPaisVecino)
{
	string nombre = pPaisVecino->idPais;
	vector<NodoPais *> listaVecinos = pPaisVecino->getListaPaiseVecinos();
	if (find(listaVecinos.begin(), listaVecinos.end(), this) == listaVecinos.end())
		listaVecinos.push_back(this); //Inserta en pPaisVecino el pais actual.
	if (find(paisesVecinos.begin(), paisesVecinos.end(), pPaisVecino) == paisesVecinos.end())
		paisesVecinos.push_back(pPaisVecino); //Inserta el pais vecino a la lista.
}

/**
 * @brief Establece las coordenadas del nodo
 * 
 * @param pCoordenadas String con coordenadas del svg.
 */
void NodoPais::setCoordenadas(string pCoordenadas)
{
	StringParser *parser = new StringParser();
	string coordenadasParseadas = parser->parsearCoordenadas(pCoordenadas);
	vector<string> splitCoordenadas = parser->splitString(coordenadasParseadas, ' ');

	float valorX = 0;
	float valorY = 0;
	int tamStringCoordenadas = splitCoordenadas.size();
	for (int i = 0; i < tamStringCoordenadas; i++)
	{
		vector<string> splitXY = parser->splitString(splitCoordenadas[i], ',');
		valorX += stof(splitXY[0]);
		valorY += stof(splitXY[1]);
		coordsX.push_back((int)valorX);
		coordsY.push_back((int)valorY);
		asignarMinMaxCoordXY(valorX, valorY);
	}
}

void NodoPais::asignarMinMaxCoordXY(float pValorX, float pValorY)
{
	if (maxCoordX < pValorX)
		maxCoordX = pValorX;
	else if (minCoordX > pValorX)
		minCoordX = pValorX;
	if (maxCoordY < pValorY)
		maxCoordY = pValorY;
	else if (minCoordY > pValorY)
		minCoordY = pValorY;
}

/**
 * @brief Retorna el puntero de la lista de paises vecinos.
 * 
 * @return vector<NodoPais*> 
 */
vector<NodoPais *> NodoPais::getListaPaiseVecinos()
{
	return paisesVecinos;
}

/**
 * @brief Verifica si un NodoPais es vecino.
 * 
 * @param pNodoPais 
 * @return true 
 * @return false 
 */
bool NodoPais::isVecino(NodoPais *pNodoPais)
{
	vector<float> interCoordX;
	vector<float> interCoordY;
	sort(pNodoPais->coordsX.begin(), pNodoPais->coordsX.end());
	sort(pNodoPais->coordsY.begin(), pNodoPais->coordsY.end());
	sort(coordsX.begin(), coordsX.end());
	sort(coordsY.begin(), coordsY.end());
	std::set_intersection(pNodoPais->coordsX.begin(), pNodoPais->coordsX.end(), coordsX.begin(), coordsX.end(), back_inserter(interCoordX));
	std::set_intersection(pNodoPais->coordsY.begin(), pNodoPais->coordsY.end(), coordsY.begin(), coordsY.end(), back_inserter(interCoordY));
	if (!interCoordX.empty() && !interCoordY.empty())
	{
		return true;
	}
	return false;
}

/**
 * @brief Establece
 * 
 * @param pColor 
 */
void NodoPais::setColorNoPermitido(string pColor)
{
	int tamVector = paisesVecinos.size();
	for (int indiceVector = 0; indiceVector < tamVector; indiceVector++)
	{
		paisesVecinos[indiceVector]->coloresNoPermitidos.push_back(pColor);
	}
}

void NodoPais::removeColorNoPermitido(string pColor)
{
	int tamVector = paisesVecinos.size();
	for (int indiceVector = 0; indiceVector < tamVector; indiceVector++)
	{
		vector<string> listaColores = paisesVecinos[indiceVector]->coloresNoPermitidos;
		listaColores.erase(remove(listaColores.begin(),listaColores.end(),pColor),listaColores.end());
	}
}
#endif
