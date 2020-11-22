#ifndef DYNAMICPROG_H
#define DYNAMICPROG_H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class DynamicProg : public ColoringAlgorithm {
    private:
        int cantidadColores;
    public:
        DynamicProg(GrafoPaises* pPaisesAprocesar);
        void inicarAlgoritmo(int cantidadColores);

};
#endif