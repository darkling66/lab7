// lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "matrix.h"

int main()
{
	const char* menu_items[] =
	{
		"Full Matix"
		, "Partial Matrix"
		, NULL
	};
	handler_t handlers[] = {
		tab_handler1
		, tab_handler2
	};
	int idx;
	do {
		idx = menu(menu_items);
		if (idx < 0)
		{
			perror("Error index handler\n");
			return -1;
		}
		if (handlers[idx](NULL))
		{
			perror("Error handling\n");
		}
	} while (idx >= 0);
	getchar();
	return 0;
}

int menu(const char* menu_items[])
{
	int n;
	for (n = 0; menu_items[n]; ++n)
	{
		printf("\t[%d]. %s\n", n, menu_items[n]);
	}

	int i = -1;
	printf("\tChoice: ");
	if (scanf("%d", &i) == 1)
	{
		if (i >= 0 && i < n)
		{
			return i;
		}
	}
	return i;
}
