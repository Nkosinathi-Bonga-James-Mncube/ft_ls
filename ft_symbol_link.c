#include "ft_ls.h"

void ft_symbol_link(char *arr,char *y)
{	
        int i;
        char name[1000] = {};
	readlink(y, name, 1000);
	ft_putstr(name);
}

