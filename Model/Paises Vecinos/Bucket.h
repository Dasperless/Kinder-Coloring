#ifndef Bucket_h
#define Bucket_h

#include "../Grafo/NodoPais.h"
class Bucket
{
private:
	int maxRangoX = 0;			//Rango Maximo
	int minRangoX = 0;
	vector<NodoPais*> paises;
	
public:
	Bucket(int pMaxRangoX, int pMinRangoX);
	int getMaxRangoX();
	int getMinRangoX();
	int getMaxRangoY();
	int getMinRangoY();	
	vector<NodoPais*> getBucketPaises();
	void insertarPais(NodoPais *pPaisInsertar);
	bool isInRangeX(int pMaxCoordX, int pMinCoordX);
};
Bucket::Bucket(int pMinRangoX,int pMaxRangoX)
{
	minRangoX = pMinRangoX;
	maxRangoX = pMaxRangoX;
}

int Bucket::getMaxRangoX(){
	return maxRangoX;
}
int Bucket::getMinRangoX(){
	return maxRangoX;
}
vector<NodoPais*> Bucket::getBucketPaises(){
	return paises;
}
void Bucket::insertarPais(NodoPais *pPaisInsertar){
	paises.push_back(pPaisInsertar);
}

bool Bucket::isInRangeX(int pMinCoordX, int pMaxCoordX){
	return ((pMinCoordX >= minRangoX && pMinCoordX <= maxRangoX) || pMaxCoordX <= maxRangoX);
}

#endif