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
		stat(arr[i], &b1);
		printf("%s\n" , arr[i]);
		//b2 = getgrgid(b1.st_gid);
		//hold = ctime(&b1.st_mtime);
		//ft_date(b1, i);
		//struct stat b1;
		printf("%ld\n" , b1.st_mtime);
		printf("%s\n" ,ctime(&b1.st_mtime));
		printf("-----------\n");
		//printf("\n%ld->\n" , seconds);
		//seconds = time((char*)ctime(&b1.st_mtime));
		//ft_putstr(ctime(&b1.st_mtime));
		i++;
		//printf("\nvalue :%lld\n" , b1.st_size);
	}

}
