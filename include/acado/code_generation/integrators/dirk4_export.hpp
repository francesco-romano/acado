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
 *    \file include/acado/code_generation/integrators/dirk4_export.hpp
 *    \author Rien Quirynen
 *    \date 2013
 */


#ifndef ACADO_TOOLKIT_DIRK4_EXPORT_HPP
#define ACADO_TOOLKIT_DIRK4_EXPORT_HPP

#include <acado/code_generation/integrators/dirk_export.hpp>


BEGIN_NAMESPACE_ACADO


/** 
 *	\brief Allows to export a tailored diagonally implicit 3-stage Runge-Kutta method of order 4 for fast model predictive control.
 *
 *	\ingroup NumericalAlgorithms
 *
 *	The class DiagonallyIRK4Export allows to export a tailored diagonally implicit 3-stage Runge-Kutta method of order 4
 *	for fast model predictive control.
 *
 *	\author Rien Quirynen
 */
class DiagonallyIRK4Export : public DiagonallyImplicitRKExport
{
    //
    // PUBLIC MEMBER FUNCTIONS:
    //

    private:

		/** Default constructor. 
		 *
		 *	@param[in] _userInteraction		Pointer to corresponding user interface.
		 *	@param[in] _commonHeaderName	Name of common header file to be included.
		 */
        DiagonallyIRK4Export(	UserInteraction* _userInteraction = 0,
							const String& _commonHeaderName = ""
							);

		/** Copy constructor (deep copy).
		 *
		 *	@param[in] arg		Right-hand side object.
		 */
        DiagonallyIRK4Export(	const DiagonallyIRK4Export& arg
							);

        /** Destructor. 
		 */
        virtual ~DiagonallyIRK4Export( );

    protected:

};

static struct RegisterDiagonallyIRK4Export
{
	RegisterDiagonallyIRK4Export();
} registerDiagonallyIRK4Export;


CLOSE_NAMESPACE_ACADO


#endif  // ACADO_TOOLKIT_DIRK4_EXPORT_HPP

// end of file.
