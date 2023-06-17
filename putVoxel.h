#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putVoxel : public FiguraGeometrica{
protected:
	int x, y, z;
public:
	putVoxel(int _x, int _y, int _z, int _r, int _g, int _b, int _a);
	~putVoxel(){};
	void draw(Sculptor &t);
};

#endif // PUTVOXEL_H