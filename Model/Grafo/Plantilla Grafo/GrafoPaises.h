#ifndef GrafoPaises_hpp 
#define GrafoPaises_hpp 

#include "NodoPais.h"
#include <vector>
#include "../Paises Vecinos/Plantilla Paises Vecinos/Bucket.h"
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
};
#endif 