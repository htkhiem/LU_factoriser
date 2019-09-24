#include "matrix_2d.h"
void InputMatrix(ifstream &ifs, Matrix2D &m) {
	double temp;
	for (size_t l = 0; l < m.getSizeX(); l++) {
		for (size_t c = 0; c < m.getSizeY(); c++) {
			ifs >> temp;
			m.setAt(l, c, temp);
		}
	}
}