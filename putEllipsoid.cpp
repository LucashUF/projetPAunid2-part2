#include "putEllipsoid.h"

putEllipsoid::putEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _radiusx, int _radiusy, int _radiusz, int _r, int _g, int _b, int _a) {
	xcenter = _xcenter; radiusx = _radiusx;
	ycenter = _ycenter; radiusy = _radiusy;
	zcenter = _zcenter; radiusz = _radiusz;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void putEllipsoid::draw(Sculptor& t) {

	t.setColor(r, g, b, a);

	double x, y, z;

	for (int i = 0; i < t.getnx(); i++)
		for (int j = 0; j < t.getny(); j++)
			for (int k = 0; k < t.getnz(); k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (radiusx * radiusx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (radiusy * radiusy);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (radiusz * radiusz);

				if ((x + y + z) < 1)
					t.putVoxel(i, j, k);
			}
}