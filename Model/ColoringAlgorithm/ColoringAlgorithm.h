#ifndef COLORINGALGORITHM_H
#define COLORINGALGORITHM_H

#include "../Grafo/GrafoPaises.h"
#include<iostream>
#include<list>

using namespace std;
class ColoringAlgorithm{
    private:
        GrafoPaises* PaisesSinColorear;
        int PaisesColoreados;
        GrafoPaises* PaisesAProcesar;

    protected:
        list<string> colores;
    public:
        ColoringAlgorithm(GrafoPaises* PaisesAProcesar);
        int getPaisesColoreados();
        GrafoPaises* getPaisesNoColoreados();
        GrafoPaises* getPaisesAProcesar();
        
};
#endif