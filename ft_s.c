#include "ft_ls.h"

int ft_s(char *folder)
{
	int bfound;
	int k;
	char *s1;
	bfound = 0;
	k = 0;

	s1 = ft_strrchr(folder, '/') +1;
	k = s1[0] == '\0'? 1:0;
	if ((s1[0] == '.' && s1[1] == '.') || (s1[0] == '.' && s1[1] == '/')) 
		k = 1;
	return (k);
}
