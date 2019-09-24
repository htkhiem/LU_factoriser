/**
 * @file matrix_2d.h
 * Interfaces to general double-precision 2D matrices for use with my other headers.
 */
#ifndef _HTKHIEM_MATRIX_2D_
#define _HTKHIEM_MATRIX_2D_
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>
using namespace std;
/** Main 2D Matrix class definition.
* This matrix class is range-checked and compatible with const parameters.
*/
class Matrix2D {
	double **elem; /** A 2D array of double-precision floating point numbers. */
	size_t size_x, size_y; /** Size of this matrix, which must always be initialised. */
public:
	/** Simple constructor
	* Initialises all elements to zero.
	* \param size_x: Can be understood as number of rows.
	* \param size_y: Can be understood as number of columns.
	*/
	Matrix2D(size_t size_x, size_t size_y) :
	size_x(size_x), size_y(size_y) { 
		elem = new double*[size_x];
		for (size_t i = 0; i < size_x; i++) {
			elem[i] = new double[size_y] {0};
		}
	}
	/** Destructor
	* Deallocates 2D double array.
	*/
	~Matrix2D() {
		for (size_t i = 0; i < size_x; i++) delete[] elem[i];
		delete[] elem;
	}
	/** Getter method
	* Returns the value at the specified location in the 2D double matrix.
	* \param pos_x: Row index of desired value.
	* \param pos_y: Column index of desired value.
	* \return a copy of the value at that location.
	*/
	double getAt(size_t pos_x, size_t pos_y) const {
		if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
		return elem[pos_x][pos_y];
	}
	/** Setter method
	* Sets the cell at the specified location to the given value.
	* \param pos_x: Row index of target cell.
	* \param pos_y: Column index of target cell.
	* \param val: Value to be set to target cell.
	*/
	void setAt(size_t pos_x, size_t pos_y, double val) {
		if (pos_x >= size_x || pos_y >= size_y) throw out_of_range("Indices exceeded Matrix2D range.");
		elem[pos_x][pos_y] = val;
	}
	/** Method to get row count
	* \return the matrix's row count as std::size_t.
	*/
	size_t getSizeX() const { return size_x; }
	/** Method to get column count
	* \return the matrix's column count as std::size_t.
	*/
	size_t getSizeY() const { return size_y; }
	/** Prints the matrix
	* Format: space-separated for now, iomanip later.
	*/
	void print() const {
		for (size_t x = 0; x < size_x; x++) {
			for (size_t y = 0; y < size_y; y++) {
				cout << this->getAt(x, y) << ' ';
			}
			cout << endl;
		}
	}
};
void InputMatrix(ifstream &ifs, Matrix2D &m);

#endif // _HTKHIEM_MATRIX_2D_