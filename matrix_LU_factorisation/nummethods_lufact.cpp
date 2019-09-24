#include "matrix_2d.h"
#include "nummethods_lufact.h"
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