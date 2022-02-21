#include "list.h"
#include <stdlib.h>
#include <time.h>

static const size_t sz = 10;

void sort(list* cont)
{
	for(size_t i = 0; i < sz; i++)
	{
		for(size_t j = 0; j < sz-1; j++)
		{
			elem_t first = list_find(cont, j);
			elem_t second = list_find(cont, j+1);
			if(first > second)
			{
				list_swap(cont, j, j+1);
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	list* cont = list_create();
	
	for(size_t i = 0; i < sz; i++)
	{
		list_insert(cont, rand(), i);
	}

	sort(cont);
	list_print(cont);
	list_destroy(cont);

	return 0;
}
