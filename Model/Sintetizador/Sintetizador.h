#ifndef SINTETIZADOR_H
#define SINTETIZADOR_H

#include "../DataMap/DataMap.h"
class Sintetizador{
    private:
        // Estructura que almacena los datos de los paises a los cuales se les cambio el color
        DataMap* dataMap;
    public:
        // Constructor
        Sintetizador();
        // Funcion que crea la estructura a pasar al XML.
        void crearEstructura();
};

#endif "SINTETIZADOR_H"