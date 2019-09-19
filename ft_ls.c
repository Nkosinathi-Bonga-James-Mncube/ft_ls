#include "ft_ls.h"
#include "ft_options.c"
#include "ft_mod.c"
#include "ft_display.c"
#include "ft_bubble_sort.c"
#include "ft_details.c"
#include "ft_array.c"
#include "ft_count.c"
#include "ft_dir_search.c"
int main(int argc,char **argv)
{
	//ls - -l .
	int k;
	int i;
	char *folder;
	k = 1;
	i = 1;
	
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		i++;
		k++;
	}
	if (argv[i] != NULL)
	{
		while (argv[i])
		{
			folder = argc == 1? ".":argv[i];
			ft_options(folder,k,argv);
			i++;
		}
	}
	else
		ft_options(".",k,argv);
	return(0);
}
