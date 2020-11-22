#ifndef DIVIDEANDCONQUER_H
#define DIVIDEANDCONQUER_H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class DivideAndConquer : public ColoringAlgorithm {
    private:
        int cantidadColores;
    public:
        DivideAndConquer(GrafoPaises* PaisesAProcesar);
        vector<pair<string,string>> iniciarAlgoritmo(int);
        vector<pair<string,string>> dividirGrafo(vector<NodoPais*> vectorNodos);
};
#endif