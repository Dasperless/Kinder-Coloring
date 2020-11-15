#ifndef NodoPais_h
#define NodoPais_h

#include <vector>
#include <string>
/**
 * Clase Nodo que almacena los datos del SVG
 */
using namespace std;
class NodoPais
{
private:
	string idPais;							//Nombre del pais.
	vector<NodoPais *> paisesColindates;	//Vector de paises colindantes.
	vector<float> coordsX;                  //Vector con las cordenadas X.
	vector<float> coordsY;                  //Vector con las coordenadas Y.
	float maxCoordX = 0;					//Maximo coordenada X
	float maxCoordY = 0;					//Minimo coordenada Y
	float minCoordX = INT_MAX;				//Maximo coordenada Y
	float minCoordY = INT_MAX;				//Minimo coordenada X
	string colorPais;						//Color del pais en hexadecimal.
	bool visitado;							//Verifica si el nodo fue visitado.
	
public:
	NodoPais(string pIdPais, string pColorPais, string pCoordenadas);	//Constructor.
	void insertarPaisColindante(NodoPais *pPaisColindante);				//Inserta un pais colindante.
	void setColorPais(string pColorPais);								//Setea el color del pais.
	void setVisitado(bool pVisited);									//Setea si el pais ha sido visitado.
	void setIdPais(string pIdPais);										//Setea el id del pais.
	void setCoordenadas(string pCoordenas);								//Setea las coordenadas.
	void asignarMinMaxCoordXY(float pValorX, float pValorY);
	string getColorPais();												//Obtiene el color del pais.
	bool isVisitado();						    						//Obtiene si el pais ha sido visitado.
	string getIdNombrePais();											//Obtiene el id del pais.
	vector<NodoPais *> getListaPaiseColindantes();						//Retorna la lista de paises colindantes.
	vector<float> getCoordenadasX();									//Obtiene las coordenadas.
	vector<float> getCoordenadasY();
	float getMaxCoordX();
	float getMaxCoordY();
	float getMinCoordX();
	float getMinCoordY();

};
#endif
