
/**
 * Clase Nodo que almacena los datos del SVG
 */
#include <string.h>
#include <list>
using namespace std;
class NodoPais
{
private:
	string  IdPais;                     //Nombre del pais.
	list<NodoPais*> PaisesColindates;	//Lista  de paises colindantes.
	string ColorPais;					//Color del pais en hexadecimal.
	
public:
	NodoPais(string pIdPais, string pColorPais) {
		setIdPais(pIdPais);
		setColorPais(pColorPais);
	}

/**
 * Inserta Los paises colindantes en ambas listas.
 * Recibe un puntero del pais colindante.
 */
	void insertarPaisColindante(NodoPais* pPaisColindante){
		pPaisColindante->getListaPaiseColindantes().push_front(this);
		PaisesColindates.push_front(pPaisColindante);					//Inserta el pais colindante a la lista
	}

/**
 * Setea el color del pais
 * Recibe como parametro el color del pais, debe ser hexadecimal.
 */	
	void setColorPais(string pColorPais){
		ColorPais = pColorPais;
	}

/**
 * Setea el nombre ID de un pais
 * Recibe como parametro nombre del pais.
 */
	void setIdPais(string pIdPais){
		IdPais = pIdPais;
	}

/**
 *Retorna un puntero de la lista de paises colindantes. 
 */
	list<NodoPais*> getListaPaiseColindantes(){
		return PaisesColindates;
	}
/**
 *Retorna el id nombre del pais 
 */	
	string getIdNombrePais(){
		return IdPais;
	}
/**
 *Retorna el color del pais.
 */	
	string getColorPais(){
		return ColorPais;
	}
};