#ifndef Bucket_h
#define Bucket_h

#include "../Grafo/NodoPais.h"
class Bucket
{
private:
	int maxRangoX = 0;			//Rango maximo del bucket.
	int minRangoX = 0;			//Rango minimo del bucket.
	vector<NodoPais*> paises;
	
public:
	Bucket(int pMaxRangoX, int pMinRangoX);					//Constructor del objeto
	int getMaxRangoX();										//Obtiene el rango maximo en x del Bucket.
	int getMinRangoX();										//Obtiene el rango minimo en x del bucket
	vector<NodoPais*> getVectorPaises();					//Obtiene un vector de los paises dentro del rango del bucket.
	void insertarPais(NodoPais *pPaisInsertar);				//Inserta un nuevo pais al vector de paises.
	bool isInRangeX(int pMaxCoordX, int pMinCoordX);		//Verifica si un pais se encuentra en el rango del Bucket.
};

/**
 * @brief Construye un nuevo objeto de tipo Bucket.
 * 
 * @param pMinRangoX 	Rango minimo en X.
 * @param pMaxRangoX 	Rango maximo en X.
 */
Bucket::Bucket(int pMinRangoX,int pMaxRangoX)
{
	minRangoX = pMinRangoX;
	maxRangoX = pMaxRangoX;
}

/**
 * @brief Obtiene el rango maximo en x del bucket.
 * 
 * @return int El rango maximo del bucket.
 */
int Bucket::getMaxRangoX(){
	return maxRangoX;
}


/**
 * @brief Obtiene el rango minimo en x del bucket.
 * 
 * @return int 	El rango minimo del bucket
 */
int Bucket::getMinRangoX(){
	return maxRangoX;
}

/**
 * @brief Obtiene un vector con los paises que pertenecen al bucket.
 * 
 * @return vector<NodoPais*> 	Paises dentro del bucket.
 */
vector<NodoPais*> Bucket::getVectorPaises(){
	return paises;
}

/**
 * @brief Inserta un pais dentro del bucket.
 * 
 * @param pPaisInsertar 	EL pais a insertar.
 */
void Bucket::insertarPais(NodoPais *pPaisInsertar){
	paises.push_back(pPaisInsertar);
}

/**
 * @brief Verifica si las coordenadas de un pais se encuentran dentro del rango del bucket.
 * 
 * @param pMinCoordX 	El rango minimo de coordendas en el eje X.
 * @param pMaxCoordX 	El rango maximo de coordendas en el eje X.
 * @return true 		El pais esta dentro del rango del bucket.
 * @return false 		El pais no se encuentra dentro del rango del bucket.
 */
bool Bucket::isInRangeX(int pMinCoordX, int pMaxCoordX){
	return ((pMinCoordX >= minRangoX && pMinCoordX <= maxRangoX) || pMaxCoordX <= maxRangoX);
}

#endif