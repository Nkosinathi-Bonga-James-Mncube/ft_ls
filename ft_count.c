#include "ft_ls.h"
void ft_dir_check2(char *folder,DIR **dir)
{
	size_t k;
	char *s;
	struct stat b;
	char *y;

	k = 0;
	if (ft_strchr(folder,'/') != 0 && folder[0] != '/')
	{
		k = ft_strlen(folder) - ft_strlen(ft_strrchr(folder,'/'));
		y = ft_strsub(folder,0,k);
		stat(y,&b);
		if (S_ISDIR(b.st_mode))
			*dir = opendir(y);
		else 
		{
			ft_putstr("ls: ");
			ft_putstr(folder);
			ft_putstr(": No such file or directory");
			exit(1);
		}
		free(y);
	}
	else
		*dir = opendir(".");
}

int             ft_count(char *folder,int bfound)
{
	DIR             *dir;
	int             k;
	struct	dirent *dp;

	dir = opendir(folder);
	if (dir == NULL)
		ft_dir_check2(folder,&dir);
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' && bfound != 1)
			k++;
		if (bfound == 1)
			k++;
	}
	closedir(dir);
	return (k);
}
