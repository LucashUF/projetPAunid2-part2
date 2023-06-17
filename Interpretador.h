#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include <vector>
#include <string>
#include "FiguraGeometrica.h"

using namespace std;

class Interpretador{
protected:
	int dimx, dimy, dimz;
	float r, g, b, a;
public:
	Interpretador();

	vector<FiguraGeometrica*> interpretador(string filename);

	int getDimx();
	int getDimy();
	int getDimz();

};

#endif // LEITOR_H