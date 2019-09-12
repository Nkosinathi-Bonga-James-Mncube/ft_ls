#include "ft_ls.h"

int             ft_count(char *folder,int bfound)
{
	DIR             *dir;
	int             k;
	struct	dirent *dp;
	//char **hold3;//remove

	//hold3 = (char**)malloc(1 *sizeof(char));//remove
	dir = opendir(folder);
	if (dir == NULL)
	{
		//dir = opendir(".");		
		ft_putstr("Cannot open\n");
		exit(1);
	}
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
