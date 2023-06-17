#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

	nx = _nx;
	ny = _ny;
	nz = _nz;

	v = new Voxel **[nx]; 

	for (int i = 0; i < nx; i++) {
		v[i] = new Voxel * [ny];
	}

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			v[i][j] = new Voxel[nz];

		}
	}

	for (int i = 0; i < nx; i++) { 
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				v[i][j][k].isOn = false;
				v[i][j][k].r = 0;
				v[i][j][k].g = 0;
				v[i][j][k].b = 0;
				v[i][j][k].a = 0;
			}
		}
	}
}

Sculptor::~Sculptor() {

	for (int i = 0; i < nx; i++) { 
		for (int j = 0; j < ny; j++) {
			delete[] v[i][j];
		}
	}
	for (int i = 0; i < nx; i++) {
		delete[] v[i];
	}
	delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {

	this->r = r / 255; 
	this->g = g / 255; 
	this->b = b / 255;
	a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
	v[x][y][z].isOn = true;
	v[x][y][z].r = r;
	v[x][y][z].g = g;
	v[x][y][z].b = b;
	v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z) {
	v[x][y][z].isOn = false;
}

int Sculptor::getnx(void) {
	return nx;
}

int Sculptor::getny(void) {
	return ny;
}

int Sculptor::getnz(void) {
	return nz;
}

void Sculptor::writeOFF(char* filename) {
	ofstream outFile;
	outFile.open(filename);

	int Nvoxel = 0;

	for (int i = 0; i < nx; i++) { 
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					Nvoxel++;
				}
			}
		}
	}

	outFile << "OFF" << endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << endl;


	for (int i = 0; i < nx; i++) { 
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
				}
			}
		}
	}

	int vertice = 0;
	outFile << setiosflags(ios::fixed); 

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					outFile << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					vertice = vertice + 8;
				}
			}
		}
	}
	outFile.close();
}