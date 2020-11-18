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
        /*Verificar que tenga colindantes, si los tiene, verificar si ya tienen algun color
        de no tener color disponible a asignar, dejar en blanco.
        */


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

    }
}