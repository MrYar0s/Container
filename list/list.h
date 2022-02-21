#ifndef SPRING_LIST_LIST_H
#define SPRING_LIST_LIST_H

#include <stddef.h>

typedef int elem_t;

typedef struct node_ node;
typedef struct list_ list;

list* list_create();
void list_destroy(list* p);
int list_insert(list* p, elem_t data, size_t pos);
int list_delete(list* p, size_t pos);
void list_push(list* p);
int list_pop(list* p);
elem_t list_get(list* p, size_t pos);
size_t list_size(list* p);
void list_print(list* p);
void list_swap(list* p, size_t first, size_t second);
node* list_head(list* p);
node* list_tail(list* p);

#endif //SPRING_LIST_LIST_H