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


