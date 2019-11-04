/**
 * @file nummethods_lufact.h
 *
 * Interfaces to the LU-factorisation functions.
 *
 * For use with matrix_2d.h.
 */
#ifndef _HTKHIEM_NUMMETHODS_LUFACT_
#define _HTKHIEM_NUMMETHODS_LUFACT_

#include "matrix_2d.h"
/** LU-Factoriser implementing Doolittle's method.
* In accordance with Doolittle's method, it assumes the diagonal of the lower matrix L to be 1s (ones).
* \param A: The source matrix, which must be square.
* \param L: The lower triangular matrix, passed as reference to be written to. In this method, its diagonal is assumed to be 1s.
* \param U: The upper triangular matrix, also passed as reference.
*/
void ALUFactorizeDoolittle(const Matrix2D &A, Matrix2D &L, Matrix2D &U);
/** LU-Factoriser implementing Crout's method.
* In accordance with Crout's method, it assumes the diagonal of the upper matrix U to be 1s (ones).
* \param A: The source matrix, which must be square.
* \param L: The lower triangular matrix, passed as reference to be written to.
* \param U: The upper triangular matrix, also passed as reference. In this method, its diagonal is assumed to be 1s.
*/
void ALUFactorizeCrout(const Matrix2D &A, Matrix2D &L, Matrix2D &U);
#endif //_HTKHIEM_NUMMETHODS_LUFACT_