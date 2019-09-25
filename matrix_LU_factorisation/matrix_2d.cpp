#include "matrix_2d.h"
using namespace std;
void InputMatrix(ifstream &ifs, Matrix2D &m) {
	double temp;
	for (size_t l = 0; l < m.getSizeX(); l++) {
		for (size_t c = 0; c < m.getSizeY(); c++) {
			ifs >> temp;
			m.setAt(l, c, temp);
		}
	}
}
Matrix2D::Matrix2D(size_t size_x, size_t size_y) :
	size_x(size_x), size_y(size_y) {
	elem = new double*[size_x];
	for (size_t i = 0; i < size_x; i++) {
		elem[i] = new double[size_y] {0};
	}
}
Matrix2D::~Matrix2D() {
	for (size_t i = 0; i < size_x; i++) delete[] elem[i];
	delete[] elem;
}
double Matrix2D::getAt(size_t pos_x, size_t pos_y) const {
	if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
	return elem[pos_x][pos_y];
}
void Matrix2D::setAt(size_t pos_x, size_t pos_y, double val) {
	if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
	elem[pos_x][pos_y] = val;
}
void Matrix2D::print() const {
	for (size_t x = 0; x < size_x; x++) {
		for (size_t y = 0; y < size_y; y++) {
			cout << this->getAt(x, y) << ' ';
		}
		cout << endl;
	}
}
Matrix2D &ConcatenateHorizontally(const Matrix2D &left, const Matrix2D &right) {
	if (left.getSizeX() != right.getSizeX()) 
		throw range_error("Cannot horizontally concatenate two matrices with different row counts.");
	Matrix2D result(left.getSizeX(), left.getSizeY() + right.getSizeY()); // TODO: warn if overflow
	for (size_t y = 0; y < left.getSizeY(); y++) { // put left matrix in result
		for (size_t x = 0; x < left.getSizeX(); x++) {
			result.setAt(x, y, left.getAt(x, y));
		}
	}
	for (size_t y = left.getSizeY(); y < left.getSizeY() + right.getSizeY(); y++) { // put right matrix in result
		for (size_t x = 0; x < left.getSizeX(); x++) {
			result.setAt(x, y, right.getAt(x, y));
		}
	}
	return result;
}
Matrix2D &ConcatenateVertically(const Matrix2D &top, const Matrix2D &bottom) {
	if (top.getSizeY() != bottom.getSizeY()) 
		throw range_error("Cannot vertically concatenate two matrices with different column counts.");
	Matrix2D result(top.getSizeX() + bottom.getSizeX(), top.getSizeY()); // TODO: warn if overflow
	for (size_t x = 0; x < top.getSizeX(); x++) { // put top matrix in result
		for (size_t y = 0; y < top.getSizeY(); y++) {
			result.setAt(x, y, top.getAt(x, y));
		}
	}
	for (size_t x = top.getSizeX(); x < top.getSizeX() + bottom.getSizeX(); x++) { // put top matrix in result
		for (size_t y = 0; y < top.getSizeY(); y++) {
			result.setAt(x, y, top.getAt(x, y));
		}
	}
	return result;
}
Matrix2D &Matrix2D::subMatrix(size_t pos_x, size_t pos_y, size_t sub_size_x, size_t sub_size_y) {
	if (pos_x + sub_size_x - 1 > size_x || pos_y + sub_size_y - 1 > size_y) 
		throw range_error("Submatrix is out of bounds.");
	Matrix2D result(sub_size_x, sub_size_y);
	for (size_t x = 0; x < sub_size_x; x++) {
		for (size_t y = 0; y < sub_size_y; y++) {
			result.setAt(x, y, this->getAt(pos_x + x, pos_y + y));
		}
		return result;
	}
}
double Matrix2D::det() const {
	if (!isSquare()) throw non_square_matrix("Cannot compute determinant: this isn't a square matrix.");
	//for (size_t x = 0; x < size_x; x++) {

	//}
}