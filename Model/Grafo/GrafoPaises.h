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
	vector<NodoPais *> listaPaises;		  //Lista de los nodo pais.
	vector<Bucket *> bucketPaisesVecinos; //Buckets con nodos pais dentro de un rango.
public:
	GrafoPaises();															 		//Constructor de la clase
	void insertaNodo(string pIdPais, string pColorPais, string pCoordenadas);		//Inserta un nodo pais en el grafo.
	vector<NodoPais *> obtenerListaNodos();									  		//Obtiene la lista de nodos
	void insertarNodoBucket(NodoPais *pNodoPais);
	vector<Bucket *> obtenerBucket();
	void procesarPaisesVecinos(vector<int> pindicesBucket, NodoPais *pNodoPais);
};
/**
 * @brief Construye un objeto de tipo GrafoPaises
 * 
 */
GrafoPaises::GrafoPaises()
{
	int maxIndiceX = 0;
	int minIndiceX = 0;
	for (int indiceBucket = 0; indiceBucket < 4; indiceBucket++)
	{
		minIndiceX = maxIndiceX;
		maxIndiceX += 500;
		Bucket *nuevoBucket = new Bucket(minIndiceX, maxIndiceX);
		bucketPaisesVecinos.push_back(nuevoBucket);
	}
}

/**
 * @brief Inserta nodos en el grafo.
 * 
 * @param pIdPais String con el id del pais.
 * @param pColorPais String  con el color del pais.
 * @param pCoordenadas String con las coordenadas del svg.
 */
void GrafoPaises::insertaNodo(string pIdPais, string pColorPais, string pCoordenadas)
{
	NodoPais *nodoInsertar = new NodoPais(pIdPais, pColorPais, pCoordenadas);
	insertarNodoBucket(nodoInsertar);
	listaPaises.push_back(nodoInsertar);
}

/**
 * @brief Retorna la lista de nodos del grafo.
 * 
 * @return vector<NodoPais *> 
 */
vector<NodoPais *> GrafoPaises::obtenerListaNodos()
{
	return listaPaises;
}

/**
 * @brief 
 * 
 * @return vector<Bucket *> 
 */
vector<Bucket *> GrafoPaises::obtenerBucket()
{
	return bucketPaisesVecinos;
}

/**
 * @brief Inserta en el bucket correspondiente un pais.
 * 
 */
void GrafoPaises::insertarNodoBucket(NodoPais *pNodoPais)
{
	int tamVectorBucket = bucketPaisesVecinos.size();
	int maxCoordXPais = pNodoPais->getMaxCoordX();
	int minCoordXPais = pNodoPais->getMinCoordX();
	vector<int> BucketInsertado;
	for (int indiceBucket = 0; indiceBucket < tamVectorBucket; indiceBucket++)
	{
		Bucket *bucketActual = bucketPaisesVecinos.at(indiceBucket);
		if (bucketActual->isInRangeX(minCoordXPais, maxCoordXPais))
		{
			bucketActual->insertarPais(pNodoPais);
			BucketInsertado.push_back(indiceBucket);
		}
	}
	procesarPaisesVecinos(BucketInsertado,pNodoPais);
}

/**
 * @brief Agrega los paises vecinos de un NodoPais
 * 
 * @param pindicesBucket	Vector con los bucket donde fue insertado el NodoPais.
 * @param pNodoPais 		El nodo que fue insertado.
 */
void GrafoPaises::procesarPaisesVecinos(vector<int> pindicesBucket, NodoPais *pNodoPais)
{
	int tamIndicesBucket = pindicesBucket.size();		 //El tamaño del vector con la lista de indices donde se inserto el nodo pais.
	int indiceBucketActual;								 //El de BucketPaisesVecinos Actual.
	vector<NodoPais *> listaPaisesBucket;				 //Lista de paises del bucket actual.
	int tamListaPaisesBucket;							 //Tamaño de la lista de paises bucket.

	NodoPais *paisActualListaPaises;
	for (int indiceBucketInsertado = 0; indiceBucketInsertado < tamIndicesBucket; indiceBucketInsertado++)
	{
		indiceBucketActual = pindicesBucket.at(indiceBucketInsertado);			//Indice del bucket actual.
		Bucket *bucketActual = bucketPaisesVecinos.at(indiceBucketActual);		//Bucket Actual.
		listaPaisesBucket = bucketActual->getVectorPaises();					//Lista de paises del bucket actual.
		tamListaPaisesBucket = listaPaisesBucket.size();
		for (int indicePaisesBucket = 0; indicePaisesBucket < tamListaPaisesBucket; indicePaisesBucket++)
		{
			paisActualListaPaises = listaPaisesBucket.at(indicePaisesBucket);
			if (pNodoPais != paisActualListaPaises && pNodoPais->isVecino(paisActualListaPaises))
			{
				paisActualListaPaises->insertarPaisVecino(pNodoPais);
			}
		}
	}
}

#endif