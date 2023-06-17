#include "putSphere.h"
/**
*
*@brief Classe do metodo usado para inserir uma esfera, tendo como *base o raio da esfera
*@param int _xcenter, int _ycenter, int _zcenter, int _radius, int _r, int _g, int _b, int _a
*
*/
putSphere::putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, int _r, int _g, int _b, int _a) {
	xcenter = _xcenter;
	ycenter = _ycenter;
	zcenter = _zcenter;
	radius = _radius;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void putSphere::draw(Sculptor &t) {

	t.setColor(r, g, b, a);

	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
			for (int k = -radius; k <= radius; k++)
				if (((xcenter + i) < 0 || (xcenter + i) >= t.getnx()) || ((ycenter + j) < 0 || (ycenter + j) >= t.getny()) || ((zcenter + k) < 0 || (zcenter + k) >= t.getnz())) {
				}
				else {
					if (i * i + j * j + k * k < radius * radius)
						t.putVoxel(xcenter + i, ycenter + j, zcenter + k);
				}
}