#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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

list* list_create()
{
	list* tmp = (list*) malloc(sizeof(list));
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return tmp;
}

void list_destroy(list* p)
{
	node *tmp = p->head;
	node *next = NULL;
	while(tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(p);
	p = NULL;
}

int list_insert(list* p, elem_t data, size_t pos)
{
	if(pos > p->size)
	{
		printf("bad position\n");
		return -1;
	}
	
	node* tmp = (node*) malloc(sizeof(node));
        tmp->data = data;
	
	if(p->size == 0)
	{
		p->head = tmp;
		p->tail = tmp;
		p->size++;
		return 0;
	}

	node* cur = p->head;
	for(size_t i = 1; i < pos; i++)
	{
		cur = cur->next;
	}

	tmp->next = cur->next;
	cur->next = tmp;

	tmp->prev = cur;

	if(tmp->next != NULL)
	{
		tmp->next->prev = tmp;
	}
	
	if(tmp->prev == p->tail)
	{
		p->tail = tmp;
	}

	p->size++;

	return 0;
}

int list_delete(list* p, size_t pos)
{
	if(pos >= p->size)
	{
		printf("bad position\n");
		return -1;
	}

	node* del = p->head;
	for(size_t i = 0; i < pos; i++)
	{
		del = del->next;
	}
	node* nextp = del->next;
	node* prevp = del->prev;

	del->next = NULL;
	del->prev = NULL;
	del->data = 0;
	p->size--;

	if(nextp == NULL && prevp == NULL)
	{
		p->head = NULL;
		p->tail = NULL;
		return 0;
	}

	if(nextp != NULL && prevp != NULL)
	{
		nextp->prev = prevp;
		prevp->next = nextp;
	}

	if(nextp == NULL)
	{
		prevp->next = NULL;
		p->tail = prevp;
	}

	if(prevp == NULL)
	{
		nextp->prev = NULL;
		p->head = nextp;
	}

	free(del);
	return 0;
}

elem_t list_get(list* p, size_t pos)
{
	if(pos >= p->size)
	{
		printf("bad position\n");
		return -1;
	}

	node* cur = p->head;
	for(size_t i = 0; i < pos; i++)
	{
		cur = cur->next;
	}
	
	return cur->data;
}

void list_print(list* p)
{
	size_t sz = p->size;
	node* cur = p->head;
	for(size_t i = 0; i < sz; i++)
	{
		printf("[%ld] = %d\n", i, cur->data);
		cur = cur->next;
	}
	printf("size = %ld\n", p->size);
}

void list_swap(list* p, size_t first, size_t second)
{
	if(first > p->size || second > p->size)
	{
		printf("bad position\n");
		return;
	}
	node* n_first = p->head;
	for(size_t i = 0; i < first; i++)
	{
		n_first = n_first->next;
	}
	node* n_second = p->head;
        for(size_t i = 0; i < second; i++)
        {
                n_second = n_second->next;
        }
	elem_t tmp = n_first->data;
	n_first->data = n_second->data;
	n_second->data = tmp;
}

node* list_head(list* p)
{
	return p->head;
}

node* list_tail(list* p)
{
	return p->tail;
}
