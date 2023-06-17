#include "Sculptor.h"
#include "FiguraGeometrica.h"
#include "Interpretador.h"
#include <vector>

int main() {
	
    vector<FiguraGeometrica*> fig;
    Interpretador l;

    fig = l.interpretador("abelha.txt");

    Sculptor abelha(l.getDimx(), l.getDimy(), l.getDimz());

    for (int i = 0; i < fig.size(); i++) {
        fig[i]->draw(abelha);
    }

    abelha.writeOFF((char*)"abelha.off");

    for (int i = 0; i < fig.size(); i++) {
        delete fig[i];
    }

    return 0;
}