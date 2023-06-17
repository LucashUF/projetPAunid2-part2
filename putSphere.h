#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putSphere : public FiguraGeometrica{
protected:
	int xcenter, ycenter, zcenter, radius;
public:
	putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, int _r, int _g, int _b, int _a);
	~putSphere() {};
	void draw(Sculptor &t);
};

#endif // PUTSPHERE_H