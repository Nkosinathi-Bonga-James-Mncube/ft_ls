/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:12 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/30 15:11:25 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void ft_display(char **arr,int total,int bfound)
{
	int j;
	j = 0;

	if (bfound == 1)
		j = total - 1;
	while (total > 0)
	{
		ft_putstr(arr[j]);
		ft_putchar('\t');
		bfound == 1?j--:j++;
		total--;
	}
}
