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
 *    \file ...
 *    \author Rien Quirynen
 *    \date 2012
 */

#include <acado/code_generation/export_matlab_mpc.hpp>


BEGIN_NAMESPACE_ACADO

using namespace std;


//
// PUBLIC MEMBER FUNCTIONS:
//

ExportMatlabMPC::ExportMatlabMPC(	const String& _templateName,
												const String& _fileName,
												const String& _commonHeaderName,
												const String& _realString,
												const String& _intString,
												int _precision,
												const String& _commentString
						) : ExportTemplatedFile(_templateName, _fileName, _commonHeaderName, _realString, _intString, _precision, _commentString)
{}


ExportMatlabMPC::ExportMatlabMPC(	const ExportMatlabMPC& arg
						) : ExportTemplatedFile( arg )
{}


ExportMatlabMPC::~ExportMatlabMPC( )
{}


ExportMatlabMPC& ExportMatlabMPC::operator=(	const ExportMatlabMPC& arg
														)
{
	if( this != &arg )
	{
		ExportTemplatedFile::operator=( arg );
	}
	
	return *this;
}

returnValue ExportMatlabMPC::configure(	const uint OSWindows, const uint numSteps, const uint verbose, const uint timingCalls )
{	
	// Configure the dictionary
	dictionary[ "@NUM_STEPS@" ] =  std::string(String(numSteps).getName());
	dictionary[ "@VERBOSE@" ] =  std::string(String(verbose).getName());
	if( timingCalls > 1 ) 	dictionary[ "@CALLS_TIMING@" ] =  std::string(String(timingCalls).getName());
	else 					dictionary[ "@CALLS_TIMING@" ] =  std::string(String(1).getName());
	dictionary[ "@OS_WINDOWS@" ] = std::string(String(OSWindows).getName());
	
	// And then fill a template file
	fillTemplate();

	return SUCCESSFUL_RETURN;
}

//
// PROTECTED MEMBER FUNCTIONS:
//

CLOSE_NAMESPACE_ACADO

// end of file.
