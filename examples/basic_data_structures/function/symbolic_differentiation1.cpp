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
 *    \file examples/function/symbolic_differentiation1.cpp
 *    \author Boris Houska, Hans Joachim Ferreau
 *    \date 2008
 */

#include <time.h>

#include <acado/utils/acado_utils.hpp>
#include <acado/user_interaction/user_interaction.hpp>
#include <acado/symbolic_expression/symbolic_expression.hpp>
#include <acado/function/function.hpp>


/* >>> start tutorial code >>> */
int main( ){

    USING_NAMESPACE_ACADO

    // DEFINE VALRIABLES:
    // ---------------------------
    DifferentialState    x;
    IntermediateState    y;
    IntermediateState    z;


    Function             f;


    // DEFINE A TEST FUNCTION:
    // -----------------------
    y = x*x;

    f << cos(x);
    f << sin(x);
    f <<     forwardDerivative( sin(x)     , x );
    f <<     forwardDerivative( cos(x)     , x );
    f <<     forwardDerivative( x*x        , x );
    f <<     forwardDerivative( y          , x );
    f <<     forwardDerivative( y + x*y    , x );
    f << x + forwardDerivative( x + y*y    , x );
    f <<     forwardDerivative( y*y + 1.0/y, x );
    f <<     forwardDerivative( sqrt(x)    , x );
    f <<     forwardDerivative( log (x)    , x );

    f <<     laplace          ( x*y        , x );


//    DifferentialState z(2);
/*
    f <<  forwardDerivative( sin(z), z );
    f <<  backwardDerivative( z(0)*z(0) + z(1)*z(1)*3.0 , z );*/


    f << backwardDerivative( cos(y)+ sin(y), x );

    FILE *file = fopen("symbolic_differentiation1_output.txt", "w" );
    file << f;
    fclose(file);

//     // TEST THE FUNCTION f:
//     // --------------------
//     double xx[3] = { 1.0, 1.0, 1.0 };
//     double *result = new double[ f.getDim() ];
// 
//     // EVALUATE f AT THE POINT  (tt,xx):
//     // ---------------------------------
//     f.evaluate( 0.0, xx, result, MEDIUM );
// 
//     delete[] result;

    return 0;
}
/* <<< end tutorial code <<< */

