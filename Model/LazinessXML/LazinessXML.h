#ifndef LAZINESSXML_H
#define LAZINESSXML_H
#include "../XMLParser/XMLParser.h"

class LazinessXML{
    private:
        int timer;
        int tiempoMax; // Tiempo en el que se debe actualizar el xml
        XMLParser *parseador; //Parseador a utilizar cuando el tiempo llegue al max.

    public:
        // Constructor
        LazinessXML(int tiempoMax, XMLParser* pParseador);
        // Funcion que permite al xml cambiar los colores
        void escribirXML();
};

#endif /*LAZINESSXML_H*/