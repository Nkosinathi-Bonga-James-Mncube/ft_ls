#include "ft_ls.h"

char *ft_s3_change(char *s3,char **arr,int j)
{
	char *temp;
	char *s2;
	s2 = s3;
	temp = ft_strjoin(s2,arr[j]);
	//free(temp);
	//temp = s2;
	return(temp);
}
