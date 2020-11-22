#include "ColoringAlgorithm.h"

ColoringAlgorithm::ColoringAlgorithm(GrafoPaises* pPaisesAProcesar){
    this->PaisesColoreados= new GrafoPaises();
    this->PaisesSinColorear= new GrafoPaises();
    this->PaisesAProcesar = pPaisesAProcesar;
    this->colores = {"#FF0000","#0000FF","#00FF00","#FFFF00","#00FFFF","#FF00FF","morado","celeste","negro","rosado","dorado"};
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