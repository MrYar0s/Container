#ifndef container_h
#define container_h

#include <stddef.h>
#include "vector.h"
#include "list.h"

typedef struct container_ container;

typedef struct container_m_{
	int(*insert) (container* p, size_t n, elem_t data);
	int(*delete) (container*p, size_t n);
	void(*push) (container* p, elem_t data);
	int(*pop) (container*p);

	elem_t(*get) (container* p, size_t n);
	size_t(*size) (container* p);

	void(*print) (container* p);
	void(*swap) (container* p, size_t i, size_t j);
	void(*destroy) (container* p);
}container_m;

typedef struct container_{
	container_m* methods;
}container;

container* vector_create(size_t element_size);

#endif //container_h