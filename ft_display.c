/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:12 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/17 14:09:58 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int ft_file(char *folder,int total,char **arr)
{
	int k;
	k = 0;
	while (k < total)
	{
		if (ft_strcmp(folder,arr[k]) == 0)
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
	ft_putstr("Not valid file or folder");
	return (0);
}

void ft_display(char *folder,char **arr,int total,int bfound)
{
	int j;
	int x;
	struct stat b1;

	j = 0;
	stat(folder,&b1);
	x  = S_ISDIR(b1.st_mode)?0:1;
	if (x == 1)
		ft_file(folder,total,arr);
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
}
