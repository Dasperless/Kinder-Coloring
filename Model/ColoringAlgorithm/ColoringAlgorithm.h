#ifndef COLORINGALGORITHM_H
#define COLORINGALGORITHM_H

#include "../Grafo/GrafoPaises.h"
#include<iostream>
#include<list>

using namespace std;
class ColoringAlgorithm{
    private:
        GrafoPaises* PaisesSinColorear;
        GrafoPaises* PaisesColoreados;
        GrafoPaises* PaisesAProcesar;

    protected:
        list<string> colores;
    public:
        ColoringAlgorithm(GrafoPaises* PaisesAProcesar);
        GrafoPaises* getPaisesColoreados();
        GrafoPaises* getPaisesNoColoreados();
        GrafoPaises* getPaisesAProcesar();
        
};
#endif