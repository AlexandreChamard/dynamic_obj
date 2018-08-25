
#include <string.h>

#include "dynamic.h"

/* arguments must not be null */
dynamic_attribute_t	*dynamic_find_attribute(dynamic_obj_t const *obj, char const *attribute_name)
{
	if (obj->n_attribute == 0)
		return (NULL);
	for (size_t i = 0; i < obj->n_attribute; ++i)
		if (strcmp(obj->attributes[i].name, attribute_name) == 0)
			return (&obj->attributes[i]);
	return (NULL);
}