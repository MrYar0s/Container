#include "container.h"
#include <stdlib.h>
#include <stdio.h>

container* list_create()
{
	container* cont = (container*) malloc(sizeof(container) + sizeof(list));
	if(cont == NULL)
	{
		return NULL;
	}

	cont->methods = (container_m*) malloc(sizeof(container_m));
	if(cont->methods == NULL)
	{
		free(cont);
		return NULL;
	}

	list* tmp = (list*)(cont + 1);

	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;

	cont->methods->insert = &list_insert;
	cont->methods->delete = &list_delete;
	cont->methods->get = &list_get;
	cont->methods->size = &list_size;
	cont->methods->print = &list_print;
	cont->methods->swap = &list_swap;
	cont->methods->head = &list_head;
	cont->methods->tail = &list_tail;
	cont->methods->destroy = &list_destroy;

	return cont;
}

void list_destroy(container* cont)
{
	list* p = (list*)(cont + 1);
	node *tmp = p->head;
	node *next = NULL;
	while(tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(cont->methods);
	free(cont);
}

int list_insert(container* cont, elem_t data, size_t pos)
{
	list* p = (list*)(cont + 1);
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

int list_delete(container* cont, size_t pos)
{
	list* p = (list*)(cont + 1);
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

elem_t list_get(container* cont, size_t pos)
{
	list* p = (list*)(cont + 1);
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

size_t list_size(container* cont)
{
	list* p = (list*)(cont + 1);
	return p->size;
}

void list_print(container* cont)
{
	list* p = (list*)(cont + 1);
	size_t sz = p->size;
	node* cur = p->head;
	for(size_t i = 0; i < sz; i++)
	{
		printf("[%ld] = %d\n", i, cur->data);
		cur = cur->next;
	}
	printf("size = %ld\n", p->size);
}

void list_swap(container* cont, size_t first, size_t second)
{
	list* p = (list*)(cont + 1);
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

elem_t list_head(container* cont)
{
	list* p = (list*)(cont + 1);
	return p->head->data;
}

elem_t list_tail(container* cont)
{
	list* p = (list*)(cont + 1);
	return p->tail->data;
}
