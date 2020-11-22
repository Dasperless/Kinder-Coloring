#ifndef SINTETIZADOR_H
#define SINTETIZADOR_H
#include <vector>
class Sintetizador
{
private:
	vector<pair<string,string>>dataStructure;
public:
	Sintetizador();										// Constructor
	void crearEstructura(vector<NodoPais *> pMemMap);	// Funcion que crea la estructura a pasar al XML{
};
/**
 * @brief Construye un objeto de tipo sintetizador
 * 
 */
Sintetizador::Sintetizador() {}

/**
 * @brief Crea una vector que contiene un hash con el id del pais y el color. 
 * 
 * @param pMemMap La estructura con los paises a cambiar.
 */
void Sintetizador::crearEstructura(vector<NodoPais *> pMemMap)
{
	int tamListaPaises = pMemMap.size();	//Tamaño del vector con los paises.
	string nombre = "";						//El nombre del pais.
	string color = "";						//El color del pais.
	NodoPais *paisActual = nullptr;			//El pais actual.
	for (int indiceVectorPaises = 0; indiceVectorPaises < tamListaPaises; indiceVectorPaises++)
	{
		paisActual = pMemMap.at(indiceVectorPaises);				//EL pais actual a sintetizar.
		nombre = paisActual->idPais;						//El nombre del pais.
		color = paisActual->colorPais;							//El color del pais.
		dataStructure.push_back(pair<string,string>(nombre,color));	//Se establece el color y se almacena en el hash.
	}
}
#endif