/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/22 14:10:32 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
//REMEBER TO CLOSE DIR/FILE!!!!!!!!!!!
void ft_dir_check(char *folder,DIR **dir)
{
	size_t k;
	char *s;
	struct stat b;

	k = 0;
	if (ft_strchr(folder,'/') != 0 && folder[0] != '/')
	{
		k = ft_strlen(folder) - ft_strlen(ft_strrchr(folder,'/'));
		stat(ft_strsub(folder,0,k),&b);
		if (S_ISDIR(b.st_mode))
			*dir = opendir(ft_strsub(folder,0,k));
		else
		{
			ft_putstr("ls :\n");
			ft_putstr(ft_strsub(folder,0,k));
 			ft_putstr("No such file or directory");
			exit(1);
		}
	}
		else
			*dir = opendir("."); 
}

char **ft_ls(char *folder,int total,int bfound,struct dirent *dp)
{
	DIR				*dir;
	int				k;
	char			**arr;
	dir = opendir(folder);
	k = 0;
	if (dir == NULL)
		ft_dir_check(folder,&dir);
	arr = (char**)malloc(total * sizeof(char*));
	while ((dp = readdir(dir)) != NULL && total > 0)
	{
		if (dp->d_name[0] != '.' && bfound != 1)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
		if (bfound == 1)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
	}
	closedir(dir);
	return (arr);
}

char **ft_array(char *folder,int bfound)
{
	int total;
	char **hold;
	struct dirent *dp;

	total = 0;
	hold = ft_ls(folder,ft_count(folder,bfound),bfound,dp);
	return (hold);
}
