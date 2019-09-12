/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:09:15 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/12 10:31:13 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_find1(char *s1, char *s2, struct stat b1, struct stat b2)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s1[k] != '\0' || s2[j] != '\0')
	{
		if (s1[k] != s2[j])
		{
			if (b1.st_mtime <= b2.st_mtime)
			{
				if (b1.st_mtime == b2.st_mtime)
				{
					if (b1.st_mtimespec.tv_nsec 
							<= b2.st_mtimespec.tv_nsec)
						return(s2[j]);
				}
				else
					return (s1[k]);
			}
		}
		if (s1[k++] != '\0' || s2[j++]!= '\0')
		{}
	}
	return (0);
}

void	ft_swap1(char **s1, char **s2)
{
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

char **ft_mod(char *folder,char **arr, int n)
{
	int i;
	int j;
	struct stat b1;
	struct stat b2;
	char *s3;

	i = 0;
	s3 = ft_strjoin(folder,"/");
	while (i < n - 1)
	{
		j = 0;
		while (j < (n - i - 1))
		{
			stat(s3, &b1);
			stat(s3, &b2);
			if (ft_find1(arr[j], arr[j + 1] ,b1 , b2) > 0)
				ft_swap1(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (arr);
}
