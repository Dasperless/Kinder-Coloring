#ifndef Bucket_h
#define Bucket_h

#include "../../Grafo/Plantilla Grafo/NodoPais.h"
class Bucket
{
private:
	int maxRangoX = 0;
	int minRangoX = 0;
	int maxRangoY = 0;
	int minRangoY = 0;
	vector<NodoPais*> paises;
	
public:
	Bucket(int pMaxRangoX, int pMinRangoX, int pMaxRangoY, int pMinRangoY);
	int getMaxRangoX();
	int getMinRangoX();
	int getMaxRangoY();
	int getMinRangoY();	
	void insertarPais(NodoPais *pPaisInsertar);
	bool isInRange(int pMaxCoord, int pMinCoord);
};
#endif