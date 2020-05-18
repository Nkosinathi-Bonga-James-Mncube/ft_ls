#include "ft_ls.h"
#include "ft_options.c"
#include "ft_mod.c"
#include "ft_display.c"
#include "ft_bubble_sort.c"
#include "ft_details.c"
#include "ft_array.c"
#include "ft_count.c"
#include "ft_dir_search.c"
#include "ft_s.c"
#include "ft_arv_count.c"
#include "ft_folder_name.c"
#include "ft_free.c"
#include "ft_symbol_link.c"
#include "ft_error.c"
int main(int argc,char **argv)
{
	int k;
	int i;
	char *folder;

	i = 1;
	k =ft_arv_count(argv);
	k = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		i++;
		k++;
	}
	if (argv[i] != NULL)
	{
		while (argv[i])
		{
			if (ft_error(argv[i]) == 0)
				ft_options(argv[i],k,argv);
			i++;
		}
	}
	else
		ft_options(".",k,argv);
	return(0);
}
