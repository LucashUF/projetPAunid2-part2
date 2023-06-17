#include "cutEllipsoid.h"

cutEllipsoid::cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _radiusx, int _radiusy, int _radiusz) {
	xcenter = _xcenter; radiusx = _radiusx;
	ycenter = _ycenter; radiusy = _radiusy;
	zcenter = _zcenter; radiusz = _radiusz;
}

void cutEllipsoid::draw(Sculptor& t) {

	double x, y, z;

	for (int i = 0; i < t.getnx(); i++)
		for (int j = 0; j < t.getny(); j++)
			for (int k = 0; k < t.getnz(); k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (radiusx * radiusx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (radiusy * radiusy);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (radiusz * radiusz);

				if ((x + y + z) < 1)
					t.cutVoxel(i, j, k);
			}
}