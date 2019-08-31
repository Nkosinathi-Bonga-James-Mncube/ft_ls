/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_details.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:14:21 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/30 14:51:41 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

 
void ft_permission1(struct stat b)
{
	ft_putstr((S_ISDIR(b.st_mode))  ? "d" : "-");
	ft_putstr((b.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((b.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((b.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((b.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((b.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((b.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((b.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((b.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((b.st_mode & S_IXOTH) ? "x" : "-");
	ft_putchar('\t');
}

void ft_output(char **arr, int total,int bfound,int j)
{
	struct stat b;
	struct group *b1;
	struct passwd *b2;

	while (total > 0)
	{
		ft_putchar('\n');
		stat(ft_strjoin("libft/", arr[j]),&b);
		b1 = getgrgid(b.st_gid);
		b2 = getpwuid(b.st_uid);
		ft_permission1(b);
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
		ft_putstr(arr[j]);
		bfound == 1? j--:j++; 
		total--;
	}
}

void ft_details(char **arr, int total,int bfound)
{
	int j;

	j = 0;
	if (bfound == 1)
		j = total-1;
	ft_output(arr, total,bfound,j);	
}	
