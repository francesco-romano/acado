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
 *    \file examples/integration_algorithm/simple_dae.cpp
 *    \author Boris Houska, Hans Joachim Ferreau
 *    \date 2008
 */


#include <acado_toolkit.hpp>


/* >>> start tutorial code >>> */
int main( ){

    USING_NAMESPACE_ACADO

    // DEFINE A RIGHT-HAND-SIDE:
    // -------------------------
    DifferentialState         x;
    AlgebraicState            z;
    Parameter               p,q;

    DifferentialEquation f;

    f << dot(x) == -p*x*x*z  ;
    f <<     0  ==  q*q - z*z + 0.1*x;

	
    // DEFINE INITIAL VALUES:
    // ----------------------

    Vector xStart( 1 );
	xStart(0) = 1.0;
    
	Vector zStart( 1 );
	zStart(0) = 1.0;

	Vector pp( 2 );
	pp(0) = 1.0;
	pp(1) = 1.0;
	
    double t0   = 0.0 ;
    double tend = 1.0 ;

	Grid timeHorizon( t0,tend );


    // DEFINE AN INTEGRATOR:
    // ---------------------

    IntegrationAlgorithm intAlg;

	intAlg.addStage( f, timeHorizon );

	intAlg.set( INTEGRATOR_PRINTLEVEL, HIGH );


	// START THE INTEGRATION:
    // ----------------------

	//integrator.freezeAll();
    intAlg.integrate( timeHorizon, xStart, zStart, pp );


    // GET THE RESULTS
    // ---------------

    VariablesGrid differentialStates;
    VariablesGrid algebraicStates   ;

//     intAlg.getX ( differentialStates );
    intAlg.getLast( LOG_DIFFERENTIAL_STATES,differentialStates );
    intAlg.getXA( algebraicStates    );

	differentialStates.print( "x" );
	algebraicStates.print( "z" );


    return 0;
}
/* <<< end tutorial code <<< */


