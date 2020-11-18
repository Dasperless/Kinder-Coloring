#include "ColoringAlgorithm.h"

ColoringAlgorithm::ColoringAlgorithm(GrafoPaises* pPaisesAProcesar){
    this->PaisesColoreados= new GrafoPaises();
    this->PaisesSinColorear= new GrafoPaises();
    this->PaisesAProcesar = pPaisesAProcesar;
    this->colores = {"rojo","azul","verde","amarillo","cafe","naranja","morado","celeste","negro","rosado","dorado"};
}

GrafoPaises* ColoringAlgorithm::getPaisesColoreados(){
    return this->PaisesColoreados;
}

GrafoPaises* ColoringAlgorithm::getPaisesNoColoreados(){
    return this->PaisesSinColorear;
}

GrafoPaises* ColoringAlgorithm::getPaisesAProcesar(){
    return this->PaisesAProcesar;
}