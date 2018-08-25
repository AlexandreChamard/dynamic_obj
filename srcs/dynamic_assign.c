
#include <string.h>

#include "dynamic.h"

void	assign_attribute(dynamic_attribute_t *attr, obj_type_e type, void *value, double f_value)
{
	free_attribute(attr);
	attr->type = type;

	switch (type) {
		case DYN_OBJ:	attr->obj = value;break;
		case DYN_FUNC:	attr->obj = value;break;
		case DYN_STR:	attr->obj = strdup(value);break;
		case DYN_CHAR:	attr->obj = value;break;
		case DYN_INT:	attr->obj = value;break;
		case DYN_FLOAT:	CAST(double)attr->obj = f_value;break;
		default:break;
	}
}

void	vdynamic_assign(dynamic_obj_t *obj, char const *name, obj_type_e type, va_list ap)
{
	name = ATTR_NAME(name);

	dynamic_attribute_t *attr = dynamic_find_attribute(obj, name);

	if (attr == NULL)
		attr = create_attribute(obj, name);
	if (strcmp(name, "_") == 0) {
		if (type != DYN_FLOAT)
			assign_attribute(attr, type, va_arg(ap, void *), 0);
		else
			assign_attribute(attr, type, 0, va_arg(ap, double));
	} else {
		assign_attribute(attr, DYN_OBJ, vcreate_dynamic_obj(type, ap), 0);
	}
}

void	dynamic_assign(dynamic_obj_t *obj, char const *name, obj_type_e type, ...)
{
	va_list ap;

	va_start(ap, type);
	vdynamic_assign(obj, name, type, ap);
	va_end(ap);
}