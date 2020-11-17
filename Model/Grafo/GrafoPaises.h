#ifndef GrafoPaises_hpp 
#define GrafoPaises_hpp 

#include "NodoPais.h"
#include <vector>
#include "../Paises Vecinos/Bucket.h"
/**
 *Clase que contiene los nodos que representan los paises del svg .
*/
class GrafoPaises
{
private:
	vector<NodoPais *> listaPaises;			//Lista de los nodo pais.
	vector<Bucket *> bucketPaisesVecinos;		//Buckets con nodos pais dentro de un rango.
public:
	GrafoPaises();															//Constructor de la clase
	void insertaNodo(string pIdPais,string pColorPais,string pCoordenadas);	//Inserta un nodo pais en el grafo.
	vector<NodoPais *> obtenerListaNodos();									//Obtiene la lista de nodos
	void insertarNodoBucket(NodoPais *pNodoPais);
	vector<Bucket *> obtenerBucket();
	
};
/**
 * @brief Construye un objeto de tipo GrafoPaises
 * 
 */
GrafoPaises::GrafoPaises() {
	int maxIndiceX = 0;
	int maxIndiceY = 0;
	int minIndiceX = 0;
	int minIndiceY = 0;
	for(int i = 0; i < 4; i++){
		minIndiceX = maxIndiceX;
		minIndiceY = maxIndiceY;
		maxIndiceX += 500;
		maxIndiceY += 250;
		Bucket *nuevoBucket = new Bucket(maxIndiceX, minIndiceX, maxIndiceY, minIndiceY);
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
 * @brief 
 * 
 * @return vector<Bucket *> 
 */
vector<Bucket *> GrafoPaises::obtenerBucket(){
	return bucketPaisesVecinos;
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
			if(bucketActual->isInRangeX(maxCoordXPais,minCoordXPais) || bucketActual->isInRangeY(maxCoordYPais,minCoordYPais)){
				bucketActual->insertarPais(pNodoPais);
			}
		}
	}

#endif 