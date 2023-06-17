#include "cutVoxel.h"
/**
*
*@brief Classe do metodo usado para inserir um voxel *entre um ponto inicial (0) e um final (1)
*@param int _x, int _y, int _z
*
*/
cutVoxel::cutVoxel(int _x, int _y, int _z) {
	x = _x;
	y = _y;
	z = _z;
}

void cutVoxel::draw(Sculptor& t) {
	t.cutVoxel(x, y, z);
}