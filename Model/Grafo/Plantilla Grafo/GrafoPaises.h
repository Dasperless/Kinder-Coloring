#ifndef GrafoPaises_hpp 
#define GrafoPaises_hpp 
/**
 *Clase que contiene los nodos que representan los paises del svg .
*/
#include "NodoPais.h"
#include <vector>
class GrafoPaises
{
private:
	vector<NodoPais *> listaPaises;			//Lista de los nodo pais.
public:
	GrafoPaises();							//Constructor de la clase
	void insertaNodo(NodoPais* pNodoPais);	//Inserta un nodo pais en el grafo.
	vector<NodoPais *> obtenerListaNodos();	//Obtiene la lista de nodos
};
#endif 