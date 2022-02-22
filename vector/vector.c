#include "container.h"
#include <stdio.h>
#include <stdlib.h>


container* vector_create(size_t element_size)
{
	container* cont = (container*)malloc(sizeof(container) + sizeof(vector));
	if(cont == NULL)
	{
		return NULL;
	}

	cont->methods = (container_m*)malloc(sizeof(container_m));
	if(cont->methods == NULL)
	{
		free(cont);
		return NULL;
	}

	vector* v = (vector*)(cont + 1);

	v->size = 0;
	v->max_size = MAX_SIZE;
	v->data = (elem_t*)malloc(MAX_SIZE * sizeof(elem_t));
	if(v->data == NULL)
	{
		free(cont->methods);
		free(cont);
		return NULL;
	}
	cont->methods->insert = &vector_insert;
	cont->methods->delete = &vector_delete;
	cont->methods->push = &vector_push;
	cont->methods->pop = &vector_pop;
	cont->methods->get = &vector_get;
	cont->methods->size = &vector_size;
	cont->methods->print = &vector_print;
	cont->methods->swap = &vector_swap;
	cont->methods->destroy = &vector_destroy;

	return cont;
}

void vector_destroy(container* cont)
{
	vector* v = (vector*)(cont + 1);
	
	free(v->data);
	v->size = 0;
	v->max_size = 0;
	free(v);
	free(cont->methods);
	free(cont);
}

void vector_push(container* cont, elem_t data)
{
	vector* v = (vector*)(cont + 1);

	if(v->max_size == v->size)
	{
		v->max_size = v->max_size * 2;
		v->data = realloc(v->data, (v->max_size) * sizeof(elem_t));
	}
	v->size ++;
	v->data[v->size - 1] = data;
}

int vector_pop(container* cont)
{
	vector* v = (vector*)(cont + 1);

	if(v->size <= 0)
	{
		printf("bad position");
		return 1;
	}
	v->size--;
	return 0;
}

int vector_delete(container* cont, size_t n)
{
	vector* v = (vector*)(cont + 1);

	if(n < 0 || n > (v->size - 1) || v->size <= 0)
	{
		return 1;
	}

	for (int i = n; i < (v->size - 1); ++i)
	{
		v->data[i] = v->data[i+1];
	}

	v->size --;
	return 0;
}

int vector_insert(container* cont, size_t n, elem_t data)
{
	vector* v = (vector*)(cont + 1);

	if(n < 0 || n > v->size  || v->size <= 0)
	{
		printf("bad position\n");
		return 1;
	}

	if (v->max_size == v->size)
	{
		v->max_size = v->max_size * 2;
		v->data = realloc(v->data, (v->max_size) * sizeof(elem_t));
	}

	v->size ++;

	for(int i = v->size - 1; i > n; i--)
	{
		v->data[i] = v->data[i - 1];
	}

	v->data[n] = data;
	return 0;
}

void vector_print(container* cont)
{
	vector* v = (vector*)(cont + 1);

	for (int i = 0; i < v->size; ++i)
	{
		printf("%d\n", v->data[i]);
	}
}

void vector_swap(container* cont, size_t i, size_t j)
{
	vector* v = (vector*)(cont + 1);

	if(i < 0 || i > (v->size - 1))
	{
		printf("bad position\n");
		return;
	}
	if(j < 0 || j > (v->size - 1))
	{
		printf("bad position\n");
		return;
	}
	elem_t tmp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = tmp;
}

elem_t vector_get(container* cont, size_t n)
{
	vector* v = (vector*)(cont + 1);

	if(n < 0 || n > (v->size - 1))
	{
		printf("bad position\n");
		return 0;
	}

	return v->data[n];
}

size_t vector_size(container* cont)
{
	vector* v = (vector*)(cont + 1);

	return v->size;
}