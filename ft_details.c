#include "ft_ls.h"

void ft_details(char **arr)
{
	struct stat b;
	struct group *b1;
	struct passwd *b2;

	stat(arr[6],&b);
	b1 = getgrgid(b.st_gid);
	b2 = getpwuid(b.st_uid);
	ft_putstr("\n---------------------\n");//delete
	ft_putnbr(b.st_nlink);
	ft_putchar('\t');
	ft_putstr(b2->pw_name);
	ft_putchar('\t');
	ft_putstr(b1->gr_name);
	ft_putchar('\t');
	ft_putnbr(b.st_size);
	ft_putchar ('\t');
	ft_putstr(ft_strsub(ctime(&b.st_mtime),4,12));
	ft_putchar('\t');
	printf("%s" , arr[6]);
}
