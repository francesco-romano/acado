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
 *    \file examples/integration_algorithm/pendulum.cpp
 *    \author Boris Houska, Hans Joachim Ferreau
 *    \date 2010
 */


#include <acado_toolkit.hpp>



int main( ){

    USING_NAMESPACE_ACADO


    // Define a Right-Hand-Side:
    // -------------------------
    DifferentialState      phi;    // the angle phi
    DifferentialState     dphi;    // the first derivative of phi w.r.t time
    Control                  F;    // a force acting on the pendulum
    Parameter                l;    // the length of the pendulum

    const double m     = 1.0  ;    // the mass of the pendulum
    const double g     = 9.81 ;    // the gravitational constant
    const double alpha = 2.0  ;    // frictional constant

    IntermediateState    z;
    DifferentialEquation f;

    z = sin(phi);

    f << dot(phi ) == dphi;
    f << dot(dphi) == -(m*g/l)*z - alpha*dphi + F/(m*l);


    // DEFINE INITIAL VALUES:
    // ----------------------

    Vector xStart( 2 );
	xStart(0) = 1.0;
	xStart(1) = 0.0;

	Vector xa;
	
    Vector u( 1 );
	u(0) = 0.0;
	
    Vector p( 1 );
	p(0) = 1.0;

    double tStart    =  0.0        ;
    double tEnd      =  2.0        ;

	Grid timeHorizon( tStart,tEnd );


    // DEFINE AN INTEGRATOR:
    // ---------------------

    IntegrationAlgorithm intAlg;

	intAlg.addStage( f, timeHorizon, INT_RK45 );

	//intAlg.set( INTEGRATOR_TYPE, INT_RK45 );
	intAlg.set( INTEGRATOR_PRINTLEVEL, HIGH );
	intAlg.set( INTEGRATOR_TOLERANCE, 1.0e-6 );


    // START THE INTEGRATION:
    // ----------------------

	intAlg.integrate( timeHorizon, xStart,xa,p,u );


    // GET THE RESULTS
    // ---------------

	VariablesGrid differentialStates;
	intAlg.getX( differentialStates );
	
	differentialStates.print( "x" );


    return 0;
}



