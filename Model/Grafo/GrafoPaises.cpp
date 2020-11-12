/**
 * Implementacion de la clase GrafoPaises.
*/
#include "Plantilla Grafo/GrafoPaises.h"

/**
 * @brief Construye un objeto de tipo GrafoPaises
 * 
 */
GrafoPaises::GrafoPaises() {}

/**
 * 
 * Recibe como parametro el id, el color y las coordenadas del pais.
*/

/**
 * @brief Inserta nodos en el grafo.
 * 
 * @param pIdPais String con el id del pais.
 * @param pColorPais String  con el color del pais.
 * @param pCoordenadas String con las coordenadas del svg.
 */
	void GrafoPaises::insertaNodo(string pIdPais,string pColorPais,string pCoordenadas){
		NodoPais *nodoInsertar = new NodoPais(pIdPais, pColorPais, pCoordenadas);
		listaPaises.push_back(nodoInsertar);
	}

/**
 * @brief Retorna la lista de nodos del grafo.
 * 
 * @return vector<NodoPais *> 
 */
	vector<NodoPais *> GrafoPaises::obtenerListaNodos(){
		return listaPaises;
	}