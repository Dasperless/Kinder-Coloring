#ifndef Bucket_h
#define Bucket_h

#include "../Grafo/NodoPais.h"
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
	vector<NodoPais*> getBucketPaises();
	void insertarPais(NodoPais *pPaisInsertar);
	bool isInRangeX(int pMaxCoordX, int pMinCoordX);
	bool isInRangeY(int pMaxCoordY, int pMinCoordY);
};
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
	return maxRangoX;
}
int Bucket::getMinRangoY(){
	return minRangoY;
}
vector<NodoPais*> Bucket::getBucketPaises(){
	return paises;
}
void Bucket::insertarPais(NodoPais *pPaisInsertar){
	paises.push_back(pPaisInsertar);
}

bool Bucket::isInRangeX(int pMaxCoordX, int pMinCoordX){
	return (pMinCoordX >= minRangoX && pMaxCoordX <= maxRangoX);
}

bool Bucket::isInRangeY(int pMaxCoordY, int pMinCoordY){
	return (pMinCoordY >= minRangoY && pMaxCoordY <= maxRangoY);
}

#endif