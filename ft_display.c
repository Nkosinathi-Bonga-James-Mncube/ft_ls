/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:12 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/21 15:28:01 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
int ft_file(char *folder,int total,char **arr,char *y)
{
	int k;
	int j;
	char *s1;
	k = 0;

	if (ft_strchr(folder,'/') != 0 && folder[0] != '/')
		y = ft_strchr(folder, '/')+1;
	else
		y = folder;
	while (k < total)
	{
		if (ft_strcmp(y,arr[k]) == 0)
		{
			ft_putstr(folder);
			ft_putstr("\n");
			return (0);
		}
		k++;
	}
	ft_putstr("ls");
	ft_putstr(": ");
	ft_putstr(folder);
	ft_putstr(": ");
	ft_putstr("No such file or directory");
	return (0);
}

void ft_display(char *folder,char **arr,int total,int bfound)
{
	int j;
	int x;
	char *y;
	struct stat b1;

	j = 0;
	stat(folder,&b1);
	x  = S_ISDIR(b1.st_mode)?0:1;
	if (x == 1)
		ft_file(folder,total,arr,y);
	if (bfound == 1)
		j = total - 1;
	while (total > 0 && x == 0)
	{
		ft_putstr(arr[j]);
		if (total != 1)
			ft_putchar('\t');
		bfound == 1?j--:j++;
		total--;
	}
	if (ft_arv_count(NULL) > 1 && S_ISDIR(b1.st_mode))
		ft_putstr("\n\n");
}
