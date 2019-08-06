/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/06 16:31:25 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>//if I remove this , the program doesnt work?
#include "libft/libft.h"
#include "ft_bubble_sort.c"
void	ft_ls(int total)
{
	DIR				*dir;
	int				k;
	int				j;
	struct dirent	*dp;
	char			**arr;

	dir = opendir(".");
	k = 0;
	j = 0;
	if (dir == NULL)
	{
		perror("Cannot open");
		exit(1);
	}
	arr = (char**)malloc(total * sizeof(char*));
	while ((dp = readdir(dir)) != NULL && total > 0)
	{
		if (dp->d_name[0] != '.')
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
	}
	ft_bubble_sort(arr, total);
}
int		ft_count(void)
{
	DIR				*dir;
	static int		k;
	struct dirent	*dp;

	dir = opendir(".");
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.')
			k++;
	}
	return (k);
}

int		main(int argc, char**argv)
{
	static int total;

	if (argc == 2 && argv[1][0] == 'l' && argv[1][1] == 's')
	{
		total = total + ft_count();
		ft_ls(total);
	}	
	return (0);
}
