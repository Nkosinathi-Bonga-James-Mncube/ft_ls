/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:51:19 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/17 16:02:04 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void ft_flag(char *folder ,int bfound ,struct options *flags)
{
	char **s1;
	int k;

	k = ft_count(folder,flags->a);
	s1 = ft_bubble_sort(ft_array(folder,flags->a),k);	
	if (flags->t == 1)
		s1 = ft_mod(folder,s1,k);
	if (flags->l == 1)
		ft_details(folder, s1, k,flags->r);
	if (flags->l != 1 || bfound == -1)
		ft_display(folder,s1,k,flags->r);
}

void	ft_bfound(char *folder,int bfound,struct options *flags)
{
	if (bfound == 0)
	{
		if (flags->l == 1)
			bfound = 0;
		else
			bfound = -1;
	}
	else
		bfound = 1;	
	if (bfound > 0)
		ft_putstr("Issue\n");
	else
		ft_flag(folder,bfound,flags);
}

int ft_check(char c1,char c2 , struct options *flags)
{
	if ( c1 == '-' && c2 == 'a')
		flags->a = 1;
	else
		if (c1 == '-' && c2== 'l')
			flags->l = 1;
		else
			if (c1 == '-' && c2 == 't')
				flags->t = 1;
			else
				if (c1 == '-' && c2 == 'r')
					flags->r = 1;
				else
				if (c1 == '-' && c2 == 'R')
					flags->R = 1;
				else
				return(1);
	return (0);
}

void ft_options(char *folder,int c,char **arr1)
{
	int k;
	int j;
	static int bfound;
	struct options *owner;

	k = 1;
	owner = (struct options*)malloc(sizeof(struct options));
	while(c > 1)
	{
		j = 1;
		if ((arr1[k][0] == '-' && arr1[k][j] == 0) || arr1[k][0] != '-')
				bfound = bfound + 1;
		while (arr1[k][j] != '\0')
		{
			bfound = bfound + ft_check(arr1[k][0] , arr1[k][j] , owner);
			j++;
		}
		c--;
		k++;
	}
	if (arr1[1] && arr1[1][0] == '-' && arr1[1][1] == '-' && bfound == 1)
		bfound = 0; 
	ft_bfound(folder,bfound, owner);
	free(owner);//<- RESTORE this!!!
}
