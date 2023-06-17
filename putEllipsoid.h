#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putEllipsoid : public FiguraGeometrica{
protected:
	int xcenter, ycenter, zcenter, radiusx, radiusy, radiusz;
public:
	putEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _radiusx, int _radiusy, int _radiusz, int _r, int _g, int _b, int _a);
	~putEllipsoid() {};
	void draw(Sculptor& t);
};

#endif // PUTELLIPSOID_H