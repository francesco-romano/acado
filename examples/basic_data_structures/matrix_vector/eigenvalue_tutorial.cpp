/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2009 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC) under
 *    supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */



 /**
 *    \file examples/matrix_vector/eigenvalue_tutorial.cpp
 *    \author Boris Houska, Hans Joachim Ferreau
 *    \date 2008
 */


#include <acado/utils/acado_utils.hpp>
#include <acado/matrix_vector/matrix_vector.hpp>


/* >>> start tutorial code >>> */
int main( ){

    USING_NAMESPACE_ACADO

    // DEFINE A MATRIX:
    // ----------------
    Matrix A(3,3);

    A(0,0) = 1.0;  A(0,1) = 0.0;  A(0,2) = 0.0;
    A(1,0) = 0.0;  A(1,1) = 3.0;  A(1,2) = 2.0;
    A(2,0) = 0.0;  A(2,1) = 2.0;  A(2,2) = 3.0;


//  ----------------------------------------
//  Just printing the Eigenvalues:
//  ----------------------------------------

    printf("\nEigenvalues of the matrix A: \n");
    A.printEigenvalues();


//  --------------------------------------------
//  Obtaining the eigenvalues and eigenvectors:
//  --------------------------------------------

    Vector  eigenvalues;
    Matrix eigenvectors;

    eigenvalues = A.getEigenvalues( eigenvectors );


    return 0;
}
/* <<< end tutorial code <<< */


