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
	void procesarPaisesVecinos(vector<Bucket*> pListaBuckets, NodoPais *pNodoPais);
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
	int maxCoordXPais = pNodoPais->maxCoordX;
	int minCoordXPais = pNodoPais->minCoordX;
	string nombre = pNodoPais->idPais;
	vector<Bucket*>  BucketInsertado;
	for (auto bucketActual: bucketPaisesVecinos)
	{
		if (bucketActual->isInRangeX(minCoordXPais, maxCoordXPais))
		{
			bucketActual->insertarPais(pNodoPais);
			BucketInsertado.push_back(bucketActual);
		}
	}
	procesarPaisesVecinos(BucketInsertado,pNodoPais);
}

/**
 * @brief Agrega los paises vecinos de un NodoPais
 * 
 * @param pListaBuckets	Vector con los bucket donde fue insertado el NodoPais.
 * @param pNodoPais 		El nodo que fue insertado.
 */
void GrafoPaises::procesarPaisesVecinos(vector<Bucket*>  pListaBuckets, NodoPais *pNodoPais)
{
	for(auto listaPaises:pListaBuckets){
		for(auto paisActual:listaPaises->getVectorPaises()){
			if (pNodoPais != paisActual && pNodoPais->isVecino(paisActual))
			{
				paisActual->insertarPaisVecino(pNodoPais);
				pNodoPais->insertarPaisVecino(paisActual);
			}
		}
	}
}

#endif