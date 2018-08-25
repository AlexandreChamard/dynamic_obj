
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

void *dynamic_get(dynamic_obj_t const *obj, char const *attribute_name)
{
	for (size_t i = 0; i < obj->n_attribute; ++i)
		if (strcmp(obj->attributes[i].name, attribute_name) == 0)
			return (obj->attributes[i].obj);
	fprintf(stderr, "error : %s is not a valid atribute\n", attribute_name);
	abort();
}

void *dynamic_valueof(dynamic_obj_t const *obj)
{
	for (size_t i = 0; i < obj->n_attribute; ++i)
		if (strcmp(obj->attributes[i].name, "_") == 0)
			return (obj->attributes[i].obj);
	fprintf(stderr, "error : obj hasn't value\n");
	abort();
}