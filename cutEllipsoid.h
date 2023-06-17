#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutEllipsoid : public FiguraGeometrica{
protected:
	int xcenter, ycenter, zcenter, radiusx, radiusy, radiusz;
public:
	cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _radiusx, int _radiusy, int _radiusz);
	~cutEllipsoid() {};
	void draw(Sculptor& t);
};

#endif // CUTELLIPSOID_H