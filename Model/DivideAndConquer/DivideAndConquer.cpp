#include "DivideAndConquer.h"

DivideAndConquer::DivideAndConquer(GrafoPaises* PaisesAProcesar) : ColoringAlgorithm(PaisesAProcesar){}

void DivideAndConquer::iniciarAlgoritmo(int pCantidadColores)
{
    GrafoPaises* paisesAprocesar = this->getPaisesAProcesar();
    vector<NodoPais*> vectorPaises = paisesAprocesar->obtenerListaNodos();
    dividirGrafo(vectorPaises);
}

void DivideAndConquer::dividirGrafo(vector<NodoPais*> vectorNodos)
{
    if(vectorNodos.size()==1)
    {
        NodoPais* pais = vectorNodos.front();

        string colorDisp = verificarColorDisp(pais);
        if(colorDisp!="fill:#f2f2f2;fill-rule:evenodd")
        {
            pais->setColorPais(colorDisp);
            this->getPaisesColoreados()->obtenerListaNodos().push_back(pais);
        }
        else{
            this->getPaisesNoColoreados()->obtenerListaNodos().push_back(pais);
        }

    }
    else
    {
        size_t const half_size = vectorNodos.size() / 2;
        vector<NodoPais*> mitadIni(vectorNodos.begin(), vectorNodos.begin() + half_size);
        vector<NodoPais*> mitadFin(vectorNodos.begin() + half_size, vectorNodos.end());
        dividirGrafo(mitadIni);
        dividirGrafo(mitadFin);
    }
}

string DivideAndConquer::verificarColorDisp(NodoPais* pPaisVerif)
{
    //Lista Vacia, color a utilizar va a ser el primero.
    if(this->getPaisesColoreados()->obtenerListaNodos().empty())
    {
        return this->colores.front();
    }
    else
    {   

        list<string> coloresUtilizados = {}; // Colores utilizados por los colindantes

        // Obtener los colores ya utilizados por los paises colindantes
        for(auto paisColidante : pPaisVerif->getListaPaiseVecinos())
        {
            for(auto paisColoreado : getPaisesColoreados()->obtenerListaNodos())
            {
                if(paisColidante->getIdNombrePais()==paisColoreado->getIdNombrePais())
                {
                    // Si el color no esta en la lista de utilizados, se agrega
                    if(!colorRepetido(coloresUtilizados,paisColoreado->getColorPais()))
                    {
                        coloresUtilizados.push_back(paisColoreado->getColorPais());
                    }
                }
            }
        }
        // Si todos los colores disponibles ya estan utilizados se deja en blanco
        if(coloresUtilizados.size()==cantidadColores){
            return "fill:#f2f2f2;fill-rule:evenodd";
        }
        // Si hay colores disponibles, se elige el primer disponible
        else{
            int contador=0;
            for(auto x : colores){
                if(contador == cantidadColores) break;
                else if (!colorRepetido(coloresUtilizados,x)) return x;
                contador ++;
            }
        }
        
    }
}
// Funcion para ver si un color ya existe en una lista
bool DivideAndConquer::colorRepetido(list<string> coloresUtilizados, string color){
    for(auto x:coloresUtilizados){
        if(x==color){
            return true;
        }
    }
    return false;
}