#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutBox : public FiguraGeometrica {
protected:
	int x0, x1, y0, y1, z0, z1;
public:
	cutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
	~cutBox() {};
	void draw(Sculptor &t);
};

#endif // CUTBOX_H