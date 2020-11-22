#include "Backtracking.h"
#include "../Grafo/NodoPais.h"
Backtracking::Backtracking(GrafoPaises *PaisesAProcesar) : ColoringAlgorithm(PaisesAProcesar) {}

vector<NodoPais *> Backtracking::iniciarAlgoritmo(int pCantidadColores)
{
	this->cantidadColores = pCantidadColores;
	GrafoPaises *paisesAprocesar = this->getPaisesAProcesar();
	vector<NodoPais *> vectorPaises = paisesAprocesar->obtenerListaNodos();
	vector<NodoPais *> vectorResuelto = backTracking(vectorPaises);
	return vectorResuelto;
}

vector<NodoPais *> Backtracking::backTracking(vector<NodoPais *> vectorNodos)
{
	NodoPais *pais = vectorNodos.front(); // Pais a evaluar
	if (vectorNodos.size() == 1)
	{
		if (paisesColoreados >= getPaisesColoreados())
			return;
		return;
	}

	int contador = 0;
	for (auto color : colores)
	{
		if (contador == cantidadColores)
		{
			break;
		}
		else if ((find(pais->coloresNoPermitidos.begin(), pais->coloresNoPermitidos.end(), color) == pais->coloresNoPermitidos.end()))
		{
			pais->colorPais = color;
			pais->setColorNoPermitido(color);
			vector<NodoPais *> quitarNodoActual(vectorNodos.begin() + 1, vectorNodos.end()); 
			backTracking(vectorNodos);
			pais->removeColorNoPermitido(color);	

		}
		contador++;
	}
}
