#include "ft_ls.h"

void ft_symbol_link(char *arr)
{	
	struct stat p;
        int i;
        int temp;
        char name[1000] = {};

	readlink(arr, name, 1000);
	ft_putstr(name);
}

