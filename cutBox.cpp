#include "cutBox.h"
/**
*
*@brief Classe do metodo usado para cortar um box (1 pixelzinho) entre um ponto inicial (0) e um final (1)
*@param int _x0, int _x1, int _y0, int _y1, int _z0, int _z1 int _r, int _g, int _b, int _a
*
*/
cutBox::cutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1) {
	x0 = _x0; x1 = _x1;
	y0 = _y0; y1 = _y1;
	z0 = _z0; z1 = _z1;
}

void cutBox::draw(Sculptor& t) {
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				t.cutVoxel(i, j, k);
			}
		}
	}
}