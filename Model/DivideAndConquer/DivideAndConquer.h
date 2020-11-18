#ifndef DIVIDEANDCONQUER.H
#define DIVIDEANDCONQUER.H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class DivideAndConquer : public ColoringAlgorithm {
    public:
        DivideAndConquer(GrafoPaises* PaisesAProcesar);
        void iniciarAlgoritmo(int);
        void dividirGrafo(vector<NodoPais*> vectorNodos);
        string verificarColorDisp(NodoPais* pPaisVerif);
};
#endif "DIVIDEANDCONQUER.H"