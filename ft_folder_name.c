#include "ft_ls.h"

void ft_folder_name(int l,int bfound, struct stat b,char *folder)
{
	if (l == 1)
	{
		if (ft_arv_count(NULL) > 1 && S_ISDIR(b.st_mode))
		{
			ft_putstr("\n");
			ft_putstr(folder);
			ft_putstr(": \n");
		}
	}
	if (l != 1 || bfound == -1)
	{
		if (ft_arv_count(NULL) > 1 && S_ISDIR(b.st_mode))
		{
			ft_putstr(folder);
			ft_putstr(": \n");
		}
	}
}
