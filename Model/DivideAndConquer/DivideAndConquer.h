#ifndef DIVIDEANDCONQUER.H
#define DIVIDEANDCONQUER.H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class DivideAndConquer : public ColoringAlgorithm {
    private:
        int cantidadColores;
    public:
        DivideAndConquer(GrafoPaises* PaisesAProcesar);
        void iniciarAlgoritmo(int);
        void dividirGrafo(vector<NodoPais*> vectorNodos);
        string verificarColorDisp(NodoPais* pPaisVerif);
        bool colorRepetido(list<string> lista, string color);
};
#endif "DIVIDEANDCONQUER.H"