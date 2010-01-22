// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ComplexVector.h: Rcpp R/C++ interface class library -- complex vectors
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <RcppCommon.h>
#include <Rcpp/RObject.h>
#include <Rcpp/ComplexVector.h>
#include <algorithm>

namespace Rcpp{
	
	ComplexVector::ComplexVector(SEXP x) throw(not_compatible) : VectorBase(), start(0) {
		switch( TYPEOF( x ) ){
			case CPLXSXP:
				setSEXP( x ) ;
				break ;
			case REALSXP:
			case LGLSXP:
			case RAWSXP:
			case INTSXP:
				setSEXP( Rf_coerceVector( x, CPLXSXP) ) ;
				break ;
			default:
				throw not_compatible( "cannot convert to complex vector" ) ;
		}
	}
	
	ComplexVector::ComplexVector(int size) : VectorBase(), start(0) {
		setSEXP( Rf_allocVector(CPLXSXP, size) ) ;
	}

} // namespace 
