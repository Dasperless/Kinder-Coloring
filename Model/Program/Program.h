#ifndef PROGRAM_H
#define PROGRAM_H

#include "../LazinessXML/LazinessXML.h"
#include "../Painter/Painter.h"
#include "../Sintetizador/Sintetizador.h"
#include "../XMLParser/XMLParser.h"
#include "../DivideAndConquer/DivideAndConquer.h"
#include <iostream>
using namespace std;

class Program{
    private:
        XMLParser * Parseador;// Parseador del svg      
        LazinessXML* Laziness;// Temporizador de laziness      
        DivideAndConquer *Divide;// Algoritmo utilizado
        Painter* pintor;// Clase encargada de pintar
        Sintetizador* sintetizador; // Clase encargada de sintetizar la informacion
    public:
        Program();	// Constructor
        void pintar(vector<pair<string,string>> vectorResuelto, GrafoPaises grafoAPintar); // Llama a la clase Painter para su funcion
        void PintarDivideXML(vector<pair<string,string>> paisesAPintar); // Indica al XML que paises y colores cambiar
        XMLParser* getParseador(); //Para obtener los datos del archivo parseado
        void iniciarPrograma();
};

#endif /*PROGRAM_H*/