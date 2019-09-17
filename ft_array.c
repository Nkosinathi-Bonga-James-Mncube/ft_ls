/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/17 16:02:43 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
//REMEBER TO CLOSE DIR/FILE!!!!!!!!!!!

char **ft_ls(char *folder,int total,int bfound,struct dirent *dp)
{
	DIR				*dir;
	int				k;
	char			**arr;
	char **hold2;//remove

	dir = opendir(folder);
	k = 0;
	if (dir == NULL)
		dir = opendir(".");
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
