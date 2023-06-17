#include "putBox.h"
/**
*
*@brief Classe do metodo usado para inserir um box (1 pixelzinho) *entre um ponto inicial (0) e um final (1)
*@param int _x0, int _x1, int _y0, int _y1, int _z0, int _z1 int _r, int _g, int _b, int _a
*
*/
putBox::putBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, int _r, int _g, int _b, int _a) {
	x0 = _x0; x1 = _x1;
	y0 = _y0; y1 = _y1;
	z0 = _z0; z1 = _z1;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}
/**
*
*@brief Metodo usado para dar cor a um box (1 pixelzinho)
*
*/
void putBox::draw(Sculptor &t) {

	t.setColor(r, g, b, a);

	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				t.putVoxel(i, j, k);
			}
		}
	}
}