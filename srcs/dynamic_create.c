
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

dynamic_obj_t	*dynamic_alloc(void)
{
	dynamic_obj_t *obj = malloc(sizeof(*obj));

	if (obj == NULL) {
		perror("malloc");
		abort();
	}
	bzero(obj, sizeof(*obj));
	obj->to_free = 1;
	return (obj);
}

dynamic_obj_t	*vcreate_dynamic_obj(obj_type_e type, va_list ap)
{
	dynamic_obj_t *obj = dynamic_alloc();

	vdynamic_assign(obj, "_", type, ap);
	return (obj);
}

dynamic_attribute_t	*create_attribute(dynamic_obj_t *obj, char const *name)
{
	++obj->n_attribute;
	obj->attributes = realloc(obj->attributes, sizeof(dynamic_attribute_t) * obj->n_attribute);
	obj->attributes[obj->n_attribute - 1].name = strdup(name);
	obj->attributes[obj->n_attribute - 1].type = DYN_NONE;
	obj->attributes[obj->n_attribute - 1].obj = NULL;
	return (&obj->attributes[obj->n_attribute - 1]);
}

dynamic_obj_t	*create_dynamic_obj(obj_type_e type, ...)
{
	va_list ap;

	va_start(ap, type);

	dynamic_obj_t *obj = vcreate_dynamic_obj(type, ap);

	va_end(ap);
	return (obj);
}