#ifndef SINTETIZADOR_H
#define SINTETIZADOR_H

#include <unordered_map>
#include <vector>
class Sintetizador
{
private:
	vector<unordered_map<string, string>> dataStructure;

public:
	Sintetizador();									  // Constructor
	void crearEstructura(vector<NodoPais *> pMemMap); // Funcion que crea la estructura a pasar al XML{
};

Sintetizador::Sintetizador() {}
void Sintetizador::crearEstructura(vector<NodoPais *> pMemMap)
{
	int tamListaPaises = pMemMap.size();
	string nombre = "";
	string color = "";
	NodoPais *paisActual = nullptr;
	for (int indiceVectorPaises = 0; indiceVectorPaises < tamListaPaises; indiceVectorPaises++)
	{
		unordered_map<string, string> hashEstructura;
		paisActual = pMemMap.at(indiceVectorPaises);
		nombre = paisActual->getIdNombrePais();
		color = paisActual->getColorPais();
		hashEstructura["color"] = color;
		hashEstructura["nombre"] = nombre;
		dataStructure.push_back(hashEstructura);
	}
}
#endif