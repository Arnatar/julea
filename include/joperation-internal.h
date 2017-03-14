/*
 * JULEA - Flexible storage framework
 * Copyright (C) 2010-2017 Michael Kuhn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file
 **/

#ifndef H_OPERATION_INTERNAL
#define H_OPERATION_INTERNAL

#include <glib.h>

#include <julea-internal.h>

#include <jlist.h>
#include <jsemantics.h>

typedef gboolean (*JOperationExecFunc) (JList*, JSemantics*);
typedef void (*JOperationFreeFunc) (gpointer);

/**
 * An operation.
 **/
struct JOperation
{
	gpointer key;
	gpointer data;

	JOperationExecFunc exec_func;
	JOperationFreeFunc free_func;
};

typedef struct JOperation JOperation;

J_GNUC_INTERNAL JOperation* j_operation_new (void);
J_GNUC_INTERNAL void j_operation_free (JOperation*);

#endif
