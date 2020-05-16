#include "ft_ls.h"

void ft_dir_search(char *folder,char **y,int *b)
{
	char *s1;
	*y = ft_strrchr(folder,'/') + 1;
	*b = 1;
}
