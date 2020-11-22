#include "DynamicProg.h"

DynamicProg::DynamicProg(GrafoPaises * PaisesAProcesar) : ColoringAlgorithm(PaisesAProcesar){}

void DynamicProg::inicarAlgoritmo(int pCantidadColores){
    this->cantidadColores = pCantidadColores;
}