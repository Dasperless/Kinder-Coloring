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
 * Recibe como parametro el puntero de un NodoPais
*/
	void GrafoPaises::insertaNodo(NodoPais* pNodo){
		listaPaises.push_back(pNodo);
	}

/**
 * Obtiene la lista de nodos del grafo.
 * Retorna un vector<NodoPais*> con todos los nodos paises del grafo.
*/
	vector<NodoPais *> GrafoPaises::obtenerListaNodos(){
		return listaPaises;
	}