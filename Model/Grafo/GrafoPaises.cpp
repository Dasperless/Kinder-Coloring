/**
 * Implementacion de la clase GrafoPaises.
*/
#include "Plantilla Grafo/GrafoPaises.h"
/**
 * Constructor del grafo.
 * No recibe ningun parametro.
*/
	GrafoPaises::GrafoPaises() {}

/**
 * Inserta nodos en el grafo.
 * Recibe como parametro el id, el color y las coordenadas del pais.
*/
	void GrafoPaises::insertaNodo(string pIdPais,string pColorPais,string pCoordenadas){
        NodoPais *nodoInsertar = new NodoPais(pIdPais, pColorPais, pCoordenadas);
		listaPaises.push_back(nodoInsertar);
	}

/**
 * Obtiene la lista de nodos del grafo.
 * Retorna un vector<NodoPais*> con todos los nodos paises del grafo.
*/
	vector<NodoPais *> GrafoPaises::obtenerListaNodos(){
		return listaPaises;
	}