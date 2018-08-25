
#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef enum obj_type {
	DYN_NONE, DYN_OBJ, DYN_FUNC, DYN_STR, DYN_CHAR, DYN_INT, DYN_FLOAT
}	obj_type_e;

typedef struct dynamic_attribute {
	char 			*name;
	obj_type_e		type;
	void			*obj; /* this is not a pointer ; this is just a 8 bytes mem  */
}	dynamic_attribute_t;

typedef struct dynamic_obj {
	int			to_free; /* 0 = not alloced | 1 = to free | 1+n = have n pointer */
	char const		*obj_type;
	size_t			n_attribute;
	dynamic_attribute_t	*attributes;
}	dynamic_obj_t;

#define DEFAULT_DYNAMIC_OBJ {}

#define ATTR_NAME(name)	((name) ? (name) : "_")
#define CAST(type)	*(type *)&

dynamic_attribute_t	*dynamic_find_attribute(dynamic_obj_t const *obj, char const *attribute_name);

/* assign */
void	assign_attribute(dynamic_attribute_t *attr, obj_type_e type, void *value, double f_value);
void	vdynamic_assign(dynamic_obj_t *obj, char const *name, obj_type_e type, va_list ap);
void	dynamic_assign(dynamic_obj_t *obj, char const *name, obj_type_e type, ...);

/* create */
dynamic_obj_t		*dynamic_alloc(void);
dynamic_attribute_t	*create_attribute(dynamic_obj_t *obj, char const *name);
dynamic_obj_t		*vcreate_dynamic_obj(obj_type_e type, va_list ap);
dynamic_obj_t		*create_dynamic_obj(obj_type_e type, ...);

/* dup */
dynamic_obj_t	*dynamic_dup(dynamic_obj_t const *obj);

/* get */
void	*dynamic_get(dynamic_obj_t const *obj, char const *attribute_name);
void	*dynamic_valueof(dynamic_obj_t const *obj);

/* free */
void	free_attribute(dynamic_attribute_t *attr);
void	free_dynamic_obj(dynamic_obj_t *obj);

/* print */
void	print_dynamic_obj(dynamic_obj_t const *obj);
void	print_deep_dynamic_obj(dynamic_obj_t const *obj);
