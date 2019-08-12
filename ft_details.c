#include "ft_ls.h"
//#include "libft/libft.h"//cant have this here
void ft_details(char **arr)
{
	struct stat b;
	struct group *b1;
	struct passwd *b2;
	//char *s1;
	//s1 = ft_strnew(100);
	stat(arr[7],&b);
	b1 = getgrgid(b.st_gid);//w1
	b2 = getpwuid(b.st_uid);
	//if (getgram())
	//getpwnam(b1);
	//passwd(arr[7], &passwd);
	//printf("->%s\n" , arr[1]);//delet this
	ft_putstr("\n---------------------\n");
	ft_putnbr(b.st_nlink);
	ft_putchar('\t');
	ft_putstr(b2->pw_name);
	ft_putchar('\t');
	ft_putstr(b1->gr_name);
	ft_putchar('\t');
	ft_putnbr(b.st_size);
	ft_putchar ('\t');
	ft_putstr(arr[7]);
	//t_putstr(b.st_uid);
}
