#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutVoxel : public FiguraGeometrica {
protected:
	int x, y, z;
public:
	cutVoxel(int _x, int _y, int _z);
	~cutVoxel() {};
	void draw(Sculptor& t);
};

#endif // CUTVOXEL_H