#ifndef PAINTER_H
#define PAINTER_H
class Painter{
    private:
		vector<NodoPais*> listaPaises;								// Lista de paises a procesar para pintar
    public:
        Painter(vector<NodoPais*> pListaPaises);					// Constructor
        void pintar(vector<pair<string,string>> pPaisesPintar);		// Funcion para pintar los paises
        void sintetizarInfo();										// Sintetizar la informacion que se lguardara en el XML
};

Painter::Painter(vector<NodoPais*> pListaPaises){
	listaPaises = pListaPaises;
}

void Painter::pintar(vector<pair<string,string>> pPaisesPintar){
	int tamPaisesPintar = pPaisesPintar.size();
	for(int indicePaisesPintar = 0; indicePaisesPintar < tamPaisesPintar; indicePaisesPintar++){
	}
}
#endif
