#ifndef PAINTER_H
#define PAINTER_H

class Painter{

    private:
        // Lista de paises a procesar para pintar
        int listaPaises;
    public:
        // Constructor
        Painter();
        // Funcion para pintar los paises
        void pintar();
        // Sintetizar la informacion que se llevara al XML
        void sintetizarInfo();
};
#endif
