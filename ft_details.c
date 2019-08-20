#include "ft_ls.h"

//void 
/*void ft_permission1(struct stat b)
{
	if (S_ISDIR(b.st_mode))
		ft_putstr("d");
	else
		ft_putchar('-');

	if (b.st_mode & S_IRUSR)
		ft_putstr("r");
	else
		ft_putchar('-');

	if (b.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');

	ft_putchar('\t');
}*/

void ft_details(char **arr, int total)
{
	struct stat b;
	struct group *b1;
	struct passwd *b2;
	int i;

	i = 0;
	while (i < total)
	{
		ft_putchar('\n');
		stat(ft_strjoin("libft/", arr[i]),&b);
		//ft_permission(b);
		b1 = getgrgid(b.st_gid);
		b2 = getpwuid(b.st_uid);
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
		ft_putstr(arr[i]);
		i++;
	}
}
