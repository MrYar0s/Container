#ifndef SPRING_LIST_LIST_H
#define SPRING_LIST_LIST_H

#include <stddef.h>

typedef int elem_t;

typedef struct container_ container;

typedef struct node_
{
	elem_t data;
	struct node_* next;
	struct node_* prev;
} node;

typedef struct list_
{
	size_t size;
	node* head;
	node* tail;
} list;

container* list_create();
void list_destroy(container* p);
int list_insert(container* p, elem_t data, size_t pos);
int list_delete(container* p, size_t pos);
elem_t list_get(container* p, size_t pos);
size_t list_size(container* p);
void list_print(container* p);
void list_swap(container* p, size_t first, size_t second);
elem_t list_head(container* p);
elem_t list_tail(container* p);

#endif //SPRING_LIST_LIST_H