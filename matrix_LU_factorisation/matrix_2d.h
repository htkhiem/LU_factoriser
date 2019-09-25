/**
 * @file matrix_2d.h
 * Interfaces to general double-precision 2D matrices for use with my other headers.
 * Basic and barebones :)
 */
#ifndef _HTKHIEM_MATRIX_2D_
#define _HTKHIEM_MATRIX_2D_
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>

using namespace std;
 /** A custom exception class inherited from standard C++ std::exception.
 */
class non_square_matrix : public std::exception {
public:
	/** Constructor (char array).
	* \param _cstr: The error message.
	*/
	explicit non_square_matrix(const char* _cstr) : info(_cstr) {}
	const char* what() const throw () {
		return info.c_str();
	}
protected:
	/** C++ string that contains the error message.
	*/
	std::string info;
};

/** Main 2D Matrix class definition.
* This matrix class is range-checked and compatible with const parameters.
*/
class Matrix2D {
	double **elem; /** A 2D array of double-precision floating point numbers. */
	size_t size_x, size_y; /** Size of this matrix, which must always be initialised. */
public:
	/** Simple constructor.
	* Initialises all elements to zero.
	* \param size_x: Can be understood as number of rows.
	* \param size_y: Can be understood as number of columns.
	*/
	Matrix2D(size_t size_x, size_t size_y);
	/** Destructor.
	* Deallocates 2D double array.
	*/
	~Matrix2D();
	/** Getter method
	* Returns the value at the specified location in the 2D double matrix.
	* \param pos_x: Row index of desired value.
	* \param pos_y: Column index of desired value.
	* \return a copy of the value at that location.
	*/
	double getAt(size_t pos_x, size_t pos_y) const;
	/** Setter method
	* Sets the cell at the specified location to the given value.
	* \param pos_x: Row index of target cell.
	* \param pos_y: Column index of target cell.
	* \param val: Value to be set to target cell.
	*/
	void setAt(size_t pos_x, size_t pos_y, double val);
	/** Method to get row count.
	* \return The matrix's row count as std::size_t.
	*/
	size_t getSizeX() const { return size_x; }
	/** Method to get column count.
	* \return The matrix's column count as std::size_t.
	*/
	size_t getSizeY() const { return size_y; }
	/** Mathod to extract a submatrix from the current matrix.
	* The submatrix is defined by the position of its top-left element and its size (counting from that element).
	* \param pos_x: x-position of the top-left element of the desired submatrix.
	* \param pos_y: x-position of the top-left element of the desired submatrix.
	* \param sub_size_x: Row count of desired submatrix.
	* \param sub_size_y: Column count of desired submatrix.
	* \return A reference to the resulting submatrix.
	* \exception Throws range_error() if the submatrix exceeds the source's range, for example when its
	* top-left element is at the bottom-right of the source and its size is larger than 1 in any direction.
	*/
	Matrix2D &subMatrix(size_t pos_x, size_t pos_y, size_t sub_size_x, size_t sub_size_y);
	/** Prints the matrix.
	* Format: space-separated for now, iomanip later.
	*/
	void print() const;
	/** Checks if this is a square matrix.
	* \return True if matrix is square and false otherwise.
	*/
	bool isSquare() const { return (size_x == size_y); }
	/** Recursively omputes and returns the determinant of this matrix, if it's square.
	* Uses the ordinary hand method of computing determinants. TODO: Implement LUP decomposition instead.
	* \return The determinant of this matrix if it's square.
	* \exception Throws non_square_matrix() if this matrix isn't square.
	*/
	double det() const;
};
/** Method to create a matrix from an std::ifstream.
* The ifstream must contain a matrix written row-by-row and separated by spaces.
* \param ifs: Reference to the ifstream containing input.
* \param m: Reference to the target matrix. This function directly modifies its parameter instead of returning its own matrix.
*/
void InputMatrix(ifstream &ifs, Matrix2D &m);
/** This function concatenates two given matrices horizontally.
* The two matrices must have the same row count.
* \param left: Reference to the first matrix.
* \param right: Reference to the second matrix, which will be concatenated to the right of the first matrix.
* \exception range_error() if the two matrices do not have the same row count.
* \return A reference to the resulting matrix.
*/
Matrix2D &ConcatenateHorizontally(const Matrix2D &left, const Matrix2D &right);
/** This function concatenates two given matrices vertically.
* The two matrices must have the same column count.
* \param top: Reference to the first matrix.
* \param bottom: Reference to the second matrix, which will be concatenated below the first matrix.
* \return A reference to the resulting matrix.
* \exception range_error() if the two matrices do not have the same column count.
*/
Matrix2D &ConcatenateVertically(const Matrix2D &top, const Matrix2D &bottom);

#endif // _HTKHIEM_MATRIX_2D_