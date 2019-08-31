/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/30 16:42:07 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//#include <stdio.h>//delete this
//#include "ft_options.c"
//#include "ft_mod.c"
//#include "ft_display.c"
//#include "ft_bubble_sort.c"//shouldn't be here?!
//#include "ft_details.c"//shouldn't be here?!
char **ft_ls(int total,int bfound,struct dirent *dp)
{
	DIR				*dir;
	int				k;
	char			**arr;
	char **s1;
	//dont need this//this will be flag->-r == 1(Reverse order)//check ft_details and modify
	//DONT NEED A (flag->r option) choice. Just replace bfound in function with flag->r 
	dir = opendir("libft/");//orginal->opendir(".");
	k = 0;
	if (dir == NULL)
	{
		perror("Cannot open");
		exit(1);
	}
	arr = (char**)malloc(total * sizeof(char*));
	while ((dp = readdir(dir)) != NULL && total > 0)
	{
		if (dp->d_name[0] != '.' && bfound== 0)//if (dp->d_name[0] != && flag->a == 0)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
		if (bfound == 1)//if (flag->a == 1)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
	}
	s1 = arr;
	free(arr);
	arr =s1;
	//ft_bubble_sort(arr, total,0);//replace 0 with bfound
	//ft_details(arr, total, bfound);
	//ft_mod(arr, total);
	//ft_display(arr,total,0);
	free(dir);//DIR LEAKS! Remember to free them!
	return (arr);
}

/*int		ft_count(int bfound,struct dirent *dp)
{
	DIR		*dir;
	int		k;

	dir = opendir("libft/");
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' && bfound == 0)//if (dp->dname[0] && flags->a != 1)
			k++;
		if (bfound == 1)
			k++;
	}
	printf(">>%d\n" , k);//remove
	free(dir);
	//free(dp);//<-do I need this?
	return (k);
}*/

char **ft_array(int bfound)
{
	int total;
	char **hold;
	char ** hold2;
	struct dirent *dp;

	total = 0;
	//total = total + ft_count(bfound);
	hold = ft_ls(ft_count(bfound),bfound,dp);
	/*hold2 = hold;
	while (total >= 0)
	{
		free(hold[total]);
		total--;
	}
	hold = hold2;*/
	return (hold);
}
