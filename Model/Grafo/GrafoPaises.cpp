/**
 * Implementacion de la clase GrafoPaises.
*/
#include "Plantilla Grafo/GrafoPaises.h"

/**
 * @brief Construye un objeto de tipo GrafoPaises
 * 
 */
GrafoPaises::GrafoPaises() {
	int indiceX = 0;
	int indiceY = 0;
	for(int i = 0; i < 4; i++){
		int tempIndiceX = indiceX;
		int tempIndiceY = indiceX;
		indiceX += 500;
		indiceY += 250;
		Bucket *nuevoBucket = new Bucket(tempIndiceX, indiceX, tempIndiceY,indiceY);
		bucketPaisesVecinos.push_back(nuevoBucket);
	}
}

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
		insertarNodoBucket(nodoInsertar);
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

/**
 * @brief Inserta en el bucket correspondiente un pais.
 * 
 */
	void GrafoPaises::insertarNodoBucket(NodoPais *pNodoPais){
		int tamVectorBucket = bucketPaisesVecinos.size();
		int maxCoordXPais = pNodoPais->getMaxCoordX();
		int minCoordXPais = pNodoPais->getMinCoordX();
		int maxCoordYPais = pNodoPais->getMaxCoordY();
		int minCoordYPais = pNodoPais->getMinCoordY();

		for(int indiceBucket = 0; indiceBucket < tamVectorBucket; indiceBucket++){
			Bucket *bucketActual = bucketPaisesVecinos.at(indiceBucket);
			if(bucketActual->isInRange(maxCoordXPais,minCoordXPais) && bucketActual->isInRange(maxCoordYPais,minCoordYPais)){
				bucketActual->insertarPais(pNodoPais);
			}
		}
	}

