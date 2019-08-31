/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:51:19 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/30 13:36:08 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void ft_flag(int bfound ,struct options *flags)
{
	char **s1;
	int k;

	k = ft_count(flags->a);
	printf("count : %d\n",k);
	s1 = ft_array(flags->a);
	if (flags->R == 1)
		ft_putstr("-R actived\n");
	if (flags->a == 1)
		ft_putstr("-a activated \n");
	if (flags->t == 1)
		ft_putstr("-t activated\n");
	if (flags->r == 1)
		ft_putstr("-r activated\n");
	if (flags->l == 1)
		ft_putstr("-l view Display\n");
	if (flags->l != 1 || bfound == -1)
	{
		ft_putstr("-Display in standard output\n");
		ft_display(s1,k,flags->r);
	}
	//ft_putnbr(k);
	while (k >= 0)
	{
		free(s1[k]);
		k--;
	}
	//ft_array() + ft_bubble_sort();// -a
	//ft_display();//-r + normal
	//ft_mod();// -t
	//ft_details(); // -l
	//ft_bubble_sort();
	//free(flags);//do I need this?
}

void	ft_bfound(int bfound,struct options *flags)
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
		ft_flag(bfound,flags);
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
//Issue with l s
//Issue with --
//Issue with -a-a- --
//Issue with ls - 
void ft_options(int c,char **arr1)
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
	ft_bfound(bfound, owner);
	free(owner);//<- RESTORE this!!!
}
