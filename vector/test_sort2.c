#include <stdlib.h>
#include <stdio.h>
#include "container.h"
#define NUM 25

int main(int argc, char const *argv[])
{
	container* p = vector_create(sizeof(elem_t));
	
	for (int i = 0; i < NUM; ++i)
	{
		p->methods->push(p, rand());
	}
	printf("CONTAINER BEFORE SORT:\n");
	p->methods->print(p);
	int swap;

	for (int i = (p->methods->size(p) - 1); i >= 0; --i)
	{
		swap = 0;

		for (int j = 0; j < i; ++j)
		{
			if(p->methods->get(p, j) > p->methods->get(p, j + 1))
			{
				p->methods->swap(p, j, j + 1);
				swap = 1;
			}
		}

		if(swap == 0)
		{
			break;
		}
	}
	printf("CONTAINER AFTER SORT:\n");
	p->methods->print(p);
	return 0;
}