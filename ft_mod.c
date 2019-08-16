#include "ft_ls.h"

void ft_date(struct stat b1, int i)
{
	printf("%ld" , time(&b1.st_mtime));
	//struct stat b1;
}
void ft_mod(char **arr, int total)
{
	struct group *b2;
	struct stat b1;
	struct stat b3;
	int i;
	int j;
	//time_t seconds;
	char *hold;

	i = 0;
	j = 0;
	printf("\n");
	while (i < total)
	{
		
		//struct stat b1 {0};
		stat((void*)(*(arr++)), &b1);
		//printf("%s" , (void*)(*(arr++)));
		//b2 = getgrgid(b1.st_gid);
		//hold = ctime(&b1.st_mtime);
		ft_date(b1, i);
		//struct stat b1;
		//printf("%ld\n" , time(&b1.st_mtime));
		//printf("\n%ld->\n" , seconds);
		//seconds = time((char*)ctime(&b1.st_mtime));
		//ft_putstr(ctime(&b1.st_mtime));
		i++;
		printf("\nvalue :%lld\n" , b1.st_size);
	}

}
