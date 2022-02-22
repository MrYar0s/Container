#ifndef vector_h
#define vector_h

#include <stddef.h>

#define MAX_SIZE 5

typedef struct container_ container;

typedef int elem_t;

typedef struct{
	size_t size;
	size_t max_size;
	elem_t* data;
}vector;

container* vector_create(size_t element_size);
void vector_destroy(container* cont);

int vector_delete(container* cont, size_t n);
int vector_insert(container* cont, size_t n, elem_t data);
void vector_push(container* cont, elem_t data);
int vector_pop(container* cont);

elem_t vector_get(container* cont, size_t n);
size_t vector_size(container* cont);

void vector_print(container* cont);
void vector_swap(container* cont, size_t i, size_t j);

#endif