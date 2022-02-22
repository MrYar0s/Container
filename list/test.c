#include "container.h"
#include <stdlib.h>
#include <time.h>

static const size_t sz = 1e6;

void sort(container* cont)
{
	for(size_t i = 0; i < sz; i++)
	{
		for(size_t j = 0; j < sz-1; j++)
		{
			elem_t first = cont->methods->get(cont, j);
			elem_t second = cont->methods->get(cont, j+1);
			if(first > second)
			{
				cont->methods->swap(cont, j, j+1);
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	container* cont = list_create();

	for(size_t i = 0; i < sz; i++)
	{
		list_insert(cont, rand(), i);
	}

	sort(cont);
	cont->methods->print(cont);
	cont->methods->destroy(cont);

	return 0;
}
