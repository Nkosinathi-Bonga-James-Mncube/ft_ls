#include "ft_ls.h"

void ft_mod(char **arr, int total)
{
	struct group *b2;
	struct stat b1;
	int i;

	i = 0;
	while (i < total)
	{
		stat(arr[i] , &b1);
		b2 = getgrgid(b1.st_gid);
		ft_putstr(ctime(&b1.st_mtime));
		i++;
	}

}
