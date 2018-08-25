
#include <stdio.h>

#include "dynamic.h"

int main()
{
	dynamic_obj_t obj = DEFAULT_DYNAMIC_OBJ;

	dynamic_assign(&obj, NULL, DYN_INT, 42);
	print_deep_dynamic_obj(&obj);
	dynamic_assign(&obj, "oui", DYN_STR, "bonjour");
	print_deep_dynamic_obj(&obj);
	dynamic_assign(&obj, NULL, DYN_STR, "foo");
	print_deep_dynamic_obj(&obj);

	dynamic_obj_t *dup_obj = dynamic_dup(&obj);

	puts(dynamic_valueof(dup_obj));

	dynamic_assign(dup_obj, "float", DYN_FLOAT, 42.42);
	dynamic_assign(dup_obj, "int", DYN_INT, 30);
	void *bla = dynamic_valueof(dynamic_get(dup_obj, "int"));
	void *bla2 = dynamic_valueof(dynamic_get(dup_obj, "float"));
	printf("\n%ld %d\n", CAST(long)bla, CAST(int)bla);
	printf("%f\n", CAST(double)bla2);
	puts("\ndup_obj :");
	print_deep_dynamic_obj(dup_obj);
	puts("\nobj :");
	print_deep_dynamic_obj(&obj);

	free_dynamic_obj(&obj);
	free_dynamic_obj(dup_obj);
}