#include "cutSphere.h"
/**
*
*@brief Classe do metodo usado para cortar uma parte esférica, tendo como base o raio da esfera
*@param int _xcenter, int _ycenter, int _zcenter, int _radius
*
*/
cutSphere::cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius) {
	xcenter = _xcenter;
	ycenter = _ycenter;
	zcenter = _zcenter;
	radius = _radius;
}

void cutSphere::draw(Sculptor &t) {
	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
			for (int k = -radius; k <= radius; k++)
				if (((xcenter + i) < 0 || (xcenter + i) >= t.getnx()) || ((ycenter + j) < 0 || (ycenter + j) >= t.getny()) || ((zcenter + k) < 0 || (zcenter + k) >= t.getnz())) {
				}
				else {
					if (i * i + j * j + k * k < radius * radius)
						t.cutVoxel(xcenter + i, ycenter + j, zcenter + k);
				}
}