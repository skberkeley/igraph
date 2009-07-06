/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009  Gabor Csardi <csardi@rmki.kfki.hu>
   UNIL DGM, Rue de Bugnon 27, CH-1005 Lausanne, Switzerland
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_MIXING_H
#define IGRAPH_MIXING_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_types.h"
#include "igraph_datatype.h"
#include "igraph_vector.h"

__BEGIN_DECLS

int igraph_assortativity_nominal(const igraph_t *graph, 
				 const igraph_vector_long_t *types,
				 igraph_real_t *res,
				 igraph_bool_t directed);

int igraph_assortativity(const igraph_t *graph,
			 const igraph_vector_t *types1,
			 const igraph_vector_t *types2,
			 igraph_real_t *res,
			 igraph_bool_t directed);

int igraph_assortativity_degree(const igraph_t *graph,
				igraph_real_t *res);

__END_DECLS

#endif
