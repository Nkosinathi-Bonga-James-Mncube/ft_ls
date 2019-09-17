#include "ft_ls.h"

int             ft_count(char *folder,int bfound)
{
	DIR             *dir;
	int             k;
	struct	dirent *dp;

	dir = opendir(folder);
	if (dir == NULL)
		dir = opendir(".");
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' && bfound != 1)
			k++;
		if (bfound == 1)
			k++;
	}
	//free(dir);
	return (k);
}
