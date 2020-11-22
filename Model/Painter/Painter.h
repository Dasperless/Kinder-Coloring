#ifndef PAINTER_H
#define PAINTER_H
class Painter{
    private:								// Lista de paises a procesar para pintar
    public:
        Painter();					// Constructor
        void pintar(vector<pair<string,string>> pPaisesPintar, GrafoPaises grafoAPintar);		// Funcion para pintar los paises
        void sintetizarInfo();										// Sintetizar la informacion que se lguardara en el XML
};

Painter::Painter(){}

void Painter::pintar(vector<pair<string,string>> pPaisesPintar, GrafoPaises grafoAPintar){
}
#endif
