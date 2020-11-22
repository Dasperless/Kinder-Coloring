#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "../ColoringAlgorithm/ColoringAlgorithm.h"

class Backtracking : public ColoringAlgorithm {
	private:
		int cantidadColores;
		int paisesColoreados;
	public:
		Backtracking(GrafoPaises* PaisesAProcesar);
		vector<NodoPais*> iniciarAlgoritmo(int pCantidadColores);
		vector<NodoPais*> backTracking(vector<NodoPais*> vectorNodos);
};
#endif