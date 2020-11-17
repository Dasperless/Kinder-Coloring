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
	bool isInRange(int pMaxCoord, int pMinCoord);
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

bool Bucket::isInRange(int pMaxCoord, int pMinCoord){
	return (pMaxCoord>=minRangoX && pMinCoord<=maxRangoX);
}


#endif