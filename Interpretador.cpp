#include "Interpretador.h"
#include "cutBox.h"
#include "cutEllipsoid.h"
#include "cutSphere.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "putEllipsoid.h"
#include "putSphere.h"
#include "putVoxel.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Interpretador::Interpretador() {}

vector<FiguraGeometrica *> Interpretador::interpretador(string filename) {
  vector<FiguraGeometrica *> fig;
  string s;
  stringstream ss;

  ifstream inFile;
  inFile.open(filename);

  if (!inFile.is_open()) { 
    cout << "Não foi possivel abrir " << filename << ".\n" << endl;
    exit(0);
  }

  while (getline(inFile, s)) {

    if (inFile.good()) {
      ss.clear();
      ss.str(s);
      ss >> s;

      if (ss.good()) {
        if (s.compare("dim") == 0) {
          ss >> dimx >> dimy >> dimz;
        } else if (s.compare("putVoxel") == 0) {
          int x, y, z;
          ss >> x >> y >> z >> r >> g >> b >> a;
          fig.push_back(new putVoxel(x, y, z, r, g, b, a));

        } else if (s.compare("cutVoxel") == 0) {
          int x, y, z;
          ss >> x >> y >> z;
          fig.push_back(new cutVoxel(x, y, z));

        } else if (s.compare("putBox") == 0) {
          int x0, y0, z0, x1, y1, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          fig.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

        } else if (s.compare("cutBox") == 0) {
          int x0, y0, z0, x1, y1, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          fig.push_back(new cutBox(x0, x1, y0, y1, z0, z1));

        } else if (s.compare("putSphere") == 0) {
          int xcenter, ycenter, zcenter, radius;
          ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
          fig.push_back(
              new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));

        } else if (s.compare("cutSphere") == 0) {
          int xcenter, ycenter, zcenter, radius;
          ss >> xcenter >> ycenter >> zcenter >> radius;
          fig.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));

        } else if (s.compare("putEllipsoid") == 0) {
          int xcenter, ycenter, zcenter, radiusx, radiusy, radiusz;
          ss >> xcenter >> ycenter >> zcenter >> radiusx >> radiusy >>
              radiusz >> r >> g >> b >> a;
          fig.push_back(new putEllipsoid(xcenter, ycenter, zcenter, radiusx,
                                             radiusy, radiusz, r, g, b, a));

        } else if (s.compare("cutEllipsoid") == 0) {
          int xcenter, ycenter, zcenter, radiusx, radiusy, radiusz;
          ss >> xcenter >> ycenter >> zcenter >> radiusx >> radiusy >> radiusz;
          fig.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, radiusx,
                                             radiusy, radiusz));
        }
      }
    }
  }

  inFile.close();
  return (fig);
}

int Interpretador::getDimx() { return dimx; }

int Interpretador::getDimy() { return dimy; }

int Interpretador::getDimz() { return dimz; }