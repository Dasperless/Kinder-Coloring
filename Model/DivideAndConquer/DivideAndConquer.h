#ifndef DIVIDEANDCONQUER_H
#define DIVIDEANDCONQUER_H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class DivideAndConquer : public ColoringAlgorithm {
    private:
        int cantidadColores;
    public:
        DivideAndConquer(GrafoPaises* PaisesAProcesar);
        vector<NodoPais*> iniciarAlgoritmo(int);
        vector<NodoPais*> dividirGrafo(vector<NodoPais*> vectorNodos);
};
#endif