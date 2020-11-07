#ifndef NodoPais_h
#define NodoPais_h
/**
 * Clase Nodo que almacena los datos del SVG
 */
#include <vector>
#include <iostream>

using namespace std;
class NodoPais
{
private:
	string idPais;							//Nombre del pais.
	vector<NodoPais *> paisesColindates;		//Lista  de paises colindantes.
	string colorPais;						//Color del pais en hexadecimal.
	string coordenadas;						//String con las coordenadas del xml.
	bool visitado;							//Verifica si el nodo fue visitado.
	

public:
	NodoPais(string pIdPais, string pColorPais, string pCoordenadas);	//Constructor.
	void insertarPaisColindante(NodoPais *pPaisColindante);				//Inserta un pais colindante.
	void setColorPais(string pColorPais);								//Setea el color del pais.
	void setVisitado(bool pVisited);									//Setea si el pais ha sido visitado.
	void setIdPais(string pIdPais);										//Setea el id del pais.
	void setCoordenadas(string pCoordenas);								//Setea las coordenadas.
	string getColorPais();									        	//Obtiene el color del pais.
	bool isVisitado();						    						//Obtiene si el pais ha sido visitado.
	string getIdNombrePais();											//Obtiene el id del pais.
	vector<NodoPais *> getListaPaiseColindantes();						//Retorna la lista de paises colindantes.
	string getCoordenadas();											//Obtiene las coordenadas.
};
#endif