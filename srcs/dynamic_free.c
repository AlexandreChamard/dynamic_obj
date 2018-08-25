
#include <stdlib.h>

#include "dynamic.h"

void	free_attribute(dynamic_attribute_t *attr)
{
	if (attr->type == DYN_OBJ || attr->type == DYN_STR) {
		if (attr->type == DYN_OBJ) {
			/* free object (all his attributes) ; peux poser des problèmes si double inclusion */
			free_dynamic_obj(attr->obj);
		} else {
			free(attr->obj);
		}
	}
}

void	free_dynamic_obj(dynamic_obj_t *obj)
{
	for (size_t i = 0; i < obj->n_attribute; ++i) {
		free_attribute(&obj->attributes[i]);
		free(obj->attributes[i].name);
	}
	free(obj->attributes);
	if (obj->to_free == 1)
		free(obj);
}