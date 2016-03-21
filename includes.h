/*
 * Standard C include files for Mathomatic.
 * Automatically includes all necessary C include files for
 * any Mathomatic C source code.
 *
 * Copyright (C) 1987-2012 George Gesslein II.
 
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

The chief copyright holder can be contacted at gesslein@mathomatic.org, or
George Gesslein II, P.O. Box 224, Lansing, NY  14882-0224  USA.
 
 */

#define VERSION "16.0.5CE"

#ifndef true
#define	true	1
#define	false	0
#endif

#define NOT80COLUMNS	1	/* For programs that use less than 80 columns wide display. */

#define HELP	0	/* Define HELP=0 to remove the help command.  Shaves at least 10 kilobytes off of the executable. */

#define SECURE      1   /* Limit I/O as much as possible */
#define HANDHELD    1   /* Reduce memory usage */

#define USE_TGAMMA  1

/* Define SILENT=0 to have debugging enabled with the symbolic math library. */
#define	SILENT	1	/* Disable debug level setting and stop messages going to stdout. */
#define LIBRARY 1   /* Further disable some things */

#undef	READLINE	/* Readline shouldn't be included in the library code. */
#undef	EDITLINE	/* Editline neither */

#undef	UNIX		/* Unix desktop functionality is slightly different for CYGWIN and MINGW */
#define SHELL_OUT 0 /* Disables system(...) */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <float.h>
#include <math.h>
#include <setjmp.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "additions.h"

/* Include files from the current directory: */
#include "standard.h"	/* a standard include file for any math program written in C */
#include "am.h"		    /* the main include file for Mathomatic, contains tunable parameters */
#include "complex.h"	/* floating point complex number arithmetic function prototypes */
#include "proto.h"	    /* global function prototypes, made with cproto utility */
#include "altproto.h"	/* backup global function prototypes, in case of no proto.h */
#include "externs.h"	/* global variable extern definitions */
#include "blt.h"	    /* blt() function definition */
