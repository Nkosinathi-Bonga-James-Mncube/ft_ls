/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_details.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:14:21 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/20 17:03:31 by nmncube          ###   ########.fr       */
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

void ft_output2(struct group *b1,struct passwd *b2,struct stat b,char *arr)
{
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
		ft_putstr(ft_strsub(ctime(&b.st_mtime),4,12));//memalloced//
		ft_putchar('\t');
		ft_putstr(arr);
}

void ft_output(char *folder,char **arr, int total,int bfound)
{
	struct stat b;
	struct group *b1;
	struct passwd *b2;
	char *s3;
	int j;
	
	j = 0;
	if (bfound == 1)
		j = total - 1;
	stat(folder,&b);
	s3 = S_ISDIR(b.st_mode)?ft_strjoin(folder,"/"):ft_strjoin("./",folder);
	while (total > 0)
	{
		ft_putchar('\n');
		stat(ft_strjoin(s3, arr[j]),&b);
		ft_output2(b1,b2,b,arr[j]);
		bfound == 1? j--:j++; 
		total--;
	}
	//ft_putstr("\n");
}

void ft_details(char *folder,char **arr, int total,int bfound)
{
	int k;
	int b;
	char *y;
	struct stat x;
	
	k = -1;
	stat(folder,&x);
	b = S_ISDIR(x.st_mode)?0: 1;
	if (ft_strchr(folder, '/') != 0 && folder[0]!= '/')//
		ft_dir_search(folder,&y,&b);//
	else
		y = folder;// uturnary method;
	if (b == 1)
	{
		while (++k < total)
		{
			b = ft_strcmp(y,arr[k]) == 0?1:-1;
			if (b == 1)
				break ;
		}
	}
	if (b == 0)
		ft_output(folder,arr, total,bfound);
	else
		if (b == 1)
			ft_output(folder,&folder, 1,bfound);
		else
			ft_putstr("\nls :No such file or directory\n");
}	
