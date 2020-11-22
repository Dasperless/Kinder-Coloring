#include "Program.h"

Program::Program(int pTiempoActualizar){
    this->parseador= new XMLParser("../ArchivosXML/world.svg");
    this->Laziness = new LazinessXML(pTiempoActualizar, this->parseador);
    // this->pintor = new Painter();
    this->sintetizador = new Sintetizador();
}




