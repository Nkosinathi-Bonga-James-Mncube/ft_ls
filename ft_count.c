#include "ft_ls.h"

int             ft_count(int bfound)
{
	DIR             *dir;
	int             k;
	struct	dirent *dp;

	dir = opendir("libft/");
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' && bfound != 1)
			k++;
		if (bfound == 1)
			k++;
	}
	printf("counter :%d\n" , k);//delete
	//free(dir);
	return (k);
}
