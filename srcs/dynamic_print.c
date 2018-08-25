
#include <stdio.h>
#include <stdbool.h>

#include "dynamic.h"

static void	print_dynamic_attribute(dynamic_attribute_t const *attr, bool full)
{
	if (full == true)
		printf("%s :\t", attr->name);
	switch (attr->type) {
		case DYN_OBJ:	print_dynamic_obj(attr->obj);break;
		case DYN_FUNC:	printf("%p\n", attr->obj);break;
		case DYN_STR:	puts(attr->obj);break;
		case DYN_CHAR:	printf("%c\n", *(char *)&attr->obj);break;
		case DYN_INT:	printf("%ld\n", *(long *)&attr->obj);break;
		case DYN_FLOAT:	printf("%.3f\n", *(double *)&attr->obj);break;
		default:break;
	}
}

void	print_dynamic_obj(dynamic_obj_t const *obj)
{
	dynamic_attribute_t *attr = dynamic_find_attribute(obj, "_");

	if (attr != NULL)
		print_dynamic_attribute(attr, false);
}

void	print_deep_dynamic_obj(dynamic_obj_t const *obj)
{
	for (size_t i = 0; i < obj->n_attribute; ++i)
		print_dynamic_attribute(&obj->attributes[i], true);
}
