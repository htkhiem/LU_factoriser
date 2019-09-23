#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>
using namespace std;
#ifndef _HTKHIEM_MATRIX_2D_
#define _HTKHIEM_MATRIX_2D_
class Matrix2D {
	double **elem;
	size_t size_x, size_y;
public:
	Matrix2D(size_t size_x, size_t size_y) :
	size_x(size_x), size_y(size_y) { // Blank constructor, initialises zero-matrix
		elem = new double*[size_x];
		for (size_t i = 0; i < size_x; i++) {
			elem[i] = new double[size_y] {0};
		}
	}
	//Matrix2D(Matrix2D &&src) { // Move constructor
	//	this->elem = src.elem;
	//	this->size_x = src.size_x;
	//	this->size_y = src.size_y;
	//	src.elem = nullptr;
	//	src.size_x = src.size_y = 0;
	//}
	~Matrix2D() {
		for (size_t i = 0; i < size_x; i++) delete[] elem[i];
		delete[] elem;
	}
	double &getAt(size_t pos_x, size_t pos_y) const {
		if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
		return elem[pos_x][pos_y];
	}
	void setAt(size_t pos_x, size_t pos_y, double val) {
		if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
		elem[pos_x][pos_y] = val;
	}
	size_t getSizeX() const { return size_x; }
	size_t getSizeY() const { return size_y; }
	void print() const {
		for (size_t x = 0; x < size_x; x++) {
			for (size_t y = 0; y < size_y; y++) {
				cout << this->getAt(x, y) << ' ';
			}
			cout << endl;
		}
	}
};
void InputMatrix(ifstream &ifs, Matrix2D &m) {
	double temp;
	for (size_t l = 0; l < m.getSizeX(); l++) {
		for (size_t c = 0; c < m.getSizeY(); c++) {
			ifs >> temp;
			m.setAt(l, c, temp);
		}
	}
}

#endif // _HTKHIEM_MATRIX_2D_