#include "DivideAndConquer.h"
#include "../Grafo/NodoPais.h"
DivideAndConquer::DivideAndConquer(GrafoPaises* PaisesAProcesar) : ColoringAlgorithm(PaisesAProcesar){}


/**
 * @brief Inicia el algoritmo de Divide-and-Conquer
 * 
 * @param pCantidadColores cantidad de colores que se utilizaran para pintar
*/
vector<NodoPais*> DivideAndConquer::iniciarAlgoritmo(int pCantidadColores)
{   
    this->cantidadColores = pCantidadColores;
    GrafoPaises* paisesAprocesar = this->getPaisesAProcesar();
    vector<NodoPais*> vectorPaises = paisesAprocesar->obtenerListaNodos();
    vector<NodoPais*> vectorResuelto = dividirGrafo(vectorPaises);
    return vectorResuelto;    
}

/**
 * @brief Divide el vector hasta tener solo 1 nodo
 * 
 * @param vectorNodos es el vector el cual se esta dividiendo
*/
vector<NodoPais*> DivideAndConquer::dividirGrafo(vector<NodoPais*> vectorNodos)
{
    if(vectorNodos.size()==1) //Caso de parada
    {
        NodoPais* pais = vectorNodos.front(); // Pais a evaluar

        int contador =0; // Contador de parada
        for(auto color: colores){ // Recorre cada color en la lista para verificar cual color colocar
            if(contador == cantidadColores){
                break;
            }
            contador++;
            // Se verifica si el color ya ha sido usado en paises vecinos
            if((find(pais->coloresNoPermitidos.begin(), pais->coloresNoPermitidos.end(), color) == pais->coloresNoPermitidos.end())){
                pais->colorPais=color; // Asignar el color si no ha sido usado
                pais->setColorNoPermitido(color); // Asigar el color como no permitido a los paises vecinos
                break;
            }
        }
        if(pais->colorPais=="fill:#f2f2f2;fill-rule:evenodd"){ // Si no hay color disponible se deja el original y se retorna un vector vacio
            this->getPaisesNoColoreados()->obtenerListaNodos().push_back(pais);
            return {};
        } 
        vector<NodoPais*> vectorReturn = {pais}; // Vector con el pais 
        return vectorReturn;
    }
    else
    {
        size_t const half_size = vectorNodos.size() / 2; // Mitad del vector
        vector<NodoPais*> mitadIni(vectorNodos.begin(), vectorNodos.begin() + half_size); //Mitad inicial
        vector<NodoPais*> mitadFin(vectorNodos.begin() + half_size, vectorNodos.end()); // Mitad Final
        vector<NodoPais*> vectorIni = dividirGrafo(mitadIni); 
        vector<NodoPais*> vectorFin = dividirGrafo(mitadFin); 
        // Se une cada mitad despues de haber sido resuelto
        vectorIni.insert(vectorIni.end(),make_move_iterator(vectorFin.begin()),make_move_iterator(vectorFin.end()));
        return vectorIni;
    }
}
