#ifndef PROGRAM_H
#define PROGRAM_H

#include "../LazinessXML/LazinessXML.h"
#include "../Painter/Painter.h"
#include "../Sintetizador/Sintetizador.h"
#include "../XMLParser/XMLParser.h"
#include <iostream>
using namespace std;

class Program{
    private:
        
        XMLParser * parseador;// Parseador del svg      
        LazinessXML* Laziness;// Temporizador de laziness      
        int algoritmo;// Algoritmo utilizado
        Painter* pintor;// Clase encargada de pintar
        Sintetizador* sintetizador; // Clase encargada de sintetizar la informacion
    public:
        Program(int tiempoActualizar);	// Constructor
        void pintar(); // Llama a la clase Painter para su funcion
        void escribirXML(); // Indica al XML que paises y colores cambiar
        XMLParser* getParseador(); //Para obtener los datos del archivo parseado
};

#endif "PROGRAM_H"