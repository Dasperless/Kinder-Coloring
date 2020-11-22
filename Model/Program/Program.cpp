#include "Program.h"
#include <iostream>
using namespace std;

Program::Program(){
    this->Parseador= new XMLParser("ArchivosXML/world.svg");
    this->Parseador->iniciarParse();
    //this->Laziness = new LazinessXML(pTiempoActualizar, this->Parseador);
    this->Divide = new DivideAndConquer(Parseador->obtenerGrafo());
    cout<<Parseador->obtenerGrafo()->obtenerListaNodos().size()<<endl;
    //this->sintetizador = new Sintetizador();
    //this->pintor = new Painter();
}

void Program::iniciarPrograma(){
    int cantidadColores;
    cout<<"Digite la cantidad de colores a usar: "<<endl;
    cin>>cantidadColores;
    vector<pair<string,string>> vectorPaises = Divide->iniciarAlgoritmo(cantidadColores);
    this->PintarDivideXML(vectorPaises);
    cout<<"Paises sin colorear: "<<Divide->getPaisesNoColoreados()->obtenerListaNodos().size()<<endl;
}

void Program::PintarDivideXML(vector<pair<string,string>> paiseAPintar){
    for(auto pais : paiseAPintar){
        this->Parseador->ModificarColor(pais.first,pais.second,"0");
    }
}