#ifndef SPRING_CONTAINER_CONTAINER_H
#define SPRING_CONTAINER_CONTAINER_H

#include "list.h"

typedef struct container_ container;

typedef struct container_m_
{
	int (*insert) (container* p, elem_t data, size_t pos);
	int (*delete) (container* p, size_t pos);
	elem_t (*get) (container* p, size_t pos);
	size_t (*size) (container* p);
	void (*print) (container* p);
	void (*swap) (container* p, size_t first, size_t second);
	elem_t (*head) (container* p);
	elem_t (*tail) (container* p);
	void (*destroy) (container* p);
} container_m;

typedef struct container_
{
	container_m* methods;
} container;

container* list_create();

#endif //SPRING_CONTAINER_CONTAINER_H
