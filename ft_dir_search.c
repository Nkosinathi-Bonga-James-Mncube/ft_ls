#include "ft_ls.h"

void ft_dir_search(char *folder,char **y,int *b)
{
	char *s1;
	//printf("%s",folder);
	//printf("%s", "hello");
	//printf("%s",ft_memccpy(ft_strrchr(folder,'/'),ft_strrchr(folder, '/'),'/',1));
	//*y = ft_strdup(ft_memccpy(ft_strrchr(folder,'/'),ft_strrchr(folder, '/'),'/',1));
	*y = ft_strrchr(folder,'/') + 1;
	*b = 1;
}
