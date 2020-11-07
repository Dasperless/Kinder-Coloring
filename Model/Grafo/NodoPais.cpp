
/**
 * Implementacion de la clase nodo.
 */
#include "Plantilla Grafo/NodoPais.h"

/**
 * Constructor de la clase NodoPais
*/
NodoPais::NodoPais(string pIdPais, string pColorPais, string ){
	setIdPais(pIdPais);
	setColorPais(pColorPais);
}	
/**
 * Inserta Los paises colindantes en ambas listas.
 * Recibe un puntero del pais colindante.
 */
	void NodoPais::insertarPaisColindante(NodoPais* pPaisColindante){
		pPaisColindante->getListaPaiseColindantes().push_back(this);	//Inserta en pPaiscolindante el pais actual.
		paisesColindates.push_back(pPaisColindante);					//Inserta el pais colindante a la lista.
	}

/**
 * Setea el color del pais
 * Recibe como parametro el color del pais, debe ser hexadecimal.
 */	
	void NodoPais::setColorPais(string pColorPais){
		colorPais = pColorPais;
	}

/**
 * Setea el nombre ID de un pais
 * Recibe como parametro nombre del pais.
 */
	void NodoPais::setIdPais(string pIdPais){
		idPais = pIdPais;
	}

/**
 * Setea si el nodo ha sido visitado
 * Recibe como parametro un booleano, True si ha sido visidado
 * False en caso contrario.
 */
	void NodoPais::setVisitado(bool pVisitado){
		visitado = pVisitado;
	}

/**
 * Setea las coordenadas del nodo.
 * Recibe como parametro un string con las coordenadas.
 */
	void NodoPais::setCoordenadas(string pCoordenadas){
		coordenadas = pCoordenadas;
	}    
/**
 *Retorna un puntero de la lista de paises colindantes. 
 */
	vector<NodoPais*> NodoPais::getListaPaiseColindantes(){
		return paisesColindates;
	}
/**
 *Retorna el id nombre del pais 
 */	
	string NodoPais::getIdNombrePais(){
		return idPais;
	}

/**
 *Retorna True si el pais ha sido visitado, False en caso contrario.
 */	
	bool NodoPais::isVisitado(){
		return visitado;
	}

/**
 *Retorna el color del pais.
 */	
	string NodoPais::getColorPais(){
		return colorPais;
	}

/**
 *Retorna el color del pais.
 */	
	string NodoPais::getCoordenadas(){
		return coordenadas;
	}    