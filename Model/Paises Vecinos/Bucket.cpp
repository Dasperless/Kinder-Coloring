#include "Plantilla Paises Vecinos/Bucket.h"
Bucket::Bucket(int pMaxRangoX, int pMinRangoX, int pMaxRangoY, int pMinRangoY)
{
	maxRangoX = pMaxRangoX;
	minRangoX = pMinRangoX;
	maxRangoY = pMaxRangoY;
	minRangoY = pMinRangoY;
}

int Bucket::getMaxRangoX(){
	return maxRangoX;
}
int Bucket::getMaxRangoY(){
	return maxRangoY;
}
int Bucket::getMinRangoX(){
	return maxRangoX
}
int Bucket::getMinRangoY(){
	return minRangoY;
}

void Bucket::insertarPais(NodoPais *pPaisInsertar){
	paises.push_back(pPaisInsertar);
}

bool Bucket::isInRange(int pMaxCoord, int pMinCoord){
	return (pMaxCoord>=minRangoX && pMinCoord<=maxRangoX);
}

