#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutSphere : public FiguraGeometrica {
protected:
	int xcenter, ycenter, zcenter, radius;
public:
	cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
	~cutSphere() {};
	void draw(Sculptor &t);
};

#endif // CUTSPHERE_H