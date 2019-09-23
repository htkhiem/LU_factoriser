#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <string>
#include "matrix_2d.h"
using namespace std;

/* Input text file format:
size mode
[ matrix here]
(mode: either d/D (Doolittle) or c/C (Crout))
Example:
3 d
1 2 3
4 5 6
7 8 9
*/

void LUFactorizeDoolittle(const Matrix2D &A, Matrix2D &L, Matrix2D &U) {
	size_t sz = A.getSizeX();
	for (size_t i = 0; i < sz; i++) {
		L.setAt(i, i, 1); // Set diagonal of L to 1
		U.setAt(0, i, A.getAt(0, i)); // Copy first row of A to U
	}
	for (size_t i = 1; i < sz; i++) { // First column of L sans first element
		L.setAt(i, 0, A.getAt(i, 0) / U.getAt(0, 0));
	}
	for (size_t i = 1; i < sz - 1; i++) { // Compute middle elements for L and U
		double sum_iji = 0;
		for (size_t j = 0; j < i - 1; j++) {
			sum_iji += L.getAt(i, j)*U.getAt(j, i);
		}
		U.setAt(i, i, A.getAt(i, i) - sum_iji);
		for (size_t j = i + 1; j < sz; j++) {
			double sum_ikj = 0, sum_jki = 0;
			for (size_t k = 0; k < i - 1; k++) {
				sum_ikj += L.getAt(i, k)*U.getAt(k, j);
				sum_jki += L.getAt(j, k)*U.getAt(k, i);
			}
			U.setAt(i, j, A.getAt(i, j) - sum_ikj);
			L.setAt(j, i, (A.getAt(j, i) - sum_jki) / U.getAt(i, i));
			L.print();
			cout << endl;
		}
	}
	// Compute the bottom-right element of U
	double sum_nin = 0;
	for (size_t i = 0; i < sz - 1; i++) {
		sum_nin += L.getAt(sz - 1, i)*U.getAt(i, sz - 1);
	}
	U.setAt(sz - 1, sz - 1, A.getAt(sz - 1, sz - 1) - sum_nin);
}

void LUFactorizeCrout(const Matrix2D &A, Matrix2D &L, Matrix2D &U) {
	size_t sz = A.getSizeX();
	for (size_t i = 0; i < sz; i++) {
		U.setAt(i, i, 1); // Set diagonal of U to 1
		L.setAt(i, 0, A.getAt(i, 0)); // Copy first column of A to L
	}
	for (size_t i = 1; i < sz; i++) { // First row of U sans first element
		U.setAt(0, i, A.getAt(0, i) / L.getAt(0, 0));
	}
	for (size_t i = 1; i < sz - 1; i++) { // Compute middle elements for L and U
		double sum_iji = 0;
		for (size_t j = 0; j < i - 1; j++) {
			sum_iji += L.getAt(i, j)*U.getAt(j, i);
		}
		L.setAt(i, i, A.getAt(i, i) - sum_iji);
		for (size_t j = i + 1; j < sz; j++) {
			double sum_ikj = 0, sum_jki = 0;
			for (size_t k = 0; k < i - 1; k++) {
				sum_ikj += L.getAt(i, k)*U.getAt(k, j);
				sum_jki += L.getAt(j, k)*U.getAt(k, i);
			}
			U.setAt(i, j, (A.getAt(i, j) - sum_ikj) / L.getAt(i, i));
			L.setAt(j, i, A.getAt(j, i) - sum_jki);
		}
	}
	double sum_nin = 0;
	for (size_t i = 0; i < sz - 1; i++) {
		sum_nin += L.getAt(sz - 1, i)*U.getAt(i, sz - 1);
	}
	L.setAt(sz - 1, sz - 1, A.getAt(sz - 1, sz - 1) - sum_nin);
}



int main() {
	cout << "Input file name with extension: ";
	string filename;
	cin >> filename;
	ifstream ifs(filename);
	if (!ifs.good()) return -1;
	size_t mat_size; // accept square matrices only
	ifs >> mat_size;
	char mode;
	ifs >> mode;
	Matrix2D A(mat_size, mat_size);
	InputMatrix(ifs, A);
	Matrix2D L(mat_size, mat_size), U(mat_size, mat_size);
	if (toupper(mode) == 'D') { // Doolittle
		LUFactorizeDoolittle(A, L, U);
	}
	else if (toupper(mode) == 'C') { // Crout
		LUFactorizeCrout(A, L, U);
	}
	cout << "A = L x U\nA =\n";
	A.print();
	cout << "\nL =\n";
	L.print();
	cout << "\nU =\n";
	U.print();
	char wait;
	cin >> wait;
	return 0;
}


