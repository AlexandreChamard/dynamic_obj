
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

dynamic_obj_t *dynamic_dup(dynamic_obj_t const *obj)
{
	dynamic_obj_t *dup_obj = dynamic_alloc();

	for (size_t i = 0; i < obj->n_attribute; ++i) {
		if (obj->attributes[i].type == DYN_OBJ) {
			dynamic_assign(dup_obj, obj->attributes[i].name, DYN_OBJ, dynamic_dup(obj->attributes[i].obj), 0);
		} else {
			if (obj->attributes[i].type == DYN_FLOAT)
				dynamic_assign(dup_obj, obj->attributes[i].name, 0, *(double *)&obj->attributes[i].obj);
			else
				dynamic_assign(dup_obj, obj->attributes[i].name, obj->attributes[i].type, obj->attributes[i].obj, 0);
		}
	}
	return (dup_obj);
}